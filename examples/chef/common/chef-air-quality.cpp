/*
 *
 *    Copyright (c) 2023 Project CHIP Authors
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
#include <app-common/zap-generated/callback.h>
#include <app-common/zap-generated/ids/Attributes.h>
#include <app-common/zap-generated/ids/Clusters.h>
#include <app/util/config.h>
#include <lib/core/DataModelTypes.h>

using namespace chip;
using namespace chip::app;
using namespace chip::app::Clusters;

#ifdef EMBER_AF_PLUGIN_AIR_QUALITY_SERVER
#include <app/clusters/air-quality-server/air-quality-server.h>
using namespace chip::app::Clusters::AirQuality;

static chip::BitMask<Feature, uint32_t> airQualityFeatures(Feature::kFair, Feature::kModerate, Feature::kVeryPoor,
                                                           Feature::kExtremelyPoor);
static Instance gAirQualityClusterInstance = Instance(1, airQualityFeatures);

void emberAfAirQualityClusterInitCallback(chip::EndpointId endpointId)
{
    gAirQualityClusterInstance.Init();
}
#endif
