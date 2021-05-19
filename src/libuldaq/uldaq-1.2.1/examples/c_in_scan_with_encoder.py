#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
UL call demonstrated:             CtrDevice.c_config_scan()

Purpose:                          Performs a continuous scan of the
                                  specified encoder channel

Demonstration:                    Displays the event counter data for
                                  the specified encoders

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Create a DaqDevice object
3.  Call daq_device.get_ctr_device() to get the ctr_device object for the CTR
    subsystem
4.  Verify the ctr_device object is valid
5.  Call ctr_device.get_info() to get the ctr_info object for the CTR subsystem
6.  Verify the counter input subsystem has a hardware pacer
7.  Call daq_device.connect() to establish a UL connection to the DAQ device
8.  Call ctr_device.c_config_scan() to configure the encoder channel
9.  Call ctr_device.c_in_scan() to start a scan for the specified number of
    counters
10. Call ctr_device.get_scan_status() in a loop and display the last
    value in the buffer from each counter
11. Display the data for each encoder channel
12. Call ctr_device.scan_stop() to stop the background operation
13. Call daq_device.disconnect() and daq_device.release() before exiting the
    process.
"""
from __future__ import print_function
from time import sleep
from os import system
from sys import stdout

from uldaq import (get_daq_device_inventory, InterfaceType, ScanStatus,
                   ScanOption, CInScanFlag, CounterMeasurementType,
                   CounterMeasurementMode, CounterEdgeDetection,
                   CounterTickSize, CounterDebounceMode, CounterDebounceTime,
                   CConfigScanFlag, create_int_buffer, DaqDevice)


def main():
    """Counter input scan with encoder example."""
    daq_device = None
    ctr_device = None
    status = ScanStatus.IDLE

    interface_type = InterfaceType.ANY
    low_encoder = 0
    encoder_count = 2
    sample_rate = 1000.0  # Hz
    samples_per_channel = 10000
    scan_options = ScanOption.CONTINUOUS
    scan_flags = CInScanFlag.DEFAULT

    encoder_type = CounterMeasurementType.ENCODER
    encoder_mode = (CounterMeasurementMode.ENCODER_X1
                    | CounterMeasurementMode.ENCODER_CLEAR_ON_Z)
    edge_detection = CounterEdgeDetection.RISING_EDGE
    tick_size = CounterTickSize.TICK_20ns
    debounce_mode = CounterDebounceMode.NONE
    debounce_time = CounterDebounceTime.DEBOUNCE_0ns
    config_flags = CConfigScanFlag.DEFAULT

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

        # Get the CtrDevice object and verify that it is valid.
        ctr_device = daq_device.get_ctr_device()
        if ctr_device is None:
            raise RuntimeError('Error: The DAQ device does not support '
                               'counters')

        # Verify the specified device supports hardware pacing for counters.
        ctr_info = ctr_device.get_info()
        if not ctr_info.has_pacer():
            raise RuntimeError('\nError: The specified DAQ device does not '
                               'support hardware paced counter input')

        # Establish a connection to the DAQ device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        # Get the encoder counter channels.
        encoder_counters = get_supported_encoder_counters(ctr_info)
        if not encoder_counters:
            raise RuntimeError('\nError: The specified DAQ device does not '
                               'support encoder channels')

        # Verify that the low_encoder number is valid.
        first_encoder = encoder_counters[0]
        if low_encoder < first_encoder:
            low_encoder = first_encoder

        if low_encoder > first_encoder + len(encoder_counters) - 1:
            low_encoder = first_encoder

        # Verify that the encoder count is valid.
        if encoder_count > len(encoder_counters):
            encoder_count = len(encoder_counters)

        # Set the high_encoder channel.
        high_encoder = low_encoder + encoder_count - 1
        if high_encoder > first_encoder + len(encoder_counters) - 1:
            high_encoder = first_encoder + len(encoder_counters) - 1

        # update the actual number of encoders being used
        encoder_count = high_encoder - low_encoder + 1

        # Clear the counter, and configure the counter as an encoder.
        for encoder in range(low_encoder, high_encoder + 1):
            ctr_device.c_config_scan(encoder, encoder_type, encoder_mode,
                                     edge_detection, tick_size, debounce_mode,
                                     debounce_time, config_flags)

        # Allocate a buffer to receive the data.
        data = create_int_buffer(encoder_count, samples_per_channel)

        print('\n', descriptor.dev_string, ' ready', sep='')
        print('    Function demonstrated: ctr_device.c_config_scan()')
        print('    Counter(s):', low_encoder, '-', high_encoder)
        print('    Sample rate:', sample_rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue\n')
        except (NameError, SyntaxError):
            pass

        # Start the scan
        ctr_device.c_in_scan(low_encoder, high_encoder, samples_per_channel,
                             sample_rate, scan_options, scan_flags, data)

        system('clear')

        try:
            while True:
                try:
                    status, transfer_status = ctr_device.get_scan_status()

                    reset_cursor()
                    print('Please enter CTRL + C to terminate the process\n')
                    print('Active DAQ device: ', descriptor.dev_string, ' (',
                          descriptor.unique_id, ')\n', sep='')

                    print('actual scan rate = ', '{:.6f}'.format(sample_rate),
                          'Hz\n')

                    index = transfer_status.current_index
                    print('currentScanCount = ',
                          transfer_status.current_scan_count)
                    print('currentTotalCount = ',
                          transfer_status.current_total_count)
                    print('currentIndex = ', index, '\n')

                    for encoder_index in range(encoder_count):
                        print('chan =', (encoder_index + low_encoder), ': ',
                              '{:.6f}'.format(data[index + encoder_index]))

                    sleep(0.1)
                    if status != ScanStatus.RUNNING:
                        break
                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            if status == ScanStatus.RUNNING:
                ctr_device.scan_stop()
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


def get_supported_encoder_counters(ctr_info):
    """Create a list of supported encoder counters for the specified device."""
    encoders = []

    number_of_counters = ctr_info.get_num_ctrs()
    for counter_number in range(number_of_counters):
        measurement_types = ctr_info.get_measurement_types(counter_number)

        if CounterMeasurementType.ENCODER in measurement_types:
            encoders.append(counter_number)

    return encoders


def reset_cursor():
    """Reset the cursor in the terminal window."""
    stdout.write('\033[1;1H')


if __name__ == '__main__':
    main()
