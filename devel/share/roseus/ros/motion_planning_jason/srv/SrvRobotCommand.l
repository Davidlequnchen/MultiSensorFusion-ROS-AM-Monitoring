;; Auto-generated. Do not edit!


(when (boundp 'motion_planning_jason::SrvRobotCommand)
  (if (not (find-package "MOTION_PLANNING_JASON"))
    (make-package "MOTION_PLANNING_JASON"))
  (shadow 'SrvRobotCommand (find-package "MOTION_PLANNING_JASON")))
(unless (find-package "MOTION_PLANNING_JASON::SRVROBOTCOMMAND")
  (make-package "MOTION_PLANNING_JASON::SRVROBOTCOMMAND"))
(unless (find-package "MOTION_PLANNING_JASON::SRVROBOTCOMMANDREQUEST")
  (make-package "MOTION_PLANNING_JASON::SRVROBOTCOMMANDREQUEST"))
(unless (find-package "MOTION_PLANNING_JASON::SRVROBOTCOMMANDRESPONSE")
  (make-package "MOTION_PLANNING_JASON::SRVROBOTCOMMANDRESPONSE"))

(in-package "ROS")





(defclass motion_planning_jason::SrvRobotCommandRequest
  :super ros::object
  :slots (_command ))

(defmethod motion_planning_jason::SrvRobotCommandRequest
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

(defclass motion_planning_jason::SrvRobotCommandResponse
  :super ros::object
  :slots (_response ))

(defmethod motion_planning_jason::SrvRobotCommandResponse
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

(defclass motion_planning_jason::SrvRobotCommand
  :super ros::object
  :slots ())

(setf (get motion_planning_jason::SrvRobotCommand :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get motion_planning_jason::SrvRobotCommand :datatype-) "motion_planning_jason/SrvRobotCommand")
(setf (get motion_planning_jason::SrvRobotCommand :request) motion_planning_jason::SrvRobotCommandRequest)
(setf (get motion_planning_jason::SrvRobotCommand :response) motion_planning_jason::SrvRobotCommandResponse)

(defmethod motion_planning_jason::SrvRobotCommandRequest
  (:response () (instance motion_planning_jason::SrvRobotCommandResponse :init)))

(setf (get motion_planning_jason::SrvRobotCommandRequest :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get motion_planning_jason::SrvRobotCommandRequest :datatype-) "motion_planning_jason/SrvRobotCommandRequest")
(setf (get motion_planning_jason::SrvRobotCommandRequest :definition-)
      "string command
---
string response

")

(setf (get motion_planning_jason::SrvRobotCommandResponse :md5sum-) "22c7c465d64c7e74c6ae22029c7ca150")
(setf (get motion_planning_jason::SrvRobotCommandResponse :datatype-) "motion_planning_jason/SrvRobotCommandResponse")
(setf (get motion_planning_jason::SrvRobotCommandResponse :definition-)
      "string command
---
string response

")



(provide :motion_planning_jason/SrvRobotCommand "22c7c465d64c7e74c6ae22029c7ca150")


