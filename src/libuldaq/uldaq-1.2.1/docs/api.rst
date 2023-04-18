############################
Python API Reference
############################
The Python API for Linux allows users to communicate and control Measurement Computing
hardware using the Python language.

The API provides structures and enumerations to manage connected devices, obtain information about
device capabilities, and configure hardware settings. Subsystem methods provide full-functionality for
each device type.

.. currentmodule:: uldaq

*****************
Device Discovery
*****************
The API provides methods to detect DAQ devices connected to the system.

    ====================================== ==========================================
    **Method**                             **Description**
    -------------------------------------- ------------------------------------------
    :func:`get_daq_device_inventory`       Gets a list of
                                           :class:`DaqDeviceDescriptor` objects
                                           that can be used as the :class:`DaqDevice`
                                           class parameter to create DaqDevice
                                           objects.
    :func:`get_net_daq_device_descriptor`  Gets a :class:`DaqDeviceDescriptor`
                                           object for an Ethernet DAQ device that
                                           can be used as the :class:`DaqDevice`
                                           class parameter to create DaqDevice
                                           objects.
    ====================================== ==========================================

.. autofunction:: get_daq_device_inventory
.. autofunction:: get_net_daq_device_descriptor


*******************
Device Management
*******************
The API provides classes to manage devices connected to the system:

    - :class:`DaqDevice`
    - :class:`DaqDeviceInfo`
    - :class:`DaqDeviceConfig`
    - :class:`DevMemInfo`

DaqDevice class
===============
Provides access to available MCC Daq devices for operation, configuration, and retrieving information.

