; Auto-generated. Do not edit!


(cl:in-package camera_control_msgs-msg)


;//! \htmlinclude currentParams.msg.html

(cl:defclass <currentParams> (roslisp-msg-protocol:ros-message)
  ((offset_x
    :reader offset_x
    :initarg :offset_x
    :type cl:integer
    :initform 0)
   (offset_y
    :reader offset_y
    :initarg :offset_y
    :type cl:integer
    :initform 0)
   (reverse_x
    :reader reverse_x
    :initarg :reverse_x
    :type cl:boolean
    :initform cl:nil)
   (reverse_y
    :reader reverse_y
    :initarg :reverse_y
    :type cl:boolean
    :initform cl:nil)
   (black_level
    :reader black_level
    :initarg :black_level
    :type cl:integer
    :initform 0)
   (pgi_mode
    :reader pgi_mode
    :initarg :pgi_mode
    :type cl:integer
    :initform 0)
   (demosaicing_mode
    :reader demosaicing_mode
    :initarg :demosaicing_mode
    :type cl:integer
    :initform 0)
   (noise_reduction
    :reader noise_reduction
    :initarg :noise_reduction
    :type cl:float
    :initform 0.0)
   (sharpness_enhancement
    :reader sharpness_enhancement
    :initarg :sharpness_enhancement
    :type cl:float
    :initform 0.0)
   (light_source_preset
    :reader light_source_preset
    :initarg :light_source_preset
    :type cl:integer
    :initform 0)
   (balance_white_auto
    :reader balance_white_auto
    :initarg :balance_white_auto
    :type cl:integer
    :initform 0)
   (sensor_readout_mode
    :reader sensor_readout_mode
    :initarg :sensor_readout_mode
    :type cl:integer
    :initform 0)
   (acquisition_frame_count
    :reader acquisition_frame_count
    :initarg :acquisition_frame_count
    :type cl:integer
    :initform 0)
   (trigger_selector
    :reader trigger_selector
    :initarg :trigger_selector
    :type cl:integer
    :initform 0)
   (trigger_mode
    :reader trigger_mode
    :initarg :trigger_mode
    :type cl:integer
    :initform 0)
   (trigger_source
    :reader trigger_source
    :initarg :trigger_source
    :type cl:integer
    :initform 0)
   (trigger_activation
    :reader trigger_activation
    :initarg :trigger_activation
    :type cl:integer
    :initform 0)
   (trigger_delay
    :reader trigger_delay
    :initarg :trigger_delay
    :type cl:float
    :initform 0.0)
   (user_set_selector
    :reader user_set_selector
    :initarg :user_set_selector
    :type cl:integer
    :initform 0)
   (user_set_default_selector
    :reader user_set_default_selector
    :initarg :user_set_default_selector
    :type cl:integer
    :initform 0)
   (is_sleeping
    :reader is_sleeping
    :initarg :is_sleeping
    :type cl:boolean
    :initform cl:nil)
   (brightness
    :reader brightness
    :initarg :brightness
    :type cl:float
    :initform 0.0)
   (exposure
    :reader exposure
    :initarg :exposure
    :type cl:float
    :initform 0.0)
   (gain
    :reader gain
    :initarg :gain
    :type cl:float
    :initform 0.0)
   (gamma
    :reader gamma
    :initarg :gamma
    :type cl:float
    :initform 0.0)
   (binning_x
    :reader binning_x
    :initarg :binning_x
    :type cl:integer
    :initform 0)
   (binning_y
    :reader binning_y
    :initarg :binning_y
    :type cl:integer
    :initform 0)
   (roi
    :reader roi
    :initarg :roi
    :type sensor_msgs-msg:RegionOfInterest
    :initform (cl:make-instance 'sensor_msgs-msg:RegionOfInterest))
   (available_image_encoding
    :reader available_image_encoding
    :initarg :available_image_encoding
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (current_image_encoding
    :reader current_image_encoding
    :initarg :current_image_encoding
    :type cl:string
    :initform "")
   (current_image_ros_encoding
    :reader current_image_ros_encoding
    :initarg :current_image_ros_encoding
    :type cl:string
    :initform "")
   (sucess
    :reader sucess
    :initarg :sucess
    :type cl:boolean
    :initform cl:nil)
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass currentParams (<currentParams>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <currentParams>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'currentParams)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name camera_control_msgs-msg:<currentParams> is deprecated: use camera_control_msgs-msg:currentParams instead.")))

(cl:ensure-generic-function 'offset_x-val :lambda-list '(m))
(cl:defmethod offset_x-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:offset_x-val is deprecated.  Use camera_control_msgs-msg:offset_x instead.")
  (offset_x m))

(cl:ensure-generic-function 'offset_y-val :lambda-list '(m))
(cl:defmethod offset_y-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:offset_y-val is deprecated.  Use camera_control_msgs-msg:offset_y instead.")
  (offset_y m))

(cl:ensure-generic-function 'reverse_x-val :lambda-list '(m))
(cl:defmethod reverse_x-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:reverse_x-val is deprecated.  Use camera_control_msgs-msg:reverse_x instead.")
  (reverse_x m))

(cl:ensure-generic-function 'reverse_y-val :lambda-list '(m))
(cl:defmethod reverse_y-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:reverse_y-val is deprecated.  Use camera_control_msgs-msg:reverse_y instead.")
  (reverse_y m))

(cl:ensure-generic-function 'black_level-val :lambda-list '(m))
(cl:defmethod black_level-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:black_level-val is deprecated.  Use camera_control_msgs-msg:black_level instead.")
  (black_level m))

(cl:ensure-generic-function 'pgi_mode-val :lambda-list '(m))
(cl:defmethod pgi_mode-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:pgi_mode-val is deprecated.  Use camera_control_msgs-msg:pgi_mode instead.")
  (pgi_mode m))

(cl:ensure-generic-function 'demosaicing_mode-val :lambda-list '(m))
(cl:defmethod demosaicing_mode-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:demosaicing_mode-val is deprecated.  Use camera_control_msgs-msg:demosaicing_mode instead.")
  (demosaicing_mode m))

(cl:ensure-generic-function 'noise_reduction-val :lambda-list '(m))
(cl:defmethod noise_reduction-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:noise_reduction-val is deprecated.  Use camera_control_msgs-msg:noise_reduction instead.")
  (noise_reduction m))

(cl:ensure-generic-function 'sharpness_enhancement-val :lambda-list '(m))
(cl:defmethod sharpness_enhancement-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:sharpness_enhancement-val is deprecated.  Use camera_control_msgs-msg:sharpness_enhancement instead.")
  (sharpness_enhancement m))

(cl:ensure-generic-function 'light_source_preset-val :lambda-list '(m))
(cl:defmethod light_source_preset-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:light_source_preset-val is deprecated.  Use camera_control_msgs-msg:light_source_preset instead.")
  (light_source_preset m))

(cl:ensure-generic-function 'balance_white_auto-val :lambda-list '(m))
(cl:defmethod balance_white_auto-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:balance_white_auto-val is deprecated.  Use camera_control_msgs-msg:balance_white_auto instead.")
  (balance_white_auto m))

(cl:ensure-generic-function 'sensor_readout_mode-val :lambda-list '(m))
(cl:defmethod sensor_readout_mode-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:sensor_readout_mode-val is deprecated.  Use camera_control_msgs-msg:sensor_readout_mode instead.")
  (sensor_readout_mode m))

(cl:ensure-generic-function 'acquisition_frame_count-val :lambda-list '(m))
(cl:defmethod acquisition_frame_count-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:acquisition_frame_count-val is deprecated.  Use camera_control_msgs-msg:acquisition_frame_count instead.")
  (acquisition_frame_count m))

(cl:ensure-generic-function 'trigger_selector-val :lambda-list '(m))
(cl:defmethod trigger_selector-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:trigger_selector-val is deprecated.  Use camera_control_msgs-msg:trigger_selector instead.")
  (trigger_selector m))

(cl:ensure-generic-function 'trigger_mode-val :lambda-list '(m))
(cl:defmethod trigger_mode-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:trigger_mode-val is deprecated.  Use camera_control_msgs-msg:trigger_mode instead.")
  (trigger_mode m))

(cl:ensure-generic-function 'trigger_source-val :lambda-list '(m))
(cl:defmethod trigger_source-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:trigger_source-val is deprecated.  Use camera_control_msgs-msg:trigger_source instead.")
  (trigger_source m))

(cl:ensure-generic-function 'trigger_activation-val :lambda-list '(m))
(cl:defmethod trigger_activation-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:trigger_activation-val is deprecated.  Use camera_control_msgs-msg:trigger_activation instead.")
  (trigger_activation m))

(cl:ensure-generic-function 'trigger_delay-val :lambda-list '(m))
(cl:defmethod trigger_delay-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:trigger_delay-val is deprecated.  Use camera_control_msgs-msg:trigger_delay instead.")
  (trigger_delay m))

(cl:ensure-generic-function 'user_set_selector-val :lambda-list '(m))
(cl:defmethod user_set_selector-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:user_set_selector-val is deprecated.  Use camera_control_msgs-msg:user_set_selector instead.")
  (user_set_selector m))

(cl:ensure-generic-function 'user_set_default_selector-val :lambda-list '(m))
(cl:defmethod user_set_default_selector-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:user_set_default_selector-val is deprecated.  Use camera_control_msgs-msg:user_set_default_selector instead.")
  (user_set_default_selector m))

(cl:ensure-generic-function 'is_sleeping-val :lambda-list '(m))
(cl:defmethod is_sleeping-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:is_sleeping-val is deprecated.  Use camera_control_msgs-msg:is_sleeping instead.")
  (is_sleeping m))

(cl:ensure-generic-function 'brightness-val :lambda-list '(m))
(cl:defmethod brightness-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:brightness-val is deprecated.  Use camera_control_msgs-msg:brightness instead.")
  (brightness m))

(cl:ensure-generic-function 'exposure-val :lambda-list '(m))
(cl:defmethod exposure-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:exposure-val is deprecated.  Use camera_control_msgs-msg:exposure instead.")
  (exposure m))

(cl:ensure-generic-function 'gain-val :lambda-list '(m))
(cl:defmethod gain-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:gain-val is deprecated.  Use camera_control_msgs-msg:gain instead.")
  (gain m))

(cl:ensure-generic-function 'gamma-val :lambda-list '(m))
(cl:defmethod gamma-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:gamma-val is deprecated.  Use camera_control_msgs-msg:gamma instead.")
  (gamma m))

(cl:ensure-generic-function 'binning_x-val :lambda-list '(m))
(cl:defmethod binning_x-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:binning_x-val is deprecated.  Use camera_control_msgs-msg:binning_x instead.")
  (binning_x m))

(cl:ensure-generic-function 'binning_y-val :lambda-list '(m))
(cl:defmethod binning_y-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:binning_y-val is deprecated.  Use camera_control_msgs-msg:binning_y instead.")
  (binning_y m))

(cl:ensure-generic-function 'roi-val :lambda-list '(m))
(cl:defmethod roi-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:roi-val is deprecated.  Use camera_control_msgs-msg:roi instead.")
  (roi m))

(cl:ensure-generic-function 'available_image_encoding-val :lambda-list '(m))
(cl:defmethod available_image_encoding-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:available_image_encoding-val is deprecated.  Use camera_control_msgs-msg:available_image_encoding instead.")
  (available_image_encoding m))

(cl:ensure-generic-function 'current_image_encoding-val :lambda-list '(m))
(cl:defmethod current_image_encoding-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:current_image_encoding-val is deprecated.  Use camera_control_msgs-msg:current_image_encoding instead.")
  (current_image_encoding m))

(cl:ensure-generic-function 'current_image_ros_encoding-val :lambda-list '(m))
(cl:defmethod current_image_ros_encoding-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:current_image_ros_encoding-val is deprecated.  Use camera_control_msgs-msg:current_image_ros_encoding instead.")
  (current_image_ros_encoding m))

(cl:ensure-generic-function 'sucess-val :lambda-list '(m))
(cl:defmethod sucess-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:sucess-val is deprecated.  Use camera_control_msgs-msg:sucess instead.")
  (sucess m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <currentParams>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader camera_control_msgs-msg:message-val is deprecated.  Use camera_control_msgs-msg:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <currentParams>) ostream)
  "Serializes a message object of type '<currentParams>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'reverse_x) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'reverse_y) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'black_level)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'pgi_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'demosaicing_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'noise_reduction))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'sharpness_enhancement))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'light_source_preset)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'balance_white_auto)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'sensor_readout_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'acquisition_frame_count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'trigger_selector)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'trigger_mode)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'trigger_source)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'trigger_activation)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'trigger_delay))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'user_set_selector)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'user_set_default_selector)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_sleeping) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'brightness))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'exposure))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gain))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gamma))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'binning_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'binning_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'binning_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'binning_x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'binning_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'binning_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'binning_y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'binning_y)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'roi) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'available_image_encoding))))
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
   (cl:slot-value msg 'available_image_encoding))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'current_image_encoding))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'current_image_encoding))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'current_image_ros_encoding))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'current_image_ros_encoding))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'sucess) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <currentParams>) istream)
  "Deserializes a message object of type '<currentParams>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'offset_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'offset_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'offset_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'offset_y)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'reverse_x) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'reverse_y) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'black_level) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pgi_mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'demosaicing_mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'noise_reduction) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'sharpness_enhancement) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'light_source_preset) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'balance_white_auto) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sensor_readout_mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'acquisition_frame_count) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger_selector) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger_mode) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger_source) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'trigger_activation) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'trigger_delay) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'user_set_selector) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'user_set_default_selector) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'is_sleeping) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'brightness) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'exposure) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gain) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gamma) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'binning_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'binning_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'binning_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'binning_x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'binning_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'binning_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'binning_y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'binning_y)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'roi) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'available_image_encoding) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'available_image_encoding)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current_image_encoding) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'current_image_encoding) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'current_image_ros_encoding) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'current_image_ros_encoding) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'sucess) (cl:not (cl:zerop (cl:read-byte istream))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<currentParams>)))
  "Returns string type for a message object of type '<currentParams>"
  "camera_control_msgs/currentParams")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'currentParams)))
  "Returns string type for a message object of type 'currentParams"
  "camera_control_msgs/currentParams")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<currentParams>)))
  "Returns md5sum for a message object of type '<currentParams>"
  "0bd1503e3cdf30ac14ba73c781326a32")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'currentParams)))
  "Returns md5sum for a message object of type 'currentParams"
  "0bd1503e3cdf30ac14ba73c781326a32")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<currentParams>)))
  "Returns full string definition for message of type '<currentParams>"
  (cl:format cl:nil "uint32 offset_x # -20000 = Error	~%uint32 offset_y # -20000 = Error~%bool reverse_x~%bool reverse_y~%~%int32 black_level # -10000 = error/not available~%~%int32 pgi_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On~%int32 demosaicing_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Simple, 1 = BaslerPGI~%float32 noise_reduction # -20000.0 = Error, -10000.0 = Not available ~%float32 sharpness_enhancement # -20000.0 = Error, -10000.0 = Not available ~%int32 light_source_preset # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K~%int32 balance_white_auto # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Once, 2 = Continuous~%~%int32 sensor_readout_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Normal, 1 = Fast~%int32 acquisition_frame_count # -20000 = Error, -10000 = Not available ~%int32 trigger_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = FrameStart, 1 = FrameBurstStart(USB)/AcquisitionStart(GigE)~%int32 trigger_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On~%int32 trigger_source # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1(Selected Gige)~%int32 trigger_activation # -3 = Unknown, -2 = Error, -1 = Not available, 0 = RisingEdge, 1 = FallingEdge~%float32 trigger_delay # -20000.0 = Error, -10000.0 = Not available ~%~%int32 user_set_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw~%int32 user_set_default_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw ~%~%bool is_sleeping~%float32 brightness~%float32 exposure~%float32 gain~%float32 gamma ~%uint32 binning_x~%uint32 binning_y~%sensor_msgs/RegionOfInterest roi~%~%string[] available_image_encoding~%string current_image_encoding~%string current_image_ros_encoding~%~%bool sucess~%string message~%~%~%================================================================================~%MSG: sensor_msgs/RegionOfInterest~%# This message is used to specify a region of interest within an image.~%#~%# When used to specify the ROI setting of the camera when the image was~%# taken, the height and width fields should either match the height and~%# width fields for the associated image; or height = width = 0~%# indicates that the full resolution image was captured.~%~%uint32 x_offset  # Leftmost pixel of the ROI~%                 # (0 if the ROI includes the left edge of the image)~%uint32 y_offset  # Topmost pixel of the ROI~%                 # (0 if the ROI includes the top edge of the image)~%uint32 height    # Height of ROI~%uint32 width     # Width of ROI~%~%# True if a distinct rectified ROI should be calculated from the \"raw\"~%# ROI in this message. Typically this should be False if the full image~%# is captured (ROI not used), and True if a subwindow is captured (ROI~%# used).~%bool do_rectify~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'currentParams)))
  "Returns full string definition for message of type 'currentParams"
  (cl:format cl:nil "uint32 offset_x # -20000 = Error	~%uint32 offset_y # -20000 = Error~%bool reverse_x~%bool reverse_y~%~%int32 black_level # -10000 = error/not available~%~%int32 pgi_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On~%int32 demosaicing_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Simple, 1 = BaslerPGI~%float32 noise_reduction # -20000.0 = Error, -10000.0 = Not available ~%float32 sharpness_enhancement # -20000.0 = Error, -10000.0 = Not available ~%int32 light_source_preset # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Daylight5000K, 2 = Daylight6500K, 3 = Tungsten2800K~%int32 balance_white_auto # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = Once, 2 = Continuous~%~%int32 sensor_readout_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Normal, 1 = Fast~%int32 acquisition_frame_count # -20000 = Error, -10000 = Not available ~%int32 trigger_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = FrameStart, 1 = FrameBurstStart(USB)/AcquisitionStart(GigE)~%int32 trigger_mode # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Off, 1 = On~%int32 trigger_source # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Software, 1 = Line1, 2 = Line3, 3 = Line4, 4 = Action1(Selected Gige)~%int32 trigger_activation # -3 = Unknown, -2 = Error, -1 = Not available, 0 = RisingEdge, 1 = FallingEdge~%float32 trigger_delay # -20000.0 = Error, -10000.0 = Not available ~%~%int32 user_set_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw~%int32 user_set_default_selector # -3 = Unknown, -2 = Error, -1 = Not available, 0 = Default, 1 = UserSet1, 2 = UserSet2, 3 = UserSet3, 4 = HighGain, 5 = AutoFunctions, 6 = ColorRaw ~%~%bool is_sleeping~%float32 brightness~%float32 exposure~%float32 gain~%float32 gamma ~%uint32 binning_x~%uint32 binning_y~%sensor_msgs/RegionOfInterest roi~%~%string[] available_image_encoding~%string current_image_encoding~%string current_image_ros_encoding~%~%bool sucess~%string message~%~%~%================================================================================~%MSG: sensor_msgs/RegionOfInterest~%# This message is used to specify a region of interest within an image.~%#~%# When used to specify the ROI setting of the camera when the image was~%# taken, the height and width fields should either match the height and~%# width fields for the associated image; or height = width = 0~%# indicates that the full resolution image was captured.~%~%uint32 x_offset  # Leftmost pixel of the ROI~%                 # (0 if the ROI includes the left edge of the image)~%uint32 y_offset  # Topmost pixel of the ROI~%                 # (0 if the ROI includes the top edge of the image)~%uint32 height    # Height of ROI~%uint32 width     # Width of ROI~%~%# True if a distinct rectified ROI should be calculated from the \"raw\"~%# ROI in this message. Typically this should be False if the full image~%# is captured (ROI not used), and True if a subwindow is captured (ROI~%# used).~%bool do_rectify~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <currentParams>))
  (cl:+ 0
     4
     4
     1
     1
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     4
     1
     4
     4
     4
     4
     4
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'roi))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'available_image_encoding) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:length (cl:slot-value msg 'current_image_encoding))
     4 (cl:length (cl:slot-value msg 'current_image_ros_encoding))
     1
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <currentParams>))
  "Converts a ROS message object to a list"
  (cl:list 'currentParams
    (cl:cons ':offset_x (offset_x msg))
    (cl:cons ':offset_y (offset_y msg))
    (cl:cons ':reverse_x (reverse_x msg))
    (cl:cons ':reverse_y (reverse_y msg))
    (cl:cons ':black_level (black_level msg))
    (cl:cons ':pgi_mode (pgi_mode msg))
    (cl:cons ':demosaicing_mode (demosaicing_mode msg))
    (cl:cons ':noise_reduction (noise_reduction msg))
    (cl:cons ':sharpness_enhancement (sharpness_enhancement msg))
    (cl:cons ':light_source_preset (light_source_preset msg))
    (cl:cons ':balance_white_auto (balance_white_auto msg))
    (cl:cons ':sensor_readout_mode (sensor_readout_mode msg))
    (cl:cons ':acquisition_frame_count (acquisition_frame_count msg))
    (cl:cons ':trigger_selector (trigger_selector msg))
    (cl:cons ':trigger_mode (trigger_mode msg))
    (cl:cons ':trigger_source (trigger_source msg))
    (cl:cons ':trigger_activation (trigger_activation msg))
    (cl:cons ':trigger_delay (trigger_delay msg))
    (cl:cons ':user_set_selector (user_set_selector msg))
    (cl:cons ':user_set_default_selector (user_set_default_selector msg))
    (cl:cons ':is_sleeping (is_sleeping msg))
    (cl:cons ':brightness (brightness msg))
    (cl:cons ':exposure (exposure msg))
    (cl:cons ':gain (gain msg))
    (cl:cons ':gamma (gamma msg))
    (cl:cons ':binning_x (binning_x msg))
    (cl:cons ':binning_y (binning_y msg))
    (cl:cons ':roi (roi msg))
    (cl:cons ':available_image_encoding (available_image_encoding msg))
    (cl:cons ':current_image_encoding (current_image_encoding msg))
    (cl:cons ':current_image_ros_encoding (current_image_ros_encoding msg))
    (cl:cons ':sucess (sucess msg))
    (cl:cons ':message (message msg))
))
