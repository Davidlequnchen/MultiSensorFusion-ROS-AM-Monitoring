.. currentmodule:: uldaq

############
Introduction
############
The Python API for Linux allows users to access and control supported Measurement Computing
hardware using the Python language over the Linux platform. Python 2.7 and 3.4+ are supported.

The Python package name is **uldaq**. The uldaq package is implemented in Python as an interface
to the UL shared object library.

The UL for Linux API provides structures and enumerations to manage connected devices,
obtain information about device capabilities, and configure hardware settings.

.. note:: For performance reasons, data is returned in the Python API as arrays instead of lists.

The uldaq package is available on `GitHub <https://github.com/mccdaq>`_.

*************
Installation
*************
Refer to the `README file <https://github.com/mccdaq/uldaq>`_ for
information about how to download the UL for Linux package and install the API.

**************************
Creating a Python program
**************************
When creating a UL for Linux program in Python, import the uldaq package to use in your
code:  :code:`import uldaq`

Refer to the example programs and the API documentation in the *Python API Reference*
for more information.

*****************
Example programs
*****************
UL for Linux example programs are available to run with MCC hardware. Refer to the
`README file <https://github.com/mccdaq/uldaq>`_ for
information about how to download and extract the examples.

Connect a supported Measurement Computing DAQ device to your system before
running an example. Complete these steps to run a UL for Linux example:

 1. Open a terminal window in the UL for Linux examples folder directory.
 2. Enter `./file_name.py`.
    For example, enter `./a_in.py` to run the analog input example.

Users can also choose to import the example code into an IDE, such as PyCharm or Eclipse, and run the examples
from that environment.

.. tabularcolumns:: |p{100pt}|p{300pt}|

The example download file includes the following example programs:

    ========================    =========================================================
    **Method**                  **Description**
    ------------------------    ---------------------------------------------------------
    a_in                        Reads an A/D input channel.
                                Demonstrates :func:`~AiDevice.a_in`.
    a_in_scan                   Scans a range of A/D input channels, and stores
                                the data in an array. Demonstrates
                                :func:`~AiDevice.a_in_scan` and
                                :func:`~AiDevice.scan_stop`.
    a_in_scan_with_events       Performs an A/D scan using events to determine
                                the data in an array. Demonstrates
                                when data is available or when the acquisition
                                is complete. The example also demonstrates how
                                to retrieve the data when it becomes available.
                                Demonstrates :func:`~DaqDevice.enable_event`,
                                :func:`~AiDevice.scan_wait` and
                                :func:`~AiDevice.scan_stop`.
    a_in_scan_with_queue        Creates a queue that sets individual channel
                                ranges for an A/D scan. Demonstrates
                                :func:`~AiDevice.a_in_load_queue`,
                                :func:`~AiDevice.a_in_scan`,
                                and :func:`~AiDevice.scan_stop`.
    a_in_scan_with_trigger      Scans a range of A/D channels when a trigger
                                is received, and stores the data in an array.
                                This example shows how to obtain and configure
                                trigger options. Demonstrates
                                :func:`~AiDevice.a_in_scan`
                                and :func:`~AiDevice.scan_stop`.
    a_in_scan_iepe              Enables IEPE mode for a range of A/D channels,
                                and scans the specified A/D channels.
                                Demonstrates :func:`~AiDevice.a_in_scan`
                                and :func:`~AiDevice.scan_stop`.
    a_out                       Writes a specified value to a D/A output
                                channel. Demonstrates :func:`~AoDevice.a_out`.
    a_out_scan                  Performs a D/A scan. Data can be viewed with
                                an oscilloscope or meter. Demonstrates
                                :func:`~AoDevice.a_out_scan` and :func:`~AoDevice.scan_stop`.
    c_in                        Sets the initial value of a counter and counts
                                events. Demonstrates :func:`~CtrDevice.c_in` and
                                :func:`~CtrDevice.c_clear`.
    c_in_scan                   Scans a range of counter channels. Demonstrates
                                :func:`~CtrDevice.c_in_scan`, :func:`~CtrDevice.c_load`
                                and :func:`~CtrDevice.scan_stop`.
    c_in_scan_with_encoder      Scans a range of encoder channels. Demonstrates
                                :func:`~CtrDevice.c_in_scan`,
                                :func:`~CtrDevice.c_config_scan`, and
                                :func:`~CtrDevice.scan_stop`.
    daq_in_scan	                Simultaneously acquires analog, digital, and
                                counter data. Demonstrates
                                :func:`~DaqiDevice.daq_in_scan`
                                and  :func:`~DaqiDevice.scan_stop`.
    daq_in_scan_with_trigger    Sets up a trigger function, and simultaneously
                                acquires analog, digital, and counter data
                                when the trigger is received. Demonstrates
                                :func:`~DaqiDevice.daq_in_scan` and
                                :func:`~DaqiDevice.scan_stop`.
    daq_out_scan                Simultaneously outputs analog and digital
                                data. Demonstrates :func:`~DaqoDevice.daq_out_scan`
                                and :func:`~DaqoDevice.scan_stop`.
    d_bit_in                    Configures multiple digital bits for input,
                                and reads the bit values. Demonstrates
                                :func:`~DioDevice.d_config_bit` and
                                :func:`~DioDevice.d_bit_in`.
    d_bit_out                   Writes a specified value to multiple digital
                                output bits. Demonstrates :func:`~DioDevice.d_config_bit`
                                and :func:`~DioDevice.d_bit_out`.
    d_in                        Configures a port for input and reads the port
                                value. Demonstrates :func:`~DioDevice.d_config_port` and
                                :func:`~DioDevice.d_in`.
    d_in_scan                   Configures a port for input and continuously
                                reads it. Demonstrates :func:`~DioDevice.d_config_port`,
                                :func:`~DioDevice.d_in_scan`, and
                                :func:`~DioDevice.d_in_scan_stop`.
    d_out                       Configures a port for output and writes a
                                specified value. Demonstrates
                                :func:`~DioDevice.d_config_port` and
                                :func:`~DioDevice.d_out`.
    d_out_scan                  Configures the port direction and outputs
                                digital data. Demonstrates
                                :func:`~DioDevice.d_config_port`,
                                :func:`~DioDevice.d_out_scan`,
                                and :func:`~DioDevice.d_out_scan_stop`.
    remote_discovery            Discovers remote Ethernet DAQ devices. Demonstrates
                                :func:`get_net_daq_device_descriptor`.
    t_in                        Reads a temperature channel.
                                Demonstrates :func:`~AiDevice.t_in`.
    tmr_pulse_out               Generates an output pulse at a specified
                                duty cycle and frequency. Demonstrates
                                :func:`~TmrDevice.pulse_out_start` and
                                :func:`~TmrDevice.pulse_out_stop`.
    ========================    =========================================================

*******************
Supported hardware
*******************
Refer to the :ref:`hwref` section for a list of all supported Measurement Computing
devices with links to supported UL for Linux capabilities.

************
Support
************
| Measurement Computing Corporation
| 508-946-5100
| Technical Support: `www.mccdaq.com/support <https://www.mccdaq.com/Support.aspx>`_
| Knowledgebase: `kb.mccdaq.com <http://kb.mccdaq.com>`_
| `www.mccdaq.com <https://www.mccdaq.com>`_
|


