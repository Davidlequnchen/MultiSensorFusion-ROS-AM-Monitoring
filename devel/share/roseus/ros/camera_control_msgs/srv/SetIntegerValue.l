;; Auto-generated. Do not edit!


(when (boundp 'camera_control_msgs::SetIntegerValue)
  (if (not (find-package "CAMERA_CONTROL_MSGS"))
    (make-package "CAMERA_CONTROL_MSGS"))
  (shadow 'SetIntegerValue (find-package "CAMERA_CONTROL_MSGS")))
(unless (find-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUE")
  (make-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUE"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUEREQUEST")
  (make-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUEREQUEST"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUERESPONSE")
  (make-package "CAMERA_CONTROL_MSGS::SETINTEGERVALUERESPONSE"))

(in-package "ROS")





(defclass camera_control_msgs::SetIntegerValueRequest
  :super ros::object
  :slots (_value ))

(defmethod camera_control_msgs::SetIntegerValueRequest
  (:init
   (&key
    ((:value __value) 0)
    )
   (send-super :init)
   (setq _value (round __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; int32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _value
       (write-long _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _value
     (setq _value (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass camera_control_msgs::SetIntegerValueResponse
  :super ros::object
  :slots (_success _message ))

(defmethod camera_control_msgs::SetIntegerValueResponse
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

(defclass camera_control_msgs::SetIntegerValue
  :super ros::object
  :slots ())

(setf (get camera_control_msgs::SetIntegerValue :md5sum-) "f17b32d87dddbe303f3f462e91a430a4")
(setf (get camera_control_msgs::SetIntegerValue :datatype-) "camera_control_msgs/SetIntegerValue")
(setf (get camera_control_msgs::SetIntegerValue :request) camera_control_msgs::SetIntegerValueRequest)
(setf (get camera_control_msgs::SetIntegerValue :response) camera_control_msgs::SetIntegerValueResponse)

(defmethod camera_control_msgs::SetIntegerValueRequest
  (:response () (instance camera_control_msgs::SetIntegerValueResponse :init)))

(setf (get camera_control_msgs::SetIntegerValueRequest :md5sum-) "f17b32d87dddbe303f3f462e91a430a4")
(setf (get camera_control_msgs::SetIntegerValueRequest :datatype-) "camera_control_msgs/SetIntegerValueRequest")
(setf (get camera_control_msgs::SetIntegerValueRequest :definition-)
      "# Used by :
# - set_black_level ROS service. (value = new targeted black level).
# - set_acquisition_frame_count ROS service (value = new targeted frame count).
# - set_offset_x ROS service (value = targeted offset in x-axis)
# - set_offset_y ROS service (value = targeted offset in y-axis)
# - set_demosaicing_mode ROS Service (value : 0 = Simple, 1 = Basler PGI)
# - set_light_source_preset ROS service (value : 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K)
# - set_balance_white_auto ROS service (value : 0 = Off, 1 = Once, 2 = Continuous)
# - set_sensor_readout_mode ROS service (value : 0 = Normal, 1 = Fast)
# - set_trigger_selector ROS service (value : 	0 = Frame start, 1 = Frame burst start (ace USB cameras) / Acquisition Start (ace GigE cameras))
# - set_trigger_source ROS service (value : 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1 (only selected GigE Camera))
# - set_trigger_activation ROS service (value : 0 = RigingEdge, 1 = FallingEdge)
# - set_line_selector ROS service (value : 0 = Line1, 1 = Line2, 2 = Line3, 3 = Line4)
# - set_line_mode ROS service (value : 0 = Input, 1 = Output)
# - set_line_source ROS sevice (value : 0 = Exposure Active, 1 = FrameTriggerWait, 2 = UserOutput1, 3 = Timer1Active, 4 = FlashWindow)
# - set_device_link_throughput_limit ROS service (value = new targeted throughput limit in Bytes/sec.).
# - select_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
# - select_default_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
# - set_gamma_selector (value: 0 = User, 1 = sRGB)

int32 value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")

(setf (get camera_control_msgs::SetIntegerValueResponse :md5sum-) "f17b32d87dddbe303f3f462e91a430a4")
(setf (get camera_control_msgs::SetIntegerValueResponse :datatype-) "camera_control_msgs/SetIntegerValueResponse")
(setf (get camera_control_msgs::SetIntegerValueResponse :definition-)
      "# Used by :
# - set_black_level ROS service. (value = new targeted black level).
# - set_acquisition_frame_count ROS service (value = new targeted frame count).
# - set_offset_x ROS service (value = targeted offset in x-axis)
# - set_offset_y ROS service (value = targeted offset in y-axis)
# - set_demosaicing_mode ROS Service (value : 0 = Simple, 1 = Basler PGI)
# - set_light_source_preset ROS service (value : 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K)
# - set_balance_white_auto ROS service (value : 0 = Off, 1 = Once, 2 = Continuous)
# - set_sensor_readout_mode ROS service (value : 0 = Normal, 1 = Fast)
# - set_trigger_selector ROS service (value : 	0 = Frame start, 1 = Frame burst start (ace USB cameras) / Acquisition Start (ace GigE cameras))
# - set_trigger_source ROS service (value : 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1 (only selected GigE Camera))
# - set_trigger_activation ROS service (value : 0 = RigingEdge, 1 = FallingEdge)
# - set_line_selector ROS service (value : 0 = Line1, 1 = Line2, 2 = Line3, 3 = Line4)
# - set_line_mode ROS service (value : 0 = Input, 1 = Output)
# - set_line_source ROS sevice (value : 0 = Exposure Active, 1 = FrameTriggerWait, 2 = UserOutput1, 3 = Timer1Active, 4 = FlashWindow)
# - set_device_link_throughput_limit ROS service (value = new targeted throughput limit in Bytes/sec.).
# - select_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
# - select_default_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)
# - set_gamma_selector (value: 0 = User, 1 = sRGB)

int32 value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")



(provide :camera_control_msgs/SetIntegerValue "f17b32d87dddbe303f3f462e91a430a4")


