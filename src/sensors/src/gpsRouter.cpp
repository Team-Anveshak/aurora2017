#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <rover_msgs/RouterAngle.h>
#include <cstdlib>
#include <cmath>
#include <time.h>

#define PI 3.14159

time_t start, end;

double lat_initR = 12.99178849*PI/180,logg_initR = 80.2310192*PI/180; //intial coordinates of router i.e. base station
double lat,logg; //gps coordinates of rover time dependent
double phi,theta; //initial angle wrt geographic north
 
void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg){
	lat = (msg->latitude)*PI/180;
	logg = (msg->longitude)*PI/180;
	theta = atan2((sin(logg_initR - logg))*(cos(lat_initR)),(cos(lat))*(sin(lat_initR))-(sin(lat))*(cos(lat_initR)*(cos(logg_initR-logg))));
	if(theta<0) theta = theta + 2*PI;
}

int main(int argc,char **argv){
	ros::init(argc,argv,"gps");
	ros::NodeHandle n;

	//ros::Subscriber gps_router = n.subscribe("/phone1/android/fix",50,gpsCallback);
	ros::Publisher angle_pub = n.advertise<rover_msgs::RouterAngle>("/rover1/routerAngle",50);
	ros::Rate loop_rate(5);	

	while(ros::ok()){
		ros::spinOnce();
		rover_msgs::RouterAngle Angle;
		Angle.angle = (theta*180/PI-phi)/2;
		ROS_INFO("%f\n",Angle.angle);
		time(&start);
		time(&end);
		while((difftime(end,start) < 10))
		{
       	time(&end);
        }
		angle_pub.publish(Angle);
		loop_rate.sleep();		
	}
	ros::spin();
	return 0 ;
}

