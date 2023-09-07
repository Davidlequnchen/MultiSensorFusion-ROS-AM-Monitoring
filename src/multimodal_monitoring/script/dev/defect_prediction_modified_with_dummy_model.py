
import rospy
import numpy as np  # Added for generating dummy predictions
from collections import deque  
from message_filters import ApproximateTimeSynchronizer, Subscriber
from sklearn.externals import joblib  
from std_msgs.msg import String
from opencv_apps.msg import MomentArrayStamped, ContourArea, MaxContourArea, RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature

class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node("multimodal_prediction_node", anonymous=True)
        
        # Initialize deque for buffering features
        self.audio_feature_buffer = deque(maxlen=100)  
        self.visual_feature_buffer = deque(maxlen=100)  
        
        # Dummy model for placeholder
        # In reality, you would load a pre-trained model here
        self.ml_model = None  # joblib.load('path/to/your/model.pkl')  
        
        # Initialize subscribers for all the required topics
        self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea)
        self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea)
        self.ellipse_sub = Subscriber("/general_contours/ellipses", RotatedRectArrayStamped)
        self.rectangle_sub = Subscriber("/general_contours/rectangles", RotatedRectArrayStamped)
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature)

        # Synchronize all the topics
        self.synchronizer = ApproximateTimeSynchronizer(
            [self.acoustic_feature_sub, self.contour_moment_sub, self.convex_hull_sub, self.max_contour_area_sub, self.ellipse_sub, self.rectangle_sub],
            queue_size=10,
            slop=0.1
        )
        self.synchronizer.registerCallback(self.callback)
        
        # Initialize prediction publisher
        self.prediction_pub = rospy.Publisher("prediction_topic", String, queue_size=10)

    # Callback function should also be modified to accept all the messages
    def callback(self, acoustic_msg, moment_msg, hull_msg, max_area_msg, ellipse_msg, rectangle_msg):
        # Here you would extract and append the features to the buffers
        # As a placeholder, appending random features
        self.audio_feature_buffer.append(acoustic_msg.data)
        self.visual_feature_buffer.append(moment_msg.moments[0].moment10)  # Assuming this is the feature you are interested in
        
        # Check if buffers are sufficiently full
        if len(self.audio_feature_buffer) >= 10 and len(self.visual_feature_buffer) >= 10:
            # Aggregate features into a single feature vector
            feature_vector = list(self.audio_feature_buffer) + list(self.visual_feature_buffer)
            
            # Dummy prediction using random values
            # In your real application, use your trained model to make the prediction
            prediction = np.random.choice(["defect", "no_defect"])
            
            # Publish the prediction
            self.prediction_pub.publish(String(data=str(prediction)))

if __name__ == "__main__":
    try:
        node = MultimodalPredictionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
