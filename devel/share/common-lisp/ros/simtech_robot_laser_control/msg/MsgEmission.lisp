; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgEmission.msg.html

(cl:defclass <MsgEmission> (roslisp-msg-protocol:ros-message)
  ((emission
    :reader emission
    :initarg :emission
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MsgEmission (<MsgEmission>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgEmission>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgEmission)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgEmission> is deprecated: use simtech_robot_laser_control-msg:MsgEmission instead.")))

(cl:ensure-generic-function 'emission-val :lambda-list '(m))
(cl:defmethod emission-val ((m <MsgEmission>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:emission-val is deprecated.  Use simtech_robot_laser_control-msg:emission instead.")
  (emission m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgEmission>) ostream)
  "Serializes a message object of type '<MsgEmission>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'emission) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgEmission>) istream)
  "Deserializes a message object of type '<MsgEmission>"
    (cl:setf (cl:slot-value msg 'emission) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgEmission>)))
  "Returns string type for a message object of type '<MsgEmission>"
  "simtech_robot_laser_control/MsgEmission")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgEmission)))
  "Returns string type for a message object of type 'MsgEmission"
  "simtech_robot_laser_control/MsgEmission")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgEmission>)))
  "Returns md5sum for a message object of type '<MsgEmission>"
  "b41438f20140254925ccd78f3541f322")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgEmission)))
  "Returns md5sum for a message object of type 'MsgEmission"
  "b41438f20140254925ccd78f3541f322")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgEmission>)))
  "Returns full string definition for message of type '<MsgEmission>"
  (cl:format cl:nil "bool emission~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgEmission)))
  "Returns full string definition for message of type 'MsgEmission"
  (cl:format cl:nil "bool emission~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgEmission>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgEmission>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgEmission
    (cl:cons ':emission (emission msg))
))
