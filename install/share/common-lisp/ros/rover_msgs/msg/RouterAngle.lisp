; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude RouterAngle.msg.html

(cl:defclass <RouterAngle> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass RouterAngle (<RouterAngle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RouterAngle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RouterAngle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<RouterAngle> is deprecated: use rover_msgs-msg:RouterAngle instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <RouterAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:angle-val is deprecated.  Use rover_msgs-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RouterAngle>) ostream)
  "Serializes a message object of type '<RouterAngle>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RouterAngle>) istream)
  "Deserializes a message object of type '<RouterAngle>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RouterAngle>)))
  "Returns string type for a message object of type '<RouterAngle>"
  "rover_msgs/RouterAngle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RouterAngle)))
  "Returns string type for a message object of type 'RouterAngle"
  "rover_msgs/RouterAngle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RouterAngle>)))
  "Returns md5sum for a message object of type '<RouterAngle>"
  "4edb55038e2b888976a0c0c56935341c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RouterAngle)))
  "Returns md5sum for a message object of type 'RouterAngle"
  "4edb55038e2b888976a0c0c56935341c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RouterAngle>)))
  "Returns full string definition for message of type '<RouterAngle>"
  (cl:format cl:nil "float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RouterAngle)))
  "Returns full string definition for message of type 'RouterAngle"
  (cl:format cl:nil "float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RouterAngle>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RouterAngle>))
  "Converts a ROS message object to a list"
  (cl:list 'RouterAngle
    (cl:cons ':angle (angle msg))
))
