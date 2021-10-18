; Auto-generated. Do not edit!


(cl:in-package camera_control_msgs-srv)


;//! \htmlinclude SetStringValue-request.msg.html

(cl:defclass <SetStringValue-request> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:string
    :initform ""))
)

(cl:defclass SetStringValue-request (<SetStringValue-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetStringValue-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetStringValue-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetStringValue-request> is deprecated: use camera_control_msgs-srv:SetStringValue-request instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SetStringValue-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:value-val is deprecated.  Use camera_control_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetStringValue-request>) ostream)
  "Serializes a message object of type '<SetStringValue-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'value))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetStringValue-request>) istream)
  "Deserializes a message object of type '<SetStringValue-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'value) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetStringValue-request>)))
  "Returns string type for a service object of type '<SetStringValue-request>"
  "camera_control_msgs/SetStringValueRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetStringValue-request)))
  "Returns string type for a service object of type 'SetStringValue-request"
  "camera_control_msgs/SetStringValueRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetStringValue-request>)))
  "Returns md5sum for a message object of type '<SetStringValue-request>"
  "43ad6a9b380ac342e4b20e501a2fd46c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetStringValue-request)))
  "Returns md5sum for a message object of type 'SetStringValue-request"
  "43ad6a9b380ac342e4b20e501a2fd46c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetStringValue-request>)))
  "Returns full string definition for message of type '<SetStringValue-request>"
  (cl:format cl:nil "# Used by :~%# - set_Image_Encoding ROS service. (value = mono8, mono16, bgr8, rgb8, bayer_bggr8, bayer_gbrg8, bayer_rggb8, bayer_grbg8, bayer_rggb16, bayer_bggr16, bayer_gbrg16, bayer_grbg16).~%~%string value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetStringValue-request)))
  "Returns full string definition for message of type 'SetStringValue-request"
  (cl:format cl:nil "# Used by :~%# - set_Image_Encoding ROS service. (value = mono8, mono16, bgr8, rgb8, bayer_bggr8, bayer_gbrg8, bayer_rggb8, bayer_grbg8, bayer_rggb16, bayer_bggr16, bayer_gbrg16, bayer_grbg16).~%~%string value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetStringValue-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'value))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetStringValue-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetStringValue-request
    (cl:cons ':value (value msg))
))
;//! \htmlinclude SetStringValue-response.msg.html

(cl:defclass <SetStringValue-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass SetStringValue-response (<SetStringValue-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetStringValue-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetStringValue-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetStringValue-response> is deprecated: use camera_control_msgs-srv:SetStringValue-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetStringValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:success-val is deprecated.  Use camera_control_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SetStringValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:message-val is deprecated.  Use camera_control_msgs-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetStringValue-response>) ostream)
  "Serializes a message object of type '<SetStringValue-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetStringValue-response>) istream)
  "Deserializes a message object of type '<SetStringValue-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetStringValue-response>)))
  "Returns string type for a service object of type '<SetStringValue-response>"
  "camera_control_msgs/SetStringValueResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetStringValue-response)))
  "Returns string type for a service object of type 'SetStringValue-response"
  "camera_control_msgs/SetStringValueResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetStringValue-response>)))
  "Returns md5sum for a message object of type '<SetStringValue-response>"
  "43ad6a9b380ac342e4b20e501a2fd46c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetStringValue-response)))
  "Returns md5sum for a message object of type 'SetStringValue-response"
  "43ad6a9b380ac342e4b20e501a2fd46c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetStringValue-response>)))
  "Returns full string definition for message of type '<SetStringValue-response>"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetStringValue-response)))
  "Returns full string definition for message of type 'SetStringValue-response"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetStringValue-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetStringValue-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetStringValue-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetStringValue)))
  'SetStringValue-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetStringValue)))
  'SetStringValue-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetStringValue)))
  "Returns string type for a service object of type '<SetStringValue>"
  "camera_control_msgs/SetStringValue")