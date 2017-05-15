#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/MagneticField.h>
#include <rover_msgs/WheelVelocity.h>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <cmath>
#include <time.h>

time_t start, end;

#define PI 3.14159
#define R 6371

//double lat_dest=11.993511*PI/180,logg_dest=80.272439*PI/180;
double lat_dest=12.99151885*PI/180,logg_dest=80.23199121*PI/180;
double lat,logg,dist,brng,brng_cur,decl=-1.666666666666667*PI/180;
//int service,status;
int countR,countL,dir;
double theta,x,y;

void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg){
	lat = (msg->latitude)*PI/180;
	logg = (msg->longitude)*PI/180;
	//service = msg->status.service;
	//status = msg->status.status;
	
	brng = atan2((sin(logg_dest - logg))*(cos(lat_dest)),(cos(lat))*(sin(lat_dest))-(sin(lat))*(cos(lat_dest)*(cos(logg_dest-logg))));
	if(brng>=0)	brng=brng;
	else	brng=brng+2*PI;
	float a = (sin((lat_dest-lat)/2))*(sin((lat_dest-lat)/2)) + (cos(lat))*(cos(lat_dest))*(sin((logg_dest-logg)/2))*(sin((logg_dest-logg)/2));
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	dist= R*c;
}

void ortnCallback(const sensor_msgs::MagneticField::ConstPtr& msg){
	x = (msg->magnetic_field.x)*1000000;
	y = (msg->magnetic_field.y)*1000000;
	
	theta = atan2(x,y);

	brng_cur=decl-theta;
	if(brng_cur<0)  brng_cur=brng_cur+2*PI;

	/*if( decl > 0 ){
		if(y>0 && (theta+decl-PI)<0 )	brng_cur = theta + decl;
		if(y>0 && (theta+decl-PI)>0 )	brng_cur = theta + decl - 2*PI;
		if(y<0)		brng_cur = theta + decl -PI;	
	}
	else {
		if(y<0 && (theta-fabs(decl))<0 )	brng_cur = theta + PI - decl;
		if(y<0 && (theta-fabs(decl))>0 )	brng_cur = theta - decl - PI;
		if(y>0)	brng_cur = theta - decl;	
	}
	*/
}

void laserCallback(const sensor_msgs::LaserScan::ConstPtr& msg)
{
	int size = msg->ranges.size();

	countL=0;
	countR=0;
	int i,j;
	for(i = -3; i < size/2; i++)
	{
		for (j=i; j<i+6; j++)
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
			dir = (-j+2);
			break;		
  		}
  		else if(countR<=4 && countL>=4)
		{
			dir = (j-2);
			break;
  		}
  		else if(countR>=4 && countL>=4)
		{
			dir = (j-2);
			break;
  		}
		
		countL=0;	
		countR=0;		
	}
}



int main(int argc,char **argv)
{
	ros::init(argc,argv,"gps");
	ros::NodeHandle n;

	ros::Subscriber gps_sub = n.subscribe("/phone1/android/fix",100,gpsCallback);
	ros::Subscriber ortn_sub = n.subscribe("/phone1/android/magnetic_field",100,ortnCallback);
	ros::Subscriber obs_sub = n.subscribe("/scan",100,laserCallback);
	ros::Publisher vel_pub = n.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
	ros::Rate loop_rate(5);

	/*float a = (sin((lat_dest-lat_init)/2))*(sin((lat_dest-lat_init)/2)) + (cos (lat_init))*(cos (lat_dest))*(sin((logg_dest-logg_init)/2))*(sin((logg_dest-logg_init)/2));
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	dist_init= R*c;
	*/
	int mode = 0;
	
	while(ros::ok()){
	ros::spinOnce();
	rover_msgs::WheelVelocity vel;

	if(fabs(dist)>0.002){
		if(fabs(brng-brng_cur)*180/PI>=15 && (mode==0)){
			if ((brng-brng_cur)*180/PI<=-15){
				vel.left_front_vel = -50;
    	 	   	vel.right_front_vel = 50;
        		vel.left_middle_vel = -50;
        		vel.right_middle_vel = 50;
        		vel.left_back_vel = -50;
        		vel.right_back_vel = 50;	
			}
			else{
				vel.left_front_vel = 50;
        		vel.right_front_vel = -50;
        		vel.left_middle_vel = 50;
        		vel.right_middle_vel = -50;
        		vel.left_back_vel = 50;
        		vel.right_back_vel = -50;
			}
		
		}
		/*else if(fabs(brng-brng_cur)<=20*PI/180 && fabs(brng-brng_cur)>5*PI/180 && (mode==0)){
			
			if (brng-brng_cur<=0){

			vel.left_front_vel = 50;
    	 	   	vel.right_front_vel = -50;
        		vel.left_middle_vel = 50;
        		vel.right_middle_vel = -50;
        		vel.left_back_vel = 50;
        		vel.right_back_vel = -50;	

			}
			else{
				vel.left_front_vel = -50;
        		vel.right_front_vel = 50;
        		vel.left_middle_vel = -50;
        		vel.right_middle_vel = 50;
        		vel.left_back_vel = -50;
        		vel.right_back_vel = 50;
			}
		
		}*/
		else if(dir>5 || dir<-5){
			mode=1;
			if(dir>5){
				vel.left_front_vel = 50;
    	 	   	vel.right_front_vel = -50;
        		vel.left_middle_vel = 50;
        		vel.right_middle_vel = -50;
        		vel.left_back_vel = 50;
        		vel.right_back_vel = -50;
			}
			else{
				vel.left_front_vel = -50;
        		vel.right_front_vel = 50;
        		vel.left_middle_vel = -50;
        		vel.right_middle_vel = 50;
        		vel.left_back_vel = -50;
        		vel.left_back_vel = 50;
        		vel.right_back_vel = -50;
			}			
		}
		else{
			vel.left_front_vel = 70;
        	vel.right_front_vel = 70;
        	vel.left_middle_vel = 70;
        	vel.right_middle_vel = 70;
        	vel.left_back_vel = 70;
        	vel.right_back_vel = 70;
        	vel_pub.publish(vel);	
			time(&start);
			time(&end);
        	while((difftime(end,start) < 5))
			{
       		time(&end);
        	//ROS_INFO("%f\n",difftime(end,start));
        	}
        	mode=0;
		}
	}
	else{
		vel.left_front_vel = 0;
        vel.right_front_vel = 0;
        vel.left_middle_vel = 0;
        vel.right_middle_vel = 0;
        vel.left_back_vel = 0;
        vel.right_back_vel = 0;
	}
	vel_pub.publish(vel);
	loop_rate.sleep();

	}
	
	ros::spin();
	return 0 ;
}

