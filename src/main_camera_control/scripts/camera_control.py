#!/usr/bin/env python
import rospy
import math
import os
import sys
import webbrowser
import time
from sensor_msgs.msg import Joy
from rover_msgs.msg import CameraMotion

PI = 3.14159
motion_value = CameraMotion()


##  To control yaw pitch motion of camera
# 	@joy_sub- joy node subscriber
#	@data - is the array of the joystick values

class CameraControl:
    def __init__(self):
        rospy.init_node('CameraControl', anonymous = True)
    #    self.topic = rospy.get_param('~camera_control', 'rover1/camera_dir')

    ## @joyCallback callback function for joy subscriber
    #      @x_axis_value- x axis position of joystick controller
    #	   @y_axis_value- y axis position of joystick controller
    #	   @scale- magnitude of a vector, lies between (0, 5)
    #	   @angle- horizontal plane angle made by controller
    #    left_value = data.buttons[2]
    #    right_value = data.buttons[1]
    #    up_value = data.buttons[3]
    #    down_value = data.buttons[0]

 
    def joyCallback(self, data):
        motion_value.data=[1,1,1,1]
        rospy.loginfo("Left %s\t" % data.buttons[2] +"Rigth %s \t" % data.buttons[1] + "Up %s\t" % data.buttons[3] + "Down %s" % data.buttons[0])



    ##  @start starts to publish the values to 'rover1/camera_dir' topic
    #	    @cam_pub- is   publisher variable
    #	    @rate- publishing rate in Hz      

    def start(self):
        cam_pub = rospy.Publisher('rover1/camera_dir', CameraMotion, queue_size = 10)
        joy_sub = rospy.Subscriber('joy', Joy, self.joyCallback)
        rate = rospy.Rate(10)
        #print motion_value
        if not rospy.is_shutdown():
            #rospy.loginfo("camera motion values publishing %s" % rospy.get_time())
            cam_pub.publish(motion_value)
            rospy.loginfo("Left")
            ##chrome_path = '/usr/bin/firefox %s'
            #os.system("sudo motion")
            #time.sleep(0.5)
            ##url = 'http://localhost:8081'
            rospy.loginfo("camera started %s" % rospy.get_time())
            ##webbrowser.get(chrome_path).open(url)
            ##flag= 1
            rate.sleep()

	if rospy.is_shutdown():
	    #os.system("sudo killall motion")
	    ##webbrowser.close()
	    exit()	
if __name__ == '__main__':
    try:
        camControl = CameraControl()
        camControl.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
