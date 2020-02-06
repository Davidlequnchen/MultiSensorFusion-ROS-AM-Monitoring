/*
 * scanCONTROL Linux SDK - example code
 *
 * MIT License
 *
 * Copyright © 2017-2018 Micro-Epsilon Messtechnik GmbH & Co. KG
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "GetProfilesCallback.h"

gint32 main()
{
    gint32 ret = 0;

    char *interfaces[MAX_INTERFACE_COUNT];
    guint32 resolutions[MAX_RESOLUTION];
    guint32 interface_count = 0;

    guint32 idle_time = 3900;
    guint32 exposure_time = 100;

    if ((ret = CInterfaceLLT::GetDeviceInterfaces(&interfaces[0], MAX_INTERFACE_COUNT)) ==
        ERROR_GETDEVINTERFACE_REQUEST_COUNT) {
        std::cout << "There are more than " << MAX_INTERFACE_COUNT << " scanCONTROL connected" << std::endl;
        interface_count = MAX_INTERFACE_COUNT;
    } else if (ret < 1) {
        std::cout << "A error occured during searching for connected scanCONTROL" << std::endl;
        interface_count = 0;
    } else {
        interface_count = ret;
    }

    if (interface_count == 0) {
        std::cout << "There is no scanCONTROL connected - Exiting" << std::endl;
        exit(0);
    } else if (interface_count == 1) {
        std::cout << "There is 1 scanCONTROL connected " << std::endl;
    } else {
        std::cout << "There are " << interface_count << " scanCONTROL connected" << std::endl;
    }

    for (guint32 i = 0; i < interface_count; i++) {
        std::cout << interfaces[i] << "" << std::endl;
    }

    // new LLT instance
    hLLT = new CInterfaceLLT();
    event = CInterfaceLLT::CreateEvent();

    if ((ret = hLLT->SetDeviceInterface(interfaces[0])) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting dev id " << ret << "!" << std::endl;
        goto cleanup;
    }

    // connect to sensor
    if ((ret = hLLT->Connect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << "!" << std::endl;
        goto cleanup;
    }

    if ((ret = hLLT->GetLLTType(&llt_type)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while GetLLTType!" << std::endl;
        goto cleanup;
    }

    if (ret == GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED) {
        std::cout << "Can't decode scanCONTROL type. Please contact Micro Epsilon for a newer version of the library."
                  << std::endl;
        goto cleanup;
    }

    if (llt_type >= scanCONTROL27xx_25 && llt_type <= scanCONTROL27xx_xxx) {
        std::cout << "The scanCONTROL is a scanCONTROL27xx" << std::endl;
    } else if (llt_type >= scanCONTROL26xx_25 && llt_type <= scanCONTROL26xx_xxx) {
        std::cout << "The scanCONTROL is a scanCONTROL26xx" << std::endl;
    } else if (llt_type >= scanCONTROL29xx_25 && llt_type <= scanCONTROL29xx_xxx) {
        std::cout << "The scanCONTROL is a scanCONTROL29xx" << std::endl;
    } else if (llt_type >= scanCONTROL30xx_25 && llt_type <= scanCONTROL30xx_xxx) {
        std::cout << "The scanCONTROL is a scanCONTROL30xx" << std::endl;
    } else if (llt_type >= scanCONTROL25xx_25 && llt_type <= scanCONTROL25xx_xxx) {
        std::cout << "The scanCONTROL is a scanCONTROL25xx" << std::endl;
    } else {
        std::cout << "The scanCONTROL is a undefined type\nPlease contact Micro-Epsilon for a newer SDK" << std::endl;
        goto cleanup;
    }

    std::cout << "Get all possible resolutions" << std::endl;
    if ((ret = hLLT->GetResolutions(&resolutions[0], MAX_RESOLUTION)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error GetResolutions!" << std::endl;
        goto cleanup;
    }

    // set Resolution to max
    resolution = resolutions[0];

    if (hLLT->SetResolution(resolution) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting transmission mode!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetProfileConfig(PROFILE) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting SetProfileConfig!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_IDLE_TIME, idle_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting FEATURE_FUNCTION_IDLE_TIME!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_EXPOSURE_TIME, exposure_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting FEATURE_FUNCTION_EXPOSURE_TIME!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting FEATURE_FUNCTION_TRIGGER!" << std::endl;
        goto cleanup;
    }

    std::cout << "Register callbacks" << std::endl;

    // register Callbacks for program handling
    if (hLLT->RegisterBufferCallback((gpointer)&NewProfile, NULL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering buffer callback!" << std::endl;
        goto cleanup;
    }

    if (hLLT->RegisterControlLostCallback((gpointer)&ControlLostCallback, NULL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if (GetProfilesCallback() < GENERAL_FUNCTION_OK) {
        std::cout << "Error in GetProfiles_Callback!" << std::endl;
        goto cleanup;
    }

    // disconnect to sensor
    std::cout << "Disconnect" << std::endl;
    if ((ret = hLLT->Disconnect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while disconnecting to camera - Error " << ret << "!" << std::endl;
    }

cleanup:
    delete hLLT;
    CInterfaceLLT::FreeEvent(event);
}

gint32 GetProfilesCallback()
{
    gint32 ret = 0;
    profile_count = 0;

    std::vector<double> value_x, value_z;
    needed_profile_count = 100;

    std::cout << "Get profiles via callback" << std::endl;

    profile_buffer.resize(resolution * 64);

    value_x.resize(resolution);
    value_z.resize(resolution);

    CInterfaceLLT::ResetEvent(event);

    // setup transfer of multiple profiles
    if ((ret = hLLT->TransferProfiles(NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in profile transfer! " << ret << "" << std::endl;
        return ret;
    }

    std::cout << "Start acquisition of profiles" << std::endl;
    if (CInterfaceLLT::WaitForSingleObject(event, 5000) != WAIT_OBJECT_0) {
        std::cout << "Timeout!" << std::endl;
    }

    // stop transfer
    if ((ret = hLLT->TransferProfiles(NORMAL_TRANSFER, false)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while stopping transmission!" << std::endl;
        return ret;
    }

    if (profile_count == needed_profile_count && profile_data_size == profile_buffer.size()) {
        std::cout << "1: All " << profile_count << " profiles reveived with correct size" << std::endl;
    } else {
        std::cout << "1: Wrong profile count: " << profile_count << "" << std::endl;
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    // display example points
    if ((ret = CInterfaceLLT::ConvertProfile2Values(&profile_buffer[0], profile_buffer.size(), resolution, PROFILE, llt_type, 0,
                                                    NULL, NULL, NULL, &value_x[0], &value_z[0], NULL, NULL)) !=
        (CONVERT_X | CONVERT_Z)) {
        std::cout << "Error while extracting profiles" << std::endl;
        return ret;
    }

    DisplayProfiles(&value_x[0], &value_z[0], resolution);
    DisplayTimestamp(&profile_buffer[(resolution * 64) - 16]);

    return GENERAL_FUNCTION_OK;
}

void NewProfile(const void *data, size_t data_size, gpointer user_data)
{
    if (data_size == profile_buffer.size() && profile_count < needed_profile_count) {
        profile_data_size = data_size;
        memcpy(&profile_buffer[0], data, data_size);
        profile_count++;

        CInterfaceLLT::Timestamp2TimeAndCount(&profile_buffer[(resolution * 64) - 16], &shutter_closed, &shutter_opened,
                                              &profile_counter, NULL);
        if (first_trans > 3) {
            if ((profile_counter != old_profile_counter + 1) ||
                !(profile_counter == 0 && old_profile_counter == 16777215))
                lost_profiles += profile_counter - old_profile_counter - 1;
        } else {
            first_trans++;
        }
        old_profile_counter = profile_counter;
        std::cout << "PC: " << profile_counter << " LP: " << lost_profiles << " \r";
    }
    if (profile_count >= needed_profile_count) {
        set_event(event);
    }
}

void ControlLostCallback(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    std::cout << "Control lost" << std::endl;
    exit(0);
}

void DisplayProfiles(double *x, double *z, guint32 resolution)
{
    for (guint32 i = 0; i < resolution; i++) {
        std::cout << "\rX: " << x[i] << "  Z: " << z[i];
        usleep(1250);
    }
    std::cout << std::endl;
}

void DisplayTimestamp(guchar *timestamp)
{
    double shutter_open = 0.0, shutter_close = 0.0;
    guint32 profile_count = 0;

    CInterfaceLLT::Timestamp2TimeAndCount(&timestamp[0], &shutter_open, &shutter_close, &profile_count, NULL);

    std::cout.precision(8);
    std::cout << "Profile Count: " << profile_count << " ShutterOpen: " << shutter_open
              << " ShutterClose: " << shutter_close << std::endl;
    std::cout.precision(6);
}
