;; Auto-generated. Do not edit!


(when (boundp 'dnb_msgs::ComponentStatus)
  (if (not (find-package "DNB_MSGS"))
    (make-package "DNB_MSGS"))
  (shadow 'ComponentStatus (find-package "DNB_MSGS")))
(unless (find-package "DNB_MSGS::COMPONENTSTATUS")
  (make-package "DNB_MSGS::COMPONENTSTATUS"))

(in-package "ROS")
;;//! \htmlinclude ComponentStatus.msg.html


(intern "*INITIALIZED*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*INITIALIZED* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*INITIALIZED* 0)
(intern "*STOPPED*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*STOPPED* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*STOPPED* 1)
(intern "*RUNNING*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*RUNNING* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*RUNNING* 2)
(intern "*CONFIG_NEEDED*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*CONFIG_NEEDED* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*CONFIG_NEEDED* 3)
(intern "*ERROR*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*ERROR* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*ERROR* 4)
(intern "*INTERACTION_REQUEST*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*INTERACTION_REQUEST* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*INTERACTION_REQUEST* 5)
(intern "*DEACTIVATED*" (find-package "DNB_MSGS::COMPONENTSTATUS"))
(shadow '*DEACTIVATED* (find-package "DNB_MSGS::COMPONENTSTATUS"))
(defconstant dnb_msgs::ComponentStatus::*DEACTIVATED* 6)
(defclass dnb_msgs::ComponentStatus
  :super ros::object
  :slots (_status_id _status_msg ))

(defmethod dnb_msgs::ComponentStatus
  (:init
   (&key
    ((:status_id __status_id) 0)
    ((:status_msg __status_msg) "")
    )
   (send-super :init)
   (setq _status_id (round __status_id))
   (setq _status_msg (string __status_msg))
   self)
  (:status_id
   (&optional __status_id)
   (if __status_id (setq _status_id __status_id)) _status_id)
  (:status_msg
   (&optional __status_msg)
   (if __status_msg (setq _status_msg __status_msg)) _status_msg)
  (:serialization-length
   ()
   (+
    ;; int8 _status_id
    1
    ;; string _status_msg
    4 (length _status_msg)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _status_id
       (write-byte _status_id s)
     ;; string _status_msg
       (write-long (length _status_msg) s) (princ _status_msg s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _status_id
     (setq _status_id (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _status_id 127) (setq _status_id (- _status_id 256)))
   ;; string _status_msg
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status_msg (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get dnb_msgs::ComponentStatus :md5sum-) "3edf5da01aa562198fec3c468cecb80b")
(setf (get dnb_msgs::ComponentStatus :datatype-) "dnb_msgs/ComponentStatus")
(setf (get dnb_msgs::ComponentStatus :definition-)
      "# component id; it must be unique among all registered components
# @TODO: use on one topic and identify by id
#string component_id

# the official status id of the component
# possible values are
int8 INITIALIZED = 0
int8 STOPPED = 1
int8 RUNNING = 2
int8 CONFIG_NEEDED = 3
int8 ERROR = 4
int8 INTERACTION_REQUEST = 5
int8 DEACTIVATED = 6
int8 status_id

# an individual message for config or error cases
# it should describe the type of needed config or occurred error briefly
# it should be possible to extract automaticly subsequent actions/instructions from the message if this is needed
string status_msg

")



(provide :dnb_msgs/ComponentStatus "3edf5da01aa562198fec3c468cecb80b")


