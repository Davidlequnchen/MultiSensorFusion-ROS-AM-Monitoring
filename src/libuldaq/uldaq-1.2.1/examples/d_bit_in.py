#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:        dio_device.d_bit_in()

Purpose:                          Reads the values of the bits for the
                                  first digital port

Demonstration:                    Displays the value of each bit in the
                                  first digital port
Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_dio_device() to get the dio_device object for the
    digital subsystem
4.  Verify that the DAQ device has a digital input subsystem
5.  Call daq_device.connect() to establish a UL connection to the DAQ device
6.  Get the supported port types
7.  Get the port information for the first supported port
8.  Call dio_device.d_config_bit to configure the port for bit I/O if the the
    port is bit configurable; otherwise, call dio_device.d_config_port to
    configure the port for port I/O
9.  Call dio_device.d_bit_in() to read each bit of the digital port
10. Display the data for each bit
11. Call daq_device.disconnect() and daq_device.release() before exiting the
    process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                   DigitalDirection, DigitalPortIoType)


def main():
    """Digital bit input example."""
    daq_device = None

    interface_type = InterfaceType.ANY
    port_types_index = 0

    try:
        # Get descriptors for all of the available DAQ devices.
        devices = get_daq_device_inventory(interface_type)
        number_of_devices = len(devices)
        if number_of_devices == 0:
            raise RuntimeError('Error: No DAQ devices found')

        print('Found', number_of_devices, 'DAQ device(s):')
        for i in range(number_of_devices):
            print('  [', i, '] ', devices[i].product_name, ' (',
                  devices[i].unique_id, ')', sep='')

        descriptor_index = input('\nPlease select a DAQ device, enter a number'
                                 + ' between 0 and '
                                 + str(number_of_devices - 1) + ': ')
        descriptor_index = int(descriptor_index)
        if descriptor_index not in range(number_of_devices):
            raise RuntimeError('Error: Invalid descriptor index')

        # Create the DAQ device from the descriptor at the specified index.
        daq_device = DaqDevice(devices[descriptor_index])

        # Get the DioDevice object and verify that it is valid.
        dio_device = daq_device.get_dio_device()
        if dio_device is None:
            raise RuntimeError('Error: The DAQ device does not support digital '
                               'input')

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # Get the port types for the device(AUXPORT, FIRSTPORTA, ...)
        dio_info = dio_device.get_info()
        port_types = dio_info.get_port_types()

        if port_types_index >= len(port_types):
            port_types_index = len(port_types) - 1

        port_to_read = port_types[port_types_index]

        # Get the port I/O type and the number of bits for the first port.
        port_info = dio_info.get_port_info(port_to_read)

        # If the port is bit configurable, then configure the individual bits
        # for input; otherwise, configure the entire port for input.
        if port_info.port_io_type == DigitalPortIoType.BITIO:
            # Configure all of the bits for input for the first port.
            for i in range(port_info.number_of_bits):
                dio_device.d_config_bit(port_to_read, i, DigitalDirection.INPUT)
        elif port_info.port_io_type == DigitalPortIoType.IO:
            # Configure the entire port for input.
            dio_device.d_config_port(port_to_read, DigitalDirection.INPUT)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: dio_device.d_bit_in()')
        print('    Port: ', port_to_read.name)
        print('    Port I/O type: ', port_info.port_io_type.name)
        print('    Bits: ', port_info.number_of_bits)
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        try:
            while True:
                try:
                    reset_cursor()
                    print('Please enter CTRL + C to terminate the process\n')
                    print('Active DAQ device: ', descriptor.dev_string, ' (',
                          descriptor.unique_id, ')\n', sep='')

                    # Read each of the bits from the first port.
                    for bit_number in range(port_info.number_of_bits):
                        data = dio_device.d_bit_in(port_to_read, bit_number)

                        clear_eol()
                        print('Bit(', bit_number, ') Data: ', data)

                    sleep(0.1)
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


def reset_cursor():
    """Reset the cursor in the terminal window."""
    stdout.write('\033[1;1H')


def clear_eol():
    """Clear all characters to the end of the line."""
    stdout.write('\x1b[2K')


if __name__ == '__main__':
    main()
