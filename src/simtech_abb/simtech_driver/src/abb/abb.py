'''
Michael Dawson-Haggerty

abb.py: contains classes and support functions which interact with an ABB Robot
 running our software stack (RAPID code module SERVER)


For functions which require targets (XYZ positions with quaternion
orientation), targets can be passed as [[XYZ], [Quats]] OR [XYZ, Quats]

'''

import socket
import json
import time
import inspect
#from threading import Thread
from collections import deque
import logging
from struct import *

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())


class Robot:
    def __init__(self):
        self.control = True
        self.delay = .08

    def init_ant(self,
                 ip='192.168.125.1',
                 port_motion=5000,
                 port_logger=5001):

        self.delay = .08

        self.connect_motion((ip, port_motion))
        #log_thread = Thread(target = self.get_net,
        #                    args   = ((ip, port_logger))).start()

        self.set_units('millimeters', 'degrees')
        self.set_tool()
        self.set_workobject()
        self.set_speed()
        self.set_zone()

    def connect_motion(self, remote):
        log.info('Attempting to connect to robot motion server at %s',
                 str(remote))
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.settimeout(2.5)
        self.sock.connect(remote)
        self.sock.settimeout(None)
        log.info('Connected to robot motion server at %s', str(remote))

    def connect_logger(self, remote, maxlen=10):
        self.pose = deque(maxlen=maxlen)
        self.joints = deque(maxlen=maxlen)
        self.float_joints = deque(maxlen=maxlen)

        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.connect(remote)
        self.s.setblocking(1) # s.setblocking(1) is equivalent to s.settimeout(None)

    def read_logger(self):
        data = self.s.recv(4096).split()
        self.joints.append(data)

    def read_raw_logger(self):
        try:
            raw_data = self.s.recv(4096)
            if len(raw_data) > 27:
                n_joints = unpack('i', raw_data[:4])[0]
                if n_joints == 32:
                    self.float_joints.append(unpack('ffffffff',
                                             raw_data[4:n_joints+4]))
                elif n_joints == 24:
                    self.float_joints.append(unpack('ffffff',
                                             raw_data[4:n_joints+4]))
            return True
        except socket.error, e:
            return False

    def set_units(self, linear, angular):
        units_l = {'millimeters': 1.0,
                   'meters': 1000.0,
                   'inches': 25.4}
        units_a = {'degrees': 1.0,
                   'radians': 57.2957795}
        self.scale_linear = units_l[linear]
        self.scale_angle = units_a[angular]

    def ping(self, response=True):
        '''
        Sends a ping to check if the robot is connected.
        '''
        msg = "0 #"
        rsp = ""
        rsp = self.send(msg, response=True)
        return rsp

    def cancel_motion(self, response=True):
        '''
        Stops robot movement and cancels active paths.
        '''
        msg = "100 #"
        return self.send(msg, response)

    def r_laser(self, response=True):
        '''
        Stop and reset laser signals.
        '''
        msg = "101 #"
        return self.send(msg, response)

    def r_powder(self, response=True):
        '''
        Stop and reset powder feeder signals.
        '''
        msg = "102 #"
        return self.send(msg, response)

    def r_wire(self, response=True):
        '''
        Stop and reset powder feeder signals.
        '''
        msg = "103 #"
        return self.send(msg, response)

    def configure_laser(self, laser_type, response=True):
        '''
        Configure robor triggers for laser and wire feeder if needed
        0: Rofin
        1: Tumpf
        '''
        msg = "110 " + str(int(laser_type)) + " #"
        return self.send(msg, response)

    def configure_feeder(self, feeder_type, response=True):
        '''
        Configure robor triggers for laser and wire feeder if needed
        0: powder
        1: wire
        '''
        msg = "111 " + str(int(feeder_type)) + " #"
        return self.send(msg,response)

    def set_cartesian(self, pose, linear=True, response=True):
        '''
        Executes a move immediately from the current pose,
        to 'pose', with units of millimeters.
        '''
        try:
            if linear:
                msg = "01 " + self.format_pose(pose)
            else:
                msg = "10 " + self.format_pose(pose)
            return self.send(msg, response)
        except NameError as name:
            return str(name)

    def set_cartesian_trigg(self, pose, trigger=False, response=True):
        '''
        Executes a move immediately from the current pose,
        to 'pose', with units of millimeters. And triggers
        a digital output.
        '''
        try:
            msg = "11 " + self.format_pose(pose)
            msg = msg[:-1]
            msg += str(int(trigger)) + " #"
            return self.send(msg, response)
        except NameError as name:
            return str(name)

    def get_cartesian(self):
        '''
        Returns the current pose of the robot, in millimeters
        '''
        msg = "03 #"
        data = self.send(msg).split()
        r = [float(s) for s in data]
        return [r[2:5], r[5:9]]

    def get_joints(self):
        '''
        Returns the current angles of the robots joints, in degrees.
        '''
        msg = "04 #"
        data = self.send(msg).split()
        return [float(s) / self.scale_angle for s in data[2:8]]

    def get_external_axis(self):
        '''
        If you have an external axis connected to your robot controller
        (such as a FlexLifter 600, google it), this returns the joint angles
        '''
        msg = "05 #"
        data = self.send(msg).split()
        return [float(s) for s in data[2:8]]

    def get_robotinfo(self):
        '''
        Returns a robot- unique string, with things such as the
        robot's model number.
        Example output from and IRB 2400:
        ['24-53243', 'ROBOTWARE_5.12.1021.01', '2400/16 Type B']
        '''
        msg = "98 #"
        data = str(self.send(msg))[5:].split('*')
        log.debug('get_robotinfo result: %s', str(data))
        return data

    def set_tool(self, tool=[[0, 0, 0], [1, 0, 0, 0]]):
        '''
        Sets the tool centerpoint (TCP) of the robot.
        When you command a cartesian move,
        it aligns the TCP frame with the requested frame.

        Offsets are from tool0, which is defined at the intersection of the
        tool flange center axis and the flange face.
        '''
        try:
            msg = "06 " + self.format_pose(tool)
            resp = self.send(msg)
            self.tool = tool
            return resp
        except NameError as name:
            return str(name)

    def load_json_tool(self, file_obj, filename):
        if file_obj.__class__.__name__ == 'str':
            file_obj = open(filename, 'rb')
        tool = check_coordinates(json.load(file_obj))
        self.set_tool(tool)

    def get_tool(self):
        log.debug('get_tool returning: %s', str(self.tool))
        return self.tool

    def set_workobject(self, work_obj=[[0, 0, 0], [1, 0, 0, 0]]):
        '''
        The workobject is a local coordinate frame you can define on the robot,
        then subsequent cartesian moves will be in this coordinate frame.
        '''
        try:
            msg = "07 " + self.format_pose(work_obj)
            return self.send(msg)
        except NameError as name:
            return str(name)

    def set_speed(self, speed=[0, 50, 50, 50]):
        '''
        speed: [robot TCP linear speed (mm/s), TCP orientation speed (deg/s),
                external axis linear, external axis orientation]
        '''

        if len(speed) != 4:
            return "PARAM_ERROR"
        msg = "08 "
        msg += format(speed[0], "+08.1f") + " "
        msg += format(speed[1], "+08.2f") + " "
        msg += format(speed[2], "+08.1f") + " "
        msg += format(speed[3], "+08.2f") + " #"
        return self.send(msg)

    def set_zone(self,
                 zone_key='z1',
                 point_motion=False,
                 manual_zone=[]):
        zone_dict = {'z0': [.3, .3, .03],
                     'z1': [1, 1, .1],
                     'z5': [5, 8, .8],
                     'z10': [10, 15, 1.5],
                     'z15': [15, 23, 2.3],
                     'z20': [20, 30, 3],
                     'z30': [30, 45, 4.5],
                     'z50': [50, 75, 7.5],
                     'z100': [100, 150, 15],
                     'z200': [200, 300, 30]}
        '''
        Sets the motion zone of the robot. This can also be thought of as
        the flyby zone, AKA if the robot is going from point A -> B -> C,
        how close do we have to pass by B to get to C

        zone_key: uses values from RAPID handbook (stored here in zone_dict)
        with keys 'z*', you should probably use these

        point_motion: go to point exactly, and stop briefly before moving on

        manual_zone = [pzone_tcp, pzone_ori, zone_ori]
        pzone_tcp: mm, radius from goal where robot tool centerpoint
                   is not rigidly constrained
        pzone_ori: mm, radius from goal where robot tool orientation
                   is not rigidly constrained
        zone_ori: degrees, zone size for the tool reorientation
        '''

        if point_motion:
            zone = [0, 0, 0]
        elif len(manual_zone) == 3:
            zone = manual_zone
        elif zone_key in zone_dict.keys():
            zone = zone_dict[zone_key]
        else:
            return "PARAM_ERROR"

        msg = "09 "
        msg += str(int(point_motion)) + " "
        msg += format(zone[0], "+08.4f") + " "
        msg += format(zone[1], "+08.4f") + " "
        msg += format(zone[2], "+08.4f") + " #"
        return self.send(msg)

    def move_ext_axis(self, axis, rot_position, rot_speed):
        '''
        A function to move a external axis to a specified position
        in degrees
        '''
        msg = '12 ' + str(int(axis)) + ' '
        msg += str(float(rot_position)) + ' '
        msg += str(float(rot_speed)) + ' #'
        #return
        return self.send(msg)

    def set_external_axis(self, axis_unscaled=[-550, 0, 0, 0, 0, 0]):
        if len(axis_unscaled) != 6:
            return False
        msg = "34 "
        for axis in axis_unscaled:
            msg += format(axis, "+08.2f") + " "
        msg += "#"
        return self.send(msg)

    def move_circular(self, pose_onarc, pose_end):
        '''
        Executes a movement in a circular path from current position,
        through pose_onarc, to pose_end
        '''
        try:
            msg_0 = "35 " + self.format_pose(pose_onarc)
            msg_1 = "36 " + self.format_pose(pose_end)

            data = self.send(msg_0).split()
            if data[1] != '1':
                log.warn('move_circular incorrect response, bailing!')
                return False
            return self.send(msg_1)
        except NameError as name:
            return str(name)

    def wait_time(self, value):
        '''
        A function to set time to wait.
        '''
        msg = '94 ' + str(float(value)) + ' #'
        #return
        return self.send(msg)

    def wait_input(self, value, id=0):
        '''
        A function to wait for a physical DII line on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the DIO you want this to switch.
        '''
        msg = '93 ' + str(int(id)) + ' ' + str(int(bool(value))) + ' #'
        #return
        return self.send(msg)

    def force_gdo(self, value, id=0):
        '''
        A function to force a value to a group of DO on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the AO you want this to switch.
        '''
        msg = '85 ' + str(int(id)) + ' ' + str(int(value)) + ' #'
        #return
        return self.send(msg)

    def set_gdo(self, value, id=0):
        '''
        A function to set a value to a group of DO on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the AO you want this to switch.
        '''
        msg = '95 ' + str(int(id)) + ' ' + str(int(value)) + ' #'
        #return
        return self.send(msg)

    def force_ao(self, value, id=0):
        '''
        A function to force a physical AO line on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the AO you want this to switch.
        '''
        msg = '86 ' + str(int(id)) + ' ' + str(float(value)) + ' #'
        #return
        return self.send(msg)

    def set_ao(self, value, id=0):
        '''
        A function to set a physical AO line on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the AO you want this to switch.
        '''
        msg = '96 ' + str(int(id)) + ' ' + str(float(value)) + ' #'
        #return
        return self.send(msg)

    def force_dio(self, value, id=0):
        '''
        A function to force a physical DIO line on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the DIO you want this to switch.
        '''
        msg = '87 ' + str(int(id)) + ' ' + str(int(bool(value))) + ' #'
        #return
        return self.send(msg)

    def set_dio(self, value, id=0):
        '''
        A function to set a physical DIO line on the robot.
        For this to work you're going to need to edit the RAPID function
        and fill in the DIO you want this to switch.
        '''
        msg = '97 ' + str(int(id)) + ' ' + str(int(bool(value))) + ' #'
        #return
        return self.send(msg)

    def send(self, message, wait_for_response=True):
        '''
        Send a formatted message to the robot socket.
        if wait_for_response, we wait for the response and return it
        '''
        caller = inspect.stack()[1][3]
        log.debug('%-14s sending: %s', caller, message)
        self.sock.send(message)
        time.sleep(self.delay)
        if not wait_for_response:
            return
        data = self.sock.recv(4096)
        log.debug('%-14s recieved: %s', caller, data)
        return data

    def format_pose(self, pose):
        pose = check_coordinates(pose)
        msg = ''
        for cartesian in pose[0]:
            msg += format(cartesian * self.scale_linear,  "+08.1f") + " "
        for quaternion in pose[1]:
            msg += format(quaternion, "+08.5f") + " "
        msg += "#"
        return msg

    def close(self):
        self.send("99 #", True)
        self.sock.shutdown(socket.SHUT_RDWR)
        self.sock.close()
        log.info('Disconnected from ABB robot.')

    def __enter__(self):
        return self

    def __exit__(self, type, value, traceback):
        self.close()


def check_coordinates(coordinates):
    if ((len(coordinates) == 2) and (len(coordinates[0]) == 3)
       and (len(coordinates[1]) == 4)):
        check_quaternions(coordinates[1])
        return coordinates
    elif (len(coordinates) == 7):
        check_quaternions(coordinates[3:7])
        return [coordinates[0:3], coordinates[3:7]]
    log.warn('Recieved malformed coordinate: %s', str(coordinates))
    raise NameError('PARAM_ERROR')

def check_quaternions(quat):
    d = 0
    for w in quat:
        d = d + w * w
    if round(d, 3) != 1:
        print 'Normalize quaternions'
        raise NameError('PARAM_ERROR')

if __name__ == '__main__':
    formatter = logging.Formatter(
        "[%(asctime)s] %(levelname)-7s (%(filename)s:%(lineno)3s) %(message)s",
        "%Y-%m-%d %H:%M:%S")
    handler_stream = logging.StreamHandler()
    handler_stream.setFormatter(formatter)
    handler_stream.setLevel(logging.DEBUG)
    log = logging.getLogger('abb')
    log.setLevel(logging.DEBUG)
    log.addHandler(handler_stream)
