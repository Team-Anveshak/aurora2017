#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/MagneticField.h>
#include <rover_msgs/WheelVelocity.h>
#include <cstdlib>
#include <cmath>

#define PI 3.14159
#define R 6371

double lat_init=12.99190489,logg_init= 80.23337262,dist_init;
double lat_dest=12.992511,logg_dest=80.232439;
double lat,logg,dist,brng,brng_cur,decl;
int service,status;


void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
	lat = (msg->latitude)*PI/180;
	logg = (msg->longitude)*PI/180;
	service = msg->status.service;
	status = msg->status.status;
	
	brng = atan2((sin(logg_dest - logg))*(cos(lat_dest)),(cos(lat))*(sin(lat_dest))-(sin(lat))*(cos(lat_dest)*(cos(logg_dest-logg))));
	
	float a = (sin((lat_dest-lat)/2))*(sin((lat_dest-lat)/2)) + (cos(lat))*(cos(lat_dest))*(sin((logg_dest-logg)/2))*(sin((logg_dest-logg)/2));
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	dist= R*c;
}

void ortnCallback(const sensor_msgs::MagneticField::ConstPtr& msg)
{
	float x = (msg->magnetic_field.x)*PI/180;
	float y = (msg->magnetic_field.y)*PI/180;
	
	float theta = fabs(atan2( y, x ));
	if(y<0)		theta = PI - theta;

	if( decl > 0 ){
		if(y>0 && (theta+decl-PI)<0 )		brng_cur = theta + decl;
		if(y>0 && (theta+decl-PI)>0 )	 brng_cur = theta + decl - 2*PI;
		if(y<0)		brng_cur = theta + decl -PI;	
	}
	else {
		if(y<0 && (theta-fabs(decl))<0 )		brng_cur = theta + PI - decl;
		if(y<0 && (theta-fabs(decl))>0 )	 brng_cur = theta - decl - PI;
		if(y>0)		brng_cur = theta - decl;	
	}

}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"gps");
	ros::NodeHandle n;

	ros::Time current_time, last_time;

	ros::Subscriber gps_sub = n.subscribe("/phone1/android/fix",1000,gpsCallback);
	ros::Subscriber ortn_sub = n.subscribe("/phone1/android/magnetic_field",1000,ortnCallback);
	ros::Publisher vel_pub = n.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
	ros::Rate loop_rate(5);	

	float a = (sin((lat_dest-lat_init)/2))*(sin((lat_dest-lat_init)/2)) + (cos (lat_init))*(cos (lat_dest))*(sin((logg_dest-logg_init)/2))*(sin((logg_dest-logg_init)/2));
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	dist_init= R*c;

	while(ros::ok())
	{
	ros::spinOnce();
	rover_msgs::WheelVelocity vel;
	if(fabs(brng-brng_cur)>=30*PI/180 )
	{
		if (brng-brng_cur<=0){
			vel.left_front_vel = 70;
	 	   	vel.right_front_vel = -70;
    		vel.left_middle_vel = 70;
    		vel.right_middle_vel = -70;
    		vel.left_back_vel = 70;
    		vel.right_back_vel = -70;	
		}
		else{
			vel.left_front_vel = -70;
    		vel.right_front_vel = 70;
    		vel.left_middle_vel = -70;
    		vel.right_middle_vel = 70;
    		vel.left_back_vel = -70;
    		vel.right_back_vel = 70;
		}
	
	}
	else if(fabs(brng-brng_cur)<=30*PI/180 && fabs(brng-brng_cur)>15*PI/180)
	{
		
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

	}
	else if(fabs(dist_init-dist)>0.002 && fabs(brng-brng_cur)<=15*PI/180)
	{
		current_time = ros::Time::now();
		last_time = ros::Time::now();
		while((current_time-last_time).toSec()<=5)
		{
			vel.left_front_vel = 70;
		 	vel.right_front_vel = 70;
	    	vel.left_middle_vel = 70;
	    	vel.right_middle_vel = 70;
	    	vel.left_back_vel = 70;
	    	vel.right_back_vel = 70;
			current_time = ros::Time::now();

    	}
	}	
			
	else
	{
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

