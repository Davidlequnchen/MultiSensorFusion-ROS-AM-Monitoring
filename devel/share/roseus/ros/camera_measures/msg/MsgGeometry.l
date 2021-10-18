;; Auto-generated. Do not edit!


(when (boundp 'camera_measures::MsgGeometry)
  (if (not (find-package "CAMERA_MEASURES"))
    (make-package "CAMERA_MEASURES"))
  (shadow 'MsgGeometry (find-package "CAMERA_MEASURES")))
(unless (find-package "CAMERA_MEASURES::MSGGEOMETRY")
  (make-package "CAMERA_MEASURES::MSGGEOMETRY"))

(in-package "ROS")
;;//! \htmlinclude MsgGeometry.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass camera_measures::MsgGeometry
  :super ros::object
  :slots (_header _major_axis _minor_axis _orientation _x _y _minor_axis_average ))

(defmethod camera_measures::MsgGeometry
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:major_axis __major_axis) 0.0)
    ((:minor_axis __minor_axis) 0.0)
    ((:orientation __orientation) 0.0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:minor_axis_average __minor_axis_average) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _major_axis (float __major_axis))
   (setq _minor_axis (float __minor_axis))
   (setq _orientation (float __orientation))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _minor_axis_average (float __minor_axis_average))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:major_axis
   (&optional __major_axis)
   (if __major_axis (setq _major_axis __major_axis)) _major_axis)
  (:minor_axis
   (&optional __minor_axis)
   (if __minor_axis (setq _minor_axis __minor_axis)) _minor_axis)
  (:orientation
   (&optional __orientation)
   (if __orientation (setq _orientation __orientation)) _orientation)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:minor_axis_average
   (&optional __minor_axis_average)
   (if __minor_axis_average (setq _minor_axis_average __minor_axis_average)) _minor_axis_average)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _major_axis
    4
    ;; float32 _minor_axis
    4
    ;; float32 _orientation
    4
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _minor_axis_average
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _major_axis
       (sys::poke _major_axis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _minor_axis
       (sys::poke _minor_axis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _orientation
       (sys::poke _orientation (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _minor_axis_average
       (sys::poke _minor_axis_average (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _major_axis
     (setq _major_axis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _minor_axis
     (setq _minor_axis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _orientation
     (setq _orientation (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _minor_axis_average
     (setq _minor_axis_average (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get camera_measures::MsgGeometry :md5sum-) "3adfca161cefb9cf304720422e5ec87c")
(setf (get camera_measures::MsgGeometry :datatype-) "camera_measures/MsgGeometry")
(setf (get camera_measures::MsgGeometry :definition-)
      "Header header
float32 major_axis
float32 minor_axis
# float32 circle_diameter
float32 orientation
float32 x
float32 y
float32 minor_axis_average

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



(provide :camera_measures/MsgGeometry "3adfca161cefb9cf304720422e5ec87c")


