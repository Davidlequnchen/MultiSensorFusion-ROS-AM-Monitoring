;; Auto-generated. Do not edit!


(when (boundp 'defects_identification::MsgDefects)
  (if (not (find-package "DEFECTS_IDENTIFICATION"))
    (make-package "DEFECTS_IDENTIFICATION"))
  (shadow 'MsgDefects (find-package "DEFECTS_IDENTIFICATION")))
(unless (find-package "DEFECTS_IDENTIFICATION::MSGDEFECTS")
  (make-package "DEFECTS_IDENTIFICATION::MSGDEFECTS"))

(in-package "ROS")
;;//! \htmlinclude MsgDefects.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass defects_identification::MsgDefects
  :super ros::object
  :slots (_header _defectsType ))

(defmethod defects_identification::MsgDefects
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:defectsType __defectsType) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _defectsType (round __defectsType))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:defectsType
   (&optional __defectsType)
   (if __defectsType (setq _defectsType __defectsType)) _defectsType)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _defectsType
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _defectsType
       (write-long _defectsType s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _defectsType
     (setq _defectsType (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get defects_identification::MsgDefects :md5sum-) "def1db136df73f888f606360f32da1ad")
(setf (get defects_identification::MsgDefects :datatype-) "defects_identification/MsgDefects")
(setf (get defects_identification::MsgDefects :definition-)
      "Header header
int32 defectsType  # 0, 1, 2, 3
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



(provide :defects_identification/MsgDefects "def1db136df73f888f606360f32da1ad")


