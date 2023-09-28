#!/usr/bin/env python3
import rospy
# import rospkg
import os
import numpy as np
from matplotlib import pyplot as plt
from scipy.io import wavfile
import scipy
import math
import numpy as np
from collections import deque
import essentia.standard as es
from essentia.standard import Spectrum, Windowing, SpectralCentroidTime, SpectralComplexity, SpectralContrast
from essentia.standard import Decrease, Energy, EnergyBandRatio, FlatnessDB, Flux, RollOff, StrongPeak, CentralMoments
from essentia.standard import DistributionShape, Crest, MelBands, MFCC

from audio_common_msgs.msg import AudioData
from audio_common_msgs.msg import AudioInfo
from acoustic_monitoring_msgs.msg import (
    AudioDataStamped,
    MsgAcousticFeature,
    MsgAcousticFeaturePython
)

class AcousticFeatureExtractor:
    def __init__(self):
        self.nh = rospy.init_node('acoustic_feature_extractor', anonymous=True)
        audio_topic_info = rospy.get_param('~audio_topic_info', '/audio_info')

        # Initialize parameters
        self.frame_size = rospy.get_param("~frame_size", 1024)
        self.hop_length = rospy.get_param("~hop_length", 512)
        self.sample_rate = rospy.get_param("~sample_rate", 44100)
        self.buffer_duration = rospy.get_param("~buffer_size", 100) #100 ms
        self.buffer_size = int(self.buffer_duration * 0.001 * self.sample_rate)
        self.audio_buffer = deque(maxlen=self.buffer_size)  # Max buffer size to hold 100 ms of audio data (4410 samples)
        
        # Initialize Essentia algorithms
        self.rms_algo = es.RMS()
        self.envelope_algo = es.Envelope()
        self.zcr_algo = es.ZeroCrossingRate()
        self.dyn_algo = es.DynamicComplexity()
        self.loudness_algo = es.LoudnessVickers()
        # Initialize the algorithms
        self.window_algo = Windowing(type='hann')
        self.spectrum_algo = Spectrum()
        self.centroid_algo = SpectralCentroidTime(sampleRate=self.sample_rate)
        self.complexity_algo = SpectralComplexity(sampleRate=self.sample_rate)
        self.contrast_algo = SpectralContrast(frameSize=self.buffer_size, highFrequencyBound=self.sample_rate/2, lowFrequencyBound=200, sampleRate=self.sample_rate)
        self.decrease_algo = Decrease()
        self.energy_algo = Energy()
        self.energy_band_ratio_algo = EnergyBandRatio(sampleRate=self.sample_rate, stopFrequency=7000)
        self.flatness_algo = FlatnessDB()
        self.spectral_flux = Flux()
        self.rolloff_algo = RollOff(sampleRate=self.sample_rate)
        self.strong_peak_algo = StrongPeak()
        self.central_moment_algo = CentralMoments()
        self.distrubution_shape = DistributionShape()
        self.spectral_crest_factor = Crest()
        self.mfcc_algo = MFCC(highFrequencyBound=self.sample_rate/2, numberCoefficients=13, sampleRate=self.sample_rate)

        self.audio_sub = rospy.Subscriber("audioStamped", AudioDataStamped, self.audio_callback, queue_size=20)
        self.audio_info_sub = rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)
        self.audio_feature_pub = rospy.Publisher("/acoustic_feature", MsgAcousticFeature, queue_size=10)

        rospy.spin()


    def cb_audio_info(self, msg_audio_info):
        self.channels = msg_audio_info.channels
        self.sample_rate = msg_audio_info.sample_rate
        self.sample_format = msg_audio_info.sample_format
        self.coding_format = msg_audio_info.coding_format


        
    def audio_callback(self, msg_audio):

        nbits = 16 # Each sample is 2 bytes
        scale_factor = 2**(nbits - 1)
        # Convert the audio to a numpy array and scale it in one step
        audio_data_numpy = (np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor)

        # Update the buffer with the new audio data
        self.audio_buffer.extend(audio_data_numpy)

        # Ensure that the buffer size is exactly 4410 samples
        if len(self.audio_buffer) < self.buffer_size:
            # Pad with zeros if smaller than desired
            self.audio_buffer.extend([0.0] * (self.buffer_size - len(self.audio_buffer)))
        elif len(self.audio_buffer) > self.buffer_size:
            # Trim if larger than desired
            self.audio_buffer = deque(list(self.audio_buffer)[-self.buffer_siz:], maxlen=self.buffer_siz)

        # Convert deque to numpy array for feature extraction
        audio_data_buffered = np.array(self.audio_buffer).astype(np.float32)


        time_features = self.extract_time_features(audio_data_buffered)
        freqeuncy_features = self.extract_frequency_features(audio_data_buffered)

        msg_acoustic_feature = MsgAcousticFeature()
        msg_acoustic_feature.header = msg_audio.header
        ## time-domain features
        msg_acoustic_feature.rms_energy = time_features["rms_energy"]
        msg_acoustic_feature.amplitude_envelope_mean = time_features['amplitude_envelope_mean'] 
        msg_acoustic_feature.amplitude_envelope_std = time_features['amplitude_envelope_std']
        msg_acoustic_feature.zero_crossing_rate = time_features['zero_crossing_rate']
        msg_acoustic_feature.dynamic_complexity = time_features['dynamic_complexity']
        msg_acoustic_feature.loudness = time_features['loudness']
        msg_acoustic_feature.loudness_vickers = time_features['loudness_vickers']
        ## frequency-domain features
        msg_acoustic_feature.spectral_centroid = freqeuncy_features['spectral_centroid']
        msg_acoustic_feature.spectral_complexity = freqeuncy_features['spectral_complexity']
        msg_acoustic_feature.spectral_contrast_0 = freqeuncy_features['spectral_contrast_0']
        msg_acoustic_feature.spectral_contrast_1 = freqeuncy_features['spectral_contrast_1']
        msg_acoustic_feature.spectral_contrast_2 = freqeuncy_features['spectral_contrast_2']
        msg_acoustic_feature.spectral_contrast_3 = freqeuncy_features['spectral_contrast_3']
        msg_acoustic_feature.spectral_contrast_4 = freqeuncy_features['spectral_contrast_4']
        msg_acoustic_feature.spectral_contrast_5 = freqeuncy_features['spectral_contrast_5']
        msg_acoustic_feature.spectral_valley_0 = freqeuncy_features['spectral_valley_0']
        msg_acoustic_feature.spectral_valley_1 = freqeuncy_features['spectral_valley_1']
        msg_acoustic_feature.spectral_valley_2 = freqeuncy_features['spectral_valley_2']
        msg_acoustic_feature.spectral_valley_3 = freqeuncy_features['spectral_valley_3']
        msg_acoustic_feature.spectral_valley_4 = freqeuncy_features['spectral_valley_4']
        msg_acoustic_feature.spectral_valley_5 = freqeuncy_features['spectral_valley_5']
        msg_acoustic_feature.spectral_decrease = freqeuncy_features['spectral_decrease']
        msg_acoustic_feature.spectral_energy = freqeuncy_features['spectral_energy']
        msg_acoustic_feature.spectral_energy_band_ratio = freqeuncy_features['spectral_energy_band_ratio']
        msg_acoustic_feature.spectral_flatness = freqeuncy_features['spectral_flatness']
        msg_acoustic_feature.spectral_flux = freqeuncy_features['spectral_flux']
        msg_acoustic_feature.spectral_rolloff = freqeuncy_features['spectral_rolloff']
        msg_acoustic_feature.spectral_strong_peak = freqeuncy_features['spectral_strong_peak']
        msg_acoustic_feature.spectral_variance = freqeuncy_features['spectral_variance']
        msg_acoustic_feature.spectral_skewness = freqeuncy_features['spectral_skewness']
        msg_acoustic_feature.spectral_kurtosis = freqeuncy_features['spectral_kurtosis']
        msg_acoustic_feature.spectral_crest_factor = freqeuncy_features['spectral_crest_factor']
        msg_acoustic_feature.mfcc_0 = freqeuncy_features['mfcc_0']
        msg_acoustic_feature.mfcc_1 = freqeuncy_features['mfcc_1']
        msg_acoustic_feature.mfcc_2 = freqeuncy_features['mfcc_2']
        msg_acoustic_feature.mfcc_3 = freqeuncy_features['mfcc_3']
        msg_acoustic_feature.mfcc_4 = freqeuncy_features['mfcc_4']
        msg_acoustic_feature.mfcc_5 = freqeuncy_features['mfcc_5']
        msg_acoustic_feature.mfcc_6 = freqeuncy_features['mfcc_6']
        msg_acoustic_feature.mfcc_7 = freqeuncy_features['mfcc_7']
        msg_acoustic_feature.mfcc_8 = freqeuncy_features['mfcc_8']
        msg_acoustic_feature.mfcc_9 = freqeuncy_features['mfcc_9']
        msg_acoustic_feature.mfcc_10 = freqeuncy_features['mfcc_10']
        msg_acoustic_feature.mfcc_11 = freqeuncy_features['mfcc_11']
        msg_acoustic_feature.mfcc_12 = freqeuncy_features['mfcc_12']


        self.audio_feature_pub.publish(msg_acoustic_feature)



    def extract_time_features(self, audio_data):
        """
        Extract time domain features from an audio signal using Essentia.
        
        Parameters:
        - audio_signal: numpy array, the audio signal from which to extract features
        - sample_rate: int, the sample rate of the audio signal
        
        Returns:
        - features: dict, a dictionary containing the extracted features
        """

        features = {}

        rms_energy = self.rms_algo(audio_data)
        features['rms_energy'] = rms_energy
        
        # Amplitude Envelope
        amplitude_envelope = self.envelope_algo(audio_data)
        features['amplitude_envelope_mean'] = amplitude_envelope.mean()
        features['amplitude_envelope_std'] = amplitude_envelope.std()
        
        # Zero Crossing Rate
        zero_crossing_rate = self.zcr_algo(audio_data)
        features['zero_crossing_rate'] = zero_crossing_rate
        
        # Dynamic Complexity and Loudness
        dynamic_complexity, loudness = self.dyn_algo(audio_data)
        features['dynamic_complexity'] = dynamic_complexity
        features['loudness'] = loudness

        # Loudness Vickers
        loudness_vickers = self.loudness_algo(audio_data)
        features['loudness_vickers'] = loudness_vickers

        return features


    def extract_frequency_features(self, audio_data):
        
        features = {}
        # for frame in es.FrameGenerator(audio_data, frameSize=self.frame_size, hopSize=self.hop_length):
        windowed_frame = self.window_algo(audio_data)
        spectrum = self.spectrum_algo(windowed_frame)
        
        features['spectral_centroid'] = self.centroid_algo(spectrum)
        features['spectral_complexity'] = self.complexity_algo(spectrum)

        spectral_contrast, spectral_valley = self.contrast_algo(spectrum)
        # Store spectral contrast and valley values separately
        for i, val in enumerate(spectral_contrast):
            features[f'spectral_contrast_{i}'] = val
        for i, val in enumerate(spectral_valley):
            features[f'spectral_valley_{i}'] = val
            
        features['spectral_decrease'] = self.decrease_algo(spectrum)
        features['spectral_energy'] = self.energy_algo(spectrum)
        features['spectral_energy_band_ratio'] = self.energy_band_ratio_algo(spectrum)
        features['spectral_flatness'] = self.flatness_algo(spectrum)
        features['spectral_flux'] = self.spectral_flux(spectrum)
        features['spectral_rolloff'] = self.rolloff_algo(spectrum)
        features['spectral_strong_peak'] = self.strong_peak_algo(spectrum)
        central_moments = self.central_moment_algo(spectrum)
        features['spectral_variance'], features['spectral_skewness'], features['spectral_kurtosis'] = self.distrubution_shape(central_moments)
        features['spectral_crest_factor'] = self.spectral_crest_factor(spectrum)
        
        mfcc_bands, mfcc_coeffs = self.mfcc_algo(spectrum)
        for i, coeff in enumerate(mfcc_coeffs):
            features[f'mfcc_{i}'] = coeff
        
        return features


if __name__ == '__main__':
    try:
        AcousticFeatureExtractor()
    except rospy.ROSInterruptException:
        pass
