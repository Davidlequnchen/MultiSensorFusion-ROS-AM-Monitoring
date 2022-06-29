;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::MsgEmission)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'MsgEmission (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::MSGEMISSION")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::MSGEMISSION"))

(in-package "ROS")
;;//! \htmlinclude MsgEmission.msg.html


(defclass simtech_robot_laser_control::MsgEmission
  :super ros::object
  :slots (_emission ))

(defmethod simtech_robot_laser_control::MsgEmission
  (:init
   (&key
    ((:emission __emission) nil)
    )
   (send-super :init)
   (setq _emission __emission)
   self)
  (:emission
   (&optional (__emission :null))
   (if (not (eq __emission :null)) (setq _emission __emission)) _emission)
  (:serialization-length
   ()
   (+
    ;; bool _emission
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _emission
       (if _emission (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _emission
     (setq _emission (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get simtech_robot_laser_control::MsgEmission :md5sum-) "b41438f20140254925ccd78f3541f322")
(setf (get simtech_robot_laser_control::MsgEmission :datatype-) "simtech_robot_laser_control/MsgEmission")
(setf (get simtech_robot_laser_control::MsgEmission :definition-)
      "bool emission

")



(provide :simtech_robot_laser_control/MsgEmission "b41438f20140254925ccd78f3541f322")


