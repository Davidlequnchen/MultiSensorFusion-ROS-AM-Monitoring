#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Wrapper call demonstrated:    ai_device.t_in()

Purpose:                      Reads the user-specified A/D input channels.

Demonstration:                Displays the analog input temperature data
                              for each of the user-specified channels.

Steps:
1. Call get_daq_device_inventory() to get the list of available DAQ devices.
2. Create a DaqDevice object.
3. Call daq_device.get_ai_device() to get the ai_device object for the
   analog input subsystem.
4. Verify the ai_device object is valid.
5. Verify the device supports temperature channels types.
6. Call daq_device.connect() to establish a UL connection to the DAQ device.
7. Call ai_device.t_in() to read a value from an A/D input channel.
8. Display the data for each channel.
9. Call daq_device.disconnect() and daq_device.release() before exiting the
   process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                   TempScale, AiChanType, ULException, ULError)

USB_2416_ID = 0xd0
USB_2416_4AO_ID = 0xd1
USB_2408_ID = 0xfd
USB_2408_2AO_ID = 0xfe


def main():
    """Temperature input example."""
    daq_device = None

    interface_type = InterfaceType.ANY
    low_channel = 0
    high_channel = 3
    scale = TempScale.CELSIUS

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
            raise RuntimeError(
                'Error: The DAQ device does not support analog input')

        # Verify that the DAQ device has temperature channels.
        ai_info = ai_device.get_info()
        chan_types = ai_info.get_chan_types()
        if (AiChanType.TC not in chan_types
                and AiChanType.RTD not in chan_types
                and AiChanType.SEMICONDUCTOR not in chan_types
                and AiChanType.THERMISTOR not in chan_types):
            raise RuntimeError(
                'Error: The DAQ device does not support temperature channels')

        # Verify the DAQ device has the specified number of channels
        number_of_channels = ai_info.get_num_chans()
        if high_channel >= number_of_channels:
            high_channel = number_of_channels - 1

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: ai_device.t_in()')
        print('    Channels: ', low_channel, '-', high_channel)
        # Display channel configuration information.
        ai_config = ai_device.get_config()
        for chan in range(low_channel, high_channel + 1):
            # Set the specified analog channels to TC type if the specified
            # DAQ device is a USB-2408 or USB-2416 device
            if (descriptor.product_id == USB_2416_ID
                    or descriptor.product_id == USB_2416_4AO_ID
                    or descriptor.product_id == USB_2408_ID
                    or descriptor.product_id == USB_2408_2AO_ID):
                ai_config.set_chan_type(chan, AiChanType.TC)

            chan_type = -1
            chan_type_str = 'N/A'
            try:
                chan_type = ai_config.get_chan_type(chan)
                chan_type_str = chan_type.name
            except ULException as ul_error:
                if ul_error.error_code != ULError.CONFIG_NOT_SUPPORTED:
                    raise ul_error

            if chan_type == AiChanType.TC:
                tc_type = ai_config.get_chan_tc_type(chan)
                chan_type_str += ' Type ' + tc_type.name
            elif (chan_type == AiChanType.RTD
                  or chan_type == AiChanType.THERMISTOR):
                connect_type = ai_config.get_chan_sensor_connection_type(chan)
                chan_type_str += ' ' + connect_type.name
            print('        Channel', chan, 'type:', chan_type_str)
        print('    Temperature scaling:', scale.name)

        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        try:
            while True:
                try:
                    display_strings = []
                    # Read data for the specified analog input channels.
                    for channel in range(low_channel, high_channel + 1):
                        try:
                            data = ai_device.t_in(channel, scale)
                            display_strings.append('Channel(' + str(channel)
                                                   + ') Data: '
                                                   + '{:10.6f}'.format(data))
                        except ULException as ul_error:
                            if ul_error.error_code == ULError.OPEN_CONNECTION:
                                display_strings.append('Channel(' + str(channel)
                                                       + ') Data: '
                                                       + 'Open Connection')
                            else:
                                raise ul_error

                    reset_cursor()
                    print('Please enter CTRL + C to terminate the process\n')
                    print('Active DAQ device: ', descriptor.dev_string, ' (',
                          descriptor.unique_id, ')\n', sep='')

                    # Display data for the specified analog input channels.
                    for display_string in display_strings:
                        clear_eol()
                        print(display_string)

                    sleep(0.5)
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
