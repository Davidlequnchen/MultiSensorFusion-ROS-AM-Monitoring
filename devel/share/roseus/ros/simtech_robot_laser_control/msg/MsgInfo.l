;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::MsgInfo)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'MsgInfo (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::MSGINFO")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::MSGINFO"))

(in-package "ROS")
;;//! \htmlinclude MsgInfo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass simtech_robot_laser_control::MsgInfo
  :super ros::object
  :slots (_header _time _track_number ))

(defmethod simtech_robot_laser_control::MsgInfo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:time __time) "")
    ((:track_number __track_number) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _time (string __time))
   (setq _track_number (round __track_number))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:track_number
   (&optional __track_number)
   (if __track_number (setq _track_number __track_number)) _track_number)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _time
    4 (length _time)
    ;; int32 _track_number
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _time
       (write-long (length _time) s) (princ _time s)
     ;; int32 _track_number
       (write-long _track_number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _time
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _time (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _track_number
     (setq _track_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_robot_laser_control::MsgInfo :md5sum-) "e43375f64afc0ea18fe6ceb84397eb65")
(setf (get simtech_robot_laser_control::MsgInfo :datatype-) "simtech_robot_laser_control/MsgInfo")
(setf (get simtech_robot_laser_control::MsgInfo :definition-)
      "Header header
string time
int32 track_number

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



(provide :simtech_robot_laser_control/MsgInfo "e43375f64afc0ea18fe6ceb84397eb65")


