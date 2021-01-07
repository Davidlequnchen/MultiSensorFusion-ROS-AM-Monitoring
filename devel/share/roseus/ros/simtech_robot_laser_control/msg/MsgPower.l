;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::MsgPower)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'MsgPower (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::MSGPOWER")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::MSGPOWER"))

(in-package "ROS")
;;//! \htmlinclude MsgPower.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass simtech_robot_laser_control::MsgPower
  :super ros::object
  :slots (_header _value ))

(defmethod simtech_robot_laser_control::MsgPower
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _value (float __value))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _value
       (sys::poke _value (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _value
     (setq _value (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_robot_laser_control::MsgPower :md5sum-) "4bea522f9243fd34ea7bc74ce85697a8")
(setf (get simtech_robot_laser_control::MsgPower :datatype-) "simtech_robot_laser_control/MsgPower")
(setf (get simtech_robot_laser_control::MsgPower :definition-)
      "# the power to be published and send to laser socket
Header header
float32 value

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :simtech_robot_laser_control/MsgPower "4bea522f9243fd34ea7bc74ce85697a8")


