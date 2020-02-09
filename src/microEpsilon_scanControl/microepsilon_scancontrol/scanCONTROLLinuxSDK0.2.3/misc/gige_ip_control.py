#!/usr/bin/env python3

#
# GigE IP setup script
#
# MIT License
#
# Copyright (c) 2018 Micro-Epsilon Messtechnik GmbH & Co. KG
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

import socket
import struct
import binascii
from sys import platform
from argparse import ArgumentParser
if platform == 'linux' or platform == 'linux2':
    import IN   # pylint: disable=import-error


GVCP_PORT = 3956


class GvcpException(Exception):
    ''' raise if GVCP status error '''
    pass


def gige_msg(key, flags, command, req_id, data=b''):
    ''' constructs a GVCP message (header + data) '''
    data_size = len(data)
    return struct.pack('>BBHHH', key, flags, command, data_size, req_id) + data


def forceip(mac_addr, ip_addr, subnet_mask, gateway):
    ''' constructs the GVCP command FORCEIP_CMD '''
    mac = int(mac_addr, 16)
    mach = (mac >> 32) & 0xffff
    macl = mac & 0xffffffff
    ips = socket.inet_aton(ip_addr)
    mask = socket.inet_aton(subnet_mask)
    gw = socket.inet_aton(gateway)
    fmt = '>xxHIxxxxxxxxxxxx4sxxxxxxxxxxxx4sxxxxxxxxxxxx4s'
    data = struct.pack(fmt, mach, macl, ips, mask, gw)
    return gige_msg(0x42, 0x01, 0x0004, 0x0002, data)


def discovery(connected_socket, host_ip):
    ''' sends DISCOVERY_CMD and returns MAC of selected scanner '''

    manufacturer_names = []
    camera_names = []
    device_versions = []
    serial_numbers = []
    current_ip = []
    current_subnet = []
    mac_addresses = []

    # send DISCOVERY_CMD broadcast
    discovery_cmd = gige_msg(0x42, 0x11, 0x0002, 0x0001)
    connected_socket.sendto(discovery_cmd, ('255.255.255.255', GVCP_PORT))

    discover_ack_fmt = '>6HIH6s14I32s32s32s48s16s16s'
    cameras_found = 0

    # received and interpret DISCOVERY_ACK (answer)
    try:
        while True:
            recv_data, recv_ip = connected_socket.recvfrom(2048)

            # ignore data if own broadcast is received
            if recv_ip[0] == host_ip:
                continue

            discover_ack = struct.unpack(discover_ack_fmt, recv_data)
            if discover_ack[0] != 0 and discover_ack[3] != 0x0001:
                raise GvcpException('discover_ack failed')

            mac_addresses.append(binascii.hexlify(discover_ack[8]).decode('utf-8'))
            current_ip.append(socket.inet_ntoa(struct.pack('>I', discover_ack[14])))
            current_subnet.append(socket.inet_ntoa(struct.pack('>I', discover_ack[18])))
            manufacturer_names.append(discover_ack[23].decode('utf-8'))
            camera_names.append(discover_ack[24].decode('utf-8').rstrip('\0')[:25])
            device_versions.append(discover_ack[25].decode('utf-8'))
            serial_numbers.append(discover_ack[27].decode('utf-8')[:9])
    except socket.timeout:
        cameras_found = len(camera_names)
        print(cameras_found, 'camera(s) found')
    except Exception as e:
        print('Error', e)

    if cameras_found is 0:
        raise GvcpException('No scanner found')

    # print list with found cameras
    table_header = '{0:^3} | {1:^25} | {2:^9} | {3:^12} | {4:^13} | {5:^13}'.format('#', 'type', 'serial',
                                                                                    'MAC', 'IP', 'subnet')
    print(len(table_header) * '-')
    print(table_header)
    print(len(table_header) * '-')
    for i, camera in enumerate(camera_names):
        print('{0:^3} | {1:25} | {2:^9} | {3:^12} | {4:^13} | {5:^13}'.format(i, camera, serial_numbers[i],
                                                                              mac_addresses[i], current_ip[i],
                                                                              current_subnet[i]))
    print(len(table_header) * '-')

    # poll desired camera list index from user
    while(True):
        try:
            index = int(input('Select scanner: '))
            if not 0 <= index < cameras_found:
                raise ValueError('index not available, please choose valid scanner index from list')
        except Exception as e:
            print("Try again -", e)
        else:
            break

    return mac_addresses[index]


def main():
    parser = ArgumentParser(description='Searches scanners in all subnets and sets IP address of selected one.')
    parser.add_argument('--version', action='version', version='%(prog)s 0.1b')
    parser.add_argument('IP', help='IP address to set')
    parser.add_argument('HOSTIP', help='IP address of network interface')
    if platform == 'linux' or platform == 'linux2':
        parser.add_argument('-d', '--device',
                            help='Identifier of network interface the scanner is connected to (e.g. \'eth0\')')
    parser.add_argument('-s', '--subnet', default='255.255.255.0',
                        help='Subnet mask to set (default: 255.255.255.0)')
    parser.add_argument('-g', '--gateway', default='0.0.0.0',
                        help='Standard gateway to set (default: 0.0.0.0)')
    parser.add_argument('-m', '--mac', help='Sets IP directly to the scanner with this MAC address')

    args = parser.parse_args()

    camera_ip = args.IP
    host_ip = args.HOSTIP
    camera_mac = args.mac
    camera_subnet = args.subnet
    camera_gateway = args.gateway

    # create socket and bind to GVCP port
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    sock.settimeout(1.0)

    # if linux is used the network interface doesn't need to bound to the socket. But to make sure the broadcast is sent
    # via the correct if the interface can be optionally bound to a device.
    if platform == 'linux' or platform == 'linux2':
        if args.device is not None:
            sock.setsockopt(socket.SOL_SOCKET, IN.SO_BINDTODEVICE, args.device)
            sock.bind(('', GVCP_PORT))
    else:
        sock.bind((host_ip, GVCP_PORT))

    if camera_mac is None:
        camera_mac = discovery(sock, host_ip)

    # broadcast FORCEIP_CMD
    forceip_cmd = forceip(camera_mac, camera_ip, camera_subnet, camera_gateway)
    sock.sendto(forceip_cmd, ('255.255.255.255', GVCP_PORT))

    while True:
        recv_data, recv_ip = sock.recvfrom(2048)

        # ignore data if own broadcast is received
        if recv_ip[0] == host_ip:
            continue

        forceip_ack = struct.unpack('>4H', recv_data)
        if forceip_ack[0] != 0 and forceip_ack[3] != 0x0002:
            raise GvcpException('FORCEIP failed')
        else:
            break

    print('IP', camera_ip, 'set to camera with MAC', camera_mac)


if __name__ == "__main__":
    main()