Methods
-------
.. autoclass:: DaqDevice
    :members:

    ===================================  =================================================================
    **Method**                           **Description**
    -----------------------------------  -----------------------------------------------------------------
    :func:`~DaqDevice.get_descriptor`    Returns the DaqDeviceDescriptor for an existing
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.connect`           Establishes a connection to a physical DAQ device referenced by
                                         the :class:`DaqDevice` object.
    :func:`~DaqDevice.is_connected`      Gets the  connection status of a DAQ device referenced
                                         by the :class:`DaqDevice` object.
    :func:`~DaqDevice.disconnect`        Disconnects from the DAQ device referenced
                                         by the :class:`DaqDevice` object.
    :func:`~DaqDevice.flash_led`         Flashes the LED on the DAQ device for the device
                                         referenced by the :class:`DaqDevice` object.
    :func:`~DaqDevice.get_info`          Gets the DAQ device information object used to retrieve
                                         information about the DAQ device for the device
                                         referenced by the :class:`DaqDevice` object.
    :func:`~DaqDevice.get_config`        Gets the DAQ device configuration object for the device
                                         referenced by the :class:`DaqDevice` object.
    :func:`~DaqDevice.get_ai_device`     Gets the analog input subsystem object used to access the
                                         AI subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.get_ao_device`     Gets the analog output subsystem object used to access the
                                         AO subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.get_dio_device`    Gets the digital input/output subsystem object used to access
                                         the DIO subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.get_ctr_device`    Gets the counter subsystem object used to access the
                                         counter subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.get_tmr_device`    Gets the counter subsystem object used to access the
                                         timer subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.get_daqi_device`   Gets the DAQ input subsystem object used to access the
                                         DAQ input subsystem for the device referenced by the
                                         :class:`DaiDevice` object.
    :func:`~DaqDevice.get_daqo_device`   Gets the DAQ output subsystem object used to access the
                                         DAQ output subsystem for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.enable_event`      Binds one or more event conditions to a callback function
                                         for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.disable_event`     Disables one or more event conditions and unbinds the associated
                                         callback function for the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.mem_read`          Reads a value from a specified region in memory on the device
                                         referenced by the :class:`DaqDevice` object.
    :func:`~DaqDevice.mem_write`         Writes a block of data to the specified address in the reserved
                                         memory area on the device referenced by the
                                         :class:`DaqDevice` object.
    :func:`~DaqDevice.release`           Removes the device referenced by the :class:`DaqDevice` object
                                         from the Universal Library, and releases
                                         all resources associated with that device.
    :func:`~DaqDevice.reset`             Resets the DAQ device. This causes the DAQ
                                         device to disconnect from the host.
                                         Invoke :func:`DaqDevice.connect` to
                                         re-establish the connection to the device.
    ===================================  =================================================================

DaqDeviceInfo class
======================
Provides information about the capabilities of the DAQ device.

Methods
-------
.. autoclass:: DaqDeviceInfo()
    :members:

    ========================================  ==================================================
    **Method**                                  **Description**
    ----------------------------------------  --------------------------------------------------
    :func:`~DaqDeviceInfo.get_product_id`       Gets the product type referenced by the
                                                :class:`DaqDevice` object.
    :func:`~DaqDeviceInfo.get_event_types`      Gets a list of :class:`DaqEventType` values
                                                containing the types supported by the device
                                                referenced by the :class:`DaqDevice` object.
    :func:`~DaqDeviceInfo.get_mem_info`         Gets the DAQ device memory information object
                                                used to retrieve information about the reserved
                                                memory regions on the DAQ device
                                                referenced by the :class:`DaqDevice` object.
    ========================================  ==================================================

DaqDeviceConfig class
======================
Provides information about the configuration of the DAQ device.

Methods
-------
.. autoclass:: DaqDeviceConfig()
    :members:

    ===================================================    =============================================
    **Method**                                              **Description**
    ---------------------------------------------------    ---------------------------------------------
    :func:`~DaqDeviceConfig.get_version`                    Gets the version of the
                                                            firmware specified on
                                                            the device referenced by
                                                            the :class:`DaqDevice`
                                                            object, specified by
                                                            :class:`DevVersionType`,
                                                            and returns it as a
                                                            string.
    :func:`~DaqDeviceConfig.has_exp`                        Determines whether the
                                                            device referenced by the
                                                            :class:`DaqDevice`
                                                            object has an
                                                            expansion board attached.
    :func:`~DaqDeviceConfig.set_connection_code`            Configures the connection
                                                            code for the device
                                                            referenced by the
                                                            :class:`DaqDevice` object.
    :func:`~DaqDeviceConfig.get_connection_code`            Gets the connection
                                                            code for the device
                                                            referenced by the
                                                            :class:`DaqDevice` object.
    :func:`~DaqDeviceConfig.get_ip_address`                 Gets the IP address
                                                            of the device referenced
                                                            by the :class:`DaqDevice`
                                                            object.
    :func:`~DaqDeviceConfig.get_network_interface_name`     Gets the network
                                                            interface name of the
                                                            device referenced by the
                                                            :class:`DaqDevice` object.
    ===================================================    =============================================

DevMemInfo class
======================
Constructor for the :class:`DaqDeviceInfo` class.

Methods
-------
.. autoclass:: DevMemInfo()
    :members:

    =========================================   ==================================================
    **Method**                                  **Description**
    -----------------------------------------   --------------------------------------------------
    :func:`~DevMemInfo.get_mem_regions`         Gets a list of memory regions on the device
                                                referenced by the :class:`DaqDevice` object.
    :func:`~DevMemInfo.get_mem_descriptor`      Gets the memory descriptor object for the
                                                specified region of memory on the device
                                                referenced by the :class:`DaqDevice` object.
    =========================================   ==================================================

***********************************************************
Analog Input Subsystem
***********************************************************
Provides classes to manage the AI subsystem on a device:

    - :class:`AiDevice`
    - :class:`AiInfo`
    - :class:`AiConfig`

AiDevice class
======================
Analog input subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: AiDevice()
    :members:

    =================================   ========================================================
    **Method**                          **Description**
    ---------------------------------   --------------------------------------------------------
    :func:`~AiDevice.get_info`          Gets the analog input information object for the device
                                        referenced by the :class:`AiDevice` object.
    :func:`~AiDevice.get_config`        Gets the analog input configuration object for the
                                        device referenced by the :class:`AiDevice` object.
    :func:`~AiDevice.a_in`              Returns the value read from an A/D channel on the device
                                        referenced by the :class:`AiDevice` object.
    :func:`~AiDevice.a_in_scan`         Scans a range of A/D channels on the device
                                        referenced by the :class:`AiDevice` object, and
                                        stores the samples.
    :func:`~AiDevice.a_in_load_queue`   Loads the A/D queue of the device referenced by the
                                        :class:`AiDevice` object.
    :func:`~AiDevice.set_trigger`       Configures the trigger parameters for the device
                                        referenced by the :class:`AiDevice` object that
                                        will be used when :func:`a_in_scan` is called with
                                        :class:`~ScanOption.RETRIGGER`
                                        or :class:`~ScanOption.EXTTRIGGER`.
    :func:`~AiDevice.get_scan_status`   Gets the status, count, and index of an
                                        A/D scan operation on the device referenced by the
                                        :class:`AiDevice` object.
    :func:`~AiDevice.scan_stop`         Stops the analog input scan operation currently running
                                        on the device referenced by the :class:`AiDevice` object.
    :func:`~AiDevice.scan_wait`         Waits until the scan operation completes on the device
                                        referenced by the :class:`AiDevice` object, or
                                        the specified timeout elapses.
    :func:`~AiDevice.t_in`              Returns a temperature value read from an A/D channel on
                                        the device referenced by the :class:`AiDevice` object.
    :func:`~AiDevice.t_in_list`         Returns a list of temperature values read from an A/D
                                        channel on the device referenced by the
                                        :class:`AiDevice` object.
    =================================   ========================================================

AiInfo class
===============
Provides information about the capabilities of the analog input subsystem.

Methods
-------
.. autoclass:: AiInfo()
    :members:

    ==========================================   =================================================================
    **Method**                                   **Description**
    ------------------------------------------   -----------------------------------------------------------------
    :func:`~AiInfo.get_num_chans`                Gets the total number of A/D channels on the device referenced
                                                 by the :class:`AiInfo` object.
    :func:`~AiInfo.get_num_chans_by_mode`        Gets the number of A/D channels on the device referenced
                                                 by the :class:`AiInfo` object for the specified input mode.
    :func:`~AiInfo.get_num_chans_by_type`        Gets the number of A/D channels on the device referenced
                                                 by the :class:`AiInfo` object for the specified
                                                 :class:`AiChanType`.
    :func:`~AiInfo.get_resolution`               Gets the A/D resolution for the device referenced
                                                 by the :class:`AiInfo` object in number of bits.
    :func:`~AiInfo.get_min_scan_rate`            Gets the minimum scan rate for the device referenced
                                                 by the :class:`AiInfo` object in samples per second.
    :func:`~AiInfo.get_max_scan_rate`            Gets the maximum scan rate for the device referenced
                                                 by the :class:`AiInfo` object in samples per second.
    :func:`~AiInfo.get_max_throughput`           Gets the maximum throughput for the device referenced
                                                 by the :class:`AiInfo` object in samples per second.
    :func:`~AiInfo.get_max_burst_rate`           Gets the maximum burst rate for the device referenced
                                                 by the :class:`AiInfo` object in samples per second.
    :func:`~AiInfo.get_max_burst_throughput`     Gets the maximum burst throughput
                                                 for the device referenced by the :class:`AiInfo` object
                                                 in samples per second when using the
                                                 :class:`ScanOption.BURSTIO`.
    :func:`~AiInfo.get_fifo_size`                Gets the FIFO size in bytes for the device referenced
                                                 by the :class:`AiInfo` object.
    :func:`~AiInfo.get_scan_options`             Gets a list of :class:`ScanOption` attributes (suitable
                                                 for bit-wise operations) specifying scan options supported
                                                 by the device referenced by the :class:`AiInfo` object.
    :func:`~AiInfo.has_pacer`                    Determines whether the device referenced by the
                                                 :class:`AiInfo` object supports paced analog input operations.
    :func:`~AiInfo.get_chan_types`               Gets a list of :class:`AiChanType` attributes
                                                 (suitable for bit-wise operations) indicating supported
                                                 channel types for the device referenced by the
                                                 :class:`AiInfo` object.
    :func:`~AiInfo.get_ranges`                   Gets a list of supported ranges for the device referenced
                                                 by the :class:`AiInfo` object.
    :func:`~AiInfo.get_trigger_types`            Gets a list of supported trigger types for the device referenced
                                                 by the :class:`AiInfo` object.
    :func:`~AiInfo.get_max_queue_length`         Gets the maximum length of the queue list for the device
                                                 referenced by the :class:`AiInfo` object.
    :func:`~AiInfo.get_queue_types`              Gets a list of supported queue types for the device
                                                 referenced by the :class:`AiInfo` object.
    :func:`~AiInfo.get_chan_queue_limitations`   Gets a list of queue limitations for the device referenced
                                                 by the :class:`AiInfo` object.
    :func:`~AiInfo.supports_iepe`                Determines whether the device referenced by the :class:`AiInfo`
                                                 object supports IEPE excitation for analog input operations.
    ==========================================   =================================================================

AiConfig class
===============
Provides classes to configure analog input options.

Methods
-------
.. autoclass:: AiConfig()
    :members:

    ================================================== ===========================================================
    **Method**                                         **Description**
    -------------------------------------------------- -----------------------------------------------------------
    :func:`~AiConfig.set_chan_type`                    Configures the channel type for the specified A/D channel.
    :func:`~AiConfig.get_chan_type`                    Gets the channel type for for the specified A/D channel.
    :func:`~AiConfig.set_chan_tc_type`                 Configures the thermocouple type for the specified A/D
                                                       channel.
    :func:`~AiConfig.get_chan_tc_type`                 Gets the thermocouple type for the specified A/D channel.
    :func:`~AiConfig.set_chan_sensor_connection_type`  Configures the sensor connection type for the
                                                       specified A/D channel.
    :func:`~AiConfig.get_chan_sensor_connection_type`  Gets the sensor connection type for the specified A/D
                                                       channel.
    :func:`~AiConfig.get_chan_sensor_coefficients`     Gets the sensor coefficients being used for the
                                                       specified A/D channel.
    :func:`~AiConfig.set_chan_iepe_mode`               Configures the IEPE mode for the specified A/D channel.
    :func:`~AiConfig.get_chan_iepe_mode`               Gets the IEPE mode for the specified A/D channel.
    :func:`~AiConfig.set_chan_coupling_mode`           Configures the coupling mode for the specified A/D channel.
    :func:`~AiConfig.get_chan_coupling_mode`           Gets the coupling mode for the specified A/D channel.
    :func:`~AiConfig.set_chan_sensor_sensitivity`      Configures the sensor sensitivity for the specified A/D
                                                       channel in Volts/unit.
    :func:`~AiConfig.get_chan_sensor_sensitivity`      Gets the sensor sensitivity for the specified A/D channel
                                                       in Volts/unit.
    :func:`~AiConfig.set_chan_slope`                   Configures the slope multiplier for the specified
                                                       A/D channel.
    :func:`~AiConfig.get_chan_slope`                   Gets the slope multiplier of the specified A/D channel.
    :func:`~AiConfig.set_chan_offset`                  Configures the offset value for the specified
                                                       A/D channel.
    :func:`~AiConfig.get_chan_offset`                  Gets the offset value of the specified A/D channel.
    :func:`~AiConfig.get_cal_date`                     Gets the calibration date for the DAQ device.
    :func:`~AiConfig.set_chan_otd_mode`                Configures the open thermocouple detection mode for the
                                                       specified A/D channel.
    :func:`~AiConfig.get_chan_otd_mode`                Gets the open thermocouple detection mode for the
                                                       specified A/D channel.
    :func:`~AiConfig.set_temp_unit`                    Configures the temperature unit for the specified A/D
                                                       channel.
    :func:`~AiConfig.get_temp_unit`                    Gets the temperature unit for the specified A/D channel.
    :func:`~AiConfig.set_chan_data_rate`               Configures the data rate for the specified A/D channel.
    :func:`~AiConfig.get_chan_data_rate`               Gets the data rate for the specified A/D channel.
    :func:`~AiConfig.set_otd_mode`                     Configures the open thermocouple detection mode for the A/D.
    :func:`~AiConfig.get_otd_mode`                     Gets the open thermocouple detection mode for the A/D.
    :func:`~AiConfig.set_calibration_table_type`       Configures the calibration table type for the A/D.
    :func:`~AiConfig.get_calibration_table_type`       Gets the calibration table type for the A/D.
    :func:`~AiConfig.set_reject_freq_type`             Configures the rejection frequency type for the A/D.
    :func:`~AiConfig.get_reject_freq_type`             Gets the rejection frequency type for the A/D.
    :func:`~AiConfig.get_expansion_cal_date`           Gets the calibration date of the expansion board connected
                                                       to the DAQ device.
    ================================================== ===========================================================

********************************************************************
Analog Output Subsystem
********************************************************************
Provides classes to manage the analog output subsystem on a device:

    - :class:`AoDevice`
    - :class:`AoInfo`
    - :class:`AoConfig`

AoDevice class
======================
Analog output subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: AoDevice()
    :members:

    =================================  =======================================================
    **Method**                          **Description**
    ---------------------------------  -------------------------------------------------------
    :func:`~AoDevice.get_info`          Gets the analog output information object for the
                                        device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.get_config`        Gets the analog output configuration object for the
                                        device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.a_out`             Writes the data value to a D/A output channel on the
                                        device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.a_out_scan`        Outputs values to a range of D/A channels on the
                                        device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.get_scan_status`   Gets the current status, count, and index for the
                                        device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.scan_stop`         Stops the D/A scan operation currently running on
                                        the device referenced by the :class:`AoDevice` object.
    :func:`~AoDevice.scan_wait`         Waits until the scan operation completes on
                                        the device referenced by the :class:`AoDevice` object,
                                        or the specified timeout elapses.
    :func:`~AoDevice.set_trigger`       Configures the trigger parameters for the device
                                        referenced by the :class:`AoDevice` object
                                        that will be used when :func:`a_out_scan` is called
                                        that will be used when :func:`a_out_scan` is called
                                        with :class:`~ScanOption.RETRIGGER` or
                                        :class:`~ScanOption.EXTTRIGGER`.
    :func:`~AoDevice.a_out_list`        Writes a list of values to the specified range of
                                        D/A channels for the device referenced by the
                                        :class:`AoDevice` object.
    =================================  =======================================================

