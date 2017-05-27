#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/MagneticField.h>
#include <rover_msgs/WheelVelocity.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/Float32.h>
#include <cstdlib>
#include <cmath>
#include <time.h>
 
time_t start, end;
 
#define PI 3.14159
#define R 6371
 
double latt[5]={1,2,3,4,5},logi[5]={1,2,3,4,5};
int i=0;
double lat_dest=latt[i]*PI/180,logg_dest=logi[i]*PI/180;
double lat,logg,dist,brng,brng_cur,decl=-1.666666666666667*PI/180;
double theta,x,y;
int bi,flg=0,nav_flg=0;
float b_angle,b_dist,brng_int,b_time;
 
void gpsCallback(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
    if(nav_flg==0){
 
        lat = (msg->latitude)*PI/180;
        logg = (msg->longitude)*PI/180;
    
        brng = atan2((sin(logg_dest - logg))*(cos(lat_dest)),(cos(lat))*(sin(lat_dest))-(sin(lat))*(cos(lat_dest)*(cos(logg_dest-logg))));
                
        float a = (sin((lat_dest-lat)/2))*(sin((lat_dest-lat)/2)) + (cos(lat))*(cos(lat_dest))*(sin((logg_dest-logg)/2))*(sin((logg_dest-logg)/2));
        float c = 2 * atan2(sqrt(a),sqrt(1-a));
        dist= R*c;
    }
}
 
void ortnCallback(const sensor_msgs::MagneticField::ConstPtr& msg)
{    
    x = (msg->magnetic_field.x)*1000000;
    y = (msg->magnetic_field.y)*1000000;
 
    theta = atan2(x,y);
 
    brng_cur=decl-theta;
  //  if(brng_cur<0)  brng_cur=brng_cur+2*PI;
}
 
void camCallback(const geometry_msgs::Pose2D::ConstPtr& msg)
{    
    if(flg==1){
        time(&start);
        time(&end);
        do{
        b_dist=msg->x;
        b_angle=msg->theta;
        flg=0;
        time(&end);
        if(difftime(end,start)>120)                            //if ball was not detected in 2 min's
            break;
        }while(b_dist==0);
    }
}
 
void recieve_gps(int i){
    lat_dest=latt[i]*PI/180;
    logg_dest=logi[i]*PI/180;
}
 
 
int main(int argc,char **argv)
{
    ros::init(argc,argv,"gps");
    ros::NodeHandle n;
    recieve_gps(0);                          //recieve initial gps dest
    ROS_INFO("===Initial gps destn set===");
    ros::Subscriber gps_sub = n.subscribe("/phone1/android/fix",1000,gpsCallback);
    ros::Subscriber ortn_sub = n.subscribe("/phone1/android/magnetic_field",1000,ortnCallback);    
    ros::Publisher vel_pub = n.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
    ros::Publisher flg_pub = n.advertise<std_msgs::Float32>("/gps_loc_flg",10);
    ros::Subscriber cam_sub = n.subscribe("/ball_pos",1000,camCallback);
    ros::Rate loop_rate(5);    
 
    while(ros::ok())
    {
        rover_msgs::WheelVelocity vel;
        ros::spinOnce();
 
        if(fabs(dist)>0.002)
        {
            if(fabs(brng-brng_cur)*180/PI>=15 )
            {
                if ((brng-brng_cur)*180/PI<=-15)
                {
                    vel.left_front_vel = -50;
                        vel.right_front_vel = 50;
                    vel.left_middle_vel = -50;
                    vel.right_middle_vel = 50;
                    vel.left_back_vel = -50;
                    vel.right_back_vel = 50;
                    vel_pub.publish(vel);
                }
                else
                {
                    vel.left_front_vel = 50;
                    vel.right_front_vel = -50;
                    vel.left_middle_vel = 50;
                    vel.right_middle_vel = -50;
                    vel.left_back_vel = 50;
                    vel.right_back_vel = -50;
                    vel_pub.publish(vel);
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
            else
            {
                vel.left_front_vel = 70;
                vel.right_front_vel = 70;
                vel.left_middle_vel = 70;
                vel.right_middle_vel = 70;
                vel.left_back_vel = 70;
                vel.right_back_vel = 70;
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
        else
        {
            vel.left_front_vel = 0;
            vel.right_front_vel = 0;
            vel.left_middle_vel = 0;
            vel.right_middle_vel = 0;
            vel.left_back_vel = 0;
            vel.right_back_vel = 0;
            vel_pub.publish(vel);
 
            std_msgs::Float32 flag;
            flag.data=flg=1;
            flg_pub.publish(flag);
            ros::spinOnce();
            flag.data=flg=0;
            flg_pub.publish(flag);
            
            if(b_dist>0)
            {
                //nav_to(b_dist,b_angle); towards the ball
                nav_flg=1;
                brng_int=brng_cur;
                time(&start);
                time(&end);
                while(fabs(brng_int-brng_cur)*180/PI<=fabs(fabs(b_angle)-10))
                {           //10 deg is set as error, change it an angle where rover will stop doing oscillations...
                    if ((brng_int-brng_cur)*180/PI<=-fabs(b_angle))
                    {                   //check for the direction of rotation.make it proper
                        vel.left_front_vel = -50;
                            vel.right_front_vel = 50;
                        vel.left_middle_vel = -50;
                        vel.right_middle_vel = 50;
                        vel.left_back_vel = -50;
                        vel.right_back_vel = 50;
                        vel_pub.publish(vel);
                    }
                    else
                    {
                        vel.left_front_vel = 50;
                        vel.right_front_vel = -50;
                        vel.left_middle_vel = 50;
                        vel.right_middle_vel = -50;
                        vel.left_back_vel = 50;
                        vel.right_back_vel = -50;
                        vel_pub.publish(vel);
                    }
                    ros::spinOnce();
                    time(&end);
                    if(difftime(end,start)>30)    break;                                //assuming rover will take less than 30s for 360 deg rotation    
                }
                vel.left_front_vel = 70;
                vel.right_front_vel = 70;
                vel.left_middle_vel = 70;
                vel.right_middle_vel = 70;
                vel.left_back_vel = 70;
                vel.right_back_vel = 70;
                vel_pub.publish(vel);    
                time(&start);
                time(&end);
                b_time=b_dist*.05;                                                //max rpm=175,dist is in cm, then min time taken for travelling 1m @ 175/255 is 5s
                
                while(difftime(end,start) < b_time)
                {
                       time(&end);
                }
                
                vel.left_front_vel = 0;
                vel.right_front_vel = 0;
                vel.left_middle_vel = 0;
                vel.right_middle_vel = 0;
                vel.left_back_vel = 0;
                vel.right_back_vel = 0;
                vel_pub.publish(vel);
                nav_flg=0;
                ROS_INFO("===Successfully navigated towards the ball===");            //navigaton to ball done
            }
            else if (b_dist==0)
                ROS_INFO("===Ball was not detected, proceeding to next gps location===");
/*********************************************************************************************************2 denotes the given number of gps coordinates******************************************************/
            if(i<=2)
            {
                recieve_gps(++i);
                ROS_INFO("===New gps destn set===");
            }
            else
            {
                ROS_INFO("===Final destn reached===");
                break;
            }
        }
 
    //ROS_INFO("%lf\t%lf\t%lf\t%lf",brng,brng_cur,vel.left_front_vel,vel.right_front_vel);
    loop_rate.sleep();
    }
 
    ros::spin();
    return 0 ;
}
 
 
 
 
//Reorient camera
 
 
 
 

