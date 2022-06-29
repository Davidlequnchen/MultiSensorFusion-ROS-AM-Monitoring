;; Auto-generated. Do not edit!


(when (boundp 'simtech_kuka_eki_interface::SrvRobotCommand)
  (if (not (find-package "SIMTECH_KUKA_EKI_INTERFACE"))
    (make-package "SIMTECH_KUKA_EKI_INTERFACE"))
  (shadow 'SrvRobotCommand (find-package "SIMTECH_KUKA_EKI_INTERFACE")))
(unless (find-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMAND")
  (make-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMAND"))
(unless (find-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMANDREQUEST")
  (make-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMANDREQUEST"))
(unless (find-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMANDRESPONSE")
  (make-package "SIMTECH_KUKA_EKI_INTERFACE::SRVROBOTCOMMANDRESPONSE"))

(in-package "ROS")





(defclass simtech_kuka_eki_interface::SrvRobotCommandRequest
  :super ros::object
  :slots (_command ))

(defmethod simtech_kuka_eki_interface::SrvRobotCommandRequest
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

(defclass simtech_kuka_eki_interface::SrvRobotCommandResponse
  :super ros::object
  :slots (_response ))

(defmethod simtech_kuka_eki_interface::SrvRobotCommandResponse
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

(defclass simtech_kuka_eki_interface::SrvRobotCommand
  :super ros::object
  :slots ())

(setf (get simtech_kuka_eki_interface::SrvRobotCommand :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_kuka_eki_interface::SrvRobotCommand :datatype-) "simtech_kuka_eki_interface/SrvRobotCommand")
(setf (get simtech_kuka_eki_interface::SrvRobotCommand :request) simtech_kuka_eki_interface::SrvRobotCommandRequest)
(setf (get simtech_kuka_eki_interface::SrvRobotCommand :response) simtech_kuka_eki_interface::SrvRobotCommandResponse)

(defmethod simtech_kuka_eki_interface::SrvRobotCommandRequest
  (:response () (instance simtech_kuka_eki_interface::SrvRobotCommandResponse :init)))

(setf (get simtech_kuka_eki_interface::SrvRobotCommandRequest :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_kuka_eki_interface::SrvRobotCommandRequest :datatype-) "simtech_kuka_eki_interface/SrvRobotCommandRequest")
(setf (get simtech_kuka_eki_interface::SrvRobotCommandRequest :definition-)
      "string command
---
string response

")

(setf (get simtech_kuka_eki_interface::SrvRobotCommandResponse :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get simtech_kuka_eki_interface::SrvRobotCommandResponse :datatype-) "simtech_kuka_eki_interface/SrvRobotCommandResponse")
(setf (get simtech_kuka_eki_interface::SrvRobotCommandResponse :definition-)
      "string command
---
string response

")



(provide :simtech_kuka_eki_interface/SrvRobotCommand "22c7c465d64c7e74c6ae22029c7ca150")


