;; Auto-generated. Do not edit!


(when (boundp 'simtech_kuka_rsi_hw_interface::MsgCartVelocity)
  (if (not (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE"))
    (make-package "SIMTECH_KUKA_RSI_HW_INTERFACE"))
  (shadow 'MsgCartVelocity (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE")))
(unless (find-package "SIMTECH_KUKA_RSI_HW_INTERFACE::MSGCARTVELOCITY")
  (make-package "SIMTECH_KUKA_RSI_HW_INTERFACE::MSGCARTVELOCITY"))

(in-package "ROS")
;;//! \htmlinclude MsgCartVelocity.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass simtech_kuka_rsi_hw_interface::MsgCartVelocity
  :super ros::object
  :slots (_header _Vx _Vy _Vz _Speed ))

(defmethod simtech_kuka_rsi_hw_interface::MsgCartVelocity
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:Vx __Vx) 0.0)
    ((:Vy __Vy) 0.0)
    ((:Vz __Vz) 0.0)
    ((:Speed __Speed) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _Vx (float __Vx))
   (setq _Vy (float __Vy))
   (setq _Vz (float __Vz))
   (setq _Speed (float __Speed))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:Vx
   (&optional __Vx)
   (if __Vx (setq _Vx __Vx)) _Vx)
  (:Vy
   (&optional __Vy)
   (if __Vy (setq _Vy __Vy)) _Vy)
  (:Vz
   (&optional __Vz)
   (if __Vz (setq _Vz __Vz)) _Vz)
  (:Speed
   (&optional __Speed)
   (if __Speed (setq _Speed __Speed)) _Speed)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _Vx
    4
    ;; float32 _Vy
    4
    ;; float32 _Vz
    4
    ;; float32 _Speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _Vx
       (sys::poke _Vx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Vy
       (sys::poke _Vy (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Vz
       (sys::poke _Vz (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _Speed
       (sys::poke _Speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _Vx
     (setq _Vx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Vy
     (setq _Vy (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Vz
     (setq _Vz (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _Speed
     (setq _Speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_kuka_rsi_hw_interface::MsgCartVelocity :md5sum-) "595faad6b795bb4eb50cefc150fb1610")
(setf (get simtech_kuka_rsi_hw_interface::MsgCartVelocity :datatype-) "simtech_kuka_rsi_hw_interface/MsgCartVelocity")
(setf (get simtech_kuka_rsi_hw_interface::MsgCartVelocity :definition-)
      "Header header
float32 Vx
float32 Vy
float32 Vz
float32 Speed


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



(provide :simtech_kuka_rsi_hw_interface/MsgCartVelocity "595faad6b795bb4eb50cefc150fb1610")


