import socket
import logging
import inspect
import time
import os
import glob


laser_ip = '10.0.0.230'  # the laser ip address that you want to connect
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
        #time.sleep(self.delay)

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


    def read_power(self, response=True):
        # read the laser power
        msg = b'ROP\r'
        laser_power = self.send(msg, response)
        return laser_power

    def read_ip(self, response = True):
        # read the ip address of the server
        msg = b'RIP\r'
        laser_ip = self.send(msg, response)
        return laser_ip
    
    def AimingBeamOn(self, response=True):
        # turn on the aiming beam
        msg = b'ABN\r'
        on_response = self.send(msg, response)
        return on_response

    def AimingBeamOFF(self, response=True):
        # turn OFF the aiming beam
        msg = 'ABF\r'.encode('utf-8')
        off_response = self.send(msg, response)
        return off_response

    def laser_temp(self, response=True):
        # read the current laser temperature
        # msg = base64.b64encode('RCT')
        msg = b"RCT\r"
        laser_temperature = self.send(msg, response)
        return laser_temperature
    
    def min_current_setpoint(self, response=True):
        # read minimun current setpoint
        msg = b'RNC\r'
        minimun_curretn_setpoint = self.send(msg, response)
        return minimun_curretn_setpoint

    def read_current_setpoint(self, response=True):
        msg = b'RCS\r'
        current_setpoint = self.send(msg, response)
        return current_setpoint

    def disable_external_control(self, response=True):
        msg = b'DEC\r'
        return self.send(msg, response)

    def enable_external_control(self, response=True):
        msg = b'EEC\r'
        return self.send(msg, response)

    def disable_hardware_emmision(self, response=True):
        msg = b'DLE\r'
        return self.send(msg, response)

    def enable_hardware_emmision(self, response=True):
        msg = b'ELE\r'
        return self.send(msg, response)

    def set_diode_current(self, diode_current, response=True):
        #msg = b'SDC 70.0\r'
        msg = ('SDC' + ' ' + diode_current +'\r').encode('utf-8')
        return self.send(msg, response)

    def start_emission(self, response=True):
        msg = b'EMON\r'
        return self.send(msg, response)

    def close(self):
        self.s.shutdown(socket.SHUT_RDWR)
        self.s.close()
        self.log.info('Disconnected from the socket.')

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()
