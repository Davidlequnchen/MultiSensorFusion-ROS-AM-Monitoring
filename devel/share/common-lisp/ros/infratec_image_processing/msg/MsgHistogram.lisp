; Auto-generated. Do not edit!


(cl:in-package infratec_image_processing-msg)


;//! \htmlinclude MsgHistogram.msg.html

(cl:defclass <MsgHistogram> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (histogram
    :reader histogram
    :initarg :histogram
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass MsgHistogram (<MsgHistogram>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgHistogram>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgHistogram)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name infratec_image_processing-msg:<MsgHistogram> is deprecated: use infratec_image_processing-msg:MsgHistogram instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgHistogram>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:header-val is deprecated.  Use infratec_image_processing-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'histogram-val :lambda-list '(m))
(cl:defmethod histogram-val ((m <MsgHistogram>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader infratec_image_processing-msg:histogram-val is deprecated.  Use infratec_image_processing-msg:histogram instead.")
  (histogram m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgHistogram>) ostream)
  "Serializes a message object of type '<MsgHistogram>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'histogram))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'histogram))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgHistogram>) istream)
  "Deserializes a message object of type '<MsgHistogram>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'histogram) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'histogram)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgHistogram>)))
  "Returns string type for a message object of type '<MsgHistogram>"
  "infratec_image_processing/MsgHistogram")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgHistogram)))
  "Returns string type for a message object of type 'MsgHistogram"
  "infratec_image_processing/MsgHistogram")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgHistogram>)))
  "Returns md5sum for a message object of type '<MsgHistogram>"
  "8b804f15fac99f33a0d9c6309bbd6803")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgHistogram)))
  "Returns md5sum for a message object of type 'MsgHistogram"
  "8b804f15fac99f33a0d9c6309bbd6803")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgHistogram>)))
  "Returns full string definition for message of type '<MsgHistogram>"
  (cl:format cl:nil "Header header~%uint32[] histogram~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgHistogram)))
  "Returns full string definition for message of type 'MsgHistogram"
  (cl:format cl:nil "Header header~%uint32[] histogram~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgHistogram>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'histogram) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgHistogram>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgHistogram
    (cl:cons ':header (header msg))
    (cl:cons ':histogram (histogram msg))
))
