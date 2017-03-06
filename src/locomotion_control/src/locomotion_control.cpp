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
    vel_pub = nh.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
    joy_sub = nh.subscribe<sensor_msgs::Joy>("/joy",10,&LocomotionControl::joyCallback,this);
}

void LocomotionControl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){
    rover_msgs::WheelVelocity vel;
    
    float x_axis_val = joy->axes[0];
    float y_axis_val = joy->axes[1];
    //double angle = atan2(y_axis_val,x_axis_val);

    //float scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    //ROS_INFO_STREAM("scale : " << scale);
    float e= 4;
    
    float b = 45;
    float a = 110;
    float c2 = 50;
    float c1 = 45;

    //% velocity algorithm

    float v = c2 * y_axis_val;
    float r;
    if(fabs(x_axis_val)>=0.2 && fabs(x_axis_val<0.5)){
        r = c1*e;
    }
    else if(x_axis_val>=0.5){
        r = c1*e*2;
    }
    float dem = (1+ b/r)*(1+ b/r) + (a/2/r)*(a/2/r);

    float v1 = v;
    float v2 = v*( (1+b/r)*(1+b/r)/dem);
    float v3 = v* ((1+b/r)*(1+(a/2/r*a/2/r))/dem);
    float v4 = v*((1+b/r)/dem);


    if(fabs(x_axis_val)<0.2){
        vel.left_front_vel = c2 * y_axis_val;
        vel.right_front_vel = c2 * y_axis_val;
        vel.left_middle_vel = c2 * y_axis_val;
        vel.right_middle_vel = c2 * y_axis_val;
        vel.left_back_vel = c2 * y_axis_val;
	vel.right_back_vel = c2 * y_axis_val;
    }
    if (fabs(y_axis_val)<0.15 && x_axis_val<-0.5){
        vel.left_front_vel = -c2 * x_axis_val;
        vel.right_front_vel = c2 * x_axis_val;
        vel.left_middle_vel = -c2 * x_axis_val;
        vel.right_middle_vel = c2 * x_axis_val;
        vel.left_back_vel = -c2 * x_axis_val;
        vel.right_back_vel = c2 * x_axis_val;
    }
    if (fabs(y_axis_val)<0.15 && x_axis_val>0.5){
        vel.left_front_vel = -c2 * x_axis_val;
        vel.right_front_vel = c2 * x_axis_val;
        vel.left_middle_vel = -c2 * x_axis_val;
        vel.right_middle_vel = c2 * x_axis_val;
        vel.left_back_vel = -c2 * x_axis_val;
        vel.right_back_vel = c2 * x_axis_val;
    }
    if(y_axis_val>0.2){   
        if(x_axis_val>0.25){
            vel.left_front_vel = v3;
            vel.right_front_vel = v1;
            vel.left_middle_vel = v4;
            vel.right_middle_vel = v2;
            vel.left_back_vel = v3;
            vel.right_back_vel = v1;
        }
        else if(x_axis_val<-0.25){
            vel.left_front_vel = v1;
            vel.right_front_vel = v3;
            vel.left_middle_vel = v2;
            vel.right_middle_vel = v4;
            vel.left_back_vel = v1;
            vel.right_back_vel = v3;   
        }
    }
    
    else if(y_axis_val<-0.2){   
        if(x_axis_val>0.25){
            vel.left_front_vel = v3;
            vel.right_front_vel = v1;
            vel.left_middle_vel = v4;
            vel.right_middle_vel = v2;
            vel.left_back_vel = v3;
            vel.right_back_vel = v1;
        }
        else if(x_axis_val<-0.25){
            vel.left_front_vel = v1;
            vel.right_front_vel = v3;
            vel.left_middle_vel = v2;
            vel.right_middle_vel = v4;
            vel.left_back_vel = v1;
            vel.right_back_vel = v3;   
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
