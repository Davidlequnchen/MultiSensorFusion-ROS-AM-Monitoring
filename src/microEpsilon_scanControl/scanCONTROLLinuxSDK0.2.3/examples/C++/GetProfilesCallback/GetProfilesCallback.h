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

#ifndef GETPROFILESCALLBACK_H
#define GETPROFILESCALLBACK_H

#include <iostream>
#include <llt.h>
#include <vector>

#define MAX_INTERFACE_COUNT 5
#define MAX_RESOLUTION 6

gint32 GetProfilesCallback(void);
void DisplayProfiles(double *, double *, guint32);
void DisplayTimestamp(guchar *);

void NewProfile(const void *data, size_t data_size, gpointer user_data);
void ControlLostCallback(gpointer user_data);

CInterfaceLLT *hLLT;
guint32 resolution;
std::vector<guint8> profile_buffer;
TScannerType llt_type;
guint32 profile_count, needed_profile_count;
guint32 profile_data_size;

// for live profile count
guint32 first_trans = 0;
guint32 profile_counter = 0, old_profile_counter = 0, lost_profiles = 0;
double shutter_closed = 0, shutter_opened = 0;

// event handle
EHANDLE *event;

#endif // GETPROFILESCALLBACK_H
