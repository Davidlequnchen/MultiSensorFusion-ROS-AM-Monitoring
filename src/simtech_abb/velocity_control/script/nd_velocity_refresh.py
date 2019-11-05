#!/usr/bin/env python
import rospy
import rospkg

from camera_measures.msg import MsgVelocity
from velocity_control.msg import MsgSpeedOverride


from velocity_controller.velocity_PID_controller import ControlSet
from velocity_controller.velocity_PID_controller import PIDController
import numpy as np


'''
this node subscribes topic: /Velocity, which is the instantaneous velocity of the robot.  -- (instantaneos minor axis)
It is a PID controller. 
Input variable: instantaneous velocity, Controlled variable(also driven force): SpeedOverride(0-100%), 
reference(nominal):nominal speed. Set_speed*CurrentSpeedOverride, e.g. v30* 50%, This is the predefined value by user.

CurrentSpeedOverride can be considered as the initial value of the SpeedOverride, ---- set power manual 

This node will keep publishing the ros message /velocity_control/SpeedOverride

This node is also a socket.
It will create a client socket which will send the controlled velocity value to the robot server.
Robot velocity server will receive the SpeedOverride(0-100%) and give this value to motion_server,
motion_server(T_ROB1) will execute speedRefresh SpeedOverride as a interrupt routine when doing MoveL, it will keep updating the SpeedOverride during robot movement.
'''


MANUAL = 0
AUTOMATIC = 1

class NdVelocityControl():
    def __init__(self):
        rospy.init_node('robot_velocity_control', anonymous=False)

        rospy.Subscriber(
            '/velocity', MsgVelocity, self.cb_velocity, queue_size=1)

        self.pub_SpeedOverride = rospy.Publisher(
            '/velocity_control/SpeedOverride', MsgSpeedOverride, queue_size=10)       


        self.msg_SpeedOverride = MsgSpeedOverride()
        self.control = ControlSet()
        #self.mode = AUTOMATIC
        self.mode = MANUAL

        self.setPIDparameters(rospy.get_param('/speed_control_parameters/pid_parameters'))
        self.setSpeedControlParameters(rospy.get_param('/speed_control_parameters/SpeedOverrideLimit'))
        self.setNominalParameters(rospy.get_param('/speed_control_parameters/CurrentSpeedOverride'))
        self.setpoint = self.CurrentSpeedOverride * 0.01 * self.speed_set

        self.control.pid.set_limits(self.SpeedOverride_min, self.SpeedOverride_max)
        self.control.pid.set_setpoint(self.setpoint)
        
        rospy.spin()

    def setPIDparameters(self, params):
        self.Kd = params['Kd']
        self.Ki = params['Ki']
        self.Kp = params['Kp']
        self.control.pid.set_parameters(self.Kp, self.Ki, self.Kd)


    def setNominalParameters(self, params):
        self.CurrentSpeedOverride = params['CurrentSpeedOverride']
        self.speed_set = params['speedSet']
    
    def setSpeedControlParameters(self, params):
        self.SpeedOverride_min = params['min']
        self.SpeedOverride_max = params['max']

    def cb_velocity(self, msg_velocity):
        stamp = msg_velocity.header.stamp
        time = stamp.to_sec()
        if self.mode == MANUAL:
            value = self.manual(self.CurrentSpeedOverride)
        elif self.mode == AUTOMATIC:
            value = self.automatic(msg_velocity.speed * 1000.0, time) # unit should be mm/s

        value = self.range(value)

        self.msg_SpeedOverride.header.stamp = stamp
        self.msg_SpeedOverride.value = value
        self.pub_SpeedOverride.publish(self.msg_SpeedOverride)



    def range(self, value):
        if value < self.SpeedOverride_min:
            value = self.SpeedOverride_min
        elif value > self.SpeedOverride_max:
            value = self.SpeedOverride_max
        return value

    def manual(self, SpeedOverride):
        value = self.control.pid.SpeedOverride(SpeedOverride)
        return value

    def automatic(self, ins_speed, time):
        value = self.control.pid.control_update(ins_speed, time)
        return value





if __name__ == '__main__':
    try:
        NdVelocityControl()
    except rospy.ROSInterruptException:
        pass
