===========  ===============================================================================================
Info         Contains a Python API for interacting with Measurement Computing's Universal Library for Linux.
Author       Measurement Computing
===========  ===============================================================================================

About
=====

The **uldaq** Python package contains an API (Application Programming Interface)
for interacting with Measurement Computing DAQ devices. The package is implemented
as an object-oriented wrapper around the UL for Linux C API using the `ctypes <https://docs.python.org/2/library/ctypes.html>`_ Python library.

**uldaq** supports Python 2.7, 3.4+

Prerequisites
=============

Running the **uldaq** Python API requires the ``UL for Linux C API``.

* Visit `uldaq on GitHub <https://github.com/mccdaq/uldaq/>`_
  to install the latest version of the UL for Linux C API.

Installing the **uldaq** Python API requires ``Python`` along with the ``pip``, ``setuptools`` and ``wheel`` packages.

* For more information on installing Python, go to `python.org <https://www.python.org/>`_.
* For more information on installing Python packages with pip, see the
  `Installing Packages <https://packaging.python.org/tutorials/installing-packages/>`_ tutorial on python.org.

Installation
============

Install the **uldaq** Python API with::

  $ pip install uldaq

..

  **Note**: Installation may need to be run with sudo.

Examples
========
A complete set of examples is include in the source tarball.
To obtain and run the examples, follow these steps:

#. Go to `pypi.org/project/uldaq <https://pypi.org/project/uldaq/>`_.
#. Under **Navigation** click the ``Download files`` link.
#. Click the ``uldaq-1.2.1.tar.gz`` link to download the file.
#. Copy the file from the default download location to a desired location.
#. Navigate to the file location and run::

    $ tar -xvf uldaq-1.2.1.tar.gz


#. The Python examples are located in the examples folder. Run the following commands to execute the analog input example::

    $ cd uldaq-1.2.1/examples
    $ ./a_in.py

  **Note**: For best results, run examples in a terminal window.

Usage
=====
The following is a simple example for reading a single voltage value from each channel in
an analog input subsystem of a Measurement Computing DAQ device.

.. code-block:: python

 from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                    AiInputMode, Range, AInFlag)

 try:
     # Get a list of available DAQ devices
     devices = get_daq_device_inventory(InterfaceType.USB)
     # Create a DaqDevice Object and connect to the device
     daq_device = DaqDevice(devices[0])
     daq_device.connect()
     # Get AiDevice and AiInfo objects for the analog input subsystem
     ai_device = daq_device.get_ai_device()
     ai_info = ai_device.get_info()

     # Read and display voltage values for all analog input channels
     for channel in range(ai_info.get_num_chans()):
         data = ai_device.a_in(channel, AiInputMode.SINGLE_ENDED,
                               Range.BIP10VOLTS, AInFlag.DEFAULT)
         print('Channel', channel, 'Data:', data)

     daq_device.disconnect()
     daq_device.release()

 except ULException as e:
     print('\n', e)  # Display any error messages

The same example using a with block:

.. code-block:: python

 from uldaq import (get_daq_device_inventory, DaqDevice, InterfaceType,
                    AiInputMode, Range, AInFlag)

 try:
     # Get a list of available devices
     devices = get_daq_device_inventory(InterfaceType.USB)
     # Create a DaqDevice Object and connect to the device
     with DaqDevice(devices[0]) as daq_device:
         # Get AiDevice and AiInfo objects for the analog input subsystem
         ai_device = daq_device.get_ai_device()
         ai_info = ai_device.get_info()

         # Read and display voltage values for all analog input channels
         for channel in range(ai_info.get_num_chans()):
             data = ai_device.a_in(channel, AiInputMode.SINGLE_ENDED,
                                   Range.BIP10VOLTS, AInFlag.DEFAULT)
             print('Channel', channel, 'Data:', data)

 except ULException as e:
     print('\n', e)  # Display any error messages

Support/Feedback
================
The **uldaq** package is supported by MCC. For **uldaq** support, contact technical support
through `mccdaq.com/Support.aspx <http://www.mccdaq.com/Support.aspx>`_ . Please include version information for Python,
uldaq C API and uldaq Python API packages used as well as detailed steps on how to reproduce the
problem.

Documentation
=============
Documentation is available at `mccdaq.com <https://www.mccdaq.com/PDFs/Manuals/UL-Linux/python/>`_.

License
=======
**uldaq** is licensed under an MIT-style license. Other incorporated projects may be licensed under
different licenses. All licenses allow for non-commercial and commercial use.
