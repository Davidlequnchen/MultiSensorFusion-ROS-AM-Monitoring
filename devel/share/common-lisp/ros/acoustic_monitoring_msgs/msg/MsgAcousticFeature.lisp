; Auto-generated. Do not edit!


(cl:in-package acoustic_monitoring_msgs-msg)


;//! \htmlinclude MsgAcousticFeature.msg.html

(cl:defclass <MsgAcousticFeature> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (rms_energy
    :reader rms_energy
    :initarg :rms_energy
    :type cl:float
    :initform 0.0)
   (amplitude_envelope
    :reader amplitude_envelope
    :initarg :amplitude_envelope
    :type cl:float
    :initform 0.0)
   (zero_crossing_rate
    :reader zero_crossing_rate
    :initarg :zero_crossing_rate
    :type cl:float
    :initform 0.0)
   (mfccs_mean
    :reader mfccs_mean
    :initarg :mfccs_mean
    :type cl:float
    :initform 0.0)
   (mfccs_variance
    :reader mfccs_variance
    :initarg :mfccs_variance
    :type cl:float
    :initform 0.0)
   (spectral_centroids
    :reader spectral_centroids
    :initarg :spectral_centroids
    :type cl:float
    :initform 0.0)
   (spectral_rolloff
    :reader spectral_rolloff
    :initarg :spectral_rolloff
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgAcousticFeature (<MsgAcousticFeature>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgAcousticFeature>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgAcousticFeature)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name acoustic_monitoring_msgs-msg:<MsgAcousticFeature> is deprecated: use acoustic_monitoring_msgs-msg:MsgAcousticFeature instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:header-val is deprecated.  Use acoustic_monitoring_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'rms_energy-val :lambda-list '(m))
(cl:defmethod rms_energy-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:rms_energy-val is deprecated.  Use acoustic_monitoring_msgs-msg:rms_energy instead.")
  (rms_energy m))

(cl:ensure-generic-function 'amplitude_envelope-val :lambda-list '(m))
(cl:defmethod amplitude_envelope-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:amplitude_envelope-val is deprecated.  Use acoustic_monitoring_msgs-msg:amplitude_envelope instead.")
  (amplitude_envelope m))

(cl:ensure-generic-function 'zero_crossing_rate-val :lambda-list '(m))
(cl:defmethod zero_crossing_rate-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:zero_crossing_rate-val is deprecated.  Use acoustic_monitoring_msgs-msg:zero_crossing_rate instead.")
  (zero_crossing_rate m))

(cl:ensure-generic-function 'mfccs_mean-val :lambda-list '(m))
(cl:defmethod mfccs_mean-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:mfccs_mean-val is deprecated.  Use acoustic_monitoring_msgs-msg:mfccs_mean instead.")
  (mfccs_mean m))

(cl:ensure-generic-function 'mfccs_variance-val :lambda-list '(m))
(cl:defmethod mfccs_variance-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:mfccs_variance-val is deprecated.  Use acoustic_monitoring_msgs-msg:mfccs_variance instead.")
  (mfccs_variance m))

(cl:ensure-generic-function 'spectral_centroids-val :lambda-list '(m))
(cl:defmethod spectral_centroids-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_centroids-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_centroids instead.")
  (spectral_centroids m))

(cl:ensure-generic-function 'spectral_rolloff-val :lambda-list '(m))
(cl:defmethod spectral_rolloff-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_rolloff-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_rolloff instead.")
  (spectral_rolloff m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgAcousticFeature>) ostream)
  "Serializes a message object of type '<MsgAcousticFeature>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rms_energy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'amplitude_envelope))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'zero_crossing_rate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'mfccs_mean))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'mfccs_variance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_centroids))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_rolloff))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgAcousticFeature>) istream)
  "Deserializes a message object of type '<MsgAcousticFeature>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rms_energy) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'amplitude_envelope) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zero_crossing_rate) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'mfccs_mean) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'mfccs_variance) (roslisp-utils:decode-single-float-bits bits)))
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
    (cl:setf (cl:slot-value msg 'spectral_rolloff) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgAcousticFeature>)))
  "Returns string type for a message object of type '<MsgAcousticFeature>"
  "acoustic_monitoring_msgs/MsgAcousticFeature")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgAcousticFeature)))
  "Returns string type for a message object of type 'MsgAcousticFeature"
  "acoustic_monitoring_msgs/MsgAcousticFeature")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgAcousticFeature>)))
  "Returns md5sum for a message object of type '<MsgAcousticFeature>"
  "c14a16b80445b9cad4c6f29ce8f94aa6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgAcousticFeature)))
  "Returns md5sum for a message object of type 'MsgAcousticFeature"
  "c14a16b80445b9cad4c6f29ce8f94aa6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgAcousticFeature>)))
  "Returns full string definition for message of type '<MsgAcousticFeature>"
  (cl:format cl:nil "Header header~%# time-domain features~%float32 rms_energy~%float32 amplitude_envelope~%float32 zero_crossing_rate~%# frequency-domain features~%# float32 mfccs~%float32 mfccs_mean~%float32 mfccs_variance~%float32 spectral_centroids~%float32 spectral_rolloff~%~%~%# spectral_centroid computes the \"average\" frequency at each frame, where frequencies are weighted relatively by their energy.~%# spectral_bandwidth similar to centroid, but for variance (or other moments).~%# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgAcousticFeature)))
  "Returns full string definition for message of type 'MsgAcousticFeature"
  (cl:format cl:nil "Header header~%# time-domain features~%float32 rms_energy~%float32 amplitude_envelope~%float32 zero_crossing_rate~%# frequency-domain features~%# float32 mfccs~%float32 mfccs_mean~%float32 mfccs_variance~%float32 spectral_centroids~%float32 spectral_rolloff~%~%~%# spectral_centroid computes the \"average\" frequency at each frame, where frequencies are weighted relatively by their energy.~%# spectral_bandwidth similar to centroid, but for variance (or other moments).~%# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgAcousticFeature>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgAcousticFeature>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgAcousticFeature
    (cl:cons ':header (header msg))
    (cl:cons ':rms_energy (rms_energy msg))
    (cl:cons ':amplitude_envelope (amplitude_envelope msg))
    (cl:cons ':zero_crossing_rate (zero_crossing_rate msg))
    (cl:cons ':mfccs_mean (mfccs_mean msg))
    (cl:cons ':mfccs_variance (mfccs_variance msg))
    (cl:cons ':spectral_centroids (spectral_centroids msg))
    (cl:cons ':spectral_rolloff (spectral_rolloff msg))
))
