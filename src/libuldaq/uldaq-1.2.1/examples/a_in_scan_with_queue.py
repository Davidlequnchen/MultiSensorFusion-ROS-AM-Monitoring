#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
Wrapper call demonstrated:    ai_device.a_in_load_queue()

Purpose:                      Set up the queue with available ranges
                              and input modes

Demonstration:                Initialize and load the queue

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_ai_device() to get the ai_device object for the AI
    subsystem
4.  Verify the ai_device object is valid
5.  Call ai_device.get_info() to get the ai_info object for the AI subsystem
6.  Verify the analog input subsystem has a hardware pacer
7.  Call daq_device.connect() to establish a UL connection to the DAQ device
8.  Call ai_info.get_queue_types() to get the supported queue types for the AI
    subsystem
9.  Create the queue array
10. Call ai_device.a_in_load_queue() to load the queue
11. Call ai_device.a_in_scan() to start the scan of A/D input channels
12. Call ai_device.get_scan_status() to check the status of the background
    operation
13. Display the data for each channel
14. Call ai_device.scan_stop() to stop the background operation
15. Call daq_device.disconnect() and daq_device.release() before exiting the
    process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (get_daq_device_inventory, DaqDevice, AInScanFlag,
                   AiInputMode, AiQueueElement, create_float_buffer,
                   ScanOption, ScanStatus, InterfaceType, Range)


def main():
    """Analog input scan with queue example."""
    daq_device = None
    ai_device = None
    status = ScanStatus.IDLE

    range_index = 0
    interface_type = InterfaceType.ANY
    low_channel = 0
    high_channel = 3
    samples_per_channel = 10000
    rate = 100
    scan_options = ScanOption.DEFAULTIO | ScanOption.CONTINUOUS
    flags = AInScanFlag.DEFAULT

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

        # Get the AiDevice object and verify that it is valid.
        ai_device = daq_device.get_ai_device()
        if ai_device is None:
            raise RuntimeError('Error: The DAQ device does not support analog '
                               'input')

        # Verify the specified device supports hardware pacing for analog input.
        ai_info = ai_device.get_info()
        if not ai_info.has_pacer():
            raise RuntimeError('Error: The specified DAQ device does not '
                               'support hardware paced analog input')

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # The default input mode is SINGLE_ENDED.
        input_mode = AiInputMode.SINGLE_ENDED
        # If SINGLE_ENDED input mode is not supported, set to DIFFERENTIAL.
        if ai_info.get_num_chans_by_mode(AiInputMode.SINGLE_ENDED) <= 0:
            input_mode = AiInputMode.DIFFERENTIAL

        # Get the number of channels and validate the high channel number.
        number_of_channels = ai_info.get_num_chans_by_mode(input_mode)
        if high_channel >= number_of_channels:
            high_channel = number_of_channels - 1
        channel_count = high_channel - low_channel + 1

        # Get a list of supported ranges and validate the range index.
        ranges = ai_info.get_ranges(input_mode)
        if range_index >= len(ranges):
            range_index = len(ranges) - 1

        # Get a list of supported queue types.
        queue_types = ai_info.get_queue_types()
        if not queue_types:
            raise RuntimeError('Error: The device does not support a gain '
                               'queue')

        # Assign each channel in the queue an input mode (SE/DIFF) and a range.
        # If multiple ranges are supported, we will cycle through them and
        # repeat ranges if the number of channels exceeds the number of ranges.
        #
        # This block of code could be used to set other queue elements such as
        # the input mode and channel list.
        queue_list = []
        for i in range(channel_count):
            queue_element = AiQueueElement()
            queue_element.channel = i
            queue_element.input_mode = input_mode
            queue_element.range = ranges[range_index]

            queue_list.append(queue_element)

            range_index += 1
            if range_index >= len(ranges):
                range_index = 0

        # Load the queue.
        ai_device.a_in_load_queue(queue_list)

        data = create_float_buffer(channel_count, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: ai_device.a_in_load_queue()')
        print('    Channels: ', low_channel, '-', high_channel)
        for i in range(channel_count):
            print('        Channel:', queue_list[i].channel,
                  ', Input mode:', AiInputMode(queue_list[i].input_mode).name,
                  ', Range:', Range(queue_list[i].range).name)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        # Start the acquisition.
        #
        # When using the queue, the low_channel, high_channel, input_mode, and
        # range parameters are ignored since they are specified in queue_array.
        rate = ai_device.a_in_scan(low_channel, high_channel, input_mode,
                                   ranges[range_index], samples_per_channel,
                                   rate, scan_options, flags, data)

        system('clear')

        try:
            while True:
                try:
                    # Get the status of the background operation
                    status, transfer_status = ai_device.get_scan_status()

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

                    # Display the data.
                    for i in range(channel_count):
                        print('chan =',
                              i + low_channel, ': ',
                              '{:.6f}'.format(data[index + i]))

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
            if status == ScanStatus.RUNNING:
                ai_device.scan_stop()
            if daq_device.is_connected():
                daq_device.disconnect()
            daq_device.release()


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
