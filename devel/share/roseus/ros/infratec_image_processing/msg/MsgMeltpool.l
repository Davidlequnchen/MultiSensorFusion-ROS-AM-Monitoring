;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::MsgMeltpool)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'MsgMeltpool (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::MSGMELTPOOL")
  (make-package "INFRATEC_IMAGE_PROCESSING::MSGMELTPOOL"))

(in-package "ROS")
;;//! \htmlinclude MsgMeltpool.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::MsgMeltpool
  :super ros::object
  :slots (_header _melt_pool_size _heat_affected_zone ))

(defmethod infratec_image_processing::MsgMeltpool
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:melt_pool_size __melt_pool_size) 0.0)
    ((:heat_affected_zone __heat_affected_zone) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _melt_pool_size (float __melt_pool_size))
   (setq _heat_affected_zone (float __heat_affected_zone))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:melt_pool_size
   (&optional __melt_pool_size)
   (if __melt_pool_size (setq _melt_pool_size __melt_pool_size)) _melt_pool_size)
  (:heat_affected_zone
   (&optional __heat_affected_zone)
   (if __heat_affected_zone (setq _heat_affected_zone __heat_affected_zone)) _heat_affected_zone)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _melt_pool_size
    4
    ;; float32 _heat_affected_zone
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _melt_pool_size
       (sys::poke _melt_pool_size (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _heat_affected_zone
       (sys::poke _heat_affected_zone (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _melt_pool_size
     (setq _melt_pool_size (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _heat_affected_zone
     (setq _heat_affected_zone (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get infratec_image_processing::MsgMeltpool :md5sum-) "53ff07d859c81343775714d56bbac875")
(setf (get infratec_image_processing::MsgMeltpool :datatype-) "infratec_image_processing/MsgMeltpool")
(setf (get infratec_image_processing::MsgMeltpool :definition-)
      "Header header
float32 melt_pool_size
float32 heat_affected_zone

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



(provide :infratec_image_processing/MsgMeltpool "53ff07d859c81343775714d56bbac875")


