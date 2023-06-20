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
   (mel_spectrogram
    :reader mel_spectrogram
    :initarg :mel_spectrogram
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (mfccs
    :reader mfccs
    :initarg :mfccs
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (ber
    :reader ber
    :initarg :ber
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
    :initform 0.0)
   (spectral_bandwidth
    :reader spectral_bandwidth
    :initarg :spectral_bandwidth
    :type cl:float
    :initform 0.0)
   (spectral_flatness
    :reader spectral_flatness
    :initarg :spectral_flatness
    :type cl:float
    :initform 0.0)
   (spectral_crest_factor
    :reader spectral_crest_factor
    :initarg :spectral_crest_factor
    :type cl:float
    :initform 0.0)
   (spectral_kurtosis
    :reader spectral_kurtosis
    :initarg :spectral_kurtosis
    :type cl:float
    :initform 0.0)
   (spectral_variance
    :reader spectral_variance
    :initarg :spectral_variance
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

(cl:ensure-generic-function 'mel_spectrogram-val :lambda-list '(m))
(cl:defmethod mel_spectrogram-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:mel_spectrogram-val is deprecated.  Use acoustic_monitoring_msgs-msg:mel_spectrogram instead.")
  (mel_spectrogram m))

(cl:ensure-generic-function 'mfccs-val :lambda-list '(m))
(cl:defmethod mfccs-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:mfccs-val is deprecated.  Use acoustic_monitoring_msgs-msg:mfccs instead.")
  (mfccs m))

(cl:ensure-generic-function 'ber-val :lambda-list '(m))
(cl:defmethod ber-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:ber-val is deprecated.  Use acoustic_monitoring_msgs-msg:ber instead.")
  (ber m))

(cl:ensure-generic-function 'spectral_centroids-val :lambda-list '(m))
(cl:defmethod spectral_centroids-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_centroids-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_centroids instead.")
  (spectral_centroids m))

(cl:ensure-generic-function 'spectral_rolloff-val :lambda-list '(m))
(cl:defmethod spectral_rolloff-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_rolloff-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_rolloff instead.")
  (spectral_rolloff m))

(cl:ensure-generic-function 'spectral_bandwidth-val :lambda-list '(m))
(cl:defmethod spectral_bandwidth-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_bandwidth-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_bandwidth instead.")
  (spectral_bandwidth m))

(cl:ensure-generic-function 'spectral_flatness-val :lambda-list '(m))
(cl:defmethod spectral_flatness-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_flatness-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_flatness instead.")
  (spectral_flatness m))

(cl:ensure-generic-function 'spectral_crest_factor-val :lambda-list '(m))
(cl:defmethod spectral_crest_factor-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_crest_factor-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_crest_factor instead.")
  (spectral_crest_factor m))

(cl:ensure-generic-function 'spectral_kurtosis-val :lambda-list '(m))
(cl:defmethod spectral_kurtosis-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_kurtosis-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_kurtosis instead.")
  (spectral_kurtosis m))

(cl:ensure-generic-function 'spectral_variance-val :lambda-list '(m))
(cl:defmethod spectral_variance-val ((m <MsgAcousticFeature>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader acoustic_monitoring_msgs-msg:spectral_variance-val is deprecated.  Use acoustic_monitoring_msgs-msg:spectral_variance instead.")
  (spectral_variance m))
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
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'mel_spectrogram))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'mel_spectrogram))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'mfccs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'mfccs))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ber))))
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_bandwidth))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_flatness))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_crest_factor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_kurtosis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'spectral_variance))))
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
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'mel_spectrogram) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'mel_spectrogram)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'mfccs) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'mfccs)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ber) (roslisp-utils:decode-single-float-bits bits)))
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
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_bandwidth) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_flatness) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_crest_factor) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_kurtosis) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'spectral_variance) (roslisp-utils:decode-single-float-bits bits)))
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
  "57131d07b28013debc0969e0928b0739")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgAcousticFeature)))
  "Returns md5sum for a message object of type 'MsgAcousticFeature"
  "57131d07b28013debc0969e0928b0739")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgAcousticFeature>)))
  "Returns full string definition for message of type '<MsgAcousticFeature>"
  (cl:format cl:nil "Header header~%# time-domain features~%float32 rms_energy~%float32 amplitude_envelope~%float32 zero_crossing_rate~%# freqeuncy domain features~%float32[] mel_spectrogram~%float32[] mfccs~%float32 ber~%float32 spectral_centroids~%float32 spectral_rolloff~%float32 spectral_bandwidth~%float32 spectral_flatness~%float32 spectral_crest_factor~%float32 spectral_kurtosis~%float32 spectral_variance~%~%~%# spectral_centroid computes the \"average\" frequency at each frame, where frequencies are weighted relatively by their energy.~%# spectral_bandwidth similar to centroid, but for variance (or other moments).~%# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgAcousticFeature)))
  "Returns full string definition for message of type 'MsgAcousticFeature"
  (cl:format cl:nil "Header header~%# time-domain features~%float32 rms_energy~%float32 amplitude_envelope~%float32 zero_crossing_rate~%# freqeuncy domain features~%float32[] mel_spectrogram~%float32[] mfccs~%float32 ber~%float32 spectral_centroids~%float32 spectral_rolloff~%float32 spectral_bandwidth~%float32 spectral_flatness~%float32 spectral_crest_factor~%float32 spectral_kurtosis~%float32 spectral_variance~%~%~%# spectral_centroid computes the \"average\" frequency at each frame, where frequencies are weighted relatively by their energy.~%# spectral_bandwidth similar to centroid, but for variance (or other moments).~%# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgAcousticFeature>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'mel_spectrogram) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'mfccs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
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
    (cl:cons ':mel_spectrogram (mel_spectrogram msg))
    (cl:cons ':mfccs (mfccs msg))
    (cl:cons ':ber (ber msg))
    (cl:cons ':spectral_centroids (spectral_centroids msg))
    (cl:cons ':spectral_rolloff (spectral_rolloff msg))
    (cl:cons ':spectral_bandwidth (spectral_bandwidth msg))
    (cl:cons ':spectral_flatness (spectral_flatness msg))
    (cl:cons ':spectral_crest_factor (spectral_crest_factor msg))
    (cl:cons ':spectral_kurtosis (spectral_kurtosis msg))
    (cl:cons ':spectral_variance (spectral_variance msg))
))
