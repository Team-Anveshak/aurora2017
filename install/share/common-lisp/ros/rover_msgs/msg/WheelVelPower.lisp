; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude WheelVelPower.msg.html

(cl:defclass <WheelVelPower> (roslisp-msg-protocol:ros-message)
  ((left_front_vel
    :reader left_front_vel
    :initarg :left_front_vel
    :type cl:float
    :initform 0.0)
   (right_front_vel
    :reader right_front_vel
    :initarg :right_front_vel
    :type cl:float
    :initform 0.0)
   (left_middle_vel
    :reader left_middle_vel
    :initarg :left_middle_vel
    :type cl:float
    :initform 0.0)
   (right_middle_vel
    :reader right_middle_vel
    :initarg :right_middle_vel
    :type cl:float
    :initform 0.0)
   (left_back_vel
    :reader left_back_vel
    :initarg :left_back_vel
    :type cl:float
    :initform 0.0)
   (right_back_vel
    :reader right_back_vel
    :initarg :right_back_vel
    :type cl:float
    :initform 0.0)
   (power_1
    :reader power_1
    :initarg :power_1
    :type cl:float
    :initform 0.0)
   (power_2
    :reader power_2
    :initarg :power_2
    :type cl:float
    :initform 0.0)
   (power_3
    :reader power_3
    :initarg :power_3
    :type cl:float
    :initform 0.0))
)

(cl:defclass WheelVelPower (<WheelVelPower>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <WheelVelPower>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'WheelVelPower)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<WheelVelPower> is deprecated: use rover_msgs-msg:WheelVelPower instead.")))

(cl:ensure-generic-function 'left_front_vel-val :lambda-list '(m))
(cl:defmethod left_front_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:left_front_vel-val is deprecated.  Use rover_msgs-msg:left_front_vel instead.")
  (left_front_vel m))

(cl:ensure-generic-function 'right_front_vel-val :lambda-list '(m))
(cl:defmethod right_front_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:right_front_vel-val is deprecated.  Use rover_msgs-msg:right_front_vel instead.")
  (right_front_vel m))

(cl:ensure-generic-function 'left_middle_vel-val :lambda-list '(m))
(cl:defmethod left_middle_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:left_middle_vel-val is deprecated.  Use rover_msgs-msg:left_middle_vel instead.")
  (left_middle_vel m))

(cl:ensure-generic-function 'right_middle_vel-val :lambda-list '(m))
(cl:defmethod right_middle_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:right_middle_vel-val is deprecated.  Use rover_msgs-msg:right_middle_vel instead.")
  (right_middle_vel m))

(cl:ensure-generic-function 'left_back_vel-val :lambda-list '(m))
(cl:defmethod left_back_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:left_back_vel-val is deprecated.  Use rover_msgs-msg:left_back_vel instead.")
  (left_back_vel m))

(cl:ensure-generic-function 'right_back_vel-val :lambda-list '(m))
(cl:defmethod right_back_vel-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:right_back_vel-val is deprecated.  Use rover_msgs-msg:right_back_vel instead.")
  (right_back_vel m))

(cl:ensure-generic-function 'power_1-val :lambda-list '(m))
(cl:defmethod power_1-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:power_1-val is deprecated.  Use rover_msgs-msg:power_1 instead.")
  (power_1 m))

(cl:ensure-generic-function 'power_2-val :lambda-list '(m))
(cl:defmethod power_2-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:power_2-val is deprecated.  Use rover_msgs-msg:power_2 instead.")
  (power_2 m))

(cl:ensure-generic-function 'power_3-val :lambda-list '(m))
(cl:defmethod power_3-val ((m <WheelVelPower>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:power_3-val is deprecated.  Use rover_msgs-msg:power_3 instead.")
  (power_3 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <WheelVelPower>) ostream)
  "Serializes a message object of type '<WheelVelPower>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_front_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_front_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_middle_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_middle_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'left_back_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'right_back_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'power_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'power_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'power_3))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <WheelVelPower>) istream)
  "Deserializes a message object of type '<WheelVelPower>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_front_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_front_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_middle_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_middle_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_back_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'right_back_vel) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'power_1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'power_2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'power_3) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<WheelVelPower>)))
  "Returns string type for a message object of type '<WheelVelPower>"
  "rover_msgs/WheelVelPower")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'WheelVelPower)))
  "Returns string type for a message object of type 'WheelVelPower"
  "rover_msgs/WheelVelPower")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<WheelVelPower>)))
  "Returns md5sum for a message object of type '<WheelVelPower>"
  "f13c06ab7a6186260b614a9e977d02cb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'WheelVelPower)))
  "Returns md5sum for a message object of type 'WheelVelPower"
  "f13c06ab7a6186260b614a9e977d02cb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<WheelVelPower>)))
  "Returns full string definition for message of type '<WheelVelPower>"
  (cl:format cl:nil "float64 left_front_vel~%float64 right_front_vel~%float64 left_middle_vel~%float64 right_middle_vel~%float64 left_back_vel~%float64 right_back_vel~%float64 power_1~%float64 power_2~%float64 power_3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'WheelVelPower)))
  "Returns full string definition for message of type 'WheelVelPower"
  (cl:format cl:nil "float64 left_front_vel~%float64 right_front_vel~%float64 left_middle_vel~%float64 right_middle_vel~%float64 left_back_vel~%float64 right_back_vel~%float64 power_1~%float64 power_2~%float64 power_3~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <WheelVelPower>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <WheelVelPower>))
  "Converts a ROS message object to a list"
  (cl:list 'WheelVelPower
    (cl:cons ':left_front_vel (left_front_vel msg))
    (cl:cons ':right_front_vel (right_front_vel msg))
    (cl:cons ':left_middle_vel (left_middle_vel msg))
    (cl:cons ':right_middle_vel (right_middle_vel msg))
    (cl:cons ':left_back_vel (left_back_vel msg))
    (cl:cons ':right_back_vel (right_back_vel msg))
    (cl:cons ':power_1 (power_1 msg))
    (cl:cons ':power_2 (power_2 msg))
    (cl:cons ':power_3 (power_3 msg))
))
