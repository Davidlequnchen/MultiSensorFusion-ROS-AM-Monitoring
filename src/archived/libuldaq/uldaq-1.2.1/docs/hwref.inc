.. currentmodule:: uldaq

.. |br| raw:: html

       <br>

.. raw:: latex

       \newpage

.. _1808:

****************
USB-1808 Series
****************
The USB-1808 Series includes the following devices:

- USB-1808, USB-1808-OEM
- USB-1808X, USB-1808X-OEM

The USB-1808 Series supports the following UL for Linux capabilities. Unless
otherwise indicated, OEM versions support the same capabilities as the equivalent
standard versions.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.UNI10VOLTS`, :class:`~Range.UNI5VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      USB-1808: 0.0233 to 50,000 S/s |br| USB-1808X: 0.0233 to 200,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        0 to 7
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      USB-1808: 0.0233 to 125,000 S/s |br| USB-1808X: 0.0233 to 500,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      USB-1808: 0.0233 to 50,000 S/s (input), 0.0233 to 125,000 S/s (output) |br| USB-1808X: 0.0233 to 200,000 S/s (input), 0.0233 to 500,000 S/s (output)
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.d_in_scan`, :func:`~DioDevice.d_out_scan`, :func:`~DioDevice.d_in_get_scan_status`, :func:`~DioDevice.d_out_get_scan_status`, :func:`~DioDevice.d_in_scan_stop`, :func:`~DioDevice.d_out_scan_stop`, :func:`~DioDevice.d_in_scan_wait`, :func:`~DioDevice.d_out_scan_wait`, :func:`~DioDevice.d_in_set_trigger`, :func:`~DioDevice.d_out_set_trigger`, :func:`~DioDevice.get_config`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 3
Scan options:	               :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	                 USB-1808: 0.0233 to 50,000 S/s |br| USB-1808X: 0.0233 to 200,000 S/s
Scan flags:                  :class:`~CInScanFlag.DEFAULT`, :class:`~CInScanFlag.CTR32_BIT`, :class:`~CInScanFlag.NOCLEAR`
Trigger types:	             :class:`~CInScanFlag.HIGH`, :class:`~TriggerType.LOW`,
                             :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                             :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                             :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Counter measurement types:   Counter 0 to Counter 1: :class:`~CounterMeasurementType.COUNT`,
                             :class:`~CounterMeasurementType.PERIOD`, :class:`~CounterMeasurementType.PULSE_WIDTH`
                             |br| Counter 2 to Counter 3: :class:`~CounterMeasurementType.ENCODER`
Counter measurement modes:   :class:`~CounterMeasurementType.COUNT` measurement type: :class:`~CounterMeasurementMode.CLEAR_ON_READ`,
                             :class:`~CounterMeasurementMode.NO_RECYCLE`, :class:`~CounterMeasurementMode.COUNT_DOWN`,
                             :class:`~CounterMeasurementMode.RANGE_LIMIT_ON`
                             |br| :class:`~CounterMeasurementType.PERIOD` measurement type: :class:`~CounterMeasurementMode.PERIOD_X1`,
                             :class:`~CounterMeasurementMode.PERIOD_X10`, :class:`~CounterMeasurementMode.PERIOD_X100`,
                             :class:`~CounterMeasurementMode.PERIOD_X1000`
                             |br| :class:`~CounterMeasurementType.PULSE_WIDTH` measurement type: :class:`~CounterMeasurementMode.DEFAULT` |br|
                             :class:`~CounterMeasurementType.ENCODER` measurement type: :class:`~CounterMeasurementMode.ENCODER_X1`,
                             :class:`~CounterMeasurementMode.ENCODER_X2`, :class:`~CounterMeasurementMode.ENCODER_X4`,
                             :class:`~CounterMeasurementMode.ENCODER_LATCH_ON_Z`, :class:`~CounterMeasurementMode.ENCODER_RANGE_LIMIT_ON`,
                             :class:`~CounterMeasurementMode.ENCODER_Z_ACTIVE_EDGE`
Tick sizes:                  :class:`~CounterTickSize.TICK_20ns`, :class:`~CounterTickSize.TICK_200ns`,
                             :class:`~CounterTickSize.TICK_2000ns`, :class:`~CounterTickSize.TICK_20000ns`
Register types:              :class:`~CounterRegisterType.COUNT`, :class:`~CounterRegisterType.LOAD`,
                             :class:`~CounterRegisterType.MIN_LIMIT`, :class:`~CounterRegisterType.MAX_LIMIT`
Debounce times:              :class:`~CounterDebounceTime.DEBOUNCE_500ns`, :class:`~CounterDebounceTime.DEBOUNCE_1500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3500ns`, :class:`~CounterDebounceTime.DEBOUNCE_7500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_15500ns`, :class:`~CounterDebounceTime.DEBOUNCE_31500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_63500ns`, :class:`~CounterDebounceTime.DEBOUNCE_127500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_100us`, :class:`~CounterDebounceTime.DEBOUNCE_300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_700us`, :class:`~CounterDebounceTime.DEBOUNCE_1500us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3100us`, :class:`~CounterDebounceTime.DEBOUNCE_6300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_12700us`, :class:`~CounterDebounceTime.DEBOUNCE_25500us`
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`, :func:`~CtrDevice.c_config_scan`, :func:`~CtrDevice.c_in_scan`, :func:`~CtrDevice.set_trigger`, :func:`~CtrDevice.get_scan_status`, :func:`~CtrDevice.scan_stop`, :func:`~CtrDevice.scan_wait`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0 to 1
Options:	                   :class:`~PulseOutOption.DEFAULT`, :class:`~PulseOutOption.EXTTRIGGER`, :class:`~PulseOutOption.RETRIGGER`
Frequency:	                 0.0233 to 50,000,000 Hz
Trigger types:	             :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                             :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                             :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                             :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`, :func:`~TmrDevice.get_pulse_out_status`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

DAQI
-------------
===============   ==============================================================
Channel types:	  :class:`~DaqInChanType.ANALOG_DIFF`, :class:`~DaqInChanType.ANALOG_SE`
                  :class:`~DaqInChanType.DIGITAL` :class:`~DaqInChanType.CTR32`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      USB-1808: 0.0233 to 50,000 S/s |br| USB-1808X: 0.0233 to 200,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~DaqiDevice.daq_in_scan`, :func:`~DaqiDevice.get_scan_status`, :func:`~DaqiDevice.scan_stop`, :func:`~DaqiDevice.scan_wait`, :func:`~DaqiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

DAQO
-------------
===============   ==============================================================
Channel types:	  :class:`~DaqOutChanType.ANALOG`, :class:`~DaqOutChanType.DIGITAL`
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	  :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      USB-1808: 0.0233 to 125,000 S/s |br| USB-1808X: 0.0233 to 500,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~DaqoDevice.daq_out_scan`, :func:`~DaqoDevice.get_scan_status`, :func:`~DaqoDevice.scan_stop`, :func:`~DaqoDevice.scan_wait`, :func:`~DaqoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1608g:

*****************
USB-1608G Series
*****************
The USB-1608G Series includes the following devices:

- USB-1608G, USB-1608G-OEM
- USB-1608GX, USB-1608GX-OEM
- USB-1608GX-2AO, USB-1608GX-2AO-OEM

The USB-1608G Series supports the following UL for Linux capabilities. Unless
otherwise indicated, OEM versions support the same capabilities as the equivalent
standard versions.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 15
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`, :class:`~ScanOption.BURSTMODE`
Scan rates:	      USB-1608G: 0.0149 to 250,000 S/s |br| USB-1608GX: 0.0149 to 500,000 S/s |br| USB-1608GX-2AO: 0.0149 to 500,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.0149 to 500,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 15
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 1
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0
Options:	                   :class:`~PulseOutOption.DEFAULT`
Frequency:	                 0.0149 to 32,000,000 Hz
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`, :func:`~TmrDevice.get_pulse_out_status`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

....

.. raw:: latex

       \newpage

.. _1208hs:

*****************
USB-1208HS Series
*****************
The USB-1208HS Series includes the following devices:

- USB-1208HS
- USB-1208HS-2AO
- USB-1208HS-4AO

The USB-1208HS Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          Single-ended: :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2PT5VOLTS`, :class:`~Range.UNI10VOLTS`
                  |br| Differential: :class:`~Range.BIP20VOLTS`, :class:`~Range.BIP10VOLTS`
                  :class:`~Range.BIP5VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`, :class:`~ScanOption.BURSTMODE`
