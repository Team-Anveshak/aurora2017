#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <ros/console.h>

  double x = 0.0;
  double y = 0.0;
  double th = 0.0;


  double vx;
  double vy;
  double vth;

void Callback(const geometry_msgs::Twist::ConstPtr& msg){
	vx = msg->linear.x;
	vy = msg->linear.y;
	vth = msg->angular.z;
}

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;

  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odometry", 1000);
  ros::Subscriber cmdvel;
   	
  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
  cmdvel = n.subscribe<geometry_msgs::Twist>("cmd_vel",1000,&Callback);
  
  //ros::Rate r(0.04);
  while(n.ok()){
    
    ros::spinOnce(); // check for incoming messages
    current_time = ros::Time::now();
    //ROS_INFO_STREAM("scale");


    //compute odometry in a typical way given the velocities of the robot
    double dt = (current_time - last_time).toSec();
    double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
    double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
    double delta_th = vth * dt;

    x += delta_x;
    y += delta_y;
    th += delta_th;

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.child_frame_id = "chassis";
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;

  }
}