AoInfo class
===============
Provides information about the capabilities of the analog output subsystem.

Methods
-------
.. autoclass:: AoInfo()
    :members:

    ===================================  ===================================================================
    **Method**                           **Description**
    -----------------------------------  -------------------------------------------------------------------
    :func:`~AoInfo.get_num_chans`        Gets the total number of D/A channels for the device
                                         referenced by the :class:`AoInfo` object.
    :func:`~AoInfo.get_resolution`       Gets the D/A resolution in number of bits for the device
                                         referenced by the :class:`AoInfo` object.
    :func:`~AoInfo.get_min_scan_rate`    Gets the minimum scan rate for the device
                                         referenced by the :class:`AoInfo` object in samples per second.
    :func:`~AoInfo.get_max_scan_rate`    Gets the maximum scan rate for the device
                                         referenced by the :class:`AoInfo` object in samples per second.
    :func:`~AoInfo.get_max_throughput`   Gets the maximum throughput for the device
                                         referenced by the :class:`AoInfo` object in samples per second.
    :func:`~AoInfo.get_fifo_size`        Gets the FIFO size in bytes for the device
                                         referenced by the :class:`AoInfo` object.
    :func:`~AoInfo.get_scan_options`     Gets a list of :class:`ScanOption` attributes (suitable
                                         for bit-wise operations) specifying scan options supported
                                         by the device referenced by the :class:`AoInfo` object.
    :func:`~AoInfo.has_pacer`            Determines whether the device referenced by the :class:`AoInfo`
                                         object supports paced analog output operations.
    :func:`~AoInfo.get_ranges`           Gets a list of supported ranges for the device
                                         referenced by the :class:`AoInfo` object.
    :func:`~AoInfo.get_trigger_types`    Gets a list of supported trigger types for the device referenced
                                         by the :class:`AoInfo` object.
    ===================================  ===================================================================

