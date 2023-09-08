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

FRAME_SIZE = 1024 #1024
HOP_LENGTH = 512



        rospy.init_node("acoustic_feature_node")

        audio_topic_info = rospy.get_param('~audio_topic_info', '/audio_info')

        # subscribe the audio topic, and use callback function to visualise and post-process it. topic: filteredAudioStamped
        rospy.Subscriber('audioStamped', AudioDataStamped, self.cb_acoustic_signal, queue_size=2)
        rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)

        # publisher 
        self.pub_acoustic_feature = rospy.Publisher('/acoustic_feature',
                                                    MsgAcousticFeature, queue_size = 2)

        rospy.spin()
        # rate = rospy.Rate(10) # 10hz
        # while not rospy.is_shutdown():
        #     rate.sleep()


        self.channels = msg_audio_info.channels
        self.sampling_rate = msg_audio_info.sample_rate
        self.sample_format = msg_audio_info.sample_format
        self.coding_format = msg_audio_info.coding_format

    # Normalising the spectral centroid for visualisation
        return sklearn.preprocessing.minmax_scale(x, axis=axis)

        samplerate = self.sampling_rate
        magnitudes = np.abs(np.fft.rfft(x)) # magnitudes of positive frequencies
        length = len(x)
        freqs = np.abs(np.fft.fftfreq(length, 1.0/samplerate)[:length//2+1]) # positive frequencies
        return np.sum(magnitudes*freqs) / np.sum(magnitudes) # return weighted mean

        """calculate the amplitude envelope of a signal with a given frame size."""
        return np.array([max(signal[i:i+frame_size]) for i in range(0, len(signal), hop_length)])

        """Infer the frequency bin associated to a given split frequency."""
        frequency_range = sample_rate / 2
        frequency_delta_per_bin = frequency_range / num_frequency_bins
        split_frequency_bin = math.floor(split_frequency / frequency_delta_per_bin)
        return int(split_frequency_bin)


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
        msg_acoustic_feature = MsgAcousticFeature()
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
        # msg_acoustic_feature.

        ## time-freqeuncy representations
        # msg_acoustic_feature.mel_spectrogram = mel_spectrogram
        msg_acoustic_feature.mfccs = mfccs

        self.pub_acoustic_feature.publish(msg_acoustic_feature)



if __name__ == '__main__':
    try:
        NdAudioSignal()
    except rospy.ROSInterruptException:
        pass
    def extract_rms_energy(self, audio_data, frame_size, hop_length):
        return librosa.feature.rms(audio_data, frame_length=frame_size, hop_length=hop_length)[0]
    def extract_zero_crossing_rate(self, audio_data):
        return sum(librosa.zero_crossings(audio_data, pad=False))
    def extract_stft(self, audio_data, frame_size, hop_length):
        return librosa.stft(audio_data, n_fft=frame_size, hop_length=hop_length)
    def extract_mfccs(self, audio_data, sr, n_mfcc=13):
        return librosa.feature.mfcc(y=audio_data, n_mfcc=n_mfcc, sr=sr)
    def extract_spectral_centroids(self, audio_data, sr, frame_size, hop_length):
        return librosa.feature.spectral_centroid(y=audio_data, sr=sr, n_fft=frame_size, hop_length=hop_length)[0]
    def extract_spectral_rolloff(self, audio_data, sr):
        return librosa.feature.spectral_rolloff(y=audio_data, sr=sr, roll_percent=0.85)
    def extract_spectral_bandwidth(self, audio_data, sr, frame_size, hop_length):
        return librosa.feature.spectral_bandwidth(y=audio_data, sr=sr, n_fft=frame_size, hop_length=hop_length)[0]
    def extract_spectral_flatness(self, audio_data, frame_size, hop_length):
        return librosa.feature.spectral_flatness(y=audio_data, power=2, n_fft=frame_size, hop_length=hop_length)[0]
    def extract_spectral_kurtosis(self, S_power):
        return scipy.stats.kurtosis(abs(S_power))
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
            rms_energy = self.extract_rms_energy(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
            zero_crossing_rate = self.extract_zero_crossing_rate(audio_data_numpy)
    
            ## -------------------------------Frequency-domain feature extraction-------------------------------------
            ## Short-time FFT
            S_audio_data = self.extract_stft(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
            S_power, phase = librosa.magphase(S_audio_data)
            mfccs = self.extract_mfccs(audio_data_numpy, self.sampling_rate)
           
            ## Band-Energy Ratio: based on spectrogram (Short time FT)
            # 1D numpy array 
            # ber = self.band_energy_ratio(S_audio_data, split_frequency=200, sample_rate=self.sampling_rate)
            # ber_normalized = self.normalize(ber)
            
            ## spectral centroid 
            spectral_centroids = self.extract_spectral_centroids(audio_data_numpy, self.sampling_rate, FRAME_SIZE, HOP_LENGTH)
            # spectral_centroids_normalized = self.normalize(spectral_centroids)
            ## spectral rolloff
            spectral_rolloff = self.extract_spectral_rolloff(audio_data_numpy, self.sampling_rate)
            # spectral_rolloff_normalized = self.normalize(spectral_rolloff)
            ## spectral bandwidth
            spectral_bandwidth = self.extract_spectral_bandwidth(audio_data_numpy, self.sampling_rate, FRAME_SIZE, HOP_LENGTH)
            # spectral_bandwidth_normalized = self.normalize(spectral_bandwidth)
            ## spectral flatness
            spectral_flatness = self.extract_spectral_flatness(audio_data_numpy, FRAME_SIZE, HOP_LENGTH)
            ## spectral kurtosis
            spectral_kurtosis = self.extract_spectral_kurtosis(S_power)
            ## spectral variance
            spectral_variance = scipy.stats.variation(abs(S_power))
            ## spectral crest factor
            # spectral_crest_factor = self.spectral_crest(S_power)
    
            
            # initialise the message objects
            msg_acoustic_feature = MsgAcousticFeature()
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
            # msg_acoustic_feature.
    
            ## time-freqeuncy representations
            # msg_acoustic_feature.mel_spectrogram = mel_spectrogram
            msg_acoustic_feature.mfccs = mfccs
    
            self.pub_acoustic_feature.publish(msg_acoustic_feature)
    
    
    
    if __name__ == '__main__':
        try:
            NdAudioSignal()
        except rospy.ROSInterruptException: