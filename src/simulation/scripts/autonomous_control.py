#!/usr/bin/env python
import rospy
import math
import os
import time
from rover_msgs.msg import WheelVelocity
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from rover_msgs,msg import GPS

rover_six_wheel_vel = []
sim_wheel_vel = []
destination_gps1 = {'x':0,'y':5,'z':5}

class AutonomousLocomotion:
    def __init__(self):
        rospy.init_node('AutonomousLocomotion', anonymous = True)

    def gpsCallback(self, data):
    	self.inst_x = data.inst_x
    	self.inst_y = data.inst_y
    	self.inst_z = data.inst_z
    	self.inst_speed = data.inst_speed
    	rospy.loginfo("X %s\t" % inst_x +"Y %s \t" % inst_y + "Z %s\t" % inst_z + "Speed %s" % inst_speed)

    def start(self):
    	sim_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size = 10)
    	rover_vel_pub = rospy.Publisher('rover1/wheel_vel', WheelVelocity, queue_size = 10)
        gps_sub = rospy.Subscriber('rover1/gps', GPS, self.gpsCallback)
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            rover_vel_pub.publish(rover_six_wheel_vel)
            sim_vel_pub.publish(sim_wheel_vel)
            rate.sleep()

	while rospy.is_shutdown():
	    exit()	
if __name__ == '__main__':
    try:
        autoLocomotion = AutonomousLocomotion()
        autoLocomotion.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
