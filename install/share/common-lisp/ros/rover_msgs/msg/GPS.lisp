; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude GPS.msg.html

(cl:defclass <GPS> (roslisp-msg-protocol:ros-message)
  ((inst_lat
    :reader inst_lat
    :initarg :inst_lat
    :type cl:float
    :initform 0.0)
   (inst_lng
    :reader inst_lng
    :initarg :inst_lng
    :type cl:float
    :initform 0.0))
)

(cl:defclass GPS (<GPS>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GPS>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GPS)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<GPS> is deprecated: use rover_msgs-msg:GPS instead.")))

(cl:ensure-generic-function 'inst_lat-val :lambda-list '(m))
(cl:defmethod inst_lat-val ((m <GPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:inst_lat-val is deprecated.  Use rover_msgs-msg:inst_lat instead.")
  (inst_lat m))

(cl:ensure-generic-function 'inst_lng-val :lambda-list '(m))
(cl:defmethod inst_lng-val ((m <GPS>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:inst_lng-val is deprecated.  Use rover_msgs-msg:inst_lng instead.")
  (inst_lng m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GPS>) ostream)
  "Serializes a message object of type '<GPS>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'inst_lat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'inst_lng))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GPS>) istream)
  "Deserializes a message object of type '<GPS>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'inst_lat) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'inst_lng) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GPS>)))
  "Returns string type for a message object of type '<GPS>"
  "rover_msgs/GPS")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GPS)))
  "Returns string type for a message object of type 'GPS"
  "rover_msgs/GPS")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GPS>)))
  "Returns md5sum for a message object of type '<GPS>"
  "bdc78d65862232f16b2d232d64a4f3eb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GPS)))
  "Returns md5sum for a message object of type 'GPS"
  "bdc78d65862232f16b2d232d64a4f3eb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GPS>)))
  "Returns full string definition for message of type '<GPS>"
  (cl:format cl:nil "float32 inst_lat~%float32 inst_lng~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GPS)))
  "Returns full string definition for message of type 'GPS"
  (cl:format cl:nil "float32 inst_lat~%float32 inst_lng~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GPS>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GPS>))
  "Converts a ROS message object to a list"
  (cl:list 'GPS
    (cl:cons ':inst_lat (inst_lat msg))
    (cl:cons ':inst_lng (inst_lng msg))
))
