#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/LaserScan.h>
#include <rover_msgs/WheelVelocity.h>
#include <cstdlib>
#include <cmath>
#include <time.h>

time_t start, end;

int countR,countL,dir;



void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	int size = msg->ranges.size();

	countL=0;
	countR=0;
	int i,j;
	for(i = -13; i < size; i++)
	{
		for (j=i; j<i+26; j++)
		{
			if(msg->ranges[j]>=5)
			{
				countR++;	
			}
 			/*if(msg->ranges[size-j]>=2)
			{
  				countL++;
 			}*/	
		}
		
		if (countR>=22)
		{
			dir = (j-12);
			break;		
  		}
/*  		else if(countR<=22 && countL>=22)
		{
			dir = (j-10);
			break;
  		}
  		else if(countR>=22 && countL>=22)
		{
			dir = (j-10);
			break;
  		}
		*/
		//countL=0;	
		countR=0;		
	}
}


int main(int argc,char **argv){
	ros::init(argc,argv,"obs");
	ros::NodeHandle n;
	ros::Subscriber obs_sub = n.subscribe("/scan",1000,laserCallback);
	ros::Publisher vel_pub = n.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
	ros::Rate loop_rate(5);

	int mode = 0;

	while(ros::ok()){
	ros::spinOnce();

	rover_msgs::WheelVelocity vel;

	ROS_INFO("%i",dir);
	ROS_INFO_STREAM("Hello " << "World");
	
	if(dir>25 || dir<-25){
			mode=1;
			if(dir>25){
				vel.left = 50;
    	 	   	vel.right = -50;
        		
			}
			else{
				vel.left = -50;
        		vel.right = 50;
        		
			}			
		}
		else{
			vel.left = 50;
        	vel.right = 50;
        	
        	vel_pub.publish(vel);	
			time(&start);
			time(&end);
        	while((difftime(end,start) < 1))
			{
       		time(&end);
        	//ROS_INFO("%f\n",difftime(end,start));
        	}
        	mode=0;
		}
		vel_pub.publish(vel);
		loop_rate.sleep();
	}
	
	ros::spin();
	return 0 ;
}

