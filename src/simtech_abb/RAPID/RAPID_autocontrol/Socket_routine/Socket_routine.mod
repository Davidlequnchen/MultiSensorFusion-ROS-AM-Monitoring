
MODULE Socket_routine

!////////////////
!This Socket_routine module handles the subroutine to conduct surface scanning task
!It uses a tcp socket to communicate with the ROS 
!It inspect the global variable routine_command to see if the mode need to change
!////////////////

VAR socketdev clientSocket;
VAR socketdev serverSocket;
PERS num maintaskPort:= 11003;

VAR bool connected;
VAR bool reconnected;        !//Drop and reconnection happened during serving a command
!// sampling rate
PERS num maintaskWaitTime:= 0.1;  !0.02 Recommended for real controller, 0.03 < 1/30 , thus, reasonable. 0.1s - 10Hz

! VAR bool Command_Changed;
! VAR num last_routine_command := 0; ! initial command should be mode 0 (idle mode)

CONST num SERVER_OK := 1;
VAR num ok;
VAR num defects_received; !// the received defects type, 0 - no defects

!////////////////
!LOCAL METHODS
!////////////////
PROC SetDefectsResult(string msg)
    !//Local variables
    VAR bool auxOk;

    auxOk:= StrToVal(msg, defects_received);
    IF auxOk = FALSE THEN
    !//Impossible to read the v
        TPWrite "LASER: Failed to get the defects result";
    ELSE
        IF defects_received = 0 THEN
          is_defects := FALSE;
        ELSE
          is_defects := TRUE;
        ENDIF
    ENDIF
ENDPROC



PROC ServerCreateAndConnect(num port)
	VAR string clientIP;
	VAR num time_val := WAIT_MAX;  ! default to wait-forever

	IF (SocketGetStatus(serverSocket) = SOCKET_CLOSED) SocketCreate serverSocket;
	IF (SocketGetStatus(serverSocket) = SOCKET_CREATED) SocketBind serverSocket, "192.168.125.1", port;
	IF (SocketGetStatus(serverSocket) = SOCKET_BOUND) SocketListen serverSocket;
	TPWrite "MainTask: Maintask waiting for incomming connections ...";

	!IF Present(wait_time) time_val := wait_time;

    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    WaitUntil (SocketGetStatus(clientSocket) = SOCKET_CLOSED);

    SocketAccept serverSocket, clientSocket, \ClientAddress:=clientIP, \Time:=time_val;
	TPWrite "MainTask: Connected to IP " + clientIP;
ENDPROC



PROC Reconnect ()
		connected:=FALSE;
		!Closing the server
		SocketClose clientSocket;
		SocketClose serverSocket;
		!Reinitiate the server
		ServerCreateAndConnect maintaskPort;
		connected:= TRUE;
		reconnected:= TRUE;
ENDPROC




PROC main()
 !//Local variables
  VAR string receivedString;   !//Received string
  VAR string sendString;       !//Reply string


  connected:=FALSE;
  WaitTime 1;
  ServerCreateAndConnect maintaskPort;
  connected:=TRUE;

  ! Command_Changed := FALSE;



  !//Server Loop
    WHILE TRUE DO
        !//Initialization of program flow variables
        ok:=SERVER_OK;              !//Correctness of executed instruction.
        reconnected:=FALSE;         !//Has communication dropped after receiving a command?


        !//Wait for a command
        !// store the received data into the variable receivedString within the time limit
        SocketReceive clientSocket \Str:=receivedString \Time:=WAIT_MAX;

        SetDefectsResult receivedString;

        !Compose the acknowledge string to send back to the client
        IF connected = TRUE THEN
            IF reconnected = FALSE THEN
			        IF SocketGetStatus(clientSocket) = SOCKET_CONNECTED THEN
						      sendString := NumToStr(routine_command,1); !routine_command is a global variable to be defined in the COMMON.sys
						      SocketSend clientSocket \Str:=sendString;
			        ENDIF
            ENDIF
        ENDIF
        WaitTime maintaskWaitTime;
    ENDWHILE



  ERROR (LONG_JMP_ALL_ERR)
      TPWrite "MainTask: Error Handler:" + NumtoStr(ERRNO,0);
      TEST ERRNO
        CASE ERR_SOCK_CLOSED:
          TPWrite "MainTask: Client has closed connection.";
          TPWrite "MainTask: Closing socket and restarting.";
          Reconnect;
          TRYNEXT;
        CASE ERR_NORUNUNIT:
          TPWrite "MainTask: No contact with unit.";
          TRYNEXT;
        DEFAULT:
          TPWrite "MainTask: Unknown error.";
          TPWrite "MainTask: Closing socket and restarting.";
          TPWrite "MainTask: ------";
          Reconnect;
          TRYNEXT;
		  ENDTEST


ENDPROC

ENDMODULE