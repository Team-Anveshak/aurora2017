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
motion_value = [False, False, False, False]


class CameraControl:
    def __init__(self):
        rospy.init_node('CameraControl', anonymous = True)
 
    def joyCallback(self, data):
        motion_value[0] = data.buttons[2]
        motion_value[1] = data.buttons[1]
        motion_value[2] = data.buttons[3]
        motion_value[3] = data.buttons[0]
        rospy.loginfo("Left %s\t" % data.buttons[2] +"Rigth %s \t" % data.buttons[1] + "Up %s\t" % data.buttons[3] + "Down %s" % data.buttons[0])


    def start(self):
        cam_pub = rospy.Publisher('/rover1/camera_dir', CameraMotion, queue_size = 10)
        joy_sub = rospy.Subscriber('/joy', Joy, self.joyCallback)
        rate = rospy.Rate(10)
        cnt=0
        reset_flag=0
       
        while not rospy.is_shutdown():
        	

            if cnt==5 :
            	reset_flag=1
            	cnt=0

            cnt=cnt+1
            cam_pub.publish( motion_value[0], motion_value[1], motion_value[2], motion_value[3],reset_flag)
            reset_flag=0
	   
            rate.sleep()

    if rospy.is_shutdown():
        exit()    
if __name__ == '__main__':
    try:
        camControl = CameraControl()
        camControl.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
