;; Auto-generated. Do not edit!


(when (boundp 'pcl_msgs::ModelCoefficients)
  (if (not (find-package "PCL_MSGS"))
    (make-package "PCL_MSGS"))
  (shadow 'ModelCoefficients (find-package "PCL_MSGS")))
(unless (find-package "PCL_MSGS::MODELCOEFFICIENTS")
  (make-package "PCL_MSGS::MODELCOEFFICIENTS"))

(in-package "ROS")
;;//! \htmlinclude ModelCoefficients.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass pcl_msgs::ModelCoefficients
  :super ros::object
  :slots (_header _values ))

(defmethod pcl_msgs::ModelCoefficients
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:values __values) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _values __values)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:values
   (&optional __values)
   (if __values (setq _values __values)) _values)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32[] _values
    (* 4    (length _values)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32[] _values
     (write-long (length _values) s)
     (dotimes (i (length _values))
       (sys::poke (elt _values i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32[] _values
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _values (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _values i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get pcl_msgs::ModelCoefficients :md5sum-) "ca27dea75e72cb894cd36f9e5005e93e")
(setf (get pcl_msgs::ModelCoefficients :datatype-) "pcl_msgs/ModelCoefficients")
(setf (get pcl_msgs::ModelCoefficients :definition-)
      "Header header
float32[] values


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



(provide :pcl_msgs/ModelCoefficients "ca27dea75e72cb894cd36f9e5005e93e")


