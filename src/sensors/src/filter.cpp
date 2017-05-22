#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <rover_msgs/Laser.h>

float temp[15][400];
float scan[400];

int curr;
float add=0,count=0;

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{

int i=0,j=0,n=0;

	if (msg->header.seq - curr<11)
	{

		for (int i=0;i<360;i++)
		{
			temp[n][i] = msg->ranges[i];
		}

		n++ ;
	}
	

    else
    {
    for(i=0;i<360;i++)
    {
    	for(j=0;j<=n;j++)
    	{
    		if(temp[j][i]>0.0)
    		{
    			add=add+temp[j][i];
    			count++;
    		}
    	}
    	if(count==0) scan[i] =0;
    	else scan[i] = add/count;
    	
    	count=0;
    	add=0;
    }
     curr = msg->header.seq;
     n=0;
    }
    

}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"Scanner");
	ros::NodeHandle n;
	ros::Subscriber obs_sub = n.subscribe("/scan",1000,laserCallback);
	ros::Publisher scan_pub = n.advertise<rover_msgs::Laser>("/scan1",10);
	ros::Rate loop_rate(3000);
	int i=0,j=0;
while(ros::ok())
	{
		ros::spinOnce();
		rover_msgs::Laser laser;



		for(int i=0;i<100;i++)
		{
		
		 laser.ranges[i]=scan[i];
		
		}

		scan_pub.publish(laser);
		

	}

	    ros::spin();
		return 0 ;
}
