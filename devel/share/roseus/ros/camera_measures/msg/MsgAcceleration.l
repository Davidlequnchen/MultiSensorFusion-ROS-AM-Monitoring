;; Auto-generated. Do not edit!


(when (boundp 'camera_measures::MsgAcceleration)
  (if (not (find-package "CAMERA_MEASURES"))
    (make-package "CAMERA_MEASURES"))
  (shadow 'MsgAcceleration (find-package "CAMERA_MEASURES")))
(unless (find-package "CAMERA_MEASURES::MSGACCELERATION")
  (make-package "CAMERA_MEASURES::MSGACCELERATION"))

(in-package "ROS")
;;//! \htmlinclude MsgAcceleration.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass camera_measures::MsgAcceleration
  :super ros::object
  :slots (_header _acceleration ))

(defmethod camera_measures::MsgAcceleration
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:acceleration __acceleration) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _acceleration (float __acceleration))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:acceleration
   (&optional __acceleration)
   (if __acceleration (setq _acceleration __acceleration)) _acceleration)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _acceleration
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _acceleration
       (sys::poke _acceleration (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _acceleration
     (setq _acceleration (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get camera_measures::MsgAcceleration :md5sum-) "f548cef2b390c670e07f1d277452f218")
(setf (get camera_measures::MsgAcceleration :datatype-) "camera_measures/MsgAcceleration")
(setf (get camera_measures::MsgAcceleration :definition-)
      "Header header
float32 acceleration


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



(provide :camera_measures/MsgAcceleration "f548cef2b390c670e07f1d277452f218")