Scan rates:	      0.009 to 1,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        USB-1208HS-2AO: 0 to 1 |br| USB-1208HS-4AO: 0 to 3
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.009 to 1,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 15
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 1
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0
Options:                     :class:`~PulseOutOption.DEFAULT`
Frequency:	                 0.009 to 20,000,000 Hz
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`, :func:`~TmrDevice.get_pulse_out_status`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _2600:

*****************
USB-2600 Series
*****************
The USB-2600 Series includes the following devices:

- USB-2623
- USB-2627
- USB-2633
- USB-2637

The USB-2600 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        USB-2623 and USB-2633: 0 to 15 |br| USB-2627 and USB-2637: 0 to 63
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`, :class:`~ScanOption.BURSTMODE`
Scan rates:	      0.0149 to 1,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output (USB-2627 and USB-2637)
--------------------------------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.009 to 1,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`. :class:`~DigitalPortType.FIRSTPORTC`
Bits:             FIRSTPORTA: 0 to 7 |br| FIRSTPORTB: 0 to 7 |br| FIRSTPORTC: 0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 3
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0 to 3
Options:                     :class:`~PulseOutOption.DEFAULT`
Frequency:	                 0.0149 to 32,000,000 Hz
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`, :func:`~TmrDevice.get_pulse_out_status`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1608fsplus:

*****************
USB-1608FS-Plus
*****************

The USB-1608FS-Plus supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.BURSTIO`, :class:`~ScanOption.PACEROUT`
Scan rates:	      0.009 to 1,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`,
                  :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1208fsplus:

*****************
USB-1208FS-Plus
*****************

The USB-1208FS-Plus supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`, :class:`~AiInputMode.DIFFERENTIAL`
Ranges:	          Single-ended: :class:`~Range.BIP10VOLTS`
                  |br| Differential: :class:`~Range.BIP20VOLTS`, :class:`~Range.BIP10VOLTS`,
                  :class:`~Range.BIP5VOLTS`, :class:`~Range.BIP4VOLTS`:class:`~Range.BIP2PT5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1PT25VOLTS`:class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.0139 to 50,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
--------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.UNI5VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.0139 to 50,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counters:	                   0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1408fsplus:

*****************
USB-1408FS-Plus
*****************

The USB-1408FS-Plus supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`, :class:`~AiInputMode.DIFFERENTIAL`
Ranges:	          Single-ended: :class:`~Range.BIP10VOLTS`
                  |br| Differential: :class:`~Range.BIP20VOLTS`, :class:`~Range.BIP10VOLTS`,
                  :class:`~Range.BIP5VOLTS`, :class:`~Range.BIP4VOLTS`:class:`~Range.BIP2PT5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1PT25VOLTS`:class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.0139 to 48,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
--------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.UNI5VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.0139 to 50,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _200:

*****************
USB-200 Series
*****************
The USB-200 Series includes the following devices:

- USB-201
- USB-202
- USB-204
- USB-205

The USB-200 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`
Scan rates:	      USB-201 and USB-202: 0.0162 to 100,000 S/s |br| USB-204 and USB-205: 0.0162 to 500,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output (USB-202 and USB-205)
--------------------------------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.UNI5VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      TBD S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _2020:

*****************
USB-2020
*****************

The USB-2020 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 1
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`, :class:`~ScanOption.BURSTMODE`, :class:`~ScanOption.PACEROUT`
Scan rates:	      1,000 to 20,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.GATE_HIGH`, :class:`~TriggerType.GATE_LOW`,
                  :class:`~TriggerType.ABOVE`, :class:`~TriggerType.BELOW`,
                  :class:`~TriggerType.GATE_ABOVE`, :class:`~TriggerType.GATE_BELOW`,
                  :class:`~TriggerType.GATE_IN_WINDOW`, :class:`~TriggerType.GATE_OUT_WINDOW`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _2408:

*****************
USB-2408 Series
*****************
The USB-2408 Series includes the following devices:

- USB-2408
- USB-2408-2AO

The USB-2408 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	      0 to 15
Input modes:	  :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2PT5VOLTS`, :class:`~Range.BIP1PT25VOLTS`
                  :class:`~Range.BIPPT625VOLTS`, :class:`~Range.BIPPT312VOLTS`
                  :class:`~Range.BIPPT156VOLTS`, :class:`~Range.BIPPT078VOLTS`
Scan options:	  :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.000011 to 1102.9411 S/s. The rate is dependent on the data rate value; the actual rate that is set will be returned.
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`, :func:`~AiDevice.t_in` :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.get_chan_type`, :class:`~AiConfig.set_chan_type`,
                  :class:`~AiConfig.get_chan_tc_type`, :class:`~AiConfig.set_chan_tc_type`,
                  :class:`~AiConfig.get_chan_data_rate`, :class:`~AiConfig.set_chan_data_rate`,
                  :class:`~AiConfig.get_chan_otd_mode`, :class:`~AiConfig.set_chan_otd_mode`,
                  :class:`~AiConfig.get_temp_unit`, :class:`~AiConfig.set_temp_unit`

===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.000011 to 1,000 S/s
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 1
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _2416:

*****************
USB-2416 Series
*****************
The USB-2416 Series includes the following devices:

- USB-2416
- USB-2416-4AO

The USB-2416 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 31 (0 to 63 if the AI-EXP32 is attached)
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2PT5VOLTS`, :class:`~Range.BIP1PT25VOLTS`
                  :class:`~Range.BIPPT625VOLTS`, :class:`~Range.BIPPT312VOLTS`
                  :class:`~Range.BIPPT156VOLTS`, :class:`~Range.BIPPT078VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.000011 to 1102.9411 S/s
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`, :func:`~AiDevice.t_in` :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.get_chan_type`, :class:`~AiConfig.set_chan_type`,
                  :class:`~AiConfig.get_chan_tc_type`, :class:`~AiConfig.set_chan_tc_type`,
                  :class:`~AiConfig.get_chan_data_rate`, :class:`~AiConfig.set_chan_data_rate`,
                  :class:`~AiConfig.get_chan_otd_mode`, :class:`~AiConfig.set_chan_otd_mode`,
                  :class:`~AiConfig.get_temp_unit`, :class:`~AiConfig.set_temp_unit`

