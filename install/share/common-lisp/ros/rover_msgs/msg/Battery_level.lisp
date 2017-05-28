; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude Battery_level.msg.html

(cl:defclass <Battery_level> (roslisp-msg-protocol:ros-message)
  ((batt1
    :reader batt1
    :initarg :batt1
    :type cl:float
    :initform 0.0)
   (batt2
    :reader batt2
    :initarg :batt2
    :type cl:float
    :initform 0.0)
   (batt3
    :reader batt3
    :initarg :batt3
    :type cl:float
    :initform 0.0)
   (batt
    :reader batt
    :initarg :batt
    :type cl:integer
    :initform 0))
)

(cl:defclass Battery_level (<Battery_level>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Battery_level>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Battery_level)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<Battery_level> is deprecated: use rover_msgs-msg:Battery_level instead.")))

(cl:ensure-generic-function 'batt1-val :lambda-list '(m))
(cl:defmethod batt1-val ((m <Battery_level>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:batt1-val is deprecated.  Use rover_msgs-msg:batt1 instead.")
  (batt1 m))

(cl:ensure-generic-function 'batt2-val :lambda-list '(m))
(cl:defmethod batt2-val ((m <Battery_level>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:batt2-val is deprecated.  Use rover_msgs-msg:batt2 instead.")
  (batt2 m))

(cl:ensure-generic-function 'batt3-val :lambda-list '(m))
(cl:defmethod batt3-val ((m <Battery_level>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:batt3-val is deprecated.  Use rover_msgs-msg:batt3 instead.")
  (batt3 m))

(cl:ensure-generic-function 'batt-val :lambda-list '(m))
(cl:defmethod batt-val ((m <Battery_level>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:batt-val is deprecated.  Use rover_msgs-msg:batt instead.")
  (batt m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Battery_level>) ostream)
  "Serializes a message object of type '<Battery_level>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'batt1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'batt2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'batt3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'batt)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Battery_level>) istream)
  "Deserializes a message object of type '<Battery_level>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'batt1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'batt2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'batt3) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'batt) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Battery_level>)))
  "Returns string type for a message object of type '<Battery_level>"
  "rover_msgs/Battery_level")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Battery_level)))
  "Returns string type for a message object of type 'Battery_level"
  "rover_msgs/Battery_level")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Battery_level>)))
  "Returns md5sum for a message object of type '<Battery_level>"
  "193ae58d2bb8491f232609244038c21e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Battery_level)))
  "Returns md5sum for a message object of type 'Battery_level"
  "193ae58d2bb8491f232609244038c21e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Battery_level>)))
  "Returns full string definition for message of type '<Battery_level>"
  (cl:format cl:nil "float64 batt1~%float64 batt2~%float64 batt3~%int32 batt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Battery_level)))
  "Returns full string definition for message of type 'Battery_level"
  (cl:format cl:nil "float64 batt1~%float64 batt2~%float64 batt3~%int32 batt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Battery_level>))
  (cl:+ 0
     8
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Battery_level>))
  "Converts a ROS message object to a list"
  (cl:list 'Battery_level
    (cl:cons ':batt1 (batt1 msg))
    (cl:cons ':batt2 (batt2 msg))
    (cl:cons ':batt3 (batt3 msg))
    (cl:cons ':batt (batt msg))
))
