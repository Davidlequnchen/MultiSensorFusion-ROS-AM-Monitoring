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

#include <mescan.h>
#include <pthread.h>
#include <sys/select.h>
#include <sys/socket.h>

/*
 * helper functions header
 */

static gint32 check_resolution(guint32 resolution, TScannerType scanner_type);

static double calc_x_coo(guint8, guint8, double, guint32);
static double calc_z_coo(guint8, guint8, double, double, guint32);
static gushort calc_actual_threshold(guint8, guint8);
static gushort calc_max_intensity(guint8, guint8);
static gushort calc_reflecton_width(guint8, guint8);
static gushort calc_container_10bit(guint8, guint8, guint32);

static gint32 decode_property_file(FILE *f, guint8 *file_array);
static gint32 to_big_endian32(guint8 *array);
static gint32 get_double_value(double *value, guint8 *array, guint32 array_size);
static gint32 get_int32_value(gint32 *value, guint8 *array, guint32 array_size);
static gint32 read_device_properties(gint32 *, double *, double *, gint32 *, gint32 *, gint32 *, double *, double *,
                                     double *, double *, gint32 *, double *, guint8 *, guint32);

// handle for event control
struct EHANDLE {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool triggered;
};

typedef struct gige_cmd_t {
    guint8 key;
    guint8 flags;
    gushort command;
    gushort data_size;
    gushort req_id;
} gige_cmd_t;

/**
 * SECTION: libmescan
 * @short_description: Basic C library for scanCONTROL control and data handling
 *
 * #libmescan is the basic class for controlling and data conversion of scanCONTROL sensors
 * It is to be used with the aravis framework.
 */

/**
 * get_device_interfaces:
 * @interfaces: array for found interfaces
 * @interfaces_size: size of interfaces array
 *
 * Find available scanCONTROL sensors on interface, if sensors are in the same subnet as the host
 *
 * Returns: number of found devices or error code
 *
 * Since: 0.1.0
 */
gint32 get_device_interfaces(char *interfaces[], guint32 interfaces_size)
{
#ifndef ARAVIS_CHECK_VERSION
    printf("Warning: aravis version could not be verified\n");
#elif !ARAVIS_CHECK_VERSION(0, 5, 8)
    printf("Warning: aravis version >=0.5.8 recommended\n");
#endif

    if (interfaces == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }
    if (interfaces_size == 0) {
        return ERROR_GETDEVINTERFACE_REQUEST_COUNT;
    }

    // update aravis internal list for found devices
    arv_update_device_list();

    // search number of connected devices and write device ids in array
    gint32 n_devices = (gint32)arv_get_n_devices();
    if (n_devices < (gint32)interfaces_size) {
        for (gint32 i = 0; i < n_devices; i++) {
            interfaces[i] = (char *)arv_get_device_id(i);
            if (interfaces[i] == NULL) {
                return ERROR_GETDEVINTERFACE_INTERNAL;
            }
        }
    } else {
        return ERROR_GETDEVINTERFACE_REQUEST_COUNT;
    }
    return n_devices;
}

/**
 * get_device_infos:
 * @host_ip: IP address of host network interface
 * @sensor_info: array with sensor_info struct
 * @size: size of sensor_info array
 * @eth_if: name of network device (if NULL choose interface automatically)
 *
 * Searches scanner in network via broadcast and collects all available info. If eth_if is NULL, the network device the
 * broadcast is sent through is chosen randomly by the OS. If eth_if is defined, the stated device is bound to the
 * socket. This requires root access.
 *
 * Returns: number of found devices or error code
 *
 * Since: 0.2.1
 */
gint32 get_device_infos(const char *host_ip, sensor_info_t *sensor_info, guint32 size, const char *eth_if)
{
    struct sockaddr_in broadcast_addr, recv_addr, host_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);

    gint32 ret = 0;
    gint32 enable = 1;
    gint32 sensors_found = 0;
    fd_set readfd;

    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcast_addr.sin_port = htons(3956);

    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    recv_addr.sin_port = htons(3956);

    memset(&host_addr, 0, sizeof(host_addr));
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(3956);
    if (inet_aton(host_ip, &host_addr.sin_addr) < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }

    gint32 sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        return ERROR_GETSETDEV_CREATE_SOCKET_FAILED;
    }
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable)) < 0) {
        return ERROR_GETSENSORINFO_CREATE_SOCKET_FAILED;
    }

    if (eth_if != NULL) {
        if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, eth_if, strlen(eth_if)) < 0) {
            return ERROR_GETSETDEV_BIND_DEVICE_FAILED;
        }
        if (bind(sock, (struct sockaddr *)&recv_addr, addr_len) < 0) {
            return ERROR_GETSETDEV_BIND_DEVICE_FAILED;
        }
    }

    gige_cmd_t discovery_cmd;
    discovery_cmd.key = 0x42;
    discovery_cmd.flags = 0x11;
    discovery_cmd.command = htons(0x0002);
    discovery_cmd.data_size = htons(0x0000);
    discovery_cmd.req_id = htons(0x0001);

    guint8 *data = malloc(sizeof(discovery_cmd));
    memcpy(data, &discovery_cmd, sizeof(discovery_cmd));

    if (sendto(sock, data, sizeof(discovery_cmd), 0, (struct sockaddr *)&broadcast_addr, addr_len) < 0) {
        free(data);
        return ERROR_GETSETDEV_SEND_FAILED;
    }
    free(data);

    while (1) {
        guint8 buffer[1024] = {0};
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        FD_ZERO(&readfd);
        FD_SET(sock, &readfd);

        ret = select(sock + 1, &readfd, NULL, NULL, &timeout);

        if (ret < 0) {
            return ERROR_GETSENSORINFO_GENERAL_ERROR;
        } else if (ret) {
            if (FD_ISSET(sock, &readfd)) {
                if (recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&recv_addr, &addr_len) < 0) {
                    return ERROR_GETSETDEV_ANSWER_INVALID;
                }
                if (recv_addr.sin_addr.s_addr == host_addr.sin_addr.s_addr || recv_addr.sin_port != htons(3956)) {
                    continue;
                }

                gushort discovery_ack_status = (buffer[1] << 8) + buffer[0];
                gushort discovery_ack = (buffer[3] << 8) + buffer[2];
                if (discovery_ack_status != htons(0x0000) || discovery_ack != htons(0x0003)) {
                    return ERROR_GETSETDEV_ANSWER_INVALID;
                }

                // decode discovery_ack payload
                char mac_address_str[13] = {0};
                for (gint32 i = 0; i < 6; i++) {
                    sprintf(mac_address_str + 2 * i, "%02X", buffer[18 + i]);
                }
                mac_address_str[12] = '\0';

                if (sensors_found < size) {
                    strcpy(sensor_info[sensors_found].mac_address, mac_address_str);
                    memcpy(&sensor_info[sensors_found].ip_options, &buffer[24], 4);
                    memcpy(&sensor_info[sensors_found].ip_config, &buffer[28], 4);
                    memcpy(&sensor_info[sensors_found].ip_address, &buffer[44], 4);
                    memcpy(&sensor_info[sensors_found].subnet_mask, &buffer[60], 4);
                    memcpy(&sensor_info[sensors_found].gateway, &buffer[76], 4);
                    memcpy(sensor_info[sensors_found].manufacturer_name, &buffer[80], 32);
                    memcpy(sensor_info[sensors_found].model_name, &buffer[112], 32);
                    memcpy(sensor_info[sensors_found].device_version, &buffer[144], 32);
                    memcpy(sensor_info[sensors_found].specific_info, &buffer[176], 48);
                    memcpy(sensor_info[sensors_found].serial_number, &buffer[224], 16);
                    memcpy(sensor_info[sensors_found].userdefined, &buffer[240], 16);
                }

                sensors_found++;
            }
        } else {
            break;
        }
    }

    return sensors_found;
}

