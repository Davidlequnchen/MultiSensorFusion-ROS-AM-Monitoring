;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::MsgSetpoint)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'MsgSetpoint (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::MSGSETPOINT")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::MSGSETPOINT"))

(in-package "ROS")
;;//! \htmlinclude MsgSetpoint.msg.html


(defclass simtech_robot_laser_control::MsgSetpoint
  :super ros::object
  :slots (_setpoint ))

(defmethod simtech_robot_laser_control::MsgSetpoint
  (:init
   (&key
    ((:setpoint __setpoint) 0.0)
    )
   (send-super :init)
   (setq _setpoint (float __setpoint))
   self)
  (:setpoint
   (&optional __setpoint)
   (if __setpoint (setq _setpoint __setpoint)) _setpoint)
  (:serialization-length
   ()
   (+
    ;; float32 _setpoint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _setpoint
       (sys::poke _setpoint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _setpoint
     (setq _setpoint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simtech_robot_laser_control::MsgSetpoint :md5sum-) "c4b0a2d45139da8ec935e105dc5a9cb2")
(setf (get simtech_robot_laser_control::MsgSetpoint :datatype-) "simtech_robot_laser_control/MsgSetpoint")
(setf (get simtech_robot_laser_control::MsgSetpoint :definition-)
      "float32 setpoint

")



(provide :simtech_robot_laser_control/MsgSetpoint "c4b0a2d45139da8ec935e105dc5a9cb2")


