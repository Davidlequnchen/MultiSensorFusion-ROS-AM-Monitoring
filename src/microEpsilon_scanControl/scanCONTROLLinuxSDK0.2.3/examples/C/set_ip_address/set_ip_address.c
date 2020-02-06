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

#include "set_ip_address.h"

int main()
{
    gint32 ret = 0;
    const char *host_ip = "192.168.1.100";
    // const char *ni_name = "enp0s25";
    const char *new_ip = "192.168.1.189";

    struct in_addr ip_tmp;

    sensor_info_t scanner_info[10];
    memset(scanner_info, 0, sizeof(scanner_info));
    gint32 sensors_found = get_device_infos(host_ip, scanner_info, sizeof(scanner_info) / sizeof(*scanner_info), NULL);

    if (sensors_found <= 0) {
        printf("get_device_infos: %d\n", sensors_found);
        return 0;
    } else {
        for (int i = 0; i < sensors_found; i++) {
            printf("%s\n", scanner_info[i].manufacturer_name);
            printf("%s\n", scanner_info[i].model_name);
            printf("%s\n", scanner_info[i].mac_address);
            ip_tmp.s_addr = scanner_info[i].ip_address;
            printf("%s\n", inet_ntoa(ip_tmp));
        }
    }

    // set temporary ip to device with stated MAC address
    ret = set_device_temporary_ip(host_ip, scanner_info[0].mac_address, new_ip, "255.255.255.0", "0.0.0.0", NULL);
    if (ret < GENERAL_FUNCTION_OK) {
        printf("set_device_temporary_ip: %d\n", ret);
        return 0;
    }

    char *interfaces[MAX_INTERFACE_COUNT];
    guint32 interface_count = 0;

    ret = get_device_interfaces(&interfaces[0], MAX_INTERFACE_COUNT);
    if (ret == ERROR_GETDEVINTERFACE_REQUEST_COUNT) {
        printf("There are more than %d scanCONTROL connected\n", MAX_INTERFACE_COUNT);
        interface_count = MAX_INTERFACE_COUNT;
    } else if (ret < 1) {
        printf("A error occured during searching for connected scanCONTROL\n");
        interface_count = 0;
    } else {
        interface_count = ret;
    }

    if (interface_count == 0) {
        printf("There is no scanCONTROL connected - Exiting\n");
        exit(0);
    } else if (interface_count == 1) {
        printf("There is 1 scanCONTROL connected\n");
    } else {
        printf("There are %d scanCONTROL connected\n", interface_count);
    }

    for (guint32 i = 0; i < interface_count; i++) {
        printf("%s\n", interfaces[i]);
    }

    hLLT = create_llt_device();

    if ((set_device_interface(hLLT, interfaces[0])) < GENERAL_FUNCTION_OK) {
        printf("Error while setting dev id!\n");
        goto cleanup;
    }

    // connect to sensor
    if ((ret = connect_llt(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while connecting to camera - Error  %d!\n", ret);
        goto cleanup;
    }

    if ((ret = set_persistent_ip(hLLT, new_ip, "255.255.255.0", "0.0.0.0")) < GENERAL_FUNCTION_OK) {
        printf("Error while setting persistent ip to camera - Error  %d!\n", ret);
        goto cleanup;
    }

    // disconnect to sensor
    printf("Disconnect\n");
    if ((ret = disconnect_llt(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while disconnecting to camera - Error  %d!\n", ret);
    }

    // reset temporary IP
    set_device_temporary_ip(host_ip, scanner_info[0].mac_address, "0.0.0.0", "255.255.255.0", "0.0.0.0", NULL);

cleanup:
    // delete device handle
    if ((ret = del_device(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while deleting device - Error  %d\n!", ret);
    }
}