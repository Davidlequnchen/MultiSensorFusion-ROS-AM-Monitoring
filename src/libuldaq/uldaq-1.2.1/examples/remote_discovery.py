#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:        get_net_daq_device_descriptor()

Purpose:                          Discovers remote Ethernet DAQ devices.

                                  Note: If the host system and the Ethernet
                                  DAQ device are in the same subnet, the get
                                  daq_device_inventory() function can be
                                  used to detect the Ethernet device.

Demonstration:                    Discovers a remote Ethernet DAQ device at
                                  the specified address and flashes the LED
                                  of the detected Ethernet device.

Steps:
1. Enter the address of the Ethernet DAQ device.
2. Call get_net_daq_device_descriptor() to obtain the descriptor for the
   Ethernet DAQ device.
3. Create a DaqDevice object using the descriptor.
4. Call daq_device.connect() to establish a UL connection to the DAQ device.
5. Call daq_device.flash_led().
6. Call daq_device.disconnect() and daq_device.release() before exiting
   the process.
"""
from __future__ import print_function
from time import sleep
from os import system
import sys

from uldaq import get_net_daq_device_descriptor, DaqDevice


def main():
    """Remote device discovery example."""
    daq_device = None
    default_port = 54211
    ifc_name = None
    timeout = 5.0

    try:
        # Enter the address and port number of the remote DAQ device.
        prompt = 'Enter the host name or IP address of the DAQ device: '
        host = GET_INPUT(prompt)
        prompt = ('Enter the port number (default is ' + str(default_port)
                  + ' if left blank): ')
        port = GET_INPUT(prompt)
        try:
            port = int(port)
        except ValueError:
            port = default_port

        # Discover the remote DAQ device at the specified address and port.
        print('\nDiscovering DAQ device at address:', host, 'and port:', port,
              '- please wait...')
        descriptor = get_net_daq_device_descriptor(host, port, ifc_name,
                                                   timeout)

        print('DAQ device discovered')
        print('    ', descriptor.product_name, ' (', descriptor.unique_id, ')',
              sep='')

        # Create the DAQ device object associated with the specified descriptor.
        daq_device = DaqDevice(descriptor)

        # Establish a connection to the device.
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        print('\n', descriptor.dev_string, ' ready', sep='')
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')
        print('Please enter CTRL + C to terminate the process\n')
        print("Flashing DAQ device's LED ...")

        try:
            while True:
                try:
                    # Flash the LED on the DAQ device.
                    daq_device.flash_led(1)
                    sleep(0.25)
                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            if daq_device.is_connected():
                daq_device.disconnect()
            daq_device.release()


if __name__ == '__main__':
    # Support Python 2 and 3 input
    # Default to Python 3's input()
    GET_INPUT = input

    # If this is Python 2, use raw_input()
    if sys.version_info[:2] <= (2, 7):
        GET_INPUT = raw_input

    main()
