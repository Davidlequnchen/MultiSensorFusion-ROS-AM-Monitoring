#!/usr/bin/env python
import os
import rospy
import rospkg

from laser_control.msg import MsgControl
from laser_control.msg import MsgPower
from laser_control.msg import MsgInfo
from laser_control.msg import MsgStart
from camera_measures.msg import MsgGeometry
from camera_measures.msg import MsgStatus

from control.control import Control
from control.control import PID
import numpy as np


MANUAL = 0
STEP = 2
AUTOMATIC = 1


class NdControl():
    def __init__(self):
        rospy.init_node('control')
        rospy.Subscriber(
            '/usb_cam/geometry', MsgGeometry, self.cb_geometry, queue_size=1)
        rospy.Subscriber(
            '/control/parameters', MsgControl, self.cb_control, queue_size=1)
        rospy.Subscriber(
            '/supervisor/status', MsgStatus, self.cb_status, queue_size=1)
        self.pub_power = rospy.Publisher(
            '/control/power', MsgPower, queue_size=10)
        self.pub_info = rospy.Publisher(
            '/control/info', MsgInfo, queue_size=10)
        self.pub_start = rospy.Publisher(
            '/control/start', MsgStart, queue_size=10)


        self.msg_power = MsgPower()
        self.msg_info = MsgInfo()
        self.msg_start = MsgStart()
        self.mode = MANUAL

        self.status = False

        self.time_step = float(0)
        self.step_increase = 100
        self.control = Control()
        self.updateParameters()
        self.start = False

        self.track= []

        self.track_number = 0
        self.t_reg = 0
        self.time_control = 0
        self.track_control = 3
        self.auto_mode = 0
        self.control_time_interval = 0
        self.power_ant = 0
        self.setFirstPowerValue = True

        self.setPowerParameters(rospy.get_param('/control_parameters/power'))
        self.control.pid.set_limits(self.power_min, self.power_max)
        self.control.pid.set_setpoint(self.setpoint)

        rospy.spin()

    def setParameters(self, params):
        self.Kp = params['Kp']
        self.Ki = params['Ki']
        self.Kd = params['Kd']
        self.control.pid.set_parameters(self.Kp, self.Ki, self.Kd)
        # print 'Kp:', self.Kp, 'Ki:', self.Ki, 'Kd', self.Kd

    def setManualParameters(self, params):
        self.power = params['power']

    def setAutoParameters(self, params):
        self.setpoint = params['width']
        self.control_time_interval = params['time']
        self.auto_mode = params['mode']

    def setPowerParameters(self, params):
        self.power_min = params['min']
        self.power_max = params['max']

    def setStepParameters(self, params):
        self.power_step = params['power']
        self.trigger = params['trigger']

    def updateParameters(self):
        # get the ros parameter, which is set from 'control_parameters.yaml' file
        self.setParameters(rospy.get_param('/control_parameters/pid_parameters')) 
        self.setStepParameters(rospy.get_param('/control_parameters/step'))
        self.setManualParameters(rospy.get_param('/control_parameters/manual'))
        self.setAutoParameters(rospy.get_param('/control_parameters/automatic'))

    def cb_control(self, msg_control):
        self.mode = msg_control.value # mode set by qt, either continuous(time) or tracks
        self.updateParameters()
        # self.t_auto = 0.01* self.control_time_interval
        # self.t_reg = 0.005* self.control_time_interval 
        self.track_number = 0
        self.time_step= 0
        self.control.pid.set_setpoint(self.setpoint)
        #-----------------------------------------
        self.control_change = msg_control.change

    def cb_status(self, msg_status):
        self.power_ant = msg_status.power
        if msg_status.laser_on and not self.status:
            self.time_step = 0
            self.track_number += 1
        self.status = msg_status.laser_on

    def cb_geometry(self, msg_geo):
        stamp = msg_geo.header.stamp
        time = stamp.to_sec()
        if self.mode == MANUAL:
            self.setFirstPowerValue = True
            value = self.manual(self.power)
        elif self.mode == AUTOMATIC:
            value = self.automatic(msg_geo.minor_axis, time)
        elif self.mode == STEP:
            value = self.step(time)
        value = self.range(value)
        value = self.cooling(msg_geo.minor_axis, value) 
        self.msg_power.header.stamp = stamp
        self.msg_power.value = value
        self.msg_info.time = str(self.time_control)
        self.msg_info.track_number = self.track_number
        rospy.set_param('/control/power', value)
        self.pub_power.publish(self.msg_power)
        self.pub_info.publish(self.msg_info)
        start = self.msg_start.control
        if start is not self.start:
            self.control.pid.set_setpoint(self.setpoint)
            self.msg_start.setpoint = self.setpoint
            self.pub_start.publish(self.msg_start)
        self.start = start

    def manual(self, power):
        value = self.control.pid.power(power)
        return value

    def automatic(self, minor_axis, time):
        # if self.time_step == 0:
        #     self.time_step = time
        #     self.control.pid.time = time
        # self.time_control= time - self.time_step
        # value = self.power
        # self.msg_start.control = False
        # if self.status and self.time_step > 0:
        #     if self.auto_mode is 0:    # continous mode, use time
        #         if self.time_control > self.t_reg and self.time_control < self.t_auto:
        #             self.auto_setpoint(minor_axis)
        #         if self.time_control > self.t_auto:
        #             value = self.control.pid.update(minor_axis, time)
        #             self.msg_start.control = True
        #     elif self.auto_mode is 1:   # use track number
        #         if self.track_number is 3:
        #             self.auto_setpoint(minor_axis)
        #         if self.track_number >= 4:
        #             value = self.control.pid.update(minor_axis, time)
        #             self.msg_start.control = True
        # return value
        
        if self.setFirstPowerValue:
            self.controlled_value = self.power
            self.setFirstPowerValue = False

        if self.time_step == 0:
            self.time_step = time
            self.control.pid.time = time
        self.time_control= time - self.time_step
        # value = self.power
        self.msg_start.control = False
        if self.status and self.time_step > 0:
            if self.auto_mode is 0:    # continous mode, use time
                if self.time_control < self.control_time_interval:
                    self.auto_setpoint(minor_axis)
                if self.time_control > self.control_time_interval:
                    self.controlled_value = self.control.pid.update(minor_axis, time)
                    self.msg_start.control = True
            elif self.auto_mode is 1:   # use track number
                if self.track_number is 3:
                    self.auto_setpoint(minor_axis)
                if self.track_number >= 4:
                    self.controlled_value = self.control.pid.update(minor_axis, time)
                    self.msg_start.control = True
        
        value = self.controlled_value
        return value




    def auto_setpoint(self, minor_axis):
        self.track.append(minor_axis)
        self.setpoint = sum(self.track)/len(self.track)

    def step(self, time):
        #Step time
        if self.time_step == 0:
            self.time_step = time
        if self.status and self.time_step > 0 and time - self.time_step > self.trigger:
            value = self.power_step
        else:
            value = self.power
        return value

    def range(self, value):
        if value < self.power_min:
            value = self.power_min
        elif value > self.power_max:
            value = self.power_max
        #if  not self.status:
        #    value = 0
        return value

    def cooling(self, msg_geo, value):
        
        if msg_geo > 180:
            value = 0
        return value
        #avoiding overheating


if __name__ == '__main__':
    try:
        NdControl()
    except rospy.ROSInterruptException:
        pass
