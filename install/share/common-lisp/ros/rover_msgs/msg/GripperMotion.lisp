; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude GripperMotion.msg.html

(cl:defclass <GripperMotion> (roslisp-msg-protocol:ros-message)
  ((button_1
    :reader button_1
    :initarg :button_1
    :type cl:boolean
    :initform cl:nil)
   (button_2
    :reader button_2
    :initarg :button_2
    :type cl:boolean
    :initform cl:nil)
   (button_3
    :reader button_3
    :initarg :button_3
    :type cl:boolean
    :initform cl:nil)
   (button_4
    :reader button_4
    :initarg :button_4
    :type cl:boolean
    :initform cl:nil)
   (button_5
    :reader button_5
    :initarg :button_5
    :type cl:boolean
    :initform cl:nil)
   (button_6
    :reader button_6
    :initarg :button_6
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass GripperMotion (<GripperMotion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GripperMotion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GripperMotion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name rover_msgs-msg:<GripperMotion> is deprecated: use rover_msgs-msg:GripperMotion instead.")))

(cl:ensure-generic-function 'button_1-val :lambda-list '(m))
(cl:defmethod button_1-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_1-val is deprecated.  Use rover_msgs-msg:button_1 instead.")
  (button_1 m))

(cl:ensure-generic-function 'button_2-val :lambda-list '(m))
(cl:defmethod button_2-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_2-val is deprecated.  Use rover_msgs-msg:button_2 instead.")
  (button_2 m))

(cl:ensure-generic-function 'button_3-val :lambda-list '(m))
(cl:defmethod button_3-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_3-val is deprecated.  Use rover_msgs-msg:button_3 instead.")
  (button_3 m))

(cl:ensure-generic-function 'button_4-val :lambda-list '(m))
(cl:defmethod button_4-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_4-val is deprecated.  Use rover_msgs-msg:button_4 instead.")
  (button_4 m))

(cl:ensure-generic-function 'button_5-val :lambda-list '(m))
(cl:defmethod button_5-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_5-val is deprecated.  Use rover_msgs-msg:button_5 instead.")
  (button_5 m))

(cl:ensure-generic-function 'button_6-val :lambda-list '(m))
(cl:defmethod button_6-val ((m <GripperMotion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader rover_msgs-msg:button_6-val is deprecated.  Use rover_msgs-msg:button_6 instead.")
  (button_6 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GripperMotion>) ostream)
  "Serializes a message object of type '<GripperMotion>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_1) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_2) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_3) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_4) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_5) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'button_6) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GripperMotion>) istream)
  "Deserializes a message object of type '<GripperMotion>"
    (cl:setf (cl:slot-value msg 'button_1) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'button_2) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'button_3) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'button_4) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'button_5) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'button_6) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GripperMotion>)))
  "Returns string type for a message object of type '<GripperMotion>"
  "rover_msgs/GripperMotion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GripperMotion)))
  "Returns string type for a message object of type 'GripperMotion"
  "rover_msgs/GripperMotion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GripperMotion>)))
  "Returns md5sum for a message object of type '<GripperMotion>"
  "8edaeaec64be0c5d3ae535eef1f2c3ef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GripperMotion)))
  "Returns md5sum for a message object of type 'GripperMotion"
  "8edaeaec64be0c5d3ae535eef1f2c3ef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GripperMotion>)))
  "Returns full string definition for message of type '<GripperMotion>"
  (cl:format cl:nil "bool button_1~%bool button_2~%bool button_3~%bool button_4~%bool button_5~%bool button_6~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GripperMotion)))
  "Returns full string definition for message of type 'GripperMotion"
  (cl:format cl:nil "bool button_1~%bool button_2~%bool button_3~%bool button_4~%bool button_5~%bool button_6~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GripperMotion>))
  (cl:+ 0
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GripperMotion>))
  "Converts a ROS message object to a list"
  (cl:list 'GripperMotion
    (cl:cons ':button_1 (button_1 msg))
    (cl:cons ':button_2 (button_2 msg))
    (cl:cons ':button_3 (button_3 msg))
    (cl:cons ':button_4 (button_4 msg))
    (cl:cons ':button_5 (button_5 msg))
    (cl:cons ':button_6 (button_6 msg))
))
