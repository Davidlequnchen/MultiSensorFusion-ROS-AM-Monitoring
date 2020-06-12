#!/usr/bin/env python
import rospy

from camera_measures.msg import MsgVelocity
from camera_measures.msg import MsgVelocityStatus



class NdSupervisor():
    def __init__(self):
        rospy.init_node('velocity_supervisor')

        self.pub_status = rospy.Publisher(
            '/supervisor/velocity_status', MsgVelocityStatus, queue_size=10)

        rospy.Subscriber(
            '/velocity', MsgVelocity, self.cb_velocity, queue_size=1)
        

        self.msg_vstatus = MsgVelocityStatus()
        self.msg_vstatus.running = False

        r = rospy.Rate(10)  # 10hz
        while not rospy.is_shutdown():
            self.cb_status()
            r.sleep()

    def cb_status(self):
        #stamp = rospy.Time.now()
        self.pub_status.publish(self.msg_vstatus)

    def cb_velocity(self, msg_velocity):
        speed = 0
        running = False
        if msg_velocity.speed > 0.0005:
            running = True
            speed = 1000 * msg_velocity.speed
        self.msg_vstatus.running = running
        self.msg_vstatus.speed = speed


if __name__ == '__main__':
    try:
        NdSupervisor()
    except rospy.ROSInterruptException:
        pass
