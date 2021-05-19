#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
UL call demonstrated:             CtrDevice.c_in_scan()

Purpose:                          Performs a continuous scan of the
                                  all supported event counter channels

Demonstration:                    Displays the event counter data for
                                  the first supported event counter

Steps:
1.  Call get_daq_device_inventory() to get the list of available DAQ devices
2.  Call DaqDevice() to create a DaqDevice object
3.  Call DaqDevice.get_ctr_device() to get the CtrDevice object for the counter
    subsystem
4.  Verify the CtrDevice object is valid
5.  Verify the counter subsystem has a hardware pacer
6.  Call DaqDevice.connect() to connect to the device
9.  Call CtrDevice.c_in_scan() to start a scan for the specified number of
    counters
10. Call CtrDevice.get_scan_status() to check the status of the scan operation
11. Display the data for each channel
12. Call CtrDevice.scan_stop() to stop the scan operation
13. Call DaqDevice.disconnect() and DaqDevice.release() before exiting the
    process
"""
from __future__ import print_function
from time import sleep
from sys import stdout
from os import system

from uldaq import (get_daq_device_inventory, DaqDevice, create_int_buffer,
                   InterfaceType, CInScanFlag, ScanStatus, ScanOption,
                   CounterMeasurementType)

# Constants
CURSOR_UP = '\x1b[1A'
ERASE_LINE = '\x1b[2K'


def main():
    """Counter input scan example."""
    low_counter = 0
    high_counter = 1
    samples_per_channel = 2000  # Two second buffer (sample_rate * 2)
    sample_rate = 1000.0  # Hz
    scan_options = ScanOption.CONTINUOUS
    scan_flags = CInScanFlag.DEFAULT

    interface_type = InterfaceType.ANY
    daq_device = None
    ctr_device = None
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
        ctr_device = daq_device.get_ctr_device()

        # Verify the specified DAQ device supports counters.
        if ctr_device is None:
            raise RuntimeError('Error: The DAQ device does not support '
                               'counters')

        # Verify the specified DAQ device supports hardware pacing for counters.
        ctr_info = ctr_device.get_info()
        if not ctr_info.has_pacer():
            raise RuntimeError('Error: The DAQ device does not support paced '
                               'counter inputs')

        # Verify that the selected counters support event counting.
        verify_counters_support_events(ctr_info, low_counter, high_counter)

        number_of_counters = high_counter - low_counter + 1

        # Establish a connection to the device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        print('\n', descriptor.dev_string, 'ready')
        print('    Function demonstrated: CtrDevice.c_in_scan')
        print('    Counter(s):', low_counter, '-', high_counter)
        print('    Samples per channel:', samples_per_channel)
        print('    Sample rate:', sample_rate, 'Hz')
        print('    Scan options:', display_scan_options(scan_options))
        try:
            input('\nHit ENTER to continue')
        except (NameError, SyntaxError):
            pass

        # Create a buffer for input data.
        data = create_int_buffer(number_of_counters, samples_per_channel)
        # Start the input scan.
        sample_rate = ctr_device.c_in_scan(low_counter, high_counter,
                                           samples_per_channel, sample_rate,
                                           scan_options, scan_flags, data)

        system('clear')
        print('Please enter CTRL + C to terminate the process\n')
        print('Active DAQ device: ', descriptor.dev_string, ' (',
              descriptor.unique_id, ')\n', sep='')
        print('    Actual scan rate:   ', sample_rate, 'Hz')

        try:
            while True:
                try:
                    # Read and display the current scan status.
                    scan_status, transfer_status = ctr_device.get_scan_status()
                    if scan_status != ScanStatus.RUNNING:
                        break

                    print('    Current scan count: ',
                          transfer_status.current_scan_count)
                    print('    Current total count:',
                          transfer_status.current_total_count)
                    print('    Current index:      ',
                          transfer_status.current_index)
                    print('')

                    # Read and display the data for each counter.
                    for counter_index in range(number_of_counters):
                        counter_value = data[transfer_status.current_index
                                             - counter_index]
                        print('    Counter ', (counter_index + low_counter),
                              ':', str(counter_value).rjust(12), sep='')

                    stdout.flush()
                    sleep(0.1)
                    # Clear the previous status.
                    for _line in range(4 + number_of_counters):
                        stdout.write(CURSOR_UP + ERASE_LINE)

                except (ValueError, NameError, SyntaxError):
                    break
        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            # Stop the scan.
            if scan_status == ScanStatus.RUNNING:
                ctr_device.scan_stop()
            # Disconnect from the DAQ device.
            if daq_device.is_connected():
                daq_device.disconnect()
            # Release the DAQ device resource.
            daq_device.release()

    return


def verify_counters_support_events(ctr_info, low_counter, high_counter):
    """
    Verifies that the selected counter channels support event counting.

    Raises:
        RuntimeError if a counter channel does not support event counting
        or if a counter channel is not in range.
    """
    num_counters = ctr_info.get_num_ctrs()
    valid_counters_string = ('valid counter channels are 0 - '
                             '{0:d}'.format(num_counters - 1))
    if low_counter < 0 or low_counter >= num_counters:
        error_message = ' '.join(['Error: Invalid low_counter selection,',
                                  valid_counters_string])
        raise RuntimeError(error_message)

    if high_counter < 0 or high_counter >= num_counters:
        error_message = ' '.join(['Error: Invalid high_counter selection,',
                                  valid_counters_string])
        raise RuntimeError(error_message)

    if high_counter < low_counter:
        error_message = ('Error: Invalid counter selection, high_counter must '
                         'be greater than or equal to low_counter')
        raise RuntimeError(error_message)

    for counter in range(low_counter, high_counter + 1):
        supported_meas_types = ctr_info.get_measurement_types(counter)
        if CounterMeasurementType.COUNT not in supported_meas_types:
            error_message = ('Error: Invalid counter selection, counter {0:d} '
                             'does not support event counting'.format(counter))
            raise RuntimeError(error_message)


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
