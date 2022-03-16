#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
Wrapper call demonstrated:      ai_device.a_in_scan() with IEPE mode enabled

Purpose:                        Performs a continuous scan of the range
                                of A/D input channels

Demonstration:                  Displays the analog input data for the
                                range of user-specified channels using
                                the first supported range and input mode.
                                IEPE mode is enabled for all of specified
                                channels.

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_ai_device() to get the ai_device object for the AI
    subsystem
4.  Verify the ai_device object is valid
5.  Call ai_device.get_info() to get the ai_info object for the AI subsystem
6.  Verify the analog input subsystem has a hardware pacer
7.  Call daq_device.connect() to establish a UL connection to the DAQ device
8.  Enable IEPE mode for the specified channels
9.  Set coupling mode to AC for the specified channels
10. Call ai_device.a_in_scan() to start a scan
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
                   InterfaceType, AiInputMode, IepeMode, CouplingMode)


def main():
    """IEPE Analog input scan example."""
    daq_device = None
    ai_device = None
    status = ScanStatus.IDLE

    range_index = 0
    iepe_mode = IepeMode.ENABLED
    coupling = CouplingMode.AC
    sensor_sensitivity = 1.0  # volts per unit
    interface_type = InterfaceType.ANY
    low_channel = 0
    high_channel = 3
    samples_per_channel = 10000
    rate = 100
    scan_options = ScanOption.CONTINUOUS
    flags = AInScanFlag.DEFAULT

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

        # Get the AiDevice object and verify that it is valid.
        ai_device = daq_device.get_ai_device()
        if ai_device is None:
            raise RuntimeError(
                'Error: The DAQ device does not support analog input')

        # Verify the device supports hardware pacing for analog input.
        ai_info = ai_device.get_info()
        if not ai_info.has_pacer():
            raise RuntimeError('Error: The DAQ device does not support '
                               'hardware paced analog input')

        # Verify the device supports IEPE
        if not ai_info.supports_iepe():
            raise RuntimeError('Error: The DAQ device does not support IEPE')

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

        # Set IEPE mode, AC coupling and sensor sensitivity for each channel
        ai_config = ai_device.get_config()
        for chan in range(low_channel, high_channel + 1):
            ai_config.set_chan_iepe_mode(chan, iepe_mode)
            ai_config.set_chan_coupling_mode(chan, coupling)
            ai_config.set_chan_sensor_sensitivity(chan, sensor_sensitivity)

        data = create_float_buffer(channel_count, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: ai_device.a_in_scan()')
        print('    Channels: ', low_channel, '-', high_channel)
        print('    Input mode: ', input_mode.name)
        print('    Range: ', ranges[range_index].name)
        print('    Samples per channel: ', samples_per_channel)
        print('    Rate: ', rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        print('    Sensor Sensitivity: {:.6f}'.format(sensor_sensitivity),
              '(V/unit)')
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        system('clear')

        rate = ai_device.a_in_scan(low_channel, high_channel, input_mode,
                                   ranges[range_index], samples_per_channel,
                                   rate, scan_options, flags, data)

        try:
            while True:
                try:
                    status, transfer_status = ai_device.get_scan_status()

                    index = transfer_status.current_index
                    if index >= 0:
                        system('clear')
                        print('Please enter CTRL + C to terminate the process',
                              '\n')
                        print('Active DAQ device: ', descriptor.dev_string,
                              ' (', descriptor.unique_id, ')\n', sep='')
                        print('Actual scan rate = {:.6f}\n'.format(rate))
                        print('currentTotalCount = ',
                              transfer_status.current_total_count)
                        print('currentScanCount = ',
                              transfer_status.current_scan_count)
                        print('currentIndex = ', index, '\n')

                        for i in range(channel_count):
                            print('chan ', i + low_channel, ' = ',
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
