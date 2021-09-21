#!/usr/bin/env python3

'''
This is the noise filtering node
using scipy fft function to select the frequency, use a bandpass filter
'''


import numpy as np
from matplotlib import pyplot as plt
from scipy.io import wavfile
from scipy.fft import rfft, rfftfreq, irfft, fft, ifft, fftfreq
import rospy
from std_msgs.msg import (
    Bool
)
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
)

class FilterNode:

    def __init__(self):

        self._min_freq = rospy.get_param('~min_freq', 0)
        self._max_freq = rospy.get_param('~max_freq', 500)

        self._sample_rate = rospy.get_param('~sample_rate', 16000)
        self._frame_duration = rospy.get_param('~frame_duration', .010) #10 ms

        self._min_freq_scaled = int(self._min_freq * self._frame_duration)
        self._max_freq_scaled = int(self._max_freq * self._frame_duration)

        self._signal_pub = rospy.Publisher('filteredAudioStamped', AudioDataStamped, queue_size=5) 
        rospy.Subscriber('audioStamped', AudioDataStamped, self._audio_cb, queue_size=5)

    def _audio_cb(self, msg):

        # convert the audio to numpy array
        audio_data = msg.data
        audio_data_numpy = np.frombuffer(audio_data, dtype=np.int16)

        # get the fft
        audio_data_fft = fft(audio_data_numpy)

        # 0 out the parts of the fft using bandpass filter
        audio_data_fft[0 : self._min_freq_scaled] = 0
        audio_data_fft[self._max_freq_scaled : 80] = 0
        audio_data_fft[80 : 160 - self._max_freq_scaled] = 0
        audio_data_fft[160 - self._min_freq_scaled : 160] = 0

        # create the fittered wave to send to the vad
        audio_data_numpy_new = np.real(ifft(audio_data_fft)).astype('int16')
        audio_data_filtered = audio_data_numpy_new.tobytes()

        # create the message with the filtered audio to be sent to the VAD
        response = AudioDataStamped()
        response.header = msg.header
        response.data = audio_data_filtered
        # Add check for more graceful shutdown and don't publish if at the end.
        if not rospy.is_shutdown():
            self._signal_pub.publish(response)

if __name__ == '__main__':
    rospy.init_node("filter_node")
    audio_filter = FilterNode()
    rospy.spin()
