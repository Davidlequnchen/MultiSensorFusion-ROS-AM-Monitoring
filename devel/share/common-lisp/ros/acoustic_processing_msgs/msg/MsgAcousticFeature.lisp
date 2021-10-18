; Auto-generated. Do not edit!


(cl:in-package acoustic_processing_msgs-msg)


;//! \htmlinclude MsgAcousticFeature.msg.html

(cl:defclass <MsgAcousticFeature> (roslisp-msg-protocol:ros-message)
  ((spectral_centroids
    :reader spectral_centroids
    :initarg :spectral_centroids
    :type cl:float
    :initform 0.0)
   (fft
    :reader fft
    :initarg :fft
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgAcousticFeature (<MsgAcousticFeature>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgAcousticFeature>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgAcousticFeature)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name acoustic_processing_msgs-msg:<MsgAcousticFeature> is deprecated: use acoustic_processing_msgs-msg:MsgAcousticFeature instead.")))

(cl:ensure-generic-function 'spectral_centroids-val :lambda-list '(m))
(cl:defmethod spectral_centroids-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_processing_msgs-msg:spectral_centroids-val is deprecated.  Use acoustic_processing_msgs-msg:spectral_centroids instead.")
  (spectral_centroids m))

(cl:ensure-generic-function 'fft-val :lambda-list '(m))
(cl:defmethod fft-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_processing_msgs-msg:fft-val is deprecated.  Use acoustic_processing_msgs-msg:fft instead.")
  (fft m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgAcousticFeature>) ostream)
  "Serializes a message object of type '<MsgAcousticFeature>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_centroids))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'fft))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgAcousticFeature>) istream)
  "Deserializes a message object of type '<MsgAcousticFeature>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_centroids) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'fft) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgAcousticFeature>)))
  "Returns string type for a message object of type '<MsgAcousticFeature>"
  "acoustic_processing_msgs/MsgAcousticFeature")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgAcousticFeature)))
  "Returns string type for a message object of type 'MsgAcousticFeature"
  "acoustic_processing_msgs/MsgAcousticFeature")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgAcousticFeature>)))
  "Returns md5sum for a message object of type '<MsgAcousticFeature>"
  "dceaefa1e58f133ccf0968427c39fdf1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgAcousticFeature)))
  "Returns md5sum for a message object of type 'MsgAcousticFeature"
  "dceaefa1e58f133ccf0968427c39fdf1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgAcousticFeature>)))
  "Returns full string definition for message of type '<MsgAcousticFeature>"
  (cl:format cl:nil "float32 spectral_centroids~%float32 fft~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgAcousticFeature)))
  "Returns full string definition for message of type 'MsgAcousticFeature"
  (cl:format cl:nil "float32 spectral_centroids~%float32 fft~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgAcousticFeature>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgAcousticFeature>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgAcousticFeature
    (cl:cons ':spectral_centroids (spectral_centroids msg))
    (cl:cons ':fft (fft msg))
))
