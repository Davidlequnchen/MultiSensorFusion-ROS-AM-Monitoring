; Auto-generated. Do not edit!


(cl:in-package audio_common_msgs-msg)


;//! \htmlinclude AudioInfo.msg.html

(cl:defclass <AudioInfo> (roslisp-msg-protocol:ros-message)
  ((channels
    :reader channels
    :initarg :channels
    :type cl:fixnum
    :initform 0)
   (sample_rate
    :reader sample_rate
    :initarg :sample_rate
    :type cl:integer
    :initform 0)
   (sample_format
    :reader sample_format
    :initarg :sample_format
    :type cl:string
    :initform "")
   (bitrate
    :reader bitrate
    :initarg :bitrate
    :type cl:integer
    :initform 0)
   (coding_format
    :reader coding_format
    :initarg :coding_format
    :type cl:string
    :initform ""))
)

(cl:defclass AudioInfo (<AudioInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AudioInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AudioInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name audio_common_msgs-msg:<AudioInfo> is deprecated: use audio_common_msgs-msg:AudioInfo instead.")))

(cl:ensure-generic-function 'channels-val :lambda-list '(m))
(cl:defmethod channels-val ((m <AudioInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_common_msgs-msg:channels-val is deprecated.  Use audio_common_msgs-msg:channels instead.")
  (channels m))

(cl:ensure-generic-function 'sample_rate-val :lambda-list '(m))
(cl:defmethod sample_rate-val ((m <AudioInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_common_msgs-msg:sample_rate-val is deprecated.  Use audio_common_msgs-msg:sample_rate instead.")
  (sample_rate m))

(cl:ensure-generic-function 'sample_format-val :lambda-list '(m))
(cl:defmethod sample_format-val ((m <AudioInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_common_msgs-msg:sample_format-val is deprecated.  Use audio_common_msgs-msg:sample_format instead.")
  (sample_format m))

(cl:ensure-generic-function 'bitrate-val :lambda-list '(m))
(cl:defmethod bitrate-val ((m <AudioInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_common_msgs-msg:bitrate-val is deprecated.  Use audio_common_msgs-msg:bitrate instead.")
  (bitrate m))

(cl:ensure-generic-function 'coding_format-val :lambda-list '(m))
(cl:defmethod coding_format-val ((m <AudioInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader audio_common_msgs-msg:coding_format-val is deprecated.  Use audio_common_msgs-msg:coding_format instead.")
  (coding_format m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AudioInfo>) ostream)
  "Serializes a message object of type '<AudioInfo>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'channels)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sample_rate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sample_rate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sample_rate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sample_rate)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'sample_format))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'sample_format))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bitrate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'bitrate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'bitrate)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'bitrate)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'coding_format))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'coding_format))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AudioInfo>) istream)
  "Deserializes a message object of type '<AudioInfo>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'channels)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'sample_rate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'sample_rate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'sample_rate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'sample_rate)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sample_format) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'sample_format) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bitrate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'bitrate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'bitrate)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'bitrate)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'coding_format) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'coding_format) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AudioInfo>)))
  "Returns string type for a message object of type '<AudioInfo>"
  "audio_common_msgs/AudioInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AudioInfo)))
  "Returns string type for a message object of type 'AudioInfo"
  "audio_common_msgs/AudioInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AudioInfo>)))
  "Returns md5sum for a message object of type '<AudioInfo>"
  "9413d9b7029680d3b1db6ed0ae535f88")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AudioInfo)))
  "Returns md5sum for a message object of type 'AudioInfo"
  "9413d9b7029680d3b1db6ed0ae535f88")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AudioInfo>)))
  "Returns full string definition for message of type '<AudioInfo>"
  (cl:format cl:nil "# This message contains the audio meta data~%~%# Number of channels~%uint8 channels~%# Sampling rate [Hz]~%uint32 sample_rate~%# Audio format (e.g. S16LE)~%string sample_format~%# Amount of audio data per second [bits/s]~%uint32 bitrate~%# Audio coding format (e.g. WAVE, MP3)~%string coding_format~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AudioInfo)))
  "Returns full string definition for message of type 'AudioInfo"
  (cl:format cl:nil "# This message contains the audio meta data~%~%# Number of channels~%uint8 channels~%# Sampling rate [Hz]~%uint32 sample_rate~%# Audio format (e.g. S16LE)~%string sample_format~%# Amount of audio data per second [bits/s]~%uint32 bitrate~%# Audio coding format (e.g. WAVE, MP3)~%string coding_format~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AudioInfo>))
  (cl:+ 0
     1
     4
     4 (cl:length (cl:slot-value msg 'sample_format))
     4
     4 (cl:length (cl:slot-value msg 'coding_format))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AudioInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'AudioInfo
    (cl:cons ':channels (channels msg))
    (cl:cons ':sample_rate (sample_rate msg))
    (cl:cons ':sample_format (sample_format msg))
    (cl:cons ':bitrate (bitrate msg))
    (cl:cons ':coding_format (coding_format msg))
))
