#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:    daq_device.enable_event()

Purpose:                      Use events to determine when data is available

Demonstration:                Use the a callback function to display the
                              the data for a user-specified range of
                              A/D channels

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_ai_device() to get the ai_device object for the AI
    subsystem
4.  Verify the ai_device object is valid
5.  Call ai_device.get_info() to get the ai_info object for the AI subsystem
6.  Verify the analog input subsystem has a hardware pacer
7.  Call daq_device.connect() to establish a UL connection to the DAQ device
8.  Initialize the ScanEventParameters structure used to pass parameters to
    the callback function
9.  Call daq_device.enable_event to enable the DE_ON_DATA_AVAILABLE event
10. Call ai_device.a_in_scan() to start a finite scan of the A/D channels
11. The callback is called each time 100 samples are available to allow the
    data to be displayed
12. Call ai_device.scan_stop() to stop the background operation
13. Call daq_device.disconnect() and daq_device.release() before exiting the
    process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout
from collections import namedtuple

from uldaq import (get_daq_device_inventory, DaqDevice, AInScanFlag,
                   DaqEventType, ScanOption, InterfaceType, AiInputMode,
                   create_float_buffer, ULException, EventCallbackArgs)

RATE = 100


def main():
    """Analog input scan with events example."""
    global RATE
    daq_device = None
    ai_device = None
    ai_info = None

    range_index = 0
    interface_type = InterfaceType.ANY
    low_channel = 0
    high_channel = 3
    samples_per_channel = 10000
    flags = AInScanFlag.DEFAULT
    event_types = (DaqEventType.ON_DATA_AVAILABLE
                   | DaqEventType.ON_END_OF_INPUT_SCAN
                   | DaqEventType.ON_INPUT_SCAN_ERROR)

    scan_params = namedtuple('scan_params',
                             'buffer high_chan low_chan descriptor status')

    # set the scan options for a FINITE scan ... to set the scan options for
    # a continuous scan, uncomment the line that or's the SO_CONTINUOUS option
    # into to the scanOptions variable
    scan_options = ScanOption.DEFAULTIO
    # scan_options |= ScanOption.CONTINUOUS

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

        # Verify the device supports hardware pacing for analog input.
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

        # Allocate a buffer to receive the data.
        data = create_float_buffer(channel_count, samples_per_channel)

        # Store the user data for use in the callback function.
        scan_status = {'complete': False, 'error': False}
        user_data = scan_params(data, high_channel, low_channel, descriptor,
                                scan_status)

        # Enable the event to be notified every time 100 samples are available.
        available_sample_count = 100
        daq_device.enable_event(event_types, available_sample_count,
                                event_callback_function, user_data)

        print('\n', descriptor.dev_string, 'ready', sep='')
        print('    Function demonstrated: daq_device.enable_event()')
        print('    Channels: ', low_channel, '-', high_channel)
        print('    Input mode: ', input_mode.name)
        print('    Range: ', ranges[range_index].name)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', RATE, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        # Start the finite acquisition.
        RATE = ai_device.a_in_scan(low_channel, high_channel, input_mode,
                                   ranges[range_index], samples_per_channel,
                                   RATE, scan_options, flags, data)

        # Wait here until the scan is done ... events will be handled in the
        # event handler (eventCallbackFunction).
        # The scan_status values are set in the event handler callback.
        while not scan_status['complete'] and not scan_status['error']:
            sleep(0.1)

    except KeyboardInterrupt:
        pass
    except (ValueError, NameError, SyntaxError):
        pass
    except RuntimeError as error:
        print('\n', error)
    finally:
        if daq_device:
            if daq_device.is_connected():
                # Stop the acquisition if it is still running.
                if ai_device and ai_info and ai_info.has_pacer():
                    ai_device.scan_stop()
                daq_device.disable_event(event_types)
                daq_device.disconnect()
            daq_device.release()


def event_callback_function(event_callback_args):
    # type: (EventCallbackArgs) -> None
    """
    The callback function called in response to an event condition.

    Args:
        event_callback_args: Named tuple :class:`EventCallbackArgs` used to pass
            parameters to the user defined event callback function
            :class`DaqEventCallback`.
            The named tuple contains the following members
            event_type - the condition that triggered the event
            event_data - additional data that specifies an event condition
            user_data - user specified data
    """

    event_type = DaqEventType(event_callback_args.event_type)
    event_data = event_callback_args.event_data
    user_data = event_callback_args.user_data

    if (event_type == DaqEventType.ON_DATA_AVAILABLE
            or event_type == DaqEventType.ON_END_OF_INPUT_SCAN):
        reset_cursor()
        print('Please enter CTRL + C to terminate the process\n')
        print('Active DAQ device: ',
              user_data.descriptor.dev_string, ' (',
              user_data.descriptor.unique_id, ')\n', sep='')
        clear_eol()
        print('eventType: ', event_type.name)

        chan_count = user_data.high_chan - user_data.low_chan + 1
        scan_count = event_data
        total_samples = scan_count * chan_count

        clear_eol()
        print('eventData: ', event_data, '\n')
        print('actual scan rate = ', '{:.6f}'.format(RATE), 'Hz\n')

        # Using the remainder after dividing by the buffer length handles wrap
        # around conditions if the example is changed to a CONTINUOUS scan.
        index = (total_samples - chan_count) % user_data.buffer._length_
        clear_eol()
        print('currentIndex = ', index, '\n')

        for i in range(chan_count):
            clear_eol()
            print('chan =',
                  i + user_data.low_chan,
                  '{:10.6f}'.format(user_data.buffer[index + i]))

    if event_type == DaqEventType.ON_INPUT_SCAN_ERROR:
        exception = ULException(event_data)
        print(exception)
        user_data.status['error'] = True

    if event_type == DaqEventType.ON_END_OF_INPUT_SCAN:
        print('\nThe scan is complete\n')
        user_data.status['complete'] = True


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
