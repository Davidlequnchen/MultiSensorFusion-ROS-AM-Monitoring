; Auto-generated. Do not edit!


(cl:in-package simtech_kuka_rsi_hw_interface-msg)


;//! \htmlinclude MsgCartVelocity.msg.html

(cl:defclass <MsgCartVelocity> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (Vx
    :reader Vx
    :initarg :Vx
    :type cl:float
    :initform 0.0)
   (Vy
    :reader Vy
    :initarg :Vy
    :type cl:float
    :initform 0.0)
   (Vz
    :reader Vz
    :initarg :Vz
    :type cl:float
    :initform 0.0)
   (Speed
    :reader Speed
    :initarg :Speed
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgCartVelocity (<MsgCartVelocity>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgCartVelocity>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgCartVelocity)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_kuka_rsi_hw_interface-msg:<MsgCartVelocity> is deprecated: use simtech_kuka_rsi_hw_interface-msg:MsgCartVelocity instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgCartVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:header-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'Vx-val :lambda-list '(m))
(cl:defmethod Vx-val ((m <MsgCartVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Vx-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Vx instead.")
  (Vx m))

(cl:ensure-generic-function 'Vy-val :lambda-list '(m))
(cl:defmethod Vy-val ((m <MsgCartVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Vy-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Vy instead.")
  (Vy m))

(cl:ensure-generic-function 'Vz-val :lambda-list '(m))
(cl:defmethod Vz-val ((m <MsgCartVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Vz-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Vz instead.")
  (Vz m))

(cl:ensure-generic-function 'Speed-val :lambda-list '(m))
(cl:defmethod Speed-val ((m <MsgCartVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Speed-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Speed instead.")
  (Speed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgCartVelocity>) ostream)
  "Serializes a message object of type '<MsgCartVelocity>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Vx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Vy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Vz))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgCartVelocity>) istream)
  "Deserializes a message object of type '<MsgCartVelocity>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vy) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vz) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Speed) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgCartVelocity>)))
  "Returns string type for a message object of type '<MsgCartVelocity>"
  "simtech_kuka_rsi_hw_interface/MsgCartVelocity")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgCartVelocity)))
  "Returns string type for a message object of type 'MsgCartVelocity"
  "simtech_kuka_rsi_hw_interface/MsgCartVelocity")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgCartVelocity>)))
  "Returns md5sum for a message object of type '<MsgCartVelocity>"
  "595faad6b795bb4eb50cefc150fb1610")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgCartVelocity)))
  "Returns md5sum for a message object of type 'MsgCartVelocity"
  "595faad6b795bb4eb50cefc150fb1610")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgCartVelocity>)))
  "Returns full string definition for message of type '<MsgCartVelocity>"
  (cl:format cl:nil "Header header~%float32 Vx~%float32 Vy~%float32 Vz~%float32 Speed~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgCartVelocity)))
  "Returns full string definition for message of type 'MsgCartVelocity"
  (cl:format cl:nil "Header header~%float32 Vx~%float32 Vy~%float32 Vz~%float32 Speed~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgCartVelocity>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgCartVelocity>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgCartVelocity
    (cl:cons ':header (header msg))
    (cl:cons ':Vx (Vx msg))
    (cl:cons ':Vy (Vy msg))
    (cl:cons ':Vz (Vz msg))
    (cl:cons ':Speed (Speed msg))
))
