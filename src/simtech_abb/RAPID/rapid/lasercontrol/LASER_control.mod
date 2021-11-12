MODULE LASER_control

!////////////////
! LASER_control module creates a socket server listening to the value send by 
! the PC ROS program. The ROS nodes will calculate and send the controlled value
! of laser power and this socket will receive it. It will pass the value to the
! SERVER_motion(T_ROB1 task), which will issue the laser power to the robot 
! through analog signal
!////////////////



!//GLOBAL VARIABLES
!//PC communication
VAR socketdev clientSocket;
VAR socketdev serverSocket;
VAR num power_value;
PERS num laserPort:= 10001;



!//Correct Instruction Execution and possible return values
VAR num ok;
CONST num SERVER_BAD_MSG :=  0;
CONST num SERVER_OK := 1;
VAR bool connected;          !//Client connected
VAR bool reconnected;        !//Drop and reconnection happened during serving a command

!////////////////
!LOCAL METHODS
!////////////////
PROC SetPower(string msg)
    !//Local variables
    VAR bool auxOk;

    auxOk:= StrToVal(msg, power_value);
    IF auxOk = FALSE THEN
    !//Impossible to read the power value
        TPWrite "LASER: Failed to get the power value";
    ELSE
        SetAO aoPower, power_value;
        !SetAO aoPower, 0;
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
	TPWrite "Laser: Laser waiting for incomming connections ...";

	!IF Present(wait_time) time_val := wait_time;

    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    WaitUntil (SocketGetStatus(clientSocket) = SOCKET_CLOSED);

    SocketAccept serverSocket, clientSocket, \ClientAddress:=clientIP, \Time:=time_val;
	TPWrite "Laser: Laser Connected to IP " + clientIP;
ENDPROC


PROC Reconnect ()
    connected:=FALSE;
    !//Closing the server
    SocketClose clientSocket;
    SocketClose serverSocket;
    !//Reinitiate the server
    ServerCreateAndConnect laserPort;
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

    !//Socket connection
    connected:=FALSE;
    ServerCreateAndConnect laserPort;
    connected:=TRUE;


    !//Server Loop
    WHILE TRUE DO
        !//Initialization of program flow variables
        ok:=SERVER_OK;              !//Correctness of executed instruction.
        reconnected:=FALSE;         !//Has communication dropped after receiving a command?
        addString := "";

        !//Wait for a command
        !// store the received data into the variable receivedString within the time limit
        SocketReceive clientSocket \Str:=receivedString \Time:=WAIT_MAX;

        !SetAO aoPower, 2.919;                      !20191022
        SetPower receivedString;
        !TpWrite "laser power set";




       

        !Compose the acknowledge string to send back to the client
        IF connected = TRUE THEN
            IF reconnected = FALSE THEN
			         IF SocketGetStatus(clientSocket) = SOCKET_CONNECTED THEN
				            ! sendString := NumToStr(instructionCode,0);
                    ! sendString := sendString + " " + NumToStr(ok,0);
                    ! sendString := sendString + " " + addString;
                    sendString :=  "True" ;
                    SocketSend clientSocket \Str:=sendString;
			        ENDIF
            ENDIF
        ENDIF
    ENDWHILE

ERROR
	TEST ERRNO
            CASE ERR_SOCK_CLOSED:
                    TPWrite "LASER: Error Handler:" + NumtoStr(ERRNO,0);
                    !FullReset;
                    TPWrite "LASER: Lost connection to the client.";
                    Reconnect;
                    TRYNEXT;
			CASE ERR_NORUNUNIT:
					TPWrite "LASER: No contact with unit.";
					TRYNEXT;
            CASE ERR_AO_LIM:
                    TPWrite "LASER: analog signal is outside limits";
					TRYNEXT;
			DEFAULT:
					ErrWrite \W, "LASER Error", "Error updating laser power. Laser end";
					SetAO aoPower, 0;
	ENDTEST
UNDO    
    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    IF (SocketGetStatus(serverSocket) <> SOCKET_CLOSED) SocketClose serverSocket;
ENDPROC

ENDMODULE
