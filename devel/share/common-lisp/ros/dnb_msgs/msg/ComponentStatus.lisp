; Auto-generated. Do not edit!


(cl:in-package dnb_msgs-msg)


;//! \htmlinclude ComponentStatus.msg.html

(cl:defclass <ComponentStatus> (roslisp-msg-protocol:ros-message)
  ((status_id
    :reader status_id
    :initarg :status_id
    :type cl:fixnum
    :initform 0)
   (status_msg
    :reader status_msg
    :initarg :status_msg
    :type cl:string
    :initform ""))
)

(cl:defclass ComponentStatus (<ComponentStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ComponentStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ComponentStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dnb_msgs-msg:<ComponentStatus> is deprecated: use dnb_msgs-msg:ComponentStatus instead.")))

(cl:ensure-generic-function 'status_id-val :lambda-list '(m))
(cl:defmethod status_id-val ((m <ComponentStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dnb_msgs-msg:status_id-val is deprecated.  Use dnb_msgs-msg:status_id instead.")
  (status_id m))

(cl:ensure-generic-function 'status_msg-val :lambda-list '(m))
(cl:defmethod status_msg-val ((m <ComponentStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dnb_msgs-msg:status_msg-val is deprecated.  Use dnb_msgs-msg:status_msg instead.")
  (status_msg m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<ComponentStatus>)))
    "Constants for message type '<ComponentStatus>"
  '((:INITIALIZED . 0)
    (:STOPPED . 1)
    (:RUNNING . 2)
    (:CONFIG_NEEDED . 3)
    (:ERROR . 4)
    (:INTERACTION_REQUEST . 5)
    (:DEACTIVATED . 6))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'ComponentStatus)))
    "Constants for message type 'ComponentStatus"
  '((:INITIALIZED . 0)
    (:STOPPED . 1)
    (:RUNNING . 2)
    (:CONFIG_NEEDED . 3)
    (:ERROR . 4)
    (:INTERACTION_REQUEST . 5)
    (:DEACTIVATED . 6))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ComponentStatus>) ostream)
  "Serializes a message object of type '<ComponentStatus>"
  (cl:let* ((signed (cl:slot-value msg 'status_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'status_msg))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'status_msg))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ComponentStatus>) istream)
  "Deserializes a message object of type '<ComponentStatus>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status_id) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status_msg) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'status_msg) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ComponentStatus>)))
  "Returns string type for a message object of type '<ComponentStatus>"
  "dnb_msgs/ComponentStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ComponentStatus)))
  "Returns string type for a message object of type 'ComponentStatus"
  "dnb_msgs/ComponentStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ComponentStatus>)))
  "Returns md5sum for a message object of type '<ComponentStatus>"
  "3edf5da01aa562198fec3c468cecb80b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ComponentStatus)))
  "Returns md5sum for a message object of type 'ComponentStatus"
  "3edf5da01aa562198fec3c468cecb80b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ComponentStatus>)))
  "Returns full string definition for message of type '<ComponentStatus>"
  (cl:format cl:nil "# component id; it must be unique among all registered components~%# @TODO: use on one topic and identify by id~%#string component_id~%~%# the official status id of the component~%# possible values are~%int8 INITIALIZED = 0~%int8 STOPPED = 1~%int8 RUNNING = 2~%int8 CONFIG_NEEDED = 3~%int8 ERROR = 4~%int8 INTERACTION_REQUEST = 5~%int8 DEACTIVATED = 6~%int8 status_id~%~%# an individual message for config or error cases~%# it should describe the type of needed config or occurred error briefly~%# it should be possible to extract automaticly subsequent actions/instructions from the message if this is needed~%string status_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ComponentStatus)))
  "Returns full string definition for message of type 'ComponentStatus"
  (cl:format cl:nil "# component id; it must be unique among all registered components~%# @TODO: use on one topic and identify by id~%#string component_id~%~%# the official status id of the component~%# possible values are~%int8 INITIALIZED = 0~%int8 STOPPED = 1~%int8 RUNNING = 2~%int8 CONFIG_NEEDED = 3~%int8 ERROR = 4~%int8 INTERACTION_REQUEST = 5~%int8 DEACTIVATED = 6~%int8 status_id~%~%# an individual message for config or error cases~%# it should describe the type of needed config or occurred error briefly~%# it should be possible to extract automaticly subsequent actions/instructions from the message if this is needed~%string status_msg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ComponentStatus>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'status_msg))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ComponentStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'ComponentStatus
    (cl:cons ':status_id (status_id msg))
    (cl:cons ':status_msg (status_msg msg))
))
