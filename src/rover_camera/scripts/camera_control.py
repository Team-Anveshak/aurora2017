#!/usr/bin/env python
import rospy
import math
from sensor_msgs.msg import Joy
from rover_msgs.msg import CameraMotion

PI = 3.14159

##  To control yaw pitch motion of camera
# 	@joy_sub- joy node subscriber
	

class CameraControl:
    def __init__(self):
	print "__init__"
        rospy.init_node('CameraControl', anonymous = True)
        self.joy_sub = rospy.Subscriber('joy', Joy, self.joyCallback)

## @joyCallback callback function for joy subscriber
#	@x_axis_value- x axis position of joystick controller
#	@y_axis_value- y axis position of joystick controller
#	@scale- magnitude of a vector, lies between (0, 5)
#	@angle- horizontal plane angle made by controller
 
    def joyCallback(self, data):
	print "joy callback"
        self.x_axis_value = data.axes[2]
        self.y_axis_value = data.axes[3]
        self.scale = 5 * math.sqrt(self.x_axis_value * self.x_axis_value + self.y_axis_value * self.y_axis_value)
        self.angle = matn.degrees(math.atan(self.y_axis_value/self.x_axis_value))
        rospy.loginfo("Scale %s" % scale + "Angle %s" % angle)


##  @start starts to publish the values to 'rover1/camera_dir' topic
#	@cam_pub- is   publisher variable
#	@rate- publishing rate in Hz      

    def start(self):
        self.cam_pub = rospy.Publisher('rover1/camera_dir', CameraMotion, queue_size = 10)
        self.rate = rospy.Rate(10)

        #CameraMotion.cam_yaw_scale
        #CameraMotion.cam_yaw_dir
        #CameraMotion.cam_pitch_scale
        #CameraMotion.cam_yaw_dir
        
        self.cam_pub.publish(CameraMotion)
        self.rate.sleep()

if __name__ == '__main__':
    try:
        camControl = CameraControl()
        camControl.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
