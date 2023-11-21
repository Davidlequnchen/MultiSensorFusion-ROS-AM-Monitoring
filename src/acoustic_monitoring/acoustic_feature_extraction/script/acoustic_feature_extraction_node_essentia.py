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
import struct
from collections import deque, defaultdict
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
        self.buffer_duration = rospy.get_param("~buffer_size", 40) # ms
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
        self.contrast_algo = SpectralContrast(frameSize=self.frame_size, highFrequencyBound=self.sample_rate/2, lowFrequencyBound=200, sampleRate=self.sample_rate)
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
        self.mfcc_algo = MFCC(inputSize=self.hop_length+1, highFrequencyBound=self.sample_rate/2, numberCoefficients=13, sampleRate=self.sample_rate)

        self.audio_sub = rospy.Subscriber("audioStamped", AudioDataStamped, self.audio_callback, queue_size=20)
        self.audio_info_sub = rospy.Subscriber(audio_topic_info, AudioInfo, self.cb_audio_info, queue_size=1)
        self.audio_feature_pub = rospy.Publisher("/acoustic_feature", MsgAcousticFeature, queue_size=10)

        rospy.spin()


    def cb_audio_info(self, msg_audio_info):
        self.channels = msg_audio_info.channels
        self.sample_rate = msg_audio_info.sample_rate
        self.sample_format = msg_audio_info.sample_format
        self.coding_format = msg_audio_info.coding_format

    
    #### for min-DSP (dual channel 16 bits) #####
    def audio_callback(self, msg_audio):
        # Read the data as bytes
        byte_data = msg_audio.data

        # Initialize lists to hold unpacked data for each channel
        left_channel_data = []
        # right_channel_data = []

        # Process the data
        for i in range(0, len(byte_data), 6):
            # Left channel (first 3 bytes)
            left_padded_data = byte_data[i:i+3] + b'\x00'
            left_unpacked_data = struct.unpack('<i', left_padded_data)[0]
            if left_unpacked_data & 0x800000:  # Adjust for signed 24-bit data
                left_unpacked_data -= 0x1000000
            left_channel_data.append(left_unpacked_data)

            # # Right channel (next 3 bytes)
            # right_padded_data = byte_data[i+3:i+6] + b'\x00'
            # right_unpacked_data = struct.unpack('<i', right_padded_data)[0]
            # if right_unpacked_data & 0x800000:  # Adjust for signed 24-bit data
            #     right_unpacked_data -= 0x1000000
            # right_channel_data.append(right_unpacked_data)

        # Normalize the data
        left_channel_data = [sample / float(2 ** 23 - 1) for sample in left_channel_data]
        # right_channel_data = [sample / float(2 ** 23 - 1) for sample in right_channel_data]

        # Extend the buffers for each channel
        self.audio_buffer.extend(left_channel_data)

        while len(self.audio_buffer) > self.buffer_size:
            self.audio_buffer.popleft()
            # self.right_audio_buffer.popleft()

        if len(self.audio_buffer) < self.buffer_size:
            padding = [0.0] * (self.buffer_size - len(self.audio_buffer))
            self.audio_buffer.extend(padding)
            # self.right_audio_buffer.extend(padding)

        # Convert to numpy array for plotting (if needed)
        # Note: You now have two channels to handle
        audio_data_buffered = np.array(self.audio_buffer, dtype=np.float32)
        # Convert deque to numpy array for feature extraction
        audio_data_buffered = np.array(self.audio_buffer).astype(np.float32)


        time_features = self.extract_time_features(audio_data_buffered)
        freqeuncy_features = self.extract_freqeuncy_features_v2(audio_data_buffered)

        msg_acoustic_feature = MsgAcousticFeature()
        msg_acoustic_feature.header = msg_audio.header

        # ## time-domain features
        msg_acoustic_feature.rms_energy = time_features["rms_energy"]
        msg_acoustic_feature.amplitude_envelope_mean = time_features['amplitude_envelope_mean'] 
        msg_acoustic_feature.amplitude_envelope_std = time_features['amplitude_envelope_std']
        msg_acoustic_feature.zero_crossing_rate = time_features['zero_crossing_rate']
        msg_acoustic_feature.dynamic_complexity = time_features['dynamic_complexity']
        msg_acoustic_feature.loudness = time_features['loudness']
        msg_acoustic_feature.loudness_vickers = time_features['loudness_vickers']
        # ## frequency-domain features
        feature_names = [
            'spectral_centroid', 'spectral_complexity', 'spectral_contrast_0', 
            'spectral_contrast_1', 'spectral_contrast_2', 'spectral_contrast_3',
            'spectral_contrast_4', 'spectral_contrast_5', 'spectral_valley_0',
            'spectral_valley_1', 'spectral_valley_2', 'spectral_valley_3',
            'spectral_valley_4', 'spectral_valley_5', 'spectral_decrease', 
            'spectral_energy', 'spectral_energy_band_ratio', 'spectral_flatness',
            'spectral_flux', 'spectral_rolloff', 'spectral_strong_peak',
            'spectral_variance', 'spectral_skewness', 'spectral_kurtosis',
            'spectral_crest_factor', 'mfcc_0', 'mfcc_1', 'mfcc_2', 'mfcc_3',
            'mfcc_4', 'mfcc_5', 'mfcc_6', 'mfcc_7', 'mfcc_8', 'mfcc_9', 
            'mfcc_10', 'mfcc_11', 'mfcc_12'
        ]

        for feature in feature_names:
            setattr(msg_acoustic_feature, f"{feature}_mean", freqeuncy_features[f"{feature}_mean"])
            setattr(msg_acoustic_feature, f"{feature}_std", freqeuncy_features[f"{feature}_std"])


        self.audio_feature_pub.publish(msg_acoustic_feature)
    

    # def audio_callback(self, msg_audio):

    #     nbits = 16 # Each sample is 2 bytes
    #     scale_factor = 2**(nbits - 1)
    #     # Convert the audio to a numpy array and scale it in one step
    #     audio_data_numpy = (np.frombuffer(msg_audio.data, dtype=np.int16) / scale_factor)

    #     # Update the buffer with the new audio data
    #     self.audio_buffer.extend(audio_data_numpy)

    #     # Ensure that the buffer size is exactly 4410 samples
    #     if len(self.audio_buffer) < self.buffer_size:
    #         # Pad with zeros if smaller than desired
    #         self.audio_buffer.extend([0.0] * (self.buffer_size - len(self.audio_buffer)))
    #     elif len(self.audio_buffer) > self.buffer_size:
    #         # Trim if larger than desired
    #         self.audio_buffer = deque(list(self.audio_buffer)[-self.buffer_siz:], maxlen=self.buffer_siz)

        # Convert deque to numpy array for feature extraction
        # audio_data_buffered = np.array(self.audio_buffer).astype(np.float32)


        # time_features = self.extract_time_features(audio_data_buffered)
        # freqeuncy_features = self.extract_freqeuncy_features_v2(audio_data_buffered)

        # msg_acoustic_feature = MsgAcousticFeature()
        # msg_acoustic_feature.header = msg_audio.header

        # # ## time-domain features
        # msg_acoustic_feature.rms_energy = time_features["rms_energy"]
        # msg_acoustic_feature.amplitude_envelope_mean = time_features['amplitude_envelope_mean'] 
        # msg_acoustic_feature.amplitude_envelope_std = time_features['amplitude_envelope_std']
        # msg_acoustic_feature.zero_crossing_rate = time_features['zero_crossing_rate']
        # msg_acoustic_feature.dynamic_complexity = time_features['dynamic_complexity']
        # msg_acoustic_feature.loudness = time_features['loudness']
        # msg_acoustic_feature.loudness_vickers = time_features['loudness_vickers']
        # # ## frequency-domain features
        # feature_names = [
        #     'spectral_centroid', 'spectral_complexity', 'spectral_contrast_0', 
        #     'spectral_contrast_1', 'spectral_contrast_2', 'spectral_contrast_3',
        #     'spectral_contrast_4', 'spectral_contrast_5', 'spectral_valley_0',
        #     'spectral_valley_1', 'spectral_valley_2', 'spectral_valley_3',
        #     'spectral_valley_4', 'spectral_valley_5', 'spectral_decrease', 
        #     'spectral_energy', 'spectral_energy_band_ratio', 'spectral_flatness',
        #     'spectral_flux', 'spectral_rolloff', 'spectral_strong_peak',
        #     'spectral_variance', 'spectral_skewness', 'spectral_kurtosis',
        #     'spectral_crest_factor', 'mfcc_0', 'mfcc_1', 'mfcc_2', 'mfcc_3',
        #     'mfcc_4', 'mfcc_5', 'mfcc_6', 'mfcc_7', 'mfcc_8', 'mfcc_9', 
        #     'mfcc_10', 'mfcc_11', 'mfcc_12'
        # ]

        # for feature in feature_names:
        #     setattr(msg_acoustic_feature, f"{feature}_mean", freqeuncy_features[f"{feature}_mean"])
        #     setattr(msg_acoustic_feature, f"{feature}_std", freqeuncy_features[f"{feature}_std"])

        # self.audio_feature_pub.publish(msg_acoustic_feature)


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


    # def extract_frequency_features(self, audio_data):
    #     features = {}
    #     # for frame in es.FrameGenerator(audio_data, frameSize=self.frame_size, hopSize=self.hop_length):
    #     windowed_frame = self.window_algo(audio_data)
    #     spectrum = self.spectrum_algo(windowed_frame)
        
    #     features['spectral_centroid'] = self.centroid_algo(spectrum)
    #     features['spectral_complexity'] = self.complexity_algo(spectrum)

    #     spectral_contrast, spectral_valley = self.contrast_algo(spectrum)
    #     # Store spectral contrast and valley values separately
    #     for i, val in enumerate(spectral_contrast):
    #         features[f'spectral_contrast_{i}'] = val
    #     for i, val in enumerate(spectral_valley):
    #         features[f'spectral_valley_{i}'] = val
            
    #     features['spectral_decrease'] = self.decrease_algo(spectrum)
    #     features['spectral_energy'] = self.energy_algo(spectrum)
    #     features['spectral_energy_band_ratio'] = self.energy_band_ratio_algo(spectrum)
    #     features['spectral_flatness'] = self.flatness_algo(spectrum)
    #     features['spectral_flux'] = self.spectral_flux(spectrum)
    #     features['spectral_rolloff'] = self.rolloff_algo(spectrum)
    #     features['spectral_strong_peak'] = self.strong_peak_algo(spectrum)
    #     central_moments = self.central_moment_algo(spectrum)
    #     features['spectral_variance'], features['spectral_skewness'], features['spectral_kurtosis'] = self.distrubution_shape(central_moments)
    #     features['spectral_crest_factor'] = self.spectral_crest_factor(spectrum)
        
    #     mfcc_bands, mfcc_coeffs = self.mfcc_algo(spectrum)
    #     for i, coeff in enumerate(mfcc_coeffs):
    #         features[f'mfcc_{i}'] = coeff
        
    #     return features
    
    def extract_freqeuncy_features_v2(self, audio_data):
        features = defaultdict(list)
    
        for frame in es.FrameGenerator(audio_data, frameSize=self.frame_size, hopSize=self.hop_length):
            windowed_frame = self.window_algo(frame)
            spectrum = self.spectrum_algo(windowed_frame)

            features['spectral_centroid'].append(self.centroid_algo(spectrum))
            features['spectral_complexity'].append(self.complexity_algo(spectrum))
            spectral_contrast, spectral_valley = self.contrast_algo(spectrum)
            for i, val in enumerate(spectral_contrast):
                features[f'spectral_contrast_{i}'].append(val)
            for i, val in enumerate(spectral_valley):
                features[f'spectral_valley_{i}'].append(val)
            features['spectral_decrease'].append(self.decrease_algo(spectrum))
            features['spectral_energy'].append(self.energy_algo(spectrum))
            features['spectral_energy_band_ratio'].append(self.energy_band_ratio_algo(spectrum))
            features['spectral_flatness'].append(self.flatness_algo(spectrum))
            features['spectral_flux'].append(self.spectral_flux(spectrum))
            features['spectral_rolloff'].append(self.rolloff_algo(spectrum))
            features['spectral_strong_peak'].append(self.strong_peak_algo(spectrum))
            central_moments = self.central_moment_algo(spectrum)
            features['spectral_variance'].append(self.distrubution_shape(central_moments)[0])
            features['spectral_skewness'].append(self.distrubution_shape(central_moments)[1])
            features['spectral_kurtosis'].append(self.distrubution_shape(central_moments)[2])
            features['spectral_crest_factor'].append(self.spectral_crest_factor(spectrum))

            mfcc_bands, mfcc_coeffs = self.mfcc_algo(spectrum)
            for i, coeff in enumerate(mfcc_coeffs):
                features[f'mfcc_{i}'].append(coeff)
                
        # Prepare a dictionary to store mean and std separately
        features_separated = {}
        for key, value in features.items():
            mean_val = np.mean(value)
            std_val = np.std(value)
            features_separated[f"{key}_mean"] = mean_val
            features_separated[f"{key}_std"] = std_val
        return features_separated


if __name__ == '__main__':
    try:
        AcousticFeatureExtractor()
    except rospy.ROSInterruptException:
        pass
