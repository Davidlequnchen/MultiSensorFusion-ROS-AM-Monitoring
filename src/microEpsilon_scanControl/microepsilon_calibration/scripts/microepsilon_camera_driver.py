#!/usr/bin/env python
import time
import ctypes as ct
import numpy as np
from matplotlib import pyplot as plt
import pylinllt as llt

import os
import cv2
import rospy
import numpy as np
import std_msgs.msg
import sensor_msgs.msg
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

'''
This is the microepsilon camera driver
it use the vedio mode to extract image
it pubish raw video image from microepsilon camera with topic: 'microepsilon/image_raw'
'''


class CamerDriver():
    def __init__(self):
        self.node_name = 'microepsilon_camera_driver'
        rospy.init_node(self.node_name, anonymous=True)
        
       

        # initialize the camera, make connection
        self.initialization() 



        # Create the OpenCV display window for the RGB image
        self.cv_window_name = self.node_name
        cv2.namedWindow(self.cv_window_name, cv2.WINDOW_AUTOSIZE)
        # cv2.moveWindow(self.cv_window_name, 25, 75)

        # Create the cv_bridge object
        self.bridge = CvBridge()

        # image publisher 
        self.image_pub = rospy.Publisher(
            'microepsilon/image_raw', Image, queue_size=10)
        
        # What we do during shutdown
        rospy.on_shutdown(self.cleanup)

        #create a image object
        self.image = Image()

        r = rospy.Rate(25)
        while not rospy.is_shutdown():
            self.pub_image()
            r.sleep()

    def initialization(self):
        # Parametrize transmission --- Important: make sure this is compliant to sensor
        scanner_type = ct.c_int(0)
        self.null_ptr_int = ct.POINTER(ct.c_uint)()

        # Init profile buffer and timestamp info
        available_resolutions = (ct.c_uint*4)()
        self.available_interfaces = [ct.create_string_buffer(8) for i in range(6)]
        self.available_interfaces_p = (ct.c_char_p * 6)(*map(ct.addressof, self.available_interfaces))
        self.lost_profiles = ct.c_uint()

        # Create instance and set IP address
        self.hLLT = llt.create_llt_device()

        # Get available interfaces
        rospy.loginfo(" get Get available interfaces")
        ret = llt.get_device_interfaces(self.available_interfaces_p, len(self.available_interfaces))
        if ret < 1:
            raise ValueError("Error getting interfaces : " + str(ret))
        
        rospy.loginfo(" set_device_interface")
        ret = llt.set_device_interface(self.hLLT, self.available_interfaces[0], 0)
        if ret < 1:
            raise ValueError("Error setting device interface: " + str(ret))

        # Connect
        rospy.loginfo(" connect to sensor ")
        ret = llt.connect(self.hLLT)
        if ret < 1:
            raise ConnectionError("Error connect: " + str(ret))

        # Scanner type
        rospy.loginfo(" get scanner type")
        ret = llt.get_llt_type(self.hLLT, ct.byref(scanner_type))
        if ret < 1:
            raise ValueError("Error scanner type: " + str(ret))

        # Set exposure time
        rospy.loginfo(" set exposure time ")
        ret = llt.set_feature(self.hLLT, llt.FEATURE_FUNCTION_EXPOSURE_TIME, 100)
        if ret < 1:
            raise ValueError("Error setting exposure time: " + str(ret))

        # Set idle time
        rospy.loginfo(" set idle time ")
        ret = llt.set_feature(self.hLLT, llt.FEATURE_FUNCTION_IDLE_TIME, 100000)
        if ret < 1:
            raise ValueError("Error idle time: " + str(ret))

        # Set profile config
        rospy.loginfo(" set profile config ")
        ret = llt.set_profile_config(self.hLLT, llt.TProfileConfig.VIDEO_IMAGE)
        if ret < 1:
            raise ValueError("Error setting profile config: " + str(ret))

        self.height = ct.c_uint(0)
        self.width = ct.c_uint(0)

        # use VIDEO_MODE_0 for scanCONTROL 30xx series, to save bandwidth
        self.video_type = llt.TTransferVideoType.VIDEO_MODE_1
        if llt.TScannerType.scanCONTROL30xx_25 <= scanner_type.value <= llt.TScannerType.scanCONTROL30xx_xxx:
            self.video_type = llt.TTransferVideoType.VIDEO_MODE_0


    def disconnect(self):
        # Stop Video Stream
        ret = llt.transfer_video_stream(self.hLLT, self.video_type, 0, self.null_ptr_int, self.null_ptr_int)
        if ret < 1:
            raise ValueError("Error stopping transfer profiles: " + str(ret))

        # Disconnect
        ret = llt.disconnect(self.hLLT)
        if ret < 1:
            raise ConnectionAbortedError("Error while disconnect: "  + str(ret))

        # Disconnect
        ret = llt.del_device(self.hLLT)
        if ret < 1:
            raise ConnectionAbortedError("Error while delete: " + str(ret))


    def pub_image(self):
        # try:
             # Start transfer
            rospy.loginfo(" start transfer profiles")
            ret = llt.transfer_video_stream(self.hLLT, self.video_type, 1, ct.byref(self.width), ct.byref(self.height))
            if ret < 1:
                raise ValueError("Error starting transfer profiles: " + str(ret))

        
            # Allocate profile buffer
            profile_buffer = (ct.c_ubyte * (self.width.value * self.height.value))()
            
            # Warm-up time
            time.sleep(0.2)


            rospy.loginfo(" get profile buffer ")
            ret = llt.get_actual_profile(self.hLLT, profile_buffer, len(profile_buffer), llt.TProfileConfig.VIDEO_IMAGE,
                                    ct.byref(self.lost_profiles))
            if ret != len(profile_buffer):
                raise ValueError("Error get profile buffer data: " + str(ret))
            
            # Convert the image to a Numpy array since for cv2 format
            cv_image = np.frombuffer(profile_buffer, dtype='uint8').reshape((self.height.value, self.width.value))
            
        
            # cv_image = np.reshape(image, shape=(480, 640, n_channels), dtype=dtype )
            # rospy.loginfo(cv_image)
            # plt.figure()
            # plt.imshow(cv_image, 'gray', origin='lower')
            # plt.show()

            #----------------
            # br = CvBridge()
            # >>> dtype, n_channels = br.encoding_as_cvtype2('8UC3')
            # >>> im = np.ndarray(shape=(480, 640, n_channels), dtype=dtype)
            # >>> msg = br.cv2_to_imgmsg(im)  # Convert the image to a message
            # >>> im2 = br.imgmsg_to_cv2(msg) # Convert the message to a new image
            # >>> cmprsmsg = br.cv2_to_compressed_imgmsg(im)  # Convert the image to a compress message
            # >>> im22 = br.compressed_imgmsg_to_cv2(msg) # Convert the compress message to a new image
            # >>> cv2.imwrite("this_was_a_message_briefly.png", im2)
            #---------------------------------------
            
            # convert cv image into ros image message. 
            self.image = self.bridge.cv2_to_imgmsg(cv_image)

            # # # Display the image.--------------------------
            cv2.imshow(self.node_name, cv_image)
            # Process any keyboard commands-----------
            self.keystroke = cv2.waitKey(5)
            if 32 <= self.keystroke and self.keystroke < 128:
                cc = chr(self.keystroke).lower()
                if cc == 'q':
                    # The user has press the q key, so exit
                    rospy.signal_shutdown("User hit q key to quit.")
            
            #try:
            self.image_pub.publish(self.image)
            # except CvBridgeError as e:
            #     print(e)

        # except:
        #     rospy.loginfo("image exception")
            
            # Stop Video Stream
            ret = llt.transfer_video_stream(self.hLLT, self.video_type, 0, self.null_ptr_int, self.null_ptr_int)
            if ret < 1:
                raise ValueError("Error stopping transfer profiles: " + str(ret))
    
    def cleanup(self):
        print ("Shutting down node.")
        self.disconnect()
        cv2.destroyAllWindows() 


if __name__ == '__main__':
    try:
        CamerDriver()
    except rospy.ROSInterruptException:
        pass
