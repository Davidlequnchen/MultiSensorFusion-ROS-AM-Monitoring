;; Auto-generated. Do not edit!


(when (boundp 'simtech_kuka_rsi_hw_interface::MsgCartPosition)
  (if (not (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE"))
    (make-package "SIMTECH_KUKA_RSI_HW_INTERFACE"))
  (shadow 'MsgCartPosition (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE")))
(unless (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE::MSGCARTPOSITION")
  (make-package "SIMTECH_KUKA_RSI_HW_INTERFACE::MSGCARTPOSITION"))

(in-package "ROS")
;;//! \htmlinclude MsgCartPosition.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass simtech_kuka_rsi_hw_interface::MsgCartPosition
  :super ros::object
  :slots (_header _X _Y _Z _A _B _C ))

(defmethod simtech_kuka_rsi_hw_interface::MsgCartPosition
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:X __X) 0.0)
    ((:Y __Y) 0.0)
    ((:Z __Z) 0.0)
    ((:A __A) 0.0)
    ((:B __B) 0.0)
    ((:C __C) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _X (float __X))
   (setq _Y (float __Y))
   (setq _Z (float __Z))
   (setq _A (float __A))
   (setq _B (float __B))
   (setq _C (float __C))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:Y
   (&optional __Y)
   (if __Y (setq _Y __Y)) _Y)
  (:Z
   (&optional __Z)
   (if __Z (setq _Z __Z)) _Z)
  (:A
   (&optional __A)
   (if __A (setq _A __A)) _A)
  (:B
   (&optional __B)
   (if __B (setq _B __B)) _B)
  (:C
   (&optional __C)
   (if __C (setq _C __C)) _C)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _X
    4
    ;; float32 _Y
    4
    ;; float32 _Z
    4
    ;; float32 _A
    4
    ;; float32 _B
    4
    ;; float32 _C
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _X
       (sys::poke _X (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Y
       (sys::poke _Y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Z
       (sys::poke _Z (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _A
       (sys::poke _A (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _B
       (sys::poke _B (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _C
       (sys::poke _C (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _X
     (setq _X (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Y
     (setq _Y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Z
     (setq _Z (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _A
     (setq _A (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _B
     (setq _B (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _C
     (setq _C (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_kuka_rsi_hw_interface::MsgCartPosition :md5sum-) "4b9231b9f3527787d1bed1c5f318565f")
(setf (get simtech_kuka_rsi_hw_interface::MsgCartPosition :datatype-) "simtech_kuka_rsi_hw_interface/MsgCartPosition")
(setf (get simtech_kuka_rsi_hw_interface::MsgCartPosition :definition-)
      "Header header
float32 X
float32 Y
float32 Z
float32 A
float32 B
float32 C

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



(provide :simtech_kuka_rsi_hw_interface/MsgCartPosition "4b9231b9f3527787d1bed1c5f318565f")


