import rospy
from message_filters import ApproximateTimeSynchronizer, Subscriber
from sklearn.externals import joblib
import pickle
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
        self.model = pickle.load(open("../trained_model/metamodel_NN_all_100ms.pkl", "rb"))

        
        ## vision features
        self.contour_moment_sub = Subscriber("/contour_moments/moments", MomentArrayStamped)
        self.convex_hull_sub = Subscriber("/convex_hull/hull_area", ContourArea )
        self.max_contour_area_sub = Subscriber("/general_contours/max_contour_area", MaxContourArea )

        ## acoustic features
        self.acoustic_feature_sub = Subscriber('/acoustic_feature', MsgAcousticFeature)

        self.synchronizer = ApproximateTimeSynchronizer([self.contour_moment_sub, self.convex_hull_sub, 
                                                        self.max_contour_area_sub, self.acoustic_feature_sub], queue_size=5, slop=0.1)
        
        self.synchronizer.registerCallback(self.callback)
        self.prediction_pub = rospy.Publisher("/ml_prediction", String, queue_size=10)


    # def callback(self, contour_moment_msg, convex_hull_msg, max_contour_area_msg, acoustic_feature_msg):
    #     # extract numeric values from the messages
    #     mu20 = contour_moment_msg.mu20
    #     mu11 = contour_moment_msg.mu11
    #     mu02 = contour_moment_msg.mu02
    #     mu30 = contour_moment_msg.mu30
    #     mu21 = contour_moment_msg.mu21
    #     mu12 = contour_moment_msg.mu12
    #     mu03 = contour_moment_msg.mu03
    #     meltpool_contour_area = max_contour_area_msg.meltpool_contour_area
    #     ellipse_width = max_contour_area_msg.ellipse_width
    #     ellipse_height = max_contour_area_msg.ellipse_height
    #     rectangle_width = max_contour_area_msg.rectangle_width
    #     rectangle_height = max_contour_area_msg.rectangle_height
    #     convex_hull_area = convex_hull_msg.area[0]

    #     ## acoustic features
    #     MFCC0 = acoustic_feature_msg.mfccs[0]
    #     MFCC1 = acoustic_feature_msg.mfccs[1]
    #     MFCC2 = acoustic_feature_msg.mfccs[2]
    #     MFCC3 = acoustic_feature_msg.mfccs[3]
    #     MFCC4 = acoustic_feature_msg.mfccs[4]
    #     MFCC5 = acoustic_feature_msg.mfccs[5]
    #     MFCC6 = acoustic_feature_msg.mfccs[6]
    #     MFCC7 = acoustic_feature_msg.mfccs[7]
    #     MFCC8 = acoustic_feature_msg.mfccs[8]
    #     MFCC9 = acoustic_feature_msg.mfccs[9]
    #     MFCC10 = acoustic_feature_msg.mfccs[10]
    #     MFCC11 = acoustic_feature_msg.mfccs[11]
    #     MFCC12 = acoustic_feature_msg.mfccs[12]
    #     spectral_centroid = acoustic_feature_msg.spectral_centroids
    #     spectral_bandwidth = acoustic_feature_msg.spectral_bandwidth
    #     spectral_flatness = acoustic_feature_msg.spectral_flatness
    #     spectral_crest_factor = acoustic_feature_msg.spectral_crest_factor
    #     spectral_kurtosis = acoustic_feature_msg.spectral_kurtosis
    #     spectral_variance = acoustic_feature_msg.spectral_variance


    #     features_combined = [mu20, mu11, mu02, mu30, mu21, mu12, mu03, meltpool_contour_area, ellipse_width,
    #                         ellipse_height, rectangle_height, rectangle_width, convex_hull_area, MFCC0,
    #                         MFCC1, MFCC2, MFCC3, MFCC4, MFCC5, MFCC6, MFCC7, MFCC8, MFCC9, MFCC10, MFCC11, MFCC12,
    #                         spectral_centroid, spectral_bandwidth, spectral_flatness, spectral_crest_factor,
    #                         spectral_kurtosis, spectral_variance]

    #     prediction = self.model.predict([features_combined])[0]
    #     self.prediction_pub.publish(prediction)

    def callback(self, contour_moment_msg, convex_hull_msg, max_contour_area_msg, acoustic_feature_msg):
        # list of variables
        contour_moment_vars = ["mu20", "mu11", "mu02", "mu30", "mu21", "mu12", "mu03"]
        max_contour_area_vars = ["meltpool_contour_area", "ellipse_width", "ellipse_height", "rectangle_height", "rectangle_width"]
        convex_hull_vars = ["area"]
        acoustic_feature_vars = ["mfccs", "spectral_centroids", "spectral_bandwidth", "spectral_flatness", 
                                "spectral_crest_factor", "spectral_kurtosis", "spectral_variance"]
        
        features_combined = []
        # iterate through the variables and extract their values
        for var in contour_moment_vars:
            features_combined.append(getattr(contour_moment_msg, var))
        for var in max_contour_area_vars:
            features_combined.append(getattr(max_contour_area_msg, var))
        for var in convex_hull_vars:
            features_combined.append(getattr(convex_hull_msg, var)[0])
        for var in acoustic_feature_vars:
            features_combined.append(getattr(acoustic_feature_msg, var))
        
        prediction = self.model.predict([features_combined])[0]
        self.prediction_pub.publish(prediction)




if __name__ == '__main__':
    try:
        MultimodalPredictionNode()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
