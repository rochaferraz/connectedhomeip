/*
 *
 *    Copyright (c) 2025 Project CHIP Authors
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
#pragma once

#include <devices/wifi-network-management/WiFiNetworkManagementDevice.h>
#include <platform/DefaultTimerDelegate.h>

#ifndef ChipLogFormatByteSpan
#define ChipLogFormatByteSpan "%.*s"
#define ChipLogValueByteSpan(span) static_cast<int>((span).size()), reinterpret_cast<const char *>((span).data())
#endif

namespace chip {
namespace app {

/**
 * @brief An implementation of a Wi-Fi Network Management Device.
 *
 * This class serves as a simple example of a Wi-Fi network manager. It implements the
 * WiFiNetworkManagementDelegate interface and logs credential changes.
 */
class LoggingWiFiNetworkManagementDevice : public WiFiNetworkManagementDevice, public Clusters::WiFiNetworkManagementDelegate
{
public:
    LoggingWiFiNetworkManagementDevice();
    ~LoggingWiFiNetworkManagementDevice() override = default;

    // WiFiNetworkManagementDelegate
    void OnNetworkCredentialsChanged(ByteSpan ssid, ByteSpan passphrase) override;
    void OnNetworkCredentialsCleared() override;

private:
    DefaultTimerDelegate mTimerDelegate;
};

} // namespace app
} // namespace chip
