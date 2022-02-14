#!/usr/bin/env python3
import rospy
import rospkg
import os

import numpy as np
from matplotlib import pyplot as plt
from scipy.io import wavfile
# from scipy.fft import rfft, rfftfreq, irfft, fft, ifft, fftfreq
import scipy
import math

import librosa
import sklearn

from audio_common_msgs.msg import AudioData
from audio_common_msgs.msg import AudioInfo
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
    MsgAcousticFeature,
)

# librosa default frame sie and hop length: 2048 and 512 samples
# for our ROS application - each chunck is 1/30 seconds, which contains around 533 data points

FRAME_SIZE = 2048 #1024
HOP_LENGTH = 512



class NdAudioSignal():
    def __init__(self):
        rospy.init_node("acoustic_feature_node")

        audio_topic_info = rospy.get_param('~audio_topic_info', '/audio_info')

        # subscribe the audio topic, and use callback function to visualise and post-process it. topic: filteredAudioStamped
        rospy.Subscriber('audioStamped', AudioDataStamped, self.cb_acoustic_signal, queue_size=5)
        rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)

        # publisher 
        self.pub_acoustic_feature = rospy.Publisher('/acoustic_feature',
                                                    MsgAcousticFeature, queue_size = 5)

        rospy.spin()
        # rate = rospy.Rate(10) # 10hz
        # while not rospy.is_shutdown():
        #     rate.sleep()


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

    def calculate_split_frequency_bin(self, split_frequency, sample_rate, num_frequency_bins):
        """Infer the frequency bin associated to a given split frequency."""
        frequency_range = sample_rate / 2
        frequency_delta_per_bin = frequency_range / num_frequency_bins
        split_frequency_bin = math.floor(split_frequency / frequency_delta_per_bin)
        return int(split_frequency_bin)


    def band_energy_ratio(self, spectrogram, split_frequency, sample_rate):
        """Calculate band energy ratio with a given split frequency."""
        split_frequency_bin = self.calculate_split_frequency_bin(split_frequency, sample_rate, len(spectrogram[0]))
        band_energy_ratio = []
        # calculate power spectrogram
        power_spectrogram = np.abs(spectrogram) ** 2
        power_spectrogram = power_spectrogram.T
        # calculate BER value for each frame
        for frame in power_spectrogram:
            sum_power_low_frequencies = frame[:split_frequency_bin].sum()
            sum_power_high_frequencies = frame[split_frequency_bin:].sum()
            band_energy_ratio_current_frame = sum_power_low_frequencies / sum_power_high_frequencies
            band_energy_ratio.append(band_energy_ratio_current_frame)
        return np.array(band_energy_ratio)





    def cb_acoustic_signal(self, msg_audio):
        # convert the audio to numpy array
        audio_data = msg_audio.data
        audio_data_numpy = np.frombuffer(audio_data, dtype=np.int16)  #np.int16
        nbits = 16
        temp = np.zeros(len(audio_data_numpy))
        temp = audio_data_numpy/(2**(nbits - 1))
        audio_data_numpy = temp
        # audio_data_numpy /= 2**(nbits - 1)

        ## -------------------------------Time-domain feature extraction-------------------------------------------
        ae = self.amplitude_envelope(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
        rms_energy = librosa.feature.rms(audio_data_numpy, frame_length=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        zero_crossing_rate = sum(librosa.zero_crossings(audio_data_numpy, pad=False))

        ## -------------------------------Frequency-domain feature extraction-------------------------------------
        ## Short-time FFT
        S_audio_data = librosa.stft(audio_data_numpy, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)
        Y_audio_data = np.abs(S_audio_data) ** 2 # calculation of power spectrogram (convert from complex number to real number), should be (r,c)
        Y_log_audio_data = librosa.power_to_db(Y_audio_data) # convert to log frequency

        ## Mel-spectrogram - mel scale representation
        # shape (n_mels, xxx)
        mel_spectrogram = librosa.feature.melspectrogram(audio_data_numpy, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH, n_mels=10)

        ## Mel-Frequency Cepstral Coefficients(MFCCs)
        # shape (n_mfcc, xxx)
        mfccs = librosa.feature.mfcc(y=audio_data_numpy, n_mfcc=13, sr=self.sampling_rate)
       
        ## Band-Energy Ratio: based on spectrogram (Short time FT)
        # 1D numpy array 
        ber = self.band_energy_ratio(S_audio_data, split_frequency=2000, sample_rate=self.sampling_rate)
        # ber_normalized = self.normalize(ber)
        
        ## spectral centroid 
        spectral_centroids = librosa.feature.spectral_centroid(y=audio_data_numpy, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0] 
        # spectral_centroids_normalized = self.normalize(spectral_centroids)
        ## spectral rolloff
        spectral_rolloff = librosa.feature.spectral_rolloff(y=audio_data_numpy+0.01, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        # spectral_rolloff_normalized = self.normalize(spectral_rolloff)
        ## spectral bandwidth
        spectral_bandwidth = librosa.feature.spectral_bandwidth(y=audio_data_numpy, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        # spectral_bandwidth_normalized = self.normalize(spectral_bandwidth)

        
        # initialise the message objects
        msg_acoustic_feature = MsgAcousticFeature()
        msg_acoustic_feature.header = msg_audio.header
        msg_acoustic_feature.rms_energy = rms_energy ## without scaling
        msg_acoustic_feature.amplitude_envelope = ae
        msg_acoustic_feature.zero_crossing_rate = zero_crossing_rate
        # frequency-domain feature
        msg_acoustic_feature.mel_spectrogram = mel_spectrogram
        msg_acoustic_feature.mfccs = mfccs
        msg_acoustic_feature.ber = ber
        msg_acoustic_feature.spectral_centroids = spectral_centroids
        msg_acoustic_feature.spectral_rolloff = spectral_rolloff
        msg_acoustic_feature.spectral_bandwidth = spectral_bandwidth

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
