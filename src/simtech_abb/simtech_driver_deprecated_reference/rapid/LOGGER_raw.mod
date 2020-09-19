MODULE LOGGER


! The Logger_raw module should be load into a separate task, logger task
! This is to receive the data of joint state and robot state from the robot
! user could define a client socket to connect to this server to get the data messages
!////////////////
!GLOBAL VARIABLES/
!////////////////
!PC communication
VAR socketdev clientSocket;
VAR socketdev serverSocket;
PERS num loggerPort:= 5001;

VAR bool connected;
VAR bool reconnected;        !//Drop and reconnection happened during serving a command

!//Logger sampling rate
PERS num loggerWaitTime:= 0.02;  !Recommended for real controller
!PERS num loggerWaitTime:= 0.1;    !Recommended for virtual controller
!PERS bool joints_notcartesians:= TRUE;

PROC ServerCreateAndConnect(string ip, num port)
	VAR string clientIP;
	SocketCreate serverSocket;
	SocketBind serverSocket, ip, port;
	SocketListen serverSocket;
	TPWrite "LOGGER: Logger waiting for incomming connections ...";
	WHILE SocketGetStatus(clientSocket) <> SOCKET_CONNECTED DO
		SocketAccept serverSocket,clientSocket \ClientAddress:=clientIP \Time:=WAIT_MAX;
		IF SocketGetStatus(clientSocket) <> SOCKET_CONNECTED THEN
			TPWrite "LOGGER: Problem serving an incomming connection.";
			TPWrite "LOGGER: Try reconnecting.";
		ENDIF
		 !Wait 0.5 seconds for the next reconnection
		 WaitTime 0.5;
	ENDWHILE
	TPWrite "LOGGER: Connected to IP " + clientIP;
ENDPROC

PROC Reconnect ()
		connected:=FALSE;
		!Closing the server
		SocketClose clientSocket;
		SocketClose serverSocket;
		!Reinitiate the server
		ServerCreateAndConnect ipController,loggerPort;
		connected:= TRUE;
		reconnected:= TRUE;
ENDPROC

PROC main()
	VAR string data;
	VAR string data2;
	VAR robtarget position;
	VAR jointtarget joints;
    VAR string sendString;
	VAR rawbytes raw_data;
	VAR rawbytes buffer;

	VAR string date;
	VAR string time;
	VAR clock timer;

	date:= CDate();
	time:= CTime();
    ClkStart timer;

	connected:=FALSE;
	WaitTime 1;
	ServerCreateAndConnect ipController,loggerPort;
	connected:=TRUE;

	WHILE TRUE DO
		reconnected:=FALSE;         !//Has communication dropped after receiving a command?
			!Joint Coordinates
			joints := CJointT();    !//read current joint angles, The current values for the external axes, in mm for linear axes, in degrees for rotational axes
			PackRawBytes joints.robax.rax_1, raw_data, 1, \Float4;
			PackRawBytes joints.robax.rax_2, raw_data, 5, \Float4;
			PackRawBytes joints.robax.rax_3, raw_data, 9, \Float4;
			PackRawBytes joints.robax.rax_4, raw_data, 13, \Float4;
			PackRawBytes joints.robax.rax_5, raw_data, 17, \Float4;
			PackRawBytes joints.robax.rax_6, raw_data, 21, \Float4;

			IF IsMechUnitActive(STN1) THEN
				PackRawBytes joints.extax.eax_b, raw_data, 25, \Float4;
				PackRawBytes joints.extax.eax_c, raw_data, 29, \Float4;
			ENDIF
			IF connected = TRUE THEN
				IF reconnected = FALSE THEN
					IF SocketGetStatus(clientSocket) = SOCKET_CONNECTED THEN
						PackRawBytes RawBytesLen(raw_data), buffer, 1, \IntX := UDINT; ! Packet length (excluding this prefix)
						CopyRawBytes raw_data, 1, buffer, 5; ! Message data
						SocketSend clientSocket \RawData:=buffer;
					ENDIF
				ENDIF
			ENDIF
			WaitTime loggerWaitTime;
	ENDWHILE
ERROR (LONG_JMP_ALL_ERR)
  TPWrite "LOGGER: Error Handler:" + NumtoStr(ERRNO,0);
	TEST ERRNO
		CASE ERR_SOCK_CLOSED:
			TPWrite "LOGGER: Client has closed connection.";
			TPWrite "LOGGER: Closing socket and restarting.";
			Reconnect;
			TRYNEXT;
		CASE ERR_NORUNUNIT:
			TPWrite "LOGGER: No contact with unit.";
			TRYNEXT;
		DEFAULT:
			TPWrite "LOGGER: Unknown error.";
			TPWrite "LOGGER: Closing socket and restarting.";
			TPWrite "LOGGER: ------";
			Reconnect;
			TRYNEXT;
		ENDTEST
ENDPROC

ENDMODULE
