#include "ros/ros.h"
#include "sensor_msgs/NavSatFix.h"
int i;
float lat,logg;
float pc[9];
void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
  lat = msg->latitude;
  logg = msg->longitude;
	for(i=0;i<9;i++)
		pc[i]=msg->position_covariance[i];
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "GPS");   
  ros::NodeHandle n;   
  ros::Subscriber sub = n.subscribe("/phone1/android/fix", 100,gpsCallback);
  ros::Publisher gps_pub = n.advertise<sensor_msgs::NavSatFix>("gps/fix",100);
  ros::Rate loop_rate(10);   

  while (ros::ok())
  {
    ros::spinOnce();

    sensor_msgs::NavSatFix gps;
    
    gps.header.frame_id = "gps_link";
    gps.latitude = lat;
    gps.longitude=logg;	
		gps.position_covariance_type=1;
		for(i=0;i<9;i++)
			gps.position_covariance[i]=pc[i];

    gps_pub.publish(gps);
    
    loop_rate.sleep();

  }
  return 0;
}
