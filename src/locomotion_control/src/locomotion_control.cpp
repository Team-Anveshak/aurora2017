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
    float x_axis_val = joy->axes[0];
    float y_axis_val = joy->axes[1];

    float scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    //ROS_INFO_STREAM("scale : " << scale);
    float e= 1;

    if(fabs(y_axis_val)<=0.2){
        y_axis_val=0;
    }

    else if (y_axis_val>0.2){
     y_axis_val= y_axis_val*5.0/4.0*(e-0.5) + (2.5-e)/4.0;
    }

    else if (y_axis_val<-0.2){
     y_axis_val= y_axis_val*5.0/4.0*(e-0.5) - (2.5-e)/4.0;
    }
    //double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
    
    ROS_INFO_STREAM("y : " << y_axis_val << "x : "<< x_axis_val);

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

ROS_INFO_STREAM("a ::" << 1+b/r << "b: "<< (1+a/2/r)*(1+a/2/r)<< "dem: "<< dem);


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
    vel_pub.publish(vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
