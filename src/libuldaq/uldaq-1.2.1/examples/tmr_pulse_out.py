#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
UL call demonstrated:             TmrDevice.pulse_out_start()

Purpose:                          Generate an output pulse using the
                                  specified timer

Demonstration:                    Outputs user defined pulse on the
                                  specified timer

Steps:
1. Call get_daq_device_inventory() to get the list of available DAQ devices
2. Call DaqDevice() to create a DaqDevice object
3. Call DaqDevice.get_tmr_device() to get the TmrDevice object for the timer
   subsystem
4. Verify the TmrDevice object is valid
5. Call DaqDevice.connect() to connect to the device
6. Call TmrDevice.pulse_out_start() to start the output pulse for the specified
   timer
7. Call TmrDevice.get_pulse_out_status() to get the output status and display
   the status
8. Call TmrDevice.scan_stop() to stop the scan
9. Call DaqDevice.disconnect() and DaqDevice.release() before exiting the
   process
"""
from __future__ import print_function
from time import sleep
from sys import stdout
from os import system

from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                   TmrIdleState, PulseOutOption, TmrStatus)

# Constants
ERASE_LINE = '\x1b[2K'


def main():
    """Timer pulse output example."""
    timer_number = 0
    frequency = 1000.0  # Hz
    duty_cycle = 0.5  # 50 percent
    pulse_count = 0  # Continuous
    initial_delay = 0.0
    idle_state = TmrIdleState.LOW
    options = PulseOutOption.DEFAULT
    interface_type = InterfaceType.ANY
    daq_device = None
    tmr_device = None

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
        tmr_device = daq_device.get_tmr_device()

        # Verify the specified DAQ device supports timers.
        if tmr_device is None:
            raise RuntimeError('Error: The DAQ device does not support timers')

        # Establish a connection to the device.
        descriptor = daq_device.get_descriptor()
        print('\nConnecting to', descriptor.dev_string, '- please wait...')
        # For Ethernet devices using a connection_code other than the default
        # value of zero, change the line below to enter the desired code.
        daq_device.connect(connection_code=0)

        print('\n', descriptor.dev_string, 'ready')
        print('    Function demonstrated: TmrDevice.pulse_out_start')
        print('    Timer:', timer_number)
        print('    Frequency:', frequency, 'Hz')
        print('    Duty cycle:', duty_cycle)
        print('    Initial delay:', initial_delay)
        try:
            input('\nHit ENTER to continue')
        except (NameError, SyntaxError):
            pass

        # Start the timer pulse output.
        (frequency,
         duty_cycle,
         initial_delay) = tmr_device.pulse_out_start(timer_number, frequency,
                                                     duty_cycle, pulse_count,
                                                     initial_delay, idle_state,
                                                     options)

        system('clear')
        print('Please enter CTRL + C to terminate the process\n')
        print('Active DAQ device: ', descriptor.dev_string, ' (',
              descriptor.unique_id, ')\n', sep='')
        print('    Actual frequency:', frequency, 'Hz')
        print('    Actual duty cycle:', duty_cycle, 'Hz')
        print('    Actual initial delay:', initial_delay, 'Hz')

        try:
            print('\n    Outputting {0:.6f} Hz pulse with duty cycle {1:.3f} '
                  'for timer {2:d}'.format(frequency, duty_cycle, timer_number))
            status = tmr_device.get_pulse_out_status(timer_number)
            count = 0
            if status == TmrStatus.RUNNING:
                # If the status is RUNNING, then this timer does support the
                # get_pulse_out_status() function so the status is checked to
                # determine if the pulse output is stopped due to an error.
                while status == TmrStatus.RUNNING:
                    status = tmr_device.get_pulse_out_status(timer_number)
                    print_status_dots(count)
                    count += 1
            else:
                # If the status is IDLE, then this timer does not support the
                # get_pulse_out_status() function so we will wait for user
                # input to stop the pulse output.
                while True:
                    print_status_dots(count)
                    count += 1

        except KeyboardInterrupt:
            pass

    except RuntimeError as error:
        print('\n', error)

    finally:
        if daq_device:
            # Stop the scan.
            if tmr_device:
                tmr_device.pulse_out_stop(timer_number)
            stdout.write(ERASE_LINE)
            print('\r    Status:', TmrStatus.IDLE)
            # Disconnect from the DAQ device.
            if daq_device.is_connected():
                daq_device.disconnect()
            # Release the DAQ device resource.
            daq_device.release()


def print_status_dots(count):
    """Display incrementing dots to indicate a status of running."""
    if count % 6 == 0:
        stdout.write(ERASE_LINE)
        print('\r   ', TmrStatus.RUNNING, end='')
    else:
        print('.', end='')
    stdout.flush()
    sleep(0.5)


if __name__ == '__main__':
    main()
