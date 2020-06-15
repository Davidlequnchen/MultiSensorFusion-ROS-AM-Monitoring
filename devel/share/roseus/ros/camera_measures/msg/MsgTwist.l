;; Auto-generated. Do not edit!


(when (boundp 'camera_measures::MsgTwist)
  (if (not (find-package "CAMERA_MEASURES"))
    (make-package "CAMERA_MEASURES"))
  (shadow 'MsgTwist (find-package "CAMERA_MEASURES")))
(unless (find-package "CAMERA_MEASURES::MSGTWIST")
  (make-package "CAMERA_MEASURES::MSGTWIST"))

(in-package "ROS")
;;//! \htmlinclude MsgTwist.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass camera_measures::MsgTwist
  :super ros::object
  :slots (_header _linear_x _linear_y _linear_z _linear_speed ))

(defmethod camera_measures::MsgTwist
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:linear_x __linear_x) 0.0)
    ((:linear_y __linear_y) 0.0)
    ((:linear_z __linear_z) 0.0)
    ((:linear_speed __linear_speed) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _linear_x (float __linear_x))
   (setq _linear_y (float __linear_y))
   (setq _linear_z (float __linear_z))
   (setq _linear_speed (float __linear_speed))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:linear_x
   (&optional __linear_x)
   (if __linear_x (setq _linear_x __linear_x)) _linear_x)
  (:linear_y
   (&optional __linear_y)
   (if __linear_y (setq _linear_y __linear_y)) _linear_y)
  (:linear_z
   (&optional __linear_z)
   (if __linear_z (setq _linear_z __linear_z)) _linear_z)
  (:linear_speed
   (&optional __linear_speed)
   (if __linear_speed (setq _linear_speed __linear_speed)) _linear_speed)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _linear_x
    4
    ;; float32 _linear_y
    4
    ;; float32 _linear_z
    4
    ;; float32 _linear_speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _linear_x
       (sys::poke _linear_x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _linear_y
       (sys::poke _linear_y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _linear_z
       (sys::poke _linear_z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _linear_speed
       (sys::poke _linear_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _linear_x
     (setq _linear_x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _linear_y
     (setq _linear_y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _linear_z
     (setq _linear_z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _linear_speed
     (setq _linear_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get camera_measures::MsgTwist :md5sum-) "65dc00dc0a137c0a769cb88b9a8dbe98")
(setf (get camera_measures::MsgTwist :datatype-) "camera_measures/MsgTwist")
(setf (get camera_measures::MsgTwist :definition-)
      "Header header
float32 linear_x
float32 linear_y
float32 linear_z
float32 linear_speed
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



(provide :camera_measures/MsgTwist "65dc00dc0a137c0a769cb88b9a8dbe98")


