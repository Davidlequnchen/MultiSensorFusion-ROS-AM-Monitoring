#!/usr/bin/env python3
import rospy
import numpy as np  
from collections import deque  
from message_filters import ApproximateTimeSynchronizer, Subscriber
# from sklearn.externals import joblib  
from std_msgs.msg import String
from opencv_apps.msg import MomentArrayStamped, ContourArea, MaxContourArea, RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature
from multimodal_monitoring.msg import MsgDefect  


class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node("multimodal_prediction_node", anonymous=True)
        
        # Initialize deque for buffering features
        self.audio_feature_buffer = deque(maxlen=100)  
        self.visual_feature_buffer = deque(maxlen=100)  
        
        # Load pre-trained machine learning model
        # self.ml_model = joblib.load('path/to/your/model.pkl')  
        
        # Initialize subscribers for all the required topics
        self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea)
        self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea)
        self.ellipse_sub = Subscriber("/general_contours/ellipses", RotatedRectArrayStamped)
        self.rectangle_sub = Subscriber("/general_contours/rectangles", RotatedRectArrayStamped)
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature)

        # Synchronize all the topics
        self.synchronizer = ApproximateTimeSynchronizer(
            [self.contour_moment_sub, self.convex_hull_sub, self.max_contour_area_sub],
            queue_size=20,
            slop=0.1
        )
        self.synchronizer.registerCallback(self.callback)
        
        # Initialize prediction publisher
        self.prediction_pub = rospy.Publisher("quality_predicted", MsgDefect, queue_size=10)
    
    def callback(self, contour_moment_msg, convex_hull_msg, max_contour_area_msg):
        # List of variables
        contour_moment_vars = ["mu20", "mu11", "mu02", "mu30", "mu21", "mu12", "mu03"]
        max_contour_area_vars = ["meltpool_contour_area", "ellipse_width", "ellipse_height", "rectangle_height", "rectangle_width"]
        convex_hull_vars = ["area"]
        acoustic_feature_vars = ["mfccs", "spectral_centroids", "spectral_bandwidth", "spectral_flatness",
                                "spectral_crest_factor", "spectral_kurtosis", "spectral_variance"]
        
        features_combined = []
        # Iterate through the variables and extract their values
        for msg, vars in zip([ max_contour_area_msg, convex_hull_msg],
                            [ max_contour_area_vars, convex_hull_vars]):
            for var in vars:
                value = getattr(msg, var, None)  # Get attribute value, return None if not found
                if value is None:
                    rospy.logwarn(f"Attribute {var} not found in message {msg}. Skipping.")
                    continue
                if isinstance(value, list):  # Flatten if the value is a list
                    features_combined.extend(value)
                else:
                    features_combined.append(value)
        
        
        # Dummy prediction using random values
        prediction = int(np.random.choice([0,1,2,3]))
        # Make prediction
        # prediction = self.ml_model.predict([feature_vector])[0]
        
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
