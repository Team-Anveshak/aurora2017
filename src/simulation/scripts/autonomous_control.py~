#!/usr/bin/env python
import rospy
import math
import os
import time
import tf
import calculations
from rover_msgs.msg import WheelVelocity, GPS
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3

rover_six_wheel_vel = WheelVelocity()
sim_wheel_vel = Twist()
destination_gps1 = {'lng':0,'lat':5}
starting_point = {'lng':5,'lat':5}
vx, vy, vth = 0.1, -0.1, 0.1

class AutonomousLocomotion:
    def __init__(self):
        rospy.init_node('AutonomousLocomotion', anonymous = True)
        self.start = calculations.xyz(starting_point['lat'], starting_point['lng'])
        self.location1 = calculations.xyz(destination_gps1['lat'], destination_gps1['lng'])

    def gpsCallback(self, data):
    	inst_lng = data.inst_lng
    	inst_lat = data.inst_lat
        position_vector(inst_lat, inst_lng)
        self.start = self.current
    	rospy.loginfo("c_lat %s\t" % inst_lat +"c_lng %s \t" % inst_lng)

    def start(self):
    	sim_vel_pub = rospy.Publisher('cmd_vel', Twist, queue_size = 10)
    	rover_vel_pub = rospy.Publisher('rover1/wheel_vel', WheelVelocity, queue_size = 10)
        self.odom_pub = rospy.Publisher('rover1/odom', Odometry, queue_size = 10)#change topic name to odom if needed
        gps_sub = rospy.Subscriber('rover1/gps', GPS, self.gpsCallback)
        self.odom = Odometry()
        self.odom.header.stamp = rospy.Time.now()
        self.odom.header.frame_id = "odom"
        # imu_sub = 
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            rover_vel_pub.publish(rover_six_wheel_vel)
            sim_vel_pub.publish(sim_wheel_vel)
            rate.sleep()
        while rospy.is_shutdown():
            exit()

    def position_vector(lat, lng, self):
        self.current = calculations.xyz(lat, lng)
        d = calculations.distance(current, location1)
        angle_magnetic_north_sc = calculations.great_circle_angle(starting_point, current, calculations.magnetic_northpole)
        angle_magnetic_north_cdest1 = calculations.great_circle_angle(current, location1, calculations.magnetic_northpole)
        # set the position
        self.odom.pose.pose = Pose(Point(current[0], current[1], current[2]), Quaternion(0.0, 0.0, 0.0, 1.0))
        self.odom.pose.covariance = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
        # set the velocity
        self.odom.child_frame_id = "base_link"
        self.odom.twist.twist = Twist(Vector3(vx, vy, 0), Vector3(0, 0, vth))
        self.odom.twist.covariance = [[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 0]]
        self.odom_pub.publish()
		
if __name__ == '__main__':
    try:
        autoLocomotion = AutonomousLocomotion()
        autoLocomotion.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
