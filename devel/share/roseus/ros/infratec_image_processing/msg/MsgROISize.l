;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::MsgROISize)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'MsgROISize (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::MSGROISIZE")
  (make-package "INFRATEC_IMAGE_PROCESSING::MSGROISIZE"))

(in-package "ROS")
;;//! \htmlinclude MsgROISize.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::MsgROISize
  :super ros::object
  :slots (_header _pixels ))

(defmethod infratec_image_processing::MsgROISize
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:pixels __pixels) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _pixels (round __pixels))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:pixels
   (&optional __pixels)
   (if __pixels (setq _pixels __pixels)) _pixels)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _pixels
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _pixels
       (write-long _pixels s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _pixels
     (setq _pixels (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get infratec_image_processing::MsgROISize :md5sum-) "77890d32d59f41937276b08815f00d0a")
(setf (get infratec_image_processing::MsgROISize :datatype-) "infratec_image_processing/MsgROISize")
(setf (get infratec_image_processing::MsgROISize :definition-)
      "Header header
int32 pixels


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



(provide :infratec_image_processing/MsgROISize "77890d32d59f41937276b08815f00d0a")


