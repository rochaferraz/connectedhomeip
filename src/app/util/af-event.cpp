/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *
 *    Copyright (c) 2020 Silicon Labs
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
/*****************************************************************************
 * @file
 * @brief Application event code that is common to both the SOC and EZSP platforms.
 *******************************************************************************
 ******************************************************************************/

#include <app/util/af-event.h>

#include <app/util/af.h>
#include <app/util/attribute-storage.h>

#include <platform/CHIPDeviceLayer.h>

#define EMBER_MAX_EVENT_CONTROL_DELAY_MS (UINT32_MAX / 2)
#define EMBER_MAX_EVENT_CONTROL_DELAY_QS (EMBER_MAX_EVENT_CONTROL_DELAY_MS >> 8)
#define EMBER_MAX_EVENT_CONTROL_DELAY_MINUTES (EMBER_MAX_EVENT_CONTROL_DELAY_MS >> 16)

#include <app-common/zap-generated/callback.h>

#include <zap-generated/af-gen-event.h>

using namespace chip;
using namespace chip::Platform;

// *****************************************************************************
// Globals

#ifdef EMBER_AF_GENERATED_EVENT_CODE
// Stubs for IAS Zone Client Cluster issue #2057
EmberEventControl emberAfPluginIasZoneClientStateMachineEventControl;
void emberAfPluginIasZoneClientStateMachineEventHandler(void){};

EMBER_AF_GENERATED_EVENT_CODE
#endif // EMBER_AF_GENERATED_EVENT_CODE

static IntrusiveList<MatterEventMetaContext> eventMetaContexts;

void MatterRegisterAfEvent(MatterEventMetaContext * newContext)
{
    eventMetaContexts.PushBack(newContext);
}

void MatterUnregisterAllAfEvents()
{
    while (eventMetaContexts.begin() != eventMetaContexts.end())
    {
        eventMetaContexts.Remove(&(*eventMetaContexts.begin()));
    }
}

void EventControlHandler(chip::System::Layer * systemLayer, void * appState)
{
    EmberEventControl * control = reinterpret_cast<EmberEventControl *>(appState);
    if (control->status != EMBER_EVENT_INACTIVE)
    {
        control->status = EMBER_EVENT_INACTIVE;

        if (control->callback != nullptr)
        {
            (control->callback)(control->endpoint);
            return;
        }

        for (auto metaContext : eventMetaContexts)
        {
            const EmberEventData & event = metaContext.event;
            if (event.control != control)
                continue;
            control->status = EMBER_EVENT_INACTIVE;
            event.handler((uint8_t) metaContext.context.endpoint);
            break;
        }
    }
}

// *****************************************************************************
// Functions

// A function used to initialize events for idling
void emAfInitEvents(void) {}

const char * emberAfGetEventString(uint8_t index)
{
    if (index == 0xFF)
    {
        return emAfStackEventString;
    }

    uint8_t iteratorCounter = 0;
    for (auto & metaContext : eventMetaContexts)
    {
        if (iteratorCounter == index)
        {
            return metaContext.eventString;
        }
        iteratorCounter++;
    }

    return emAfStackEventString;
}

static EmberAfEventContext * findEventContext(EndpointId endpoint, ClusterId clusterId, bool isClient)
{
    for (auto & metaContext : eventMetaContexts)
    {
        auto context = metaContext.context;
        if (context.endpoint == endpoint && context.clusterId == clusterId && context.isClient == isClient)
        {
            return &metaContext.context;
        }
    }
    return nullptr;
}

EmberStatus emberEventControlSetDelayMS(EmberEventControl * control, uint32_t delayMs)
{
    if (delayMs <= EMBER_MAX_EVENT_CONTROL_DELAY_MS)
    {
        control->status = EMBER_EVENT_MS_TIME;
#if !CHIP_DEVICE_LAYER_NONE
        chip::DeviceLayer::SystemLayer().StartTimer(chip::System::Clock::Milliseconds32(delayMs), EventControlHandler, control);
#endif
    }
    else
    {
        return EMBER_BAD_ARGUMENT;
    }
    return EMBER_SUCCESS;
}

void emberEventControlSetInactive(EmberEventControl * control)
{
    if (control->status != EMBER_EVENT_INACTIVE)
    {
        control->status = EMBER_EVENT_INACTIVE;
#if !CHIP_DEVICE_LAYER_NONE
        chip::DeviceLayer::SystemLayer().CancelTimer(EventControlHandler, control);
#endif
    }
}

