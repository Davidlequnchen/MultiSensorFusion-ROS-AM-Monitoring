import rospy
from message_filters import ApproximateTimeSynchronizer, Subscriber
from sklearn.externals import joblib
from std_msgs.msg import String
from std_msgs.msg import Float32
from opencv_apps.msg import MomentArrayStamped
from opencv_apps.msg import ContourArea
from opencv_apps.msg import MaxContourArea
from opencv_apps.msg import RotatedRectArrayStamped
from acoustic_monitoring_msgs.msg import MsgAcousticFeature


class MultimodalPredictionNode:
    def __init__(self):
        rospy.init_node('ml_defect_prediction_node')
        self.model = joblib.load("../trained_model/metamodel_NN_all_100ms.pkl")
        
        ## vision features
        self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea )
        self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea )
        self.ellipse_sub = Subscriber("/general_contours/ellipses", RotatedRectArrayStamped)
        self.rectangle_sub = Subscriber("/general_contours/rectangles", RotatedRectArrayStamped)

        ## acoustic features
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature)

        self.synchronizer = ApproximateTimeSynchronizer([self.contour_moment_sub, self.convex_hull_sub, 
                                                        self.max_contour_area_sub, self.ellipse_sub, 
                                                        self.rectangle_sub, self.acoustic_feature_sub], queue_size=5, slop=0.1)
        
        self.synchronizer.registerCallback(self.callback)
        self.prediction_pub = rospy.Publisher("/ml_prediction", String, queue_size=10)


    def callback(self, sensor1_data, sensor2_data, sensor3_data):
        features_combined = [sensor1_data.data, sensor2_data.data, sensor3_data.data]
        prediction = self.model.predict([features])[0]
        self.prediction_pub.publish(prediction)





if __name__ == '__main__':
    try:
        MultimodalPredictionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
