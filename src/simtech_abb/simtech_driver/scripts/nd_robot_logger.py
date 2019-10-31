#!/usr/bin/env python
import rospy
import numpy as np
from sensor_msgs.msg import JointState
from abb.logger_robot import LoggerRobot


class NdRobotLogger():
    def __init__(self):
        rospy.init_node('robot_state', anonymous=False)

        self.pub = rospy.Publisher(
            'joint_states', JointState, queue_size=10)

        self.msg_joint_state = JointState()
        '''
        self.msg_joint_state.name = ['joint_1', 'joint_2', 'joint_3',
                                     'joint_4', 'joint_5', 'joint_6',
                                     'irbp_a250/joint2', 'irbp_a250/joint4']
        self.msg_joint_state.position = [0, 0, 0, 0, 0, 0, 0, 0]
        '''

        self.msg_joint_state.name = ['joint_1', 'joint_2', 'joint_3',
                                     'joint_4', 'joint_5', 'joint_6']
        self.msg_joint_state.position = [0, 0, 0, 0, 0, 0]

        robot_ip = rospy.get_param('~robot_ip', '192.168.30.4')
        j23_coupled = rospy.get_param('~J23_coupled', True)

        self.logger_robot = LoggerRobot()
        self.logger_robot.connect(robot_ip)
        self.talker(j23_coupled)

    def talker(self, j23_coupled=True):
        while not rospy.is_shutdown():
            if not self.logger_robot.read_raw_logger(): # failed to receive data from the robot server
                break
            if len(self.logger_robot.float_joints) > 0:
                self.msg_joint_state.header.stamp = rospy.Time.now()
                joints_pose = self.logger_robot.float_joints.popleft()
                for i in range(0, len(joints_pose)): #len(joints_pose)-3
                    self.msg_joint_state.position[i] = (
                        np.deg2rad(joints_pose[i]))
                if j23_coupled:
                    self.msg_joint_state.position[2] += (
                        -1 * self.msg_joint_state.position[1])
                #rospy.loginfo(len(logger_robot.joints))
                self.pub.publish(self.msg_joint_state)
            rospy.sleep(0.01)
        self.logger_robot.disconnect()


if __name__ == '__main__':
    try:
        NdRobotLogger()
    except rospy.ROSInterruptException:
        pass
