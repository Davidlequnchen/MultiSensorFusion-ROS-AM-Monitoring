; Auto-generated. Do not edit!


(cl:in-package simtech_kuka_rsi_hw_interface-msg)


;//! \htmlinclude MsgCartPosition.msg.html

(cl:defclass <MsgCartPosition> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (X
    :reader X
    :initarg :X
    :type cl:float
    :initform 0.0)
   (Y
    :reader Y
    :initarg :Y
    :type cl:float
    :initform 0.0)
   (Z
    :reader Z
    :initarg :Z
    :type cl:float
    :initform 0.0)
   (A
    :reader A
    :initarg :A
    :type cl:float
    :initform 0.0)
   (B
    :reader B
    :initarg :B
    :type cl:float
    :initform 0.0)
   (C
    :reader C
    :initarg :C
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgCartPosition (<MsgCartPosition>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgCartPosition>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgCartPosition)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_kuka_rsi_hw_interface-msg:<MsgCartPosition> is deprecated: use simtech_kuka_rsi_hw_interface-msg:MsgCartPosition instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:header-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'X-val :lambda-list '(m))
(cl:defmethod X-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:X-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:X instead.")
  (X m))

(cl:ensure-generic-function 'Y-val :lambda-list '(m))
(cl:defmethod Y-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Y-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Y instead.")
  (Y m))

(cl:ensure-generic-function 'Z-val :lambda-list '(m))
(cl:defmethod Z-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:Z-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:Z instead.")
  (Z m))

(cl:ensure-generic-function 'A-val :lambda-list '(m))
(cl:defmethod A-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:A-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:A instead.")
  (A m))

(cl:ensure-generic-function 'B-val :lambda-list '(m))
(cl:defmethod B-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:B-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:B instead.")
  (B m))

(cl:ensure-generic-function 'C-val :lambda-list '(m))
(cl:defmethod C-val ((m <MsgCartPosition>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_kuka_rsi_hw_interface-msg:C-val is deprecated.  Use simtech_kuka_rsi_hw_interface-msg:C instead.")
  (C m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgCartPosition>) ostream)
  "Serializes a message object of type '<MsgCartPosition>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'X))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'Z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'A))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'B))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'C))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgCartPosition>) istream)
  "Deserializes a message object of type '<MsgCartPosition>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'X) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'A) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'B) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'C) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgCartPosition>)))
  "Returns string type for a message object of type '<MsgCartPosition>"
  "simtech_kuka_rsi_hw_interface/MsgCartPosition")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgCartPosition)))
  "Returns string type for a message object of type 'MsgCartPosition"
  "simtech_kuka_rsi_hw_interface/MsgCartPosition")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgCartPosition>)))
  "Returns md5sum for a message object of type '<MsgCartPosition>"
  "4b9231b9f3527787d1bed1c5f318565f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgCartPosition)))
  "Returns md5sum for a message object of type 'MsgCartPosition"
  "4b9231b9f3527787d1bed1c5f318565f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgCartPosition>)))
  "Returns full string definition for message of type '<MsgCartPosition>"
  (cl:format cl:nil "Header header~%float32 X~%float32 Y~%float32 Z~%float32 A~%float32 B~%float32 C~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgCartPosition)))
  "Returns full string definition for message of type 'MsgCartPosition"
  (cl:format cl:nil "Header header~%float32 X~%float32 Y~%float32 Z~%float32 A~%float32 B~%float32 C~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgCartPosition>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgCartPosition>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgCartPosition
    (cl:cons ':header (header msg))
    (cl:cons ':X (X msg))
    (cl:cons ':Y (Y msg))
    (cl:cons ':Z (Z msg))
    (cl:cons ':A (A msg))
    (cl:cons ':B (B msg))
    (cl:cons ':C (C msg))
))