/**
 * set_device_temporary_ip:
 * @host_ip: IP address of host network interface
 * @mac_address: target MAC address of sensor
 * @sensor_ip: new sensor IP
 * @sensor_subnet: new sensor subnet
 * @sensor_gateway: new sensor gateway
 * @eth_if: name of network device (if NULL choose interface automatically)
 *
 * Sets temporary IP config to sensor with the given MAC address via broadcast. If eth_if is NULL, the network device
 * the broadcast is sent through is chosen randomly by the OS. If eth_if is defined, the stated device is bound to the
 * socket. This requires root access.
 *
 * Returns: error code or success
 *
 * Since: 0.2.1
 */
gint32 set_device_temporary_ip(const char *host_ip, const char *mac_address, const char *sensor_ip,
                               const char *sensor_subnet, const char *sensor_gateway, const char *eth_if)
{
    struct sockaddr_in broadcast_addr, recv_addr;
    struct in_addr host_addr, ip_addr, subnet_addr, gw_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    gint32 enable = 1;
    fd_set readfd;
    gint32 ret = 0;

    gige_cmd_t forceip_cmd;
    forceip_cmd.key = 0x42;
    forceip_cmd.flags = 0x01;
    forceip_cmd.command = htons(0x0004);
    forceip_cmd.req_id = htons(0x0002);

    struct forceip_data {
        guint8 mac[8];
        guint32 res1;
        guint32 res2;
        guint32 res3;
        in_addr_t ip;
        guint32 res4;
        guint32 res5;
        guint32 res6;
        in_addr_t subnet;
        guint32 res7;
        guint32 res8;
        guint32 res9;
        in_addr_t gw;
    } forceip_data;

    memset(&forceip_data, 0, sizeof(forceip_data));

    memset(&broadcast_addr, 0, sizeof(broadcast_addr));
    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    broadcast_addr.sin_port = htons(3956);

    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    recv_addr.sin_port = htons(3956);

    if (inet_aton(host_ip, &host_addr) < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }
    if (inet_aton(sensor_ip, &ip_addr) < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }
    if (inet_aton(sensor_subnet, &subnet_addr) < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }
    if (inet_aton(sensor_gateway, &gw_addr) < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }

    forceip_data.ip = ip_addr.s_addr;
    forceip_data.subnet = subnet_addr.s_addr;
    forceip_data.gw = gw_addr.s_addr;

    for (gint32 i = 0; i < 6; i++) {
        sscanf(mac_address + 2 * i, "%2hhx", forceip_data.mac + 2 + i);
    }

    gint32 sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        return ERROR_GETSETDEV_CREATE_SOCKET_FAILED;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &enable, sizeof(enable)) < 0) {
        return ERROR_GETSETDEV_CREATE_SOCKET_FAILED;
    }

    if (eth_if != NULL) {
        if (setsockopt(sock, SOL_SOCKET, SO_BINDTODEVICE, eth_if, strlen(eth_if)) < 0) {
            return ERROR_GETSETDEV_BIND_DEVICE_FAILED;
        }
        if (bind(sock, (struct sockaddr *)&recv_addr, addr_len) < 0) {
            return ERROR_GETSETDEV_BIND_DEVICE_FAILED;
        }
    }

    forceip_cmd.data_size = htons(sizeof(forceip_data));

    gint32 data_size = sizeof(forceip_cmd) + sizeof(forceip_data);
    guint8 *data = malloc(data_size);
    memcpy(data, &forceip_cmd, sizeof(forceip_cmd));
    memcpy(data + sizeof(forceip_cmd), &forceip_data, sizeof(forceip_data));

    if (sendto(sock, data, data_size, 0, (struct sockaddr *)&broadcast_addr, addr_len) < 0) {
        free(data);
        return ERROR_GETSETDEV_SEND_FAILED;
    }
    free(data);

    while (1) {
        guint8 buffer[1024] = {0};
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        FD_ZERO(&readfd);
        FD_SET(sock, &readfd);

        ret = select(sock + 1, &readfd, NULL, NULL, &timeout);

        if (ret < 0) {
            return ERROR_GETSENSORINFO_GENERAL_ERROR;
        } else if (ret) {
            if (FD_ISSET(sock, &readfd)) {
                if (recvfrom(sock, buffer, 1024, 0, (struct sockaddr *)&recv_addr, &addr_len) < 0) {
                    return ERROR_GETSETDEV_ANSWER_INVALID;
                }
                if (recv_addr.sin_addr.s_addr == host_addr.s_addr || recv_addr.sin_port != htons(3956)) {
                    continue;
                }

                gushort discovery_ack_status = (buffer[1] << 8) + buffer[0];
                gushort discovery_ack = (buffer[3] << 8) + buffer[2];
                if (discovery_ack_status != htons(0x0000) || discovery_ack != htons(0x0005)) {
                    return ERROR_GETSETDEV_ANSWER_INVALID;
                } else {
                    break;
                }
            }
        } else {
            return ERROR_GETSETDEV_ANSWER_INVALID;
        }
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * convert_profile_2_values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @resolution: set resolution of sensor
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a full profile received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.1.0
 */
gint32 convert_profile_2_values(const guint8 *data, guint32 buffer_size, guint32 resolution,
                                TProfileConfig profile_config, TScannerType scanner_type, guint32 reflection,
                                gushort *width, gushort *intensity, gushort *threshold, double *x, double *z,
                                guint32 *m0, guint32 *m1)
{
    gint32 ret = 0;

    // data scaling factor (scanCONTROL type dependent)
    double scaling = 0.0, offset = 0.0;

    if (data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }
    if ((ret = get_scaling_and_offset_by_type(scanner_type, &scaling, &offset)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (profile_config != PROFILE && profile_config != PURE_PROFILE && profile_config != QUARTER_PROFILE) {
        return ERROR_PROFTRANS_WRONG_DATA_FORMAT;
    }
    if (reflection > 3) {
        return ERROR_PROFTRANS_REFLECTION_NUMBER_TOO_HIGH; // wrong reflection id
    }

    if ((ret = check_resolution(resolution, scanner_type)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if (buffer_size < resolution * 64) {
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    // calculate offset for chosen reflection in byte
    gint32 irefl = 16 * reflection;

    // avoid point extraction from timestamp
    if (reflection == 3) {
        resolution--;
    }

    // iterate over each profile point in data
    for (gint32 i = 0; i < resolution * 64; i += 64) {
        // check if correct file format (must begin with 0)
        if ((data[i + irefl] & 0xC0) != 0) {
            return ERROR_PROFTRANS_WRONG_DATA_FORMAT;
        }

        if (width != NULL) {
            width[i / 64] = calc_reflecton_width(data[i + irefl], data[i + irefl + 1]);
        }
        if (intensity != NULL) {
            intensity[i / 64] = calc_max_intensity(data[i + irefl + 1], data[i + irefl + 2]);
        }
        if (threshold != NULL) {
            threshold[i / 64] = calc_actual_threshold(data[i + irefl + 2], data[i + irefl + 3]);
        }
        if (x != NULL) {
            x[i / 64] = calc_x_coo(data[i + irefl + 4], data[i + irefl + 5], scaling, 1);
        }
        if (z != NULL) {
            z[i / 64] = calc_z_coo(data[i + irefl + 6], data[i + irefl + 7], scaling, offset, 1);
        }
        if (m0 != NULL) {
            m0[i / 64] = (data[i + irefl + 8] << 24) | (data[i + irefl + 9] << 16) | (data[i + irefl + 10] << 8) |
                            data[i + irefl + 11];
        }
        if (m1 != NULL) {
            m1[i / 64] = (data[i + irefl + 12] << 24) | (data[i + irefl + 13] << 16) | (data[i + irefl + 14] << 8) |
                            data[i + irefl + 15];
        }
    }    

    // construct return value depending on extracted data
    ret = 0;
    if (width != NULL) {
        ret |= CONVERT_WIDTH;
    }
    if (intensity != NULL) {
        ret |= CONVERT_MAXIMUM;
    }
    if (threshold != NULL) {
        ret |= CONVERT_THRESHOLD;
    }
    if (x != NULL) {
        ret |= CONVERT_X;
    }
    if (z != NULL) {
        ret |= CONVERT_Z;
    }
    if (m0 != NULL) {
        ret |= CONVERT_M0;
    }
    if (m1 != NULL) {
        ret |= CONVERT_M1;
    }
    return ret;
}

/**
 * convert_rearranged_container_2_values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @rearrangement: value of rearrangement register
 * @number_profiles: number of profiles in container
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a rearranged container received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.2.0
 */
gint32 convert_rearranged_container_2_values(const guint8 *data, guint32 buffer_size, guint32 rearrangement,
                                             guint32 number_profiles, TScannerType scanner_type, guint32 reflection,
                                             gushort *width, gushort *intensity, gushort *threshold, double *x,
                                             double *z)
{
    gint32 ret = 0;

    // data scaling factor (scanCONTROL type dependent)
    double scaling = 0.0, offset = 0.0;

    if (data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }
    if ((ret = get_scaling_and_offset_by_type(scanner_type, &scaling, &offset)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    guint32 has_z = rearrangement & CONTAINER_DATA_Z;
    guint32 has_x = (rearrangement & CONTAINER_DATA_X) >> 1;
    guint32 has_t = (rearrangement & CONTAINER_DATA_THRES) >> 2;
    guint32 has_i = (rearrangement & CONTAINER_DATA_INTENS) >> 3;
    guint32 has_w = (rearrangement & CONTAINER_DATA_WIDTH) >> 4;
    guint32 has_m1L = (rearrangement & CONTAINER_DATA_MOM1L) >> 5;
    guint32 has_m1U = (rearrangement & CONTAINER_DATA_MOM1U) >> 6;
    guint32 has_m0L = (rearrangement & CONTAINER_DATA_MOM0L) >> 7;
    guint32 has_m0U = (rearrangement & CONTAINER_DATA_MOM0U) >> 8;
    guint32 has_loopback = (rearrangement & CONTAINER_DATA_LOOPBACK) >> 9;
    guint32 has_empty_ts = (rearrangement & CONTAINER_DATA_EMPTYFIELD4TS) >> 10;
    // guint32 has_ts = (rearrangement & CONTAINER_DATA_TS) >> 11;
    guint32 is_lsbf = (rearrangement & CONTAINER_DATA_LSBF) >> 17;
    // guint32 is_signed = (rearrangement & CONTAINER_DATA_SIGNED) >> 18;
    guint32 has_stripe1 = (rearrangement & CONTAINER_STRIPE_1) >> 20;
    guint32 has_stripe2 = (rearrangement & CONTAINER_STRIPE_2) >> 21;
    guint32 has_stripe3 = (rearrangement & CONTAINER_STRIPE_3) >> 22;
    guint32 has_stripe4 = (rearrangement & CONTAINER_STRIPE_4) >> 23;

    guint32 resolution = 0;
    guint32 resolution_flag = (rearrangement & 0x0000F000) >> 12;

    if (has_loopback) {
        return ERROR_PROFTRANS_LOOPBACK_NOT_SUPPORTED;
    }

    bool is_llt3000 = scanner_type >= scanCONTROL30xx_25 && scanner_type <= scanCONTROL30xx_xxx;
    switch (resolution_flag) {
        case 6:
            resolution = 80;
            break;
        case 7:
            resolution = 160;
            break;
        case 8:
            resolution = is_llt3000 ? 256 : 320;
            break;
        case 9:
            resolution = is_llt3000 ? 512 : 640;
            break;
        case 10:
            resolution = is_llt3000 ? 1024 : 1280;
            break;
        case 11:
            resolution = 2048;
            break;
        default:
            return ERROR_PROFTRANS_WRONG_RESOLUTION;
    }

    if ((ret = check_resolution(resolution, scanner_type)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    switch (reflection) {
        case 0:
            if (!has_stripe1)
                return ERROR_PROFTRANS_REFLECTION_NO_DATA;
            break;
        case 1:
            if (!has_stripe2)
                return ERROR_PROFTRANS_REFLECTION_NO_DATA;
            break;
        case 2:
            if (!has_stripe3)
                return ERROR_PROFTRANS_REFLECTION_NO_DATA;
            break;
        case 3:
            if (!has_stripe4)
                return ERROR_PROFTRANS_REFLECTION_NO_DATA;
            break;
        default:
            return ERROR_PROFTRANS_REFLECTION_NUMBER_TOO_HIGH;
            break;
    }

    guint32 fs = resolution * 2; // field size
    guint32 number_fields = has_z + has_x + has_t + has_i + has_w + has_m0L + has_m0U + has_m1L + has_m1U;
    guint32 number_stripes = has_stripe1 + has_stripe2 + has_stripe3 + has_stripe4;
    guint32 width_profile = (number_fields * number_stripes + has_empty_ts) * fs;
    guint32 width_stripe = number_fields * fs;
    guint32 expected_data_size = width_profile * number_profiles;

    if (buffer_size < expected_data_size) {
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    for (gint32 profile = 0; profile < number_profiles; profile++) {
        gint32 pw = profile * width_profile; // current profile width
        gint32 pp = profile * resolution;    // position in profile

        // take possibilty of additional stripe in account
        gint32 ws = 0;
        if (reflection >= 1 && has_stripe1) {
            ws = width_stripe;
        }
        if (reflection >= 2 && has_stripe2) {
            ws += width_stripe;
        }
        if (reflection >= 3 && has_stripe3) {
            ws += width_stripe;
        }
        // iterate over data
        for (gint32 i = ws; i < fs + ws; i++) {
            if (z != NULL && has_z) {
                z[i / 2 - ws + pp] = calc_z_coo(data[i + pw], data[i + 1 + pw], scaling, offset, is_lsbf);
            }
            if (x != NULL && has_x) {
                x[i / 2 - ws + pp] =
                    calc_x_coo(data[i + fs * has_z + pw], data[i + 1 + fs * has_z + pw], scaling, is_lsbf);
            }
            if (threshold != NULL && has_t) {
                threshold[i / 2 - ws + pp] = calc_container_10bit(data[i + fs * (has_z + has_x) + pw],
                                                                  data[i + 1 + fs * (has_z + has_x) + pw], is_lsbf);
            }
            if (intensity != NULL && has_i) {
                intensity[i / 2 - ws + pp] =
                    calc_container_10bit(data[i + fs * (has_z + has_x + has_t) + pw],
                                         data[i + 1 + fs * (has_z + has_x + has_t) + pw], is_lsbf);
            }
            if (width != NULL && has_w) {
                width[i / 2 - ws + pp] =
                    calc_container_10bit(data[i + fs * (has_z + has_x + has_t + has_i) + pw],
                                         data[i + 1 + fs * (has_z + has_x + has_t + has_i) + pw], is_lsbf);
            }
        }
    }
    // construct return value depending on extracted data
    ret = 0;
    if (width != NULL && has_w) {
        ret |= CONVERT_WIDTH;
    }
    if (intensity != NULL && has_i) {
        ret |= CONVERT_MAXIMUM;
    }
    if (threshold != NULL && has_t) {
        ret |= CONVERT_THRESHOLD;
    }
    if (x != NULL && has_x) {
        ret |= CONVERT_X;
    }
    if (z != NULL && has_z) {
        ret |= CONVERT_Z;
    }
    return ret;
}

/**
 * convert_part_profile_2_values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @partial_profile: TPartialProfile with information about image size
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a partial profile received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.1.0
 */
gint32 convert_part_profile_2_values(const guint8 *data, guint32 buffer_size, TPartialProfile *partial_profile,
                                     TScannerType scanner_type, guint32 reflection, gushort *width, gushort *intensity,
                                     gushort *threshold, double *x, double *z, guint32 *m0, guint32 *m1)
{
    gint32 ret = 0;

    // data scaling factor (scanCONTROL type dependent)
    double scaling = 0.0, offset = 0.0;

    if (data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }
    if ((ret = get_scaling_and_offset_by_type(scanner_type, &scaling, &offset)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    // get number of points, start data and data width
    guint32 point_start = partial_profile->nStartPoint; // number of points
    guint32 point_ct = partial_profile->nPointCount;    // number of points
    guint32 d_start = partial_profile->nStartPointData; // data start
    guint32 d_width = partial_profile->nPointDataWidth; // data width

    // check for valid inputs
    if (reflection > 3) {
        return ERROR_PROFTRANS_REFLECTION_NUMBER_TOO_HIGH; // wrong reflection id
    }
    if (point_ct == 0 || d_width == 0) {
        return ERROR_PARTPROFILE_NO_POINT_COUNT;
    }
    if (point_ct % 4 != 0 || point_start % 4 != 0) {
        return ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_POINT;
    }
    if (d_width % 4 != 0 || d_start % 4 != 0) {
        return ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_DATA;
    }
    if ((d_start + d_width) > 64) {
        return ERROR_PARTPROFILE_TOO_MUCH_BYTES;
    }
    if (scanCONTROL27xx_25 <= scanner_type && scanner_type <= scanCONTROL26xx_xxx) {
        if ((point_start + point_ct) > 640) {
            return ERROR_PARTPROFILE_TOO_MUCH_POINTS;
        }
    } 
	if (scanCONTROL25xx_25 <= scanner_type && scanner_type <= scanCONTROL25xx_xxx) {
        if ((point_start + point_ct) > 640) {
            return ERROR_PARTPROFILE_TOO_MUCH_POINTS;
        }
    } 
	if (scanCONTROL29xx_25 <= scanner_type && scanner_type <= scanCONTROL29xx_xxx) {
        if ((point_start + point_ct) > 1280) {
            return ERROR_PARTPROFILE_TOO_MUCH_POINTS;
        }
    } 
	if (scanCONTROL30xx_25 <= scanner_type && scanner_type <= scanCONTROL30xx_xxx) {
        if ((point_start + point_ct) > 2048) {
            return ERROR_PARTPROFILE_TOO_MUCH_POINTS;
        }
    }

    if (buffer_size < point_ct * d_width) {
        return ERROR_PROFTRANS_WRONG_DATA_SIZE;
    }

    // calculate offset for chosen reflection in byte
    gint32 irefl = 16 * reflection;

    // iterate over each point in data minus timestamp
    for (gint32 i = d_start; i < point_ct * d_width - d_start - 16; i += d_width) {

        // check if correct file format (must begin with 0)
        if (d_start == irefl) {
            if ((data[i + irefl] & 0xC0) != 0) {
                return ERROR_PROFTRANS_WRONG_DATA_FORMAT; // wrong data format
            }
        }
        if (width != NULL && d_start == irefl && d_width >= (irefl + 2 - d_start)) {
            width[i / d_width] = calc_reflecton_width(data[i + irefl], data[i + irefl + 1]);
        }
        if (intensity != NULL && d_start <= irefl + 1 && d_width >= (irefl + 3 - d_start)) {
            intensity[i / d_width] =
                calc_max_intensity(data[i + irefl + 1], data[i + irefl + 2]);
        }
        if (threshold != NULL && d_start <= irefl + 2 && d_width >= (irefl + 4 - d_start)) {
            threshold[i / d_width] =
                calc_actual_threshold(data[i + irefl + 2], data[i + irefl + 3]);
        }
        if (x != NULL && d_start <= irefl + 4 && d_width >= (irefl + 6 - d_start)) {
            x[i / d_width] = calc_x_coo(data[i + irefl + 4], data[i + irefl + 5], scaling, 1);
        }
        if (z != NULL && d_start <= irefl + 6 && d_width >= (irefl + 8 - d_start)) {
            z[i / d_width] =
                calc_z_coo(data[i + irefl + 6], data[i + irefl + 7], scaling, offset, 1);
        }
        if (m0 != NULL && d_start <= irefl + 8 && d_width >= (irefl + 12 - d_start)) {
            m0[i / d_width] = (data[i + irefl + 8] << 24) | (data[i + irefl + 9] << 16) |
                                (data[i + irefl + 10] << 8) | data[i + irefl + 11];
        }
        if (m1 != NULL && d_start <= irefl + 12 && d_width >= (irefl + 16 - d_start)) {
            m1[i / d_width] = (data[i + irefl + 12] << 24) | (data[i + irefl + 13] << 16) |
                                (data[i + irefl + 14] << 8) | data[i + irefl + 15];
        }
    }    

    // construct return value depending on extracted data
    ret = 0;
    if (width != NULL && (d_start <= irefl && d_width >= (irefl + 2 - d_start))) {
        ret |= CONVERT_WIDTH;
    }
    if (intensity != NULL && (d_start <= irefl + 1 && d_width >= (irefl + 3 - d_start))) {
        ret |= CONVERT_MAXIMUM;
    }
    if (threshold != NULL && (d_start <= irefl + 2 && d_width >= (irefl + 4 - d_start))) {
        ret |= CONVERT_THRESHOLD;
    }
    if (x != NULL && (d_start <= irefl + 4 && d_width >= (irefl + 6 - d_start))) {
        ret |= CONVERT_X;
    }
    if (z != NULL && (d_start <= irefl + 6 && d_width >= (irefl + 8 - d_start))) {
        ret |= CONVERT_Z;
    }
    if (m0 != NULL && (d_start <= irefl + 8 && d_width >= (irefl + 12 - d_start))) {
        ret |= CONVERT_M0;
    }
    if (m1 != NULL && (d_start <= irefl + 12 && d_width >= (irefl + 16 - d_start))) {
        ret |= CONVERT_M1;
    }
    return ret;
}

/**
 * timestamp_2_time_and_count:
 * @data: buffer with timestamp raw data (must be 16 bytes)
 * @ts_shutter_opened: absolute timestamp of integration start
 * @ts_shutter_closed: absolute timestamp of integration end
 * @profile_number: profile number of current profile
 * @enc_times2_or_digin: 2x value of encoder step or state of digital input


 *
 * Extracts the most important data from 16 byte timestamp raw data
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 timestamp_2_time_and_count(const guint8 *data, double *ts_shutter_opened, double *ts_shutter_closed,
                                  guint32 *profile_number, gushort *enc_times2_or_digin)
{
    if (data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }

    if (profile_number != NULL) {
        // extract profile number
        *profile_number = (guint32)(data[1] << 16 | data[2] << 8 | data[3]);
    }
    if (ts_shutter_opened != NULL) {
        // extract shutter open timestamp
        *ts_shutter_opened =
            (double)((double)((data[4] & 0xFE) >> 1) +
                     (double)(((data[4] & 0x01) << 12) | (data[5] << 4) | ((data[6] & 0xF0) >> 4)) / 8000.0 +
                     (double)(((data[6] & 0x0F) << 8) | data[7]) / (24576000.0));
    }
    if (enc_times2_or_digin != NULL) {
        // extract encoder x2 or state dig in
        *enc_times2_or_digin = (gushort)(data[8] << 8 | data[9]);
    }
    if (ts_shutter_closed != NULL) {
        // extract shutter closed timestamp
        *ts_shutter_closed =
            (double)((double)((data[12] & 0xFE) >> 1) +
                     (double)(((data[12] & 0x01) << 12) | (data[13] << 4) | ((data[14] & 0xF0) >> 4)) / 8000.0 +
                     (double)(((data[14] & 0x0F) << 8) | data[15]) / (24576000.0));
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * init_device:
 * @camera_name: name string of found scanCONTROL
 * @data: a *MEDeviceData
 * @path: path to device_properties.dat
 *
 * Initializes ME device properties
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 init_device(const char *camera_name, MEDeviceData *data, const char *path)
{
    /*
     * device_properties.dat has the following structure
     * -------------------------------------------------
     * size field: 4x4 byte
     * integer field: 4x4 byte
     * double field: 8x4 byte
     * scanner name field: 4 byte
     * names separated by tabs
     */

    gint32 fd = 0, ret = 0, name_ct = 0;
    guint32 arr_size = 0;
    guint8 *arr_ptr;
    struct stat st;

    if (camera_name == NULL || data == NULL || path == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }

    // file operations
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        return ERROR_DEVPROP_NOT_FOUND; // File not found
    }

    fd = fileno(file);
    fstat(fd, &st);

    // rough check of file format
    if (st.st_size % 4 == 0 && st.st_size < 62000 && st.st_size >= 58708) {
        arr_size = st.st_size;
    } else {
        return ERROR_DEVPROP_WRONG_FILE_FORMAT; // wrong file format
    }

    guint8 file_arr[arr_size];
    arr_ptr = &file_arr[0]; // use pointer to navigate through array

    // decode device_properties->dat
    if (decode_property_file(file, file_arr) == -1) {
        return ERROR_DEVPROP_DECODE; // cant decode file
    }

    gint32 file_version = 0;
    ret = get_int32_value(&file_version, file_arr, arr_size);
    if (ret < 0 || file_version < 2) {
        return ERROR_DEVPROP_DEPRECATED; // Get file version failed
    }
    arr_ptr += ret;
    arr_size -= ret;

    // get size of device name data field
    gint32 size_of_data_field = to_big_endian32(arr_ptr);
    gint32 number_devices = 0;

    char device_names[250][25];
    memset(device_names, 0, sizeof(device_names));
    gint32 prev_pos = 0;

    // reads the list of device names
    for (gint32 i = 0; i < 250; i++) {
        // skip size field and already read parts
        guint8 *str_ptr = arr_ptr + 16 + prev_pos;
        // search tabs; break if none found
        guint8 *tab_ptr = (guint8 *)memchr(str_ptr, '\t', arr_size - 16 - prev_pos);
        if (tab_ptr == NULL) {
            break;
        }
        // copy chars until position of char
        gint32 tab_pos = tab_ptr - str_ptr;
        for (gint32 j = 0; j < tab_pos; j++) {
            if (j % 4 == 0) {
                device_names[i][j / 4] = *(str_ptr + j);
            }
        }
        // null terminate string
        device_names[i][tab_pos] = '\0';
        prev_pos += tab_pos + 4;
        number_devices++;
    }

    // point pointer to next data field
    arr_ptr += size_of_data_field * 4 + 16;
    arr_size -= size_of_data_field * 4 + 16; // 1 size field + result

    // use dyn. sized arrays to avoid memory handling
    gint32 field_device_series[number_devices];
    double field_scaling[number_devices];
    double fo[number_devices];
    gint32 max_packet_size[number_devices];
    gint32 max_frequency[number_devices];
    gint32 post_proc[number_devices];
    double min_x_display[number_devices];
    double max_x_display[number_devices];
    double min_y_display[number_devices];
    double max_y_display[number_devices];
    gint32 rotate_image[number_devices];
    double min_width[number_devices];

    // read all available sensor meta data from file
    ret = read_device_properties(field_device_series, field_scaling, fo, max_packet_size, max_frequency, post_proc,
                                 min_x_display, max_x_display, min_y_display, max_y_display, rotate_image, min_width,
                                 arr_ptr, arr_size);
    if (ret < 1) {
        return ERROR_DEVPROP_READ_FAILURE; // read device properties failed
    }

    // search for first occurence of "2" in camera name
    char *c_short = strchr(camera_name, 0x32);
    if (c_short == NULL) {
        return ERROR_DEVPROP_WRONG_CAMERA; // camera name not recognized
    }

    // compare devproperty device names and camera name
    for (gint32 i = 0; i < number_devices; i++) {
        char *d_short = strchr(device_names[i], 0x32);
        if (d_short != NULL) {
            if (strncmp(d_short, c_short, 8) == 0) {
                break;
            } else {
                name_ct++;
            }
        }
    }
    if (name_ct >= number_devices) {
        return ERROR_DEVPROP_WRONG_CAMERA; // camera name not recognized
    }

    // set data for found sensor
    data->scaling = field_scaling[name_ct];
    data->offset = fo[name_ct];
    data->max_packet_size = max_packet_size[name_ct];
    data->max_frequency = max_frequency[name_ct];
    data->post_proc = post_proc[name_ct] & 0x1;
    data->min_x_display = min_x_display[name_ct];
    data->max_x_display = max_x_display[name_ct];
    data->min_y_display = min_y_display[name_ct];
    data->max_y_display = max_y_display[name_ct];
    data->rotate_image = rotate_image[name_ct];
    data->min_width = min_width[name_ct];

    return GENERAL_FUNCTION_OK;
}

/**
 * create_event:
 *
 * Initializes Windows-esque event handling
 *
 * Returns: an EHANDLE
 *
 * Since: 0.1.0
 */
EHANDLE *create_event()
{
    // initialize mutex, cond and triggered
    EHANDLE *event_handle = malloc(sizeof(EHANDLE));
    pthread_mutex_init(&event_handle->mutex, 0);
    pthread_cond_init(&event_handle->cond, 0);
    event_handle->triggered = false;

    return event_handle;
}

/**
 * set_event:
 * @event_handle: a *EHANDLE
 *
 * Set the event to signal condition change
 *
 * Since: 0.1.0
 */
void set_event(EHANDLE *event_handle)
{
    // lock context and set event conditions
    pthread_mutex_lock(&event_handle->mutex);
    event_handle->triggered = true;
    pthread_cond_signal(&event_handle->cond);
    pthread_mutex_unlock(&event_handle->mutex);
}

/**
 * reset_event:
 * @event_handle: a *EHANDLE
 *
 * Reset event to inital condition
 *
 * Since: 0.1.0
 */
void reset_event(EHANDLE *event_handle)
{
    // lock context and reset event conditions
    pthread_mutex_lock(&event_handle->mutex);
    event_handle->triggered = false;
    pthread_mutex_unlock(&event_handle->mutex);
}

/**
 * free_event:
 * @event_handle: a *EHANDLE
 *
 * Free event handle resources
 *
 * Since: 0.1.0
 */
void free_event(EHANDLE *event_handle)
{
    // destroy event handle resources
    pthread_mutex_destroy(&event_handle->mutex);
    pthread_cond_destroy(&event_handle->cond);
    free(event_handle);
}

/**
 * wait_for_single_object:
 * @event_handle: a *EHANDLE
 * @timeout: timeout in milleseconds
 *
 * Waits for event to be set or until timeout is reached.
 *
 * Returns: 0 if successful otherwise an error number
 */
gint32 wait_for_single_object(EHANDLE *event_handle, guint32 timeout)
{
    gint32 ret = 0;

    // lock and wait for event to signal
    pthread_mutex_lock(&event_handle->mutex);

    // define point of time were timeout is reached
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += (time_t)(timeout / 1000);
    ts.tv_nsec += (timeout % 1000) * 1000000;

    // wait until event set or timeout
    while (!event_handle->triggered && ret == 0) {
        ret = pthread_cond_timedwait(&event_handle->cond, &event_handle->mutex, &ts);
    }
    pthread_mutex_unlock(&event_handle->mutex);

    return ret;
}

/**
 * get_llt_type_by_name:
 * @full_model_name: scanCONTROL name as read by aravis
 * @scanner_type: pointer to TScannerType
 *
 * Extracts scanner type from device name (without the need for a connected device)
 *
 * Returns: error code or success
 */
gint32 get_llt_type_by_name(const char *full_model_name, TScannerType *scanner_type)
{
    if (full_model_name == NULL) {
        return ERROR_GENERAL_POINTER_MISSING; // no data given
    }

    // search for first occurence of " " (0x20) in camera name and return pointer
    char *model_name = strchr(full_model_name, 0x20);
    if (model_name == NULL) {
        return ERROR_GENERAL_DEVICE_BUSY; // camera name not recognized
    }

    if (scanner_type != NULL) {
        // copy first two chars of model name to get sensor type
        char model_type[3] = {0};
        strncpy(model_type, model_name+1, 2);
        model_type[2] = '\0';

        // compare strings to get correct device type
        if (strcmp(model_type, "29") == 0) {
            *scanner_type = scanCONTROL29xx_xxx;
        } else if (strcmp(model_type, "26") == 0) {
            *scanner_type = scanCONTROL26xx_xxx;
        } else if (strcmp(model_type, "27") == 0) {
            *scanner_type = scanCONTROL27xx_xxx;
        } else if (strcmp(model_type, "30") == 0) {
            *scanner_type = scanCONTROL30xx_xxx;
        } else if (strcmp(model_type, "25") == 0) {
            *scanner_type = scanCONTROL25xx_xxx;
        } else {
            *scanner_type = StandardType;
            return GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED;
        }

        // copy char 5-9 of model name to get measuring range
        char measuring_range[4] = {0};
        strncpy(measuring_range, model_name + 6, 4);
        measuring_range[3] = '\0';

        // compare strings to get correct measuring range
        if (strcmp(measuring_range, "10 ") == 0) {
            *scanner_type -= 996;
        } else if (strcmp(measuring_range, "25 ") == 0) {
            *scanner_type -= 999;
        } else if (strcmp(measuring_range, "50 ") == 0) {
		    if (*scanner_type == scanCONTROL30xx_xxx) {
				*scanner_type -= 998;
			} else { 
				*scanner_type -= 997;
			}
        } else if (strcmp(measuring_range, "100") == 0) {
            *scanner_type -= 998;
        } else {
            *scanner_type = StandardType;
            return GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED;
        }
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * get_scaling_and_offset_by_type:
 * @scanner_type: TScannerType
 * @scaling: pointer for scaling value
 * @offset: pointer for offset value
 *
 * Gets scaling and offset factor for scanner type (without the need for a connected device)
 *16
 * Returns: error code or success
 */
gint32 get_scaling_and_offset_by_type(TScannerType scanner_type, double *scaling, double *offset)
{
    double tmp_scaling = 0.0;
    double tmp_offset = 0.0;

    if (scanner_type == scanCONTROL29xx_10) {
        tmp_scaling = 0.0005;
        tmp_offset = 55.0;
    } else if (scanner_type == scanCONTROL26xx_25 || scanner_type == scanCONTROL29xx_25 || scanner_type == scanCONTROL25xx_25) {
        tmp_scaling = 0.001;
        tmp_offset = 65.0;
    } else if (scanner_type == scanCONTROL26xx_50 || scanner_type == scanCONTROL29xx_50 || scanner_type == scanCONTROL25xx_50) {
        tmp_scaling = 0.002;
        tmp_offset = 95.0;
    } else if (scanner_type == scanCONTROL26xx_100 || scanner_type == scanCONTROL29xx_100 || scanner_type == scanCONTROL25xx_100) {
        tmp_scaling = 0.005;
        tmp_offset = 250.0;
    } else if (scanner_type == scanCONTROL27xx_25) {
        tmp_scaling = 0.001;
        tmp_offset = 100.0;
    } else if (scanner_type == scanCONTROL27xx_50) {
        tmp_scaling = 0.002;
        tmp_offset = 210.0;
    } else if (scanner_type == scanCONTROL27xx_100) {
        tmp_scaling = 0.005;
        tmp_offset = 450.0;
    } else if (scanner_type == scanCONTROL30xx_25) {
        tmp_scaling = 0.001;
        tmp_offset = 85.0;
    } else if (scanner_type == scanCONTROL30xx_50) {
        tmp_scaling = 0.002;
        tmp_offset = 125.0;
    } else {
        return GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED;
    }

    if (scaling != NULL) {
        *scaling = tmp_scaling;
    }
    if (offset != NULL) {
        *offset = tmp_offset;
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * translate_error_value:
 * @error_value: error value to translate
 * @error_string: pointer to string buffer
 * @string_size: string buffer size
 *
 * Translates error value to more readable error string
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 translate_error_value(gint32 error_value, char *error_string, guint32 string_size)
{
    if (error_string == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (string_size < 150) {
        return ERROR_TRANSERRORVALUE_BUFFER_SIZE_TOO_LOW;
    }
    memset(error_string, 0, string_size);

    switch (error_value) {
        case GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED:
            strcpy(error_string, "Passed device name not know, please update library");
            break;
        case GENERAL_FUNCTION_OK:
            strcpy(error_string, "Function successfully executed");
            break;
        case GENERAL_FUNCTION_NOT_AVAILABLE:
            strcpy(error_string, "This function is not available, please update library");
            break;
        case ERROR_GETDEVICENAME_SIZE_TOO_LOW:
            strcpy(error_string, "The size of a buffer is to small");
            break;
        case ERROR_GETDEVICENAME_NO_BUFFER:
            strcpy(error_string, "No buffer has been passed");
            break;
        case ERROR_PROFTRANS_REFLECTION_NUMBER_TOO_HIGH:
            strcpy(error_string, "The index of the reflection to be put out is >3");
            break;
        case ERROR_PROFTRANS_WRONG_DATA_SIZE:
            strcpy(error_string, "The count of interrogated profiles / container is bigger than 65535");
            break;
        case ERROR_PROFTRANS_WRONG_DATA_FORMAT:
            strcpy(error_string, "Not able to convert the profile into the requested profile configuration");
            break;
        case ERROR_PROFTRANS_WRONG_RESOLUTION:
            strcpy(error_string, "The count of interrogated profiles / container is bigger than 65535");
            break;
        case ERROR_PROFTRANS_REFLECTION_NO_DATA:
            strcpy(error_string, "Not able to convert the loaded profile into the requested profile configuration");
            break;
        case ERROR_PROFTRANS_NO_NEW_PROFILE:
            strcpy(error_string, "Since the last call of GetActualProfile no new profile has been received");
            break;
        case ERROR_PROFTRANS_BUFFER_SIZE_TOO_LOW:
            strcpy(error_string, "The buffer size of the passed buffer is too small");
            break;
        case ERROR_PROFTRANS_NO_PROFILE_TRANSFER:
            strcpy(error_string, "The profile transfer has not been started");
            break;
        case ERROR_PROFTRANS_WRONG_BUFFER_POINTER:
            strcpy(error_string, "Wrong Transfer Config");
            break;
        case ERROR_PROFTRANS_WRONG_TRANSFER_CONFIG:
            strcpy(error_string, "Wrong Transfer Config");
            break;
        case ERROR_PROFTRANS_LOOPBACK_NOT_SUPPORTED:
            strcpy(error_string, "Function does not support container with loopback parameters");
            break;
        case ERROR_SETGETFUNCTIONS_WRONG_BUFFER_COUNT:
            strcpy(error_string, "The buffer count must be in the range of >=2 and <= 200");
            break;
        case ERROR_SETGETFUNCTIONS_PACKET_SIZE:
            strcpy(error_string, "The requested packet size is not supported");
            break;
        case ERROR_SETGETFUNCTIONS_WRONG_PROFILE_CONFIG:
            strcpy(error_string, "The requested profile configuration is not available");
            break;
        case ERROR_SETGETFUNCTIONS_NOT_SUPPORTED_RESOLUTION:
            strcpy(error_string, "The requested resolution is not supported");
            break;
        case ERROR_SETGETFUNCTIONS_REFLECTION_NUMBER_TOO_HIGH:
            strcpy(error_string, "The index of the reflection to be put out is >3");
            break;
        case ERROR_SETGETFUNCTIONS_WRONG_FEATURE_ADRESS:
            strcpy(error_string, "The address of the selected property is wrong");
            break;
        case ERROR_SETGETFUNCTIONS_SIZE_TOO_LOW:
            strcpy(error_string, "The size of the passed field is too small");
            break;
        case ERROR_SETGETFUNCTIONS_WRONG_PROFILE_SIZE:
            strcpy(error_string, "The size of the profile/container is wrong");
            break;
        case ERROR_SETGETFUNCTIONS_MOD_4:
            strcpy(error_string, "The  parameter is of wrong format - not divisible by 4");
            break;
        case ERROR_SETGETFUNCTIONS_USER_MODE_TOO_HIGH:
            strcpy(error_string, "The usermode number is not present");
            break;
        case ERROR_SETGETFUNCITONS_USER_MODE_FACTORY_DEFAULT:
            strcpy(error_string, "User mode 0 can't be overwritten");
            break;
        case ERROR_SETGETFUNCITONS_HEARTBEAT_TOO_HIGH:
            strcpy(error_string, "Heartbeat parameter is has a too high value");
            break;
        case ERROR_GETDEVINTERFACE_REQUEST_COUNT:
            strcpy(error_string, "The size of the passed field is to small");
            break;
        case ERROR_GETDEVINTERFACE_INTERNAL:
            strcpy(error_string, "Internal failure during scanCONTROL request");
            break;
        case ERROR_GETSETDEV_CREATE_SOCKET_FAILED:
            strcpy(error_string, "Socket creation failed");
            break;
        case ERROR_GETSETDEV_BIND_DEVICE_FAILED:
            strcpy(error_string, "Couldn't bind GVCP Port 3956 to socket. Port may be already in use");
            break;
        case ERROR_GETSETDEV_IP_INVALID:
            strcpy(error_string, "Wrong format of IP addresses, subnet or gateway");
            break;
        case ERROR_GETSETDEV_SEND_FAILED:
            strcpy(error_string, "Sending broadcast failed - network unreachable");
            break;
        case ERROR_GETSETDEV_ANSWER_INVALID:
            strcpy(error_string, "Sensor answer invalid");
            break;
        case ERROR_GETSETDEV_GENERAL_ERROR:
            strcpy(error_string, "General interface error");
            break;
        case ERROR_CONNECT_LLT_COUNT:
            strcpy(error_string, "There is no scanCONTROL connected to the computer or the driver "
                                 "is not installed correctly");
            break;
        case ERROR_CONNECT_SELECTED_LLT:
            strcpy(error_string, "The selected interface is not available or used by another instance");
            break;
        case ERROR_CONNECT_ALREADY_CONNECTED:
            strcpy(error_string, "There is already a scanCONTROL connected with this ID");
            break;
        case ERROR_CONNECT_LLT_NUMBER_ALREADY_USED:
            strcpy(error_string, "The requested scanCONTROL is already used by another instance");
            break;
        case ERROR_CONNECT_INVALID_DEVICE_ID:
            strcpy(error_string, "No valid device id was given - use SetDeviceInterface();");
            break;
        case ERROR_PARTPROFILE_NO_PART_PROF:
            strcpy(error_string, "The profile configuration is not set to PARTIAL_PROFILE"
                                 " -> call SetProfileConfig(PARTIAL_PROFILE);");
            break;
        case ERROR_PARTPROFILE_TOO_MUCH_BYTES:
            strcpy(error_string, "The count of bytes per point is too high -> change "
                                 "StartPointData or PointDataWidth");
            break;
        case ERROR_PARTPROFILE_TOO_MUCH_POINTS:
            strcpy(error_string, "The count of points is too high -> change StartPoint or PointCount");
            break;
        case ERROR_PARTPROFILE_NO_POINT_COUNT:
            strcpy(error_string, "PointCount or PointDataWidth is 0");
            break;
        case ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_POINT:
            strcpy(error_string, "StartPoint or PointCount are not a multiple of UnitSizePoint");
            break;
        case ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_DATA:
            strcpy(error_string, "StartPointData or PointDataWidth are not a multiple of UnitSizePointData");
            break;
        case ERROR_TRANSERRORVALUE_WRONG_ERROR_VALUE:
            strcpy(error_string, "A wrong error value has been passed");
            break;
        case ERROR_TRANSERRORVALUE_BUFFER_SIZE_TOO_LOW:
            strcpy(error_string, "The size of the passed buffer is too small for the string");
            break;
        case ERROR_GENERAL_NOT_CONNECTED:
            strcpy(error_string, "There is no connection to the scanCONTROL -> call Connect");
            break;
        case ERROR_GENERAL_DEVICE_BUSY:
            strcpy(error_string, "The connection to the scanCONTROL is interfered or disconnected "
                                 "-> reconnect and check interface of the scanCONTROL");
            break;
        case ERROR_TRANSMISSION_CANCEL_NO_TRANSMISSION_ACTIVE:
            strcpy(error_string, "Function couldnt be executed due to no active profile transmission");
            break;
        case ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE:
            strcpy(error_string, "Function could not be executed as the profile transfer is active");
            break;
        case ERROR_READWRITECONFIG_CANT_CREATE_FILE:
            strcpy(error_string, "The specified file cannot be created");
            break;
        case ERROR_READWRITECONFIG_CANT_OPEN_FILE:
            strcpy(error_string, "The specified file cannot be opened");
            break;
        case ERROR_READWRITECONFIG_QUEUE_TO_SMALL:
            strcpy(error_string, "The data array is too small");
            break;
        case ERROR_READWRITECONFIG_FILE_EMPTY:
            strcpy(error_string, "The specified file is empty");
            break;
        case ERROR_READWRITECONFIG_UNKNOWN_FILE:
            strcpy(error_string, "The imported data has not the expected format");
            break;
        case ERROR_GENERAL_GET_SET_ADDRESS:
            strcpy(error_string, "The address could not be read or written. The connection to the "
                                 "sensor may be lost or a too old firmware is used");
            break;
        case ERROR_GENERAL_POINTER_MISSING:
            strcpy(error_string, "A required pointer is set NULL");
            break;
        case ERROR_GENERAL_WHILE_SAVE_PROFILES:
            strcpy(error_string, "Function could not be executed as the saving of profiles is active");
            break;
        case ERROR_GENERAL_VALUE_NOT_ALLOWED:
            strcpy(error_string, "Function could not be executed as one of the provided values is not allowed");
            break;
        default:
            return ERROR_TRANSERRORVALUE_WRONG_ERROR_VALUE;
            break;
    }
    return GENERAL_FUNCTION_OK;
}

/***
 Helper functions
***/

/***
  check if resolution is plausibel
 ***/
gint32 check_resolution(guint32 resolution, TScannerType scanner_type)
{
    if (scanner_type >= scanCONTROL27xx_25 && scanner_type <= scanCONTROL26xx_xxx) {
        if (resolution > 640 || resolution < 80 || (resolution % 80) != 0) {
            return ERROR_PROFTRANS_WRONG_RESOLUTION;
        }
    } else if (scanner_type >= scanCONTROL25xx_25 && scanner_type <= scanCONTROL25xx_xxx) {
        if (resolution > 640 || resolution < 160 || (resolution % 160) != 0) {
            return ERROR_PROFTRANS_WRONG_RESOLUTION;
        }
    } else if (scanner_type >= scanCONTROL29xx_25 && scanner_type <= scanCONTROL29xx_xxx) {
        if (resolution > 1280 || resolution < 160 || (resolution % 160) != 0) {
            return ERROR_PROFTRANS_WRONG_RESOLUTION;
        }
    } else if (scanner_type >= scanCONTROL30xx_25 && scanner_type <= scanCONTROL30xx_xxx) {
        if (resolution > 2048 || resolution < 256 || (resolution % 256) != 0) {
            return ERROR_PROFTRANS_WRONG_RESOLUTION;
        }
    } else {
        return GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED;
    }
    return GENERAL_FUNCTION_OK;
}

/***
 calc_reflecton_width calculates transfered reflection width values from buffervalue
***/
gushort calc_reflecton_width(guint8 byte1, guint8 byte2)
{
    return (gushort)(((byte1 & 0x3F) << 4) | ((byte2 & 0xF0) >> 4));
}

/***
 calc_max_intensity calculates transfered max intensity values from buffervalue
***/
gushort calc_max_intensity(guint8 byte1, guint8 byte2)
{
    return (gushort)(((byte1 & 0x0F) << 6) | ((byte2 & 0xFC) >> 2));
}

/***
 calc_actual_threshold calculates transfered threshold values from buffervalue
***/
gushort calc_actual_threshold(guint8 byte1, guint8 byte2) { return (gushort)(((byte1 & 0x03) << 8) | byte2); }

/***
 calc_x_coo calculates real calibrated x values from buffervalue
***/
double calc_x_coo(guint8 byte1, guint8 byte2, double scaling, guint32 endianess)
{
    if (endianess) {
        return (double)((((byte1 << 8) | byte2) - 32768) * scaling);
    } else {
        return (double)((((byte2 << 8) | byte1) - 32768) * scaling);
    }
}

/***
 calc_z_coo calculates real calibrated z values of a buffervalue
***/
double calc_z_coo(guint8 byte1, guint8 byte2, double scaling, double offset, guint32 endianess)
{
    gushort uncalibrated_z = 0;
    if (endianess) {
        uncalibrated_z = (byte1 << 8) | byte2;
    } else {
        uncalibrated_z = (byte2 << 8) | byte1;
    }
    if (uncalibrated_z != 0) {
        return (double)((uncalibrated_z - 32768) * scaling + offset);
    } else {
        return 0.0;
    }
}

/***
 calc_container_10bit transforms the 10bit values received from the sensor to the actual values
 ***/
gushort calc_container_10bit(guint8 byte1, guint8 byte2, guint32 endianess)
{
    if (endianess) {
        return (gushort)(((byte1 << 8) | byte2) >> 6);
    } else {
        return (gushort)(((byte2 << 8) | byte1) >> 6);
    }
}

/***
   read_device_properties reads device properties and stores them in arrays
***/
gint32 read_device_properties(gint32 *field_device_series, double *field_scaling, double *fo, gint32 *max_packet_size,
                              gint32 *max_frequency, gint32 *post_proc, double *min_x_display, double *max_x_display,
                              double *min_y_display, double *max_y_display, gint32 *rotate_image, double *min_width,
                              guint8 *file_arr, guint32 arr_size)
{
    // get device series
    gint32 ret = get_int32_value(field_device_series, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get scaling
    ret = get_double_value(field_scaling, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get offset
    ret = get_double_value(fo, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get max packet size
    ret = get_int32_value(max_packet_size, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get max frequency
    ret = get_int32_value(max_frequency, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // Get post processing flag
    ret = get_int32_value(post_proc, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get min x display value
    ret = get_double_value(min_x_display, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get max x display value
    ret = get_double_value(max_x_display, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get min y display value
    ret = get_double_value(min_y_display, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // get max y display value
    ret = get_double_value(max_y_display, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // matrix rotation
    ret = get_int32_value(rotate_image, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    // min width
    ret = get_double_value(min_width, file_arr, arr_size);
    if (ret == -1) {
        return ret;
    }
    file_arr += ret;
    arr_size -= ret;

    return 1;
}

/***
   get_int32_value reads a 32-bit integer value from the the file
***/
gint32 get_int32_value(gint32 *val_arr, guint8 *arr, guint32 array_size)
{
    if (array_size < 32) {
        return -1;
    }

    // get size of current data field (First 32-bit integer value of data field)
    guint32 data_size = to_big_endian32(arr);

    if (array_size < data_size * 16) {
        return -1;
    }

    // get gint32 values from file
    for (gint32 i = 0; i < data_size * 16; i = i + 16) {
        val_arr[i / 16] = to_big_endian32(&arr[i + 16]);
    }

    return data_size * 16 + 16;
}

/***
   get_double_value reads a double floating point value (64-bit) from the the file
***/
gint32 get_double_value(double *val_arr, guint8 *array, guint32 array_size)
{
    if (array_size < 48) {
        return -1;
    }

    // get size of current data field (First 32-bit integer value of data field)
    gint32 data_size = to_big_endian32(array);

    if (array_size < data_size * 32) {
        return -1;
    }

    // get dbl values from file
    for (gint32 i = 0; i < data_size * 32; i += 32) {
        guint32 byte_array[8] = {0};

        for (gint32 j = 0; j < 8; j++) {
            byte_array[7 - j] = array[16 + i + j * 4] & 0xFF;
        }

        char res_string[17] = {0};
        for (gint32 j = 0; j < 8; j++) {
            sprintf(res_string + i * 2, "%02X", byte_array[j]);
        }
        res_string[16] = '\0';

        double res = 0.0;
        // convert HEX string to double
        sscanf(res_string, "%llx", (unsigned long long *)&res);
        val_arr[i / 32] = res;
    }
    return data_size * 32 + 16;
}

/***
   decode_property_file decodes device_properties.dat
***/
gint32 decode_property_file(FILE *file, guint8 *arr)
{
    guint8 bytes[4];
    gint32 i = 0;

    if (file != NULL) {
        // read lines
        while (fread(bytes, 1, 4, file)) {
            // decoding function
            gint32 decoded_data = ((bytes[0] | (bytes[1] << 8) | (bytes[2] << 16) | (bytes[3] << 24)) / 21 - 333) / -7;
            memcpy(&arr[i], &decoded_data, 4);
            i += 4;
        }
        return 0;
    } else {
        return -1;
    }
}

/***
   to_big_endian32 converts a 16 byte data field to a 32-bit big endian integer
***/
gint32 to_big_endian32(guint8 *array) { return (array[12] << 24) | (array[8] << 16) | (array[4] << 8) | array[0]; }