MODULE SERVER_motion


LOCAL CONST zonedata DEFAULT_CORNER_DIST := z10;
LOCAL VAR intnum intr_cancel_motion;
LOCAL VAR intnum intr_configure;
LOCAL VAR intnum intr_configure_feeder;
LOCAL VAR robtarget pAct;
LOCAL VAR robtarget pActB;
LOCAL VAR robtarget pActC;
!//Control of the laser
!VAR triggdata laser_ON;
!VAR triggdata laser_OFF;
!VAR triggdata wireON_tps;
!VAR triggdata wireOFF_tps;
VAR jointtarget jointsTarget;

!//for velocityRefresh
VAR intnum time_int;
VAR num override;
!VAR num speed_corr; // This variable will be defined in common.sys
!////////////////////local variables


!/////////////////////////////////local process


PROC Initialize()
	Reset doLaserReq;
	Reset doLaserOn;
	Reset DoBeam1;
	Reset DoAnologOn;
	!SetAO aoPower,0;
	Reset doProgramStart;
	!IF laser_conf = 0 THEN
		!SetIpg;
	!ELSE
		!SetTrumpf;
	!ENDIF
	!IF feeder_conf = 1 THEN
		!SetWire;
	!ENDIF

	n_cartesian_command := 1;
	n_cartesian_motion := 1;
	!ActUnit STN1;
	!Find the current external axis values so they don't move when we start
	jointsTarget := CJointT();
	externalAxis := jointsTarget.extax;
ENDPROC

!////LaserOn and LaserOff should be set at process beginning and the End
!////It is prepare the laser ready but does not start the laser
PROC LaserOn()
	SetDo doLaserReq,1;
	Set doLaserOn;
	Set DoBeam1;
	Set DoAnologOn;
	!SetAO aoPower, 1;
	TpWrite "Wait for laser ready signal";
	WaitDI diLaserReady,1;
	WaitTime 0.5;
ENDPROC

PROC LaserOff()
	SetAO aoPower,0;
	Reset DoAnologOn;
	Reset DoBeam1;
	Reset doLaserOn;
	WaitDI diLaserReady,0;
	SetDo doLaserReq,0;
ENDPROC

!/// LaserStart and LaserEnd funtions are for start and end the laser during the process.
PROC LaserStart()
	TpWrite "Laser started";
	SetDo doProgramStart,1;
ENDPROC

PROC LaserEnd()
	SetDo doProgramStart,0;
	TpWrite "Laser finished";
ENDPROC


!//////////////////////////
!/////main funtion start////

