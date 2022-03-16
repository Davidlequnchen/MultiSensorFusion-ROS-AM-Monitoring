.. currentmodule:: uldaq

.. _hwref:

####################
Hardware Reference
####################
This section is an overview of capabilities for specific devices.
In some cases, parameters are dependent on other parameter settings.
Where that is the case, the more inclusive value will be shown.
For example, if a device has fewer channels in differential mode than in
single-ended mode, the single-ended value will be shown here. Likewise, if
there are different ranges for different modes of operation, all potential
ranges are shown.

To determine device capabilities for specific modes of operation, or valid
arguments not listed here, use the :class:`DaqDevice` class methods to query the
device to determine the subsystems supported, then use the :class:`DaqDeviceInfo`
class methods for each of the supported subsystems to determine capabilities.

After a connection to the device is established, you can also use the Config class
methods for each subsystem to get and set the current configuration of the device.

    .. list-table:: Measurement Computing devices supported by UL for Linux
        :widths: 25 25 25 25
        :header-rows: 0

        * - :ref:`E-1608 <e1608>`
          - :ref:`USB-1608GX <1608g>`
          - :ref:`USB-2623 <2600>`
          - :ref:`USB-DIO24H/37 <dio24>`

        * - :ref:`E-DIO24 <edio24>`
          - :ref:`USB-1608GX-2AO <1608g>`
          - :ref:`USB-2627 <2600>`
          - :ref:`USB-DIO32HS <dio32hs>`

        * - :ref:`E-TC <etc>`
          - :ref:`USB-1608HS <1608hs>`
          - :ref:`USB-2633 <2600>`
          - :ref:`USB-DIO96H <dio96h>`

        * - :ref:`SC-1608-2AO-USB <sc1608>`
          - :ref:`USB-1608HS-2AO <1608hs>`
          - :ref:`USB-2637 <2600>`
          - :ref:`USB-DIO96H/50 <dio96h>`

        * - :ref:`SC-1608-USB <sc1608>`
          - :ref:`USB-1808 <1808>`
          - :ref:`USB-3101 <3100>`
          - :ref:`USB-ERB08 <erb>`

        * - :ref:`SC-1608X-USB <sc1608>`
          - :ref:`USB-1808X <1808>`
          - :ref:`USB-3102 <3100>`
          - :ref:`USB-ERB24 <erb>`

        * - :ref:`TC-32 <tc32>`
          - :ref:`USB-2001-TC <2001tc>`
          - :ref:`USB-3103 <3100>`
          - :ref:`USB-PDISO8 <pdiso>`

        * - :ref:`USB-1024HLS <1024>`
          - :ref:`USB-201 <200>`
          - :ref:`USB-3104 <3100>`
          - :ref:`USB-PDISO8/40 <pdiso>`

        * - :ref:`USB-1024LS <1024>`
          - :ref:`USB-202 <200>`
          - :ref:`USB-3105 <3100>`
          - :ref:`USB-QUAD08 <quad08>`

        * - :ref:`USB-1208FS-PLUS <1208fsplus>`
          - :ref:`USB-2020 <2020>`
          - :ref:`USB-3106 <3100>`
          - :ref:`USB-SSR08 <ssr>`

        * - :ref:`USB-1208HS <1208hs>`
          - :ref:`USB-204 <200>`
          - :ref:`USB-3110 <3100>`
          - :ref:`USB-SSR24 <ssr>`

        * - :ref:`USB-1208HS-2AO <1208hs>`
          - :ref:`USB-205 <200>`
          - :ref:`USB-3112 <3100>`
          - :ref:`USB-TC <tc>`

        * - :ref:`USB-1208HS-4AO <1208hs>`
          - :ref:`USB-2408 <2408>`
          - :ref:`USB-3114 <3100>`
          - :ref:`USB-TC-AI <tcai>`

        * - :ref:`USB-1408FS-PLUS <1408fsplus>`
          - :ref:`USB-2408-2AO <2408>`
          - :ref:`USB-CTR04 <ctr0x>`
          - :ref:`USB-TEMP <temp>`

        * - :ref:`USB-1608FS-PLUS <1608fsplus>`
          - :ref:`USB-2416 <2416>`
          - :ref:`USB-CTR08 <ctr0x>`
          - :ref:`USB-TEMP-AI <tempai>`

        * - :ref:`USB-1608G <1608g>`
          - :ref:`USB-2416-4AO <2416>`
          - :ref:`USB-DIO24/37 <dio24>`
          -


    .. list-table:: Data Translation devices supported by UL for Linux
        :widths: 20 20 20 20 20
        :header-rows: 0

        * - :ref:`DT9837A <dt9837>`
          - :ref:`DT9837B <dt9837>`
          - :ref:`DT9837C <dt9837>`
          -
          -

....


.. include:: hwref.inc







