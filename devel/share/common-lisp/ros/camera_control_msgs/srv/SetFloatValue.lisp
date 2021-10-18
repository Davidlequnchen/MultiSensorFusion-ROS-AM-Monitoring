; Auto-generated. Do not edit!


(cl:in-package camera_control_msgs-srv)


;//! \htmlinclude SetFloatValue-request.msg.html

(cl:defclass <SetFloatValue-request> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0))
)

(cl:defclass SetFloatValue-request (<SetFloatValue-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetFloatValue-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetFloatValue-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetFloatValue-request> is deprecated: use camera_control_msgs-srv:SetFloatValue-request instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SetFloatValue-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:value-val is deprecated.  Use camera_control_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetFloatValue-request>) ostream)
  "Serializes a message object of type '<SetFloatValue-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetFloatValue-request>) istream)
  "Deserializes a message object of type '<SetFloatValue-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetFloatValue-request>)))
  "Returns string type for a service object of type '<SetFloatValue-request>"
  "camera_control_msgs/SetFloatValueRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetFloatValue-request)))
  "Returns string type for a service object of type 'SetFloatValue-request"
  "camera_control_msgs/SetFloatValueRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetFloatValue-request>)))
  "Returns md5sum for a message object of type '<SetFloatValue-request>"
  "345a3274594e7cc629d8cd38d3b1fe73")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetFloatValue-request)))
  "Returns md5sum for a message object of type 'SetFloatValue-request"
  "345a3274594e7cc629d8cd38d3b1fe73")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetFloatValue-request>)))
  "Returns full string definition for message of type '<SetFloatValue-request>"
  (cl:format cl:nil "# Used by :~%# - set_trigger_delay ROS service. (value = delay in micro sec.).~%# - set_line_debouncer_time ROS service. (value = delay in micro sec.).~%# - set_noise_reduction ROS service. (value = reduction value). ~%# - set_sharpness_enhancement ROS service (value = sharpness value). ~%~%float32 value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetFloatValue-request)))
  "Returns full string definition for message of type 'SetFloatValue-request"
  (cl:format cl:nil "# Used by :~%# - set_trigger_delay ROS service. (value = delay in micro sec.).~%# - set_line_debouncer_time ROS service. (value = delay in micro sec.).~%# - set_noise_reduction ROS service. (value = reduction value). ~%# - set_sharpness_enhancement ROS service (value = sharpness value). ~%~%float32 value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetFloatValue-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetFloatValue-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetFloatValue-request
    (cl:cons ':value (value msg))
))
;//! \htmlinclude SetFloatValue-response.msg.html

(cl:defclass <SetFloatValue-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass SetFloatValue-response (<SetFloatValue-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetFloatValue-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetFloatValue-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetFloatValue-response> is deprecated: use camera_control_msgs-srv:SetFloatValue-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetFloatValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:success-val is deprecated.  Use camera_control_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SetFloatValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:message-val is deprecated.  Use camera_control_msgs-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetFloatValue-response>) ostream)
  "Serializes a message object of type '<SetFloatValue-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetFloatValue-response>) istream)
  "Deserializes a message object of type '<SetFloatValue-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetFloatValue-response>)))
  "Returns string type for a service object of type '<SetFloatValue-response>"
  "camera_control_msgs/SetFloatValueResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetFloatValue-response)))
  "Returns string type for a service object of type 'SetFloatValue-response"
  "camera_control_msgs/SetFloatValueResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetFloatValue-response>)))
  "Returns md5sum for a message object of type '<SetFloatValue-response>"
  "345a3274594e7cc629d8cd38d3b1fe73")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetFloatValue-response)))
  "Returns md5sum for a message object of type 'SetFloatValue-response"
  "345a3274594e7cc629d8cd38d3b1fe73")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetFloatValue-response>)))
  "Returns full string definition for message of type '<SetFloatValue-response>"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetFloatValue-response)))
  "Returns full string definition for message of type 'SetFloatValue-response"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetFloatValue-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetFloatValue-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetFloatValue-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetFloatValue)))
  'SetFloatValue-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetFloatValue)))
  'SetFloatValue-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetFloatValue)))
  "Returns string type for a service object of type '<SetFloatValue>"
  "camera_control_msgs/SetFloatValue")