===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        0 to 3
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.000011 to 1,000 S/s
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT0` |br| (:class:`~DigitalPortType.AUXPORT0`,
                  :class:`~DigitalPortType.AUXPORT1`, :class:`~DigitalPortType.AUXPORT2` if the AI-EXP32 is attached.)
Bits:             AUXPORT0: 0 to 7
                  |br| AUXPORT1: 0 to 7 (terminals 8 to 15 on the AI-EXP32)
                  |br| AUXPORT2: 0 to 7 (terminals 16 to 23 on the AI-EXP32)
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 1
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`, :func:`~DaqDeviceConfig.has_exp`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1608hs:

*****************
USB-1608HS Series
*****************
The USB-1608HS Series includes the following devices:

- USB-1608HS
- USB-1608HS-2AO

The USB-1608HS Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	      0 to 7
Input modes:	  :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	  :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER` :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.0093 to 250,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.ABOVE`, :class:`~TriggerType.BELOW`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        0 to 1
Ranges:	          :class:`~Range.BIP10VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`
Scan rates:	      0.59604 to 1,000,000 S/s
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`
Configuration:    :class:`~AoConfig.set_chan_sense_mode`, :class:`~AoConfig.get_chan_sense_mode`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT0`, :class:`~DigitalPortType.AUXPORT1`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _dio32hs:

*****************
USB-DIO32HS
*****************

The DIO32HS Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT0`, :class:`~DigitalPortType.AUXPORT1`
Bits:             0 to 15
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
                  :class:`~TriggerType.PATTERN_EQ`, :class:`~TriggerType.PATTERN_NE`,
                  :class:`~TriggerType.PATTERN_ABOVE`, :class:`~TriggerType.PATTERN_BELOW`
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.d_in_scan`, :func:`~DioDevice.d_out_scan`, :func:`~DioDevice.d_in_get_scan_status`, :func:`~DioDevice.d_out_get_scan_status`, :func:`~DioDevice.d_in_scan_stop`, :func:`~DioDevice.d_out_scan_stop`, :func:`~DioDevice.d_in_scan_wait`, :func:`~DioDevice.d_out_scan_wait`, :func:`~DioDevice.d_in_set_trigger`, :func:`~DioDevice.d_out_set_trigger`, :func:`~DioDevice.get_config`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _ctr0x:

****************
USB-CTR Series
****************
The USB-CTR Series includes the following devices:

- USB-CTR-04
- USB-CTR-08

The USB-CTR Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.02235 to 4,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.d_in_scan`, :func:`~DioDevice.d_out_scan`, :func:`~DioDevice.d_in_get_scan_status`, :func:`~DioDevice.d_in_scan_stop`, :func:`~DioDevice.d_out_scan_stop`, :func:`~DioDevice.d_in_scan_wait`, :func:`~DioDevice.d_out_scan_wait`, :func:`~DioDevice.d_in_set_trigger`, :func:`~DioDevice.d_out_set_trigger`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           USB-CTR04: 0 to 3 |br| USB-CTR08: 0 to 7
Scan options:	               :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:                  16-bit counter: 0.02235 to 4,000,000 S/s
                             |br| 32-bit counter: 0.02235 to 2,000,000 S/s
                             |br| 64-bit counter: 0.02235 to 1,000,000 S/s
Scan flags:                  :class:`~CInScanFlag.DEFAULT`, :class:`~CInScanFlag.CTR16_BIT`,
                             :class:`~CInScanFlag.CTR32_BIT`, :class:`~CInScanFlag.CTR64_BIT`,
                             :class:`~CInScanFlag.NOCLEAR`
Trigger types:	             :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                             :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`,
Counter measurement types:   :class:`~CounterMeasurementType.COUNT`, :class:`~CounterMeasurementType.PERIOD`,
                             :class:`~CounterMeasurementType.PULSE_WIDTH`, :class:`~CounterMeasurementType.TIMING`
Counter measurement modes:   :class:`~CounterMeasurementType.COUNT` measurement type: :class:`~CounterMeasurementMode.CLEAR_ON_READ`,
                             :class:`~CounterMeasurementMode.NO_RECYCLE`, :class:`~CounterMeasurementMode.COUNT_DOWN`,
                             :class:`~CounterMeasurementMode.RANGE_LIMIT_ON`, :class:`~CounterMeasurementMode.RANGE_GATING_ON`,
                             :class:`~CounterMeasurementMode.INVERT_GATE`, :class:`~CounterMeasurementMode.GATE_CONTROLS_DIR`,
                             :class:`~CounterMeasurementMode.GATE_CLEARS_CTR`, :class:`~CounterMeasurementMode.GATE_TRIG_SRC`,
                             :class:`~CounterMeasurementMode.OUTPUT_ON`, :class:`~CounterMeasurementMode.INITIAL_STATE_HIGH`
                             |br| :class:`~CounterMeasurementType.PERIOD` measurement type: :class:`~CounterMeasurementMode.PERIOD_X1`,
                             :class:`~CounterMeasurementMode.PERIOD_X10`, :class:`~CounterMeasurementMode.PERIOD_X100`,
                             :class:`~CounterMeasurementMode.PERIOD_X1000`, :class:`~CounterMeasurementMode.PERIOD_GATING_ON`,
                             :class:`~CounterMeasurementMode.PERIOD_INVERT_GATE`
                             |br| :class:`~CounterMeasurementType.PULSE_WIDTH` measurement type: :class:`~CounterMeasurementMode.GATING_ON`
                             :class:`~CounterMeasurementMode.PULSE_WIDTH_INVERT_GATE`,
                             |br| :class:`~CounterMeasurementType.TIMING` measurement type: :class:`~CounterMeasurementMode.TIMING_MODE_INVERT_GATE`
Tick sizes:                  :class:`~CounterTickSize.TICK_20PT83ns`, :class:`~CounterTickSize.TICK_208PT3ns`,
                             :class:`~CounterTickSize.TICK_2083PT3ns`, :class:`~CounterTickSize.TICK_20833PT3ns`
Register types:              :class:`~CounterRegisterType.COUNT`, :class:`~CounterRegisterType.LOAD`,
                             :class:`~CounterRegisterType.MIN_LIMIT`, :class:`~CounterRegisterType.MAX_LIMIT`,
                             :class:`~CounterRegisterType.OUTPUT_VAL0`, :class:`~CounterRegisterType.OUTPUT_VAL1`
Debounce times:              :class:`~CounterDebounceTime.DEBOUNCE_500ns`, :class:`~CounterDebounceTime.DEBOUNCE_1500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3500ns`, :class:`~CounterDebounceTime.DEBOUNCE_7500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_15500ns`, :class:`~CounterDebounceTime.DEBOUNCE_31500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_63500ns`, :class:`~CounterDebounceTime.DEBOUNCE_127500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_100us`, :class:`~CounterDebounceTime.DEBOUNCE_300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_700us`, :class:`~CounterDebounceTime.DEBOUNCE_1500us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3100us`, :class:`~CounterDebounceTime.DEBOUNCE_6300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_12700us`, :class:`~CounterDebounceTime.DEBOUNCE_25500us`
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`, :func:`~CtrDevice.c_config_scan`, :func:`~CtrDevice.c_in_scan`, :func:`~CtrDevice.set_trigger`, :func:`~CtrDevice.get_scan_status`, :func:`~CtrDevice.scan_stop`, :func:`~CtrDevice.scan_wait`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0 to 3
Options:	                   :class:`~PulseOutOption.DEFAULT`, :class:`~PulseOutOption.EXTTRIGGER`, :class:`~PulseOutOption.RETRIGGER`
Frequency:	                 0.02235 to 48,000,000 Hz
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

DAQI
-------------
===============   ==============================================================
Channel types:	  :class:`~DaqInChanType.DIGITAL`, :class:`~DaqInChanType.CTR16`,
                  :class:`~DaqInChanType.CTR32` :class:`~DaqInChanType.CTR48`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.02235 to 4,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~DaqiDevice.daq_in_scan`, :func:`~DaqiDevice.get_scan_status`, :func:`~DaqiDevice.scan_stop`, :func:`~DaqiDevice.scan_wait`, :func:`~DaqiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _quad08:

****************
USB-QUAD08
****************

The USB-QUAD08 supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0 to 7
Scan options:	               :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`
Scan rates:                  16-bit counter: 0.000011 to 8,000,000 S/s
                             |br| 32-bit counter: 0.000011 to 2,000,000 S/s
                             |br| 64-bit counter: 0.000011 to 1,000,000 S/s
