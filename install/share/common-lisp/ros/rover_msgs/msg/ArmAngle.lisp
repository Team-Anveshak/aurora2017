; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude ArmAngle.msg.html

(cl:defclass <ArmAngle> (roslisp-msg-protocol:ros-message)
  ((angle_1
    :reader angle_1
    :initarg :angle_1
    :type cl:float
    :initform 0.0)
   (angle_2
    :reader angle_2
    :initarg :angle_2
    :type cl:float
    :initform 0.0)
   (angle_3
    :reader angle_3
    :initarg :angle_3
    :type cl:float
    :initform 0.0))
)

(cl:defclass ArmAngle (<ArmAngle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ArmAngle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ArmAngle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<ArmAngle> is deprecated: use rover_msgs-msg:ArmAngle instead.")))

(cl:ensure-generic-function 'angle_1-val :lambda-list '(m))
(cl:defmethod angle_1-val ((m <ArmAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:angle_1-val is deprecated.  Use rover_msgs-msg:angle_1 instead.")
  (angle_1 m))

(cl:ensure-generic-function 'angle_2-val :lambda-list '(m))
(cl:defmethod angle_2-val ((m <ArmAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:angle_2-val is deprecated.  Use rover_msgs-msg:angle_2 instead.")
  (angle_2 m))

(cl:ensure-generic-function 'angle_3-val :lambda-list '(m))
(cl:defmethod angle_3-val ((m <ArmAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:angle_3-val is deprecated.  Use rover_msgs-msg:angle_3 instead.")
  (angle_3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ArmAngle>) ostream)
  "Serializes a message object of type '<ArmAngle>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle_3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ArmAngle>) istream)
  "Deserializes a message object of type '<ArmAngle>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle_2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle_3) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ArmAngle>)))
  "Returns string type for a message object of type '<ArmAngle>"
  "rover_msgs/ArmAngle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ArmAngle)))
  "Returns string type for a message object of type 'ArmAngle"
  "rover_msgs/ArmAngle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ArmAngle>)))
  "Returns md5sum for a message object of type '<ArmAngle>"
  "7023de6969abdb6bc7e604ee027fa612")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ArmAngle)))
  "Returns md5sum for a message object of type 'ArmAngle"
  "7023de6969abdb6bc7e604ee027fa612")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ArmAngle>)))
  "Returns full string definition for message of type '<ArmAngle>"
  (cl:format cl:nil "float32 angle_1~%float32 angle_2~%float32 angle_3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ArmAngle)))
  "Returns full string definition for message of type 'ArmAngle"
  (cl:format cl:nil "float32 angle_1~%float32 angle_2~%float32 angle_3~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ArmAngle>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ArmAngle>))
  "Converts a ROS message object to a list"
  (cl:list 'ArmAngle
    (cl:cons ':angle_1 (angle_1 msg))
    (cl:cons ':angle_2 (angle_2 msg))
    (cl:cons ':angle_3 (angle_3 msg))
))
