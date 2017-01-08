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
    //double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
/*  if(fabs(x_axis_val) < 0.20)
	   x_axis_val = 0;
    if(fabs(y_axis_val) < 0.20)
	   y_axis_val = 0;
  */
    //double scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    //double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
    // double top_left, top_right, bottom_left, bottom_right;
    //ROS_INFO_STREAM("Scale : " << scale << "Angle : "<< angle);


/*  x1 = (2147483647/33000)*(x_axis_val/2);
    x2 = (90*x_axis_val)/33000*2);
    y1 = 500*y_axis_val/33000;
    y1 = -y1;
    v = y1;
    c = cos(x2*PI/180);
    v1=v*c/(2-c);
    v2=v*c*c/(2-c);
    v3=v*c;
    
    if(x1>=0){
	top_left=v+1500;
        top_right=v1+1500;
	bottom_left=v3+1500;
	bottom_right=v2+1500;
	//theta=x2
    }		    
    if(x1<0){
	top_left=v1+1500;
	top_right=v+1500;
	bottom_left=v2+1500;
	bottom_right=v3+1500;
	//theta=x2
    }
    vel.top_left=top_left/10-100;
    vel.top_right=top_right/10-100;
    vel.bottom_left=bottom_left/10-100;
    vel.bottom_right=bottom_right/10-100;
    ROS_INFO_STREAM("TL_Velocity: " << vel.top_left << "TR_Velocity: " << vel.top_right << "BL_Velocity: " << vel.bottom_left <<"BR_Velocity: " << vel.bottom_right
    //theta=theta+45;
*/

/*
    if(fabs(angle - 90.000) < 20.000){
        vel.left_front_vel = scale + 1500;
        vel.right_front_vel = scale + 1500;
        vel.left_middle_vel = scale + 1500;
        vel.right_middle_vel = scale + 1500;
        vel.left_back_vel = scale + 1500;
        vel.right_back_vel = scale + 1500;
        ROS_INFO_STREAM("Forward Motion");
    }
    else if(fabs(angle + 90.000) < 20.000){
        vel.left_front_vel = -1 * scale + 1500;
        vel.right_front_vel = -1 * scale + 1500;
        vel.left_middle_vel = -1 * scale + 1500;
        vel.right_middle_vel = -1 * scale + 1500;
        vel.left_back_vel = -1 * scale + 1500;
        vel.right_back_vel = -1 * scale + 1500;
        ROS_INFO_STREAM("Backward Motion");
    }
    else{
        scale = 1500.00;
        vel.left_front_vel = scale;
        vel.right_front_vel = scale;
        vel.left_middle_vel = scale;
        vel.right_middle_vel = scale;
	vel.left_back_vel = scale;
	vel.right_back_vel = scale;
        ROS_INFO_STREAM("Halt");
    }

  
    vel.left_front_vel = vel.left_front_vel/2 + 750 ;
    vel.right_front_vel = vel.right_front_vel/2 + 750 ;
    vel.left_middle_vel = vel.left_middle_vel/2 + 750;
    vel.right_middle_vel = vel.right_middle_vel/2 + 750;
    vel.left_back_vel = vel.left_back_vel/2 + 750;
    vel.right_back_vel = vel.right_back_vel/2 + 750;
*/

float b = 25;
float a = 45;
float c2 = 3;
float c1 = 1;

//% velocity algorithm

float v = c2 * y_axis_val;
float r = fabs( c1/ x_axis_val );

float dem = (1+ b/r)*(1+ b/r) + (a/2/r)*(a/2/r);

float v1 = v;
float v2 = v*( (1+b/r)*(1+b/r)/dem);
float v3 = v* ((1+b/r)*(1+a/2/r)*(1+a/2/r)/dem);
float v4 = v*((1+b/r)/dem);

/*%velocity assignment*/
/*vlt=v1;
vlb=v1;
vlm=v2;
vrm=v4;
vrt=v3;
vrb=v3;*/
if(x_axis_val >= 0){
    if(x_axis_val>0.9 && (y_axis_val <= 0.1 && y_axis_val> -0.1)){
    vel.left_front_vel = c2;
    vel.right_front_vel = -c2;
    vel.left_middle_vel = c2;
    vel.right_middle_vel = -c2;
    vel.left_back_vel = c2;
    vel.right_back_vel = -c2;
    }
    else{
    vel.left_front_vel = v1;
    vel.right_front_vel = v3;
    vel.left_middle_vel = v2;
    vel.right_middle_vel = v4;
    vel.left_back_vel = v1;
    vel.right_back_vel = v3;
    }
    // thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));    
}
else{
    if(x_axis_val<-0.9 && (y_axis_val <= 0.1 && y_axis_val> -0.1)){
    vel.left_front_vel = -c2;
    vel.right_front_vel = c2;
    vel.left_middle_vel = -c2;
    vel.right_middle_vel = c2;
    vel.left_back_vel = -c2;
    vel.right_back_vel = c2;
    }
    else{
    vel.left_front_vel = v3;
    vel.right_front_vel = v1;
    vel.left_middle_vel = v4;
    vel.right_middle_vel = v2;
    vel.left_back_vel = v3;
    vel.right_back_vel = v1;
    }// thetaL=asin((a/2/r)/sqrt(dem));
    // thetaR=asin((a/2/r)/sqrt(1+(a/2/r)^2));
}

    vel_pub.publish(vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
