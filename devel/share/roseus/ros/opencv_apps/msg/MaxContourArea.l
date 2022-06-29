;; Auto-generated. Do not edit!


(when (boundp 'opencv_apps::MaxContourArea)
  (if (not (find-package "OPENCV_APPS"))
    (make-package "OPENCV_APPS"))
  (shadow 'MaxContourArea (find-package "OPENCV_APPS")))
(unless (find-package "OPENCV_APPS::MAXCONTOURAREA")
  (make-package "OPENCV_APPS::MAXCONTOURAREA"))

(in-package "ROS")
;;//! \htmlinclude MaxContourArea.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass opencv_apps::MaxContourArea
  :super ros::object
  :slots (_header _meltpool_contour_area _ellipse_angle _ellipse_x _ellipse_y _ellipse_width _ellipse_height _rectangle_angle _rectangle_x _rectangle_y _rectangle_width _rectangle_height ))

(defmethod opencv_apps::MaxContourArea
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:meltpool_contour_area __meltpool_contour_area) 0.0)
    ((:ellipse_angle __ellipse_angle) 0.0)
    ((:ellipse_x __ellipse_x) 0.0)
    ((:ellipse_y __ellipse_y) 0.0)
    ((:ellipse_width __ellipse_width) 0.0)
    ((:ellipse_height __ellipse_height) 0.0)
    ((:rectangle_angle __rectangle_angle) 0.0)
    ((:rectangle_x __rectangle_x) 0.0)
    ((:rectangle_y __rectangle_y) 0.0)
    ((:rectangle_width __rectangle_width) 0.0)
    ((:rectangle_height __rectangle_height) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _meltpool_contour_area (float __meltpool_contour_area))
   (setq _ellipse_angle (float __ellipse_angle))
   (setq _ellipse_x (float __ellipse_x))
   (setq _ellipse_y (float __ellipse_y))
   (setq _ellipse_width (float __ellipse_width))
   (setq _ellipse_height (float __ellipse_height))
   (setq _rectangle_angle (float __rectangle_angle))
   (setq _rectangle_x (float __rectangle_x))
   (setq _rectangle_y (float __rectangle_y))
   (setq _rectangle_width (float __rectangle_width))
   (setq _rectangle_height (float __rectangle_height))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:meltpool_contour_area
   (&optional __meltpool_contour_area)
   (if __meltpool_contour_area (setq _meltpool_contour_area __meltpool_contour_area)) _meltpool_contour_area)
  (:ellipse_angle
   (&optional __ellipse_angle)
   (if __ellipse_angle (setq _ellipse_angle __ellipse_angle)) _ellipse_angle)
  (:ellipse_x
   (&optional __ellipse_x)
   (if __ellipse_x (setq _ellipse_x __ellipse_x)) _ellipse_x)
  (:ellipse_y
   (&optional __ellipse_y)
   (if __ellipse_y (setq _ellipse_y __ellipse_y)) _ellipse_y)
  (:ellipse_width
   (&optional __ellipse_width)
   (if __ellipse_width (setq _ellipse_width __ellipse_width)) _ellipse_width)
  (:ellipse_height
   (&optional __ellipse_height)
   (if __ellipse_height (setq _ellipse_height __ellipse_height)) _ellipse_height)
  (:rectangle_angle
   (&optional __rectangle_angle)
   (if __rectangle_angle (setq _rectangle_angle __rectangle_angle)) _rectangle_angle)
  (:rectangle_x
   (&optional __rectangle_x)
   (if __rectangle_x (setq _rectangle_x __rectangle_x)) _rectangle_x)
  (:rectangle_y
   (&optional __rectangle_y)
   (if __rectangle_y (setq _rectangle_y __rectangle_y)) _rectangle_y)
  (:rectangle_width
   (&optional __rectangle_width)
   (if __rectangle_width (setq _rectangle_width __rectangle_width)) _rectangle_width)
  (:rectangle_height
   (&optional __rectangle_height)
   (if __rectangle_height (setq _rectangle_height __rectangle_height)) _rectangle_height)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _meltpool_contour_area
    8
    ;; float64 _ellipse_angle
    8
    ;; float64 _ellipse_x
    8
    ;; float64 _ellipse_y
    8
    ;; float64 _ellipse_width
    8
    ;; float64 _ellipse_height
    8
    ;; float64 _rectangle_angle
    8
    ;; float64 _rectangle_x
    8
    ;; float64 _rectangle_y
    8
    ;; float64 _rectangle_width
    8
    ;; float64 _rectangle_height
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _meltpool_contour_area
       (sys::poke _meltpool_contour_area (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ellipse_angle
       (sys::poke _ellipse_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ellipse_x
       (sys::poke _ellipse_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ellipse_y
       (sys::poke _ellipse_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ellipse_width
       (sys::poke _ellipse_width (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ellipse_height
       (sys::poke _ellipse_height (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rectangle_angle
       (sys::poke _rectangle_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rectangle_x
       (sys::poke _rectangle_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rectangle_y
       (sys::poke _rectangle_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rectangle_width
       (sys::poke _rectangle_width (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rectangle_height
       (sys::poke _rectangle_height (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _meltpool_contour_area
     (setq _meltpool_contour_area (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ellipse_angle
     (setq _ellipse_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ellipse_x
     (setq _ellipse_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ellipse_y
     (setq _ellipse_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ellipse_width
     (setq _ellipse_width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ellipse_height
     (setq _ellipse_height (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rectangle_angle
     (setq _rectangle_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rectangle_x
     (setq _rectangle_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rectangle_y
     (setq _rectangle_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rectangle_width
     (setq _rectangle_width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rectangle_height
     (setq _rectangle_height (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get opencv_apps::MaxContourArea :md5sum-) "c924e5f1e96fc91c0132097ca211cda0")
(setf (get opencv_apps::MaxContourArea :datatype-) "opencv_apps/MaxContourArea")
(setf (get opencv_apps::MaxContourArea :definition-)
      "Header header
float64 meltpool_contour_area
float64 ellipse_angle
float64 ellipse_x
float64 ellipse_y
float64 ellipse_width
float64 ellipse_height
float64 rectangle_angle
float64 rectangle_x
float64 rectangle_y
float64 rectangle_width
float64 rectangle_height
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



(provide :opencv_apps/MaxContourArea "c924e5f1e96fc91c0132097ca211cda0")