bool emberEventControlGetActive(EmberEventControl * control)
{
    return control->status != EMBER_EVENT_INACTIVE;
}

void emberEventControlSetActive(EmberEventControl * control)
{
    control->status = EMBER_EVENT_ZERO_DELAY;
#if !CHIP_DEVICE_LAYER_NONE
    chip::DeviceLayer::SystemLayer().ScheduleWork(EventControlHandler, control);
#endif
}

EmberStatus emberAfScheduleTickExtended(EndpointId endpoint, ClusterId clusterId, bool isClient, uint32_t delayMs,
                                        EmberAfEventPollControl pollControl, EmberAfEventSleepControl sleepControl)
{
    EmberAfEventContext * context = findEventContext(endpoint, clusterId, isClient);

    // Disabled endpoints cannot schedule events.  This will catch the problem in
    // simulation.
    EMBER_TEST_ASSERT(emberAfEndpointIsEnabled(endpoint));

    if (context != nullptr && emberAfEndpointIsEnabled(endpoint) &&
        (emberEventControlSetDelayMS(context->eventControl, delayMs) == EMBER_SUCCESS))
    {
        context->pollControl  = pollControl;
        context->sleepControl = sleepControl;
        return EMBER_SUCCESS;
    }
    return EMBER_BAD_ARGUMENT;
}

EmberStatus emberAfScheduleClusterTick(EndpointId endpoint, ClusterId clusterId, bool isClient, uint32_t delayMs,
                                       EmberAfEventSleepControl sleepControl)
{
    return emberAfScheduleTickExtended(endpoint, clusterId, isClient, delayMs,
                                       (sleepControl == EMBER_AF_OK_TO_HIBERNATE ? EMBER_AF_LONG_POLL : EMBER_AF_SHORT_POLL),
                                       (sleepControl == EMBER_AF_STAY_AWAKE ? EMBER_AF_STAY_AWAKE : EMBER_AF_OK_TO_SLEEP));
}

EmberStatus emberAfScheduleClientTickExtended(EndpointId endpoint, ClusterId clusterId, uint32_t delayMs,
                                              EmberAfEventPollControl pollControl, EmberAfEventSleepControl sleepControl)
{
    return emberAfScheduleTickExtended(endpoint, clusterId, EMBER_AF_CLIENT_CLUSTER_TICK, delayMs, pollControl, sleepControl);
}

EmberStatus emberAfScheduleClientTick(EndpointId endpoint, ClusterId clusterId, uint32_t delayMs)
{
    return emberAfScheduleClientTickExtended(endpoint, clusterId, delayMs, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP);
}

EmberStatus emberAfScheduleServerTickExtended(EndpointId endpoint, ClusterId clusterId, uint32_t delayMs,
                                              EmberAfEventPollControl pollControl, EmberAfEventSleepControl sleepControl)
{
    return emberAfScheduleTickExtended(endpoint, clusterId, EMBER_AF_SERVER_CLUSTER_TICK, delayMs, pollControl, sleepControl);
}

EmberStatus emberAfScheduleServerTick(EndpointId endpoint, ClusterId clusterId, uint32_t delayMs)
{
    return emberAfScheduleServerTickExtended(endpoint, clusterId, delayMs, EMBER_AF_LONG_POLL, EMBER_AF_OK_TO_SLEEP);
}

EmberStatus emberAfDeactivateClusterTick(EndpointId endpoint, ClusterId clusterId, bool isClient)
{
    EmberAfEventContext * context = findEventContext(endpoint, clusterId, isClient);
    if (context != nullptr)
    {
        emberEventControlSetInactive(context->eventControl);
        return EMBER_SUCCESS;
    }
    return EMBER_BAD_ARGUMENT;
}

EmberStatus emberAfDeactivateClientTick(EndpointId endpoint, ClusterId clusterId)
{
    return emberAfDeactivateClusterTick(endpoint, clusterId, EMBER_AF_CLIENT_CLUSTER_TICK);
}

EmberStatus emberAfDeactivateServerTick(EndpointId endpoint, ClusterId clusterId)
{
    return emberAfDeactivateClusterTick(endpoint, clusterId, EMBER_AF_SERVER_CLUSTER_TICK);
}
