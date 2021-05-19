#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:        dio_device.d_out_scan()

Purpose:                          Continuously output user generated
                                  data to the digital port

Demonstration:                    Outputs user specified data on the
                                  user-specified digital port

Steps:
1. Call get_daq_device_inventory() to get the list of available DAQ devices
2. Create a DaqDevice object
3. Call daq_device.get_info() to get the daq_device_info object for the DAQ
   device
4. Verify that the DAQ device has an analog output subsystem
5. Call daq_device.connect() to establish a UL connection to the DAQ device
6. Call daq_device.get_di_device() to get the di_device object for the AI
   subsystem
7. Call dio_device.d_out_scan() to start the scan of digital output port
8. Display the last 5 samples for for the port as long as scan is running
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout
from math import pi, sin

from uldaq import (get_daq_device_inventory, DaqDevice, DigitalDirection,
                   ScanOption, ScanStatus, create_int_buffer, InterfaceType,
                   DOutScanFlag, DigitalPortIoType)


def main():
    """Digital port output scan example."""
    daq_device = None
    dio_device = None
    port_to_write = None
    port_info = None
    status = ScanStatus.IDLE

    samples_per_channel = 1000
    rate = 1000
    scan_options = ScanOption.CONTINUOUS
    flags = DOutScanFlag.DEFAULT

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

        dio_device = daq_device.get_dio_device()
        if dio_device is None:
            raise RuntimeError('Error: The DAQ device does not support digital '
                               'output')

        # Verify the device supports hardware pacing for digital input.
        dio_info = dio_device.get_info()
        if not dio_info.has_pacer(DigitalDirection.OUTPUT):
            raise RuntimeError('Error: The specified DAQ device does not '
                               'support hardware paced digital output')

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # Get the port types for the device(AUXPORT, FIRSTPORTA, ...)
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

        low_port = port_to_write
        hi_port = port_to_write
        number_of_ports = hi_port - low_port + 1

        # Allocate a buffer to receive the data.
        data = create_int_buffer(number_of_ports, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: dio_device.d_out_scan()')
        print('    Port: ', low_port.name)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', rate, ' Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system("clear")

        create_output_data(samples_per_channel, port_info.number_of_bits, data)

        # Start the acquisition.
        dio_device.d_out_scan(low_port, hi_port, samples_per_channel, rate,
                              scan_options, flags, data)

        try:
            while True:
                try:
                    status, transfer_status = dio_device.d_out_get_scan_status()

                    reset_cursor()
                    print('Please enter CTRL + C to terminate the process\n')
                    print('Active DAQ device: ', descriptor.dev_string, ' (',
                          descriptor.unique_id, ')\n', sep='')

                    print('actual scan rate = ', '{:.6f}'.format(rate), 'Hz\n')

                    index = transfer_status.current_index
                    print('currentTotalCount = ',
                          transfer_status.current_total_count)
                    print('currentScanCount = ',
                          transfer_status.current_scan_count)
                    print('currentIndex = ', index, '\n')

                    if status != ScanStatus.RUNNING:
                        break
                    sleep(0.1)
                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            # Stop the acquisition if it is still running.
            if dio_device:
                if status == ScanStatus.RUNNING:
                    dio_device.d_out_scan_stop()
                if port_to_write and port_info:
                    # before disconnecting, set the port back to input
                    if (port_info.port_io_type == DigitalPortIoType.IO or
                            port_info.port_io_type == DigitalPortIoType.BITIO):
                        dio_device.d_config_port(port_to_write,
                                                 DigitalDirection.INPUT)
            if daq_device.is_connected():
                daq_device.disconnect()
            daq_device.release()


def create_output_data(samples_per_port, bits_per_port, data_buffer):
    """Create sine wave digital output data."""
    two_pi = 2 * pi
    amplitude = pow(2.0, bits_per_port) - 1
    phase_interval = two_pi / samples_per_port
    phase = 0.0

    for i in range(samples_per_port):
        data_buffer[i] = int(sin(phase) * amplitude/2 + (amplitude / 2))
        phase += phase_interval
        if phase > two_pi:
            phase = phase - two_pi


def display_scan_options(bit_mask):
    """Create a displays string for all scan options."""
    options = []
    if bit_mask == ScanOption.DEFAULTIO:
        options.append(ScanOption.DEFAULTIO.name)
    for option in ScanOption:
        if option & bit_mask:
            options.append(option.name)
    return ', '.join(options)


def reset_cursor():
    """Reset the cursor in the terminal window."""
    stdout.write('\033[1;1H')


if __name__ == '__main__':
    main()
