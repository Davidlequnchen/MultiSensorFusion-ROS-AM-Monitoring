; Auto-generated. Do not edit!


(cl:in-package camera_measures-msg)


;//! \htmlinclude MsgVelocityStatus.msg.html

(cl:defclass <MsgVelocityStatus> (roslisp-msg-protocol:ros-message)
  ((running
    :reader running
    :initarg :running
    :type cl:boolean
    :initform cl:nil)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgVelocityStatus (<MsgVelocityStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgVelocityStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgVelocityStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_measures-msg:<MsgVelocityStatus> is deprecated: use camera_measures-msg:MsgVelocityStatus instead.")))

(cl:ensure-generic-function 'running-val :lambda-list '(m))
(cl:defmethod running-val ((m <MsgVelocityStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:running-val is deprecated.  Use camera_measures-msg:running instead.")
  (running m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <MsgVelocityStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:speed-val is deprecated.  Use camera_measures-msg:speed instead.")
  (speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgVelocityStatus>) ostream)
  "Serializes a message object of type '<MsgVelocityStatus>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'running) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgVelocityStatus>) istream)
  "Deserializes a message object of type '<MsgVelocityStatus>"
    (cl:setf (cl:slot-value msg 'running) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgVelocityStatus>)))
  "Returns string type for a message object of type '<MsgVelocityStatus>"
  "camera_measures/MsgVelocityStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgVelocityStatus)))
  "Returns string type for a message object of type 'MsgVelocityStatus"
  "camera_measures/MsgVelocityStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgVelocityStatus>)))
  "Returns md5sum for a message object of type '<MsgVelocityStatus>"
  "f12f52908a2201f7da503aef7f554966")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgVelocityStatus)))
  "Returns md5sum for a message object of type 'MsgVelocityStatus"
  "f12f52908a2201f7da503aef7f554966")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgVelocityStatus>)))
  "Returns full string definition for message of type '<MsgVelocityStatus>"
  (cl:format cl:nil "bool running~%float32 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgVelocityStatus)))
  "Returns full string definition for message of type 'MsgVelocityStatus"
  (cl:format cl:nil "bool running~%float32 speed~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgVelocityStatus>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgVelocityStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgVelocityStatus
    (cl:cons ':running (running msg))
    (cl:cons ':speed (speed msg))
))
