;; Auto-generated. Do not edit!


(when (boundp 'aimen_driver::SrvRobotCommand)
  (if (not (find-package "AIMEN_DRIVER"))
    (make-package "AIMEN_DRIVER"))
  (shadow 'SrvRobotCommand (find-package "AIMEN_DRIVER")))
(unless (find-package "AIMEN_DRIVER::SRVROBOTCOMMAND")
  (make-package "AIMEN_DRIVER::SRVROBOTCOMMAND"))
(unless (find-package "AIMEN_DRIVER::SRVROBOTCOMMANDREQUEST")
  (make-package "AIMEN_DRIVER::SRVROBOTCOMMANDREQUEST"))
(unless (find-package "AIMEN_DRIVER::SRVROBOTCOMMANDRESPONSE")
  (make-package "AIMEN_DRIVER::SRVROBOTCOMMANDRESPONSE"))

(in-package "ROS")





(defclass aimen_driver::SrvRobotCommandRequest
  :super ros::object
  :slots (_command ))

(defmethod aimen_driver::SrvRobotCommandRequest
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

(defclass aimen_driver::SrvRobotCommandResponse
  :super ros::object
  :slots (_response ))

(defmethod aimen_driver::SrvRobotCommandResponse
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

(defclass aimen_driver::SrvRobotCommand
  :super ros::object
  :slots ())

(setf (get aimen_driver::SrvRobotCommand :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get aimen_driver::SrvRobotCommand :datatype-) "aimen_driver/SrvRobotCommand")
(setf (get aimen_driver::SrvRobotCommand :request) aimen_driver::SrvRobotCommandRequest)
(setf (get aimen_driver::SrvRobotCommand :response) aimen_driver::SrvRobotCommandResponse)

(defmethod aimen_driver::SrvRobotCommandRequest
  (:response () (instance aimen_driver::SrvRobotCommandResponse :init)))

(setf (get aimen_driver::SrvRobotCommandRequest :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get aimen_driver::SrvRobotCommandRequest :datatype-) "aimen_driver/SrvRobotCommandRequest")
(setf (get aimen_driver::SrvRobotCommandRequest :definition-)
      "string command
---
string response

")

(setf (get aimen_driver::SrvRobotCommandResponse :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get aimen_driver::SrvRobotCommandResponse :datatype-) "aimen_driver/SrvRobotCommandResponse")
(setf (get aimen_driver::SrvRobotCommandResponse :definition-)
      "string command
---
string response

")



(provide :aimen_driver/SrvRobotCommand "22c7c465d64c7e74c6ae22029c7ca150")


