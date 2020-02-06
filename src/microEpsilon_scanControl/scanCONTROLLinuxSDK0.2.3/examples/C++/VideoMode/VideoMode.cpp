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

#include "VideoMode.h"

gint32 main()
{
    gint32 ret = 0;

    char *interfaces[MAX_INTERFACE_COUNT];
    guint32 resolutions[MAX_RESOLUTION];
    guint32 interface_count = 0;

    guint32 idle_time = 3900;
    guint32 exposure_time = 200;

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
        std::cout << "There is 1 scanCONTROL connected" << std::endl;
    } else {
        std::cout << "There are " << interface_count << " scanCONTROL connected" << std::endl;
    }

    for (guint32 i = 0; i < interface_count; i++) {
        std::cout << interfaces[i] << std::endl;
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

    resolution = resolutions[0];

    if (hLLT->SetResolution(resolution) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting transmission mode!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetProfileConfig(VIDEO_IMAGE) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting SetProfileConfig!" << std::endl;
        goto cleanup;
    }

    if (hLLT->SetPacketSize(1024) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while setting SetPacketSize!" << std::endl;
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

    if (GetVideoImage() < GENERAL_FUNCTION_OK) {
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

gint32 GetVideoImage()
{
    gint32 ret = 0;

    std::cout << "Get video image via callback" << std::endl;

    guint32 width = 0, height = 0; 
    TTransferVideoType video_type = VIDEO_MODE_1;
     if (llt_type >= scanCONTROL30xx_25 && llt_type <= scanCONTROL30xx_xxx) {
        video_type = VIDEO_MODE_0;
    }

    CInterfaceLLT::ResetEvent(event);

    // setup transfer of multiple profiles
    if ((ret = hLLT->TransferVideoStream(video_type, true, &width, &height)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error in profile transfer!" << std::endl;
        return ret;
    }

    profile_buffer.resize(width * height);

    std::cout << "Start aquisition of profiles" << std::endl;
    if (CInterfaceLLT::WaitForSingleObject(event, 1000) != 0) {
        std::cout << "Timeout!" << std::endl;
    }

    // stop transfer
    if ((ret = hLLT->TransferVideoStream(video_type, false, NULL, NULL)) < GENERAL_FUNCTION_OK) {
        std::cout << "Error while stopping transmission!" << std::endl;
        return ret;
    }

    if (profile_data_size == profile_buffer.size()) {
        std::cout << "Video image received - write bitmap" << std::endl;
        if (WriteBMP("video_image.bmp", width, height, &profile_buffer[0]) < GENERAL_FUNCTION_OK) {
            std::cout << "Error while writing video image to bitmap" << std::endl;
        } else {
            std::cout << "Video image succefully written" << std::endl;
        }
    } else {
        std::cout << "Error while receiving video image!" << std::endl;
    }

    return GENERAL_FUNCTION_OK;
}

void NewProfile(const void *data, size_t data_size, gpointer user_data)
{
    if (data != NULL && data_size == profile_buffer.size()) {
        profile_data_size = data_size;
        memcpy(&profile_buffer[0], data, data_size);
        CInterfaceLLT::SetEvent(event);
    }
}

void ControlLostCallback(gpointer user_data)
{
    // Control of the device is lost. Display a message and exit!
    std::cout << "Control lost" << std::endl;
    exit(0);
}

gint32 WriteBMP(const char *filename, gint32 width, gint32 height, guint8 *gray8)
{
    // The following code is free to use in any project and was found on:
    // http://cpansearch.perl.org/src/DHUNT/PDL-Planet-0.05/libimage/bmp.c (c) 2002 Hari Nair

    gint32 bytesPerLine = 0;
    guint8 *line;

    FILE *file;
    BMPFileHeader bmfh;
    BMPInfoHeader bmih;
    memset(&bmfh, 0, sizeof(BMPFileHeader));
    memset(&bmih, 0, sizeof(BMPInfoHeader));

    gint32 number_colors = 256;
    RGBQuad greyscale[number_colors];

    gint32 color_size = number_colors * sizeof(RGBQuad);
    gint32 header_offset = 14 + 40 + color_size;

    // The length of each line must be a multiple of 4 bytes
    bytesPerLine = ((width + 1) / 4) * 4;

    // create the color palette
    for (gint32 i = 0; i < number_colors; i++) {
        greyscale[i].rgbBlue = i;
        greyscale[i].rgbGreen = i;
        greyscale[i].rgbRed = i;
        greyscale[i].rgbReserved = 0;
    }

    // File header
    bmfh.bfType = 0x4D42;
    bmfh.bfOffBits = header_offset;
    bmfh.bfSize = bmfh.bfOffBits + bytesPerLine * height;
    bmfh.bfReserved = 0;

    // Info header
    bmih.biSize = 40;
    bmih.biWidth = width;
    bmih.biHeight = height;
    bmih.biPlanes = 1;
    bmih.biBitCount = 8;
    bmih.biCompression = 0;
    bmih.biSizeImage = bytesPerLine * height;
    bmih.biXPelsPerMeter = 0;
    bmih.biYPelsPerMeter = 0;
    bmih.biClrUsed = number_colors;
    bmih.biClrImportant = 0;

    file = fopen(filename, "wb");
    if (file == NULL) {
        std::cout << "Error opening file" << std::endl;
        return 0;
    }

    // Write struct member for member because of alignment
    fwrite(&bmfh.bfType, 2, 1, file);
    fwrite(&bmfh.bfSize, 4, 1, file);
    fwrite(&bmfh.bfReserved, 4, 1, file);
    fwrite(&bmfh.bfOffBits, 4, 1, file);

    // Write info header and color palette
    fwrite(&bmih, sizeof(BMPInfoHeader), 1, file);
    fwrite(&greyscale, sizeof(greyscale), 1, file);

    line = (guint8 *)malloc(bytesPerLine);
    if (line == NULL) {
        std::cout << "Can't allocate memory for BMP file" << std::endl;
        fclose(file);
        return 0;
    }

    gint32 x = 0, y = 0;

    for (y = height - 1; y >= 0; y--) {
        for (x = 0; x < width; x++) {
            line[width - x - 1] = gray8[x + width * y];
        }
        fwrite(line, bytesPerLine, 1, file);
    }

    free(line);
    fclose(file);

    return GENERAL_FUNCTION_OK;
}
