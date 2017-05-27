#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/MagneticField.h>
#include <rover_msgs/WheelVelocity.h>
#include <cstdlib>
#include <cmath>
#include <time.h>

time_t start, end;

#define PI 3.14159
#define R 6371

double latt[5]={0,0,0,0,0},logi[5]={0,0,0,0,0};
int i=0;
double lat_dest=latt[i]*PI/180,logg_dest=logi[i]*PI/180;
double lat,logg,dist,brng,brng_cur,decl=-1.666666666666667*PI/180;
double theta,x,y;

void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
	lat = (msg->latitude)*PI/180;
	logg = (msg->longitude)*PI/180;
	
	brng = atan2((sin(logg_dest - logg))*(cos(lat_dest)),(cos(lat))*(sin(lat_dest))-(sin(lat))*(cos(lat_dest)*(cos(logg_dest-logg))));
	if(brng>=0)	brng=brng;
	else	brng=brng+2*PI;
	float a = (sin((lat_dest-lat)/2))*(sin((lat_dest-lat)/2)) + (cos(lat))*(cos(lat_dest))*(sin((logg_dest-logg)/2))*(sin((logg_dest-logg)/2));
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	dist= R*c;
}

void ortnCallback(const sensor_msgs::MagneticField::ConstPtr& msg)
{
	x = (msg->magnetic_field.x)*1000000;
	y = (msg->magnetic_field.y)*1000000;
	
	theta = atan2(x,y);

	brng_cur=decl-theta;
	if(brng_cur<0)  brng_cur=brng_cur+2*PI;

}

void recieve_gps(int i){
	lat_dest=latt[i];
	logg_dest=logi[i];
}

int main(int argc,char **argv)
{
	ros::init(argc,argv,"gps");
	ros::NodeHandle n;
	recieve_gps(0);                          //recieve initial gps init and dest 
	ros::Subscriber gps_sub = n.subscribe("/phone1/android/fix",1000,gpsCallback);
	ros::Subscriber ortn_sub = n.subscribe("/phone1/android/magnetic_field",1000,ortnCallback);
	ros::Publisher vel_pub = n.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
	ros::Rate loop_rate(5);	

	while(ros::ok())
	{
	ros::spinOnce();
	rover_msgs::WheelVelocity vel;
	while(ros::ok())
	{
	ros::spinOnce();
	rover_msgs::WheelVelocity vel;
	if(fabs(dist)>0.002){
		if(fabs(brng-brng_cur)*180/PI>=15 ){
			if ((brng-brng_cur)*180/PI<=-15){
				vel.left = -50;
    	 	   	vel.right = 50;
        		
			}
			else{
				vel.left = 50;
        		vel.right = -50;
        		
			}
		
		}
		/*else if(fabs(brng-brng_cur)<=10*PI/180 && fabs(brng-brng_cur)>5*PI/180)
		{
			
			if (brng-brng_cur<=0){
				vel.left_front_vel = -30;
    	 		vel.right_front_vel = 30;
        		vel.left_middle_vel = -30;
        		vel.right_middle_vel = 30;
        		vel.left_back_vel = -30;
        		vel.right_back_vel = 30;	
				vel_pub.publish(vel);
			}

			else{
				vel.left_front_vel = 30;
        		vel.right_front_vel = -30;
        		vel.left_middle_vel = 30;
        		vel.right_middle_vel = -30;
        		vel.left_back_vel = 30;
        		vel.right_back_vel = -30;
        		vel_pub.publish(vel);
			}

		}*/
		else{
			vel.left = 70;
        	vel.right = 70;
        	
 			vel_pub.publish(vel);	
			time(&start);
			time(&end);
			while((difftime(end,start) < 3))
			{
       		time(&end);
        	//ROS_INFO("%f\n",difftime(end,start));
        	}
		}	
	}
	else{
		vel.left = 0;
        vel.right = 0;
        
		if(i<=2){
			recieve_gps(++i);
			ROS_INFO("===New gps destn set===");
		}
		else	ROS_INFO("===Final destn reached===");
	}
	vel_pub.publish(vel);
	ROS_INFO("%lf\t%lf",brng,brng_cur);
	loop_rate.sleep();
	
}
	ros::spin();
	return 0 ;
}

