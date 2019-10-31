#!/usr/bin/env python3

import sys
import socket
import selectors
import types

sel = selectors.DefaultSelector()


def accept_wrapper(sock):
    conn, addr = sock.accept()  # Should be ready to read
    print("accepted connection from", addr)
    conn.setblocking(False)

    #create an object to hold the data we want included 
    #along with the socket using the class types.SimpleNamespace.
    data = types.SimpleNamespace(addr=addr, inb=b"", outb=b"")
    # events is a mask show if it is ready to read or write
    events = selectors.EVENT_READ | selectors.EVENT_WRITE

    # The events mask, socket, and data objects are then passed to sel.register().
    sel.register(conn, events, data=data)


# how a client connection is handled when it’s ready:
def service_connection(key, mask):
    sock = key.fileobj
    data = key.data
    if mask & selectors.EVENT_READ:
        recv_data = sock.recv(1024)  # Should be ready to read
        if recv_data:
            data.outb += recv_data
        else:
            print("closing connection to", data.addr)
            sel.unregister(sock)
            sock.close()
    if mask & selectors.EVENT_WRITE:
        if data.outb:
            print("echoing", repr(data.outb), "to", data.addr)
            sent = sock.send(data.outb)  # Should be ready to write
            data.outb = data.outb[sent:]


if len(sys.argv) != 3:
    print("usage:", sys.argv[0], "<host> <port>")
    sys.exit(1)

host, port = sys.argv[1], int(sys.argv[2])
lsock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lsock.bind((host, port))
lsock.listen()
print("listening on", (host, port))



#Calls made to this socket will no longer block. 
lsock.setblocking(False)



sel.register(lsock, selectors.EVENT_READ, data=None)
# registers the socket to be monitored with sel.select()
# for the events you’re interested in.
# For the listening socket, we want read events: selectors.EVENT_READ.


try:
    while True:
        # wait until there are sockets ready for I/O.
        events = sel.select(timeout=None)

        # key is a SelectorKey namedtuple that contains a fileobj attribute.
        # key.fileobj is the socket object
        # mask is an event mask of the operations that are ready.
        for key, mask in events:

            if key.data is None:
                # it’s from the listening socket and we need to accept() 
                # the connection. 
                accept_wrapper(key.fileobj)

            else: 
                # it’s a client socket that’s already been accepted, 
                # and we need to service it.
                service_connection(key, mask)

except KeyboardInterrupt:
    print("caught keyboard interrupt, exiting")
finally:
    sel.close()