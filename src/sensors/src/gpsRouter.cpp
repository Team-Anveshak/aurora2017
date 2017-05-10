#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <rover_msgs/RouterAngle.h>
#include <cstdlib>
#include <cmath>

#define PI 3.14159

double lat_initR = 12.99178849*PI/180,logg_initR = 80.2310192*PI/180, dist_init;
double lat_initB = 12.99978849*PI/180,logg_initB = 80.2910192*PI/180;
double lat,logg;
double dist,dist_diff;
double theta,phi; //phi to be hard coded (initial angle)

void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg){
	lat = (msg->latitude)*PI/180;
	logg = (msg->longitude)*PI/180;
	dist = (sqrt((lat_initR-lat)*(lat_initR-lat)*100 + (logg_initR-logg)*(logg_initR-logg)*100))/10.0;
	dist_diff = (sqrt((lat_initB-lat)*(lat_initB-lat)*100 + (logg_initB-logg)*(logg_initB-logg)*100))/10.0;
	theta =	(dist*dist + dist_init*dist_init - dist_diff*dist_diff)/(2*dist*dist_init);
}

int main(int argc,char **argv){
	ros::init(argc,argv,"gps");
	ros::NodeHandle n;

	ros::Subscriber gps_sub = n.subscribe("/phone1/android/fix",50,gpsCallback);
	ros::Publisher angle_pub = n.advertise<rover_msgs::RouterAngle>("/rover1/angle",50);
	ros::Rate loop_rate(5);	
	dist_init=sqrt((lat_initB-lat_initR)*(lat_initB-lat_initR)*100 + (logg_initB-logg_initR)*(logg_initB-logg_initR)*100)/10.0;

	while(ros::ok()){
		ros::spinOnce();
		rover_msgs::RouterAngle Angle;
		if(theta>phi){
			Angle.angle = theta-phi;
		}
		else{
			Angle.angle = theta-phi;
		}
		ROS_INFO("%lf",theta-phi);
	
		angle_pub.publish(Angle);
		loop_rate.sleep();		
	}
	ros::spin();
	return 0 ;
}

