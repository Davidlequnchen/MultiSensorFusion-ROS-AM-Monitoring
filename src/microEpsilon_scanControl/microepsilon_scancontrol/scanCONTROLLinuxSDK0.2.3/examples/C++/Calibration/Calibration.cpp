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

#include "Calibration.h"

gint32 main()
{
    gint32 ret = 0;
    std::vector<char *> interfaces(MAX_INTERFACE_COUNT);
    guint32 interface_count = 0;

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

    for (guint32 i = 0; i < interface_count; i++) {
        std::cout << interfaces[i] << "" << std::endl;
    }

    // new LLT instance
    hLLT = new CInterfaceLLT();

    if ((hLLT->SetDeviceInterface(interfaces[0])) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting dev id " << ret << "!" << std::endl;
        goto cleanup;
    }

    // connect to sensor
    if ((ret = hLLT->Connect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << "!" << std::endl;
        goto cleanup;
    }

    std::cout << "Register callbacks" << std::endl;

    if ((hLLT->RegisterControlLostCallback((gpointer)&ControlLostCallback, NULL)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if (Calibration() < GENERAL_FUNCTION_OK) {
        std::cout << "Error in GetProfiles_Callback!" << std::endl;
        goto cleanup;
    }

    // disconnect to sensor
    std::cout << "Disconnect" << std::endl;
    if ((ret = hLLT->Disconnect()) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while connecting to camera - Error " << ret << "!" << std::endl;
    }

cleanup:
    delete hLLT;
}

gint32 Calibration()
{
    gint32 ret = 0;

    // custom calibration - possibility 1

    // center of rotation and angle
    double center_x = 0;   // mm
    double center_z = 95; // mm
    double angle = -2;     // deg

    // rotation center is shifted by
    double shift_x = -2; // mm
    double shift_z = -2; // mm

    std::cout << "Set Calibration" << std::endl;
    if ((ret = hLLT->SetCustomCalibration(center_x, center_z, angle, shift_x, shift_z)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    //std::cout << "Reset Calibration" << std::endl;
    //if ((ret = hLLT->ResetCustomCalibration()) < GENERAL_FUNCTION_OK) {
    //    return ret;
    //}

    // custom calibration - possibility 2 --> reading parameters with GetFeature also possible
    // available since scanCONTROL firmware version v43

    // --> see Developer Tool

    return GENERAL_FUNCTION_OK;
}

void ControlLostCallback(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    std::cout << "Control lost" << std::endl;
    exit(0);
}
