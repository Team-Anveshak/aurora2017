#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <rover_msgs/WheelVelocity.h>
#include <cstdlib>
#include <cmath>

#define PI 3.14159

class LocomotionControl{
    public:
        LocomotionControl();
    private:
        void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
        ros::NodeHandle nh;
        ros::Publisher vel_pub;
        ros::Subscriber joy_sub;
};

LocomotionControl::LocomotionControl(){
    vel_pub = nh.advertise<rover_msgs::WheelVelocity>("rover1/wheel_vel",10);
    joy_sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&LocomotionControl::joyCallback,this);
}

void LocomotionControl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){
    rover_msgs::WheelVelocity vel;
    double x_axis_val = joy->axes[0];
    double y_axis_val = joy->axes[1];

    double scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    
/*    if(scale<=0.2){
        x_axis_val=0;
        y_axis_val=0;
    }*/
    //double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
    // double top_left, top_right, bottom_left, bottom_right;
    //ROS_INFO_STREAM("Scale : " << scale << "Angle : "<< angle);

float b = 45;
float a = 110;
float c2 = 500;
float c1 = 40;

float n = 1.5; //scaling factor

//% velocity algorithm

float v = c2 * y_axis_val;
float r = fabs( c1/ x_axis_val );

float dem = (1+ b/r)*(1+ b/r) + (a/2/r)*(a/2/r);

float v1 = v;
float v2 = v*( (1+b/r)*(1+b/r)/dem);
float v3 = v* ((1+b/r)*(1+a/2/r)*(1+a/2/r)/dem);
float v4 = v*((1+b/r)/dem);

    vel.left_front_vel = 1500;
    vel.right_front_vel = 1500;
    vel.left_middle_vel = 1500;
    vel.right_middle_vel = 1500;
    vel.left_back_vel = 1500;
    vel.right_back_vel = 1500;
/*%velocity assignment*/
/*vlt=v1;
vlb=v1;
vlm=v2;
vrm=v4;
vrt=v3;x
vrb=v3;*/
if(y_axis_val>=0.1){
if(x_axis_val >= 0){
    if(x_axis_val>0.8 && (fabs(y_axis_val) <=0.2)){
    vel.left_front_vel = c2/n + 1500;
    vel.right_front_vel = -c2/n + 1500;
    vel.left_middle_vel = c2/n + 1500;
    vel.right_middle_vel = -c2/n + 1500;
    vel.left_back_vel = c2/n + 1500;
    vel.right_back_vel = -c2/n + 1500;
    }
    else{
    vel.left_front_vel = v1/5 + 1700;
    vel.right_front_vel = v3/5 + 1700;
    vel.left_middle_vel = v4/5 + 1700;
    vel.right_middle_vel = v2/5 + 1700;
    vel.left_back_vel = v1/5 + 1700;
    vel.right_back_vel = v3/5 + 1700;
    }
    // thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));    
}
else if(x_axis_val < 0){
    if(x_axis_val<-0.8 && (fabs(y_axis_val) <= 0.2)){
    vel.left_front_vel = -c2/n + 1500;
    vel.right_front_vel = c2/n + 1500;
    vel.left_middle_vel = -c2/n + 1500;
    vel.right_middle_vel = c2/n + 1500;
    vel.left_back_vel = -c2/n + 1500;
    vel.right_back_vel = c2/n + 1500;
    }
    else{
    vel.left_front_vel = v3/5 + 1700;
    vel.right_front_vel = v1/5 + 1700;
    vel.left_middle_vel = v2/5 + 1700;
    vel.right_middle_vel = v4/5 + 1700;
    vel.left_back_vel = v3/5 + 1700;
    vel.right_back_vel = v1/5 + 1700;
    }// thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));
}    
}

else if(y_axis_val<=-0.1){
    if(x_axis_val >= 0){
    if(x_axis_val>0.8 && (fabs(y_axis_val) <=0.2)){
    vel.left_front_vel = c2/n + 1500;
    vel.right_front_vel = -c2/n + 1500;
    vel.left_middle_vel = c2/n + 1500;
    vel.right_middle_vel = -c2/n + 1500;
    vel.left_back_vel = c2/n + 1500;
    vel.right_back_vel = -c2/n + 1500;
    }
    else{
    vel.left_front_vel = v1/5 + 1300;
    vel.right_front_vel = v3/5 + 1300;
    vel.left_middle_vel = v4/5 + 1300;
    vel.right_middle_vel = v2/5 + 1300;
    vel.left_back_vel = v1/5 + 1300;
    vel.right_back_vel = v3/5 + 1300;
    }
    // thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));    
    }
    else if(x_axis_val < 0){
    if(x_axis_val<-0.8 && (fabs(y_axis_val) <= 0.2)){
    vel.left_front_vel = -c2/n + 1500;
    vel.right_front_vel = c2/n + 1500;
    vel.left_middle_vel = -c2/n + 1500;
    vel.right_middle_vel = c2/n + 1500;
    vel.left_back_vel = -c2/n + 1500;
    vel.right_back_vel = c2/n + 1500;
    }
    else{
    vel.left_front_vel = v3/5 + 1300;
    vel.right_front_vel = v1/5 + 1300;
    vel.left_middle_vel = v2/5 + 1300;
    vel.right_middle_vel = v4/5 + 1300;
    vel.left_back_vel = v3/5 + 1300;
    vel.right_back_vel = v1/5 + 1300;
    }// thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));
}
}

    vel_pub.publish(vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
