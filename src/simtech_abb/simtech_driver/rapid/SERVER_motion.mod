MODULE SERVER_motion


LOCAL CONST zonedata DEFAULT_CORNER_DIST := z10;
LOCAL VAR intnum intr_cancel_motion;
LOCAL VAR intnum intr_configure;
LOCAL VAR intnum intr_configure_feeder;
LOCAL VAR robtarget pAct;
LOCAL VAR robtarget pActB;
LOCAL VAR robtarget pActC;
!//Control of the laser
VAR triggdata laser_ON;
VAR triggdata laser_OFF;
VAR triggdata wireON_tps;
VAR triggdata wireOFF_tps;

PROC Initialize()
	IF laser_conf = 0 THEN
		SetRofin;
	ELSE
		SetTrumpf;
	ENDIF
	IF feeder_conf = 1 THEN
		SetWire;
	ENDIF
	n_cartesian_command := 1;
	n_cartesian_motion := 1;
	!ActUnit STN1;
	!Find the current external axis values so they don't move when we start
	!jointsTarget := CJointT();
	!externalAxis := jointsTarget.extax;
ENDPROC

PROC SetRofin()
		TriggIO laser_ON, 0\DOp:=Do_FL_RayoLaserEnc, 1; !TdoPStartStat
		TriggIO laser_OFF, 0\DOp:=Do_FL_RayoLaserEnc, 0; !TdoPStartStat
		TriggIO wireON_tps, 0\DOp:=Do_FL_RayoLaserEnc, 1; !doTPSWireF
		TriggIO wireOFF_tps, 0\DOp:=Do_FL_RayoLaserEnc, 0; !doTPSWireF
ENDPROC

PROC SetTrumpf()
		TriggIO laser_ON, 0\DOp:=TdoPStartStat, 1; !TdoPStartStat
		TriggIO laser_OFF, 0\DOp:=TdoPStartStat, 0; !TdoPStartStat
		TriggIO wireON_tps, 0\DOp:=TdoPStartStat, 1; !TdoPStartStat
		TriggIO wireOFF_tps, 0\DOp:=TdoPStartStat, 0; !TdoPStartStat
ENDPROC

PROC SetWire()
		TriggIO wireON_tps, 0\DOp:=doTPSWireF, 1; !doTPSWireF
		TriggIO wireOFF_tps, 0\DOp:=doTPSWireF, 0; !doTPSWireF
ENDPROC

