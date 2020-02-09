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

#include "ContainerMode.h"

gint32 main()
{
    gint32 ret = 0;

    std::vector<char *> interfaces(MAX_INTERFACE_COUNT);
    std::vector<guint32> resolutions(MAX_RESOLUTION);
    guint32 interface_count = 0;

    guint32 idle_time = 900;
    gint32 exposure_time = 100;

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
    event = CInterfaceLLT::CreateEvent();

    if ((hLLT->SetDeviceInterface(interfaces[0])) < GENERAL_FUNCTION_OK) {
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
        std::cout << "Can't decode scanCONTROL type. Please contact Micro Epsilon for a newer version "
                     "of the library."
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
    if ((ret = hLLT->GetResolutions(&resolutions[0], resolutions.size())) < GENERAL_FUNCTION_OK) {
        std::cout << "Error GetResolutions!" << std::endl;
        goto cleanup;
    }

    resolution = resolutions[0];

    if (hLLT->SetResolution(resolution) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting transmission mode!" << std::endl;
        goto cleanup;
    }

    if ((hLLT->SetProfileConfig(CONTAINER)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting BufferCount!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_IDLE_TIME, idle_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting idle_time!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_EXPOSURE_TIME, exposure_time) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting exposure_time!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetFeature(FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting trigger!" << std::endl;
        goto cleanup;
    }

    std::cout << "Set PacketSize" << std::endl;
    if ((ret = hLLT->SetPacketSize(320)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during SetPacketSize!" << std::endl;
        goto cleanup;
    }

    std::cout << "Register callbacks" << std::endl;

    // register Callbacks for program handling
    if ((hLLT->RegisterBufferCallback((gpointer)&NewProfile, NULL)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering buffer callback!" << std::endl;
        goto cleanup;
    }

    if ((hLLT->RegisterControlLostCallback((gpointer)&ControlLostCallback, NULL)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while registering control lost callback!" << std::endl;
        goto cleanup;
    }

    if (ContainerMode() < GENERAL_FUNCTION_OK) {
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
    CInterfaceLLT::FreeEvent(event);
}

gint32 ContainerMode()
{
    gint32 ret = 0;
    gint32 field_count = 5;
    gint32 profile_count = 256;
    container_count = 0;
    needed_container_count = 1;
    guint32 inquiry_value = 0;

    // calculate resolution bitfield for the container
    double tmp_log = 1.0 / log(2.0);
    gint32 container_resolution = (gint32)floor((log((double)resolution) * tmp_log) + 0.5);

    std::cout << "Demonstrate the container mode with rearrangement" << std::endl;
    if ((ret = hLLT->GetFeature(INQUIRY_FUNCTION_REARRANGEMENT_PROFILE, &inquiry_value)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during GetFeature" << std::endl;
        return ret;
    }
    if ((inquiry_value & 0x80000000) == 0) {
        std::cout << "The connected scanCONTROL doesn't support container mode" << std::endl;
        return ret;
    }

    // extract z
    // extract only 1st reflection
    std::cout << "Set rearrangement parameter" << std::endl;
    if ((ret = hLLT->SetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT,
                                CONTAINER_DATA_INTENS | CONTAINER_DATA_WIDTH | CONTAINER_DATA_THRES | CONTAINER_DATA_X |
                                CONTAINER_DATA_Z | CONTAINER_STRIPE_1 | CONTAINER_DATA_LSBF |
                                container_resolution << 12)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during SetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT)" << std::endl;;
        return ret;
    }

    std::cout << "Set profile container size" << std::endl;
    if ((ret = hLLT->SetProfileContainerSize(0, profile_count)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error during SetProfileContainerSize" << std::endl;;
        return ret;
    }

    container_buffer.resize(resolution * field_count * profile_count * 2);

    CInterfaceLLT::ResetEvent(event);

    // setup transfer of multiple profiles
    if ((ret = hLLT->TransferProfiles(NORMAL_CONTAINER_MODE, true)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in profile transfer!" << std::endl;
        return ret;
    }

    std::cout << "Start aquisition of profiles" << std::endl;
    if (CInterfaceLLT::WaitForSingleObject(event, 4000) != 0) {
        std::cout << "Timeout!" << std::endl;
    }

    // stop transfer
    if ((ret = hLLT->TransferProfiles(NORMAL_CONTAINER_MODE, false)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while stopping transmission!" << std::endl;
        return ret;
    }

    if (container_count == needed_container_count && profile_data_size == container_buffer.size()) {
        std::cout << "1: All " << container_count << " container reveived with correct size" << std::endl;
    } else {
        std::cout << "Wrong container count: " << container_count << std::endl;
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    guint32 rearrangement = 0;
    hLLT->GetFeature(FEATURE_FUNCTION_PROFILE_REARRANGEMENT, &rearrangement);
    std::vector<double> value_x, value_z;
    std::vector<gushort> intens, thres, refl_width;
    value_x.resize(resolution * profile_count);
    value_z.resize(resolution * profile_count);
    intens.resize(resolution * profile_count);
    thres.resize(resolution * profile_count);
    refl_width.resize(resolution * profile_count);

    ret = CInterfaceLLT::ConvertRearrangedContainer2Values(&container_buffer[0], container_buffer.size(), rearrangement,
                                                           profile_count, llt_type, 0, &refl_width[0], &intens[0],
                                                           &thres[0], &value_x[0], &value_z[0]);
    if (ret != (CONVERT_X | CONVERT_Z | CONVERT_THRESHOLD | CONVERT_WIDTH | CONVERT_MAXIMUM)) {
        std::cout << "Error while extracting profiles" << std::endl;
        return ret;
    }

    DisplayContainer(&value_x[0], &value_z[0], &refl_width[0], &intens[0], &thres[0], resolution);

    std::cout << "Writing container data to 16-bit png" << std::endl;
    if (WriteImage("container.png", resolution * field_count, profile_count, &container_buffer[0]) != 0) {
        std::cout << "Writing container to png failed" << std::endl;
    } else {
        std::cout << "Writing container data successful" << std::endl;
    }

    return GENERAL_FUNCTION_OK;
}

void NewProfile(const void *data, size_t data_size, gpointer user_data)
{
    if (data != NULL) {
        if (container_buffer.size() == data_size && container_count < needed_container_count) {
            memcpy(&container_buffer[0], data, data_size);
            profile_data_size = data_size;
            container_count++;
        }
    }
    if (container_count >= needed_container_count) {
        CInterfaceLLT::SetEvent(event);
    }
}

void ControlLostCallback(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    std::cout << "Control lost" << std::endl;
    exit(0);
}

gint32 WriteImage(const char *filename, gint32 width, gint32 height, guint8 *buffer)
{
    // The following code is free to use in any project and was found on:
    // http://www.labbookpages.co.uk/software/imgProc/libPNG.html (c) Dr. Andrew Greensted 2013

    gint32 ret = 0;
    FILE *fp = NULL;
    png_structp hpng = NULL;
    png_infop hpng_info = NULL;
    png_bytep row = NULL;

    // Open file for writing (binary mode)
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        std::cout << "Could not open file " << filename << " for writing" << std::endl;
        ret = 1;
        goto finalise;
    }

    // The write structure contains information about how the PNG file will be written (or read).
    // The info structure contains information about the PNG image that will be written into the
    // actual file. This allow programmes to find out characteristics of the image.

    // Initialize write structure
    hpng = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (hpng == NULL) {
        std::cout << "Could not allocate write struct" << std::endl;
        ret = 1;
        goto finalise;
    }

    // Initialize info structure
    hpng_info = png_create_info_struct(hpng);
    if (hpng_info == NULL) {
        std::cout << "Could not allocate info struct" << std::endl;
        ret = 1;
        goto finalise;
    }

    // Setup Exception handling
    if (setjmp(png_jmpbuf(hpng))) {
        std::cout << "Error during png creation" << std::endl;
        ret = 1;
        goto finalise;
    }

    // Various meta data for the image is now set, such as the size and the colour depth per
    // channel.
    png_init_io(hpng, fp);

    // Write header (16 bit colour depth)
    png_set_IHDR(hpng, hpng_info, width, height, 16, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE,
                 PNG_FILTER_TYPE_BASE);

    png_write_info(hpng, hpng_info);

    // Now the image data is written one row at a time

    // Allocate memory for one row (2 bytes per pixel - 16 bit gray)
    row = (png_bytep)malloc(2 * width * sizeof(png_byte));

    // Write image data
    gint32 x, y;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width * 2; x += 2) {
            row[x] = buffer[x + 1 + width * 2 * y];
            row[x + 1] = buffer[x + width * 2 * y];
        }
        png_write_row(hpng, row);
    }

    // End write
    png_write_end(hpng, NULL);

    // Clean up
finalise:
    if (fp != NULL)
        fclose(fp);
    if (hpng_info != NULL)
        png_free_data(hpng, hpng_info, PNG_FREE_ALL, -1);
    if (hpng != NULL)
        png_destroy_write_struct(&hpng, (png_infopp)NULL);
    if (row != NULL)
        free(row);

    return ret;
}

void DisplayContainer(double *x, double *z, unsigned short *width, unsigned short *intens, unsigned short *thres,
                      guint32 resolution)
{
    for (guint32 i = 0; i < resolution; i += resolution / 80) {
        std::cout << "X: " << x[i] << "\tZ: " << z[i] << "\tW: " << width[i] << "\tI: " << intens[i]
                  << "\tT: " << thres[i] << std::endl;
        usleep(1000);
    }
    std::cout << std::endl;
}
