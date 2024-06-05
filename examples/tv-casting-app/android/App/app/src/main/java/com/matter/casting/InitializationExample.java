/*
 *   Copyright (c) 2023 Project CHIP Authors
 *   All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
package com.matter.casting;

import android.content.Context;
import android.util.Log;
import chip.platform.ConfigurationManager;
import com.matter.casting.core.CastingApp;
import com.matter.casting.support.AppParameters;
import com.matter.casting.support.CommissionableData;
import com.matter.casting.support.DACProvider;
import com.matter.casting.support.DataProvider;
import com.matter.casting.support.MatterError;

public class InitializationExample {
  private static final String TAG = InitializationExample.class.getSimpleName();
  // Dummy values for commissioning demonstration only. These are hard coded in the example tv-app:
  // connectedhomeip/examples/tv-app/tv-common/src/AppTv.cpp
  private static final long DUMMY_SETUP_PASSCODE = 20202021;
  private static final int DUMMY_DISCRIMINATOR = 3874;

  /**
   * DataProvider implementation for the Unique ID that is used by the SDK to generate the Rotating
   * Device ID
   */
  private static final DataProvider<byte[]> rotatingDeviceIdUniqueIdProvider =
      new DataProvider<byte[]>() {
        private static final String ROTATING_DEVICE_ID_UNIQUE_ID =
            "EXAMPLE_ID"; // dummy value for demonstration only

        @Override
        public byte[] get() {
          return ROTATING_DEVICE_ID_UNIQUE_ID.getBytes();
        }
      };

  /**
   * DataProvider implementation for the Commissioning Data used by the SDK when the CastingApp goes
   * through commissioning
   */
  public static class CommissionableDataProvider implements DataProvider<CommissionableData> {
    CommissionableData commissionableData =
        new CommissionableData(DUMMY_SETUP_PASSCODE, DUMMY_DISCRIMINATOR);

    @Override
    public CommissionableData get() {
      return commissionableData;
    }

    /**
     * Must be implemented in the CommissionableData DataProvider if the
     * CastingPlayer/Commissioner-Generated passcode commissioning flow is going to be used. In this
     * flow, the setup passcode is generated by the Commissioner and entered by the user in the
     * tv-casting-app CX. Once it is obtained, this function should be called with the
     * Commissioner-Generated passcode to update the CommissionableData DataProvider in
     * AppParameters.
     */
    public void updateCommissionableDataSetupPasscode(long setupPasscode, int discriminator) {
      Log.i(TAG, "DataProvider<CommissionableData>::updateCommissionableDataSetupPasscode()");
      commissionableData.setSetupPasscode(setupPasscode);
      commissionableData.setDiscriminator(discriminator);
    }
  };

  public static CommissionableDataProvider commissionableDataProvider =
      new CommissionableDataProvider();

  /**
   * DACProvider implementation for the Device Attestation Credentials required at the time of
   * commissioning
   *
   * <p>Using the DACProviderStub which provides dummy values for demonstration only
   */
  private static final DACProvider dacProvider = new DACProviderStub();

  /**
   * @param applicationContext Given android.content.Context, initialize and start the CastingApp
   */
  public static MatterError initAndStart(Context applicationContext) {
    // Create an AppParameters object to pass in global casting parameters to the SDK
    AppParameters appParameters =
        new AppParameters(
            applicationContext,
            new DataProvider<ConfigurationManager>() {
              @Override
              public ConfigurationManager get() {
                return new PreferencesConfigurationManager(
                    applicationContext, "chip.platform.ConfigurationManager");
              }
            },
            rotatingDeviceIdUniqueIdProvider,
            commissionableDataProvider,
            dacProvider);

    // Initialize the SDK using the appParameters and check if it returns successfully
    MatterError err = CastingApp.getInstance().initialize(appParameters);
    if (err.hasError()) {
      Log.e(TAG, "Failed to initialize Matter CastingApp");
      return err;
    }

    err = CastingApp.getInstance().start();
    if (err.hasError()) {
      Log.e(TAG, "Failed to start Matter CastingApp");
      return err;
    }
    return err;
  }
}
