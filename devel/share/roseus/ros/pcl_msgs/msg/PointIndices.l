;; Auto-generated. Do not edit!


(when (boundp 'pcl_msgs::PointIndices)
  (if (not (find-package "PCL_MSGS"))
    (make-package "PCL_MSGS"))
  (shadow 'PointIndices (find-package "PCL_MSGS")))
(unless (find-package "PCL_MSGS::POINTINDICES")
  (make-package "PCL_MSGS::POINTINDICES"))

(in-package "ROS")
;;//! \htmlinclude PointIndices.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass pcl_msgs::PointIndices
  :super ros::object
  :slots (_header _indices ))

(defmethod pcl_msgs::PointIndices
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:indices __indices) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _header __header)
   (setq _indices __indices)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:indices
   (&optional __indices)
   (if __indices (setq _indices __indices)) _indices)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32[] _indices
    (* 4    (length _indices)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32[] _indices
     (write-long (length _indices) s)
     (dotimes (i (length _indices))
       (write-long (elt _indices i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32[] _indices
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _indices (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _indices i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get pcl_msgs::PointIndices :md5sum-) "458c7998b7eaf99908256472e273b3d4")
(setf (get pcl_msgs::PointIndices :datatype-) "pcl_msgs/PointIndices")
(setf (get pcl_msgs::PointIndices :definition-)
      "Header header
int32[] indices


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



(provide :pcl_msgs/PointIndices "458c7998b7eaf99908256472e273b3d4")