AoConfig class
===============
Provides classes to configure analog output options.

Methods
-------
.. autoclass:: AoConfig()
    :members:

    =====================================  ======================================================
    **Method**                             **Description**
    -------------------------------------  ------------------------------------------------------
    :func:`~AoConfig.set_sync_mode`        Configures the synchronization mode for the analog
                                           output subsystem.
    :func:`~AoConfig.get_sync_mode`        Gets the synchronization mode for the analog
                                           output subsystem.
    :func:`~AoConfig.set_chan_sense_mode`  Configures the sense mode for the specified DAC channel.
    :func:`~AoConfig.get_chan_sense_mode`  Gets the sense mode for the specified DAC channel.
    =====================================  ======================================================

***********************************************************
Digital I/O Subsystem
***********************************************************
Provides classes to manage the Digital I/O subsystem on a device:

    - :class:`DioDevice`
    - :class:`DioInfo`
    - :class:`DioConfig`

DioDevice class
======================
Digital I/O subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: DioDevice()
    :members:

    ==========================================  ===========================================================
    **Method**                                  **Description**
    ------------------------------------------  -----------------------------------------------------------
    :func:`~DioDevice.get_info`                 Gets the digital I/O information object for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.get_config`               Gets the digital I/O configuration object for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_config_port`            Configures a digital port as input or output for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_config_bit`             Configures a digital bit as input or output for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_in`                     Returns the value read from a digital port for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_out`                    Writes the value to the digital port type for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_bit_in`                 Returns the value read from a digital bit for the device
                                                referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_bit_out`                Writes the specified value to a digital output bit for
                                                the device referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_in_scan`                Scans a range of digital ports at the specified rate on the
                                                device referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_out_scan`               Scans data to a range of digital output ports at the
                                                specified rate on the device referenced by the
                                                :class:`DioDevice` object.
    :func:`~DioDevice.d_in_set_trigger`         Configures the trigger parameters for the device
                                                referenced by the :class:`DioDevice` object that will be
                                                used when :func:`d_in_scan` is called with
                                                :class:`~ScanOption.RETRIGGER` or
                                                :class:`~ScanOption.EXTTRIGGER`.
    :func:`~DioDevice.d_out_set_trigger`        Configures the trigger parameters for the device
                                                referenced by the :class:`DioDevice` object that will be
                                                used when :func:`d_out_scan` is called with
                                                :class:`~ScanOption.RETRIGGER` or
                                                :class:`~ScanOption.EXTTRIGGER`.
    :func:`~DioDevice.d_in_get_scan_status`     Gets the status, count, and index of the digital input
                                                scan operation on the device referenced by the.
                                                :class:`DioDevice` object.
    :func:`~DioDevice.d_out_get_scan_status`    Gets the status, count, and index of the digital output
                                                scan operation on the device referenced by the.
                                                :class:`DioDevice` object.
    :func:`~DioDevice.d_in_scan_stop`           Stops the digital input scan operation currently running.
                                                on the device referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_out_scan_stop`          Stops the digital output scan operation currently running
                                                on the device referenced by the :class:`DioDevice` object.
    :func:`~DioDevice.d_in_scan_wait`           Waits until the scan operation completes on the
                                                device referenced by the :class:`DioDevice` object, or
                                                the time specified by the timeout argument elapses.
    :func:`~DioDevice.d_out_scan_wait`          Waits until the scan operation completes on the
                                                device referenced by the :class:`DioDevice` object, or
                                                the time specified by the timeout argument elapses.
    :func:`~DioDevice.d_in_list`                Returns a list of values read from the specified range of
                                                digital ports for the device referenced by the
                                                :class:`DioDevice` object.
    :func:`~DioDevice.d_out_list`               Writes a list of values to the specified range of
                                                digital output ports for the device referenced by the
                                                :class:`DioDevice` object.
    :func:`~DioDevice.d_clear_alarm`            Clears the alarms for the bits
                                                specified by the bit mask within the
                                                specified :class:`DigitalPortType`
                                                of the device referenced by the
                                                :class:`DioDevice` object.
    ==========================================  ===========================================================

