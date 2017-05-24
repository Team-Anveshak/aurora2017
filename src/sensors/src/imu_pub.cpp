#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

double orx,ory,orz,orw;
double angx,angy,angz;
double accx,accy,accz;

void gpsCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
	orx = msg-> orientation.x;
	ory = msg-> orientation.y;
	orz = msg-> orientation.z;
	orw = msg-> orientation.w;

	angx= msg-> angular_velocity.x;
	angy= msg-> angular_velocity.y;
	angz= msg-> angular_velocity.z;

	accx= msg-> linear_acceleration.x;
	accy= msg-> linear_acceleration.y;
	accz= msg-> linear_acceleration.z;	
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"imu");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("phone1/android/imu",1000,gpsCallback);
	ros::Publisher imu_pub = n.advertise<sensor_msgs::Imu>("imu/data",1000);
	//ros::Rate loop_rate(1);

while(ros::ok())
{

	
	sensor_msgs::Imu imu;
	
	imu.header.frame_id="imu_link";

	imu.orientation.x = orx;
	imu.orientation.y = ory;
	imu.orientation.z = orz;
	imu.orientation.w = orw;

	imu.angular_velocity.x = angx;
	imu.angular_velocity.y = angy;
	imu.angular_velocity.z = angz;

	imu.linear_acceleration.x = accx;
	imu.linear_acceleration.y = accy;
	imu.linear_acceleration.z = accz;

	ros::spinOnce();
	imu_pub.publish(imu);
	//loop_rate.sleep();
	
}
	ros::spin();
	return 0 ;
}

