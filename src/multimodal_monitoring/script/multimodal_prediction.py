#!/usr/bin/env python3
import rospy
import rospkg
import os
import logging
import numpy as np  
from collections import deque  
from message_filters import ApproximateTimeSynchronizer, Subscriber
import joblib
from std_msgs.msg import String
from opencv_apps.msg import MomentArrayStamped, ContourArea, MaxContourArea, RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature
from multimodal_monitoring.msg import MsgDefect  

dirname = rospkg.RosPack().get_path('multimodal_monitoring')
logging.getLogger('sklearnex').setLevel(logging.WARNING)


class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node("multimodal_prediction_node", anonymous=True)
        
        # Initialize deque for buffering features
        self.audio_feature_buffer = deque(maxlen=100)  
        self.visual_feature_buffer = deque(maxlen=100)  
        
        # Load pre-trained machine learning model
        self.ml_model = joblib.load(os.path.join(dirname, 'config', 'metamodel_KNN.sav'))
        # Load the saved StandardScaler model at the initialization part of your ROS node
        self.scaler = joblib.load(os.path.join(dirname, 'config', 'StandardScaler_audio_visual.pkl'))
        
        # Initialize subscribers for all the required topics
        self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea)
        self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea)
        # self.ellipse_sub = Subscriber("/general_contours/ellipses", RotatedRectArrayStamped)
        # self.rectangle_sub = Subscriber("/general_contours/rectangles", RotatedRectArrayStamped)
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature)

        # Synchronize all the topics
        self.synchronizer = ApproximateTimeSynchronizer(
            [self.contour_moment_sub, self.convex_hull_sub, self.max_contour_area_sub, self.acoustic_feature_sub],
            queue_size=20,
            slop=0.1
        )
        self.synchronizer.registerCallback(self.callback)
        
        # Initialize prediction publisher
        self.prediction_pub = rospy.Publisher("quality_predicted", MsgDefect, queue_size=10)
                       
                       
    def callback(self, contour_moment_msg, convex_hull_msg, max_contour_area_msg, acoustic_feature_msg):
        # List of variables
        contour_moment_vars = ["mu20", "mu02", "mu03"]
        max_contour_area_vars = ["meltpool_contour_area", "ellipse_width", "ellipse_height", "rectangle_height", "rectangle_width"]
        convex_hull_vars = ["area"]
        acoustic_feature_vars = ["spectral_centroids", "spectral_bandwidth", "spectral_flatness", "spectral_variance",
                                 "spectral_skewness", "spectral_entropy", "spectral_flux"]
        
        features_combined = []            
        # Iterate through the variables and extract their values
        for msg, vars in zip([convex_hull_msg, max_contour_area_msg, contour_moment_msg, acoustic_feature_msg],
                            [convex_hull_vars, max_contour_area_vars, contour_moment_vars, acoustic_feature_vars]):
            # Handle array messages (MomentArrayStamped and ContourArea)
            if hasattr(msg, 'moments') or hasattr(msg, 'area'):
                array_data = getattr(msg, 'moments', []) or getattr(msg, 'area', [])
                # Only consider the first element in the list, ignore the rest
                array_data = array_data[:1]
                for single_msg in array_data:
                    for var in vars:
                        value = getattr(single_msg, var, None)
                        if value is None:
                            # rospy.logwarn(f"Attribute {var} not found. Adding zero as placeholder.")
                            features_combined.append(0)
                        else:
                            features_combined.append(value)
            # Handle non-array messages (MaxContourArea)
            else:
                for var in vars:
                    value = getattr(msg, var, None)
                    if value is None:
                        # rospy.logwarn(f"Attribute {var} not found. Adding zero as placeholder.")
                        features_combined.append(0)
                    else:
                        features_combined.append(value)
                        
        rospy.loginfo("Features Combined: %s", features_combined)
        
        # Reshape the features_combined to a 2D array as scaler expects 2D input
        features_reshaped = np.array(features_combined).reshape(1, -1)
# 
        # Standardize the features
        features_standardized = self.scaler.transform(features_reshaped)

        # Make prediction
        # prediction = int(np.random.choice([0,1,2,3]))
        prediction = self.ml_model.predict([features_standardized[0]])[0]
        
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
