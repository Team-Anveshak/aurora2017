#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/GPS.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry>
#include <cstdlib>
#include <cmath>

#define PI 3.14159

class LocomotionControl{
    public:
        LocomotionControl();
    private:
        void gpsCallback(const rover_msgs::GPS::ConstPtr& gps);
        ros::NodeHandle nh;
        ros::Publisher vel_pub;
        ros::Publisher cmd_vel_pub;
        ros::Subscriber gps_pub;
};

LocomotionControl::LocomotionControl(){
    vel_pub = nh.advertise<rover_msgs::WheelVelocity>("rover1/wheel_vel",10);
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",10);
    gps_pub = nh.subscribe<rover_msgs::GPS>("rover1/gps",10,&LocomotionControl::gpsCallback,this);
}

void LocomotionControl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){
    rover_msgs::WheelVelocity vel;
    geometry_msgs::Twist sim_vel;//simulation velocity
    rover_msgs::GPS inst_pose;
    float 

    float scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    //ROS_INFO_STREAM("scale : " << scale);
    float e= 1;

    if(fabs(y_axis_val)<=0.2) y_axis_val=0;
    else if (y_axis_val>0.2)  y_axis_val= y_axis_val*5.0/4.0*(e-0.5) + (2.5-e)/4.0;
    else if (y_axis_val<-0.2) y_axis_val= y_axis_val*5.0/4.0*(e-0.5) - (2.5-e)/4.0;
    
    float b = 45;
    float a = 110;
    float c2 = 500;
    float c1 = 40;

    //% velocity algorithm

    float v = c2 * y_axis_val;
    float r = fabs( c1/ x_axis_val );

    float dem = (1+ b/r)*(1+ b/r) + (a/2/r)*(a/2/r);

    float v1 = v;
    float v2 = v*( (1+b/r)*(1+b/r)/dem);
    float v3 = v* ((1+b/r)*(1+(a/2/r*a/2/r))/dem);
    float v4 = v*((1+b/r)/dem);

    ROS_INFO_STREAM("y : " << y_axis_val << "x : " << x_axis_val <<"angular" << v/r);


    if(x_axis_val >= 0){
        if(fabs(y_axis_val) <= 0.2){
            if (fabs(x_axis_val)<=0.5){
                vel.left_front_vel = 1500;
                vel.right_front_vel = 1500;
                vel.left_middle_vel = 1500;
                vel.right_middle_vel = 1500;
                vel.left_back_vel = 1500;
                vel.right_back_vel = 1500;
            }
            else if(x_axis_val>=0.5){
                float x_axis_val_mod1= x_axis_val*0.4+0.3;
                vel.left_front_vel = -c2*x_axis_val_mod1+1500;
                vel.right_front_vel = c2*x_axis_val_mod1+1500;
                vel.left_middle_vel = -c2*x_axis_val_mod1+1500;
                vel.right_middle_vel = c2*x_axis_val_mod1+1500;
                vel.left_back_vel = -c2*x_axis_val_mod1+1500;
                vel.right_back_vel = c2*x_axis_val_mod1+1500;
            }
        }
        else{
            vel.left_front_vel = v3 + 1500;
            vel.right_front_vel = v1 + 1500;
            vel.left_middle_vel = v2 + 1500;
            vel.right_middle_vel = v4 + 1500;
            vel.left_back_vel = v3 + 1500;
            vel.right_back_vel = v1 + 1500;
        }
    }

    else if(x_axis_val < 0){
        if(fabs(y_axis_val) <= 0.2){
            if (fabs(x_axis_val)<=0.5){
                vel.left_front_vel = 1500;
                vel.right_front_vel = 1500;
                vel.left_middle_vel = 1500;
                vel.right_middle_vel = 1500;
                vel.left_back_vel = 1500;
                vel.right_back_vel = 1500;
            }
            else if(x_axis_val<-0.5){
                float x_axis_val_mod2= x_axis_val*0.4-0.3;
                vel.left_front_vel = -c2*x_axis_val_mod2+1500;
                vel.right_front_vel = c2*x_axis_val_mod2+1500;
                vel.left_middle_vel = -c2*x_axis_val_mod2+1500;
                vel.right_middle_vel = c2*x_axis_val_mod2+1500;
                vel.left_back_vel = -c2*x_axis_val_mod2+1500;
                vel.right_back_vel = c2*x_axis_val_mod2+1500;
            }
        } 
        else{
            vel.left_front_vel = v1 + 1500;
            vel.right_front_vel = v3 + 1500;
            vel.left_middle_vel = v2 + 1500;
            vel.right_middle_vel = v4 + 1500;
            vel.left_back_vel = v1 + 1500;
            vel.right_back_vel = v3 + 1500;
        }   
    }

    sim_vel.linear.x = (vel.right_front_vel + vel.right_middle_vel + vel.right_back_vel + vel.left_back_vel + vel.left_middle_vel + vel.left_front_vel)*(cos(angle)/6);
    sim_vel.linear.y = (vel.right_front_vel + vel.right_middle_vel + vel.right_back_vel + vel.left_back_vel + vel.left_middle_vel + vel.left_front_vel)*(sin(angle)/6);
    sim_vel.linear.z = 0;
    sim_vel.angular.x = 0;
    sim_vel.angular.y = 0;
    sim_vel.angular.z = (vel.right_middle_vel - vel.left_middle_vel+ vel.right_front_vel + vel.right_back_vel - vel.left_front_vel - vel.left_back_vel)/(b*3); 

    if(x_axis_val < 0) sim_vel.linear.x = sim_vel.linear.x*-1;
    if(y_axis_val < 0) sim_vel.linear.y = sim_vel.linear.y*-1;
    if(fabs(y_axis_val)<0.2 && fabs(x_axis_val >0.8)) sim_vel.angular.z = vel.right_middle_vel/b;

    vel_pub.publish(vel);
    cmd_vel_pub.publish(sim_vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
