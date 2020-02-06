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

#ifndef MULTILLT_H
#define MULTILLT_H

#include <iostream>
#include <llt.h>
#include <vector>

#define MAX_INTERFACE_COUNT 5
#define MAX_RESOLUTION 6

gint32 MultiLLT(void);
void DisplayProfiles(double *, double *, guint32);
void DisplayTimestamp(guchar *);
void NewProfile(const void *, size_t, gpointer);
void ControlLostCallback(gpointer user_data);

CInterfaceLLT *hLLT, *hLLT_2;
guint32 resolution, resolution_2;
std::vector<guint8> profile_buffer, profile_buffer_2;
TScannerType llt_type, llt_type_2;
guint32 profile_count, profile_count_2, needed_profile_count, needed_profile_count_2;
guint32 profile_data_size;
guint32 profile_data_size_2;

// event handle
EHANDLE *event;

#endif // MULTILLT_H