DioInfo class
===============
Provides information about the capabilities of the digital I/O subsystem.

Methods
-------
.. autoclass:: DioInfo()
    :members:

    ====================================  ===========================================================
    **Method**                            **Description**
    ------------------------------------  -----------------------------------------------------------
    :func:`~DioInfo.get_num_ports`        Gets the total number of digital I/O ports on the device
                                          referenced by the :class:`DioInfo` object.
    :func:`~DioInfo.get_port_types`       Gets a list of supported port types on the device
                                          referenced by the :class:`DioInfo` object.
    :func:`~DioInfo.get_port_info`        Gets the port information object for the specified port
                                          on the device referenced by the :class:`DioInfo` object.
    :func:`~DioInfo.has_pacer`            Determines whether the device referenced by the
                                          :class:`DioInfo` supports paced digital operations
                                          (scanning) for the specified digital direction.
    :func:`~DioInfo.get_min_scan_rate`    Gets the minimum scan rate for the device
                                          referenced by the :class:`DioInfo` object
                                          in samples per second for the specified digital direction.
    :func:`~DioInfo.get_max_scan_rate`    Gets the maximum scan rate for the device
                                          referenced by the :class:`DioInfo` object
                                          in samples per second.
                                          for the specified digital direction.
    :func:`~DioInfo.get_max_throughput`   Gets the maximum throughput for the device
                                          referenced by the :class:`DioInfo` object
                                          in samples per second for the
                                          specified digital direction.
    :func:`~DioInfo.get_fifo_size`        Gets the FIFO size in bytes for the device
                                          referenced by the :class:`DioInfo` object for the
                                          specified digital direction.
    :func:`~DioInfo.get_scan_options`     Gets a list of :class:`ScanOption` attributes (suitable for
                                          bit-wise operations) specifying scan options supported by
                                          the device referenced by the :class:`DioInfo` object
                                          for the specified digital direction.
    :func:`~DioInfo.get_trigger_types`    Gets a list of supported trigger types for the device
                                          referenced by the :class:`DioInfo` object for the
                                          specified digital direction.
    ====================================  ===========================================================

DioConfig class
===============
Provides classes to configure digital options.

Methods
-------
.. autoclass:: DioConfig()
    :members:

    =============================================== ==============================================================
    **Method**                                      **Description**
    ----------------------------------------------- --------------------------------------------------------------
    :func:`~DioConfig.get_port_direction`           Gets the configured direction for each bit in the specified
                                                    port for the device referenced by the :class:`DioInfo` object.
    :func:`~DioConfig.set_port_initial_output_val`  Sets the initial output value of the specified digital port
                                                    type. This allows for a known state when switching the port
                                                    direction from input to output.
    :func:`~DioConfig.get_port_iso_filter_mask`     Gets the ISO filter mask for the specified port type.
    :func:`~DioConfig.set_port_iso_filter_mask`     Sets the ISO filter mask for the specified port type.
    :func:`~DioConfig.get_port_output_logic`        Gets the output logic for the specified port type.
    =============================================== ==============================================================

***********************************************************
Counter Subsystem
***********************************************************
Provides classes to manage the counter subsystem on a device:

    - :class:`CtrDevice`
    - :class:`CtrInfo`
    - :class:`CtrConfig`

CtrDevice class
======================
Counter subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: CtrDevice()
    :members:

    ==================================  ===========================================================
    **Method**                          **Description**
    ----------------------------------  -----------------------------------------------------------
    :func:`~CtrDevice.get_info`         Gets the counter information object for the device
                                        referenced by the :class:`CtrDevice` object.
    :func:`~CtrDevice.get_config`       Gets the counter configuration object for the device
                                        referenced by the :class:`CtrDevice` object.
    :func:`~CtrDevice.c_in`             Reads the value of a count register for the device
                                        referenced by the :class:`CtrDevice` object.
    :func:`~CtrDevice.c_load`           Loads a value into the specified counter register for the
                                        device referenced by the :class:`CtrDevice` object.
    :func:`~CtrDevice.c_clear`          Clears the value of a count register for the device
                                        referenced by the :class:`CtrDevice` object (sets it to 0).
    :func:`~CtrDevice.c_read`           Reads the value of the specified counter register for the
                                        device referenced by the :class:`CtrDevice` object.
    :func:`~CtrDevice.c_in_scan`        Scans a range of counters at the specified rate on the
                                        device referenced by the :class:`CtrDevice` object, and
                                        stores samples.
    :func:`~CtrDevice.c_config_scan`    Configures the specified counter on the
                                        device referenced by the :class:`CtrDevice` object;
                                        for counters with programmable types.
    :func:`~CtrDevice.set_trigger`      Configures the trigger parameters for the
                                        device referenced by the :class:`CtrDevice` object
                                        that will be used when :func:`c_in_scan` is called with
                                        :class:`~ScanOption.RETRIGGER` or
                                        :class:`~ScanOption.EXTTRIGGER`.
    :func:`~CtrDevice.get_scan_status`  Gets the status, count, and index of the for the
                                        counter input scan operation on the device referenced by
                                        the :class:`CtrDevice` object.
    :func:`~CtrDevice.scan_stop`        Stops the counter input scan operation on the device
                                        referenced by the :class:`CtrDevice`.
    :func:`~CtrDevice.scan_wait`        Waits until the scan operation completes on the device
                                        referenced by the :class:`CtrDevice` object, or
                                        the specified timeout elapses.
    ==================================  ===========================================================

CtrInfo class
===============
Provides information about the capabilities of the counter subsystem.

