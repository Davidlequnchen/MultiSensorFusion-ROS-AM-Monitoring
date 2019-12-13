; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgStart.msg.html

(cl:defclass <MsgStart> (roslisp-msg-protocol:ros-message)
  ((control
    :reader control
    :initarg :control
    :type cl:boolean
    :initform cl:nil)
   (setpoint
    :reader setpoint
    :initarg :setpoint
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgStart (<MsgStart>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgStart>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgStart)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgStart> is deprecated: use simtech_robot_laser_control-msg:MsgStart instead.")))

(cl:ensure-generic-function 'control-val :lambda-list '(m))
(cl:defmethod control-val ((m <MsgStart>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:control-val is deprecated.  Use simtech_robot_laser_control-msg:control instead.")
  (control m))

(cl:ensure-generic-function 'setpoint-val :lambda-list '(m))
(cl:defmethod setpoint-val ((m <MsgStart>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:setpoint-val is deprecated.  Use simtech_robot_laser_control-msg:setpoint instead.")
  (setpoint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgStart>) ostream)
  "Serializes a message object of type '<MsgStart>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'control) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'setpoint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgStart>) istream)
  "Deserializes a message object of type '<MsgStart>"
    (cl:setf (cl:slot-value msg 'control) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'setpoint) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgStart>)))
  "Returns string type for a message object of type '<MsgStart>"
  "simtech_robot_laser_control/MsgStart")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgStart)))
  "Returns string type for a message object of type 'MsgStart"
  "simtech_robot_laser_control/MsgStart")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgStart>)))
  "Returns md5sum for a message object of type '<MsgStart>"
  "e881025c4deef3846ab5aed40f4f106e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgStart)))
  "Returns md5sum for a message object of type 'MsgStart"
  "e881025c4deef3846ab5aed40f4f106e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgStart>)))
  "Returns full string definition for message of type '<MsgStart>"
  (cl:format cl:nil "bool control~%float32 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgStart)))
  "Returns full string definition for message of type 'MsgStart"
  (cl:format cl:nil "bool control~%float32 setpoint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgStart>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgStart>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgStart
    (cl:cons ':control (control msg))
    (cl:cons ':setpoint (setpoint msg))
))
