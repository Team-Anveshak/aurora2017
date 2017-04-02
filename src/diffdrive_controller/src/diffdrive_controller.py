#!/usr/bin/python
import rospy
import roslib

# Messages
from geometry_msgs.msg import Twist
from rover_msgs.msg import WheelVelocity

class CmdVelToDiffDriveMotors:
  def __init__(self):
    rospy.init_node('diffdrive_controller')
    self.cmdvel_sub = rospy.Subscriber('cmd_vel', Twist, self.twistCallback)
    # self.lwheel_tangent_vel_target_pub = rospy.Publisher('lwheel_tangent_vel_target', Float32, queue_size=10)
    self.vel_pub = rospy.Publisher('rover1/wheel_vel', WheelVelocity, queue_size=20)

    self.L = rospy.get_param('~robot_wheel_separation_distance', 0.64) 
    self.R = rospy.get_param('~robot_wheel_radius', 0.125)

    self.rate = rospy.get_param('~rate', 50)
    self.timeout_idle = rospy.get_param('~timeout_idle', 2)
    self.time_prev_update = rospy.Time.now()

    self.target_v = 0;
    self.target_w = 0;

  # When given no commands for some time, do not move
  def spin(self):
    rospy.loginfo("Start diffdrive_controller")
    rate = rospy.Rate(self.rate)
    time_curr_update = rospy.Time.now()
    
    rospy.on_shutdown(self.shutdown)

    while not rospy.is_shutdown():
      time_diff_update = (time_curr_update - self.time_prev_update).to_sec()
      if time_diff_update < self.timeout_idle: # Only move if command given recently
        self.update();
      rate.sleep()
    rospy.spin();

  def shutdown(self):
    rospy.loginfo("Stop diffdrive_controller")
  	# Stop message
    vel=WheelVelocity()
    vel.left_front_vel = 0
    vel.left_middle_vel = 0;
    vel.left_back_vel = 0
    vel.right_front_vel = 0
    vel.right_middle_vel = 0
    vel.right_back_vel = 0
    self.vel_pub.publish(vel)

    rospy.sleep(1)    

  def update(self):
    # Suppose we have a target velocity v and angular velocity w
    # Suppose we have a robot with wheel radius R and distance between wheels L
    # Let vr and vl be angular wheel velocity for right and left wheels, respectively
    # Relate 2v = R (vr +vl) because the forward speed is the sum of the combined wheel velocities
    # Relate Lw = R (vr - vl) because rotation is a function of counter-clockwise wheel speeds
    # Compute vr = (2v + wL) / 2R
    # Compute vl = (2v - wL) / 2R
    # vr = (2*self.target_v + self.target_w*self.L) / (2)
    # vl = (2*self.target_v - self.target_w*self.L) / (2)
    vel=WheelVelocity()

    vel.left_front_vel = (2*self.target_v - self.target_w*self.L) / (2*0.0125)
    vel.left_middle_vel = (2*self.target_v - self.target_w*self.L) / (2*0.0125)
    vel.left_back_vel = (2*self.target_v - self.target_w*self.L) / (2*0.0125)
    vel.right_front_vel = (2*self.target_v + self.target_w*self.L) / (2*0.0125)
    vel.right_middle_vel = (2*self.target_v + self.target_w*self.L) / (2*0.0125)
    vel.right_back_vel = (2*self.target_v + self.target_w*self.L) / (2*0.0125)

    # self.rwheel_tangent_vel_target_pub.publish(vr)
    # self.lwheel_tangent_vel_target_pub.publish(vl)
    self.vel_pub.publish(vel)

  def twistCallback(self,msg):
    self.target_v = msg.linear.x;
    self.target_w = msg.angular.z;
    self.time_prev_update = rospy.Time.now()


def main():
  cmdvel_to_motors = CmdVelToDiffDriveMotors();
  cmdvel_to_motors.spin()

if __name__ == '__main__':
  main(); 
