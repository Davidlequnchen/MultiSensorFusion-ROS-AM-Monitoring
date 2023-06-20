; Auto-generated. Do not edit!


(cl:in-package point_cloud_analysis-msg)


;//! \htmlinclude MsgPointCloudScan.msg.html

(cl:defclass <MsgPointCloudScan> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:boolean
    :initform cl:nil)
   (scanning_count
    :reader scanning_count
    :initarg :scanning_count
    :type cl:integer
    :initform 0))
)

(cl:defclass MsgPointCloudScan (<MsgPointCloudScan>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgPointCloudScan>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgPointCloudScan)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name point_cloud_analysis-msg:<MsgPointCloudScan> is deprecated: use point_cloud_analysis-msg:MsgPointCloudScan instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <MsgPointCloudScan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:ready-val is deprecated.  Use point_cloud_analysis-msg:ready instead.")
  (ready m))

(cl:ensure-generic-function 'scanning_count-val :lambda-list '(m))
(cl:defmethod scanning_count-val ((m <MsgPointCloudScan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader point_cloud_analysis-msg:scanning_count-val is deprecated.  Use point_cloud_analysis-msg:scanning_count instead.")
  (scanning_count m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgPointCloudScan>) ostream)
  "Serializes a message object of type '<MsgPointCloudScan>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ready) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'scanning_count)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgPointCloudScan>) istream)
  "Deserializes a message object of type '<MsgPointCloudScan>"
    (cl:setf (cl:slot-value msg 'ready) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'scanning_count) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgPointCloudScan>)))
  "Returns string type for a message object of type '<MsgPointCloudScan>"
  "point_cloud_analysis/MsgPointCloudScan")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgPointCloudScan)))
  "Returns string type for a message object of type 'MsgPointCloudScan"
  "point_cloud_analysis/MsgPointCloudScan")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgPointCloudScan>)))
  "Returns md5sum for a message object of type '<MsgPointCloudScan>"
  "e17f7c935aac21da9daa560a5aff6392")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgPointCloudScan)))
  "Returns md5sum for a message object of type 'MsgPointCloudScan"
  "e17f7c935aac21da9daa560a5aff6392")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgPointCloudScan>)))
  "Returns full string definition for message of type '<MsgPointCloudScan>"
  (cl:format cl:nil "bool ready # to tell the analysis node ready or not~%int32 scanning_count # No. of scan~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgPointCloudScan)))
  "Returns full string definition for message of type 'MsgPointCloudScan"
  (cl:format cl:nil "bool ready # to tell the analysis node ready or not~%int32 scanning_count # No. of scan~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgPointCloudScan>))
  (cl:+ 0
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgPointCloudScan>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgPointCloudScan
    (cl:cons ':ready (ready msg))
    (cl:cons ':scanning_count (scanning_count msg))
))
