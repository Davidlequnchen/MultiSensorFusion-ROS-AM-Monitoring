; Auto-generated. Do not edit!


(cl:in-package infratec_image_processing-msg)


;//! \htmlinclude MsgThreshold.msg.html

(cl:defclass <MsgThreshold> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (threshold
    :reader threshold
    :initarg :threshold
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgThreshold (<MsgThreshold>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgThreshold>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgThreshold)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name infratec_image_processing-msg:<MsgThreshold> is deprecated: use infratec_image_processing-msg:MsgThreshold instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgThreshold>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:header-val is deprecated.  Use infratec_image_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'threshold-val :lambda-list '(m))
(cl:defmethod threshold-val ((m <MsgThreshold>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:threshold-val is deprecated.  Use infratec_image_processing-msg:threshold instead.")
  (threshold m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgThreshold>) ostream)
  "Serializes a message object of type '<MsgThreshold>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'threshold))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgThreshold>) istream)
  "Deserializes a message object of type '<MsgThreshold>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'threshold) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgThreshold>)))
  "Returns string type for a message object of type '<MsgThreshold>"
  "infratec_image_processing/MsgThreshold")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgThreshold)))
  "Returns string type for a message object of type 'MsgThreshold"
  "infratec_image_processing/MsgThreshold")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgThreshold>)))
  "Returns md5sum for a message object of type '<MsgThreshold>"
  "3dc898e59e7081935abe13d2f48debb8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgThreshold)))
  "Returns md5sum for a message object of type 'MsgThreshold"
  "3dc898e59e7081935abe13d2f48debb8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgThreshold>)))
  "Returns full string definition for message of type '<MsgThreshold>"
  (cl:format cl:nil "Header header~%float32 threshold~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgThreshold)))
  "Returns full string definition for message of type 'MsgThreshold"
  (cl:format cl:nil "Header header~%float32 threshold~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgThreshold>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgThreshold>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgThreshold
    (cl:cons ':header (header msg))
    (cl:cons ':threshold (threshold msg))
))
