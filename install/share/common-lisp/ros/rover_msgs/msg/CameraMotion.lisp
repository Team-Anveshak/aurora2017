; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude CameraMotion.msg.html

(cl:defclass <CameraMotion> (roslisp-msg-protocol:ros-message)
  ((X_button
    :reader X_button
    :initarg :X_button
    :type cl:integer
    :initform 0)
   (B_button
    :reader B_button
    :initarg :B_button
    :type cl:integer
    :initform 0)
   (Y_button
    :reader Y_button
    :initarg :Y_button
    :type cl:integer
    :initform 0)
   (A_button
    :reader A_button
    :initarg :A_button
    :type cl:integer
    :initform 0))
)

(cl:defclass CameraMotion (<CameraMotion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CameraMotion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CameraMotion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<CameraMotion> is deprecated: use rover_msgs-msg:CameraMotion instead.")))

(cl:ensure-generic-function 'X_button-val :lambda-list '(m))
(cl:defmethod X_button-val ((m <CameraMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:X_button-val is deprecated.  Use rover_msgs-msg:X_button instead.")
  (X_button m))

(cl:ensure-generic-function 'B_button-val :lambda-list '(m))
(cl:defmethod B_button-val ((m <CameraMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:B_button-val is deprecated.  Use rover_msgs-msg:B_button instead.")
  (B_button m))

(cl:ensure-generic-function 'Y_button-val :lambda-list '(m))
(cl:defmethod Y_button-val ((m <CameraMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:Y_button-val is deprecated.  Use rover_msgs-msg:Y_button instead.")
  (Y_button m))

(cl:ensure-generic-function 'A_button-val :lambda-list '(m))
(cl:defmethod A_button-val ((m <CameraMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:A_button-val is deprecated.  Use rover_msgs-msg:A_button instead.")
  (A_button m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CameraMotion>) ostream)
  "Serializes a message object of type '<CameraMotion>"
  (cl:let* ((signed (cl:slot-value msg 'X_button)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'B_button)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Y_button)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'A_button)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CameraMotion>) istream)
  "Deserializes a message object of type '<CameraMotion>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'X_button) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'B_button) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Y_button) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'A_button) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CameraMotion>)))
  "Returns string type for a message object of type '<CameraMotion>"
  "rover_msgs/CameraMotion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CameraMotion)))
  "Returns string type for a message object of type 'CameraMotion"
  "rover_msgs/CameraMotion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CameraMotion>)))
  "Returns md5sum for a message object of type '<CameraMotion>"
  "88cb68eb53c6c53209c17372919da333")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CameraMotion)))
  "Returns md5sum for a message object of type 'CameraMotion"
  "88cb68eb53c6c53209c17372919da333")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CameraMotion>)))
  "Returns full string definition for message of type '<CameraMotion>"
  (cl:format cl:nil "int32 X_button~%int32 B_button~%int32 Y_button~%int32 A_button~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CameraMotion)))
  "Returns full string definition for message of type 'CameraMotion"
  (cl:format cl:nil "int32 X_button~%int32 B_button~%int32 Y_button~%int32 A_button~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CameraMotion>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CameraMotion>))
  "Converts a ROS message object to a list"
  (cl:list 'CameraMotion
    (cl:cons ':X_button (X_button msg))
    (cl:cons ':B_button (B_button msg))
    (cl:cons ':Y_button (Y_button msg))
    (cl:cons ':A_button (A_button msg))
))
