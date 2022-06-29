; Auto-generated. Do not edit!


(cl:in-package audio_utils-msg)


;//! \htmlinclude AudioFrame.msg.html

(cl:defclass <AudioFrame> (roslisp-msg-protocol:ros-message)
  ((format
    :reader format
    :initarg :format
    :type cl:string
    :initform "")
   (channel_count
    :reader channel_count
    :initarg :channel_count
    :type cl:integer
    :initform 0)
   (sampling_frequency
    :reader sampling_frequency
    :initarg :sampling_frequency
    :type cl:integer
    :initform 0)
   (frame_sample_count
    :reader frame_sample_count
    :initarg :frame_sample_count
    :type cl:integer
    :initform 0)
   (data
    :reader data
    :initarg :data
    :type (cl:vector cl:fixnum)
   :initform (cl:make-array 0 :element-type 'cl:fixnum :initial-element 0)))
)

(cl:defclass AudioFrame (<AudioFrame>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AudioFrame>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AudioFrame)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name audio_utils-msg:<AudioFrame> is deprecated: use audio_utils-msg:AudioFrame instead.")))

(cl:ensure-generic-function 'format-val :lambda-list '(m))
(cl:defmethod format-val ((m <AudioFrame>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_utils-msg:format-val is deprecated.  Use audio_utils-msg:format instead.")
  (format m))

(cl:ensure-generic-function 'channel_count-val :lambda-list '(m))
(cl:defmethod channel_count-val ((m <AudioFrame>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_utils-msg:channel_count-val is deprecated.  Use audio_utils-msg:channel_count instead.")
  (channel_count m))

(cl:ensure-generic-function 'sampling_frequency-val :lambda-list '(m))
(cl:defmethod sampling_frequency-val ((m <AudioFrame>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_utils-msg:sampling_frequency-val is deprecated.  Use audio_utils-msg:sampling_frequency instead.")
  (sampling_frequency m))

(cl:ensure-generic-function 'frame_sample_count-val :lambda-list '(m))
(cl:defmethod frame_sample_count-val ((m <AudioFrame>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_utils-msg:frame_sample_count-val is deprecated.  Use audio_utils-msg:frame_sample_count instead.")
  (frame_sample_count m))

(cl:ensure-generic-function 'data-val :lambda-list '(m))
(cl:defmethod data-val ((m <AudioFrame>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_utils-msg:data-val is deprecated.  Use audio_utils-msg:data instead.")
  (data m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AudioFrame>) ostream)
  "Serializes a message object of type '<AudioFrame>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'format))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'format))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'channel_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'channel_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'channel_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'channel_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sampling_frequency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sampling_frequency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sampling_frequency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sampling_frequency)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frame_sample_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'frame_sample_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'frame_sample_count)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'frame_sample_count)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream))
   (cl:slot-value msg 'data))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AudioFrame>) istream)
  "Deserializes a message object of type '<AudioFrame>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'format) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'format) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'channel_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'channel_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'channel_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'channel_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sampling_frequency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sampling_frequency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sampling_frequency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sampling_frequency)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'frame_sample_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'frame_sample_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'frame_sample_count)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'frame_sample_count)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'data) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'data)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AudioFrame>)))
  "Returns string type for a message object of type '<AudioFrame>"
  "audio_utils/AudioFrame")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AudioFrame)))
  "Returns string type for a message object of type 'AudioFrame"
  "audio_utils/AudioFrame")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AudioFrame>)))
  "Returns md5sum for a message object of type '<AudioFrame>"
  "82adf6775a8307ce59815e86a751d73c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AudioFrame)))
  "Returns md5sum for a message object of type 'AudioFrame"
  "82adf6775a8307ce59815e86a751d73c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AudioFrame>)))
  "Returns full string definition for message of type '<AudioFrame>"
  (cl:format cl:nil "# Supported formats (all formats are little endian): ~%# - \"signed_8\"~%# - \"signed_16\"~%# - \"signed_24\"~%# - \"signed_padded_24\"~%# - \"signed_32\"~%# - \"unsigned_8\"~%# - \"unsigned_16\"~%# - \"unsigned_24\"~%# - \"unsigned_padded_24\"~%# - \"unsigned_32\"~%# - \"float\"~%# - \"double\"~%string format~%uint32 channel_count~%uint32 sampling_frequency~%uint32 frame_sample_count~%~%uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AudioFrame)))
  "Returns full string definition for message of type 'AudioFrame"
  (cl:format cl:nil "# Supported formats (all formats are little endian): ~%# - \"signed_8\"~%# - \"signed_16\"~%# - \"signed_24\"~%# - \"signed_padded_24\"~%# - \"signed_32\"~%# - \"unsigned_8\"~%# - \"unsigned_16\"~%# - \"unsigned_24\"~%# - \"unsigned_padded_24\"~%# - \"unsigned_32\"~%# - \"float\"~%# - \"double\"~%string format~%uint32 channel_count~%uint32 sampling_frequency~%uint32 frame_sample_count~%~%uint8[] data~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AudioFrame>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'format))
     4
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'data) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AudioFrame>))
  "Converts a ROS message object to a list"
  (cl:list 'AudioFrame
    (cl:cons ':format (format msg))
    (cl:cons ':channel_count (channel_count msg))
    (cl:cons ':sampling_frequency (sampling_frequency msg))
    (cl:cons ':frame_sample_count (frame_sample_count msg))
    (cl:cons ':data (data msg))
))
