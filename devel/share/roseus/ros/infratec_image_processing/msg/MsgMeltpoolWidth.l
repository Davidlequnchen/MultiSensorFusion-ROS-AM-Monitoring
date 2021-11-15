;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::MsgMeltpoolWidth)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'MsgMeltpoolWidth (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::MSGMELTPOOLWIDTH")
  (make-package "INFRATEC_IMAGE_PROCESSING::MSGMELTPOOLWIDTH"))

(in-package "ROS")
;;//! \htmlinclude MsgMeltpoolWidth.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::MsgMeltpoolWidth
  :super ros::object
  :slots (_header _melt_pool_width ))

(defmethod infratec_image_processing::MsgMeltpoolWidth
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:melt_pool_width __melt_pool_width) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _melt_pool_width (float __melt_pool_width))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:melt_pool_width
   (&optional __melt_pool_width)
   (if __melt_pool_width (setq _melt_pool_width __melt_pool_width)) _melt_pool_width)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _melt_pool_width
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _melt_pool_width
       (sys::poke _melt_pool_width (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _melt_pool_width
     (setq _melt_pool_width (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get infratec_image_processing::MsgMeltpoolWidth :md5sum-) "e7e9e312c51dbe288dc9af4b67dff15c")
(setf (get infratec_image_processing::MsgMeltpoolWidth :datatype-) "infratec_image_processing/MsgMeltpoolWidth")
(setf (get infratec_image_processing::MsgMeltpoolWidth :definition-)
      "Header header
float32 melt_pool_width #pixels


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



(provide :infratec_image_processing/MsgMeltpoolWidth "e7e9e312c51dbe288dc9af4b67dff15c")


