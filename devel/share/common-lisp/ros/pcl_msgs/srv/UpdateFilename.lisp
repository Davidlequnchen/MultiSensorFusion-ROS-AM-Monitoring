; Auto-generated. Do not edit!


(cl:in-package pcl_msgs-srv)


;//! \htmlinclude UpdateFilename-request.msg.html

(cl:defclass <UpdateFilename-request> (roslisp-msg-protocol:ros-message)
  ((filename
    :reader filename
    :initarg :filename
    :type cl:string
    :initform ""))
)

(cl:defclass UpdateFilename-request (<UpdateFilename-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UpdateFilename-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UpdateFilename-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pcl_msgs-srv:<UpdateFilename-request> is deprecated: use pcl_msgs-srv:UpdateFilename-request instead.")))

(cl:ensure-generic-function 'filename-val :lambda-list '(m))
(cl:defmethod filename-val ((m <UpdateFilename-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-srv:filename-val is deprecated.  Use pcl_msgs-srv:filename instead.")
  (filename m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UpdateFilename-request>) ostream)
  "Serializes a message object of type '<UpdateFilename-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'filename))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'filename))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UpdateFilename-request>) istream)
  "Deserializes a message object of type '<UpdateFilename-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'filename) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'filename) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UpdateFilename-request>)))
  "Returns string type for a service object of type '<UpdateFilename-request>"
  "pcl_msgs/UpdateFilenameRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UpdateFilename-request)))
  "Returns string type for a service object of type 'UpdateFilename-request"
  "pcl_msgs/UpdateFilenameRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UpdateFilename-request>)))
  "Returns md5sum for a message object of type '<UpdateFilename-request>"
  "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UpdateFilename-request)))
  "Returns md5sum for a message object of type 'UpdateFilename-request"
  "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UpdateFilename-request>)))
  "Returns full string definition for message of type '<UpdateFilename-request>"
  (cl:format cl:nil "string filename~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UpdateFilename-request)))
  "Returns full string definition for message of type 'UpdateFilename-request"
  (cl:format cl:nil "string filename~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UpdateFilename-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'filename))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UpdateFilename-request>))
  "Converts a ROS message object to a list"
  (cl:list 'UpdateFilename-request
    (cl:cons ':filename (filename msg))
))
;//! \htmlinclude UpdateFilename-response.msg.html

(cl:defclass <UpdateFilename-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass UpdateFilename-response (<UpdateFilename-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UpdateFilename-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UpdateFilename-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pcl_msgs-srv:<UpdateFilename-response> is deprecated: use pcl_msgs-srv:UpdateFilename-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <UpdateFilename-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pcl_msgs-srv:success-val is deprecated.  Use pcl_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UpdateFilename-response>) ostream)
  "Serializes a message object of type '<UpdateFilename-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UpdateFilename-response>) istream)
  "Deserializes a message object of type '<UpdateFilename-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UpdateFilename-response>)))
  "Returns string type for a service object of type '<UpdateFilename-response>"
  "pcl_msgs/UpdateFilenameResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UpdateFilename-response)))
  "Returns string type for a service object of type 'UpdateFilename-response"
  "pcl_msgs/UpdateFilenameResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UpdateFilename-response>)))
  "Returns md5sum for a message object of type '<UpdateFilename-response>"
  "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UpdateFilename-response)))
  "Returns md5sum for a message object of type 'UpdateFilename-response"
  "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UpdateFilename-response>)))
  "Returns full string definition for message of type '<UpdateFilename-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UpdateFilename-response)))
  "Returns full string definition for message of type 'UpdateFilename-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UpdateFilename-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UpdateFilename-response>))
  "Converts a ROS message object to a list"
  (cl:list 'UpdateFilename-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'UpdateFilename)))
  'UpdateFilename-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'UpdateFilename)))
  'UpdateFilename-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UpdateFilename)))
  "Returns string type for a service object of type '<UpdateFilename>"
  "pcl_msgs/UpdateFilename")