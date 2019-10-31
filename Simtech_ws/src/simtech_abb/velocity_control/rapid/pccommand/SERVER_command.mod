MODULE SERVER_command

!////////////////
!This SERVER_command module handles command send from the PC software,
!It create a listening socket(server socket) to keep listening to the command.
!After receiving the command, it will issue them to the SERER_motion module.
!The SERVER_motion will handle the execution of the command.
!////////////////



!//GLOBAL VARIABLES
!//PC communication
VAR socketdev clientSocket;
VAR socketdev serverSocket;
VAR num instructionCode;
VAR num params{10};
VAR num nParams;

!//Correct Instruction Execution and possible return values
VAR num ok;
CONST num SERVER_BAD_MSG :=  0;
CONST num SERVER_OK := 1;
VAR bool connected;          !//Client connected
VAR bool reconnected;        !//Drop and reconnection happened during serving a command



!//LOCAL Variables/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


CONST num serverPort:= 11000;



!////////////////
!LOCAL METHODS
!////////////////

!//Method to parse the message received from a PC
!// If correct message, loads values on:
!// - instructionCode.
!// - nParams: Number of received parameters.
!// - params{nParams}: Vector of received params.
PROC ParseMsg(string msg)
    !//Local variables
    VAR bool auxOk;
    VAR num ind:=1;
    VAR num newInd;
    VAR num length;
    VAR num indParam:=1;
    VAR string subString;
    VAR bool end := FALSE;

    !//Find the end character
    !// meaning: from the first character in the msg to start searching "#", return the position of '#'
    length := StrMatch(msg,1,"#");  
    IF length > StrLen(msg) THEN
        !//Corrupt message
        nParams := -1;
    ELSE
        !//Read Instruction code
        newInd := StrMatch(msg,ind," ") + 1;
        subString := StrPart(msg,ind,newInd - ind - 1);
        !//the auxOk is given true and the value from subString is given to instructionCode
        auxOk:= StrToVal(subString, instructionCode);
        IF auxOk = FALSE THEN
            !//Impossible to read instruction code
            nParams := -1;
        ELSE
            ind := newInd;
            !//Read all instruction parameters (maximum of 8)
            WHILE end = FALSE DO
                newInd := StrMatch(msg,ind," ") + 1;
                IF newInd > length THEN
                    end := TRUE;
                ELSE
                    subString := StrPart(msg,ind,newInd - ind - 1);
                    auxOk := StrToVal(subString, params{indParam});
                    indParam := indParam + 1;
                    ind := newInd;
                ENDIF
            ENDWHILE
            nParams:= indParam - 1;
        ENDIF
    ENDIF
ENDPROC


!//Handshake between server and client:
!// - Creates socket.
!// - Waits for incoming TCP connection.
PROC ServerCreateAndConnect(num port)
	VAR string clientIP;
	VAR num time_val := WAIT_MAX;  ! default to wait-forever

	IF (SocketGetStatus(serverSocket) = SOCKET_CLOSED) SocketCreate serverSocket;
	IF (SocketGetStatus(serverSocket) = SOCKET_CREATED) SocketBind serverSocket, "192.168.125.1", port;
	IF (SocketGetStatus(serverSocket) = SOCKET_BOUND) SocketListen serverSocket;
	TPWrite "SERVER_Command: SERVER waiting for incomming connections ...";

	!IF Present(wait_time) time_val := wait_time;

  IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
  WaitUntil (SocketGetStatus(clientSocket) = SOCKET_CLOSED);

    SocketAccept serverSocket, clientSocket, \ClientAddress:=clientIP, \Time:=time_val;
	TPWrite "SERVER_Command: Connected to IP " + clientIP;
ENDPROC




PROC FullReset ()
    IF cancel_motion = TRUE
      cancel_motion := FALSE;
    n_cartesian_command := n_cartesian_motion;
    cancel_motion := TRUE;
    !SetDO Do_FL_RayoLaserEnc, 0;
    !SetDO TdoPStartStat, 0;
    !SetDO Do_FL_StandByEnc, 0;
    !SetDO Do_FL_RedENC, 0;
    !SetDO doGTV_StartExtern, 0;
    !SetDO DoWeldGas, 0;
    !SetDO DoRootGas, 0;
    !SetDO DoCossJet, 0;
    !SetDO doGTV_Stop, 1;
    !SetDO doTPSWireF, 0;
    !SetDO doTPSWeld, 0;
    ERROR (LONG_JMP_ALL_ERR)
        TEST ERRNO
            CASE ERR_NORUNUNIT:
                TRYNEXT;
        ENDTEST
