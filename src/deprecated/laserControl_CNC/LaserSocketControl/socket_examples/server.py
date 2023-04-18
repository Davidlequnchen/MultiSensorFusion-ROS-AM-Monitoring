#!/usr/bin/env python3

import socket


HOST = '127.0.0.1'
PORT = 65432

# create a socket object that supports the context manager type,
# a build in type
# so you can use it in a with statement. 
# then, There’s no need to call s.close():
# Pass address family(IPv4: AF_INET) and socket type(TCP: transmission control protocal)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT)) # bind the specific network interface and port number
    # port should be an integer from 1-65535 (0 is reserved). 
    # 127.0.0.1 is the standard IPv4 address for the loopback interface
    s.listen()
    # listen() has a backlog parameter. which specifies the unaccepted connections.(optional)

    # create a new socket object 'connection' from accept(), 
    # distinguished it from the previous listening socket
    connection, addr = s.accept()


    #This reads whatever data the client sends and
    # echoes it back using conn.sendall().

    #The with statement is used with connection to 
    #automatically close the socket at the end of the block.
    with connection:
        print('Connected by ', addr)
        while True:
            data = connection.recv(1024)
            if not data:
                break
            connection.sendall(data)
    '''
while True:
    clientsocket, address =  s.accept()
    # print s.accept().address
    print({address})
    print("Connection from {address} has been established")
    clientsocket.send(bytes("Welcome to the server","utf-8"))
    clientsocket.close()
'''