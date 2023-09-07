
import rospy
from collections import deque  # Added for buffering
from message_filters import ApproximateTimeSynchronizer, Subscriber
from sklearn.externals import joblib  # Consider using standalone joblib
from std_msgs.msg import String
from std_msgs.msg import Float32
from opencv_apps.msg import MomentArrayStamped
from opencv_apps.msg import ContourArea
from opencv_apps.msg import MaxContourArea
from opencv_apps.msg import RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature

class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node("multimodal_prediction_node", anonymous=True)
        
        # Initialize deque for buffering features
        self.audio_feature_buffer = deque(maxlen=100)  # Adjust maxlen as needed
        self.visual_feature_buffer = deque(maxlen=100)  # Adjust maxlen as needed
        
        # Load pre-trained machine learning model
        self.ml_model = joblib.load('path/to/your/model.pkl')  # Update path
        
        # Initialize subscribers and synchronizer
        self.audio_sub = Subscriber("audio_feature_topic", Float32)
        self.visual_sub = Subscriber("visual_feature_topic", MomentArrayStamped)
        self.synchronizer = ApproximateTimeSynchronizer(
            [self.audio_sub, self.visual_sub], queue_size=10, slop=0.1
        )
        self.synchronizer.registerCallback(self.callback)
        
        # Initialize prediction publisher
        self.prediction_pub = rospy.Publisher("prediction_topic", String, queue_size=10)

    def callback(self, audio_msg, visual_msg):
        # Append new features to the buffers
        self.audio_feature_buffer.append(audio_msg.data)
        self.visual_feature_buffer.append(visual_msg.moment)  # Assuming 'moment' is the feature
        
        # Check if buffers are sufficiently full
        if len(self.audio_feature_buffer) >= 10 and len(self.visual_feature_buffer) >= 10:  # Adjust thresholds
            # Aggregate features into a single feature vector
            feature_vector = list(self.audio_feature_buffer) + list(self.visual_feature_buffer)
            
            # Make prediction
            prediction = self.ml_model.predict([feature_vector])[0]
            
            # Publish the prediction
            self.prediction_pub.publish(String(data=str(prediction)))

if __name__ == "__main__":
    try:
        node = MultimodalPredictionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
