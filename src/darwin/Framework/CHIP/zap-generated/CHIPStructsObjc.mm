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

#import "CHIPStructsObjc.h"

NS_ASSUME_NONNULL_BEGIN

@implementation CHIPScenesClusterSceneExtensionFieldSet
- (instancetype)init
{
    if (self = [super init]) {

        _clusterId = @(0);

        _length = @(0);

        _value = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterPowerProfileRecord
- (instancetype)init
{
    if (self = [super init]) {

        _powerProfileId = @(0);

        _energyPhaseId = @(0);

        _powerProfileRemoteControl = @(0);

        _powerProfileState = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterScheduledPhase
- (instancetype)init
{
    if (self = [super init]) {

        _energyPhaseId = @(0);

        _scheduledTime = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerProfileClusterTransferredPhase
- (instancetype)init
{
    if (self = [super init]) {

        _energyPhaseId = @(0);

        _macroPhaseId = @(0);

        _expectedDuration = @(0);

        _peakPower = @(0);

        _energy = @(0);

        _maxActivationDelay = @(0);
    }
    return self;
}
@end

@implementation CHIPDescriptorClusterDeviceType
- (instancetype)init
{
    if (self = [super init]) {

        _type = @(0);

        _revision = @(0);
    }
    return self;
}
@end

@implementation CHIPAccessControlClusterTarget
- (instancetype)init
{
    if (self = [super init]) {

        _cluster = nil;

        _endpoint = nil;

        _deviceType = nil;
    }
    return self;
}
@end

@implementation CHIPAccessControlClusterAccessControlEntry
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _privilege = @(0);

        _authMode = @(0);

        _subjects = nil;

        _targets = nil;
    }
    return self;
}
@end

@implementation CHIPAccessControlClusterExtensionEntry
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _data = [NSData data];
    }
    return self;
}
@end

@implementation CHIPBridgedActionsClusterActionStruct
- (instancetype)init
{
    if (self = [super init]) {

        _actionID = @(0);

        _name = @"";

        _type = @(0);

        _endpointListID = @(0);

        _supportedCommands = @(0);

        _status = @(0);
    }
    return self;
}
@end

@implementation CHIPBridgedActionsClusterEndpointListStruct
- (instancetype)init
{
    if (self = [super init]) {

        _endpointListID = @(0);

        _name = @"";

        _type = @(0);

        _endpoints = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPOtaSoftwareUpdateRequestorClusterProviderLocation
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _providerNodeID = @(0);

        _endpoint = @(0);
    }
    return self;
}
@end

@implementation CHIPPowerSourceClusterBatChargeFaultChangeType
- (instancetype)init
{
    if (self = [super init]) {

        _current = [NSArray array];

        _previous = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPPowerSourceClusterBatFaultChangeType
- (instancetype)init
{
    if (self = [super init]) {

        _current = [NSArray array];

        _previous = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPPowerSourceClusterWiredFaultChangeType
- (instancetype)init
{
    if (self = [super init]) {

        _current = [NSArray array];

        _previous = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPGeneralCommissioningClusterBasicCommissioningInfo
- (instancetype)init
{
    if (self = [super init]) {

        _failSafeExpiryLengthSeconds = @(0);
    }
    return self;
}
@end

@implementation CHIPNetworkCommissioningClusterNetworkInfo
- (instancetype)init
{
    if (self = [super init]) {

        _networkID = [NSData data];

        _connected = @(0);
    }
    return self;
}
@end

@implementation CHIPNetworkCommissioningClusterThreadInterfaceScanResult
- (instancetype)init
{
    if (self = [super init]) {

        _panId = @(0);

        _extendedPanId = @(0);

        _networkName = @"";

        _channel = @(0);

        _version = @(0);

        _extendedAddress = @(0);

        _rssi = @(0);

        _lqi = @(0);
    }
    return self;
}
@end

@implementation CHIPNetworkCommissioningClusterWiFiInterfaceScanResult
- (instancetype)init
{
    if (self = [super init]) {

        _security = @(0);

        _ssid = [NSData data];

        _bssid = [NSData data];

        _channel = @(0);

        _wiFiBand = @(0);

        _rssi = @(0);
    }
    return self;
}
@end

@implementation CHIPGeneralDiagnosticsClusterNetworkInterfaceType
- (instancetype)init
{
    if (self = [super init]) {

        _name = @"";

        _fabricConnected = @(0);

        _offPremiseServicesReachableIPv4 = @(0);

        _offPremiseServicesReachableIPv6 = @(0);

        _hardwareAddress = [NSData data];

        _type = @(0);
    }
    return self;
}
@end

@implementation CHIPSoftwareDiagnosticsClusterSoftwareFaultStruct
- (instancetype)init
{
    if (self = [super init]) {

        _id = @(0);

        _name = @"";

        _faultRecording = [NSData data];
    }
    return self;
}
@end

@implementation CHIPSoftwareDiagnosticsClusterThreadMetrics
- (instancetype)init
{
    if (self = [super init]) {

        _id = @(0);

        _name = @"";

        _stackFreeCurrent = @(0);

        _stackFreeMinimum = @(0);

        _stackSize = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterNeighborTable
- (instancetype)init
{
    if (self = [super init]) {

        _extAddress = @(0);

        _age = @(0);

        _rloc16 = @(0);

        _linkFrameCounter = @(0);

        _mleFrameCounter = @(0);

        _lqi = @(0);

        _averageRssi = @(0);

        _lastRssi = @(0);

        _frameErrorRate = @(0);

        _messageErrorRate = @(0);

        _rxOnWhenIdle = @(0);

        _fullThreadDevice = @(0);

        _fullNetworkData = @(0);

        _isChild = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterOperationalDatasetComponents
- (instancetype)init
{
    if (self = [super init]) {

        _activeTimestampPresent = @(0);

        _pendingTimestampPresent = @(0);

        _masterKeyPresent = @(0);

        _networkNamePresent = @(0);

        _extendedPanIdPresent = @(0);

        _meshLocalPrefixPresent = @(0);

        _delayPresent = @(0);

        _panIdPresent = @(0);

        _channelPresent = @(0);

        _pskcPresent = @(0);

        _securityPolicyPresent = @(0);

        _channelMaskPresent = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterRouteTable
- (instancetype)init
{
    if (self = [super init]) {

        _extAddress = @(0);

        _rloc16 = @(0);

        _routerId = @(0);

        _nextHop = @(0);

        _pathCost = @(0);

        _lqiIn = @(0);

        _lqiOut = @(0);

        _age = @(0);

        _allocated = @(0);

        _linkEstablished = @(0);
    }
    return self;
}
@end

@implementation CHIPThreadNetworkDiagnosticsClusterSecurityPolicy
- (instancetype)init
{
    if (self = [super init]) {

        _rotationTime = @(0);

        _flags = @(0);
    }
    return self;
}
@end

@implementation CHIPOperationalCredentialsClusterFabricDescriptor
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _rootPublicKey = [NSData data];

        _vendorId = @(0);

        _fabricId = @(0);

        _nodeId = @(0);

        _label = @"";
    }
    return self;
}
@end

@implementation CHIPOperationalCredentialsClusterNOCStruct
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _noc = [NSData data];

        _icac = nil;
    }
    return self;
}
@end

@implementation CHIPGroupKeyManagementClusterGroupInfo
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _groupId = @(0);

        _endpoints = [NSArray array];

        _groupName = @"";
    }
    return self;
}
@end

@implementation CHIPGroupKeyManagementClusterGroupKey
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _groupId = @(0);

        _groupKeySetID = @(0);
    }
    return self;
}
@end

@implementation CHIPGroupKeyManagementClusterGroupKeySet
- (instancetype)init
{
    if (self = [super init]) {

        _groupKeySetID = @(0);

        _securityPolicy = @(0);

        _epochKey0 = [NSData data];

        _epochStartTime0 = @(0);

        _epochKey1 = [NSData data];

        _epochStartTime1 = @(0);

        _epochKey2 = [NSData data];

        _epochStartTime2 = @(0);
    }
    return self;
}
@end

@implementation CHIPFixedLabelClusterLabelStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPUserLabelClusterLabelStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPModeSelectClusterModeOptionStruct
- (instancetype)init
{
    if (self = [super init]) {

        _label = @"";

        _mode = @(0);

        _semanticTag = @(0);
    }
    return self;
}
@end

@implementation CHIPModeSelectClusterSemanticTag
- (instancetype)init
{
    if (self = [super init]) {

        _mfgCode = @(0);

        _value = @(0);
    }
    return self;
}
@end

@implementation CHIPDoorLockClusterDlCredential
- (instancetype)init
{
    if (self = [super init]) {

        _credentialType = @(0);

        _credentialIndex = @(0);
    }
    return self;
}
@end

@implementation CHIPIasAceClusterIasAceZoneStatusResult
- (instancetype)init
{
    if (self = [super init]) {

        _zoneId = @(0);

        _zoneStatus = @(0);
    }
    return self;
}
@end

@implementation CHIPChannelClusterChannelInfo
- (instancetype)init
{
    if (self = [super init]) {

        _majorNumber = @(0);

        _minorNumber = @(0);

        _name = @"";

        _callSign = @"";

        _affiliateCallSign = @"";
    }
    return self;
}
@end

@implementation CHIPChannelClusterLineupInfo
- (instancetype)init
{
    if (self = [super init]) {

        _operatorName = @"";

        _lineupName = @"";

        _postalCode = @"";

        _lineupInfoType = @(0);
    }
    return self;
}
@end

@implementation CHIPTargetNavigatorClusterTargetInfo
- (instancetype)init
{
    if (self = [super init]) {

        _identifier = @(0);

        _name = @"";
    }
    return self;
}
@end

@implementation CHIPMediaPlaybackClusterPlaybackPosition
- (instancetype)init
{
    if (self = [super init]) {

        _updatedAt = @(0);

        _position = @(0);
    }
    return self;
}
@end

@implementation CHIPMediaInputClusterInputInfo
- (instancetype)init
{
    if (self = [super init]) {

        _index = @(0);

        _inputType = @(0);

        _name = @"";

        _descriptionString = @"";
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterDimension
- (instancetype)init
{
    if (self = [super init]) {

        _width = @(0);

        _height = @(0);

        _metric = @(0);
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterAdditionalInfo
- (instancetype)init
{
    if (self = [super init]) {

        _name = @"";

        _value = @"";
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterParameter
- (instancetype)init
{
    if (self = [super init]) {

        _type = @(0);

        _value = @"";

        _externalIDList = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterContentSearch
- (instancetype)init
{
    if (self = [super init]) {

        _parameterList = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterStyleInformation
- (instancetype)init
{
    if (self = [super init]) {

        _imageUrl = @"";

        _color = @"";

        _size = [CHIPContentLauncherClusterDimension new];
    }
    return self;
}
@end

@implementation CHIPContentLauncherClusterBrandingInformation
- (instancetype)init
{
    if (self = [super init]) {

        _providerName = @"";

        _background = [CHIPContentLauncherClusterStyleInformation new];

        _logo = [CHIPContentLauncherClusterStyleInformation new];

        _progressBar = [CHIPContentLauncherClusterStyleInformation new];

        _splash = [CHIPContentLauncherClusterStyleInformation new];

        _waterMark = [CHIPContentLauncherClusterStyleInformation new];
    }
    return self;
}
@end

@implementation CHIPAudioOutputClusterOutputInfo
- (instancetype)init
{
    if (self = [super init]) {

        _index = @(0);

        _outputType = @(0);

        _name = @"";
    }
    return self;
}
@end

@implementation CHIPApplicationLauncherClusterApplicationLauncherApplication
- (instancetype)init
{
    if (self = [super init]) {

        _catalogVendorId = @(0);

        _applicationId = @"";
    }
    return self;
}
@end

@implementation CHIPApplicationLauncherClusterApplicationEP
- (instancetype)init
{
    if (self = [super init]) {

        _application = [CHIPApplicationLauncherClusterApplicationLauncherApplication new];

        _endpoint = @"";
    }
    return self;
}
@end

@implementation CHIPApplicationBasicClusterApplicationBasicApplication
- (instancetype)init
{
    if (self = [super init]) {

        _catalogVendorId = @(0);

        _applicationId = @"";
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterSimpleStruct
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = @(0);

        _d = [NSData data];

        _e = @"";

        _f = @(0);

        _g = @(0);

        _h = @(0);
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNullablesAndOptionalsStruct
- (instancetype)init
{
    if (self = [super init]) {

        _nullableInt = nil;

        _optionalInt = nil;

        _nullableOptionalInt = nil;

        _nullableString = nil;

        _optionalString = nil;

        _nullableOptionalString = nil;

        _nullableStruct = nil;

        _optionalStruct = nil;

        _nullableOptionalStruct = nil;

        _nullableList = nil;

        _optionalList = nil;

        _nullableOptionalList = nil;
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNestedStruct
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = [CHIPTestClusterClusterSimpleStruct new];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterNestedStructList
- (instancetype)init
{
    if (self = [super init]) {

        _a = @(0);

        _b = @(0);

        _c = [CHIPTestClusterClusterSimpleStruct new];

        _d = [NSArray array];

        _e = [NSArray array];

        _f = [NSArray array];

        _g = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterDoubleNestedStructList
- (instancetype)init
{
    if (self = [super init]) {

        _a = [NSArray array];
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterTestFabricScoped
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);
    }
    return self;
}
@end

@implementation CHIPTestClusterClusterTestListStructOctet
- (instancetype)init
{
    if (self = [super init]) {

        _fabricIndex = @(0);

        _operationalCert = [NSData data];
    }
    return self;
}
@end

NS_ASSUME_NONNULL_END
