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

#include "PartialProfileMultiLLT.h"

int main()
{
    gint32 ret = 0;

    std::vector<char *> interfaces(MAX_INTERFACE_COUNT);
    std::vector<guint32> resolutions(MAX_RESOLUTION);
    guint32 interface_count = 0;

    guint32 idle_time = 3900;
    guint32 exposure_time = 100;

    // example user data
    gint32 llt_id1 = 1;
    gint32 llt_id2 = 2;

    if ((ret = CInterfaceLLT::GetDeviceInterfaces(&interfaces[0], interfaces.size())) ==
        ERROR_GETDEVINTERFACE_REQUEST_COUNT) {
        std::cout << "There are more than " << interfaces.size() << " scanCONTROL connected" << std::endl;
        interface_count = interfaces.size();
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
        std::cout << "There is 1 scanCONTROL connected" << std::endl;
    } else {
        std::cout << "There are " << interface_count << " scanCONTROL connected" << std::endl;
    }

    if (interface_count < 2) {
        std::cout << "Please connect 2 scanCONTROL" << std::endl;
        goto cleanup;
    }

    for (guint32 i = 0; i < interface_count; i++) {
        std::cout << interfaces[i] << std::endl;
    }

    // make a new instance for each LLT
    hLLT = new CInterfaceLLT();
    hLLT_2 = new CInterfaceLLT();
    event = CInterfaceLLT::CreateEvent();

    if ((hLLT->SetDeviceInterface(interfaces[0])) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting dev id " << ret << "!" << std::endl;
        goto cleanup;
    }
    if ((hLLT_2->SetDeviceInterface(interfaces[1])) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting dev id " << ret << "!" << std::endl;
        goto cleanup;
    }

    // connect to sensors
    if ((ret = hLLT->Connect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << std::endl;
        goto cleanup;
    }
    if ((ret = hLLT_2->Connect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << std::endl;
        goto cleanup;
    }

    if ((ret = hLLT->GetLLTType(&llt_type)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while GetLLTType!" << std::endl;
        goto cleanup;
    }

    if (llt_type >= scanCONTROL27xx_25 && llt_type <= scanCONTROL27xx_xxx) {
        std::cout << "The scanCONTROL 1 is a scanCONTROL27xx" << std::endl;
    } else if (llt_type >= scanCONTROL26xx_25 && llt_type <= scanCONTROL26xx_xxx) {
        std::cout << "The scanCONTROL 1 is a scanCONTROL26xx" << std::endl;
    } else if (llt_type >= scanCONTROL29xx_25 && llt_type <= scanCONTROL29xx_xxx) {
        std::cout << "The scanCONTROL 1 is a scanCONTROL29xx" << std::endl;
    } else if (llt_type >= scanCONTROL30xx_25 && llt_type <= scanCONTROL30xx_xxx) {
        std::cout << "The scanCONTROL 1 is a scanCONTROL30xx" << std::endl;
    } else if (llt_type >= scanCONTROL25xx_25 && llt_type <= scanCONTROL25xx_xxx) {
        std::cout << "The scanCONTROL 1 is a scanCONTROL25xx" << std::endl;
    } else {
        std::cout << "The scanCONTROL 1 is a undefined type\nPlease contact Micro-Epsilon for a newer SDK" << std::endl;
        goto cleanup;
    }

    if ((ret = hLLT_2->GetLLTType(&llt_type_2)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while GetLLTType!" << std::endl;
        goto cleanup;
    }
    
    if (llt_type_2 >= scanCONTROL27xx_25 && llt_type_2 <= scanCONTROL27xx_xxx) {
        std::cout << "The scanCONTROL 2 is a scanCONTROL27xx" << std::endl;
    } else if (llt_type_2 >= scanCONTROL26xx_25 && llt_type_2 <= scanCONTROL26xx_xxx) {
        std::cout << "The scanCONTROL 2 is a scanCONTROL26xx" << std::endl;
    } else if (llt_type_2 >= scanCONTROL29xx_25 && llt_type_2 <= scanCONTROL29xx_xxx) {
        std::cout << "The scanCONTROL 2 is a scanCONTROL29xx" << std::endl;
    } else if (llt_type_2 >= scanCONTROL30xx_25 && llt_type_2 <= scanCONTROL30xx_xxx) {
        std::cout << "The scanCONTROL 2 is a scanCONTROL30xx" << std::endl;
    } else if (llt_type_2 >= scanCONTROL25xx_25 && llt_type_2 <= scanCONTROL25xx_xxx) {
        std::cout << "The scanCONTROL 2 is a scanCONTROL25xx" << std::endl;
    } else {
        std::cout << "The scanCONTROL 2 is a undefined type\nPlease contact Micro-Epsilon for a newer SDK" << std::endl;
        goto cleanup;
    }

    std::cout << "Get all possible resolutions" << std::endl;
    if ((ret = hLLT->GetResolutions(&resolutions[0], resolutions.size())) < GENERAL_FUNCTION_OK) {
        std::cout << "Error GetResolutions!" << std::endl;
        goto cleanup;
    }

    resolution = resolutions[0];

    if (hLLT->SetResolution(resolution) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting transmission mode!" << std::endl;
        goto cleanup;
    }

    if ((ret = hLLT_2->GetResolutions(&resolutions[0], resolutions.size())) < GENERAL_FUNCTION_OK) {
        std::cout << "Error GetResolutions!" << std::endl;
        goto cleanup;
    }

    resolution_2 = resolutions[0];

    if (hLLT_2->SetResolution(resolution_2) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting transmission mode!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetProfileConfig(PARTIAL_PROFILE) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting SetProfileConfig!" << std::endl;
        goto cleanup;
    }

    if (hLLT_2->SetProfileConfig(PARTIAL_PROFILE) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting SetProfileConfig!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_IDLE_TIME, idle_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_EXPOSURE_TIME, exposure_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    if (hLLT_2->SetFeature(FEATURE_FUNCTION_IDLE_TIME, idle_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    if (hLLT_2->SetFeature(FEATURE_FUNCTION_EXPOSURE_TIME, exposure_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    if (hLLT_2->SetFeature(FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    std::cout << "Register callbacks" << std::endl;

    // register Callbacks
    if ((hLLT->RegisterBufferCallback((gpointer)&NewProfile, &llt_id1)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering buffer callback!" << std::endl;
        goto cleanup;
    }

    if ((hLLT->RegisterControlLostCallback((gpointer)&ControlLostCallback, &llt_id1)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if ((hLLT_2->RegisterBufferCallback((gpointer)&NewProfile, &llt_id2)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering buffer callback!" << std::endl;
        goto cleanup;
    }

    if ((hLLT_2->RegisterControlLostCallback((gpointer)&ControlLostCallback, &llt_id2)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if (MultiLLT() < GENERAL_FUNCTION_OK) {
        std::cout << "Error in GetProfiles_Callback!" << std::endl;
        goto cleanup;
    }

    // disconnect to sensor
    std::cout << "Disconnect" << std::endl;
    if ((ret = hLLT->Disconnect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << std::endl;
        goto cleanup;
    }
    if ((ret = hLLT_2->Disconnect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << std::endl;
    }

cleanup:
    delete hLLT;
    delete hLLT_2;
    CInterfaceLLT::FreeEvent(event);
}

gint32 MultiLLT()
{
    gint32 ret = 0;
    profile_count = 0;
    profile_count_2 = 0;

    std::vector<double> value_x, value_z, value_x_2, value_z_2;

    // set Partial Profile Settings for each sensor (X/Z only - saves bandwidth)
    TPartialProfile partial_profile, partial_profile_2;

    partial_profile.nStartPoint = 0;
    partial_profile.nStartPointData = 4;
    partial_profile.nPointCount = resolution;
    partial_profile.nPointDataWidth = 4;

    partial_profile_2.nStartPoint = 0;
    partial_profile_2.nStartPointData = 4;
    partial_profile_2.nPointCount = resolution_2;
    partial_profile_2.nPointDataWidth = 4;

    needed_profile_count = 50;
    needed_profile_count_2 = 50;

    std::cout << "Get profiles from multiple scanners via callback" << std::endl;

    profile_buffer.resize(partial_profile.nPointCount * partial_profile.nPointDataWidth);
    value_x.resize(partial_profile.nPointCount);
    value_z.resize(partial_profile.nPointCount);

    profile_buffer_2.resize(partial_profile_2.nPointCount * partial_profile_2.nPointDataWidth);
    value_x_2.resize(partial_profile_2.nPointCount);
    value_z_2.resize(partial_profile_2.nPointCount);

    // setup partial profile transmission
    if ((ret = hLLT->SetPartialProfile(&partial_profile)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in set partial profile: " << ret << std::endl;
        return ret;
    }

    // setup partial profile transmission
    if ((ret = hLLT_2->SetPartialProfile(&partial_profile_2)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in set partial profile: " << ret << std::endl;
        return ret;
    }

    // setup transfer of multiple profiles
    if ((ret = hLLT->TransferProfiles(NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in profile transfer!" << std::endl;
        return ret;
    }

    if ((ret = hLLT_2->TransferProfiles(NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in profile transfer!" << std::endl;
        return ret;
    }

    std::cout << "Start aquisition of profiles" << std::endl;

    CInterfaceLLT::ResetEvent(event);

    if (CInterfaceLLT::WaitForSingleObject(event, 2000) != 0) {
        std::cout << "Timeout!" << std::endl;
    }

    // Stop transfer
    if ((ret = hLLT->TransferProfiles(NORMAL_TRANSFER, false)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in stopping profile transfer! " << ret << std::endl;
        return ret;
    }

    if ((ret = hLLT_2->TransferProfiles(NORMAL_TRANSFER, false)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in stopping profile transfer! " << ret << std::endl;
        return ret;
    }

    if (profile_count == needed_profile_count && profile_data_size == profile_buffer.size()) {
        std::cout << "1: All " << profile_count << " profiles reveived with correct size" << std::endl;
    } else {
        std::cout << "1: Wrong profile count: " << profile_count << std::endl;
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    if (profile_count_2 == needed_profile_count_2 && profile_data_size_2 == profile_buffer_2.size()) {
        std::cout << "2: All " << profile_count_2 << " profiles reveived with correct size" << std::endl;
    } else {
        std::cout << "2: Wrong profile count: " << profile_count_2 << std::endl;
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    // display example points
    if ((ret = CInterfaceLLT::ConvertPartProfile2Values(&profile_buffer[0], profile_buffer.size(), &partial_profile,
                                                        llt_type, 0, NULL, NULL, NULL, &value_x[0], &value_z[0], NULL,
                                                        NULL)) != (CONVERT_X | CONVERT_Z)) {
        std::cout << "Error while extracting profiles (scanner 1)" << std::endl;
        return ret;
    }
	
    if ((ret = CInterfaceLLT::ConvertPartProfile2Values(
             &profile_buffer_2[0], profile_buffer_2.size(), &partial_profile_2, llt_type_2, 0, NULL, NULL, NULL,
             &value_x_2[0], &value_z_2[0], NULL, NULL)) != (CONVERT_X | CONVERT_Z)) {
        std::cout << "Error while extracting profiles (scanner 2)" << std::endl;
        return ret;
    }

    DisplayProfiles(&value_x[0], &value_z[0], partial_profile.nPointCount - 4);
    DisplayTimestamp(&profile_buffer[(partial_profile.nPointCount * partial_profile.nPointDataWidth) - 16]);

    DisplayProfiles(&value_x_2[0], &value_z_2[0], partial_profile_2.nPointCount - 4);
    DisplayTimestamp(&profile_buffer_2[(partial_profile_2.nPointCount * partial_profile_2.nPointDataWidth) - 16]);

    return GENERAL_FUNCTION_OK;
}

void NewProfile(const void *data, size_t data_size, gpointer user_data)
{
    if (data != NULL && *(gint32 *)user_data == 1 && data_size == profile_buffer.size() &&
        profile_count < needed_profile_count) {
        profile_data_size = data_size;
        memcpy(&profile_buffer[0], data, data_size);
        profile_count++;
    }
    if (data != NULL && *(gint32 *)user_data == 2 && data_size == profile_buffer_2.size() &&
        profile_count_2 < needed_profile_count_2) {
        profile_data_size_2 = data_size;
        memcpy(&profile_buffer_2[0], data, data_size);
        profile_count_2++;
    }
    if (profile_count >= needed_profile_count && profile_count_2 >= needed_profile_count_2) {
        CInterfaceLLT::SetEvent(event);
    }
}

void ControlLostCallback(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    if (*(gint32 *)user_data == 1) {
        std::cout << "Control lost Sensor 1" << std::endl;
    }
    if (*(gint32 *)user_data == 2) {
        std::cout << "Control lost Sensor 2" << std::endl;
    }
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