Methods
-------
.. autoclass:: CtrInfo()
    :members:

    ======================================  =======================================================
    **Method**                              **Description**
    --------------------------------------  -------------------------------------------------------
    :func:`~CtrInfo.get_num_ctrs`           Gets the total number of counter channels for the
                                            device referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_measurement_types`  Gets a list of supported measurement types
                                            for a specified counter on the
                                            device referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_measurement_modes`  Gets a list of supported measurement modes
                                            compatible with the specified measurement type on the
                                            device referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_register_types`     Gets a list of supported register types for the
                                            device referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_resolution`         Gets the resolution in number of bits for the
                                            device referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_min_scan_rate`      Gets the minimum scan rate for the device referenced
                                            by the :class:`CtrInfo` object in samples per second.
    :func:`~CtrInfo.get_max_scan_rate`      Gets the maximum scan rate for the device referenced
                                            by the :class:`CtrInfo` object in samples per second.
    :func:`~CtrInfo.get_max_throughput`     Gets the maximum throughput for the device referenced
                                            by the :class:`CtrInfo` object in samples per second.
    :func:`~CtrInfo.get_fifo_size`          Gets the FIFO size in bytes for the device referenced
                                            by the :class:`CtrInfo` object.
    :func:`~CtrInfo.get_scan_options`       Gets a list of scan options supported by the device
                                            referenced by the :class:`CtrInfo` object.
    :func:`~CtrInfo.has_pacer`              Determines whether the device referenced
                                            by the :class:`CtrInfo` object supports paced
                                            counter input operations.
    :func:`~CtrInfo.get_trigger_types`      Gets a list of trigger types supported by the device
                                            referenced by the :class:`CtrInfo` object.
    ======================================  =======================================================

CtrConfig class
===============
Provides classes to configure counter options.

Methods
-------
.. autoclass:: CtrConfig()
    :members:

    =============================================== ==============================================================
    **Method**                                      **Description**
    ----------------------------------------------- --------------------------------------------------------------
    :func:`~CtrConfig.set_register_val`             Configures the register value for the specified counter.
    :func:`~CtrConfig.get_register_val`             Gets the register value for the specified counter.
    =============================================== ==============================================================

***********************************************************
Timer Subsystem
***********************************************************
Provides classes to manage the timer subsystem on a device:

    - :class:`TmrDevice`
    - :class:`TmrInfo`

TmrDevice class
======================
Timer subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: TmrDevice()
    :members:

    =========================================   =========================================================
    **Method**                                  **Description**
    -----------------------------------------   ---------------------------------------------------------
    :func:`~TmrDevice.get_info`                 Gets the timer information object for the device
                                                referenced by the :class:`TmrDevice` object.
    :func:`~TmrDevice.pulse_out_start`          Starts the specified timer on the device
                                                referenced by the :class:`TmrDevice` object to generate
                                                digital pulses at a specified frequency and duty cycle.
    :func:`~TmrDevice.pulse_out_stop`           Stops the specified timer output on the device referenced
                                                by the :class:`TmrDevice` object.
    :func:`~TmrDevice.get_pulse_out_status`     Gets the status of the timer output operation for the
                                                specified timer on the on the device referenced by the
                                                :class:`TmrDevice` object.
    :func:`~TmrDevice.set_trigger`              Configures the trigger parameters that will be used when
                                                :func:`pulse_out_start` is called with
                                                :class:`~PulseOutOption.EXTTRIGGER` or
                                                :class:`~PulseOutOption.RETRIGGER`.
    =========================================   =========================================================

TmrInfo class
===============
Provides information about the capabilities of the timer subsystem.

Methods
-------
.. autoclass:: TmrInfo()
    :members:

    ======================================   ====================================================
    **Method**                               **Description**
    --------------------------------------   ----------------------------------------------------
    :func:`~TmrInfo.get_num_tmrs`            Gets the total number of timer channels on the
                                             device referenced by the :class:`TmrInfo` object.
    :func:`~TmrInfo.get_timer_type`          Get the timer type for the specified timer on the
                                             device referenced by the :class:`TmrInfo` object.
    :func:`~TmrInfo.get_min_frequency`       Gets the minimum output frequency on the
                                             device referenced by the :class:`TmrInfo` object.
    :func:`~TmrInfo.get_max_frequency`       Gets the maximum output frequency for the
                                             specified timer on the device referenced by the
                                             :class:`TmrInfo` object.
    ======================================   ====================================================

***********************************************************
Daq Input Subsystem
***********************************************************
Provides classes to manage the DAQ input subsystem on a device:

    - :class:`DaqiDevice`
    - :class:`DaqiInfo`


DaqiDevice class
======================
Daq Input subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: DaqiDevice()
    :members:

    ===================================  ================================================================
    **Method**                            **Description**
    -----------------------------------  ----------------------------------------------------------------
    :func:`~DaqiDevice.get_info`          Gets daq input information object for the device referenced by
                                          the :class:`DaqiDevice` object.
    :func:`~DaqiDevice.set_trigger`       Configures the trigger parameters for the device
                                          referenced by the :class:`DaqiDevice` object that
                                          will be used when :func:`daq_in_scan` is called with
                                          :class:`~ScanOption.RETRIGGER`
                                          or :class:`~ScanOption.EXTTRIGGER`.
    :func:`~DaqiDevice.daq_in_scan`       Allows scanning of multiple input subsystems,
                                          such as analog, digital, counter, on the device referenced by
                                          the :class:`DaqiDevice` object and stores the
                                          samples in an array.
    :func:`~DaqiDevice.get_scan_status`   Gets the status, count, and index of  the synchronous input
                                          scan operation on the device referenced by the
                                          :class:`DaqiDevice` object.
    :func:`~DaqiDevice.scan_stop`         Stops the synchronous output scan operation
                                          on the device referenced by the
                                          :class:`DaqiDevice` object currently running.
    :func:`~DaqiDevice.scan_wait`         Waits until the scan operation completes on the device
                                          referenced by the :class:`DaqiDevice` object, or the specified
                                          timeout elapses.
    ===================================  ================================================================

DaqiInfo class
===============
Provides information about the capabilities of the DAQ input subsystem.

Methods
-------
.. autoclass:: DaqiInfo()
    :members:

    ====================================   =============================================================
    **Method**                              **Description**
    ------------------------------------   -------------------------------------------------------------
    :func:`~DaqiInfo.get_channel_types`     Gets a list of supported :class:`DaqInChanType` attributes
                                            for the device referenced by the :class:`DaqiInfo` object.
    :func:`~DaqiInfo.get_min_scan_rate`     Gets the minimum scan rate for the device referenced
                                            by the :class:`DaqiInfo` object in samples per second.
    :func:`~DaqiInfo.get_max_scan_rate`     Gets the maximum scan rate for the device referenced
                                            by the :class:`DaqiInfo` object in samples per second.
    :func:`~DaqiInfo.get_max_throughput`    Gets the maximum throughput for the device referenced
                                            by the :class:`DaqiInfo` object in samples per second.
    :func:`~DaqiInfo.get_fifo_size`         Gets the FIFO size in bytes for the device referenced
                                            by the :class:`DaqiInfo` object.
    :func:`~DaqiInfo.get_scan_options`      Gets a list of scan options supported by the device
                                            referenced by the :class:`DaqiInfo` object.
    :func:`~DaqiInfo.get_trigger_types`     Gets a list of trigger types supported by the device
                                            referenced by the :class:`DaqiInfo` object.
    ====================================   =============================================================

***********************************************************
Daq Output Subsystem
***********************************************************
Provides classes to manage the DAQ output subsystem on a device:

    - :class:`DaqoDevice`
    - :class:`DaqoInfo`

DaqoDevice class
======================
DAQ output subsystem of the UL DAQ Device.

Methods
-------
.. autoclass:: DaqoDevice()
    :members:

    ===================================  ===============================================================
    **Method**                            **Description**
    -----------------------------------  ---------------------------------------------------------------
    :func:`~DaqoDevice.get_info`          Gets the DAQ output information object for the device
                                          referenced by the :class:`DaqoDevice` object.
    :func:`~DaqoDevice.set_trigger`       Configures the trigger parameters for the device
                                          referenced by the :class:`DaqoDevice` object
                                          that will be used when :func:`daq_out_scan` is called
                                          with :class:`~ScanOption.RETRIGGER` or
                                          :class:`~ScanOption.EXTTRIGGER`.
    :func:`~DaqoDevice.daq_out_scan`      Outputs values synchronously to multiple output subsystems,
                                          such as analog and digital subsystems, on the device
                                          referenced by the :class:`DaqoDevice` object.
    :func:`~DaqoDevice.get_scan_status`   Gets the status, count, and index of the synchronous output
                                          scan operation on the device referenced by the
                                          :class:`DaqoDevice` object.
    :func:`~DaqoDevice.scan_stop`         Stops the synchronous output scan operation
                                          on the device referenced by the
                                          :class:`DaqoDevice` object currently running.
    ===================================  ===============================================================

DaqoInfo class
===============
Provides information about the capabilities of the DAQ output subsystem.

Methods
-------
.. autoclass:: DaqoInfo()
    :members:

    ====================================   ==============================================================
    **Method**                              **Description**
    ------------------------------------   --------------------------------------------------------------
    :func:`~DaqoInfo.get_channel_types`     Gets a list of supported :class:`DaqOutChanType` attributes
                                            for the device referenced by the :class:`DaqoInfo` object.
    :func:`~DaqoInfo.get_min_scan_rate`     Gets the minimum scan rate for the device referenced by the
                                            :class:`DaqoInfo` object in samples per second.
    :func:`~DaqoInfo.get_max_scan_rate`     Gets the maximum scan rate for the device referenced by the
                                            :class:`DaqoInfo` object in samples per second.
    :func:`~DaqoInfo.get_max_throughput`    Gets the maximum throughput for the device referenced by the
                                            :class:`DaqoInfo` object in samples per second.
    :func:`~DaqoInfo.get_fifo_size`         Gets FIFO for the DAQ size in bytes for the device referenced
                                            by the :class:`DaqoInfo` object .
    :func:`~DaqoInfo.get_scan_options`      Gets a list of scan options supported by the device
                                            referenced by the :class:`DaqoInfo` object.
    :func:`~DaqoInfo.get_trigger_types`     Gets a list of trigger types supported by the device
                                            referenced by the :class:`DaqoInfo` object.
    ====================================   ==============================================================

***************
Global Methods
***************

Buffer Management
==================
Provides methods to allocate buffers for data storage:

    =============================  =================================================================
    **Method**                      **Description**
    -----------------------------  -----------------------------------------------------------------
    :func:`create_float_buffer`     Creates a buffer for double precision floating point
                                    sample values.
    :func:`create_int_buffer`       Creates a buffer for 64-bit unsigned integer sample values.
    =============================  =================================================================

.. autofunction:: create_float_buffer
.. autofunction:: create_int_buffer

ULException class
==================
Exception for an error in the UL.

.. autoexception:: ULException
    :members:

******
Events
******

The Python API provides event handling capability for each :class:`DaqEventType` condition.
Events are enabled and disabled using the :func:`DaqDevice.enable_event` and
:func:`DaqDevice.disable_event` methods. Valid callback functions for events have a single
argument of type :class:`EventCallbackArgs`, which is a namedtuple containing the following three elements:

  **event_type**:
    The :class:`DaqEventType` condition that triggered the event.
  **event_data**:
    The total samples acquired for an :class:`~DaqEventType.ON_DATA_AVAILABLE` event,
    the :class:`ULError` code for an :class:`~DaqEventType.ON_INPUT_SCAN_ERROR` or an
    :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR` event, otherwise None.
  **user_data**:
    The object passed as the ``user_data`` parameter for the :func:`DaqDevice.enable_event` method.

