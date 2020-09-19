VAR intnum time_int;
VAR num override;
...
!setup interupt
CONNECT time_int WITH speed_refresh;
ITimer 0.1, time_int; !is used to order and enable a timed interrupt
ISleep time_int; !deactivate an individual interrupt temporarily.
!During the deactivation time any generated interrupts of the specified type are discarded
!without any trap execution


...
MoveL p1, v100, fine, tool2;

! Read current speed override set from FlexPendant
override := CSpeedOverride (\CTask);

!IWatch: activate an interrupt which was previously ordered but was deactivated with ISleep
IWatch time_int; 

MoveL p2, v100, fine, tool2;
IDelete time_int; ! Cancel the interupt

! Reset to FlexPendant old speed override
WaitTime 0.5;
SpeedRefresh override;
...


! the trap routine
TRAP speed_refresh
VAR speed_corr;
! Analog input signal value from sensor, value 0 ... 10
speed_corr := (ai_sensor * 10);
SpeedRefresh speed_corr;
ERROR
IF ERRNO = ERR_SPEED_REFRESH_LIM THEN
    IF speed_corr > 100 speed_corr := 100;
    IF speed_corr < 0 speed_corr := 0;
    RETRY;
ENDIF
ENDTRAP
