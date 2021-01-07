; Auto-generated. Do not edit!


(cl:in-package microepsilon_scancontrol-msg)


;//! \htmlinclude MsgCommand.msg.html

(cl:defclass <MsgCommand> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgCommand (<MsgCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name microepsilon_scancontrol-msg:<MsgCommand> is deprecated: use microepsilon_scancontrol-msg:MsgCommand instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <MsgCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader microepsilon_scancontrol-msg:command-val is deprecated.  Use microepsilon_scancontrol-msg:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgCommand>) ostream)
  "Serializes a message object of type '<MsgCommand>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'command))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgCommand>) istream)
  "Deserializes a message object of type '<MsgCommand>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'command) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgCommand>)))
  "Returns string type for a message object of type '<MsgCommand>"
  "microepsilon_scancontrol/MsgCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgCommand)))
  "Returns string type for a message object of type 'MsgCommand"
  "microepsilon_scancontrol/MsgCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgCommand>)))
  "Returns md5sum for a message object of type '<MsgCommand>"
  "7a381543013b116822c4c5bfba61dfce")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgCommand)))
  "Returns md5sum for a message object of type 'MsgCommand"
  "7a381543013b116822c4c5bfba61dfce")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgCommand>)))
  "Returns full string definition for message of type '<MsgCommand>"
  (cl:format cl:nil "float32 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgCommand)))
  "Returns full string definition for message of type 'MsgCommand"
  (cl:format cl:nil "float32 command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgCommand>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgCommand
    (cl:cons ':command (command msg))
))
