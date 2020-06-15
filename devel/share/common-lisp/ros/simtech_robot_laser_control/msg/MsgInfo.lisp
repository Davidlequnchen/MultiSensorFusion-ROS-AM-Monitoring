; Auto-generated. Do not edit!


(cl:in-package simtech_robot_laser_control-msg)


;//! \htmlinclude MsgInfo.msg.html

(cl:defclass <MsgInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (time
    :reader time
    :initarg :time
    :type cl:string
    :initform "")
   (track_number
    :reader track_number
    :initarg :track_number
    :type cl:integer
    :initform 0))
)

(cl:defclass MsgInfo (<MsgInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simtech_robot_laser_control-msg:<MsgInfo> is deprecated: use simtech_robot_laser_control-msg:MsgInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:header-val is deprecated.  Use simtech_robot_laser_control-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <MsgInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:time-val is deprecated.  Use simtech_robot_laser_control-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'track_number-val :lambda-list '(m))
(cl:defmethod track_number-val ((m <MsgInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simtech_robot_laser_control-msg:track_number-val is deprecated.  Use simtech_robot_laser_control-msg:track_number instead.")
  (track_number m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgInfo>) ostream)
  "Serializes a message object of type '<MsgInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'time))
  (cl:let* ((signed (cl:slot-value msg 'track_number)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgInfo>) istream)
  "Deserializes a message object of type '<MsgInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'time) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'track_number) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgInfo>)))
  "Returns string type for a message object of type '<MsgInfo>"
  "simtech_robot_laser_control/MsgInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgInfo)))
  "Returns string type for a message object of type 'MsgInfo"
  "simtech_robot_laser_control/MsgInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgInfo>)))
  "Returns md5sum for a message object of type '<MsgInfo>"
  "e43375f64afc0ea18fe6ceb84397eb65")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgInfo)))
  "Returns md5sum for a message object of type 'MsgInfo"
  "e43375f64afc0ea18fe6ceb84397eb65")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgInfo>)))
  "Returns full string definition for message of type '<MsgInfo>"
  (cl:format cl:nil "Header header~%string time~%int32 track_number~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgInfo)))
  "Returns full string definition for message of type 'MsgInfo"
  (cl:format cl:nil "Header header~%string time~%int32 track_number~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'time))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgInfo
    (cl:cons ':header (header msg))
    (cl:cons ':time (time msg))
    (cl:cons ':track_number (track_number msg))
))
