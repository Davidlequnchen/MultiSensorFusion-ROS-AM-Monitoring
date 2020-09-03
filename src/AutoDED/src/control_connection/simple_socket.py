import socket
import logging
import inspect
import time
import os
import glob
# import ros library
import rospy



laser_ip = '192.168.125.1'  # the robot controller ip address that you want to connect
PORT = 11003      # the port used by routine socket server



class SimpleConnection():

    def __init__(self):
        #self.control = True
        self.delay = .08
        # define a socket object(client) for data transmission
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.log = logging.getLogger(__name__)
        self.log.addHandler(logging.NullHandler())


    def send(self, message, wait_for_response=True):
        '''
        Send a formatted message to the socket.
        if wait_for_response, we wait for the response and return it
        '''

        self.s.send(message)
        #number_of_bytes= self.s.send(message)
        #self.log.debug('%-14s has successfully send : %s bytes of data', caller, number_of_bytes)
        time.sleep(self.delay)


        data = self.s.recv(1024)
        #self.log.debug('%-14s recieved: %s', caller, data)
        return data
    
    def read_command(self):
        try:
            data = self.s.recv(1024)
            self.command_received = data
            
            return True
        
        except socket.error, e:
            return False
            
       
    def estab_connect(self,remote):
        self.log.info('Attempting to connect to server at %s', str(remote))
        self.s.settimeout(2.5)
        try:
            self.s.connect((remote,PORT))
        except Exception as e: 
            self.log.error("something's wrong with %s:%d. Exception is %s" % (remote, PORT, e))
        self.s.settimeout(None)
        self.command_received = None
        self.log.info('Successfully connected to server at %s', str(remote))
        print ('Successfully connected to server at %s', str(remote))


    def close(self):
        self.s.shutdown(socket.SHUT_RDWR)
        self.s.close()
        self.log.info('Disconnected from the socket.')

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()





'''
connection = SimpleConnection()
connection.estab_connect(laser_ip)

while True:
    # wait for data transmission
    print ("test1")
    recved = connection.s.recv(1024)
    # If return empty byte, then nothing received
    print ("test2")
    if not recved:
        print ("no command")
        
    
    # read the message
    print("command received: ")
    print(recved.decode())
'''