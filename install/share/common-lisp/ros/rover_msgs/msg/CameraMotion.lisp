; Auto-generated. Do not edit!


(cl:in-package rover_msgs-msg)


;//! \htmlinclude CameraMotion.msg.html

(cl:defclass <CameraMotion> (roslisp-msg-protocol:ros-message)
  ((X_button
    :reader X_button
    :initarg :X_button
    :type cl:boolean
    :initform cl:nil)
   (B_button
    :reader B_button
    :initarg :B_button
    :type cl:boolean
    :initform cl:nil)
   (Y_button
    :reader Y_button
    :initarg :Y_button
    :type cl:boolean
    :initform cl:nil)
   (A_button
    :reader A_button
    :initarg :A_button
    :type cl:boolean
    :initform cl:nil))
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
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'X_button) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'B_button) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'Y_button) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'A_button) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CameraMotion>) istream)
  "Deserializes a message object of type '<CameraMotion>"
    (cl:setf (cl:slot-value msg 'X_button) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'B_button) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'Y_button) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'A_button) (cl:not (cl:zerop (cl:read-byte istream))))
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
  "b767c6f7caee821455d285d718340233")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CameraMotion)))
  "Returns md5sum for a message object of type 'CameraMotion"
  "b767c6f7caee821455d285d718340233")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CameraMotion>)))
  "Returns full string definition for message of type '<CameraMotion>"
  (cl:format cl:nil "bool X_button~%bool B_button~%bool Y_button~%bool A_button~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CameraMotion)))
  "Returns full string definition for message of type 'CameraMotion"
  (cl:format cl:nil "bool X_button~%bool B_button~%bool Y_button~%bool A_button~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CameraMotion>))
  (cl:+ 0
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CameraMotion>))
  "Converts a ROS message object to a list"
  (cl:list 'CameraMotion
    (cl:cons ':X_button (X_button msg))
    (cl:cons ':B_button (B_button msg))
    (cl:cons ':Y_button (Y_button msg))
    (cl:cons ':A_button (A_button msg))
))
