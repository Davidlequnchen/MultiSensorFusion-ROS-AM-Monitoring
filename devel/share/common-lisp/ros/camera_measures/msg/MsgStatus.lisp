; Auto-generated. Do not edit!


(cl:in-package camera_measures-msg)


;//! \htmlinclude MsgStatus.msg.html

(cl:defclass <MsgStatus> (roslisp-msg-protocol:ros-message)
  ((running
    :reader running
    :initarg :running
    :type cl:boolean
    :initform cl:nil)
   (laser_on
    :reader laser_on
    :initarg :laser_on
    :type cl:boolean
    :initform cl:nil)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0)
   (power
    :reader power
    :initarg :power
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgStatus (<MsgStatus>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgStatus>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgStatus)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_measures-msg:<MsgStatus> is deprecated: use camera_measures-msg:MsgStatus instead.")))

(cl:ensure-generic-function 'running-val :lambda-list '(m))
(cl:defmethod running-val ((m <MsgStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:running-val is deprecated.  Use camera_measures-msg:running instead.")
  (running m))

(cl:ensure-generic-function 'laser_on-val :lambda-list '(m))
(cl:defmethod laser_on-val ((m <MsgStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:laser_on-val is deprecated.  Use camera_measures-msg:laser_on instead.")
  (laser_on m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <MsgStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:speed-val is deprecated.  Use camera_measures-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'power-val :lambda-list '(m))
(cl:defmethod power-val ((m <MsgStatus>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:power-val is deprecated.  Use camera_measures-msg:power instead.")
  (power m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgStatus>) ostream)
  "Serializes a message object of type '<MsgStatus>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'running) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'laser_on) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'power))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgStatus>) istream)
  "Deserializes a message object of type '<MsgStatus>"
    (cl:setf (cl:slot-value msg 'running) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'laser_on) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'power) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgStatus>)))
  "Returns string type for a message object of type '<MsgStatus>"
  "camera_measures/MsgStatus")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgStatus)))
  "Returns string type for a message object of type 'MsgStatus"
  "camera_measures/MsgStatus")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgStatus>)))
  "Returns md5sum for a message object of type '<MsgStatus>"
  "9a60217041610aa06a277c2abf60970c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgStatus)))
  "Returns md5sum for a message object of type 'MsgStatus"
  "9a60217041610aa06a277c2abf60970c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgStatus>)))
  "Returns full string definition for message of type '<MsgStatus>"
  (cl:format cl:nil "bool running~%bool laser_on~%float32 speed~%float32 power~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgStatus)))
  "Returns full string definition for message of type 'MsgStatus"
  (cl:format cl:nil "bool running~%bool laser_on~%float32 speed~%float32 power~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgStatus>))
  (cl:+ 0
     1
     1
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgStatus>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgStatus
    (cl:cons ':running (running msg))
    (cl:cons ':laser_on (laser_on msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':power (power msg))
))
