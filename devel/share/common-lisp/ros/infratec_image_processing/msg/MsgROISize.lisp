; Auto-generated. Do not edit!


(cl:in-package infratec_image_processing-msg)


;//! \htmlinclude MsgROISize.msg.html

(cl:defclass <MsgROISize> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (pixels
    :reader pixels
    :initarg :pixels
    :type cl:integer
    :initform 0))
)

(cl:defclass MsgROISize (<MsgROISize>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgROISize>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgROISize)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name infratec_image_processing-msg:<MsgROISize> is deprecated: use infratec_image_processing-msg:MsgROISize instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgROISize>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:header-val is deprecated.  Use infratec_image_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'pixels-val :lambda-list '(m))
(cl:defmethod pixels-val ((m <MsgROISize>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:pixels-val is deprecated.  Use infratec_image_processing-msg:pixels instead.")
  (pixels m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgROISize>) ostream)
  "Serializes a message object of type '<MsgROISize>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'pixels)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgROISize>) istream)
  "Deserializes a message object of type '<MsgROISize>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pixels) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgROISize>)))
  "Returns string type for a message object of type '<MsgROISize>"
  "infratec_image_processing/MsgROISize")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgROISize)))
  "Returns string type for a message object of type 'MsgROISize"
  "infratec_image_processing/MsgROISize")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgROISize>)))
  "Returns md5sum for a message object of type '<MsgROISize>"
  "77890d32d59f41937276b08815f00d0a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgROISize)))
  "Returns md5sum for a message object of type 'MsgROISize"
  "77890d32d59f41937276b08815f00d0a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgROISize>)))
  "Returns full string definition for message of type '<MsgROISize>"
  (cl:format cl:nil "Header header~%int32 pixels~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgROISize)))
  "Returns full string definition for message of type 'MsgROISize"
  (cl:format cl:nil "Header header~%int32 pixels~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgROISize>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgROISize>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgROISize
    (cl:cons ':header (header msg))
    (cl:cons ':pixels (pixels msg))
))