Usage
=====
The following can be used as a prototype for an event callback function.

.. code-block:: python

  def event_callback_function(event_callback_args: EventCallbackArgs) -> None:
      event_type = event_callback_args.event_type
      event_data = event_callback_args.event_data
      user_data = event_callback_args.user_data

      # Insert user specific code here

      return

************
Constants
************

    - :class:`AiCalTableType`
    - :class:`AiChanQueueLimitation`
    - :class:`AiChanType`
    - :class:`AiInputMode`
    - :class:`AInFlag`
    - :class:`AiRejectFreqType`
    - :class:`AInScanFlag`
    - :class:`AiQueueType`
    - :class:`AOutFlag`
    - :class:`AOutListFlag`
    - :class:`AOutScanFlag`
    - :class:`AOutSenseMode`
    - :class:`AOutSyncMode`
    - :class:`CalibrationType`
    - :class:`CConfigScanFlag`
    - :class:`CInScanFlag`
    - :class:`CounterDebounceMode`
    - :class:`CounterDebounceTime`
    - :class:`CounterEdgeDetection`
    - :class:`CounterMeasurementMode`
    - :class:`CounterMeasurementType`
    - :class:`CounterRegisterType`
    - :class:`CounterTickSize`
    - :class:`CouplingMode`
    - :class:`DaqEventType`
    - :class:`DaqInChanType`
    - :class:`DaqInScanFlag`
    - :class:`DaqOutChanType`
    - :class:`DaqOutScanFlag`
    - :class:`DevVersionType`
    - :class:`DigitalDirection`
    - :class:`DigitalPortIoType`
    - :class:`DigitalPortType`
    - :class:`DInScanFlag`
    - :class:`DOutScanFlag`
    - :class:`IepeMode`
    - :class:`InterfaceType`
    - :class:`MemAccessType`
    - :class:`MemRegion`
    - :class:`OtdMode`
    - :class:`PulseOutOption`
    - :class:`Range`
    - :class:`ScanOption`
    - :class:`ScanStatus`
    - :class:`SensorConnectionType`
    - :class:`TempUnit`
    - :class:`TempScale`
    - :class:`TcType`
    - :class:`TimerType`
    - :class:`TInFlag`
    - :class:`TInListFlag`
    - :class:`TmrIdleState`
    - :class:`TmrStatus`
    - :class:`TriggerType`
    - :class:`ULError`
    - :class:`WaitType`

