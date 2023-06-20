; Auto-generated. Do not edit!


(cl:in-package pcl_msgs-msg)


;//! \htmlinclude ModelCoefficients.msg.html

(cl:defclass <ModelCoefficients> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (values
    :reader values
    :initarg :values
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass ModelCoefficients (<ModelCoefficients>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ModelCoefficients>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ModelCoefficients)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pcl_msgs-msg:<ModelCoefficients> is deprecated: use pcl_msgs-msg:ModelCoefficients instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ModelCoefficients>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-msg:header-val is deprecated.  Use pcl_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'values-val :lambda-list '(m))
(cl:defmethod values-val ((m <ModelCoefficients>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-msg:values-val is deprecated.  Use pcl_msgs-msg:values instead.")
  (values m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ModelCoefficients>) ostream)
  "Serializes a message object of type '<ModelCoefficients>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'values))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'values))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ModelCoefficients>) istream)
  "Deserializes a message object of type '<ModelCoefficients>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'values) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'values)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ModelCoefficients>)))
  "Returns string type for a message object of type '<ModelCoefficients>"
  "pcl_msgs/ModelCoefficients")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ModelCoefficients)))
  "Returns string type for a message object of type 'ModelCoefficients"
  "pcl_msgs/ModelCoefficients")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ModelCoefficients>)))
  "Returns md5sum for a message object of type '<ModelCoefficients>"
  "ca27dea75e72cb894cd36f9e5005e93e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ModelCoefficients)))
  "Returns md5sum for a message object of type 'ModelCoefficients"
  "ca27dea75e72cb894cd36f9e5005e93e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ModelCoefficients>)))
  "Returns full string definition for message of type '<ModelCoefficients>"
  (cl:format cl:nil "Header header~%float32[] values~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ModelCoefficients)))
  "Returns full string definition for message of type 'ModelCoefficients"
  (cl:format cl:nil "Header header~%float32[] values~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ModelCoefficients>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'values) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ModelCoefficients>))
  "Converts a ROS message object to a list"
  (cl:list 'ModelCoefficients
    (cl:cons ':header (header msg))
    (cl:cons ':values (values msg))
))
