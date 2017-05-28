; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude Enc.msg.html

(cl:defclass <Enc> (roslisp-msg-protocol:ros-message)
  ((rpm_enc_1
    :reader rpm_enc_1
    :initarg :rpm_enc_1
    :type cl:float
    :initform 0.0)
   (rpm_enc_2
    :reader rpm_enc_2
    :initarg :rpm_enc_2
    :type cl:float
    :initform 0.0))
)

(cl:defclass Enc (<Enc>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Enc>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Enc)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<Enc> is deprecated: use rover_msgs-msg:Enc instead.")))

(cl:ensure-generic-function 'rpm_enc_1-val :lambda-list '(m))
(cl:defmethod rpm_enc_1-val ((m <Enc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:rpm_enc_1-val is deprecated.  Use rover_msgs-msg:rpm_enc_1 instead.")
  (rpm_enc_1 m))

(cl:ensure-generic-function 'rpm_enc_2-val :lambda-list '(m))
(cl:defmethod rpm_enc_2-val ((m <Enc>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:rpm_enc_2-val is deprecated.  Use rover_msgs-msg:rpm_enc_2 instead.")
  (rpm_enc_2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Enc>) ostream)
  "Serializes a message object of type '<Enc>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'rpm_enc_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'rpm_enc_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Enc>) istream)
  "Deserializes a message object of type '<Enc>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rpm_enc_1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rpm_enc_2) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Enc>)))
  "Returns string type for a message object of type '<Enc>"
  "rover_msgs/Enc")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Enc)))
  "Returns string type for a message object of type 'Enc"
  "rover_msgs/Enc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Enc>)))
  "Returns md5sum for a message object of type '<Enc>"
  "7fc26589b8f906330b9bf64006152365")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Enc)))
  "Returns md5sum for a message object of type 'Enc"
  "7fc26589b8f906330b9bf64006152365")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Enc>)))
  "Returns full string definition for message of type '<Enc>"
  (cl:format cl:nil "float64 rpm_enc_1~%float64 rpm_enc_2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Enc)))
  "Returns full string definition for message of type 'Enc"
  (cl:format cl:nil "float64 rpm_enc_1~%float64 rpm_enc_2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Enc>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Enc>))
  "Converts a ROS message object to a list"
  (cl:list 'Enc
    (cl:cons ':rpm_enc_1 (rpm_enc_1 msg))
    (cl:cons ':rpm_enc_2 (rpm_enc_2 msg))
))
