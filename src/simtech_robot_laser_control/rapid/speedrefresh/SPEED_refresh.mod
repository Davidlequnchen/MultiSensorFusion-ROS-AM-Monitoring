MODULE SPEED_refresh

!////////////////
! SPEED_refresh module creates a socket server listening to the value send by 
! the PC ROS program. The ROS nodes will calculate and send the controlled value
! of SpeedOverride and this socket will receive it. It will pass the value to the
! SERVER_motion(T_ROB1 task), which will issue the SpeedOverride to the robot 
!////////////////



!//GLOBAL VARIABLES
!//PC communication
VAR socketdev clientSocket;
VAR socketdev serverSocket;
VAR num SpeedOverride;
PERS num speedPort:= 10002;



!//Correct Instruction Execution and possible return values
VAR num ok;
CONST num SERVER_BAD_MSG :=  0;
CONST num SERVER_OK := 1;
VAR bool connected;          !//Client connected
VAR bool reconnected;        !//Drop and reconnection happened during serving a command

!////////////////
!LOCAL METHODS
!////////////////
PROC SetSpeedOverride(string msg)
    !//Local variables
    VAR bool auxOk;

    auxOk:= StrToVal(msg, SpeedOverride);
    IF auxOk = FALSE THEN
    !//Impossible to read the power value
        TPWrite "VelocityControl: Failed to get the SpeedOverride";
    ELSE
        !speed_corr := 10;
        speed_corr := SpeedOverride;
        TPWrite "VelocityControl: SpeedOverride set: ", \Num:= speed_corr;
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
	TPWrite "VelocityControl: SpeedRefresh waiting for incomming connections ...";

	!IF Present(wait_time) time_val := wait_time;

    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    WaitUntil (SocketGetStatus(clientSocket) = SOCKET_CLOSED);

    SocketAccept serverSocket, clientSocket, \ClientAddress:=clientIP, \Time:=time_val;
	TPWrite "VelocityControl: SpeedRefresh Connected to IP " + clientIP;
ENDPROC


PROC Reconnect ()
    connected:=FALSE;
    !//Closing the server
    SocketClose clientSocket;
    SocketClose serverSocket;
    !//Reinitiate the server
    ServerCreateAndConnect speedPort;
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
    ServerCreateAndConnect speedPort;
    connected:=TRUE;


    !//Server Loop
    WHILE TRUE DO
        !//Initialization of program flow variables
        ok:=SERVER_OK;              !//Correctness of executed instruction.
        reconnected:=FALSE;         !//Has communication dropped after receiving a command?
        

        !//Wait for a command
        !// store the received data into the variable receivedString within the time limit
        SocketReceive clientSocket \Str:=receivedString \Time:=WAIT_MAX;

        SetSpeedOverride receivedString;
        
        !Compose the acknowledge string to send back to the client
        IF connected = TRUE THEN
            IF reconnected = FALSE THEN
			         IF SocketGetStatus(clientSocket) = SOCKET_CONNECTED THEN
				            sendString := NumToStr(speed_corr,0);
                            sendString := sendString + " " + NumToStr(ok,0);
                            SocketSend clientSocket \Str:=sendString;
			          ENDIF
            ENDIF
        ENDIF
        
    ENDWHILE

ERROR
	TEST ERRNO
            CASE ERR_SOCK_CLOSED:
                    TPWrite "VelocityControl: Error Handler:" + NumtoStr(ERRNO,0);
                    !FullReset;
                    TPWrite "VelocityControl: Lost connection to the client.";
                    Reconnect;
                    TRYNEXT;
			CASE ERR_NORUNUNIT:
					TPWrite "VelocityControl: No contact with unit.";
					TRYNEXT;
            CASE ERR_AO_LIM:
                    TPWrite "VelocityControl: analog signal is outside limits";
					TRYNEXT;
			DEFAULT:
					ErrWrite \W, "VelocityControl Error", "Error updating SpeedOverride. VelocityControl end";
					SetAO aoPower, 0;
	ENDTEST
UNDO    
    IF (SocketGetStatus(clientSocket) <> SOCKET_CLOSED) SocketClose clientSocket;
    IF (SocketGetStatus(serverSocket) <> SOCKET_CLOSED) SocketClose serverSocket;
ENDPROC

ENDMODULE
