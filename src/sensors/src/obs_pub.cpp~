#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <cmath>

#define PI 3.14159
#define R 6371

double lat_init,logg_init,dist_init;
double lat_dest,logg_dest;
double lat,logg,brng,dist,brng_cur,decl;
int service,status;
int countR,countL,dir;

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	int size = msg->ranges.size();

	countL=0;
	countR=0;
	int i,j;
	for(i = -3; i < size/2; i++)
	{
		for (j=i; j<i+11; j++)
		{
			if(msg->ranges[j]>=1)
			{
				countR++;	
			}
 			if(msg->ranges[size-j]>=1)
			{
  				countL++;
 			}	
		}
		if (countR>=4 && countL<=4)
		{
			dir = (-j+5);
			break;		
  		}
  		else if(countR<=4 && countL>=4)
		{
			dir = (j-5);
			break;
  		}
  		else if(countR>=4 && countL>=4)
		{
			dir = (j-5);
			break;
  		}
		
		countL=0;	
		countR=0;		
	}
}


int main(int argc,char **argv){
	ros::init(argc,argv,"obs");
	ros::NodeHandle n;
	ros::Subscriber obs_sub = n.subscribe("/scan",1000,laserCallback);
	ros::Rate loop_rate(5);

	while(ros::ok()){
	ros::spinOnce();

	ROS_INFO("%i",dir);
	ROS_INFO_STREAM("Hello " << "World");
	loop_rate.sleep();

	}
	
	ros::spin();
	return 0 ;
}

