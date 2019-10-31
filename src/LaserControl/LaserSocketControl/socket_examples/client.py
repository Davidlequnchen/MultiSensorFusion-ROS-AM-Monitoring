#!/usr/bin/env python3

import socket

HOST = '127.0.0.1' # The server's hostname or IP address
PORT = 65432       # the port used by server

# alternatively:
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    #s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST,PORT))
    s.sendall(b'Hello world')
    data = s.recv(1024)

#“Unlike send(), this method continues to send data from bytes until 
# either all data has been sent or an error occurs. 
# None is returned on success.”
print('Received', repr(data)) # read the server’s reply and then prints it.
# The repr() method returns a printable representational string of the given object.









'''
s.connect((socket.gethostname(),1234))

full_msg = ''
while True:

    msg = s.recv(8)
    if len(msg) <= 0:
        break
    full_msg += msg.decode("utf-8")

print(full_msg)
'''