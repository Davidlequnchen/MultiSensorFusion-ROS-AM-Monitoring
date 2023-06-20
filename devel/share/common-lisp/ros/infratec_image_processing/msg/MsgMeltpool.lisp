; Auto-generated. Do not edit!


(cl:in-package infratec_image_processing-msg)


;//! \htmlinclude MsgMeltpool.msg.html

(cl:defclass <MsgMeltpool> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (melt_pool_size
    :reader melt_pool_size
    :initarg :melt_pool_size
    :type cl:float
    :initform 0.0)
   (heat_affected_zone
    :reader heat_affected_zone
    :initarg :heat_affected_zone
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgMeltpool (<MsgMeltpool>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgMeltpool>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgMeltpool)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name infratec_image_processing-msg:<MsgMeltpool> is deprecated: use infratec_image_processing-msg:MsgMeltpool instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgMeltpool>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:header-val is deprecated.  Use infratec_image_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'melt_pool_size-val :lambda-list '(m))
(cl:defmethod melt_pool_size-val ((m <MsgMeltpool>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:melt_pool_size-val is deprecated.  Use infratec_image_processing-msg:melt_pool_size instead.")
  (melt_pool_size m))

(cl:ensure-generic-function 'heat_affected_zone-val :lambda-list '(m))
(cl:defmethod heat_affected_zone-val ((m <MsgMeltpool>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:heat_affected_zone-val is deprecated.  Use infratec_image_processing-msg:heat_affected_zone instead.")
  (heat_affected_zone m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgMeltpool>) ostream)
  "Serializes a message object of type '<MsgMeltpool>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'melt_pool_size))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'heat_affected_zone))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgMeltpool>) istream)
  "Deserializes a message object of type '<MsgMeltpool>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'melt_pool_size) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'heat_affected_zone) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgMeltpool>)))
  "Returns string type for a message object of type '<MsgMeltpool>"
  "infratec_image_processing/MsgMeltpool")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgMeltpool)))
  "Returns string type for a message object of type 'MsgMeltpool"
  "infratec_image_processing/MsgMeltpool")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgMeltpool>)))
  "Returns md5sum for a message object of type '<MsgMeltpool>"
  "53ff07d859c81343775714d56bbac875")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgMeltpool)))
  "Returns md5sum for a message object of type 'MsgMeltpool"
  "53ff07d859c81343775714d56bbac875")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgMeltpool>)))
  "Returns full string definition for message of type '<MsgMeltpool>"
  (cl:format cl:nil "Header header~%float32 melt_pool_size~%float32 heat_affected_zone~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgMeltpool)))
  "Returns full string definition for message of type 'MsgMeltpool"
  (cl:format cl:nil "Header header~%float32 melt_pool_size~%float32 heat_affected_zone~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgMeltpool>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgMeltpool>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgMeltpool
    (cl:cons ':header (header msg))
    (cl:cons ':melt_pool_size (melt_pool_size msg))
    (cl:cons ':heat_affected_zone (heat_affected_zone msg))
))
