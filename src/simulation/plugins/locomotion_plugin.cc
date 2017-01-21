#include <gazebo/gazebo.hh>
#include <gazebo/sensors/sensors.hh>
#include <rover_msgs/WheelVelocity.h>
#include <gazebo/math/gzmath.hh>
#include <sdf/sdf.hh> 
#include <ros/ros.h>
#define PI 3.14159
namespace gazebo{
	class locomotion_plugin:public locomotion
	{	
		ros::NodeHandle nh;
        ros::subscriber vel_pub;
        vel_sub = nh.subscribe<rover_msgs::WheelVelocity>("rover1/wheel_vel",10,&locomotion_pligin::velCallback,this);	
	};
	void locomotion_plugin::velCallback(const rover_msgs::WheelVelocity::constPtr& wheel_vel){
		ROS_INFO_STREAM("velocities"<< wheel_vel);
		
	}
	GZ_REGISTER_SENSOR_PLUGIN(locomotion_plugin);
};
