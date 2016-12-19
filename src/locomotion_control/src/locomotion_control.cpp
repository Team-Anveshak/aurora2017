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
    double scale = 5 * sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
    if((angle - 90.000) < 0.1){
        vel.left_front_vel = scale;
        vel.right_front_vel = scale;
        vel.left_middle_vel = scale;
        vel.right_middle_vel = scale;
        vel.left_back_vel = scale;
        vel.right_back_vel = scale;
        ROS_INFO_STREAM("Forward Motion");
    }
    else if((angle + 90.000) < 0.1){
        vel.left_front_vel = -1 * scale;
        vel.right_front_vel = -1 * scale;
        vel.left_middle_vel = -1 * scale;
        vel.right_middle_vel = -1 * scale;
        vel.left_back_vel = -1 * scale;
        vel.right_back_vel = -1 * scale;
        ROS_INFO_STREAM("Backward Motion");
    }
    else{
        scale = 0.000;
        vel.left_front_vel = scale;
        vel.right_front_vel = scale;
        vel.left_middle_vel = scale;
        vel.right_middle_vel = scale;
        vel.left_back_vel = scale;
        vel.right_back_vel = scale;
        ROS_INFO_STREAM("Halt");
    }
    vel_pub.publish(vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