Scan flags:                  :class:`~CInScanFlag.DEFAULT`, :class:`~CInScanFlag.CTR16_BIT`,
                             :class:`~CInScanFlag.CTR32_BIT`, :class:`~CInScanFlag.CTR64_BIT`
Trigger types:	             :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                             :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Counter measurement types:   :class:`~CounterMeasurementType.COUNT`, :class:`~CounterMeasurementType.PERIOD`,
                             :class:`~CounterMeasurementType.PULSE_WIDTH`, :class:`~CounterMeasurementType.ENCODER`
Counter measurement modes:   :class:`~CounterMeasurementType.COUNT` measurement type: :class:`~CounterMeasurementMode.CLEAR_ON_READ`,
                             :class:`~CounterMeasurementMode.NO_RECYCLE`, :class:`~CounterMeasurementMode.RANGE_LIMIT_ON`,
                             :class:`~CounterMeasurementMode.RANGE_GATING_ON`, :class:`~CounterMeasurementMode.GATE_CONTROLS_DIR`,
                             :class:`~CounterMeasurementMode.DECREMENT_ON`, :class:`~CounterMeasurementMode.LATCH_ON_INDEX`,
                             |br| :class:`~CounterMeasurementType.PERIOD` measurement type: :class:`~CounterMeasurementMode.PERIOD_X1`,
                             :class:`~CounterMeasurementMode.PERIOD_X10`, :class:`~CounterMeasurementMode.PERIOD_X100`,
                             :class:`~CounterMeasurementMode.PERIOD_X1000`, :class:`~CounterMeasurementMode.PERIOD_GATING_ON`
                             |br| :class:`~CounterMeasurementType.PULSE_WIDTH` measurement type: :class:`~CounterMeasurementMode.GATING_ON`
                             |br| :class:`~CounterMeasurementType.ENCODER` measurement type: :class:`~CounterMeasurementMode.ENCODER_X1`,
                             :class:`~CounterMeasurementMode.ENCODER_X2`, :class:`~CounterMeasurementMode.ENCODER_X4`,
                             :class:`~CounterMeasurementMode.ENCODER_LATCH_ON_Z`, :class:`~CounterMeasurementMode.ENCODER_CLEAR_ON_Z`,
                             :class:`~CounterMeasurementMode.ENCODER_NO_RECYCLE`, :class:`~CounterMeasurementMode.ENCODER_RANGE_LIMIT_ON`
Tick sizes:                  :class:`~CounterTickSize.TICK_20PT83ns`, :class:`~CounterTickSize.TICK_208PT3ns`,
                             :class:`~CounterTickSize.TICK_2083PT3ns`, :class:`~CounterTickSize.TICK_20833PT3ns`
Register types:              :class:`~CounterRegisterType.COUNT`, :class:`~CounterRegisterType.LOAD`,
                             :class:`~CounterRegisterType.MAX_LIMIT`
Debounce times:              :class:`~CounterDebounceTime.DEBOUNCE_500ns`, :class:`~CounterDebounceTime.DEBOUNCE_1500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3500ns`, :class:`~CounterDebounceTime.DEBOUNCE_7500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_15500ns`, :class:`~CounterDebounceTime.DEBOUNCE_31500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_63500ns`, :class:`~CounterDebounceTime.DEBOUNCE_127500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_100us`, :class:`~CounterDebounceTime.DEBOUNCE_300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_700us`, :class:`~CounterDebounceTime.DEBOUNCE_1500us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3100us`, :class:`~CounterDebounceTime.DEBOUNCE_6300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_12700us`, :class:`~CounterDebounceTime.DEBOUNCE_25500us`
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`, :func:`~CtrDevice.c_config_scan`, :func:`~CtrDevice.c_in_scan`, :func:`~CtrDevice.set_trigger`, :func:`~CtrDevice.get_scan_status`, :func:`~CtrDevice.scan_stop`, :func:`~CtrDevice.scan_wait`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Timer
-------------
==========================   ==============================================================
Timer argument:	             0 to 3
Options:	                   :class:`~PulseOutOption.DEFAULT`, :class:`~PulseOutOption.EXTTRIGGER`, :class:`~PulseOutOption.RETRIGGER`
Frequency:	                 0.02235 to 48,000,000 Hz
Trigger types:	             :class:`~TriggerType.NEG_EDGE`
Functions:	                 :func:`~TmrDevice.pulse_out_start`, :func:`~TmrDevice.pulse_out_stop`, :func:`~TmrDevice.get_pulse_out_status`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

DAQI
-------------
===============   ==============================================================
Channel types:	  :class:`~DaqInChanType.DIGITAL`, :class:`~DaqInChanType.CTR16`,
                  :class:`~DaqInChanType.CTR32` :class:`~DaqInChanType.CTR48`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.RETRIGGER`
Scan rates:	      0.02235 to 4,000,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~DaqiDevice.daq_in_scan`, :func:`~DaqiDevice.get_scan_status`, :func:`~DaqiDevice.scan_stop`, :func:`~DaqiDevice.scan_wait`, :func:`~DaqiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _1024:

*****************
USB-1024LS Series
*****************
The USB-1024LS Series includes the following devices:

- USB-1024LS
- USB-1024HLS

The USB-1024LS Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`, :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
Bits:             FIRSTPORTA: 0 to 7
                  |br| FIRSTPORTB: 0 to 7
                  |br| FIRSTPORTCL: 0 to 3
                  |br| FIRSTPORTCH: 0 to 3
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`, |br| :class:`~DioConfig.set_port_initial_output_val` (USB-1024HLS only)
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _dio24:

*****************
USB-DIO24 Series
*****************
The USB-DIO24 Series includes the following devices:

- USB-DIO24/37
- USB-DIO24H/37

The USB-DIO24 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`, :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
Bits:             FIRSTPORTA: 0 to 7
                  |br| FIRSTPORTB: 0 to 7
                  |br| FIRSTPORTCL: 0 to 3
                  |br| FIRSTPORTCH: 0 to 3
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`, |br| :class:`~DioConfig.set_port_initial_output_val` (USB-DIO24H/37 only)
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _dio96h:

******************
USB-DIO96H Series
******************
The USB-DIO96H Series includes the following devices:

- USB-DIO96H
- USB-DIO96H/50

