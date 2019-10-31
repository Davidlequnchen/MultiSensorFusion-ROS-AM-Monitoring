#!/usr/bin/env python3

import socket
import logging
import inspect
import time
import os
import glob
#import base64


log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())



laser_ip = '192.168.125.1'  # the laser ip address that you want to connect
PORT = 11000      # the port used by server

path = '../'
#filename = os.path.join(path, 'data', 'pose%04i.txt' %self.counter)
filename = os.path.join(path, 'data', 'data.txt')



class SimpleConnection:

    def __init__(self):
        #self.control = True
        self.delay = .08
        # define a socket object(client) for data transmission
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


    def send(self, message, wait_for_response=True):
        '''
        Send a formatted message to the socket.
        if wait_for_response, we wait for the response and return it
        '''

        caller = inspect.stack()[1][3]
        log.debug('%-14s is now sending: %s', caller, message)

        number_of_bytes= self.s.send(message)
        log.debug('%-14s has successfully send : %s bytes of data', caller, number_of_bytes)
        time.sleep(self.delay)

        #if not wait_for_response:
        #    return

        data = self.s.recv(1024)
        log.debug('%-14s recieved: %s', caller, data)
        return data



    def estab_connect(self,remote):

        

        log.info('Attempting to connect to server at %s', str(remote))

        self.s.settimeout(2.5)

        try:
            self.s.connect((remote,PORT))

        except Exception as e: 
            print("something's wrong with %s:%d. Exception is %s" % (remote, PORT, e))

        #self.s.connect_ex((remote,PORT))

        self.s.settimeout(None)

        log.info('Successfully connected to server at %s', str(remote))




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

    def set_diode_current(self, response=True):
        msg = b'SDC 45.0\r'
        return self.send(msg, response)

    
    def close(self):
        self.s.shutdown(socket.SHUT_RDWR)
        self.s.close()
        log.info('Disconnected from the socket.')


    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()


        

if __name__ == '__main__':
    formatter = logging.Formatter(
        "[%(asctime)s] %(levelname)-7s (%(filename)s:%(lineno)3s) %(message)s",
        "%Y-%m-%d %H:%M:%S")
    handler_stream = logging.StreamHandler()
    handler_stream.setFormatter(formatter)
    handler_stream.setLevel(logging.DEBUG)
    log = logging.getLogger('laser')
    log.setLevel(logging.DEBUG)
    log.addHandler(handler_stream)


    laser_connection = SimpleConnection()
    laser_connection.estab_connect(laser_ip)

  

   # f= open(filename,"w")


    log.info('disable external control:' + str(laser_connection.disable_external_control()))

    #f.write(str(laser_connection.enable_external_control()) + '\n')

    log.info('disable hardware emission control:' + str(laser_connection.disable_hardware_emmision()))
    
    #f.write(str(laser_connection.disable_hardware_emmision()) + '\n')

    log.info('Set diode current: ' + str(laser_connection.set_diode_current()))


    log.info('enable hardware emission control:' + str(laser_connection.enable_hardware_emmision()))


    while True:

        #laser = laser_connection.read_ip()
        power = laser_connection.read_power()
        #print('The current ip address is',laser)
        print('The current laser power is '+ str(power))
        #f.write(str(power)+'\t')
        

        #laser_temperature = laser_connection.laser_temp()
        #log.info('The current temperature is %s', laser_temperature)

        #if_off = laser_connection.AimingBeamOFF()
        #log.info('The aiming beam:', if_off)

        #if_on = laser_connection.AimingBeamOn()
        #log.info('The aiming beam:', if_on)

        #temp = laser_connection.laser_temp()
        #log.info("The current laser temperature is %s", temp)
         
        #minimun_curretn_setpoint = laser_connection.min_current_setpoint()
        #print('minimum current setpoint is %s', minimun_curretn_setpoint) 
        

        current_setpoint = laser_connection.read_current_setpoint()
        print('The current setpoint is ' + repr(current_setpoint))

        
        #f.write(str(current_setpoint) + '\t')
        #f.write('\n')


        



    f.close()
    laser_connection.close()




