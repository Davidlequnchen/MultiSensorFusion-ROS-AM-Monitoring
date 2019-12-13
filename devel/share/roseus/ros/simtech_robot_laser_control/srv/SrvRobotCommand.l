;; Auto-generated. Do not edit!


(when (boundp 'simtech_robot_laser_control::SrvRobotCommand)
  (if (not (find-package "SIMTECH_ROBOT_LASER_CONTROL"))
    (make-package "SIMTECH_ROBOT_LASER_CONTROL"))
  (shadow 'SrvRobotCommand (find-package "SIMTECH_ROBOT_LASER_CONTROL")))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMAND")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMAND"))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMANDREQUEST")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMANDREQUEST"))
(unless (find-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMANDRESPONSE")
  (make-package "SIMTECH_ROBOT_LASER_CONTROL::SRVROBOTCOMMANDRESPONSE"))

(in-package "ROS")





(defclass simtech_robot_laser_control::SrvRobotCommandRequest
  :super ros::object
  :slots (_command ))

(defmethod simtech_robot_laser_control::SrvRobotCommandRequest
  (:init
   (&key
    ((:command __command) "")
    )
   (send-super :init)
   (setq _command (string __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; string _command
    4 (length _command)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _command
       (write-long (length _command) s) (princ _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _command
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _command (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass simtech_robot_laser_control::SrvRobotCommandResponse
  :super ros::object
  :slots (_response ))

(defmethod simtech_robot_laser_control::SrvRobotCommandResponse
  (:init
   (&key
    ((:response __response) "")
    )
   (send-super :init)
   (setq _response (string __response))
   self)
  (:response
   (&optional __response)
   (if __response (setq _response __response)) _response)
  (:serialization-length
   ()
   (+
    ;; string _response
    4 (length _response)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _response
       (write-long (length _response) s) (princ _response s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _response
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _response (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass simtech_robot_laser_control::SrvRobotCommand
  :super ros::object
  :slots ())

(setf (get simtech_robot_laser_control::SrvRobotCommand :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_robot_laser_control::SrvRobotCommand :datatype-) "simtech_robot_laser_control/SrvRobotCommand")
(setf (get simtech_robot_laser_control::SrvRobotCommand :request) simtech_robot_laser_control::SrvRobotCommandRequest)
(setf (get simtech_robot_laser_control::SrvRobotCommand :response) simtech_robot_laser_control::SrvRobotCommandResponse)

(defmethod simtech_robot_laser_control::SrvRobotCommandRequest
  (:response () (instance simtech_robot_laser_control::SrvRobotCommandResponse :init)))

(setf (get simtech_robot_laser_control::SrvRobotCommandRequest :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_robot_laser_control::SrvRobotCommandRequest :datatype-) "simtech_robot_laser_control/SrvRobotCommandRequest")
(setf (get simtech_robot_laser_control::SrvRobotCommandRequest :definition-)
      "string command
---
string response

")

(setf (get simtech_robot_laser_control::SrvRobotCommandResponse :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_robot_laser_control::SrvRobotCommandResponse :datatype-) "simtech_robot_laser_control/SrvRobotCommandResponse")
(setf (get simtech_robot_laser_control::SrvRobotCommandResponse :definition-)
      "string command
---
string response

")



(provide :simtech_robot_laser_control/SrvRobotCommand "22c7c465d64c7e74c6ae22029c7ca150")


