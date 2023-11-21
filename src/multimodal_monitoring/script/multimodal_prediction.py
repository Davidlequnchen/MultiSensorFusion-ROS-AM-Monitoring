#!/usr/bin/env python3
import rospy
import rospkg
import os
import logging
import numpy as np  
from collections import deque  
from xgboost import XGBClassifier
from message_filters import ApproximateTimeSynchronizer, Subscriber
import joblib
from std_msgs.msg import String
# from opencv_apps.msg import MomentArrayStamped, ContourArea, MaxContourArea, RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature
from coaxial_melt_pool_monitoring.msg import MsgCoaxialMeltPoolFeatures
from multimodal_monitoring.msg import MsgDefect  


dirname = rospkg.RosPack().get_path('multimodal_monitoring')
logging.getLogger('sklearnex').setLevel(logging.WARNING)

ACOUSTIC_FEATURE_VARS = ['rms_energy', 'amplitude_envelope_mean', 'amplitude_envelope_std', 'zero_crossing_rate', 'dynamic_complexity', 'loudness',
    'loudness_vickers', 'spectral_centroid_mean', 'spectral_centroid_std', 'spectral_complexity_mean','spectral_complexity_std', 'spectral_contrast_0_mean',
    'spectral_contrast_0_std', 'spectral_contrast_1_mean', 'spectral_contrast_1_std', 'spectral_contrast_2_mean', 'spectral_contrast_2_std', 'spectral_contrast_3_mean',
    'spectral_contrast_3_std', 'spectral_contrast_4_mean','spectral_contrast_4_std', 'spectral_contrast_5_mean', 'spectral_contrast_5_std', 'spectral_valley_0_mean',
    'spectral_valley_0_std', 'spectral_valley_1_mean', 'spectral_valley_1_std', 'spectral_valley_2_mean', 'spectral_valley_2_std', 'spectral_valley_3_mean',
    'spectral_valley_3_std', 'spectral_valley_4_mean', 'spectral_valley_4_std', 'spectral_valley_5_mean', 'spectral_valley_5_std', 'spectral_decrease_mean',
    'spectral_decrease_std', 'spectral_energy_mean', 'spectral_energy_std', 'spectral_energy_band_ratio_mean', 'spectral_energy_band_ratio_std',
    'spectral_flatness_mean', 'spectral_flatness_std', 'spectral_flux_mean', 'spectral_flux_std', 'spectral_rolloff_mean', 'spectral_rolloff_std',
    'spectral_strong_peak_mean', 'spectral_strong_peak_std', 'spectral_variance_mean', 'spectral_variance_std', 'spectral_skewness_mean', 'spectral_skewness_std',
    'spectral_kurtosis_mean', 'spectral_kurtosis_std', 'spectral_crest_factor_mean', 'spectral_crest_factor_std', 'mfcc_0_mean', 'mfcc_0_std', 'mfcc_1_mean', 'mfcc_1_std', 
    'mfcc_2_mean', 'mfcc_2_std', 'mfcc_3_mean', 'mfcc_3_std', 'mfcc_4_mean', 'mfcc_4_std', 'mfcc_5_mean', 'mfcc_5_std', 'mfcc_6_mean', 'mfcc_6_std', 'mfcc_7_mean',
    'mfcc_7_std', 'mfcc_8_mean', 'mfcc_8_std', 'mfcc_9_mean', 'mfcc_9_std', 'mfcc_10_mean', 'mfcc_10_std', 'mfcc_11_mean', 'mfcc_11_std', 'mfcc_12_mean', 'mfcc_12_std'
] # 83 features

VISUAL_FEATURE_VARS = [
    'max_contour_area', 'rectangle_angle',
    'rectangle_width', 'rectangle_height', 'ellipse_angle', 'ellipse_width',
    'ellipse_height', 'max_hull_area', 'm00', 'm10', 'm01', 'm20', 'm11', 'm02',
    'm30', 'm21', 'm12', 'm03', 'mu20', 'mu11', 'mu02', 'mu30', 'mu21',
    'mu12', 'mu03', 'nu20', 'nu11', 'nu02', 'nu30', 'nu21', 'nu12', 'nu03',
    'center_x', 'center_y', 'area', 'length'
] # 36 features 