The USB-DIO96H Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`, :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
                  |br| :class:`~DigitalPortType.SECONDPORTA`, :class:`~DigitalPortType.SECONDPORTB`, :class:`~DigitalPortType.SECONDPORTCL`, :class:`~DigitalPortType.SECONDPORTCH`
                  |br| :class:`~DigitalPortType.THIRDPORTA`, :class:`~DigitalPortType.THIRDPORTB`, :class:`~DigitalPortType.THIRDPORTCL`, :class:`~DigitalPortType.THIRDPORTCH`
                  |br| :class:`~DigitalPortType.FOURTHPORTA`, :class:`~DigitalPortType.FOURTHPORTB`, :class:`~DigitalPortType.FOURTHPORTCL`, :class:`~DigitalPortType.FOURTHPORTCH`
Bits:             PORTA: 0 to 7
                  |br| PORTB: 0 to 7
                  |br| PORTCL: 0 to 3
                  |br| PORTCH: 0 to 3
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`, :class:`~DioConfig.set_port_initial_output_val`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter (USB-DIO96H only)
-----------------------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _erb:

******************
USB-ERB Series
******************
The USB-ERB Series includes the following devices:

- USB-ERB08
- USB-ERB24

The USB-ERB Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          USB-ERB08: :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
                  |br| USB-ERB24: :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`, :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
Bits:             FIRSTPORTA and FIRSTPORTB: 0 to 7
                  |br| FIRSTPORTCL and FIRSTPORTCH: 0 to 3
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_logic`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _ssr:

******************
USB-SSR Series
******************
The USB-SSR Series includes the following devices:

- USB-SSR08
- USB-SSR24

The USB-SSR Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          USB-SSR08: :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
                  |br| USB-SSR24: :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`, :class:`~DigitalPortType.FIRSTPORTCL`, :class:`~DigitalPortType.FIRSTPORTCH`
Bits:             FIRSTPORTA and FIRSTPORTB: 0 to 7
                  |br| FIRSTPORTCL and FIRSTPORTCH: 0 to 3
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_logic`, :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-----------------------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _pdiso:

******************
USB-PDISO8 Series
******************
The USB-PDISO8 Series includes the following devices:

- USB-PDISO8
- USB-PDISO8/40

The USB-PDISO8 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT0`, :class:`~DigitalPortType.AUXPORT1`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_iso_filter_mask`, :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _3100:

******************
USB-3100 Series
******************
The USB-3100 Series includes the following devices:

- USB-3101
- USB-3102
- USB-3103
- USB-3104
- USB-3105
- USB-3106
- USB-3110
- USB-3112
- USB-3114

The USB-PDISO8 Series supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	        USB-3101, USB-3102, and USB-3110: 0 to 3 |br| USB-3103, USB-3104, and USB-3112: 0 to 7 |br| USB-3105, USB-3106, and USB-3114: 0 to 15
Ranges:	          USB-3101, USB-3103, USB-3105, USB-3110, USB-3112, and USB-3114: :class:`~Range.BIP10VOLTS`, :class:`~Range.UNI10VOLTS`
                  |br| USB-3102, USB-3104, and USB-3106: :class:`~Range.BIP10VOLTS`, :class:`~Range.UNI10VOLTS`, :class:`~Range.MA0TO20`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_list`, :func:`~AoDevice.get_config`
Configuration:    :class:`~AoConfig.set_sync_mode`, :class:`~AoConfig.get_sync_mode`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==================    ==============================================================
Counter argument:	    0 to 1
Functions:	          :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:        none
==================    ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============    ==============================================================
Functions:	       :func:`~DaqDevice.flash_led`
Configuration:     none
===============    ==============================================================

....

.. raw:: latex

       \newpage

.. _2001tc:

*****************
USB-2001-TC
*****************

The USB-2001-TC supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _tc:

*****************
USB-TC
*****************

The USB-TC supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _temp:

*****************
USB-TEMP
*****************

The USB-TEMP supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 7
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`, :class:`~AiConfig.set_chan_type`, :class:`~AiConfig.get_chan_type`, :class:`~AiConfig.set_chan_sensor_connection_type`, :class:`~AiConfig.get_chan_sensor_connection_type`, :class:`~AiConfig.get_chan_sensor_coefficients`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==================   ==============================================================
Counter argument:	   0
Functions:	         :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:       none
==================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _tcai:

*****************
USB-TC-AI
*****************

The USB-TC-AI supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        Temperature: 0 to 7 |br| Voltage: 4 to 7
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~AiInputMode.SINGLE_ENDED`: :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2PT5VOLTS`, :class:`~Range.BIP1PT25VOLTS`
                  |br| :class:`~AiInputMode.DIFFERENTIAL`: :class:`~Range.BIP10VOLTS`,
                  :class:`~Range.BIP5VOLTS`, :class:`~Range.BIP2PT5VOLTS`,
                  :class:`~Range.BIP1PT25VOLTS`, :class:`~Range.BIPPT078VOLTS`
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.a_in`, :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==================   ==============================================================
Counter argument:	   0
Functions:	         :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:       none
==================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _tempai:

*****************
USB-TEMP-AI
*****************

The USB-TEMP-AI supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        Temperature: 0 to 7 |br| Voltage: 4 to 7
Input modes:	    :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~AiInputMode.SINGLE_ENDED`: :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2PT5VOLTS`, :class:`~Range.BIP1PT25VOLTS`
                  |br| :class:`~AiInputMode.DIFFERENTIAL`: :class:`~Range.BIP10VOLTS`,
                  :class:`~Range.BIP5VOLTS`, :class:`~Range.BIP2PT5VOLTS`,
                  :class:`~Range.BIP1PT25VOLTS`, :class:`~Range.BIPPT078VOLTS`
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.a_in`, :func:`~AiDevice.get_config`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`, :class:`~AiConfig.set_chan_type`, :class:`~AiConfig.get_chan_type`, :class:`~AiConfig.set_chan_sensor_connection_type`, :class:`~AiConfig.get_chan_sensor_connection_type`, :class:`~AiConfig.get_chan_sensor_coefficients`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==================   ==============================================================
Counter argument:	   0
Functions:	         :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:       none
==================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _sc1608:

*****************
SC-1608G Series
*****************

The SC-1608G Series includes the following devices:

- SC-1608G - this board is functionally equivalent to the USB-1608G.
- SC-1608GX - this board is functionally equivalent to the USB-1608GX.
- SC-1608GX-2AO - this board is functionally equivalent to the USB-1608GX-2AO.

Refer to the :ref:`USB-1608G Series <1608g>` topic for supporting UL for Linux capabilities applicable
to the SC-1608G Series.

....

.. raw:: latex

       \newpage

.. _dt9837:

****************
DT9837 Series
****************
The DT9837 Series includes the following devices:

- DT9837A
- DT9837B
- DT9837C

The DT9837 Series supports the following UL for Linux capabilities. Unless
otherwise indicated, OEM versions support the same capabilities as the equivalent
standard versions.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	        0 to 3
Input modes:	    :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.EXTTIMEBASE`, :class:`~ScanOption.TIMEBASEOUT`
Scan rates:	      DT9837A: 195.313 to 52,734 S/s  |br| DT9837B: 195.313 to 105,469 S/s |br| DT9837C: 195.313 to 105,469 S/s
Trigger types:	  DT9837A: :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`
                  |br| DT9837B: :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`,
                  |br| DT9837C: :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`,
                  :class:`~TriggerType.RISING`, :class:`~TriggerType.FALLING`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`, :func:`~AiDevice.get_config`
Configuration*:   :class:`~AiConfig.set_chan_iepe_mode`, :class:`~AiConfig.get_chan_iepe_mode`, :class:`~AiConfig.set_chan_coupling_mode`, :class:`~AiConfig.get_chan_coupling_mode`, :class:`~AiConfig.set_chan_sensor_connection_type`, :class:`~AiConfig.get_chan_sensor_connection_type`
===============   ==============================================================

