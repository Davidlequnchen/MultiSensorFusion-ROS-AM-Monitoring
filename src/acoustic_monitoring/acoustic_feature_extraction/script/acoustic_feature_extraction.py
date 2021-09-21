#!/usr/bin/env python3
import rospy
import rospkg
import os

import numpy as np
from matplotlib import pyplot as plt
from scipy.io import wavfile
from scipy.fft import rfft, rfftfreq, irfft, fft, ifft, fftfreq

import librosa
import sklearn

from audio_common_msgs.msg import AudioData
from audio_common_msgs.msg import AudioInfo
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
    MsgAcousticFeature,
)

# librosa default frame sie and ho length: 2048 and 512 samples
# for our ROS application - each chunck is 1/30 seconds, which contains around 533 data points

FRAME_SIZE = 256
HOP_LENGTH = 512



class NdAudioSignal():
    def __init__(self):
        rospy.init_node("acoustic_feature_node")

        audio_topic_info = rospy.get_param('~audio_topic_info', '/audio_info')

        # subscribe the audio topic, and use callback function to visualise and post-process it. topic: filteredAudioStamped
        rospy.Subscriber('audioStamped', AudioDataStamped, self.cb_acoustic_features, queue_size=5)
        rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)

        # publisher 
        self.pub_acoustic_feature = rospy.Publisher('/acoustic_feature',
                                                    MsgAcousticFeature, queue_size = 5)


        rospy.spin()


    def cb_audio_info(self, msg_audio_info):
        self.channels = msg_audio_info.channels
        self.sampling_rate = msg_audio_info.sample_rate
        self.sample_format = msg_audio_info.sample_format
        self.coding_format = msg_audio_info.coding_format

    # Normalising the spectral centroid for visualisation
    def normalize(self, x, axis=0):
        return sklearn.preprocessing.minmax_scale(x, axis=axis)

    def spectral_centroid(self, x, samplerate=44100):
        samplerate = self.sampling_rate
        magnitudes = np.abs(np.fft.rfft(x)) # magnitudes of positive frequencies
        length = len(x)
        freqs = np.abs(np.fft.fftfreq(length, 1.0/samplerate)[:length//2+1]) # positive frequencies
        return np.sum(magnitudes*freqs) / np.sum(magnitudes) # return weighted mean

    def amplitude_envelope(self, signal, frame_size, hop_length):
        """calculate the amplitude envelope of a signal with a given frame size."""
        return np.array([max(signal[i:i+frame_size]) for i in range(0, len(signal), hop_length)])

    def cb_acoustic_features(self, msg_audio):
        # convert the audio to numpy array
        audio_data = msg_audio.data
        audio_data_numpy = np.frombuffer(audio_data, dtype=np.int16)  #np.int16
        nbits = 16
        temp = np.zeros(len(audio_data_numpy))
        temp = audio_data_numpy/(2**(nbits - 1))
        audio_data_numpy = temp
        # audio_data_numpy /= 2**(nbits - 1)

        ## Time-domain feature extraction
        # rms_energy = librosa.feature.rms(audio_data_numpy, frame_length=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        ae = self.amplitude_envelope(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
        # ae = self.amplitude_envelope(audio_data_numpy)
        rms_energy = librosa.feature.rms(audio_data_numpy)[0]
        zero_crossing_rate = sum(librosa.zero_crossings(audio_data_numpy, pad=False))

        ## Frequency-domain feature extraction
        # spectral_centroids = librosa.feature.spectral_centroid(audio_data_numpy, sr=self.sampling_rate)[0] 
        # spectral_rolloff = librosa.feature.spectral_rolloff(audio_data_numpy+0.01, sr=self.sampling_rate)[0]
        # Mel-Frequency Cepstral Coefficients(MFCCs)
        mfccs = librosa.feature.mfcc(audio_data_numpy, sr=self.sampling_rate)
        mfccs_mean = np.mean(mfccs)
        mfccs_variance = np.var(mfccs)
        mfccs_max = np.amax(mfccs)
        mfccs_min = np.amin(mfccs)
        mfccs_std = np.std(mfccs.T, axis = 0)



        # spectral_centroids = self.spectral_centroid(audio_data_numpy) # using numpy method
        # spectral_centroids_normalized = self.normalize(spectral_centroids)
        
        # initialise the message objects
        msg_acoustic_feature = MsgAcousticFeature()
        msg_acoustic_feature.header = msg_audio.header
        msg_acoustic_feature.rms_energy = rms_energy ## without scaling
        msg_acoustic_feature.amplitude_envelope = ae
        msg_acoustic_feature.zero_crossing_rate = zero_crossing_rate
        # frequency-domain feature
        # msg_acoustic_feature.spectral_centroids = spectral_centroids_normalized
        # msg_acoustic_feature.spectral_rolloff = spectral_rolloff
        # msg_acoustic_feature.mfccs_variance = mfccs_variance
        # msg_acoustic_feature.mfccs_mean = mfccs_mean

        self.pub_acoustic_feature.publish(msg_acoustic_feature)



if __name__ == '__main__':
    try:
        NdAudioSignal()
    except rospy.ROSInterruptException:
        pass
