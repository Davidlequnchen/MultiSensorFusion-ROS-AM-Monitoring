; Auto-generated. Do not edit!


(cl:in-package camera_control_msgs-srv)


;//! \htmlinclude SetIntegerValue-request.msg.html

(cl:defclass <SetIntegerValue-request> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:integer
    :initform 0))
)

(cl:defclass SetIntegerValue-request (<SetIntegerValue-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetIntegerValue-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetIntegerValue-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetIntegerValue-request> is deprecated: use camera_control_msgs-srv:SetIntegerValue-request instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <SetIntegerValue-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:value-val is deprecated.  Use camera_control_msgs-srv:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetIntegerValue-request>) ostream)
  "Serializes a message object of type '<SetIntegerValue-request>"
  (cl:let* ((signed (cl:slot-value msg 'value)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetIntegerValue-request>) istream)
  "Deserializes a message object of type '<SetIntegerValue-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetIntegerValue-request>)))
  "Returns string type for a service object of type '<SetIntegerValue-request>"
  "camera_control_msgs/SetIntegerValueRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetIntegerValue-request)))
  "Returns string type for a service object of type 'SetIntegerValue-request"
  "camera_control_msgs/SetIntegerValueRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetIntegerValue-request>)))
  "Returns md5sum for a message object of type '<SetIntegerValue-request>"
  "f17b32d87dddbe303f3f462e91a430a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetIntegerValue-request)))
  "Returns md5sum for a message object of type 'SetIntegerValue-request"
  "f17b32d87dddbe303f3f462e91a430a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetIntegerValue-request>)))
  "Returns full string definition for message of type '<SetIntegerValue-request>"
  (cl:format cl:nil "# Used by :~%# - set_black_level ROS service. (value = new targeted black level).~%# - set_acquisition_frame_count ROS service (value = new targeted frame count).~%# - set_offset_x ROS service (value = targeted offset in x-axis)~%# - set_offset_y ROS service (value = targeted offset in y-axis)~%# - set_demosaicing_mode ROS Service (value : 0 = Simple, 1 = Basler PGI)~%# - set_light_source_preset ROS service (value : 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K)~%# - set_balance_white_auto ROS service (value : 0 = Off, 1 = Once, 2 = Continuous)~%# - set_sensor_readout_mode ROS service (value : 0 = Normal, 1 = Fast)~%# - set_trigger_selector ROS service (value : 	0 = Frame start, 1 = Frame burst start (ace USB cameras) / Acquisition Start (ace GigE cameras))~%# - set_trigger_source ROS service (value : 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1 (only selected GigE Camera))~%# - set_trigger_activation ROS service (value : 0 = RigingEdge, 1 = FallingEdge)~%# - set_line_selector ROS service (value : 0 = Line1, 1 = Line2, 2 = Line3, 3 = Line4)~%# - set_line_mode ROS service (value : 0 = Input, 1 = Output)~%# - set_line_source ROS sevice (value : 0 = Exposure Active, 1 = FrameTriggerWait, 2 = UserOutput1, 3 = Timer1Active, 4 = FlashWindow)~%# - set_device_link_throughput_limit ROS service (value = new targeted throughput limit in Bytes/sec.).~%# - select_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)~%# - select_default_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)~%# - set_gamma_selector (value: 0 = User, 1 = sRGB)~%~%int32 value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetIntegerValue-request)))
  "Returns full string definition for message of type 'SetIntegerValue-request"
  (cl:format cl:nil "# Used by :~%# - set_black_level ROS service. (value = new targeted black level).~%# - set_acquisition_frame_count ROS service (value = new targeted frame count).~%# - set_offset_x ROS service (value = targeted offset in x-axis)~%# - set_offset_y ROS service (value = targeted offset in y-axis)~%# - set_demosaicing_mode ROS Service (value : 0 = Simple, 1 = Basler PGI)~%# - set_light_source_preset ROS service (value : 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K)~%# - set_balance_white_auto ROS service (value : 0 = Off, 1 = Once, 2 = Continuous)~%# - set_sensor_readout_mode ROS service (value : 0 = Normal, 1 = Fast)~%# - set_trigger_selector ROS service (value : 	0 = Frame start, 1 = Frame burst start (ace USB cameras) / Acquisition Start (ace GigE cameras))~%# - set_trigger_source ROS service (value : 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1 (only selected GigE Camera))~%# - set_trigger_activation ROS service (value : 0 = RigingEdge, 1 = FallingEdge)~%# - set_line_selector ROS service (value : 0 = Line1, 1 = Line2, 2 = Line3, 3 = Line4)~%# - set_line_mode ROS service (value : 0 = Input, 1 = Output)~%# - set_line_source ROS sevice (value : 0 = Exposure Active, 1 = FrameTriggerWait, 2 = UserOutput1, 3 = Timer1Active, 4 = FlashWindow)~%# - set_device_link_throughput_limit ROS service (value = new targeted throughput limit in Bytes/sec.).~%# - select_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)~%# - select_default_user_set ROS service (value : 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw)~%# - set_gamma_selector (value: 0 = User, 1 = sRGB)~%~%int32 value 		# value to be setted~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetIntegerValue-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetIntegerValue-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetIntegerValue-request
    (cl:cons ':value (value msg))
))
;//! \htmlinclude SetIntegerValue-response.msg.html

(cl:defclass <SetIntegerValue-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass SetIntegerValue-response (<SetIntegerValue-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetIntegerValue-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetIntegerValue-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-srv:<SetIntegerValue-response> is deprecated: use camera_control_msgs-srv:SetIntegerValue-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetIntegerValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:success-val is deprecated.  Use camera_control_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <SetIntegerValue-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-srv:message-val is deprecated.  Use camera_control_msgs-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetIntegerValue-response>) ostream)
  "Serializes a message object of type '<SetIntegerValue-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetIntegerValue-response>) istream)
  "Deserializes a message object of type '<SetIntegerValue-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetIntegerValue-response>)))
  "Returns string type for a service object of type '<SetIntegerValue-response>"
  "camera_control_msgs/SetIntegerValueResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetIntegerValue-response)))
  "Returns string type for a service object of type 'SetIntegerValue-response"
  "camera_control_msgs/SetIntegerValueResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetIntegerValue-response>)))
  "Returns md5sum for a message object of type '<SetIntegerValue-response>"
  "f17b32d87dddbe303f3f462e91a430a4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetIntegerValue-response)))
  "Returns md5sum for a message object of type 'SetIntegerValue-response"
  "f17b32d87dddbe303f3f462e91a430a4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetIntegerValue-response>)))
  "Returns full string definition for message of type '<SetIntegerValue-response>"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetIntegerValue-response)))
  "Returns full string definition for message of type 'SetIntegerValue-response"
  (cl:format cl:nil "bool success   # indicate successful run of triggered service~%string message # informational, e.g. for error messages~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetIntegerValue-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetIntegerValue-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetIntegerValue-response
    (cl:cons ':success (success msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetIntegerValue)))
  'SetIntegerValue-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetIntegerValue)))
  'SetIntegerValue-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetIntegerValue)))
  "Returns string type for a service object of type '<SetIntegerValue>"
  "camera_control_msgs/SetIntegerValue")