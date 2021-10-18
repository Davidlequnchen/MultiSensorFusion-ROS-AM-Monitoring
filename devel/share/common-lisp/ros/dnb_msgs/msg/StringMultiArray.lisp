; Auto-generated. Do not edit!


(cl:in-package dnb_msgs-msg)


;//! \htmlinclude StringMultiArray.msg.html

(cl:defclass <StringMultiArray> (roslisp-msg-protocol:ros-message)
  ((layout
    :reader layout
    :initarg :layout
    :type std_msgs-msg:MultiArrayLayout
    :initform (cl:make-instance 'std_msgs-msg:MultiArrayLayout))
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass StringMultiArray (<StringMultiArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <StringMultiArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'StringMultiArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dnb_msgs-msg:<StringMultiArray> is deprecated: use dnb_msgs-msg:StringMultiArray instead.")))

(cl:ensure-generic-function 'layout-val :lambda-list '(m))
(cl:defmethod layout-val ((m <StringMultiArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dnb_msgs-msg:layout-val is deprecated.  Use dnb_msgs-msg:layout instead.")
  (layout m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <StringMultiArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dnb_msgs-msg:data-val is deprecated.  Use dnb_msgs-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <StringMultiArray>) ostream)
  "Serializes a message object of type '<StringMultiArray>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'layout) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <StringMultiArray>) istream)
  "Deserializes a message object of type '<StringMultiArray>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'layout) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<StringMultiArray>)))
  "Returns string type for a message object of type '<StringMultiArray>"
  "dnb_msgs/StringMultiArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'StringMultiArray)))
  "Returns string type for a message object of type 'StringMultiArray"
  "dnb_msgs/StringMultiArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<StringMultiArray>)))
  "Returns md5sum for a message object of type '<StringMultiArray>"
  "77f374096c7ec9d15c35d6d0e5287e6b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'StringMultiArray)))
  "Returns md5sum for a message object of type 'StringMultiArray"
  "77f374096c7ec9d15c35d6d0e5287e6b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<StringMultiArray>)))
  "Returns full string definition for message of type '<StringMultiArray>"
  (cl:format cl:nil "std_msgs/MultiArrayLayout layout~%string[] data~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'StringMultiArray)))
  "Returns full string definition for message of type 'StringMultiArray"
  (cl:format cl:nil "std_msgs/MultiArrayLayout layout~%string[] data~%================================================================================~%MSG: std_msgs/MultiArrayLayout~%# The multiarray declares a generic multi-dimensional array of a~%# particular data type.  Dimensions are ordered from outer most~%# to inner most.~%~%MultiArrayDimension[] dim # Array of dimension properties~%uint32 data_offset        # padding elements at front of data~%~%# Accessors should ALWAYS be written in terms of dimension stride~%# and specified outer-most dimension first.~%# ~%# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]~%#~%# A standard, 3-channel 640x480 image with interleaved color channels~%# would be specified as:~%#~%# dim[0].label  = \"height\"~%# dim[0].size   = 480~%# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)~%# dim[1].label  = \"width\"~%# dim[1].size   = 640~%# dim[1].stride = 3*640 = 1920~%# dim[2].label  = \"channel\"~%# dim[2].size   = 3~%# dim[2].stride = 3~%#~%# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.~%~%================================================================================~%MSG: std_msgs/MultiArrayDimension~%string label   # label of given dimension~%uint32 size    # size of given dimension (in type units)~%uint32 stride  # stride of given dimension~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <StringMultiArray>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'layout))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <StringMultiArray>))
  "Converts a ROS message object to a list"
  (cl:list 'StringMultiArray
    (cl:cons ':layout (layout msg))
    (cl:cons ':data (data msg))
))
