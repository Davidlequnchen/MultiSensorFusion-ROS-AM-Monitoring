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

!////Laser_On and Laser_Off should be set at process beginning and the End
!////It is prepare the laser ready but does not start the laser
PROC Laser_On()
	SetDo doLaserReq,1;
	Set doLaserOn;
	Set DoBeam1;
	Set DoAnologOn;
	!SetAO aoPower, 1;
	TpWrite "Wait for laser ready signal";
	WaitDI diLaserReady,1;
	WaitTime 0.5;
ENDPROC

PROC Laser_Off()
	SetAO aoPower,0;
	Reset DoAnologOn;
	Reset DoBeam1;
	Reset doLaserOn;
	WaitDI diLaserReady,0;
	SetDo doLaserReq,0;
ENDPROC

!/// Laser_Start and Laser_End funtions are for start and end the laser during the process.
PROC Laser_Start()
	TpWrite "Laser started";
	SetDo doProgramStart,1;
ENDPROC

PROC Laser_End()
	SetDo doProgramStart,0;
	TpWrite "Laser finished";
ENDPROC


!//////////////////////////
!/////main funtion start////

PROC Motion_command()
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
	IPers cancel_motion, intr_cancel_motion;


	!IDelete intr_configure;
	!CONNECT intr_configure WITH new_configure_handler;
	!IPers laser_conf, intr_configure;

	!IDelete intr_configure_feeder;
	!CONNECT intr_configure_feeder WITH new_configure_handler;
	!IPers feeder_conf, intr_configure_feeder;

	WHILE path_finished = FALSE DO
		! pAct := CRobT(\Tool:=currentTool \WObj:=currentWObj);
		pAct := CRobT(\Tool:=currentTool \WObj:=currentWobj);
		!Check for new motion command
		IF n_cartesian_command <> n_cartesian_motion THEN
			TEST command_type{n_cartesian_motion}
				CASE 1: !Cartesian linear move
					moveCompleted := FALSE;
					cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
					MoveL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj ;
					moveCompleted := TRUE;

				CASE 10: !Cartesian joint move
					moveCompleted := FALSE;
					cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
					MoveJ cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj ;
					moveCompleted := TRUE;

				CASE 121: !External axis move
					moveCompleted := FALSE;
					pActB := CRobT(\Tool:=currentTool \WObj:=currentWobj);
					pActB.extax.eax_b := extAxisMove{n_cartesian_motion};
					MOVEJ pActB, cartesian_speed{n_cartesian_motion}, currentZone, currentTool \WObj:=currentWobj;
					!IndAMove STN1, 1\ToAbsNum:=cartesianTarget{n_cartesian_motion}.extax.eax_b, cartesian_speed{n_cartesian_motion}.v_reax;
					!IndReset STN1, 1;
					moveCompleted := TRUE;

				CASE 122: !External axis move
					moveCompleted := FALSE;
					pActC := CRobT(\Tool:=currentTool \WObj:=currentWobj);
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
					Laser_On;

				CASE 1000102: !Laser ready Fase
					Laser_Off;

				CASE 1000103: !Laser start (laser emission start)
					Laser_Start;

				CASE 1000104: !Laser end
					Laser_End;


				CASE 20201: !set JOSN motion finish -- path_finished is true 
					path_finished := TRUE;

				CASE 20202: !set JOSN motion start -- path_finished is false 
					path_finished := FALSE;

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
	Laser_Off;
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





ENDMODULE
