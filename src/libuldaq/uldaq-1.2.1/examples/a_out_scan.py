#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
UL call demonstrated:             AoDevice.a_out_scan()

Purpose:                          Continuously output a waveform
                                  on a D/A output channel

Demonstration:                    Outputs user generated data
                                  on analog output channel 0

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Call DaqDevice() to create a DaqDevice object
3.  Call DaqDevice.get_ao_device() to get the AoDevice object for the analog
    output subsystem
4.  Verify the AoDevice object is valid
5.  Verify the analog output subsystem has a hardware pacer
6.  Call DaqDevice.connect() to connect to the device
7.  Call AoDevice.a_out_scan() to output the waveform to a D/A channel
8.  Call AoDevice.get_scan_status() to get the scan status and display the
    status.
9.  Call AoDevice.scan_stop() to stop the scan
10. Call DaqDevice.disconnect() and DaqDevice.release() before exiting the
    process
"""
from __future__ import print_function
from math import pi, sin
from time import sleep
from sys import stdout
from os import system

from uldaq import get_daq_device_inventory, DaqDevice, create_float_buffer
from uldaq import InterfaceType, AOutScanFlag, ScanOption, ScanStatus

# Constants
CURSOR_UP = '\x1b[1A'
ERASE_LINE = '\x1b[2K'


def main():
    """Analog output scan example."""
    # Parameters for AoDevice.a_out_scan
    low_channel = 0
    high_channel = 0
    voltage_range_index = 0  # Use the first supported range
    samples_per_channel = 2000  # Two second buffer (sample_rate * 2)
    sample_rate = 1000  # Hz
    scan_options = ScanOption.CONTINUOUS
    scan_flags = AOutScanFlag.DEFAULT

    interface_type = InterfaceType.ANY
    daq_device = None
    ao_device = None
    scan_status = ScanStatus.IDLE

    try:
        # Get descriptors for all of the available DAQ devices.
        devices = get_daq_device_inventory(interface_type)
        number_of_devices = len(devices)

        # Verify at least one DAQ device is detected.
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
        ao_device = daq_device.get_ao_device()

        # Verify the specified DAQ device supports analog output.
        if ao_device is None:
            raise RuntimeError('Error: The DAQ device does not support analog '
                               'output')

        # Verify the device supports hardware pacing for analog output.
        ao_info = ao_device.get_info()
        if not ao_info.has_pacer():
            raise RuntimeError('Error: The DAQ device does not support paced '
                               'analog output')

        # Establish a connection to the device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        chan_string = str(low_channel)
        num_channels = high_channel - low_channel + 1
        if num_channels > 1:
            chan_string = ' '.join((chan_string, '-', str(high_channel)))

        # Select the voltage range
        voltage_ranges = ao_info.get_ranges()
        if voltage_range_index < 0:
            voltage_range_index = 0
        elif voltage_range_index >= len(voltage_ranges):
            voltage_range_index = len(voltage_ranges) - 1
        voltage_range = ao_info.get_ranges()[voltage_range_index]

        # Create a buffer for output data.
        out_buffer = create_float_buffer(num_channels, samples_per_channel)

        # Fill the output buffer with data.
        amplitude = 1.0  # Volts
        # Set an offset if the range is unipolar
        offset = amplitude if voltage_range > 1000 else 0.0
        samples_per_cycle = int(sample_rate / 10.0)  # 10 Hz sine wave
        create_output_data(num_channels, samples_per_channel, samples_per_cycle,
                           amplitude, offset, out_buffer)

        print('\n', descriptor.dev_string, 'ready')
        print('    Function demonstrated: AoDevice.a_out_scan')
        print('    Channel(s):', chan_string)
        print('    Range:', voltage_range.name)
        print('    Samples per channel:', samples_per_channel)
        print('    Sample Rate:', sample_rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue')
        except (NameError, SyntaxError):
            pass

        # Start the output scan.
        sample_rate = ao_device.a_out_scan(low_channel, high_channel,
                                           voltage_range, samples_per_channel,
                                           sample_rate, scan_options,
                                           scan_flags, out_buffer)

        system('clear')
        print('Please enter CTRL + C to terminate the process\n')
        print('Active DAQ device: ', descriptor.dev_string, ' (',
              descriptor.unique_id, ')\n', sep='')
        print('    Actual scan rate:   ', sample_rate, 'Hz')

        try:
            while True:
                # Get and display the scan status.
                scan_status, transfer_status = ao_device.get_scan_status()
                if scan_status != ScanStatus.RUNNING:
                    break
                print('    Current scan count: ',
                      transfer_status.current_scan_count)
                print('    Current total count:',
                      transfer_status.current_total_count)
                print('    Current index:      ',
                      transfer_status.current_index)
                stdout.flush()
                sleep(0.1)
                # Clear the previous status before displaying the next status.
                for _line in range(3):
                    stdout.write(CURSOR_UP + ERASE_LINE)

        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            # Stop the scan.
            if scan_status == ScanStatus.RUNNING:
                ao_device.scan_stop()
            # Disconnect from the DAQ device.
            if daq_device.is_connected():
                daq_device.disconnect()
            # Release the DAQ device resource.
            daq_device.release()


def create_output_data(number_of_channels, samples_per_channel,
                       samples_per_cycle, amplitude, offset, data_buffer):
    """Populate the buffer with sine wave data for the specified number of
       channels."""
    cycles_per_buffer = int(samples_per_channel / samples_per_cycle)
    i = 0
    for _cycle in range(cycles_per_buffer):
        for sample in range(samples_per_cycle):
            for _chan in range(number_of_channels):
                data_buffer[i] = amplitude * sin(2 * pi * sample
                                                 / samples_per_cycle) + offset
                i += 1


def display_scan_options(bit_mask):
    """Create a displays string for all scan options."""
    options = []
    if bit_mask == ScanOption.DEFAULTIO:
        options.append(ScanOption.DEFAULTIO.name)
    for option in ScanOption:
        if option & bit_mask:
            options.append(option.name)
    return ', '.join(options)


if __name__ == '__main__':
    main()