\* For additional information, refer to the *Using UL for Linux* section in Appendix D of the `DT9837 Series User's Manual <https://www.mccdaq.com/GetPDF.aspx?t=/PDFs/manuals/UM9837.pdf>`_.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output (DT9837A and DT9837C only)
-----------------------------------------
===============   ==============================================================
Channels:	        0
Ranges:	          DT9837A: :class:`~Range.BIP10VOLTS`
                  |br| DT9837C: :class:`~Range.BIP3VOLTS`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTTRIGGER`
Scan rates:	      DT9837A: 10,000 to 52,734 S/s |br| DT9837C: 10,000 to 96,000 S/s
Trigger types:	  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`
Functions:	      :func:`~AoDevice.a_out`, :func:`~AoDevice.a_out_scan`, :func:`~AoDevice.get_scan_status`, :func:`~AoDevice.scan_stop`, :func:`~AoDevice.scan_wait`, :func:`~AoDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter (DT9837A and DT9837B only)
-----------------------------------
==========================   ==============================================================
Counter argument:	           0 to 2
Scan options:	               :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.EXTTIMEBASE`, :class:`~ScanOption.TIMEBASEOUT`
Scan rates:	                 DT9837A: 195.313 to 52,734 S/s |br| DT9837B: 195.313 to 10,546 S/s
Scan flags:                  :class:`~CInScanFlag.DEFAULT`, :class:`~CInScanFlag.CTR32_BIT`, :class:`~CInScanFlag.NOCLEAR`
Trigger types:	             :class:`~CInScanFlag.POS_EDGE`, :class:`~TriggerType.RISING`
Counter measurement types:   Counter 0 to Counter 1: :class:`~CounterMeasurementType.COUNT`,
                             :class:`~CounterMeasurementType.PERIOD`,
                             |br| Counter 2 to Counter 3: :class:`~CounterMeasurementType.PULSE_WIDTH`
Counter measurement modes:   :class:`~CounterMeasurementType.COUNT` measurement type: :class:`~CounterMeasurementMode.DEFAULT`
                             |br| :class:`~CounterMeasurementType.PERIOD` measurement type: :class:`~CounterMeasurementMode.PERIOD_X1`,
                             |br| :class:`~CounterMeasurementType.PULSE_WIDTH` measurement type: :class:`~CounterMeasurementMode.DEFAULT`
Tick sizes:                  :class:`~CounterTickSize.TICK_20ns`, :class:`~CounterTickSize.TICK_200ns`,
                             :class:`~CounterTickSize.TICK_2000ns`, :class:`~CounterTickSize.TICK_20000ns`
Register types:              :class:`~CounterRegisterType.COUNT`, :class:`~CounterRegisterType.LOAD`,
                             :class:`~CounterRegisterType.MIN_LIMIT`, :class:`~CounterRegisterType.MAX_LIMIT`
Debounce times:              :class:`~CounterDebounceTime.DEBOUNCE_500ns`, :class:`~CounterDebounceTime.DEBOUNCE_1500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3500ns`, :class:`~CounterDebounceTime.DEBOUNCE_7500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_15500ns`, :class:`~CounterDebounceTime.DEBOUNCE_31500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_63500ns`, :class:`~CounterDebounceTime.DEBOUNCE_127500ns`,
                             :class:`~CounterDebounceTime.DEBOUNCE_100us`, :class:`~CounterDebounceTime.DEBOUNCE_300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_700us`, :class:`~CounterDebounceTime.DEBOUNCE_1500us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_3100us`, :class:`~CounterDebounceTime.DEBOUNCE_6300us`,
                             :class:`~CounterDebounceTime.DEBOUNCE_12700us`, :class:`~CounterDebounceTime.DEBOUNCE_25500us`
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`, :func:`~CtrDevice.c_config_scan`, :func:`~CtrDevice.c_in_scan`, :func:`~CtrDevice.set_trigger`, :func:`~CtrDevice.get_scan_status`, :func:`~CtrDevice.scan_stop`, :func:`~CtrDevice.scan_wait`
Configuration*:              :class:`~CtrConfig.set_register_val`, :class:`~CtrConfig.get_register_val`
==========================   ==============================================================

\* For additional information, refer to the *Using UL for Linux* section in Appendix D of the `DT9837 Series User's Manual <https://www.mccdaq.com/GetPDF.aspx?t=/PDFs/manuals/UM9837.pdf>`_.

.. tabularcolumns:: |p{75pt}|p{370pt}|

DAQI
-------------
===============   ==============================================================
Channel types:	  DT9837A: :class:`~DaqInChanType.ANALOG_SE`, :class:`~DaqInChanType.CTR32`, :class:`~DaqInChanType.DAC`
                  |br| DT9837B: :class:`~DaqInChanType.ANALOG_SE`, :class:`~DaqInChanType.CTR32`
                  |br| DT9837C: :class:`~DaqInChanType.ANALOG_SE`
Scan options:	    :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.SINGLEIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTTRIGGER`, :class:`~ScanOption.EXTTIMEBASE`, :class:`~ScanOption.TIMEBASEOUT`
Scan rates:	      DT9837A: 195.313 to 52,734 S/s |br| DT9837B: 195.313 to 105,469 S/s |br| DT9837C: 195.313 to 105,469 S/s
Trigger types:	  DT9837A::class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`
                  |br| DT9837B: :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.RISING`
                  |br| DT9837C: :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
                  :class:`~TriggerType.RISING`, :class:`~TriggerType.FALLING`
Functions:	      :func:`~DaqiDevice.daq_in_scan`, :func:`~DaqiDevice.get_scan_status`, :func:`~DaqiDevice.scan_stop`, :func:`~DaqiDevice.scan_wait`, :func:`~DaqiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`, :class:`~DaqEventType.ON_END_OF_OUTPUT_SCAN`,
                  :class:`~DaqEventType.ON_OUTPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`
Configuration:    none
===============   ==============================================================

....

.. raw:: latex

       \newpage

.. _e1608:

*****************
E-1608
*****************

The E-1608 supports the following UL for Linux capabilities. Unless otherwise
indicated, the OEM version supports the same capabilities as the standard version.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	      0 to 7
Input modes:	  :class:`~AiInputMode.DIFFERENTIAL`, :class:`~AiInputMode.SINGLE_ENDED`
Ranges:	          :class:`~Range.BIP10VOLTS`, :class:`~Range.BIP5VOLTS`,
                  :class:`~Range.BIP2VOLTS`, :class:`~Range.BIP1VOLTS`
Scan options:	  :class:`~ScanOption.DEFAULTIO`, :class:`~ScanOption.BLOCKIO`, :class:`~ScanOption.CONTINUOUS`, :class:`~ScanOption.EXTCLOCK`, :class:`~ScanOption.EXTTRIGGER`
Scan rates:	      0.01863 to 250,000 S/s
Trigger types:	  :class:`~TriggerType.HIGH`, :class:`~TriggerType.LOW`,
                  :class:`~TriggerType.POS_EDGE`, :class:`~TriggerType.NEG_EDGE`
Functions:	      :func:`~AiDevice.a_in`, :func:`~AiDevice.a_in_scan`, :func:`~AiDevice.a_in_load_queue`, :func:`~AiDevice.get_scan_status`, :func:`~AiDevice.scan_stop`, :func:`~AiDevice.scan_wait`, :func:`~AiDevice.set_trigger`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Output
-------------
===============   ==============================================================
Channels:	      0 to 1
Ranges:	          :class:`~Range.BIP10VOLTS`
Functions:	      :func:`~AoDevice.a_out`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	         0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Events
-------------
===============   ==============================================================
Event types:      :class:`~DaqEventType.ON_DATA_AVAILABLE`, :class:`~DaqEventType.ON_END_OF_INPUT_SCAN`,
                  :class:`~DaqEventType.ON_INPUT_SCAN_ERROR`
Functions:	      :func:`~DaqDevice.enable_event`, :func:`~DaqDevice.disable_event`
Configuration:    none
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`, :func:`~DaqDevice.mem_read`, :func:`~DaqDevice.mem_write`
Configuration:    :class:`~DaqDeviceConfig.get_connection_code`,
                  :class:`~DaqDeviceConfig.set_connection_code`,
                  :class:`~DaqDeviceConfig.get_ip_address`,
                  :class:`~DaqDeviceConfig.get_network_interface_name`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{300pt}|p{75pt}|

