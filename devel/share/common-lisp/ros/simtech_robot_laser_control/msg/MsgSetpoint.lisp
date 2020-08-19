; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgSetpoint.msg.html

(cl:defclass <MsgSetpoint> (roslisp-msg-protocol:ros-message)
  ((setpoint
    :reader setpoint
    :initarg :setpoint
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgSetpoint (<MsgSetpoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgSetpoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgSetpoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgSetpoint> is deprecated: use simtech_robot_laser_control-msg:MsgSetpoint instead.")))

(cl:ensure-generic-function 'setpoint-val :lambda-list '(m))
(cl:defmethod setpoint-val ((m <MsgSetpoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:setpoint-val is deprecated.  Use simtech_robot_laser_control-msg:setpoint instead.")
  (setpoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgSetpoint>) ostream)
  "Serializes a message object of type '<MsgSetpoint>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgSetpoint>) istream)
  "Deserializes a message object of type '<MsgSetpoint>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'setpoint) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgSetpoint>)))
  "Returns string type for a message object of type '<MsgSetpoint>"
  "simtech_robot_laser_control/MsgSetpoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgSetpoint)))
  "Returns string type for a message object of type 'MsgSetpoint"
  "simtech_robot_laser_control/MsgSetpoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgSetpoint>)))
  "Returns md5sum for a message object of type '<MsgSetpoint>"
  "c4b0a2d45139da8ec935e105dc5a9cb2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgSetpoint)))
  "Returns md5sum for a message object of type 'MsgSetpoint"
  "c4b0a2d45139da8ec935e105dc5a9cb2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgSetpoint>)))
  "Returns full string definition for message of type '<MsgSetpoint>"
  (cl:format cl:nil "float32 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgSetpoint)))
  "Returns full string definition for message of type 'MsgSetpoint"
  (cl:format cl:nil "float32 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgSetpoint>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgSetpoint>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgSetpoint
    (cl:cons ':setpoint (setpoint msg))
))
