;; Auto-generated. Do not edit!


(when (boundp 'opencv_apps::ContourArea)
  (if (not (find-package "OPENCV_APPS"))
    (make-package "OPENCV_APPS"))
  (shadow 'ContourArea (find-package "OPENCV_APPS")))
(unless (find-package "OPENCV_APPS::CONTOURAREA")
  (make-package "OPENCV_APPS::CONTOURAREA"))

(in-package "ROS")
;;//! \htmlinclude ContourArea.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass opencv_apps::ContourArea
  :super ros::object
  :slots (_header _area ))

(defmethod opencv_apps::ContourArea
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:area __area) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _area __area)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:area
   (&optional __area)
   (if __area (setq _area __area)) _area)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64[] _area
    (* 8    (length _area)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64[] _area
     (write-long (length _area) s)
     (dotimes (i (length _area))
       (sys::poke (elt _area i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64[] _area
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _area (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _area i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get opencv_apps::ContourArea :md5sum-) "492a39775739bec790d41ced94d2fdc1")
(setf (get opencv_apps::ContourArea :datatype-) "opencv_apps/ContourArea")
(setf (get opencv_apps::ContourArea :definition-)
      "Header header
float64[] area


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



(provide :opencv_apps/ContourArea "492a39775739bec790d41ced94d2fdc1")


