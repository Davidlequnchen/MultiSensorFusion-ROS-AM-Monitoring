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

#include "LLTPeakFilter.h"

gint32 main()
{
    gint32 ret = 0;
    std::vector<char *> interfaces(MAX_INTERFACE_COUNT);
    gint32 interface_count = 0;

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
        std::cout << "There is 1 scanCONTROL connected " << std::endl;
    } else {
        std::cout << "There are " << interface_count << " scanCONTROL connected " << std::endl;
    }

    for (gint32 i = 0; i < interface_count; i++) {
        std::cout << interfaces[i] << std::endl;
    }

    // new LLT instance
    hLLT = new CInterfaceLLT();

    if ((hLLT->SetDeviceInterface(interfaces[0])) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting dev id " << ret << "!" << std::endl;
        goto cleanup;
    }

    // Connect to sensor */
    if ((ret = hLLT->Connect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << "!" << std::endl;
        goto cleanup;
    }

    std::cout << "Register callbacks" << std::endl;

    if ((hLLT->RegisterControlLostCallback((gpointer)&ControlLostCallback, NULL)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if (SetPeakFilters() < GENERAL_FUNCTION_OK) {
        std::cout << "Error in GetProfiles_Callback!" << std::endl;
        goto cleanup;
    }

    // Disconnect to sensor
    std::cout << "Disconnect" << std::endl;
    if ((ret = hLLT->Disconnect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << "!" << std::endl;
    }

cleanup:
    delete hLLT;
}

gint32 SetPeakFilters()
{
    gint32 ret = 0;

    // set the desired PeakFilter values:
    ushort min_width = 2;
    ushort max_width = 256;
    ushort min_intensity = 0;
    ushort max_intensity = 1023;

    // peak filter - possibility 1

    // write peak filter settings to sensor
    std::cout << "Write Peak filter:" << std::endl;
    std::cout << " - Min width: " << min_width << "\n - Max width: " << max_width << std::endl;
    std::cout << " - Min intensity: " << min_intensity << "\n - Max intensity: " << max_intensity << std::endl;
    if ((ret = hLLT->SetPeakFilter(min_width, max_width, min_intensity, max_intensity)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting peak values" << ret << std::endl;
    }

    // peak filter - possibility 2 --> reading parameters with GetFeature also possible
    // available since scanCONTROL firmware version v43

    // write min/max intensity
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_PEAKFILTER_HEIGHT,  (max_intensity << 16) + min_intensity)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting peak values" << ret << std::endl;
    }
    // write min/max width
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_PEAKFILTER_WIDTH, (max_width << 16) + min_width)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting peak values" << ret << std::endl;
    }
    // activate settings
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_EXTRA_PARAMETER, 0) < GENERAL_FUNCTION_OK)) {
        std::cout << "Error during setting peak values" << ret << std::endl;
    }

    // set the desired free measuring field
    ushort start_z = 20000;
    ushort size_z = 25000;
    ushort start_x = 20000;
    ushort size_x = 25000;

    // measuring field - possibility 1

    // write free measuring field settings to sensor
    std::cout << "Write free measuring field:\n - Start z: " << start_z << "\n - Size z: " << size_z
              << "\n - Start x: " << start_x << "\n - Size x: " << size_x << std::endl;
    // enable the free measuring field
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_MEASURINGFIELD, ROI1_FREE_REGION)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }
    // set the values
    if ((ret = hLLT->SetFreeMeasuringField(start_z, size_z, start_x, size_x)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }

    // measuring field - possibility 2 --> reading parameters with GetFeature also possible
    // available since scanCONTROL firmware version v43

    // enable the free measuring field
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_MEASURINGFIELD, ROI1_FREE_REGION)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }
    // write start/size x
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_ROI1_POSITION, (size_x << 16) + start_x)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }
    // write start/size z
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_ROI1_DISTANCE, (size_z << 16) + start_z)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }
    // activate settings
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_EXTRA_PARAMETER, 0)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during setting the free measuring field" << ret << std::endl;
        return ret;
    }

    return GENERAL_FUNCTION_OK;
}

void ControlLostCallback(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    std::cout << "Control lost" << std::endl;
    exit(0);
}
