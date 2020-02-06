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

#ifndef VIDEOMODE_H
#define VIDEOMODE_H

#include <iostream>
#include <llt.h>
#include <vector>

#define MAX_INTERFACE_COUNT 5
#define MAX_RESOLUTION 6

gint32 GetVideoImage(void);

void NewProfile(const void *, size_t, gpointer);
void ControlLostCallback(gpointer ptr);

CInterfaceLLT *hLLT;
guint32 resolution;
std::vector<guint8> profile_buffer;
TScannerType llt_type;
guint32 profile_data_size;

gint32 WriteBMP(const char *filename, gint32 width, gint32 height, guint8 *gray8);

// event handle
EHANDLE *event;

struct BMPFileHeader {
    gshort bfType;     /* "BM" */
    gint32 bfSize;     /* Size of file in bytes */
    gint32 bfReserved; /* set to 0 */
    gint32 bfOffBits;  /* Byte offset to actual bitmap data (= 54) */
};

struct BMPInfoHeader {
    gint32 biSize;          /* Size of BITMAPINFOHEADER, in bytes (= 40) */
    gint32 biWidth;         /* Width of image, in pixels */
    gint32 biHeight;        /* Height of images, in pixels */
    gshort biPlanes;        /* Number of planes in target device (set to 1) */
    gshort biBitCount;      /* Bits per pixel (24 in this case) */
    gint32 biCompression;   /* Type of compression (0 if no compression) */
    gint32 biSizeImage;     /* Image size, in bytes (0 if no compression) */
    gint32 biXPelsPerMeter; /* Resolution in pixels/meter of display device */
    gint32 biYPelsPerMeter; /* Resolution in pixels/meter of display device */
    gint32 biClrUsed;       /* Number of colors in the color table (if 0, use
                            maximum allowed by biBitCount) */
    gint32 biClrImportant;  /* Number of important colors.  If 0, all colors
                            are important */
};

struct RGBQuad {
    guint8 rgbBlue;
    guint8 rgbGreen;
    guint8 rgbRed;
    guint8 rgbReserved;
};

#endif // VIDEOMODE_H