class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node("multimodal_prediction_node", anonymous=True)
        
        # Initialize deque for buffering features
        self.audio_feature_buffer = deque(maxlen=100)  
        self.visual_feature_buffer = deque(maxlen=100)  
        
        # Load pre-trained machine learning model
        self.ml_model = joblib.load(os.path.join(dirname, 'config', 'XGBoost_All_Features.joblib')) # top classifiers: XGBoost_All_Features, LightGBM_All_Features
        # Load the saved StandardScaler model at the initialization part of your ROS node
        self.scaler = joblib.load(os.path.join(dirname, 'config', 'StandardScaler_All_Features.pkl'))
        
        # Initialize subscribers for all the required topics
        # self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        # self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea)
        # self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea)
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature) # 100Hz, 10 ms
        self.visual_feature_subscriber = Subscriber('/coaxial_melt_pool_features', MsgCoaxialMeltPoolFeatures) # 60Hz 16.67 ms

        # Synchronize all the topics
        self.synchronizer = ApproximateTimeSynchronizer(
                # [self.contour_moment_sub, self.convex_hull_sub, self.max_contour_area_sub, self.acoustic_feature_sub],
                [self.acoustic_feature_sub, self.visual_feature_subscriber],
                queue_size=20,
                slop=0.001 #s
            )
        self.synchronizer.registerCallback(self.callback)
        
        # Initialize prediction publisher
        self.prediction_pub = rospy.Publisher("/quality_predicted", MsgDefect, queue_size=10)
                       
                       
    def callback(self, acoustic_feature_msg, visual_feature_msg):
        features_combined = []
        for msg, vars in zip([acoustic_feature_msg, visual_feature_msg],
                            [ACOUSTIC_FEATURE_VARS, VISUAL_FEATURE_VARS]):
            for var in vars:
                value = getattr(msg, var, None)
                if value is None:
                    rospy.logwarn(f"Attribute {var} not found. Adding zero as placeholder.")
                    features_combined.append(0)
                else:
                    features_combined.append(value)
            # # Handle array messages (MomentArrayStamped and ContourArea)
            # if hasattr(msg, 'moments') or hasattr(msg, 'area'):
            #     array_data = getattr(msg, 'moments', []) or getattr(msg, 'area', [])
            #     # Only consider the first element in the list, ignore the rest
            #     array_data = array_data[:1]
            #     for single_msg in array_data:
            #         for var in vars:
            #             value = getattr(single_msg, var, None)
            #             if value is None:
            #                 # rospy.logwarn(f"Attribute {var} not found. Adding zero as placeholder.")
            #                 features_combined.append(0)
            #             else:
            #                 features_combined.append(value)
            # # Handle non-array messages (MaxContourArea)
            # else:
            #     for var in vars:
            #         value = getattr(msg, var, None)
            #         if value is None:
            #             # rospy.logwarn(f"Attribute {var} not found. Adding zero as placeholder.")
            #             features_combined.append(0)
            #         else:
            #             features_combined.append(value)
                        
        rospy.loginfo("Features Combined: %s", features_combined)

        # Check for NaNs or Infinities
        if np.any(np.isnan(features_combined)) or np.any(np.isinf(features_combined)):
            rospy.logwarn("NaN or Infinity detected in features")
        
        # Reshape the features_combined to a 2D array and Standardize the features
        features_reshaped = np.array(features_combined).reshape(1, -1)
        features_standardized = self.scaler.transform(features_reshaped)

        # Make prediction
        # prediction = int(np.random.choice([0,1,2,3]))
        prediction = self.ml_model.predict(features_standardized)[0]
        # prediction = self.ml_model.predict([features_standardized[0]])[0]
        
        # Publish the prediction
        prediction_msg = MsgDefect()
        prediction_msg.header.stamp = rospy.Time.now()  # Add timestamp
        prediction_msg.defect = prediction  # Assuming 'prediction' contains the integer code for the defect type
        self.prediction_pub.publish(prediction_msg)



if __name__ == "__main__":
    try:
        node = MultimodalPredictionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
