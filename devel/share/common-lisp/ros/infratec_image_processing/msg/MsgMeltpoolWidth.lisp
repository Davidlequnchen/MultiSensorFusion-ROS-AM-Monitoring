; Auto-generated. Do not edit!


(cl:in-package infratec_image_processing-msg)


;//! \htmlinclude MsgMeltpoolWidth.msg.html

(cl:defclass <MsgMeltpoolWidth> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (melt_pool_width
    :reader melt_pool_width
    :initarg :melt_pool_width
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgMeltpoolWidth (<MsgMeltpoolWidth>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgMeltpoolWidth>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgMeltpoolWidth)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name infratec_image_processing-msg:<MsgMeltpoolWidth> is deprecated: use infratec_image_processing-msg:MsgMeltpoolWidth instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgMeltpoolWidth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:header-val is deprecated.  Use infratec_image_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'melt_pool_width-val :lambda-list '(m))
(cl:defmethod melt_pool_width-val ((m <MsgMeltpoolWidth>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:melt_pool_width-val is deprecated.  Use infratec_image_processing-msg:melt_pool_width instead.")
  (melt_pool_width m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgMeltpoolWidth>) ostream)
  "Serializes a message object of type '<MsgMeltpoolWidth>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'melt_pool_width))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgMeltpoolWidth>) istream)
  "Deserializes a message object of type '<MsgMeltpoolWidth>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'melt_pool_width) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgMeltpoolWidth>)))
  "Returns string type for a message object of type '<MsgMeltpoolWidth>"
  "infratec_image_processing/MsgMeltpoolWidth")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgMeltpoolWidth)))
  "Returns string type for a message object of type 'MsgMeltpoolWidth"
  "infratec_image_processing/MsgMeltpoolWidth")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgMeltpoolWidth>)))
  "Returns md5sum for a message object of type '<MsgMeltpoolWidth>"
  "e7e9e312c51dbe288dc9af4b67dff15c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgMeltpoolWidth)))
  "Returns md5sum for a message object of type 'MsgMeltpoolWidth"
  "e7e9e312c51dbe288dc9af4b67dff15c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgMeltpoolWidth>)))
  "Returns full string definition for message of type '<MsgMeltpoolWidth>"
  (cl:format cl:nil "Header header~%float32 melt_pool_width #pixels~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgMeltpoolWidth)))
  "Returns full string definition for message of type 'MsgMeltpoolWidth"
  (cl:format cl:nil "Header header~%float32 melt_pool_width #pixels~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgMeltpoolWidth>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgMeltpoolWidth>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgMeltpoolWidth
    (cl:cons ':header (header msg))
    (cl:cons ':melt_pool_width (melt_pool_width msg))
))
