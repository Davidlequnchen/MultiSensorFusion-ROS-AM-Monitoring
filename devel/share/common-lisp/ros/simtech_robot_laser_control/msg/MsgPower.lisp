; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgPower.msg.html

(cl:defclass <MsgPower> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgPower (<MsgPower>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgPower>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgPower)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgPower> is deprecated: use simtech_robot_laser_control-msg:MsgPower instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:header-val is deprecated.  Use simtech_robot_laser_control-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <MsgPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:value-val is deprecated.  Use simtech_robot_laser_control-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgPower>) ostream)
  "Serializes a message object of type '<MsgPower>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgPower>) istream)
  "Deserializes a message object of type '<MsgPower>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgPower>)))
  "Returns string type for a message object of type '<MsgPower>"
  "simtech_robot_laser_control/MsgPower")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgPower)))
  "Returns string type for a message object of type 'MsgPower"
  "simtech_robot_laser_control/MsgPower")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgPower>)))
  "Returns md5sum for a message object of type '<MsgPower>"
  "4bea522f9243fd34ea7bc74ce85697a8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgPower)))
  "Returns md5sum for a message object of type 'MsgPower"
  "4bea522f9243fd34ea7bc74ce85697a8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgPower>)))
  "Returns full string definition for message of type '<MsgPower>"
  (cl:format cl:nil "# the power to be published and send to laser socket~%Header header~%float32 value~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgPower)))
  "Returns full string definition for message of type 'MsgPower"
  (cl:format cl:nil "# the power to be published and send to laser socket~%Header header~%float32 value~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgPower>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgPower>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgPower
    (cl:cons ':header (header msg))
    (cl:cons ':value (value msg))
))
