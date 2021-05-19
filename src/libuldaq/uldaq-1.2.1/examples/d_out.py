#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:        dio_device.d_out()

Purpose:                          Writes the the specified DIO port

Demonstration:                    Writes the digital data to the
                                  digital port
Steps:
1. Call get_daq_device_inventory() to get the list of available DAQ devices
2. Create a DaqDevice object
3. Verify that the DAQ device has a digital output subsystem
4. Call daq_device.connect() to establish a UL connection to the DAQ device
5. Get the supported port types
6. Call dio_device.d_config_port() to configure the port for input
7. Call dio_device.d_out() to read the data for the digital port
8. Display the data for the port
9. Call daq_device.disconnect() and daq_device.release() before exiting the
   process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                   DigitalDirection, DigitalPortIoType)


def main():
    """Digital port output example."""
    daq_device = None
    dio_device = None
    port_to_write = None
    port_info = None

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
            raise RuntimeError('Error: The device does not support digital '
                               'output')

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

        port_to_write = port_types[port_types_index]

        # Get the port I/O type and the number of bits for the first port.
        port_info = dio_info.get_port_info(port_to_write)

        # Configure the port for output.
        if (port_info.port_io_type == DigitalPortIoType.IO or
                port_info.port_io_type == DigitalPortIoType.BITIO):
            dio_device.d_config_port(port_to_write, DigitalDirection.OUTPUT)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: dio_device.d_out()')
        print('    Port: ', port_types[port_types_index].name)
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        max_port_value = int(pow(2.0, port_info.number_of_bits) - 1)

        reset_cursor()
        print('Active DAQ device: ', descriptor.dev_string, ' (',
              descriptor.unique_id, ')\n', sep='')
        try:
            while True:
                try:
                    data = input('Enter a value between 0 and '
                                 + '{:.0f}'.format(max_port_value)
                                 + ' (or non-numeric character to exit): ')

                    # write the first port
                    dio_device.d_out(port_to_write, int(data))

                    sleep(0.1)
                    cursor_up()
                    clear_eol()
                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            if dio_device and port_to_write and port_info:
                # before disconnecting, set the port back to input
                if (port_info.port_io_type == DigitalPortIoType.IO
                        or port_info.port_io_type == DigitalPortIoType.BITIO):
                    dio_device.d_config_port(port_to_write,
                                             DigitalDirection.INPUT)
            if daq_device.is_connected():
                daq_device.disconnect()
            daq_device.release()


def reset_cursor():
    """Reset the cursor in the terminal window."""
    stdout.write('\033[1;1H')


def cursor_up():
    """Move the cursor up one line."""
    stdout.write('\033[A')


def clear_eol():
    """Clear all characters to the end of the line."""
    stdout.write('\x1b[2K')


if __name__ == '__main__':
    main()