.. autoclass:: AiCalTableType
    :members:
.. autoclass:: AiChanQueueLimitation
    :members:
.. autoclass:: AiChanType
    :members:
.. autoclass:: AiInputMode
    :members:
.. autoclass:: AInFlag
    :members:
.. autoclass:: AiRejectFreqType
    :members:
.. autoclass:: AInScanFlag
    :members:
.. autoclass:: AiQueueType
    :members:
.. autoclass:: AOutFlag
    :members:
.. autoclass:: AOutListFlag
    :members:
.. autoclass:: AOutScanFlag
    :members:
.. autoclass:: AOutSenseMode
    :members:
.. autoclass:: AOutSyncMode
    :members:
.. autoclass:: CalibrationType
    :members:
.. autoclass:: CConfigScanFlag
    :members:
.. autoclass:: CInScanFlag
    :members:
.. autoclass:: CounterDebounceMode
    :members:
.. autoclass:: CounterDebounceTime
    :members:
.. autoclass:: CounterEdgeDetection
    :members:
.. autoclass:: CounterMeasurementMode
    :members:
.. autoclass:: CounterMeasurementType
    :members:
.. autoclass:: CounterRegisterType
    :members:
.. autoclass:: CouplingMode
    :members:
.. autoclass:: CounterTickSize
    :members:
.. autoclass:: DaqInChanType
    :members:
.. autoclass:: DaqInScanFlag
    :members:
.. autoclass:: DaqEventType
    :members:
.. autoclass:: DaqOutChanType
    :members:
.. autoclass:: DaqOutScanFlag
    :members:
.. autoclass:: DigitalDirection
    :members:
.. autoclass:: DigitalPortIoType
    :members:
.. autoclass:: DigitalPortType
    :members:
.. autoclass:: DInScanFlag
    :members:
.. autoclass:: DOutScanFlag
    :members:
.. autoclass:: DevVersionType
    :members:
.. autoclass:: IepeMode
    :members:
.. autoclass:: InterfaceType
    :members:
.. autoclass:: MemAccessType
    :members:
.. autoclass:: MemRegion
    :members:
.. autoclass:: OtdMode
    :members:
.. autoclass:: PulseOutOption
    :members:
.. autoclass:: Range
    :members:
.. autoclass:: ScanOption
    :members:
.. autoclass:: ScanStatus
    :members:
.. autoclass:: SensorConnectionType
    :members:
.. autoclass:: TcType
    :members:
.. autoclass:: TempUnit
    :members:
.. autoclass:: TempScale
    :members:
.. autoclass:: TimerType
    :members:
.. autoclass:: TInFlag
    :members:
.. autoclass:: TInListFlag
    :members:
.. autoclass:: TmrIdleState
    :members:
.. autoclass:: TmrStatus
    :members:
.. autoclass:: TriggerType
    :members:
.. autoclass:: ULError
    :members:
.. autoclass:: WaitType
    :members:

************
Types
************

    - :class:`DaqDeviceDescriptor`
    - :class:`MemDescriptor`
    - :class:`AiQueueElement`
    - :class:`DaqInChanDescriptor`
    - :class:`DaqOutChanDescriptor`
    - :class:`TransferStatus`
    - :class:`EventCallbackArgs`

.. autoclass:: DaqDeviceDescriptor
    :members:
.. autoclass:: MemDescriptor
    :members:
.. autoclass:: AiQueueElement
    :members:
.. autoclass:: DaqInChanDescriptor
    :members:
.. autoclass:: DaqOutChanDescriptor
    :members:
.. autoclass:: DioPortInfo
    :members:
.. autoclass:: TransferStatus
    :members:
.. autoclass:: EventCallbackArgs
    :members:
    :show-inheritance:
