; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude WheelVelocity.msg.html

(cl:defclass <WheelVelocity> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:float
    :initform 0.0)
   (right
    :reader right
    :initarg :right
    :type cl:float
    :initform 0.0)
   (reset_flag
    :reader reset_flag
    :initarg :reset_flag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass WheelVelocity (<WheelVelocity>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WheelVelocity>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WheelVelocity)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<WheelVelocity> is deprecated: use rover_msgs-msg:WheelVelocity instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <WheelVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:left-val is deprecated.  Use rover_msgs-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <WheelVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:right-val is deprecated.  Use rover_msgs-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'reset_flag-val :lambda-list '(m))
(cl:defmethod reset_flag-val ((m <WheelVelocity>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:reset_flag-val is deprecated.  Use rover_msgs-msg:reset_flag instead.")
  (reset_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WheelVelocity>) ostream)
  "Serializes a message object of type '<WheelVelocity>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'reset_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WheelVelocity>) istream)
  "Deserializes a message object of type '<WheelVelocity>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reset_flag) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WheelVelocity>)))
  "Returns string type for a message object of type '<WheelVelocity>"
  "rover_msgs/WheelVelocity")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WheelVelocity)))
  "Returns string type for a message object of type 'WheelVelocity"
  "rover_msgs/WheelVelocity")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WheelVelocity>)))
  "Returns md5sum for a message object of type '<WheelVelocity>"
  "22c56d70a0f2060151657bd9cd98512f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WheelVelocity)))
  "Returns md5sum for a message object of type 'WheelVelocity"
  "22c56d70a0f2060151657bd9cd98512f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WheelVelocity>)))
  "Returns full string definition for message of type '<WheelVelocity>"
  (cl:format cl:nil "float64 left~%float64 right~%int16 reset_flag~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WheelVelocity)))
  "Returns full string definition for message of type 'WheelVelocity"
  (cl:format cl:nil "float64 left~%float64 right~%int16 reset_flag~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WheelVelocity>))
  (cl:+ 0
     8
     8
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WheelVelocity>))
  "Converts a ROS message object to a list"
  (cl:list 'WheelVelocity
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
    (cl:cons ':reset_flag (reset_flag msg))
))
