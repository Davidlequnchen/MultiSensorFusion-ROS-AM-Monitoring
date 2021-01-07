; Auto-generated. Do not edit!


(cl:in-package motion_planning_jason-srv)


;//! \htmlinclude SrvRobotCommand-request.msg.html

(cl:defclass <SrvRobotCommand-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:string
    :initform ""))
)

(cl:defclass SrvRobotCommand-request (<SrvRobotCommand-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SrvRobotCommand-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SrvRobotCommand-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motion_planning_jason-srv:<SrvRobotCommand-request> is deprecated: use motion_planning_jason-srv:SrvRobotCommand-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <SrvRobotCommand-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motion_planning_jason-srv:command-val is deprecated.  Use motion_planning_jason-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SrvRobotCommand-request>) ostream)
  "Serializes a message object of type '<SrvRobotCommand-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'command))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SrvRobotCommand-request>) istream)
  "Deserializes a message object of type '<SrvRobotCommand-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'command) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'command) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SrvRobotCommand-request>)))
  "Returns string type for a service object of type '<SrvRobotCommand-request>"
  "motion_planning_jason/SrvRobotCommandRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SrvRobotCommand-request)))
  "Returns string type for a service object of type 'SrvRobotCommand-request"
  "motion_planning_jason/SrvRobotCommandRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SrvRobotCommand-request>)))
  "Returns md5sum for a message object of type '<SrvRobotCommand-request>"
  "22c7c465d64c7e74c6ae22029c7ca150")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SrvRobotCommand-request)))
  "Returns md5sum for a message object of type 'SrvRobotCommand-request"
  "22c7c465d64c7e74c6ae22029c7ca150")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SrvRobotCommand-request>)))
  "Returns full string definition for message of type '<SrvRobotCommand-request>"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SrvRobotCommand-request)))
  "Returns full string definition for message of type 'SrvRobotCommand-request"
  (cl:format cl:nil "string command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SrvRobotCommand-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'command))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SrvRobotCommand-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SrvRobotCommand-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude SrvRobotCommand-response.msg.html

(cl:defclass <SrvRobotCommand-response> (roslisp-msg-protocol:ros-message)
  ((response
    :reader response
    :initarg :response
    :type cl:string
    :initform ""))
)

(cl:defclass SrvRobotCommand-response (<SrvRobotCommand-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SrvRobotCommand-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SrvRobotCommand-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motion_planning_jason-srv:<SrvRobotCommand-response> is deprecated: use motion_planning_jason-srv:SrvRobotCommand-response instead.")))

(cl:ensure-generic-function 'response-val :lambda-list '(m))
(cl:defmethod response-val ((m <SrvRobotCommand-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motion_planning_jason-srv:response-val is deprecated.  Use motion_planning_jason-srv:response instead.")
  (response m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SrvRobotCommand-response>) ostream)
  "Serializes a message object of type '<SrvRobotCommand-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'response))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'response))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SrvRobotCommand-response>) istream)
  "Deserializes a message object of type '<SrvRobotCommand-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'response) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'response) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SrvRobotCommand-response>)))
  "Returns string type for a service object of type '<SrvRobotCommand-response>"
  "motion_planning_jason/SrvRobotCommandResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SrvRobotCommand-response)))
  "Returns string type for a service object of type 'SrvRobotCommand-response"
  "motion_planning_jason/SrvRobotCommandResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SrvRobotCommand-response>)))
  "Returns md5sum for a message object of type '<SrvRobotCommand-response>"
  "22c7c465d64c7e74c6ae22029c7ca150")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SrvRobotCommand-response)))
  "Returns md5sum for a message object of type 'SrvRobotCommand-response"
  "22c7c465d64c7e74c6ae22029c7ca150")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SrvRobotCommand-response>)))
  "Returns full string definition for message of type '<SrvRobotCommand-response>"
  (cl:format cl:nil "string response~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SrvRobotCommand-response)))
  "Returns full string definition for message of type 'SrvRobotCommand-response"
  (cl:format cl:nil "string response~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SrvRobotCommand-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'response))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SrvRobotCommand-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SrvRobotCommand-response
    (cl:cons ':response (response msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SrvRobotCommand)))
  'SrvRobotCommand-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SrvRobotCommand)))
  'SrvRobotCommand-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SrvRobotCommand)))
  "Returns string type for a service object of type '<SrvRobotCommand>"
  "motion_planning_jason/SrvRobotCommand")