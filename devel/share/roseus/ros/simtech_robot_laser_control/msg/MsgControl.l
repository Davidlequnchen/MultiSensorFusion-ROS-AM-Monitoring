;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::MsgControl)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'MsgControl (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::MSGCONTROL")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::MSGCONTROL"))

(in-package "ROS")
;;//! \htmlinclude MsgControl.msg.html


(defclass simtech_robot_laser_control::MsgControl
  :super ros::object
  :slots (_change _value ))

(defmethod simtech_robot_laser_control::MsgControl
  (:init
   (&key
    ((:change __change) nil)
    ((:value __value) 0)
    )
   (send-super :init)
   (setq _change __change)
   (setq _value (round __value))
   self)
  (:change
   (&optional (__change :null))
   (if (not (eq __change :null)) (setq _change __change)) _change)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; bool _change
    1
    ;; int32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _change
       (if _change (write-byte -1 s) (write-byte 0 s))
     ;; int32 _value
       (write-long _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _change
     (setq _change (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _value
     (setq _value (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_robot_laser_control::MsgControl :md5sum-) "c0714776f3b1ecd3928d4fe859ff95f8")
(setf (get simtech_robot_laser_control::MsgControl :datatype-) "simtech_robot_laser_control/MsgControl")
(setf (get simtech_robot_laser_control::MsgControl :definition-)
      "# /control/parameters topic 
bool change
int32 value

")



(provide :simtech_robot_laser_control/MsgControl "c0714776f3b1ecd3928d4fe859ff95f8")


