;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::MsgThreshold)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'MsgThreshold (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::MSGTHRESHOLD")
  (make-package "INFRATEC_IMAGE_PROCESSING::MSGTHRESHOLD"))

(in-package "ROS")
;;//! \htmlinclude MsgThreshold.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::MsgThreshold
  :super ros::object
  :slots (_header _threshold ))

(defmethod infratec_image_processing::MsgThreshold
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:threshold __threshold) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _threshold (float __threshold))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:threshold
   (&optional __threshold)
   (if __threshold (setq _threshold __threshold)) _threshold)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _threshold
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _threshold
       (sys::poke _threshold (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _threshold
     (setq _threshold (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get infratec_image_processing::MsgThreshold :md5sum-) "3dc898e59e7081935abe13d2f48debb8")
(setf (get infratec_image_processing::MsgThreshold :datatype-) "infratec_image_processing/MsgThreshold")
(setf (get infratec_image_processing::MsgThreshold :definition-)
      "Header header
float32 threshold

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



(provide :infratec_image_processing/MsgThreshold "3dc898e59e7081935abe13d2f48debb8")


