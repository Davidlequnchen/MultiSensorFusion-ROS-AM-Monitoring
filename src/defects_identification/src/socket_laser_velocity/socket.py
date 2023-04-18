import socket
import logging
import inspect
import time
import os
import glob


controller_ip = '192.168.125.1'  # the robot ip address that you want to connect
VELOCITY_PORT = 10002            # the port used by velocity socket server
LASER_PORT = 10001                # the port used by laser server socket



class SocketConnection():

    def __init__(self, ip, port):
        #self.control = True
        self.delay = .08
        # define a socket object(client) for data transmission
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.log = logging.getLogger(__name__)
        self.log.addHandler(logging.NullHandler())
        self.ip = ip
        self.port = port


    def send(self, message, wait_for_response=True):
        '''
        Send a formatted message to the socket.
        '''

        self.s.send(message)
        #number_of_bytes= self.s.send(message)
        #self.log.debug('%-14s has successfully send : %s bytes of data', caller, number_of_bytes)
        time.sleep(self.delay)
        
        # echo back information
        data = self.s.recv(1024)
        
        
        return data


    def estab_connect(self):
        self.log.info('Attempting to connect to server at %s', str(self.ip))
        self.s.settimeout(2.5)
        try:
            self.s.connect((self.ip, self.port))
        except Exception as e: 
            self.log.error("something's wrong with %s:%d. Exception is %s" % (self.ip, self.port, e))
        self.s.settimeout(None)
        self.log.info('Successfully connected to server at %s', str(self.ip))


    # for velocity socket, send the SpeedOverride value (0-100)
    def set_SpeedOverride(self, send_SpeedOverride, response=True):
        #msg = b'SDC 70.0\r'
        msg = (send_SpeedOverride).encode('utf-8')
        return self.send(msg, response)
    
    
    # for the laser socket, send the analog laser power 
    def set_analog_power(self, send_power, response=True):
        #msg = b'SDC 70.0\r'
        msg = (send_power).encode('utf-8')
        return self.send(msg, response)



    def close(self):
        self.s.shutdown(socket.SHUT_RDWR)
        self.s.close()
        self.log.info('Disconnected from the socket.')

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()
