;; Auto-generated. Do not edit!


(when (boundp 'laser_control::MsgStart)
  (if (not (find-package "LASER_CONTROL"))
    (make-package "LASER_CONTROL"))
  (shadow 'MsgStart (find-package "LASER_CONTROL")))
(unless (find-package "LASER_CONTROL::MSGSTART")
  (make-package "LASER_CONTROL::MSGSTART"))

(in-package "ROS")
;;//! \htmlinclude MsgStart.msg.html


(defclass laser_control::MsgStart
  :super ros::object
  :slots (_control _setpoint ))

(defmethod laser_control::MsgStart
  (:init
   (&key
    ((:control __control) nil)
    ((:setpoint __setpoint) 0.0)
    )
   (send-super :init)
   (setq _control __control)
   (setq _setpoint (float __setpoint))
   self)
  (:control
   (&optional (__control :null))
   (if (not (eq __control :null)) (setq _control __control)) _control)
  (:setpoint
   (&optional __setpoint)
   (if __setpoint (setq _setpoint __setpoint)) _setpoint)
  (:serialization-length
   ()
   (+
    ;; bool _control
    1
    ;; float32 _setpoint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _control
       (if _control (write-byte -1 s) (write-byte 0 s))
     ;; float32 _setpoint
       (sys::poke _setpoint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _control
     (setq _control (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _setpoint
     (setq _setpoint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get laser_control::MsgStart :md5sum-) "e881025c4deef3846ab5aed40f4f106e")
(setf (get laser_control::MsgStart :datatype-) "laser_control/MsgStart")
(setf (get laser_control::MsgStart :definition-)
      "bool control
float32 setpoint

")



(provide :laser_control/MsgStart "e881025c4deef3846ab5aed40f4f106e")


