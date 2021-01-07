; Auto-generated. Do not edit!


(cl:in-package pcl_msgs-msg)


;//! \htmlinclude PointIndices.msg.html

(cl:defclass <PointIndices> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (indices
    :reader indices
    :initarg :indices
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass PointIndices (<PointIndices>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PointIndices>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PointIndices)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pcl_msgs-msg:<PointIndices> is deprecated: use pcl_msgs-msg:PointIndices instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PointIndices>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-msg:header-val is deprecated.  Use pcl_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'indices-val :lambda-list '(m))
(cl:defmethod indices-val ((m <PointIndices>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-msg:indices-val is deprecated.  Use pcl_msgs-msg:indices instead.")
  (indices m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PointIndices>) ostream)
  "Serializes a message object of type '<PointIndices>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'indices))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    ))
   (cl:slot-value msg 'indices))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PointIndices>) istream)
  "Deserializes a message object of type '<PointIndices>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'indices) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'indices)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PointIndices>)))
  "Returns string type for a message object of type '<PointIndices>"
  "pcl_msgs/PointIndices")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PointIndices)))
  "Returns string type for a message object of type 'PointIndices"
  "pcl_msgs/PointIndices")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PointIndices>)))
  "Returns md5sum for a message object of type '<PointIndices>"
  "458c7998b7eaf99908256472e273b3d4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PointIndices)))
  "Returns md5sum for a message object of type 'PointIndices"
  "458c7998b7eaf99908256472e273b3d4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PointIndices>)))
  "Returns full string definition for message of type '<PointIndices>"
  (cl:format cl:nil "Header header~%int32[] indices~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PointIndices)))
  "Returns full string definition for message of type 'PointIndices"
  (cl:format cl:nil "Header header~%int32[] indices~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PointIndices>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'indices) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PointIndices>))
  "Converts a ROS message object to a list"
  (cl:list 'PointIndices
    (cl:cons ':header (header msg))
    (cl:cons ':indices (indices msg))
))