PROC main()
    !VAR jointtarget target;
    !VAR zonedata stop_mode;

    !//Motion configuration
    ConfJ\On;
    ConfL\Off;
    SingArea \Wrist;
    moveCompleted:= TRUE;

    !//Initialization of WorkObject, Tool, Speed, Zone and Laser
    Initialize;

    ! Set up interrupt
	IDelete intr_cancel_motion;
	CONNECT intr_cancel_motion WITH new_cancel_motion_handler;
	IPers cancel_motion, intr_cancel_motion; !// Interrupt at value change of a persistent variable


	!setup interupt for velocity refresh
	IDelete time_int;
	CONNECT time_int WITH speed_refresh;
	ITimer 0.1, time_int; !//is used to order and enable a timed interrupt
	ISleep time_int; !//deactivate an individual interrupt temporarily.
	!//During the deactivation time any generated interrupts of the specified type are discarded
	!//without any trap execution


	!IDelete intr_configure;
	!CONNECT intr_configure WITH new_configure_handler;
	!IPers laser_conf, intr_configure;
	!Orders an interrupt which is to occur each time the persistent variable laser_conf is changed. 

	!IDelete intr_configure_feeder;
	!CONNECT intr_configure_feeder WITH new_configure_handler;
	!IPers feeder_conf, intr_configure_feeder;

    WHILE TRUE DO
      pAct := CRobT(\Tool:=currentTool \WObj:=currentWObj);
        !Check for new motion command
      IF n_cartesian_command <> n_cartesian_motion THEN
          TEST command_type{n_cartesian_motion}
            CASE 1: !Cartesian linear move
			  ! //Read current speed override set from FlexPendant
              !override := CSpeedOverride (\CTask);
			  !//IWatch: activate an interrupt which was previously ordered but was deactivated with ISleep
              IWatch time_int;

              moveCompleted := FALSE;
              cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              MoveL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj ;
              moveCompleted := TRUE;

              ISleep time_int;
			  !IDelete time_int; !//Cancel the interupt
			  ! //Reset to FlexPendant old speed override
			  !WaitTime 0.5;
			  !SpeedRefresh override;

            CASE 10: !Cartesian joint move
              moveCompleted := FALSE;
              cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              MoveJ cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj ;
              moveCompleted := TRUE;

            CASE 121: !External axis move
              moveCompleted := FALSE;
              pActB := CRobT(\Tool:=currentTool \WObj:=currentWObj);
              pActB.extax.eax_b := extAxisMove{n_cartesian_motion};
              MOVEJ pActB, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj;
              !IndAMove STN1, 1\ToAbsNum:=cartesianTarget{n_cartesian_motion}.extax.eax_b, cartesian_speed{n_cartesian_motion}.v_reax;
              !IndReset STN1, 1;
							moveCompleted := TRUE;

			CASE 122: !External axis move
				moveCompleted := FALSE;
				pActC := CRobT(\Tool:=currentTool \WObj:=currentWObj);
							pActC.extax.eax_c := extAxisMove{n_cartesian_motion};
							MOVEJ pActC, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj;
							!IndAMove STN1, 2\ToAbsNum:=cartesianTarget{n_cartesian_motion}.extax.eax_b, cartesian_speed{n_cartesian_motion}.v_reax;
							!IndReset STN1, 2;
							moveCompleted := TRUE;

            !CASE 110: !Trigger linear OFF
              !moveCompleted := FALSE;
              !cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              !TriggL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, laser_OFF \T2:=wireOFF_tps, currentZone, currentTool \WObj:=currentWobj ;
							!moveCompleted := TRUE;

            !CASE 111: !Trigger linear ON
              !moveCompleted := FALSE;
              !cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              !TriggL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, laser_ON \T2:=wireON_tps, currentZone, currentTool \WObj:=currentWobj ;
							!moveCompleted := TRUE;

			CASE 94: !Wait time
				WaitTime numBufferAux{n_cartesian_motion};

			CASE 1000101: !Laser Ready true
				LaserOn;

			CASE 1000102: !Laser ready Fase
				LaserOff;

			CASE 1000103: !Laser start (laser emission start)
				LaserStart;

			CASE 1000104: !Laser end
				LaserEnd;

            DEFAULT:
				TPWrite "SERVER_motion: Illegal instruction code: ", \Num:=command_type{n_cartesian_motion};
		  ENDTEST
		  n_cartesian_motion := n_cartesian_motion + 1;
		IF n_cartesian_motion > 49
		    n_cartesian_motion := 1;
		ENDIF
        WaitTime 0.01;  ! Throttle loop while waiting for new command
    ENDWHILE
ERROR
	TEST ERRNO
			CASE ERR_NORUNUNIT:
					TPWrite "MOTION: No contact with unit.";
					TRYNEXT;
			DEFAULT:
					ErrWrite \W, "Motion Error", "Error executing motion.  Aborting trajectory.";
					abort_trajectory;
	ENDTEST
ENDPROC

LOCAL PROC abort_trajectory()
    clear_path;
    ExitCycle;  ! restart program
ENDPROC

LOCAL PROC clear_path()
    IF ( NOT (IsStopMoveAct(\FromMoveTask) OR IsStopMoveAct(\FromNonMoveTask)) )
        StopMove;          ! stop any active motions
    StartMove;             ! re-enable motions
ENDPROC

LOCAL TRAP new_cancel_motion_handler
	IF (NOT cancel_motion) RETURN;
	! Reset
	cancel_motion := FALSE;
	n_cartesian_motion := n_cartesian_command;
	LaserOff;
	abort_trajectory;
	ERROR
		TEST ERRNO
				CASE ERR_NORUNUNIT:
						TRYNEXT;
				DEFAULT:
						ErrWrite \W, "Motion Error", "Error executing motion.  Aborting trajectory.";
						abort_trajectory;
		ENDTEST
ENDTRAP


! the trap routine for speed refresh
LOCAL TRAP speed_refresh
	! speed_corr := 10;
	! // speed_corr is obtained through pid controller, it will be updated in SPEED_refresh.mod
	SpeedRefresh speed_corr;
	ERROR
	IF ERRNO = ERR_SPEED_REFRESH_LIM THEN
    	IF speed_corr > 100 speed_corr := 100;
    	IF speed_corr < 0 speed_corr := 0;
    	RETRY;
	ENDIF
ENDTRAP

ENDMODULE
