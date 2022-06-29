;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::MsgHistogram)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'MsgHistogram (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::MSGHISTOGRAM")
  (make-package "INFRATEC_IMAGE_PROCESSING::MSGHISTOGRAM"))

(in-package "ROS")
;;//! \htmlinclude MsgHistogram.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::MsgHistogram
  :super ros::object
  :slots (_header _histogram ))

(defmethod infratec_image_processing::MsgHistogram
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:histogram __histogram) (make-array 0 :initial-element 0 :element-type :integer))
    )
   (send-super :init)
   (setq _header __header)
   (setq _histogram __histogram)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:histogram
   (&optional __histogram)
   (if __histogram (setq _histogram __histogram)) _histogram)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32[] _histogram
    (* 4    (length _histogram)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32[] _histogram
     (write-long (length _histogram) s)
     (dotimes (i (length _histogram))
       (write-long (elt _histogram i) s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32[] _histogram
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _histogram (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _histogram i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get infratec_image_processing::MsgHistogram :md5sum-) "8b804f15fac99f33a0d9c6309bbd6803")
(setf (get infratec_image_processing::MsgHistogram :datatype-) "infratec_image_processing/MsgHistogram")
(setf (get infratec_image_processing::MsgHistogram :definition-)
      "Header header
uint32[] histogram

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



(provide :infratec_image_processing/MsgHistogram "8b804f15fac99f33a0d9c6309bbd6803")


