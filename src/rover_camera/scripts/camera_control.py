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
    #      @x_axis_value- x axis position of joystick controller
    #	   @y_axis_value- y axis position of joystick controller
    #	   @scale- magnitude of a vector, lies between (0, 5)
    #	   @angle- horizontal plane angle made by controller

 
    def joyCallback(self, data):
        self.left_value = data.buttons[2]
        self.right_value = data.buttons[1]
        self.up_value = data.buttons[3]
        self.down_value = data.buttons[0]
        rospy.loginfo("Left %s\t" % self.left_value +"Rigth %s \t" % self.right_value + "Up %s\t" % self.up_value + "Down %s" % self.down_value)



    ##  @start starts to publish the values to 'rover1/camera_dir' topic
    #	    @cam_pub- is   publisher variable
    #	    @rate- publishing rate in Hz      

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
