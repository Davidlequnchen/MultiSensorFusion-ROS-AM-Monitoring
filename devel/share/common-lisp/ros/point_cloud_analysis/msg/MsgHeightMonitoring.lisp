; Auto-generated. Do not edit!


(cl:in-package point_cloud_analysis-msg)


;//! \htmlinclude MsgHeightMonitoring.msg.html

(cl:defclass <MsgHeightMonitoring> (roslisp-msg-protocol:ros-message)
  ((plane_id
    :reader plane_id
    :initarg :plane_id
    :type cl:integer
    :initform 0)
   (height_std
    :reader height_std
    :initarg :height_std
    :type cl:float
    :initform 0.0)
   (height_mean
    :reader height_mean
    :initarg :height_mean
    :type cl:float
    :initform 0.0)
   (heighest_max_min_difference
    :reader heighest_max_min_difference
    :initarg :heighest_max_min_difference
    :type cl:float
    :initform 0.0)
   (tilt_angle
    :reader tilt_angle
    :initarg :tilt_angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass MsgHeightMonitoring (<MsgHeightMonitoring>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgHeightMonitoring>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgHeightMonitoring)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name point_cloud_analysis-msg:<MsgHeightMonitoring> is deprecated: use point_cloud_analysis-msg:MsgHeightMonitoring instead.")))

(cl:ensure-generic-function 'plane_id-val :lambda-list '(m))
(cl:defmethod plane_id-val ((m <MsgHeightMonitoring>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:plane_id-val is deprecated.  Use point_cloud_analysis-msg:plane_id instead.")
  (plane_id m))

(cl:ensure-generic-function 'height_std-val :lambda-list '(m))
(cl:defmethod height_std-val ((m <MsgHeightMonitoring>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:height_std-val is deprecated.  Use point_cloud_analysis-msg:height_std instead.")
  (height_std m))

(cl:ensure-generic-function 'height_mean-val :lambda-list '(m))
(cl:defmethod height_mean-val ((m <MsgHeightMonitoring>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:height_mean-val is deprecated.  Use point_cloud_analysis-msg:height_mean instead.")
  (height_mean m))

(cl:ensure-generic-function 'heighest_max_min_difference-val :lambda-list '(m))
(cl:defmethod heighest_max_min_difference-val ((m <MsgHeightMonitoring>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:heighest_max_min_difference-val is deprecated.  Use point_cloud_analysis-msg:heighest_max_min_difference instead.")
  (heighest_max_min_difference m))

(cl:ensure-generic-function 'tilt_angle-val :lambda-list '(m))
(cl:defmethod tilt_angle-val ((m <MsgHeightMonitoring>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:tilt_angle-val is deprecated.  Use point_cloud_analysis-msg:tilt_angle instead.")
  (tilt_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgHeightMonitoring>) ostream)
  "Serializes a message object of type '<MsgHeightMonitoring>"
  (cl:let* ((signed (cl:slot-value msg 'plane_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'height_std))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'height_mean))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'heighest_max_min_difference))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'tilt_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgHeightMonitoring>) istream)
  "Deserializes a message object of type '<MsgHeightMonitoring>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'plane_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'height_std) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'height_mean) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'heighest_max_min_difference) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'tilt_angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgHeightMonitoring>)))
  "Returns string type for a message object of type '<MsgHeightMonitoring>"
  "point_cloud_analysis/MsgHeightMonitoring")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgHeightMonitoring)))
  "Returns string type for a message object of type 'MsgHeightMonitoring"
  "point_cloud_analysis/MsgHeightMonitoring")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgHeightMonitoring>)))
  "Returns md5sum for a message object of type '<MsgHeightMonitoring>"
  "d5dba450528743fdd28379753715b42a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgHeightMonitoring)))
  "Returns md5sum for a message object of type 'MsgHeightMonitoring"
  "d5dba450528743fdd28379753715b42a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgHeightMonitoring>)))
  "Returns full string definition for message of type '<MsgHeightMonitoring>"
  (cl:format cl:nil "int32 plane_id         # the id for the scanning~%float32 height_std~%float32 height_mean~%float32 heighest_max_min_difference~%float32 tilt_angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgHeightMonitoring)))
  "Returns full string definition for message of type 'MsgHeightMonitoring"
  (cl:format cl:nil "int32 plane_id         # the id for the scanning~%float32 height_std~%float32 height_mean~%float32 heighest_max_min_difference~%float32 tilt_angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgHeightMonitoring>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgHeightMonitoring>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgHeightMonitoring
    (cl:cons ':plane_id (plane_id msg))
    (cl:cons ':height_std (height_std msg))
    (cl:cons ':height_mean (height_mean msg))
    (cl:cons ':heighest_max_min_difference (heighest_max_min_difference msg))
    (cl:cons ':tilt_angle (tilt_angle msg))
))