Settings memory map
********************
The settings memory map is provided for advanced applications which require device
configuration.

Note that default device settings are acceptable for most applications. If you need
to change a device setting, however, the preferred method to use is InstaCal.

=============   =========================================================     =================
**Address**     **Value**                                                     **Default Value**
-------------   ---------------------------------------------------------     -----------------
0x000-0x001      Network options:

                    Bit 0: 0 = DHCP enabled, 1 = DHCP disabled                 0x0000
                    |br| Bit 1: 0 = Auto IP enabled, 0 = Auto IP disabled
                    |br| Bit 2-15: reserved
0x002-0x005      Default IPv4 address                                          192.168.0.101
0x006-0x009      Default IPv4 subnet mask                                      255.255.255.0
0x00A-0x00D      Default IPv4 gateway address                                  192.168.0.101
0x00E-0x00F      Reserved
0x010-0x011      Reserved
0x012-0x015      Connection code, 4 bytes                                      0x00000000
0x016            DOut connection mode. This determines the DOut value          0
                 when the connection status changes.
                 |br| 0 = no change
                 |br| 1 = apply specified tristate/latch values
0x017            DOut tristate mask for connection/disconnection               0xFF
                 (bits set to 0 are outputs, bits set to 1 are no
                 change).
0x018            Reserved
0x019            DOut latch value when host is connected.                      0x00
0x01A            DOut latch value when host is disconnected.                   0x00
0x01B            AOut channel 0 connection mode. This determines the           0
                 AOut value when the connection changes.
                 |br| 0 = no change
                 |br| 1 = apply specified values to channel 0
0x01C-0x01D      AOut channel 0 value when host is connected.                  32768
0x01E-0x01F      AOut channel 0 value when host is disconnected.               32768
0x020            AOut channel 1 connection mode. This determines the           0
                 AOut value when the connection changes.
                 |br| 0 = no change
                 |br| 1 = apply specified values to channel 1
0x021-0x022      AOut channel 1 value when host is connected.                  32768
0x023-0x024      AOut channel 1 value when host is disconnected.               32768
0x025-0x1FF      Reserved
=============   =========================================================     =================

Note: The settings do not take effect until after the device is reset or power
cycled.

If you are unable to communicate with the device after changing the settings
section of memory, refer to the *Restoring factory default settings* section of the
device user's manual.

To prevent unwanted memory writes to the device EEPROM, a memory unlock code of
0xAA55 is required for the :class:`DaqDevice.mem_write` and
:class:`DaqDeviceConfig.set_connection_code` functions.

....

.. raw:: latex

       \newpage

.. _edio24:

*****************
E-DIO24
*****************

The E-DIO24 supports the following UL for Linux capabilities. Unless otherwise
indicated, the OEM version supports the same capabilities as the standard version.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT0`,
                  :class:`~DigitalPortType.AUXPORT1`,
                  :class:`~DigitalPortType.AUXPORT2`
Bits:             AUXPORT0: 0 to 7
                  |br| AUXPORT1: 0 to 7
                  |br| AUXPORT2: 0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_in_list`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_out_list`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.get_config`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	           0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`, :func:`~DaqDevice.mem_read`, :func:`~DaqDevice.mem_write`
Configuration:    :class:`~DaqDeviceConfig.get_connection_code`,
                  :class:`~DaqDeviceConfig.set_connection_code`,
                  :class:`~DaqDeviceConfig.get_ip_address`,
                  :class:`~DaqDeviceConfig.get_network_interface_name`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{300pt}|p{75pt}|

Settings memory map
********************
The settings memory map is provided for advanced applications which require device
configuration.

Note that default device settings are acceptable for most applications. If you need
to change a device setting, however, the preferred method to use is InstaCal.

=============   =========================================================     =================
**Address**     **Value**                                                     **Default Value**
-------------   ---------------------------------------------------------     -----------------
0x000-0x001      Network options:

                    Bit 0: 0 = DHCP enabled, 1 = DHCP disabled                 0x0000
                    |br| Bit 1: 0 = Auto IP enabled, 0 = Auto IP disabled
                    |br| Bit 2-15: reserved
0x002-0x005      Default IPv4 address                                          192.168.0.101
0x006-0x009      Default IPv4 subnet mask                                      255.255.255.0
0x00A-0x00D      Default IPv4 gateway address                                  192.168.0.101
0x00E-0x00F      Reserved
0x010-0x011      Reserved
0x012-0x015      Connection code, 4 bytes                                      0x00000000
0x016            DOut connection mode. This determines the DOut value          0
                 when the connection status changes.
                 |br| 0 = no change
                 |br| 1 = apply specified tristate/latch values
0x017            Reserved
0x018            DOut port 0 tristate mask for connection/disconnection        0xFF
                 (bits set to 0 are outputs, bits set to 1 are no
                 change).
0x019            DOut port 1 tristate mask for connection/disconnection        0xFF
                 (bits set to 0 are outputs, bits set to 1 are no
                 change).
0x01A            DOut port 2 tristate mask for connection/disconnection        0xFF
                 (bits set to 0 are outputs, bits set to 1 are no
                 change).
0x01B            Reserved
0x01C            DOut port 0 latch value when host is connected.               0x00
0x01D            DOut port 1 latch value when host is connected.               0x00
0x01E            DOut port 2 latch value when host is connected.               0x00
0x01F            Reserved
0x020            DOut port 0 latch value when host is disconnected.            0x00
0x021            DOut port 1 latch value when host is disconnected.            0x00
0x022            DOut port 2 latch value when host is disconnected.            0x00
0x023-0x0FF      Reserved
=============   =========================================================     =================

Note: The settings do not take effect until after the device is reset or power
cycled.

If you are unable to communicate with the device after changing the settings
section of memory, refer to the *Restoring factory default settings* section of the
device user's manual.

To prevent unwanted memory writes to the device EEPROM, a memory unlock code of
0xAA55 is required for the :class:`DaqDevice.mem_write` and
:class:`DaqDeviceConfig.set_connection_code` functions.

....

.. raw:: latex

       \newpage

.. _etc:

*****************
E-TC
*****************

The E-TC supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
================= ==============================================================
Channels:	      0 to 7
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.get_config`
Flags:            :class:`~TInFlag.DEFAULT`, :class:`~TInFlag.WAIT_FOR_NEW_DATA`
List flags:       :class:`~TInListFlag.DEFAULT`, :class:`~TInListFlag.WAIT_FOR_NEW_DATA`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`,
                  :class:`~AiConfig.set_chan_type`, :class:`~AiConfig.get_chan_type`,
                  :class:`~AiConfig.set_otd_mode`, :class:`~AiConfig.get_otd_mode`,
                  :class:`~AiConfig.set_calibration_table_type`, :class:`~AiConfig.get_calibration_table_type`
================= ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.AUXPORT`
Bits:             0 to 7
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config`, :func:`~DioDevice.d_clear_alarm`
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	         0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`, :func:`~DaqDevice.mem_read`, :func:`~DaqDevice.mem_write`
Configuration:    :class:`~DaqDeviceConfig.get_connection_code`,
                  :class:`~DaqDeviceConfig.set_connection_code`,
                  :class:`~DaqDeviceConfig.get_ip_address`,
                  :class:`~DaqDeviceConfig.get_network_interface_name`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{300pt}|p{75pt}|

