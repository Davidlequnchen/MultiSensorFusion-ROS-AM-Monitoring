#!/usr/bin/env python3

import rospy
import cv2
import numpy as np
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
from coaxial_melt_pool_monitoring.msg import MsgCoaxialMeltPoolFeatures

class FeatureExtractionNode:
    def __init__(self):
        # Initialize ROS node
        rospy.init_node('coaxial_feature_extraction_node')

        image_topic = rospy.get_param('~image', '/usb_cam/image_raw')
        self.threshold = rospy.get_param('~threshold', 235)
        
        # Initialize CvBridge
        self.bridge = CvBridge()
        
        # Initialize publishers
        self.feature_pub = rospy.Publisher('coaxial_melt_pool_features', MsgCoaxialMeltPoolFeatures, queue_size=10)
        self.image_general_contour = rospy.Publisher('image_general_contour', Image, queue_size=5)
        self.image_convex_hull_pub = rospy.Publisher('image_convex_hull', Image, queue_size=5)
        self.image_moment_pub = rospy.Publisher('image_moment_extract', Image, queue_size=5)
        
        # Initialize subscriber
        rospy.Subscriber(image_topic, Image, self.image_callback)
        

    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        except CvBridgeError as e:
            rospy.logerr("CvBridge Error: {}".format(e))
            return
        
        # Feature extraction
        general_result = np.array(self.general_contour_extraction(cv_image, threshold=self.threshold))
        max_hull_area = np.array(self.convex_hull_extract(cv_image, threshold=self.threshold))
        moment_result = np.array(self.moment_extract(cv_image, threshold=self.threshold))
        
        # Combine features into one NumPy array for better computational efficiency
        combined_features = np.concatenate([general_result,np.reshape(max_hull_area, (1,)), moment_result])
        
        feature_msg = MsgCoaxialMeltPoolFeatures()
        feature_msg.header = msg.header
        
        # Fill the message based on the structure of MsgCoaxialMeltPoolFeatures
        feature_msg.max_contour_area, feature_msg.rectangle_angle, feature_msg.rectangle_width, \
        feature_msg.rectangle_height, feature_msg.ellipse_angle, feature_msg.ellipse_width, \
        feature_msg.ellipse_height,  feature_msg.max_hull_area, feature_msg.m00, feature_msg.m10, \
        feature_msg.m01, feature_msg.m20, feature_msg.m11, feature_msg.m02, feature_msg.m30, \
        feature_msg.m21, feature_msg.m12, feature_msg.m03, feature_msg.mu20, feature_msg.mu11, \
        feature_msg.mu02, feature_msg.mu30, feature_msg.mu21, feature_msg.mu12, feature_msg.mu03, \
        feature_msg.nu20, feature_msg.nu11, feature_msg.nu02, feature_msg.nu30, feature_msg.nu21, \
        feature_msg.nu12, feature_msg.nu03, feature_msg.center_x, feature_msg.center_y, \
        feature_msg.length, feature_msg.area = combined_features

        # Publish the message
        self.feature_pub.publish(feature_msg)
        
    

    def general_contour_extraction(self, image, threshold=100):
        """
        Extract general contour features from a given image.
        
        Parameters:
            image (ndarray): The input image.
            threshold (int): The threshold value for image processing.
        
        Returns:
            list: A list containing the extracted features.
        """
        # Initialize the result list with zeros
        result = [0, 0, 0, 0, 0, 0, 0]  # [max_contour_area, rectangle_angle, rectangle_width, rectangle_height, ellipse_angle, ellipse_width, ellipse_height]
        
        src_gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        src_gray = cv2.blur(src_gray, (3, 3))
        _, threshold_output = cv2.threshold(src_gray, threshold, 255, cv2.THRESH_BINARY)
        
        contours, _ = cv2.findContours(threshold_output, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        drawing = np.zeros((threshold_output.shape[0], threshold_output.shape[1], 3), dtype=np.uint8)
        
        if not contours:
            self.image_general_contour.publish(self.bridge.cv2_to_imgmsg(drawing, "bgr8"))  # Publish original image if no contours
            return result
        
        # Find the rotated rectangles and ellipses for each contour
        min_rects = [cv2.minAreaRect(np.array(contour)) for contour in contours]
        contour_areas = [cv2.contourArea(np.array(contour)) for contour in contours]
        
        # Get the index of the max contour area
        max_contour_area_index = np.argmax(contour_areas)
        max_contour_area = contour_areas[max_contour_area_index]
        
        # Store the max contour area
        result[0] = max_contour_area
        
        # Store rectangle features
        rect = min_rects[max_contour_area_index]
        result[1] = rect[-1]
        result[2] = rect[1][0]
        result[3] = rect[1][1]
        
        # Draw rectangle on image
        box = cv2.boxPoints(rect)
        box = np.int0(box)
        cv2.drawContours(drawing, [box], 0, (90, 100, 255), 2)
        
        # Store and draw ellipse features if enough points for fitEllipse
        if len(contours[max_contour_area_index]) > 5:
            ellipse = cv2.fitEllipse(np.array(contours[max_contour_area_index]))
            result[4] = ellipse[-1]
            result[5] = ellipse[1][0]
            result[6] = ellipse[1][1]
            
            # Draw ellipse on image
            cv2.ellipse(drawing, ellipse, (90, 255, 100), 2)
        
        # Publish the resultant image
        self.image_general_contour.publish(self.bridge.cv2_to_imgmsg(drawing, "bgr8"))
        
        return result


    def convex_hull_extract(self, frame, threshold=100):
        """
        Extract convex hull features from a given image.

        Parameters:
            frame (ndarray): The input image.
            threshold (int): The threshold value for binary conversion.

        Returns:
            max_hull_area (float): The maximum area among all convex hulls.
            drawing (ndarray): The image with contours and convex hull drawn.
        """

        # Convert to grayscale if the image is colored
        if frame.shape[-1] > 1:
            src_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        else:
            src_gray = frame

        # Blur the image
        src_gray = cv2.blur(src_gray, (3, 3))

        # Apply threshold
        ret, threshold_output = cv2.threshold(src_gray, threshold, 255, cv2.THRESH_BINARY)

        # Find contours
        contours, _ = cv2.findContours(threshold_output, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

        # Initialize return values
        max_hull_area = 0.0
        drawing = np.zeros((threshold_output.shape[0], threshold_output.shape[1], 3), dtype=np.uint8)

        # Check if any contour is detected
        if contours:
            # Find the convex hull object for each contour
            hull = [cv2.convexHull(cnt) for cnt in contours]

            # Find the bounding convex hull area for each contour
            hull_area = [cv2.contourArea(h) for h in hull]

            # Get the maximum convex hull area
            max_hull_area = max(hull_area)

            # Draw contours and convex hull on the image
            for i in range(len(contours)):
                color = (np.random.randint(0, 256), np.random.randint(0, 256), np.random.randint(0, 256))
                # cv2.drawContours(drawing, contours, i, color)
                cv2.drawContours(drawing, hull, i, color, 2)

        # Publish the drawing image as a ROS topic
        self.image_convex_hull_pub.publish(self.bridge.cv2_to_imgmsg(drawing, "bgr8"))

        return max_hull_area

    def moment_extract(self, image, threshold):
        # Initialize moments as zeros
        features = [0] * 28  # Initialize a list of length 28 with all zeros

        # Convert to grayscale if the image is colored
        if len(image.shape) > 2:
            gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
        else:
            gray = image

        # Thresholding
        _, thresh = cv2.threshold(gray, threshold, 255, cv2.THRESH_BINARY)
        # Find contours
        contours, _ = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        # Sort contours by area
        contours = sorted(contours, key=cv2.contourArea, reverse=True)
        # Initialize drawing matrix
        drawing = np.zeros((thresh.shape[0], thresh.shape[1], 3), dtype=np.uint8)
        if contours:
            largest_contour = contours[0]
            moments = cv2.moments(largest_contour)
            
            # Avoid division by zero
            if moments['m00'] != 0:
                # Populating the moments in the list
                features[:24] = [moments[key] for key in sorted(moments.keys())]
                features[24] = moments['m10'] / moments['m00']
                features[25] = moments['m01'] / moments['m00']
                features[26] = cv2.contourArea(largest_contour)
                features[27] = cv2.arcLength(largest_contour, True)
                
                # Draw the contour and the center
                cv2.drawContours(drawing, [largest_contour], -1, (0, 255, 255), 2)
                center = (int(features[24]), int(features[25]))
                cv2.circle(drawing, center, 5, (255, 0, 0), -1)

        # Convert the OpenCV image to ROS message and publish
        image_message = self.bridge.cv2_to_imgmsg(drawing, "bgr8")
        self.image_moment_pub.publish(image_message)
        
        return features

if __name__ == '__main__':
    node = FeatureExtractionNode()
    rospy.spin()
