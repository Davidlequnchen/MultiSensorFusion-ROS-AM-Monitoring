; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgControl.msg.html

(cl:defclass <MsgControl> (roslisp-msg-protocol:ros-message)
  ((change
    :reader change
    :initarg :change
    :type cl:boolean
    :initform cl:nil)
   (value
    :reader value
    :initarg :value
    :type cl:integer
    :initform 0))
)

(cl:defclass MsgControl (<MsgControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgControl> is deprecated: use simtech_robot_laser_control-msg:MsgControl instead.")))

(cl:ensure-generic-function 'change-val :lambda-list '(m))
(cl:defmethod change-val ((m <MsgControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:change-val is deprecated.  Use simtech_robot_laser_control-msg:change instead.")
  (change m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <MsgControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:value-val is deprecated.  Use simtech_robot_laser_control-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgControl>) ostream)
  "Serializes a message object of type '<MsgControl>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'change) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'value)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgControl>) istream)
  "Deserializes a message object of type '<MsgControl>"
    (cl:setf (cl:slot-value msg 'change) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgControl>)))
  "Returns string type for a message object of type '<MsgControl>"
  "simtech_robot_laser_control/MsgControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgControl)))
  "Returns string type for a message object of type 'MsgControl"
  "simtech_robot_laser_control/MsgControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgControl>)))
  "Returns md5sum for a message object of type '<MsgControl>"
  "c0714776f3b1ecd3928d4fe859ff95f8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgControl)))
  "Returns md5sum for a message object of type 'MsgControl"
  "c0714776f3b1ecd3928d4fe859ff95f8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgControl>)))
  "Returns full string definition for message of type '<MsgControl>"
  (cl:format cl:nil "# /control/parameters topic ~%bool change~%int32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgControl)))
  "Returns full string definition for message of type 'MsgControl"
  (cl:format cl:nil "# /control/parameters topic ~%bool change~%int32 value~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgControl>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgControl>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgControl
    (cl:cons ':change (change msg))
    (cl:cons ':value (value msg))
))
