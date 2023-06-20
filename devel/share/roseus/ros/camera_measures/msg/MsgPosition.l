;; Auto-generated. Do not edit!


(when (boundp 'camera_measures::MsgPosition)
  (if (not (find-package "CAMERA_MEASURES"))
    (make-package "CAMERA_MEASURES"))
  (shadow 'MsgPosition (find-package "CAMERA_MEASURES")))
(unless (find-package "CAMERA_MEASURES::MSGPOSITION")
  (make-package "CAMERA_MEASURES::MSGPOSITION"))

(in-package "ROS")
;;//! \htmlinclude MsgPosition.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass camera_measures::MsgPosition
  :super ros::object
  :slots (_header _x _y _z _R _P _Y ))

(defmethod camera_measures::MsgPosition
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:z __z) 0.0)
    ((:R __R) 0.0)
    ((:P __P) 0.0)
    ((:Y __Y) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _z (float __z))
   (setq _R (float __R))
   (setq _P (float __P))
   (setq _Y (float __Y))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:R
   (&optional __R)
   (if __R (setq _R __R)) _R)
  (:P
   (&optional __P)
   (if __P (setq _P __P)) _P)
  (:Y
   (&optional __Y)
   (if __Y (setq _Y __Y)) _Y)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _x
    4
    ;; float32 _y
    4
    ;; float32 _z
    4
    ;; float32 _R
    4
    ;; float32 _P
    4
    ;; float32 _Y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _z
       (sys::poke _z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _R
       (sys::poke _R (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _P
       (sys::poke _P (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Y
       (sys::poke _Y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _z
     (setq _z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _R
     (setq _R (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _P
     (setq _P (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Y
     (setq _Y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get camera_measures::MsgPosition :md5sum-) "a33e61886c7dde7e01a026357f37c92e")
(setf (get camera_measures::MsgPosition :datatype-) "camera_measures/MsgPosition")
(setf (get camera_measures::MsgPosition :definition-)
      "Header header
float32 x
float32 y
float32 z
float32 R
float32 P
float32 Y

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



(provide :camera_measures/MsgPosition "a33e61886c7dde7e01a026357f37c92e")


