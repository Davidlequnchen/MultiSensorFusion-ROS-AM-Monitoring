#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:    daqi_device.daq_in_scan()

Purpose:                      Performs a continuous scan of the available
                              analog, digital, and/or counter input subsystems

Demonstration:                Displays the analog, digital, and counter
                              input data on the specified channels

Steps:
1. Call get_daq_device_inventory() to get the list of available DAQ devices
2. Create a DaqDevice object
3. Call daq_device.get_info() to get the daq_device_info object for the DAQ
   device
4. Verify that the DAQ device has an analog input subsystem
5. Call daq_device.connect() to establish a UL connection to the DAQ device
6. Call daq_device.get_daqi_device() to get the input daq_device object for the
   DAQI subsystem
7. Create the analog, digital, and counter channel descriptors
8. Call daq_device.daq_in_scan() to start the scan of daq input channels
9. Display the last 5 samples for the scanned channels for as long as scan is
   running
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (InterfaceType, DaqInChanType, DaqInChanDescriptor,
                   DaqInScanFlag, DigitalDirection, CounterMeasurementType,
                   Range, ScanOption, AiInputMode, ScanStatus,
                   get_daq_device_inventory, DaqDevice, create_float_buffer)


def main():
    """Multi-subsystem simultaneous input scan example."""
    daq_device = None
    daqi_device = None
    status = ScanStatus.IDLE

    samples_per_channel = 10000
    rate = 1000.0
    options = ScanOption.DEFAULTIO | ScanOption.CONTINUOUS
    flags = DaqInScanFlag.DEFAULT

    interface_type = InterfaceType.ANY

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

        # Get the DaqiDevice object and verify that it is valid.
        daqi_device = daq_device.get_daqi_device()
        if daqi_device is None:
            raise RuntimeError('Error: The device does not support daq input '
                               'subsystem')

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # Get the channel types supported by the DAQI subsystem
        daqi_info = daqi_device.get_info()
        chan_types_list = daqi_info.get_channel_types()

        # Configure the analog input channels.
        channel_descriptors = []
        if DaqInChanType.ANALOG_SE in chan_types_list:
            configure_analog_input_channels(daq_device, channel_descriptors)

        # Configure the digital input channels.
        if DaqInChanType.DIGITAL in chan_types_list:
            configure_digital_input_channels(daq_device, channel_descriptors)

        # Configure the counter input channels.
        if DaqInChanType.CTR32 in chan_types_list:
            configure_counter_input_channels(daq_device, channel_descriptors)

        number_of_scan_channels = len(channel_descriptors)

        # Allocate a buffer to receive the data
        data = create_float_buffer(number_of_scan_channels, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: daqi_device.daq_in_scan()')
        print('    Number of scan channels: ', number_of_scan_channels)
        for i in range(number_of_scan_channels):
            if (channel_descriptors[i].type == AiInputMode.SINGLE_ENDED
                    or channel_descriptors[i].type == AiInputMode.DIFFERENTIAL):
                print('        ScanChannel ', i, ': type = ',
                      DaqInChanType(channel_descriptors[i].type).name,
                      ', channel = ', channel_descriptors[i].channel,
                      ', range = ', Range(channel_descriptors[i].range).name)
            else:
                print('        ScanChannel ', i, ': type = ',
                      DaqInChanType(channel_descriptors[i].type).name,
                      ', channel = ', channel_descriptors[i].channel)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', rate, ' Hz')
        print('    Scan options:', display_scan_options(options))
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        # Start the acquisition.
        rate = daqi_device.daq_in_scan(channel_descriptors, samples_per_channel,
                                       rate, options, flags, data)

        try:
            while True:
                try:
                    # Get the status of the background operation
                    status, transfer_status = daqi_device.get_scan_status()

                    reset_cursor()
                    print('Please enter CTRL + C to terminate the process\n')
                    print('Active DAQ device: ', descriptor.dev_string, ' (',
                          descriptor.unique_id, ')\n', sep='')

                    print('actual scan rate = ', '{:.6f}'.format(rate), 'Hz\n')

                    index = transfer_status.current_index
                    print('currentScanCount = ',
                          transfer_status.current_scan_count)
                    print('currentTotalCount = ',
                          transfer_status.current_total_count)
                    print('currentIndex = ', index, '\n')

                    for i in range(number_of_scan_channels):
                        if (channel_descriptors[i].type
                                == DaqInChanType.ANALOG_SE
                                or channel_descriptors[i].type
                                == DaqInChanType.ANALOG_DIFF):
                            clear_eol()
                            print('(Ai', channel_descriptors[i].channel, '): ',
                                  '{:.6f}'.format(data[index + i]))

                        elif (channel_descriptors[i].type
                              == DaqInChanType.DIGITAL):
                            clear_eol()
                            print('(Di', channel_descriptors[i].channel, '): ',
                                  '{:d}'.format(int(data[index + i])))

                        else:
                            clear_eol()
                            print('(Ci', channel_descriptors[i].channel, '): ',
                                  '{:d}'.format(int(data[index + i])))

                    sleep(0.1)
                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            # Stop the scan if it is still running.
            if status == ScanStatus.RUNNING:
                daqi_device.scan_stop()
            if daq_device.is_connected():
                daq_device.disconnect()
            daq_device.release()


def configure_analog_input_channels(daq_device, channel_descriptors):
    """Configure the analog input channels."""
    range_index = 0
    num_analog_scan_channels = 2

    # Get the number of analog channels
    ai_device = daq_device.get_ai_device()
    ai_info = ai_device.get_info()

    # Use the SINGLE_ENDED input mode to get the number of channels.
    # If the number of channels is greater than zero, then the device
    # supports the SINGLE_ENDED input mode; otherwise, the device only
    # supports the DIFFERENTIAL input mode.
    number_of_channels = ai_info.get_num_chans_by_mode(AiInputMode.SINGLE_ENDED)
    if number_of_channels > 0:
        input_mode = AiInputMode.SINGLE_ENDED
    else:
        input_mode = AiInputMode.DIFFERENTIAL

    if num_analog_scan_channels >= number_of_channels:
        num_analog_scan_channels = number_of_channels - 1

    ranges = ai_info.get_ranges(input_mode)

    # Fill a descriptor for each channel
    for chan in range(num_analog_scan_channels):
        descriptor = DaqInChanDescriptor(chan, input_mode, ranges[range_index])

        channel_descriptors.append(descriptor)

        # Uncomment the section below to enable IEPE mode, set the coupling mode
        # to AC and set the sensor sensitivity for each analog input channel.

        # from uldaq import IepeMode, CouplingMode
        # ai_config = ai_device.get_config()
        # ai_config.set_chan_iepe_mode(chan, IepeMode.ENABLED)
        # ai_config.set_chan_coupling_mode(chan, CouplingMode.AC)
        # ai_config.set_chan_sensor_sensitivity(chan, 1.0)  # 1.0 V/unit


def configure_digital_input_channels(daq_device, channel_descriptors):
    """Configure the digital input channels."""
    port_types_index = 0

    # Get the number of analog channels
    dio_device = daq_device.get_dio_device()
    dio_info = dio_device.get_info()

    # Get the port types
    port_types = dio_info.get_port_types()

    if port_types_index >= len(port_types):
        port_types_index = len(port_types) - 1

    port_to_write = port_types[port_types_index]

    # Configure the port for input
    dio_device.d_config_port(port_to_write, DigitalDirection.INPUT)

    descriptor = DaqInChanDescriptor(port_to_write, DaqInChanType.DIGITAL)

    channel_descriptors.append(descriptor)


def configure_counter_input_channels(daq_device, channel_descriptors):
    """Configure the counter input channels."""
    num_counter_scan_channels = 1

    # get the number of analog channels
    ctr_device = daq_device.get_ctr_device()
    ctr_info = ctr_device.get_info()
    number_of_counters = ctr_info.get_num_ctrs()

    if num_counter_scan_channels >= number_of_counters:
        num_counter_scan_channels = number_of_counters - 1

    # fill a descriptor for each event counter channel
    for ctr in range(num_counter_scan_channels):
        # get the measurement types
        measurement_types = ctr_info.get_measurement_types(ctr)

        if CounterMeasurementType.COUNT in measurement_types:
            descriptor = DaqInChanDescriptor(ctr, DaqInChanType.CTR32)

            channel_descriptors.append(descriptor)


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


def clear_eol():
    """Clear all characters to the end of the line."""
    stdout.write('\x1b[2K')


if __name__ == '__main__':
    main()
