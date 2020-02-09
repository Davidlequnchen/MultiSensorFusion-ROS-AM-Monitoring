/*
 * This file is part of linllt.
 *
 * Copyright (C) Micro-Epsilon Messtechnik GmbH & Co. KG
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA or visit https://www.gnu.org/licenses/
 * lgpl.html.
 *
 */

#ifndef MESCANBASIC_H
#define MESCANBASIC_H

#include <LLTDataTypes.h>

/***
   extern functions
***/

// IP config
gint32 set_device_temporary_ip(const char *host_ip, const char *mac_address, const char *sensor_ip,
                               const char *sensor_subnet, const char *sensor_gateway, const char *eth_if);
gint32 get_device_infos(const char *host_ip, sensor_info_t *sensor_info, guint32 size, const char *eth_if);

// convert raw profiles to mm values
gint32 convert_profile_2_values(const guint8 *data, guint32 buffer_size, guint32 resolution,
                                TProfileConfig profile_config, TScannerType scanner_type, guint32 reflection,
                                gushort *width, gushort *intensity, gushort *threshold, double *x, double *z,
                                guint32 *m0, guint32 *m1);
gint32 convert_part_profile_2_values(const guint8 *data, guint32 buffer_size, TPartialProfile *partial_profile,
                                     TScannerType scanner_type, guint32 reflection, gushort *width, gushort *intensity,
                                     gushort *threshold, double *x, double *z, guint32 *m0, guint32 *m1);
gint32 convert_rearranged_container_2_values(const guint8 *data, guint32 buffer_size, guint32 rearrangement,
                                             guint32 number_profiles, TScannerType scanner_type, guint32 reflection,
                                             gushort *width, gushort *intensity, gushort *threshold, double *x,
                                             double *z);

// basic init of scanCONTROL sensor
gint32 init_device(const char *camera_name, MEDeviceData *data, const char *path);
gint32 get_llt_type_by_name(const char *full_model_name, TScannerType *scanner_type);
gint32 get_scaling_and_offset_by_type(TScannerType scanner_type, double *scaling, double *offset);

// search for available scanCONTROL sensors
gint32 get_device_interfaces(char *interfaces[], guint32 interfaces_size);

// extract important timestamp information
gint32 timestamp_2_time_and_count(const guint8 *data, double *ts_shutter_opened, double *ts_shutter_closed,
                                  guint32 *profile_number, gushort *enc_times2_or_digin);

// windows-esque event handlers (usage optional)
EHANDLE *create_event();
void set_event(EHANDLE *event_handle);
void free_event(EHANDLE *event_handle);
void reset_event(EHANDLE *event_handle);
gint32 wait_for_single_object(EHANDLE *event_handle, guint32 timeout);

// misc
gint32 translate_error_value(gint32 error_value, char *error_string, guint32 string_size);

#endif // MESCANBASIC_H
