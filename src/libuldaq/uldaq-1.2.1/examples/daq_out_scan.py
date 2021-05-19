#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
UL call demonstrated:             DaqoDevice.daq_out_scan()

Purpose:                          Synchronous output on analog and
                                  digital output channels

Demonstration:                    Continuously outputs a user specified
                                  waveform on an analog output channel
                                  and/or a digital output channel

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Call DaqDevice() to create a DaqDevice object
3.  Call DaqDevice.get_daqo_device() to get the DaqoDevice object for the DAQ
    output subsystem
4.  Verify the DaqoDevice object is valid
5.  Get the channel types supported by the DAQ output subsystem
6.  Call DaqDevice.connect() to connect to the device
7.  Configure the analog and digital channels
8.  Call DaqoDevice.daq_out_scan() to output the waveforms
9.  Call DaqoDevice.get_scan_status() to get the scan status and display the
    status.
10. Call DaqoDevice.scan_stop() to stop the scan
11. Call DaqDevice.disconnect() and DaqDevice.release() before exiting the
    process
"""
from __future__ import print_function
from math import pi, sin
from time import sleep
from sys import stdout
from os import system

from uldaq import (get_daq_device_inventory, DaqDevice, create_float_buffer,
                   InterfaceType, DaqOutScanFlag, Range, ScanOption,
                   DigitalDirection, DigitalPortType, ScanStatus,
                   DaqOutChanType, DaqOutChanDescriptor)

# Constants
CURSOR_UP = '\x1b[1A'
ERASE_LINE = '\x1b[2K'


def main():
    """Multi-subsystem simultaneous output scan example."""
    # Parameters for DaqoDevice.daq_out_scan
    channel_descriptors = []
    samples_per_channel = 2000  # Two second buffer (sample_rate * 2)
    sample_rate = 1000  # Hz
    scan_options = ScanOption.CONTINUOUS
    scan_flags = DaqOutScanFlag.DEFAULT

    # Parameters used when creating channel_descriptors list
    analog_low_channel = 0
    analog_high_channel = 0
    analog_range_index = 0
    digital_low_port_index = 0
    digital_high_port_index = 0

    interface_type = InterfaceType.ANY
    daq_device = None
    daqo_device = None

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
        daqo_device = daq_device.get_daqo_device()

        # Verify the specified DAQ device supports DAQ output.
        if daqo_device is None:
            raise RuntimeError('Error: The DAQ device does not support DAQ '
                               'output')

        daqo_info = daqo_device.get_info()

        # Establish a connection to the device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # Configure supported analog input and digital input channels
        amplitudes = []
        samples_per_cycle = int(sample_rate / 10.0)  # 10 Hz sine wave
        supported_channel_types = daqo_info.get_channel_types()
        if DaqOutChanType.ANALOG in supported_channel_types:
            configure_analog_channels(daq_device, analog_low_channel,
                                      analog_high_channel, analog_range_index,
                                      channel_descriptors, amplitudes)
        if DaqOutChanType.DIGITAL in supported_channel_types:
            configure_digital_channels(daq_device, digital_low_port_index,
                                       digital_high_port_index,
                                       channel_descriptors, amplitudes)

        num_channels = len(channel_descriptors)

        # Create a buffer for output data.
        out_buffer = create_float_buffer(num_channels, samples_per_channel)
        # Fill the output buffer with data.
        create_output_data(channel_descriptors, samples_per_channel,
                           samples_per_cycle, amplitudes, out_buffer)

        print('\n', descriptor.dev_string, 'ready')
        print('    Function demonstrated: DaqoDevice.daq_out_scan')
        print('    Number of Scan Channels:', num_channels)
        for chan in range(num_channels):
            chan_descriptor = channel_descriptors[chan]  # type: DaqOutChanDescriptor
            print('        Scan Channel', chan, end='')
            print(': type =', DaqOutChanType(chan_descriptor.type).name, end='')
            if chan_descriptor.type == DaqOutChanType.ANALOG:
                print(', channel =', chan_descriptor.channel, end='')
                print(', range =', Range(chan_descriptor.range).name, end='')
            else:
                print(', port =', DigitalPortType(chan_descriptor.channel).name,
                      end='')
            print('')
        print('    Samples per channel:', samples_per_channel)
        print('    Rate:', sample_rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue')
        except (NameError, SyntaxError):
            pass

        system('clear')

        # Start the output scan.
        sample_rate = daqo_device.daq_out_scan(channel_descriptors,
                                               samples_per_channel, sample_rate,
                                               scan_options, scan_flags,
                                               out_buffer)

        print('Please enter CTRL + C to terminate the process\n')
        print('Active DAQ device: ', descriptor.dev_string, ' (',
              descriptor.unique_id, ')\n', sep='')
        print('    Actual scan rate:   ', sample_rate, 'Hz')

        try:
            while True:
                # Get and display the scan status.
                scan_status, transfer_status = daqo_device.get_scan_status()
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
            if daqo_device:
                daqo_device.scan_stop()
            # before disconnecting, set digital ports back to input
            dio_device = daq_device.get_dio_device()
            for chan in channel_descriptors:
                if chan.type == DaqOutChanType.DIGITAL:
                    dio_device.d_config_port(chan.channel,
                                             DigitalDirection.INPUT)
            # Disconnect from the DAQ device.
            if daq_device.is_connected():
                daq_device.disconnect()
            # Release the DAQ device resource.
            daq_device.release()


def configure_analog_channels(daq_device, low_channel, high_channel,
                              range_index, channel_descriptors, amplitudes):
    """
    Add analog output channels to the channel_descriptors list.

    Raises:
        RuntimeError if a channel is not in range.
    """
    ao_device = daq_device.get_ao_device()
    ao_info = ao_device.get_info()

    # Validate the low_channel and high_channel values
    num_channels = ao_info.get_num_chans()
    valid_channels_string = ('valid channels are 0 - '
                             '{0:d}'.format(num_channels - 1))
    if low_channel < 0 or low_channel >= num_channels:
        error_message = ' '.join([('Error: Invalid analog_low_channel '
                                   'selection,'), valid_channels_string])
        raise RuntimeError(error_message)
    if high_channel < 0 or high_channel >= num_channels:
        error_message = ' '.join([('Error: Invalid analog_high_channel '
                                   'selection,'), valid_channels_string])
        raise RuntimeError(error_message)

    # Validate the range_index value
    voltage_ranges = ao_info.get_ranges()
    if range_index < 0:
        range_index = 0
    elif range_index >= len(voltage_ranges):
        range_index = len(voltage_ranges) - 1

    voltage_range = voltage_ranges[range_index]

    # Create a channel descriptor for each channel and add it to the list
    for channel in range(low_channel, high_channel + 1):
        descriptor = DaqOutChanDescriptor(channel, DaqOutChanType.ANALOG,
                                          voltage_range)
        channel_descriptors.append(descriptor)
        amplitudes.append(1.0)  # Volts peak


def configure_digital_channels(daq_device, low_port_index, high_port_index,
                               channel_descriptors, amplitudes):
    """
    Add digital output ports to the channel_descriptors list.

    Raises:
        RuntimeError if a port index is not in range
    """
    dio_device = daq_device.get_dio_device()
    dio_info = dio_device.get_info()
    port_types = dio_info.get_port_types()

    # Validate the low_port_index and high_port_index values
    number_of_ports = len(port_types)
    valid_ports_string = ('valid digital port index values are 0 - '
                          '{0:d}'.format(number_of_ports - 1))
    if low_port_index < 0 or low_port_index >= number_of_ports:
        error_message = ' '.join([('Error: Invalid digital_low_port_index '
                                   'selection,'), valid_ports_string])
        raise RuntimeError(error_message)
    if high_port_index < 0 or high_port_index >= number_of_ports:
        error_message = ' '.join([('Error: Invalid digital_high_port_index '
                                   'selection,'), valid_ports_string])
        raise RuntimeError(error_message)

    # Create a channel descriptor for each port and add it to the list
    # Also calculate the amplitude to be used for the digital port waveform
    for port_index in range(low_port_index, high_port_index + 1):
        port = port_types[port_index]

        dio_device.d_config_port(port, DigitalDirection.OUTPUT)
        descriptor = DaqOutChanDescriptor(port, DaqOutChanType.DIGITAL)
        channel_descriptors.append(descriptor)

        port_info = dio_info.get_port_info(port)
        amplitudes.append((pow(2, port_info.number_of_bits) - 1) / 2)


def create_output_data(channel_descriptors, samples_per_channel,
                       samples_per_cycle, amplitudes, data_buffer):
    """Populate the buffer with sine wave data."""
    cycles_per_buffer = int(samples_per_channel / samples_per_cycle)
    i = 0
    for _cycle in range(cycles_per_buffer):
        for sample in range(samples_per_cycle):
            for chan in channel_descriptors:
                sin_val = sin(2 * pi * sample / samples_per_cycle)
                if chan.type == DaqOutChanType.ANALOG:
                    offset = amplitudes[0] if chan.range > 1000 else 0.0
                    data_buffer[i] = amplitudes[0] * sin_val + offset
                else:
                    offset = amplitudes[1]
                    data_buffer[i] = round(amplitudes[1] * sin_val + offset)
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
