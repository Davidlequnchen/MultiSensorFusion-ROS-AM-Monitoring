; Auto-generated. Do not edit!


(cl:in-package defects_identification-msg)


;//! \htmlinclude MsgPointDistance.msg.html

(cl:defclass <MsgPointDistance> (roslisp-msg-protocol:ros-message)
  ((point_to_plane_distance
    :reader point_to_plane_distance
    :initarg :point_to_plane_distance
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass MsgPointDistance (<MsgPointDistance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MsgPointDistance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MsgPointDistance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name defects_identification-msg:<MsgPointDistance> is deprecated: use defects_identification-msg:MsgPointDistance instead.")))

(cl:ensure-generic-function 'point_to_plane_distance-val :lambda-list '(m))
(cl:defmethod point_to_plane_distance-val ((m <MsgPointDistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader defects_identification-msg:point_to_plane_distance-val is deprecated.  Use defects_identification-msg:point_to_plane_distance instead.")
  (point_to_plane_distance m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MsgPointDistance>) ostream)
  "Serializes a message object of type '<MsgPointDistance>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'point_to_plane_distance))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'point_to_plane_distance))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MsgPointDistance>) istream)
  "Deserializes a message object of type '<MsgPointDistance>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'point_to_plane_distance) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'point_to_plane_distance)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MsgPointDistance>)))
  "Returns string type for a message object of type '<MsgPointDistance>"
  "defects_identification/MsgPointDistance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MsgPointDistance)))
  "Returns string type for a message object of type 'MsgPointDistance"
  "defects_identification/MsgPointDistance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MsgPointDistance>)))
  "Returns md5sum for a message object of type '<MsgPointDistance>"
  "c24ec51a2bb9c83a98d25173a7416b03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MsgPointDistance)))
  "Returns md5sum for a message object of type 'MsgPointDistance"
  "c24ec51a2bb9c83a98d25173a7416b03")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MsgPointDistance>)))
  "Returns full string definition for message of type '<MsgPointDistance>"
  (cl:format cl:nil "float32[] point_to_plane_distance~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MsgPointDistance)))
  "Returns full string definition for message of type 'MsgPointDistance"
  (cl:format cl:nil "float32[] point_to_plane_distance~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MsgPointDistance>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'point_to_plane_distance) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MsgPointDistance>))
  "Converts a ROS message object to a list"
  (cl:list 'MsgPointDistance
    (cl:cons ':point_to_plane_distance (point_to_plane_distance msg))
))
