#!/usr/bin/env python
import rospy
import math
import os
import time
import calculations
from rover_msgs.msg import WheelVelocity
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist
from rover_msgs,msg import GPS

rover_six_wheel_vel = []
sim_wheel_vel = []
destination_gps1 = {'lng':0,'lat':5}

class AutonomousLocomotion:
    def __init__(self):
        rospy.init_node('AutonomousLocomotion', anonymous = True)

    def gpsCallback(self, data):
    	inst_lgn = data.inst_x
    	inst_lat = data.inst_y
        position_vector(inst_lat, inst_lng)
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

    def position_vector(lat, lng):
        current = calculations.xyz(lat, lng)
        location1 = calculations.xyz(destination_gps1.lat, destination_gps1.lng)
        d = calculations.distance(current, location1)
        angle_magnetic_north = calculations.great_circle_angle(current, location1, calculations.magnetic_northpole)
        
		
if __name__ == '__main__':
    try:
        autoLocomotion = AutonomousLocomotion()
        autoLocomotion.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