ENDPROC

PROC Reconnect ()
    connected:=FALSE;
    !//Closing the server
    SocketClose clientSocket;
    SocketClose serverSocket;
    !//Reinitiate the server
    ServerCreateAndConnect serverPort;
    reconnected:= FALSE;
    connected:= TRUE;
ENDPROC
!///////////////////////////
!//SERVER: Main procedure //
!///////////////////////////
PROC main()
    !//Local variables
    VAR string receivedString;   !//Received string
    VAR string sendString;       !//Reply string
    VAR string addString;        !//String to add to the reply.
    VAR robtarget cartesianPose;
    VAR jointtarget jointsPose;
	  VAR robtarget singleCartesianTarget;

    !//Socket connection
    connected:=FALSE;
    ServerCreateAndConnect serverPort;
    connected:=TRUE;
	  cancel_motion := FALSE;

    !//Server Loop
    WHILE TRUE DO
        !//Initialization of program flow variables
        ok:=SERVER_OK;              !//Correctness of executed instruction.
        reconnected:=FALSE;         !//Has communication dropped after receiving a command?
        addString := "";

        !//Wait for a command
        !// store the received data into the variable receivedString within the time limit
        SocketReceive clientSocket \Str:=receivedString \Time:=WAIT_MAX;
        ParseMsg receivedString;

        !//Execution of the command
        TEST instructionCode
            CASE 0: !Ping
                IF nParams = 0 THEN
                    ok := SERVER_OK;
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 1: !Cartesian Move
                IF nParams = 7 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 1;
                      !// set the cartesian command in the format of [x,y,z],[w,p,q,r]
                      cartesianTarget{n_cartesian_command} := [[params{1},params{2},params{3}],
                                         [params{4},params{5},params{6},params{7}],
                                         [0,0,0,0],
                                         externalAxis];
                      cartesian_speed{n_cartesian_command} := currentSpeed;
                      cartesianTriggSet{n_cartesian_command} := FALSE;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      TPWrite "Motion command complete";
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 3: !Get Cartesian Coordinates (with current tool and workobject)
                IF nParams = 0 THEN
                    !// CRobT - Reads the current position (robtarget) data
                    cartesianPose := CRobT(\Tool:=currentTool \WObj:=currentWObj);
                    !// NumToStr - converts numerical value to string. 2 means retain 2 decimals.
                    addString := NumToStr(cartesianPose.trans.x,2) + " ";
                    addString := addString + NumToStr(cartesianPose.trans.y,2) + " ";
                    addString := addString + NumToStr(cartesianPose.trans.z,2) + " ";
                    addString := addString + NumToStr(cartesianPose.rot.q1,3) + " ";
                    addString := addString + NumToStr(cartesianPose.rot.q2,3) + " ";
                    addString := addString + NumToStr(cartesianPose.rot.q3,3) + " ";
                    addString := addString + NumToStr(cartesianPose.rot.q4,3); !End of string
                    ok := SERVER_OK;
                ELSE
                    ok :=SERVER_BAD_MSG;
                ENDIF

            CASE 4: !Get Joint Coordinates
                IF nParams = 0 THEN
                    jointsPose := CJointT();
                    addString := NumToStr(jointsPose.robax.rax_1,5) + " ";
                    addString := addString + NumToStr(jointsPose.robax.rax_2,5) + " ";
                    addString := addString + NumToStr(jointsPose.robax.rax_3,5) + " ";
                    addString := addString + NumToStr(jointsPose.robax.rax_4,5) + " ";
                    addString := addString + NumToStr(jointsPose.robax.rax_5,5) + " ";
                    addString := addString + NumToStr(jointsPose.robax.rax_6,5); !End of string
                    ok := SERVER_OK;
                ELSE
                    ok:=SERVER_BAD_MSG;
                ENDIF

            CASE 6: !Set Tool
                IF nParams = 7 THEN
		   			        WHILE (frameMutex) DO
		        		        WaitTime .01; !// If the frame is being used by logger, wait here
		   			        ENDWHILE
					        frameMutex:= TRUE;
                    currentTool.tframe.trans.x:=params{1};
                    currentTool.tframe.trans.y:=params{2};
                    currentTool.tframe.trans.z:=params{3};
                    currentTool.tframe.rot.q1:=params{4};
                    currentTool.tframe.rot.q2:=params{5};
                    currentTool.tframe.rot.q3:=params{6};
                    currentTool.tframe.rot.q4:=params{7};
                    ok := SERVER_OK;
		    		      frameMutex:= FALSE;
					        TPWrite "Tool set";
                ELSE
                    ok:=SERVER_BAD_MSG;
                ENDIF

            CASE 7: !Set Work Object
                IF nParams = 7 THEN
                    currentWobj.oframe.trans.x:=params{1};
                    currentWobj.oframe.trans.y:=params{2};
                    currentWobj.oframe.trans.z:=params{3};
                    currentWobj.oframe.rot.q1:=params{4};
                    currentWobj.oframe.rot.q2:=params{5};
                    currentWobj.oframe.rot.q3:=params{6};
                    currentWobj.oframe.rot.q4:=params{7};
                    ok := SERVER_OK;
					        TPWrite "Work Object Set";
                ELSE
                    ok:=SERVER_BAD_MSG;
                ENDIF

            CASE 8: !Set Speed of the Robot
                IF nParams = 4 THEN
                    currentSpeed.v_tcp:=params{1};
                    currentSpeed.v_ori:=params{2};
                    currentSpeed.v_leax:=params{3};
                    currentSpeed.v_reax:=params{4};
					          TPWrite "Speed Set: ", \Num:=currentSpeed.v_tcp;
                    ok := SERVER_OK;
                ELSEIF nParams = 2 THEN
					           currentSpeed.v_tcp:=params{1};
					           currentSpeed.v_ori:=params{2};
					           TPWrite "Speed Set: ", \Num:=currentSpeed.v_tcp;
					          ok := SERVER_OK;
				        ELSE
                    ok:=SERVER_BAD_MSG;
                ENDIF

            CASE 9: !Set zone data
                IF nParams = 4 THEN
                    IF params{1}=1 THEN
                        currentZone.finep := TRUE;
                        currentZone.pzone_tcp := 0.0;
                        currentZone.pzone_ori := 0.0;
                        currentZone.zone_ori := 0.0;
                    ELSE
                        currentZone.finep := FALSE;
                        currentZone.pzone_tcp := params{2};
                        currentZone.pzone_ori := params{3};
                        currentZone.zone_ori := params{4};
                    ENDIF
                    ok := SERVER_OK;
                ELSE
                    ok:=SERVER_BAD_MSG;
                ENDIF
            
            CASE 009: ! set zone data with choice of z0(0) or fine(1)
                IF nParams = 1 THEN
                    IF params{1}=1 THEN
                        currentZone := fine;
                    ELSE 
                        currentZone := z0;
                    ENDIF
                    ok := SERVER_OK;
                ELSE 
                    ok:=SERVER_BAD_MSG;
                ENDIF


            CASE 1000101: !set Laser ready True            
                IF nParams = 0 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 1000101;
                      ! set laser ready
        
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      TPWrite "Laser ready is On";
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 1000102: !set Laser ready False            
                IF nParams = 0 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 1000102;
                      ! set laser ready flase
        
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      TPWrite "Laser ready is Off";
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 1000103: !set Laser emission start            
                IF nParams = 0 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 1000103;
                      ! set laser ready
        
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      TPWrite "Laser emission start";
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 1000104: !set Laser emission end            
                IF nParams = 0 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 1000104;
                      ! set laser ready
        
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      TPWrite "Laser emission end";
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF
            


			      CASE 10: !Joint Move to Pos
                IF nParams = 7 THEN
                    ok := SERVER_OK;
					          IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      command_type{n_cartesian_command} := 10;
                      cartesianTarget{n_cartesian_command} := [[params{1},params{2},params{3}],
                                         [params{4},params{5},params{6},params{7}],
                                         [0,0,0,0],
                                         externalAxis];
                      cartesian_speed{n_cartesian_command} := currentSpeed;
                      cartesianTriggSet{n_cartesian_command} := FALSE;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 11: !Trigger Move linear
                IF nParams = 8 THEN
                    ok := SERVER_OK;
          					IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                      IF params{8} < 1 THEN
                        command_type{n_cartesian_command} := 110;
                      ELSE
                        command_type{n_cartesian_command} := 111;
  										ENDIF
                      cartesianTarget{n_cartesian_command} := [[params{1},params{2},params{3}],
                                         [params{4},params{5},params{6},params{7}],
                                         [0,0,0,0],
                                         externalAxis];
                      cartesian_speed{n_cartesian_command} := currentSpeed;
                      cartesianTriggSet{n_cartesian_command} := FALSE;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                      addString := "BUFFER_OK";
                    ELSE
                      addString := "BUFFER_FULL";
                    ENDIF
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

              CASE 12: !Move external axis
        				IF nParams = 3 THEN
        					ok := SERVER_OK;
        					IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
          					currentSpeed.v_reax := params{3};
          					cartesian_speed{n_cartesian_command} := currentSpeed;
          					IF params{1} = 1 THEN
          					  command_type{n_cartesian_command} := 121;
          					  extAxisMove{n_cartesian_command} := params{2};
          					ENDIF
          					IF params{1} = 2 THEN
  					          command_type{n_cartesian_command} := 122;
  						        extAxisMove{n_cartesian_command} := params{2};
          					ENDIF
          					n_cartesian_command := n_cartesian_command + 1;
                    IF n_cartesian_command > 49
                      n_cartesian_command := 1;
                    addString := "BUFFER_OK";
                  ELSE
                    addString := "BUFFER_FULL";
                  ENDIF
                  ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF

            CASE 93: !Wait for a digital input
              IF nParams = 2 THEN
                IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                  TEST params{1}
                    CASE 0:
                      command_type{n_cartesian_command} := 930;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 1:
                      command_type{n_cartesian_command} := 931;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 2:
                      command_type{n_cartesian_command} := 932;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 3:
                      command_type{n_cartesian_command} := 933;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 4:
                      command_type{n_cartesian_command} := 934;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 5:
                      command_type{n_cartesian_command} := 935;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    DEFAULT:
                      TPWrite "SERVER: Illegal wait code DI =", \Num:=params{1};
                      ok := SERVER_BAD_MSG;
                  ENDTEST
                  addString := "BUFFER_OK";
                ELSE
                  addString := "BUFFER_FULL";
                ENDIF
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF

            CASE 94: !Wait time between moves
              IF nParams = 1 THEN
                IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                  command_type{n_cartesian_command} := 94;
                  numBufferAux{n_cartesian_command} := params{1};
                  n_cartesian_command := n_cartesian_command + 1;
                  IF n_cartesian_command > 49
                    n_cartesian_command := 1;
                  addString := "BUFFER_OK";
                ELSE
                  addString := "BUFFER_FULL";
                ENDIF
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF

      			CASE 85: !Force to GO
      				IF nParams = 2 THEN
                !IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
            			!TEST params{1}
            				!CASE 0:
                      !SetGO GO_FL_Programa, params{2};
        						!CASE 1:
                      !SetGO GO_FL_PotenciaLaser1, params{2};
                    !CASE 2:
                      !SetGO GoTPSJobL, params{2};
                    !CASE 3:
                      !SetGO TGOPROGRAM_No, params{2};
            				!DEFAULT:
                      !TPWrite "SERVER: Illegal output code FGO = ", \Num:=params{1};
                      !ok := SERVER_BAD_MSG;
        					!ENDTEST
                  !addString := "BUFFER_OK";
                !ELSE
                  !addString := "BUFFER_FULL";
                !ENDIF
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF

      			CASE 95: !Value to GO
      				IF nParams = 2 THEN
                IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
            			TEST params{1}
            				CASE 0:
        							IF params{2} > 31
        									params{2} := 31;
              				command_type{n_cartesian_command} := 950;
                      numBufferAux{n_cartesian_command} := params{2};
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
        						CASE 1:
              				command_type{n_cartesian_command} := 951;
                      numBufferAux{n_cartesian_command} := params{2};
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 2:
              				command_type{n_cartesian_command} := 952;
                      numBufferAux{n_cartesian_command} := params{2};
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 3:
              				command_type{n_cartesian_command} := 953;
                      numBufferAux{n_cartesian_command} := params{2};
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
            				DEFAULT:
                      TPWrite "SERVER: Illegal output code GO = ", \Num:=params{1};
                      ok := SERVER_BAD_MSG;
        					ENDTEST
                  addString := "BUFFER_OK";
                ELSE
                  addString := "BUFFER_FULL";
                ENDIF
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF

			      CASE 86: !Force an analog output
                !IF nParams = 2 THEN
                  !IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                    !TEST params{1}
                      !CASE 0:
                        !SetAO AoGTV_ExternDisk, params{2};
                      !CASE 1:
                        !SetAO AoGTV_ExternMassflow, params{2};
          						!DEFAULT:
                      				!TPWrite "SERVER: Illegal output code FAO = ", \Num:=params{1};
                              !ok := SERVER_BAD_MSG;
    					      !ENDTEST
                    !addString := "BUFFER_OK";
                  !ELSE
                    !addString := "BUFFER_FULL";
                  !ENDIF
                !ELSE
                    !ok :=SERVER_BAD_MSG;
                !ENDIF

			      CASE 96: !Set an analog output
                IF nParams = 2 THEN
                  IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                    TEST params{1}
                      CASE 0:
                      				command_type{n_cartesian_command} := 960;
                              numBufferAux{n_cartesian_command} := params{2};
                              n_cartesian_command := n_cartesian_command + 1;
                              IF n_cartesian_command > 49
                                n_cartesian_command := 1;
                      CASE 1:
        							        command_type{n_cartesian_command} := 961;
                              numBufferAux{n_cartesian_command} := params{2};
                              n_cartesian_command := n_cartesian_command + 1;
                              IF n_cartesian_command > 49
                                n_cartesian_command := 1;
          						DEFAULT:
                      				TPWrite "SERVER: Illegal output code AO = ", \Num:=params{1};
                              ok := SERVER_BAD_MSG;
    					      ENDTEST
                    addString := "BUFFER_OK";
                  ELSE
                    addString := "BUFFER_FULL";
                  ENDIF
                ELSE
                    ok :=SERVER_BAD_MSG;
                ENDIF

    		    CASE 87: !Set or reset a digital output
              !IF nParams = 2 THEN
        				!IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                  !TEST params{1}
        						!CASE 0:
                      !IF params{2} <> 0 THEN
                        !SetDO doGTV_StartExtern, 1;
                      !ELSE
                        !SetDO doGTV_StartExtern, 0;
                      !ENDIF
                    !CASE 1:
                      !IF params{2} <> 0 THEN
                        !SetDO doGTV_Stop, 1;
                      !ELSE
                        !SetDO doGTV_Stop, 0;
                      !ENDIF
                    !CASE 2:
                      !IF params{2} <> 0 THEN
                        !SetDO Do_FL_RedENC, 1;
                      !ELSE
                        !SetDO Do_FL_RedENC, 0;
                      !ENDIF
                    !CASE 3:
                      !IF params{2} <> 0 THEN
                        !SetDO Do_FL_StandByEnc, 1;
                      !ELSE
                        !SetDO Do_FL_StandByEnc, 0;
                      !ENDIF
                    !CASE 4:
                      !IF params{2} <> 0 THEN
                        !SetDO DoWeldGas, 1;
                      !ELSE
                        !SetDO DoWeldGas, 0;
                      !ENDIF
                    !CASE 5:
                      !IF params{2} <> 0 THEN
                        !SetDO DoRootGas, 1;
                      !ELSE
                        !SetDO DoRootGas, 0;
                      !ENDIF
                    !CASE 6:
                      !IF params{2} <> 0 THEN
                        !SetDO DoCossJet, 1;
                      !ELSE
                        !SetDO DoCossJet, 0;
                      !ENDIF
                    !CASE 7:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSReset, 1;
                      !ELSE
                        !SetDO doTPSReset, 0;
                      !ENDIF
                    !CASE 8:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSReady, 1;
                      !ELSE
                        !SetDO doTPSReady, 0;
                      !ENDIF
                    !CASE 9:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSOP0, 1;
                      !ELSE
                        !SetDO doTPSOP0, 0;
                      !ENDIF
                    !CASE 10:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSOP1, 1;
                      !ELSE
                        !SetDO doTPSOP1, 0;
                      !ENDIF
                    !CASE 11:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSOP2, 1;
                      !ELSE
                        !SetDO doTPSOP2, 0;
                      !ENDIF
                    !CASE 12:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSWireF, 1;
                      !ELSE
                        !SetDO doTPSWireF, 0;
                      !ENDIF
                    !CASE 13:
                      !IF params{2} <> 0 THEN
                        !SetDO doTPSWeld, 1;
                      !ELSE
                        !SetDO doTPSWeld, 0;
                      !ENDIF
                    !CASE 14:
                      !IF params{2} <> 0 THEN
                        !SetDO TdoLaserOn, 1;
                      !ELSE
                        !SetDO TdoLaserOn, 0;
                      !ENDIF
                    !CASE 15:
                      !IF params{2} <> 0 THEN
                        !SetDO TdoExtActiv, 1;
                      !ELSE
                        !SetDO TdoExtActiv, 0;
                      !ENDIF
                    !CASE 16:
                      !IF params{2} <> 0 THEN
                        !SetDO TdoStandBy, 1;
                      !ELSE
                        !SetDO TdoStandBy, 0;
                      !ENDIF
                    !CASE 17:
                      !IF params{2} <> 0 THEN
                        !SetDO TdoActLaser, 1;
                      !ELSE
                        !SetDO TdoActLaser, 0;
                      !ENDIF
                    !CASE 18:
                      !IF params{2} <> 0 THEN
                        !SetDO TdoPStartStat, 1;
                      !ELSE
                        !SetDO TdoPStartStat, 0;
                      !ENDIF
        						!DEFAULT:
                  		!TPWrite "SERVER: Illegal output code DO =", \Num:=params{1};
                  		!ok := SERVER_BAD_MSG;
        					!ENDTEST
                  !addString := "BUFFER_OK";
                !ELSE
                  !addString := "BUFFER_FULL";
                !ENDIF
              !ELSE
                !ok :=SERVER_BAD_MSG;
              !ENDIF

    		    CASE 97: !Set or reset a digital output
              IF nParams = 2 THEN
        				IF NOT ((n_cartesian_motion - n_cartesian_command) = 1 OR (n_cartesian_motion - n_cartesian_command) = -48) THEN
                  TEST params{1}
        						CASE 0:
                      command_type{n_cartesian_command} := 970;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 1:
                      command_type{n_cartesian_command} := 971;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 2:
                      command_type{n_cartesian_command} := 972;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 3:
                      command_type{n_cartesian_command} := 973;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 4:
                      command_type{n_cartesian_command} := 974;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 5:
                      command_type{n_cartesian_command} := 975;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 6:
                      command_type{n_cartesian_command} := 976;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 7:
                      command_type{n_cartesian_command} := 977;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 8:
                      command_type{n_cartesian_command} := 978;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 9:
                      command_type{n_cartesian_command} := 979;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 10:
                      command_type{n_cartesian_command} := 9710;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 11:
                      command_type{n_cartesian_command} := 9711;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 12:
                      command_type{n_cartesian_command} := 9712;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 13:
                      command_type{n_cartesian_command} := 9713;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 14:
                      command_type{n_cartesian_command} := 9714;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 15:
                      command_type{n_cartesian_command} := 9715;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 16:
                      command_type{n_cartesian_command} := 9716;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 17:
                      command_type{n_cartesian_command} := 9717;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
                    CASE 18:
                      command_type{n_cartesian_command} := 9718;
                      commandSetDO{n_cartesian_command} := params{2} <> 0;
                      n_cartesian_command := n_cartesian_command + 1;
                      IF n_cartesian_command > 49
                        n_cartesian_command := 1;
        						DEFAULT:
                  		TPWrite "SERVER: Illegal output code DO =", \Num:=params{1};
                  		ok := SERVER_BAD_MSG;
        					ENDTEST
                  addString := "BUFFER_OK";
                ELSE
                  addString := "BUFFER_FULL";
                ENDIF
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF

            CASE 98: !returns current robot info: serial number, robotware version, and robot type
                IF nParams = 0 THEN
                    addString := GetSysInfo(\SerialNo) + "*";
                    addString := addString + GetSysInfo(\SWVersion) + "*";
                    addString := addString + GetSysInfo(\RobotType);
                    ok := SERVER_OK;
                ELSE
                    ok :=SERVER_BAD_MSG;
                ENDIF

            CASE 99: !Close Connection
                IF nParams = 0 THEN
                    TPWrite "SERVER: Client has closed connection.";
                    connected := FALSE;
                    FullReset;
                    !//Closing the server
                    SocketClose clientSocket;
                    SocketClose serverSocket;

                    !Reinitiate the server
                    ServerCreateAndConnect serverPort;
                    connected := TRUE;
                    reconnected := TRUE;
                    ok := SERVER_OK;
                ELSE
                    ok := SERVER_BAD_MSG;
                ENDIF
      			CASE 100: !Stop
      				IF nParams = 0 THEN
      					IF cancel_motion = TRUE
      						cancel_motion := FALSE;
      					TPWrite "Cancel command";
      					n_cartesian_command := n_cartesian_motion;
      					cancel_motion := TRUE;
                          ok := SERVER_OK;
                      ELSE
                          ok := SERVER_BAD_MSG;
                      ENDIF
            CASE 101: !RESET laser
              !IF nParams = 0 THEN
                !SetDO TdoPStartStat, 0;
                !SetDO Do_FL_RayoLaserEnc, 0;
                !!SetDO Do_FL_StandByEnc, 0;
                !!SetDO Do_FL_RedENC, 0;
                !SetDO DoCossJet, 0;
                !SetDO DoRootGas, 0;
                !ok := SERVER_OK;
              !ELSE
                !ok := SERVER_BAD_MSG;
              !ENDIF
            CASE 102: !RESET powder
              !IF nParams = 0 THEN
                !SetDO doGTV_StartExtern, 0;
                !SetDO DoWeldGas, 0;
                !SetDO doGTV_Stop, 1;
                !ok := SERVER_OK;
              !ELSE
                !ok := SERVER_BAD_MSG;
              !ENDIF
            CASE 103: !RESET wire feeder
              !IF nParams = 0 THEN
                !SetDO doTPSWireF, 0;
                !SetDO doTPSReady, 0;
                !ok := SERVER_OK;
              !ELSE
                !ok := SERVER_BAD_MSG;
              !ENDIF
            CASE 110: !Configure laser
              IF nParams = 1 THEN
                laser_conf := params{1};
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF
            CASE 111: !Configure feeder
              IF nParams = 1 THEN
                feeder_conf := params{1};
              ELSE
                ok :=SERVER_BAD_MSG;
              ENDIF
                  DEFAULT:
                      TPWrite "SERVER: Illegal instruction code", \Num:=instructionCode;
                      ok := SERVER_BAD_MSG;
        ENDTEST

        !Compose the acknowledge string to send back to the client
        IF connected = TRUE THEN
            IF reconnected = FALSE THEN
			         IF SocketGetStatus(clientSocket) = SOCKET_CONNECTED THEN
				            sendString := NumToStr(instructionCode,0);
                    sendString := sendString + " " + NumToStr(ok,0);
                    sendString := sendString + " " + addString;
                    SocketSend clientSocket \Str:=sendString;
			        ENDIF
            ENDIF
        ENDIF
    ENDWHILE

ERROR (LONG_JMP_ALL_ERR)
    TEST ERRNO
        CASE ERR_SOCK_CLOSED:
            TPWrite "SERVER: Error Handler:" + NumtoStr(ERRNO,0);
            FullReset;
            TPWrite "SERVER: Lost connection to the client.";
            Reconnect;
            TRYNEXT;
        CASE ERR_NORUNUNIT:
            !TPWrite "SERVER: No contact with unit.";
            TRYNEXT;
        DEFAULT:
            TPWrite "SERVER: Error Handler:" + NumtoStr(ERRNO,0);
            FullReset;
            TPWrite "SERVER: Unknown error.";
            Reconnect;
            TRYNEXT;
    ENDTEST
UNDO    
    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    IF (SocketGetStatus(serverSocket) <> SOCKET_CLOSED) SocketClose serverSocket;
ENDPROC

ENDMODULE
