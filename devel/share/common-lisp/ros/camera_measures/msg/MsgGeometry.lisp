; Auto-generated. Do not edit!


(cl:in-package camera_measures-msg)


;//! \htmlinclude MsgGeometry.msg.html

(cl:defclass <MsgGeometry> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (major_axis
    :reader major_axis
    :initarg :major_axis
    :type cl:float
    :initform 0.0)
   (minor_axis
    :reader minor_axis
    :initarg :minor_axis
    :type cl:float
    :initform 0.0)
   (orientation
    :reader orientation
    :initarg :orientation
    :type cl:float
    :initform 0.0)
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgGeometry (<MsgGeometry>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgGeometry>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgGeometry)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_measures-msg:<MsgGeometry> is deprecated: use camera_measures-msg:MsgGeometry instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:header-val is deprecated.  Use camera_measures-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'major_axis-val :lambda-list '(m))
(cl:defmethod major_axis-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:major_axis-val is deprecated.  Use camera_measures-msg:major_axis instead.")
  (major_axis m))

(cl:ensure-generic-function 'minor_axis-val :lambda-list '(m))
(cl:defmethod minor_axis-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:minor_axis-val is deprecated.  Use camera_measures-msg:minor_axis instead.")
  (minor_axis m))

(cl:ensure-generic-function 'orientation-val :lambda-list '(m))
(cl:defmethod orientation-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:orientation-val is deprecated.  Use camera_measures-msg:orientation instead.")
  (orientation m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:x-val is deprecated.  Use camera_measures-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <MsgGeometry>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_measures-msg:y-val is deprecated.  Use camera_measures-msg:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgGeometry>) ostream)
  "Serializes a message object of type '<MsgGeometry>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'major_axis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'minor_axis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'orientation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgGeometry>) istream)
  "Deserializes a message object of type '<MsgGeometry>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'major_axis) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'minor_axis) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'orientation) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgGeometry>)))
  "Returns string type for a message object of type '<MsgGeometry>"
  "camera_measures/MsgGeometry")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgGeometry)))
  "Returns string type for a message object of type 'MsgGeometry"
  "camera_measures/MsgGeometry")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgGeometry>)))
  "Returns md5sum for a message object of type '<MsgGeometry>"
  "53b067171589c1f92c32f242adc15c57")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgGeometry)))
  "Returns md5sum for a message object of type 'MsgGeometry"
  "53b067171589c1f92c32f242adc15c57")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgGeometry>)))
  "Returns full string definition for message of type '<MsgGeometry>"
  (cl:format cl:nil "Header header~%float32 major_axis~%float32 minor_axis~%float32 orientation~%float32 x~%float32 y~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgGeometry)))
  "Returns full string definition for message of type 'MsgGeometry"
  (cl:format cl:nil "Header header~%float32 major_axis~%float32 minor_axis~%float32 orientation~%float32 x~%float32 y~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgGeometry>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgGeometry>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgGeometry
    (cl:cons ':header (header msg))
    (cl:cons ':major_axis (major_axis msg))
    (cl:cons ':minor_axis (minor_axis msg))
    (cl:cons ':orientation (orientation msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
