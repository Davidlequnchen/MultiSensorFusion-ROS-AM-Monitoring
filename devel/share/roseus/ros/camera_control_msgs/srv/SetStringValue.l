;; Auto-generated. Do not edit!


(when (boundp 'camera_control_msgs::SetStringValue)
  (if (not (find-package "CAMERA_CONTROL_MSGS"))
    (make-package "CAMERA_CONTROL_MSGS"))
  (shadow 'SetStringValue (find-package "CAMERA_CONTROL_MSGS")))
(unless (find-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUE")
  (make-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUE"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUEREQUEST")
  (make-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUEREQUEST"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUERESPONSE")
  (make-package "CAMERA_CONTROL_MSGS::SETSTRINGVALUERESPONSE"))

(in-package "ROS")





(defclass camera_control_msgs::SetStringValueRequest
  :super ros::object
  :slots (_value ))

(defmethod camera_control_msgs::SetStringValueRequest
  (:init
   (&key
    ((:value __value) "")
    )
   (send-super :init)
   (setq _value (string __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; string _value
    4 (length _value)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _value
       (write-long (length _value) s) (princ _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _value
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _value (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass camera_control_msgs::SetStringValueResponse
  :super ros::object
  :slots (_success _message ))

(defmethod camera_control_msgs::SetStringValueResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass camera_control_msgs::SetStringValue
  :super ros::object
  :slots ())

(setf (get camera_control_msgs::SetStringValue :md5sum-) "43ad6a9b380ac342e4b20e501a2fd46c")
(setf (get camera_control_msgs::SetStringValue :datatype-) "camera_control_msgs/SetStringValue")
(setf (get camera_control_msgs::SetStringValue :request) camera_control_msgs::SetStringValueRequest)
(setf (get camera_control_msgs::SetStringValue :response) camera_control_msgs::SetStringValueResponse)

(defmethod camera_control_msgs::SetStringValueRequest
  (:response () (instance camera_control_msgs::SetStringValueResponse :init)))

(setf (get camera_control_msgs::SetStringValueRequest :md5sum-) "43ad6a9b380ac342e4b20e501a2fd46c")
(setf (get camera_control_msgs::SetStringValueRequest :datatype-) "camera_control_msgs/SetStringValueRequest")
(setf (get camera_control_msgs::SetStringValueRequest :definition-)
      "# Used by :
# - set_Image_Encoding ROS service. (value = mono8, mono16, bgr8, rgb8, bayer_bggr8, bayer_gbrg8, bayer_rggb8, bayer_grbg8, bayer_rggb16, bayer_bggr16, bayer_gbrg16, bayer_grbg16).

string value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")

(setf (get camera_control_msgs::SetStringValueResponse :md5sum-) "43ad6a9b380ac342e4b20e501a2fd46c")
(setf (get camera_control_msgs::SetStringValueResponse :datatype-) "camera_control_msgs/SetStringValueResponse")
(setf (get camera_control_msgs::SetStringValueResponse :definition-)
      "# Used by :
# - set_Image_Encoding ROS service. (value = mono8, mono16, bgr8, rgb8, bayer_bggr8, bayer_gbrg8, bayer_rggb8, bayer_grbg8, bayer_rggb16, bayer_bggr16, bayer_gbrg16, bayer_grbg16).

string value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")



(provide :camera_control_msgs/SetStringValue "43ad6a9b380ac342e4b20e501a2fd46c")


