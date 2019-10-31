import socket
import logging
import inspect
import time
import os
import glob


laser_ip = '192.168.125.1'  # the laser ip address that you want to connect
PORT = 10001      # the port used by laser socket server



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

        #caller = inspect.stack()[1][3]
        #self.log.debug('%-14s is now sending: %s', caller, message)

        self.s.send(message)
        #number_of_bytes= self.s.send(message)
        #self.log.debug('%-14s has successfully send : %s bytes of data', caller, number_of_bytes)
        time.sleep(self.delay)

        #if not wait_for_response:
        #    return

        data = self.s.recv(1024)
        #self.log.debug('%-14s recieved: %s', caller, data)
        return data


    def estab_connect(self,remote):
        self.log.info('Attempting to connect to server at %s', str(remote))
        self.s.settimeout(2.5)
        try:
            self.s.connect((remote,PORT))
        except Exception as e: 
            self.log.error("something's wrong with %s:%d. Exception is %s" % (remote, PORT, e))
        self.s.settimeout(None)
        self.log.info('Successfully connected to server at %s', str(remote))


    
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
