; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude MPU.msg.html

(cl:defclass <MPU> (roslisp-msg-protocol:ros-message)
  ((gyro_x
    :reader gyro_x
    :initarg :gyro_x
    :type cl:float
    :initform 0.0)
   (gyro_y
    :reader gyro_y
    :initarg :gyro_y
    :type cl:float
    :initform 0.0)
   (gyro_z
    :reader gyro_z
    :initarg :gyro_z
    :type cl:float
    :initform 0.0)
   (acc_x
    :reader acc_x
    :initarg :acc_x
    :type cl:float
    :initform 0.0)
   (acc_y
    :reader acc_y
    :initarg :acc_y
    :type cl:float
    :initform 0.0)
   (acc_z
    :reader acc_z
    :initarg :acc_z
    :type cl:float
    :initform 0.0))
)

(cl:defclass MPU (<MPU>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MPU>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MPU)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<MPU> is deprecated: use rover_msgs-msg:MPU instead.")))

(cl:ensure-generic-function 'gyro_x-val :lambda-list '(m))
(cl:defmethod gyro_x-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:gyro_x-val is deprecated.  Use rover_msgs-msg:gyro_x instead.")
  (gyro_x m))

(cl:ensure-generic-function 'gyro_y-val :lambda-list '(m))
(cl:defmethod gyro_y-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:gyro_y-val is deprecated.  Use rover_msgs-msg:gyro_y instead.")
  (gyro_y m))

(cl:ensure-generic-function 'gyro_z-val :lambda-list '(m))
(cl:defmethod gyro_z-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:gyro_z-val is deprecated.  Use rover_msgs-msg:gyro_z instead.")
  (gyro_z m))

(cl:ensure-generic-function 'acc_x-val :lambda-list '(m))
(cl:defmethod acc_x-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:acc_x-val is deprecated.  Use rover_msgs-msg:acc_x instead.")
  (acc_x m))

(cl:ensure-generic-function 'acc_y-val :lambda-list '(m))
(cl:defmethod acc_y-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:acc_y-val is deprecated.  Use rover_msgs-msg:acc_y instead.")
  (acc_y m))

(cl:ensure-generic-function 'acc_z-val :lambda-list '(m))
(cl:defmethod acc_z-val ((m <MPU>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:acc_z-val is deprecated.  Use rover_msgs-msg:acc_z instead.")
  (acc_z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MPU>) ostream)
  "Serializes a message object of type '<MPU>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gyro_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gyro_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gyro_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'acc_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MPU>) istream)
  "Deserializes a message object of type '<MPU>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gyro_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gyro_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gyro_z) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'acc_z) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MPU>)))
  "Returns string type for a message object of type '<MPU>"
  "rover_msgs/MPU")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MPU)))
  "Returns string type for a message object of type 'MPU"
  "rover_msgs/MPU")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MPU>)))
  "Returns md5sum for a message object of type '<MPU>"
  "2c0239ab8497dbf714abae1bc9165695")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MPU)))
  "Returns md5sum for a message object of type 'MPU"
  "2c0239ab8497dbf714abae1bc9165695")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MPU>)))
  "Returns full string definition for message of type '<MPU>"
  (cl:format cl:nil "float32 gyro_x~%float32 gyro_y~%float32 gyro_z~%float32 acc_x~%float32 acc_y~%float32 acc_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MPU)))
  "Returns full string definition for message of type 'MPU"
  (cl:format cl:nil "float32 gyro_x~%float32 gyro_y~%float32 gyro_z~%float32 acc_x~%float32 acc_y~%float32 acc_z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MPU>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MPU>))
  "Converts a ROS message object to a list"
  (cl:list 'MPU
    (cl:cons ':gyro_x (gyro_x msg))
    (cl:cons ':gyro_y (gyro_y msg))
    (cl:cons ':gyro_z (gyro_z msg))
    (cl:cons ':acc_x (acc_x msg))
    (cl:cons ':acc_y (acc_y msg))
    (cl:cons ':acc_z (acc_z msg))
))
