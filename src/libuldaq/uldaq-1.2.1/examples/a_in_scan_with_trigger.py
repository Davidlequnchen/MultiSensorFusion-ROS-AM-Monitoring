#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
Wrapper call demonstrated:        ai_device.set_trigger()

Purpose:                          Setup an external trigger

Demonstration:                    Uses the first available trigger type to
                                  set up an external trigger that is used
                                  to start a scan

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_ai_device() to get the ai_device object for the AI
    subsystem
4.  Verify the ai_device object is valid
5.  Call ai_device.get_info() to get the ai_info object for the AI subsystem
6.  Verify the analog input subsystem has a hardware pacer
7.  Call daq_device.connect() to establish a UL connection to the DAQ device
8.  Call ai_info.get_trigger_types() to get the supported trigger types for the
    AI subsystem
9.  Call ai_device.set_trigger() to use the first available trigger type
10. Call ai_device.a_in_scan() to start a triggered scan of of 10000 samples
11. Call ai_device.get_scan_status() to check the status of the background
    operation
12. Display the data for each channel
13. Call ai_device.scan_stop() to stop the background operation
14. Call daq_device.disconnect() and daq_device.release() before exiting the
    process.
"""
from __future__ import print_function
from time import sleep
from os import system

from uldaq import (get_daq_device_inventory, DaqDevice, AInScanFlag,
                   ScanOption, ScanStatus, create_float_buffer,
                   InterfaceType, AiInputMode)


def main():
    """Analog input scan with trigger example."""
    daq_device = None
    ai_device = None
    status = ScanStatus.IDLE

    range_index = 0
    trigger_type_index = 0
    interface_type = InterfaceType.ANY
    low_channel = 0
    high_channel = 3
    samples_per_channel = 10000
    rate = 100
    scan_options = ScanOption.CONTINUOUS | ScanOption.EXTTRIGGER
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
            raise RuntimeError('\nError: The specified DAQ device does not '
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

        # Get a list of trigger types.
        trigger_types = ai_info.get_trigger_types()
        if not trigger_types:
            raise RuntimeError('Error: The device does not support an external '
                               'trigger')

        # Set the trigger.
        #
        # This example uses the default values for setting the trigger so there
        # is no need to call this function. If you want to change the trigger
        # type (or any other trigger parameter), uncomment this function call
        # and change the trigger type (or any other parameter)
        ai_device.set_trigger(trigger_types[trigger_type_index], 0, 0, 0, 0)

        data = create_float_buffer(channel_count, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: ai_device.set_trigger()')
        print('    Channels: ', low_channel, '-', high_channel)
        print('    Input mode: ', input_mode.name)
        print('    Range: ', ranges[range_index].name)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        print('    Trigger type:', trigger_types[trigger_type_index].name)
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        ai_device.a_in_scan(low_channel, high_channel, input_mode,
                            ranges[range_index], samples_per_channel, rate,
                            scan_options, flags, data)

        print('Please enter CTRL + C to quit waiting for trigger\n')
        print('Waiting for trigger ...\n')

        try:
            while True:
                try:
                    status, transfer_status = ai_device.get_scan_status()

                    index = transfer_status.current_index
                    if index >= 0:
                        system('clear')
                        print('Please enter CTRL + C to terminate the process')
                        print('\nActive DAQ device: ', descriptor.dev_string,
                              ' (', descriptor.unique_id, ')\n', sep='')

                        print('currentTotalCount = ',
                              transfer_status.current_total_count)
                        print('currentScanCount = ',
                              transfer_status.current_scan_count)
                        print('currentIndex = ', index, '\n')

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


if __name__ == '__main__':
    main()