PROC main()
    VAR jointtarget target;
    VAR zonedata stop_mode;

    !//Motion configuration
    ConfL \Off;
    SingArea \Wrist;
    moveCompleted:= TRUE;

    !//Initialization of WorkObject, Tool, Speed, Zone and Laser
    Initialize;

    ! Set up interrupt
	IDelete intr_cancel_motion;
	CONNECT intr_cancel_motion WITH new_cancel_motion_handler;
	IPers cancel_motion, intr_cancel_motion;

	IDelete intr_configure;
	CONNECT intr_configure WITH new_configure_handler;
	IPers laser_conf, intr_configure;

	IDelete intr_configure_feeder;
	CONNECT intr_configure_feeder WITH new_configure_handler;
	IPers feeder_conf, intr_configure_feeder;

    WHILE TRUE DO
      pAct := CRobT(\Tool:=currentTool \WObj:=currentWObj);
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

            CASE 110: !Trigger linear OFF
              moveCompleted := FALSE;
              cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              TriggL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, laser_OFF \T2:=wireOFF_tps, currentZone, currentTool \WObj:=currentWobj ;
							moveCompleted := TRUE;

            CASE 111: !Trigger linear ON
              moveCompleted := FALSE;
              cartesianTarget{n_cartesian_motion}.extax := pAct.extax;
              TriggL cartesianTarget{n_cartesian_motion}, cartesian_speed{n_cartesian_motion}, laser_ON \T2:=wireON_tps, currentZone, currentTool \WObj:=currentWobj ;
							moveCompleted := TRUE;

			CASE 930: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI Di_FL_EstadBy, 1;
				ELSE
					WaitDI Di_FL_EstadBy, 0;
				ENDIF

			CASE 931: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI Di_FL_ErrorLaserApagado, 1;
				ELSE
					WaitDI Di_FL_ErrorLaserApagado, 0;
				ENDIF

			CASE 932: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI TdiExtActiv, 1;
				ELSE
					WaitDI TdiExtActiv, 0;
				ENDIF

			CASE 933: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI TdiLaserOn, 1;
				ELSE
					WaitDI TdiLaserOn, 0;
				ENDIF

			CASE 934: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI TdiLaserAsig, 1;
				ELSE
					WaitDI TdiLaserAsig, 0;
				ENDIF

			CASE 935: !WaitDI
				IF commandSetDO{n_cartesian_motion} THEN
					WaitDI TdiLaserReady, 1;
				ELSE
					WaitDI TdiLaserReady, 0;
				ENDIF

			CASE 94: !Wait time
				WaitTime numBufferAux{n_cartesian_motion};

			CASE 950: !
				SetGO GO_FL_Programa, numBufferAux{n_cartesian_motion};

			CASE 951: !
				SetGO GO_FL_PotenciaLaser1, numBufferAux{n_cartesian_motion};

			CASE 952: !
				SetGO GoTPSJobL, numBufferAux{n_cartesian_motion};

			CASE 953: !
				SetGO TGOPROGRAM_No, numBufferAux{n_cartesian_motion};

			CASE 960: !
				SetAO AoGTV_ExternDisk, numBufferAux{n_cartesian_motion};

			CASE 961: !
				SetAO AoGTV_ExternMassflow, numBufferAux{n_cartesian_motion};

			CASE 970: !Set DO gtv START
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doGTV_StartExtern, 1;
				ELSE
					SetDO doGTV_StartExtern, 0;
				ENDIF

			CASE 971: !Set DO gtv STOP
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doGTV_Stop, 1;
				ELSE
					SetDO doGTV_Stop, 0;
				ENDIF

			CASE 972: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO Do_FL_RedENC, 1;
				ELSE
					SetDO Do_FL_RedENC, 0;
				ENDIF

			CASE 973: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO Do_FL_StandByEnc, 1;
				ELSE
					SetDO Do_FL_StandByEnc, 0;
				ENDIF

			CASE 974: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO DoWeldGas, 1;
				ELSE
					SetDO DoWeldGas, 0;
				ENDIF

			CASE 975: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO DoRootGas, 1;
				ELSE
					SetDO DoRootGas, 0;
				ENDIF

			CASE 976: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO DoCossJet, 1;
				ELSE
					SetDO DoCossJet, 0;
				ENDIF

			CASE 977: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSReset, 1;
				ELSE
					SetDO doTPSReset, 0;
				ENDIF

			CASE 978: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSReady, 1;
				ELSE
					SetDO doTPSReady, 0;
				ENDIF

			CASE 979: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSOP0, 1;
				ELSE
					SetDO doTPSOP0, 0;
				ENDIF

			CASE 9710: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSOP1, 1;
				ELSE
					SetDO doTPSOP1, 0;
				ENDIF

			CASE 9711: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSOP2, 1;
				ELSE
					SetDO doTPSOP2, 0;
				ENDIF

			CASE 9712: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSWireF, 1;
				ELSE
					SetDO doTPSWireF, 0;
				ENDIF

			CASE 9713: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO doTPSWeld, 1;
				ELSE
					SetDO doTPSWeld, 0;
				ENDIF

			CASE 9714: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO TdoLaserOn, 1;
				ELSE
					SetDO TdoLaserOn, 0;
				ENDIF

			CASE 9715: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO TdoExtActiv, 1;
				ELSE
					SetDO TdoExtActiv, 0;
				ENDIF

			CASE 9716: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO TdoStandBy, 1;
				ELSE
					SetDO TdoStandBy, 0;
				ENDIF

			CASE 9717: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO TdoActLaser, 1;
				ELSE
					SetDO TdoActLaser, 0;
				ENDIF

			CASE 9718: !Set DO
				IF commandSetDO{n_cartesian_motion} THEN
					SetDO TdoPStartStat, 1;
				ELSE
					SetDO TdoPStartStat, 0;
				ENDIF

            DEFAULT:
				TPWrite "SERVER_motion: Illegal instruction code: ", \Num:=command_type{n_cartesian_motion};
          ENDTEST
          n_cartesian_motion := n_cartesian_motion + 1;
          IF n_cartesian_motion > 49
            n_cartesian_motion := 1;
        ENDIF
        WaitTime 0.1;  ! Throttle loop while waiting for new command
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
	SetDO Do_FL_RayoLaserEnc, 0;
	SetDO TdoPStartStat, 0;
	SetDO doGTV_StartExtern, 0;
	SetDO doGTV_Stop, 0;
	SetDO doTPSWireF, 0;
	!SetDO Do_FL_RedENC, 0;
	!SetDO Do_FL_StandByEnc, 0;
	!SetDO TdoExtActiv, 0;
	!SetDO TdoLaserOn, 0;
	!SetDO TdoStandBy, 0;
	!SetDO TdoActLaser, 0;
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

LOCAL TRAP new_configure_handler
	IF laser_conf = 0 THEN
		SetRofin;
	ELSEIF laser_conf = 1 THEN
		SetTrumpf;
	ELSE
		TPWrite "MOTION: Invalid laser configure number: ", \Num:=laser_conf;
	ENDIF
	ERROR
		ErrWrite \W, "Configuring error", "Error configuring laser.";
ENDTRAP

LOCAL TRAP new_feeder_configure_handler
	IF feeder_conf = 1 THEN
		SetWire;
	ENDIF
	ERROR
		ErrWrite \W, "Configuring error", "Error configuring feeder.";
ENDTRAP

ENDMODULE
