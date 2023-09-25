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
    MsgAcousticFeaturePython
)

# librosa default frame sie and hop length: 2048 and 512 samples
# for our ROS application - each chunck is 1/30 seconds, which contains around 533 data points

FRAME_SIZE = 1024 #1024
HOP_LENGTH = 512



class NdAudioSignal():
    def __init__(self):
        rospy.init_node("acoustic_feature_node")

        audio_topic_info = rospy.get_param('~audio_topic_info', '/audio_info')

        # subscribe the audio topic, and use callback function to visualise and post-process it. topic: filteredAudioStamped
        rospy.Subscriber('audioStamped', AudioDataStamped, self.cb_acoustic_signal, queue_size=2)
        rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)

        # publisher 
        self.pub_acoustic_feature = rospy.Publisher('/acoustic_feature',
                                                    MsgAcousticFeaturePython, queue_size = 2)

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

    def spectral_crest(spectrum):
        """
        Compute the spectral crest factor, i.e. the ratio of the maximum of the spectrum to the
        sum of the spectrum
        reference:
        - https://github.com/jsawruk/pymir/blob/master/pymir/Spectrum.py
        - https://dsp.stackexchange.com/questions/27221/calculating-rms-crest-factor-for-a-stereo-signal
        """
        # absSpectrum = abs(spectrum)
        absSpectrum = np.absolute(spectrum)
        spectralSum = np.sum(absSpectrum)

        maxFrequencyIndex = np.argmax(absSpectrum)
        # maxSpectrum = absSpectrum[maxFrequencyIndex]
        maxSpectrum = np.amax(absSpectrum, axis=0)

        return maxSpectrum / spectralSum



    def cb_acoustic_signal(self, msg_audio):
        nbits = 16 # Each sample is 2 bytes
        scale_factor = 2**(nbits - 1)
        # Convert the audio to a numpy array and scale it in one step
        audio_data_numpy = np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor

        ## -------------------------------Time-domain feature extraction-------------------------------------------
        ae = self.amplitude_envelope(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
        rms_energy = librosa.feature.rms(y=audio_data_numpy, frame_length=FRAME_SIZE, hop_length=HOP_LENGTH)[0][0]
        zero_crossing_rate = sum(librosa.zero_crossings(audio_data_numpy, pad=False))

        ## -------------------------------Frequency-domain feature extraction-------------------------------------
        ## Short-time FFT
        S_audio_data = librosa.stft(audio_data_numpy, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)
        S_power, phase = librosa.magphase(S_audio_data)
        mfccs = librosa.feature.mfcc(y=audio_data_numpy, n_mfcc=13, sr=self.sampling_rate)
       
        ## Band-Energy Ratio: based on spectrogram (Short time FT)
        # 1D numpy array 
        # ber = self.band_energy_ratio(S_audio_data, split_frequency=200, sample_rate=self.sampling_rate)
        # ber_normalized = self.normalize(ber)
        
        ## spectral centroid 
        spectral_centroids = librosa.feature.spectral_centroid(y=audio_data_numpy, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0] 
        # spectral_centroids_normalized = self.normalize(spectral_centroids)
        ## spectral rolloff
        spectral_rolloff = librosa.feature.spectral_rolloff(y=audio_data_numpy, sr=self.sampling_rate, roll_percent=0.85)
        # spectral_rolloff_normalized = self.normalize(spectral_rolloff)
        ## spectral bandwidth
        spectral_bandwidth = librosa.feature.spectral_bandwidth(y=audio_data_numpy, sr=self.sampling_rate, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        # spectral_bandwidth_normalized = self.normalize(spectral_bandwidth)
        ## spectral flatness
        spectral_flatness = librosa.feature.spectral_flatness(y = audio_data_numpy, power=2, n_fft=FRAME_SIZE, hop_length=HOP_LENGTH)[0]
        ## spectral kurtosis
        spectral_kurtosis = scipy.stats.kurtosis(abs(S_power))
        ## spectral variance
        spectral_variance = scipy.stats.variation(abs(S_power))
        ## spectral crest factor
        # spectral_crest_factor = self.spectral_crest(S_power)

        
        # initialise the message objects
        msg_acoustic_feature = MsgAcousticFeaturePython()
        msg_acoustic_feature.header = msg_audio.header
        ## time-domain features
        msg_acoustic_feature.rms_energy = rms_energy ## without scaling
        msg_acoustic_feature.amplitude_envelope = ae
        msg_acoustic_feature.zero_crossing_rate = zero_crossing_rate
        # msg_acoustic_feature.ber = ber

        ## frequency-domain feature
        msg_acoustic_feature.spectral_centroids = spectral_centroids
        msg_acoustic_feature.spectral_rolloff = spectral_rolloff
        msg_acoustic_feature.spectral_bandwidth = spectral_bandwidth
        msg_acoustic_feature.spectral_kurtosis = spectral_kurtosis
        msg_acoustic_feature.spectral_flatness = spectral_flatness
        msg_acoustic_feature.spectral_variance = spectral_variance
        # msg_acoustic_feature.spectral_crest_factor = spectral_crest_factor


        ## time-freqeuncy representations
        # msg_acoustic_feature.mel_spectrogram = mel_spectrogram
        msg_acoustic_feature.mfccs = mfccs

        self.pub_acoustic_feature.publish(msg_acoustic_feature)



if __name__ == '__main__':
    try:
        NdAudioSignal()
    except rospy.ROSInterruptException:
        pass