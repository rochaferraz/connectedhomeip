/*
 *
 *    Copyright (c) 2022 Project CHIP Authors
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

// THIS FILE IS GENERATED BY ZAP

#pragma once

#include <app/util/basic-types.h>

namespace chip {
namespace app {
namespace Clusters {

namespace AccessControl {
namespace Events {

namespace AccessControlEntryChanged {
static constexpr EventId Id = 0x00000000;
} // namespace AccessControlEntryChanged

namespace AccessControlExtensionChanged {
static constexpr EventId Id = 0x00000001;
} // namespace AccessControlExtensionChanged

} // namespace Events
} // namespace AccessControl

namespace Actions {
namespace Events {

namespace StateChanged {
static constexpr EventId Id = 0x00000000;
} // namespace StateChanged

namespace ActionFailed {
static constexpr EventId Id = 0x00000001;
} // namespace ActionFailed

} // namespace Events
} // namespace Actions

namespace BasicInformation {
namespace Events {

namespace StartUp {
static constexpr EventId Id = 0x00000000;
} // namespace StartUp

namespace ShutDown {
static constexpr EventId Id = 0x00000001;
} // namespace ShutDown

namespace Leave {
static constexpr EventId Id = 0x00000002;
} // namespace Leave

namespace ReachableChanged {
static constexpr EventId Id = 0x00000003;
} // namespace ReachableChanged

} // namespace Events
} // namespace BasicInformation

namespace OtaSoftwareUpdateRequestor {
namespace Events {

namespace StateTransition {
static constexpr EventId Id = 0x00000000;
} // namespace StateTransition

namespace VersionApplied {
static constexpr EventId Id = 0x00000001;
} // namespace VersionApplied

namespace DownloadError {
static constexpr EventId Id = 0x00000002;
} // namespace DownloadError

} // namespace Events
} // namespace OtaSoftwareUpdateRequestor

namespace PowerSource {
namespace Events {

namespace WiredFaultChange {
static constexpr EventId Id = 0x00000000;
} // namespace WiredFaultChange

namespace BatFaultChange {
static constexpr EventId Id = 0x00000001;
} // namespace BatFaultChange

namespace BatChargeFaultChange {
static constexpr EventId Id = 0x00000002;
} // namespace BatChargeFaultChange

} // namespace Events
} // namespace PowerSource

namespace GeneralDiagnostics {
namespace Events {

namespace HardwareFaultChange {
static constexpr EventId Id = 0x00000000;
} // namespace HardwareFaultChange

namespace RadioFaultChange {
static constexpr EventId Id = 0x00000001;
} // namespace RadioFaultChange

namespace NetworkFaultChange {
static constexpr EventId Id = 0x00000002;
} // namespace NetworkFaultChange

namespace BootReason {
static constexpr EventId Id = 0x00000003;
} // namespace BootReason

} // namespace Events
} // namespace GeneralDiagnostics

namespace SoftwareDiagnostics {
namespace Events {

namespace SoftwareFault {
static constexpr EventId Id = 0x00000000;
} // namespace SoftwareFault

} // namespace Events
} // namespace SoftwareDiagnostics

namespace ThreadNetworkDiagnostics {
namespace Events {

namespace ConnectionStatus {
static constexpr EventId Id = 0x00000000;
} // namespace ConnectionStatus

namespace NetworkFaultChange {
static constexpr EventId Id = 0x00000001;
} // namespace NetworkFaultChange

} // namespace Events
} // namespace ThreadNetworkDiagnostics

namespace WiFiNetworkDiagnostics {
namespace Events {

namespace Disconnection {
static constexpr EventId Id = 0x00000000;
} // namespace Disconnection

namespace AssociationFailure {
static constexpr EventId Id = 0x00000001;
} // namespace AssociationFailure

namespace ConnectionStatus {
static constexpr EventId Id = 0x00000002;
} // namespace ConnectionStatus

} // namespace Events
} // namespace WiFiNetworkDiagnostics

namespace BridgedDeviceBasicInformation {
namespace Events {

namespace StartUp {
static constexpr EventId Id = 0x00000000;
} // namespace StartUp

namespace ShutDown {
static constexpr EventId Id = 0x00000001;
} // namespace ShutDown

namespace Leave {
static constexpr EventId Id = 0x00000002;
} // namespace Leave

namespace ReachableChanged {
static constexpr EventId Id = 0x00000003;
} // namespace ReachableChanged

} // namespace Events
} // namespace BridgedDeviceBasicInformation

namespace Switch {
namespace Events {

namespace SwitchLatched {
static constexpr EventId Id = 0x00000000;
} // namespace SwitchLatched

namespace InitialPress {
static constexpr EventId Id = 0x00000001;
} // namespace InitialPress

namespace LongPress {
static constexpr EventId Id = 0x00000002;
} // namespace LongPress

namespace ShortRelease {
static constexpr EventId Id = 0x00000003;
} // namespace ShortRelease

namespace LongRelease {
static constexpr EventId Id = 0x00000004;
} // namespace LongRelease

namespace MultiPressOngoing {
static constexpr EventId Id = 0x00000005;
} // namespace MultiPressOngoing

namespace MultiPressComplete {
static constexpr EventId Id = 0x00000006;
} // namespace MultiPressComplete

} // namespace Events
} // namespace Switch

namespace BooleanState {
namespace Events {

namespace StateChange {
static constexpr EventId Id = 0x00000000;
} // namespace StateChange

} // namespace Events
} // namespace BooleanState

namespace DoorLock {
namespace Events {

namespace DoorLockAlarm {
static constexpr EventId Id = 0x00000000;
} // namespace DoorLockAlarm

namespace DoorStateChange {
static constexpr EventId Id = 0x00000001;
} // namespace DoorStateChange

namespace LockOperation {
static constexpr EventId Id = 0x00000002;
} // namespace LockOperation

namespace LockOperationError {
static constexpr EventId Id = 0x00000003;
} // namespace LockOperationError

namespace LockUserChange {
static constexpr EventId Id = 0x00000004;
} // namespace LockUserChange

} // namespace Events
} // namespace DoorLock

namespace PumpConfigurationAndControl {
namespace Events {

namespace SupplyVoltageLow {
static constexpr EventId Id = 0x00000000;
} // namespace SupplyVoltageLow

namespace SupplyVoltageHigh {
static constexpr EventId Id = 0x00000001;
} // namespace SupplyVoltageHigh

namespace PowerMissingPhase {
static constexpr EventId Id = 0x00000002;
} // namespace PowerMissingPhase

namespace SystemPressureLow {
static constexpr EventId Id = 0x00000003;
} // namespace SystemPressureLow

namespace SystemPressureHigh {
static constexpr EventId Id = 0x00000004;
} // namespace SystemPressureHigh

namespace DryRunning {
static constexpr EventId Id = 0x00000005;
} // namespace DryRunning

namespace MotorTemperatureHigh {
static constexpr EventId Id = 0x00000006;
} // namespace MotorTemperatureHigh

namespace PumpMotorFatalFailure {
static constexpr EventId Id = 0x00000007;
} // namespace PumpMotorFatalFailure

namespace ElectronicTemperatureHigh {
static constexpr EventId Id = 0x00000008;
} // namespace ElectronicTemperatureHigh

namespace PumpBlocked {
static constexpr EventId Id = 0x00000009;
} // namespace PumpBlocked

namespace SensorFailure {
static constexpr EventId Id = 0x0000000A;
} // namespace SensorFailure

namespace ElectronicNonFatalFailure {
static constexpr EventId Id = 0x0000000B;
} // namespace ElectronicNonFatalFailure

namespace ElectronicFatalFailure {
static constexpr EventId Id = 0x0000000C;
} // namespace ElectronicFatalFailure

namespace GeneralFault {
static constexpr EventId Id = 0x0000000D;
} // namespace GeneralFault

namespace Leakage {
static constexpr EventId Id = 0x0000000E;
} // namespace Leakage

namespace AirDetection {
static constexpr EventId Id = 0x0000000F;
} // namespace AirDetection

namespace TurbineOperation {
static constexpr EventId Id = 0x00000010;
} // namespace TurbineOperation

} // namespace Events
} // namespace PumpConfigurationAndControl

namespace UnitTesting {
namespace Events {

namespace TestEvent {
static constexpr EventId Id = 0x00000001;
} // namespace TestEvent

namespace TestFabricScopedEvent {
static constexpr EventId Id = 0x00000002;
} // namespace TestFabricScopedEvent

} // namespace Events
} // namespace UnitTesting


} // namespace Clusters
} // namespace app
} // namespace chip
