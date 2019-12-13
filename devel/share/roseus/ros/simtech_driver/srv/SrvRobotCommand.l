;; Auto-generated. Do not edit!


(when (boundp 'simtech_driver::SrvRobotCommand)
  (if (not (find-package "SIMTECH_DRIVER"))
    (make-package "SIMTECH_DRIVER"))
  (shadow 'SrvRobotCommand (find-package "SIMTECH_DRIVER")))
(unless (find-package "SIMTECH_DRIVER::SRVROBOTCOMMAND")
  (make-package "SIMTECH_DRIVER::SRVROBOTCOMMAND"))
(unless (find-package "SIMTECH_DRIVER::SRVROBOTCOMMANDREQUEST")
  (make-package "SIMTECH_DRIVER::SRVROBOTCOMMANDREQUEST"))
(unless (find-package "SIMTECH_DRIVER::SRVROBOTCOMMANDRESPONSE")
  (make-package "SIMTECH_DRIVER::SRVROBOTCOMMANDRESPONSE"))

(in-package "ROS")





(defclass simtech_driver::SrvRobotCommandRequest
  :super ros::object
  :slots (_command ))

(defmethod simtech_driver::SrvRobotCommandRequest
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

(defclass simtech_driver::SrvRobotCommandResponse
  :super ros::object
  :slots (_response ))

(defmethod simtech_driver::SrvRobotCommandResponse
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

(defclass simtech_driver::SrvRobotCommand
  :super ros::object
  :slots ())

(setf (get simtech_driver::SrvRobotCommand :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_driver::SrvRobotCommand :datatype-) "simtech_driver/SrvRobotCommand")
(setf (get simtech_driver::SrvRobotCommand :request) simtech_driver::SrvRobotCommandRequest)
(setf (get simtech_driver::SrvRobotCommand :response) simtech_driver::SrvRobotCommandResponse)

(defmethod simtech_driver::SrvRobotCommandRequest
  (:response () (instance simtech_driver::SrvRobotCommandResponse :init)))

(setf (get simtech_driver::SrvRobotCommandRequest :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_driver::SrvRobotCommandRequest :datatype-) "simtech_driver/SrvRobotCommandRequest")
(setf (get simtech_driver::SrvRobotCommandRequest :definition-)
      "string command
---
string response

")

(setf (get simtech_driver::SrvRobotCommandResponse :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_driver::SrvRobotCommandResponse :datatype-) "simtech_driver/SrvRobotCommandResponse")
(setf (get simtech_driver::SrvRobotCommandResponse :definition-)
      "string command
---
string response

")



(provide :simtech_driver/SrvRobotCommand "22c7c465d64c7e74c6ae22029c7ca150")