Settings memory map
********************
The settings memory map is provided for advanced applications which require device
configuration.

Note that default device settings are acceptable for most applications. If you need
to change a device setting, however, the preferred method to use is InstaCal.

=============   =========================================================     =================
**Address**     **Value**                                                     **Default Value**
-------------   ---------------------------------------------------------     -----------------
0x00-0x01       Network options:

                   Bit 0: 0 = DHCP enabled, 1 = DHCP disabled                 0x0000
                   |br| Bit 1: 0 = Auto IP enabled, 0 = Auto IP disabled
                   |br| Bit 2-15: reserved
0x02-0x05       Default IPv4 address                                          192.168.0.101
0x06-0x09       Default IPv4 subnet mask                                      255.255.255.0
0x0A-0x0D       Default IPv4 gateway address                                  192.168.0.101
0x0E-0x0F       Reserved
0x10-0x11       Reserved
0x12-0x15       Connection code, 4 bytes                                      0x00000000
0x16-0x1F       Reserved
=============   =========================================================     =================

Note: The settings do not take effect until after the device is reset or power
cycled.

If you are unable to communicate with the device after changing the settings
section of memory, refer to the *Restoring factory default settings* section of the
device user's manual.

To prevent unwanted memory writes to the device EEPROM, a memory unlock code of
0xAA55 is required for the :class:`DaqDevice.mem_write` and
:class:`DaqDeviceConfig.set_connection_code` functions.

....

.. raw:: latex

       \newpage

.. _tc32:

*****************
TC-32
*****************

The TC-32 supports the following UL for Linux capabilities.

.. tabularcolumns:: |p{75pt}|p{370pt}|

Analog Input
-------------
===============   ==============================================================
Channels:	      0 to 31 |br| 0 to 63 if the TC-32-EXP is attached - see :class:`~DaqDeviceConfig.has_exp` below
Functions:	      :func:`~AiDevice.t_in`, :func:`~AiDevice.t_in_list`, :func:`~AiDevice.get_config`
Flags:            :class:`~TInFlag.DEFAULT`, :class:`~TInFlag.WAIT_FOR_NEW_DATA`
List flags:       :class:`~TInListFlag.DEFAULT`, :class:`~TInListFlag.WAIT_FOR_NEW_DATA`
Configuration:    :class:`~AiConfig.set_chan_tc_type`, :class:`~AiConfig.get_chan_tc_type`,
                  :class:`~AiConfig.set_chan_type`, :class:`~AiConfig.get_chan_type`,
                  :class:`~AiConfig.set_reject_freq_type`, :class:`~AiConfig.get_reject_freq_type`,
                  :class:`~AiConfig.set_calibration_table_type`, :class:`~AiConfig.get_calibration_table_type`,
                  :class:`~AiConfig.set_otd_mode`, :class:`~AiConfig.get_otd_mode`,
                  :class:`~AiConfig.get_expansion_cal_date`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Digital I/O
-------------
===============   ==============================================================
Ports:	          :class:`~DigitalPortType.FIRSTPORTA`, :class:`~DigitalPortType.FIRSTPORTB`
                  |br| :class:`~DigitalPortType.SECONDPORTA`, :class:`~DigitalPortType.SECONDPORTB` if the TC-32-EXP is attached - see :class:`~DaqDeviceConfig.has_exp` below
Bits:             :class:`~DigitalPortType.FIRSTPORTA`: 0 to 7
                  |br| :class:`~DigitalPortType.FIRSTPORTB`: 0 to 31
                  |br| :class:`~DigitalPortType.SECONDPORTA`: 0 to 7
                  |br| :class:`~DigitalPortType.SECONDPORTB`: 0 to 31
Functions:	      :func:`~DioDevice.d_in`, :func:`~DioDevice.d_out`, :func:`~DioDevice.d_bit_in`, :func:`~DioDevice.d_bit_out`, :func:`~DioDevice.d_config_port`, :func:`~DioDevice.d_config_bit`, :func:`~DioDevice.get_config` |br| |br| Call :class:`DaqDeviceConfig.has_exp` to determine the number of valid ports.
Configuration:    :class:`~DioConfig.get_port_direction`
===============   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Counter
-------------
==========================   ==============================================================
Counter argument:	         0
Functions:	                 :func:`~CtrDevice.c_in`, :func:`~CtrDevice.c_read`, :func:`~CtrDevice.c_load`, :func:`~CtrDevice.c_clear`
Configuration:               none
==========================   ==============================================================

.. tabularcolumns:: |p{75pt}|p{370pt}|

Device
-------------
===============   ==============================================================
Functions:	      :func:`~DaqDevice.flash_led`, :func:`~DaqDevice.mem_read`, :func:`~DaqDevice.mem_write`
Configuration:    :class:`~DaqDeviceConfig.get_connection_code`,
                  :class:`~DaqDeviceConfig.set_connection_code`,
                  :class:`~DaqDeviceConfig.get_ip_address`,
                  :class:`~DaqDeviceConfig.get_network_interface_name`,
                  :class:`~DaqDeviceConfig.has_exp`
===============   ==============================================================


.. tabularcolumns:: |p{75pt}|p{300pt}|p{75pt}|

Settings memory map
********************
The settings memory map is provided for advanced applications which require device
configuration.

Note that default device settings are acceptable for most applications. If you need
to change a device setting, however, the preferred method to use is InstaCal.

=============   =========================================================     =================
**Address**     **Value**                                                     **Default Value**
-------------   ---------------------------------------------------------     -----------------
0x00-0x01       Network options:

                   Bit 0: 0 = DHCP enabled, 1 = DHCP disabled                 0x0000
                   |br| Bit 1: 0 = Auto IP enabled, 0 = Auto IP disabled
                   |br| Bit 2-15: reserved
0x02-0x05       Default IPv4 address                                          192.168.0.101
0x06-0x09       Default IPv4 subnet mask                                      255.255.255.0
0x0A-0x0D       Default IPv4 gateway address                                  192.168.0.101
0x0E-0x0F       Reserved
0x10-0x11       Reserved
0x12-0x15       Connection code, 4 bytes                                      0x00000000
0x16-0x1F       Reserved
=============   =========================================================     =================

Note: The settings do not take effect until after the device is reset or power
cycled.

If you are unable to communicate with the device after changing the settings
section of memory, refer to the *Restoring factory default settings* section of the
device user's manual.

To prevent unwanted memory writes to the device EEPROM, a memory unlock code of
0xAA55 is required for the :class:`DaqDevice.mem_write` and
:class:`DaqDeviceConfig.set_connection_code` functions.
