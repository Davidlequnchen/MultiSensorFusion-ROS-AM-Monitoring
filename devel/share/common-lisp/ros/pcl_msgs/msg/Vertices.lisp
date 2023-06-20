; Auto-generated. Do not edit!


(cl:in-package pcl_msgs-msg)


;//! \htmlinclude Vertices.msg.html

(cl:defclass <Vertices> (roslisp-msg-protocol:ros-message)
  ((vertices
    :reader vertices
    :initarg :vertices
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass Vertices (<Vertices>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Vertices>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Vertices)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pcl_msgs-msg:<Vertices> is deprecated: use pcl_msgs-msg:Vertices instead.")))

(cl:ensure-generic-function 'vertices-val :lambda-list '(m))
(cl:defmethod vertices-val ((m <Vertices>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-msg:vertices-val is deprecated.  Use pcl_msgs-msg:vertices instead.")
  (vertices m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Vertices>) ostream)
  "Serializes a message object of type '<Vertices>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'vertices))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'vertices))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Vertices>) istream)
  "Deserializes a message object of type '<Vertices>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'vertices) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'vertices)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Vertices>)))
  "Returns string type for a message object of type '<Vertices>"
  "pcl_msgs/Vertices")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Vertices)))
  "Returns string type for a message object of type 'Vertices"
  "pcl_msgs/Vertices")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Vertices>)))
  "Returns md5sum for a message object of type '<Vertices>"
  "39bd7b1c23763ddd1b882b97cb7cfe11")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Vertices)))
  "Returns md5sum for a message object of type 'Vertices"
  "39bd7b1c23763ddd1b882b97cb7cfe11")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Vertices>)))
  "Returns full string definition for message of type '<Vertices>"
  (cl:format cl:nil "# List of point indices~%uint32[] vertices~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Vertices)))
  "Returns full string definition for message of type 'Vertices"
  (cl:format cl:nil "# List of point indices~%uint32[] vertices~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Vertices>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'vertices) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Vertices>))
  "Converts a ROS message object to a list"
  (cl:list 'Vertices
    (cl:cons ':vertices (vertices msg))
))
