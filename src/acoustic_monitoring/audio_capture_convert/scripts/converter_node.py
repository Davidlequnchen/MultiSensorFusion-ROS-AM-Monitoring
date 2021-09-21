#!/usr/bin/env python3

import rospy
from audio_common_msgs.msg import (
    AudioData
)
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped
)

class WebRTCVadNode:

    def __init__(self):

        self._audio_topic_name = rospy.get_param('~audio_topic_name', 'audio')

        self._pub = rospy.Publisher('audioStamped', AudioDataStamped, queue_size=5) 
        rospy.Subscriber(self._audio_topic_name, AudioData, self._audio_cb, queue_size=5)
        self._resp = AudioDataStamped()
        self._counter = 0

    def _audio_cb(self, msg):
        self._resp.header.stamp = rospy.Time.now()
        self._resp.header.seq = self._counter
        self._counter += 1
        self._resp.data = msg.data

        self._pub.publish(self._resp)

if __name__ == '__main__':
    rospy.init_node("conversion_node")
    vad = WebRTCVadNode()
    rospy.spin()
