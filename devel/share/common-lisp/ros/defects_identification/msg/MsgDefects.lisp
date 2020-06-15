; Auto-generated. Do not edit!


(cl:in-package defects_identification-msg)


;//! \htmlinclude MsgDefects.msg.html

(cl:defclass <MsgDefects> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (defectsType
    :reader defectsType
    :initarg :defectsType
    :type cl:integer
    :initform 0))
)

(cl:defclass MsgDefects (<MsgDefects>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgDefects>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgDefects)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name defects_identification-msg:<MsgDefects> is deprecated: use defects_identification-msg:MsgDefects instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgDefects>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader defects_identification-msg:header-val is deprecated.  Use defects_identification-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'defectsType-val :lambda-list '(m))
(cl:defmethod defectsType-val ((m <MsgDefects>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader defects_identification-msg:defectsType-val is deprecated.  Use defects_identification-msg:defectsType instead.")
  (defectsType m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgDefects>) ostream)
  "Serializes a message object of type '<MsgDefects>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'defectsType)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgDefects>) istream)
  "Deserializes a message object of type '<MsgDefects>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'defectsType) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgDefects>)))
  "Returns string type for a message object of type '<MsgDefects>"
  "defects_identification/MsgDefects")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgDefects)))
  "Returns string type for a message object of type 'MsgDefects"
  "defects_identification/MsgDefects")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgDefects>)))
  "Returns md5sum for a message object of type '<MsgDefects>"
  "def1db136df73f888f606360f32da1ad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgDefects)))
  "Returns md5sum for a message object of type 'MsgDefects"
  "def1db136df73f888f606360f32da1ad")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgDefects>)))
  "Returns full string definition for message of type '<MsgDefects>"
  (cl:format cl:nil "Header header~%int32 defectsType  # 0, 1, 2, 3~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgDefects)))
  "Returns full string definition for message of type 'MsgDefects"
  (cl:format cl:nil "Header header~%int32 defectsType  # 0, 1, 2, 3~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgDefects>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgDefects>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgDefects
    (cl:cons ':header (header msg))
    (cl:cons ':defectsType (defectsType msg))
))
