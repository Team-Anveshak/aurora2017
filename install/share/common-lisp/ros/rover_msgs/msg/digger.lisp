; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude digger.msg.html

(cl:defclass <digger> (roslisp-msg-protocol:ros-message)
  ((Step_UD_dir
    :reader Step_UD_dir
    :initarg :Step_UD_dir
    :type cl:fixnum
    :initform 0)
   (Step_UD_step
    :reader Step_UD_step
    :initarg :Step_UD_step
    :type cl:fixnum
    :initform 0)
   (LR_dir
    :reader LR_dir
    :initarg :LR_dir
    :type cl:fixnum
    :initform 0)
   (LR_step
    :reader LR_step
    :initarg :LR_step
    :type cl:fixnum
    :initform 0)
   (probe_dir
    :reader probe_dir
    :initarg :probe_dir
    :type cl:fixnum
    :initform 0)
   (probe_step
    :reader probe_step
    :initarg :probe_step
    :type cl:fixnum
    :initform 0)
   (sensor_flag
    :reader sensor_flag
    :initarg :sensor_flag
    :type cl:fixnum
    :initform 0)
   (drill
    :reader drill
    :initarg :drill
    :type cl:fixnum
    :initform 0)
   (reset_flag
    :reader reset_flag
    :initarg :reset_flag
    :type cl:fixnum
    :initform 0))
)

(cl:defclass digger (<digger>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <digger>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'digger)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<digger> is deprecated: use rover_msgs-msg:digger instead.")))

(cl:ensure-generic-function 'Step_UD_dir-val :lambda-list '(m))
(cl:defmethod Step_UD_dir-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:Step_UD_dir-val is deprecated.  Use rover_msgs-msg:Step_UD_dir instead.")
  (Step_UD_dir m))

(cl:ensure-generic-function 'Step_UD_step-val :lambda-list '(m))
(cl:defmethod Step_UD_step-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:Step_UD_step-val is deprecated.  Use rover_msgs-msg:Step_UD_step instead.")
  (Step_UD_step m))

(cl:ensure-generic-function 'LR_dir-val :lambda-list '(m))
(cl:defmethod LR_dir-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:LR_dir-val is deprecated.  Use rover_msgs-msg:LR_dir instead.")
  (LR_dir m))

(cl:ensure-generic-function 'LR_step-val :lambda-list '(m))
(cl:defmethod LR_step-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:LR_step-val is deprecated.  Use rover_msgs-msg:LR_step instead.")
  (LR_step m))

(cl:ensure-generic-function 'probe_dir-val :lambda-list '(m))
(cl:defmethod probe_dir-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:probe_dir-val is deprecated.  Use rover_msgs-msg:probe_dir instead.")
  (probe_dir m))

(cl:ensure-generic-function 'probe_step-val :lambda-list '(m))
(cl:defmethod probe_step-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:probe_step-val is deprecated.  Use rover_msgs-msg:probe_step instead.")
  (probe_step m))

(cl:ensure-generic-function 'sensor_flag-val :lambda-list '(m))
(cl:defmethod sensor_flag-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:sensor_flag-val is deprecated.  Use rover_msgs-msg:sensor_flag instead.")
  (sensor_flag m))

(cl:ensure-generic-function 'drill-val :lambda-list '(m))
(cl:defmethod drill-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:drill-val is deprecated.  Use rover_msgs-msg:drill instead.")
  (drill m))

(cl:ensure-generic-function 'reset_flag-val :lambda-list '(m))
(cl:defmethod reset_flag-val ((m <digger>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:reset_flag-val is deprecated.  Use rover_msgs-msg:reset_flag instead.")
  (reset_flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <digger>) ostream)
  "Serializes a message object of type '<digger>"
  (cl:let* ((signed (cl:slot-value msg 'Step_UD_dir)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Step_UD_step)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'LR_dir)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'LR_step)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'probe_dir)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'probe_step)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'sensor_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'drill)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'reset_flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <digger>) istream)
  "Deserializes a message object of type '<digger>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Step_UD_dir) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Step_UD_step) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'LR_dir) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'LR_step) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'probe_dir) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'probe_step) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sensor_flag) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'drill) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reset_flag) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<digger>)))
  "Returns string type for a message object of type '<digger>"
  "rover_msgs/digger")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'digger)))
  "Returns string type for a message object of type 'digger"
  "rover_msgs/digger")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<digger>)))
  "Returns md5sum for a message object of type '<digger>"
  "a7cf0473c0894e95cbc4f5151b34a89d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'digger)))
  "Returns md5sum for a message object of type 'digger"
  "a7cf0473c0894e95cbc4f5151b34a89d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<digger>)))
  "Returns full string definition for message of type '<digger>"
  (cl:format cl:nil "int16 Step_UD_dir ~%int16 Step_UD_step ~%int16 LR_dir~%int16 LR_step ~%int16 probe_dir ~%int16 probe_step~%int16 sensor_flag~%int16 drill~%int16 reset_flag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'digger)))
  "Returns full string definition for message of type 'digger"
  (cl:format cl:nil "int16 Step_UD_dir ~%int16 Step_UD_step ~%int16 LR_dir~%int16 LR_step ~%int16 probe_dir ~%int16 probe_step~%int16 sensor_flag~%int16 drill~%int16 reset_flag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <digger>))
  (cl:+ 0
     2
     2
     2
     2
     2
     2
     2
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <digger>))
  "Converts a ROS message object to a list"
  (cl:list 'digger
    (cl:cons ':Step_UD_dir (Step_UD_dir msg))
    (cl:cons ':Step_UD_step (Step_UD_step msg))
    (cl:cons ':LR_dir (LR_dir msg))
    (cl:cons ':LR_step (LR_step msg))
    (cl:cons ':probe_dir (probe_dir msg))
    (cl:cons ':probe_step (probe_step msg))
    (cl:cons ':sensor_flag (sensor_flag msg))
    (cl:cons ':drill (drill msg))
    (cl:cons ':reset_flag (reset_flag msg))
))
