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
  
    if(fabs(x_axis_val) < 0.20)
	   x_axis_val = 0;
    if(fabs(y_axis_val) < 0.20)
	   y_axis_val = 0;
  
    double scale = 500 * sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    double angle = atan2(y_axis_val,x_axis_val) * 180 / PI;
    ROS_INFO_STREAM("Scale : " << scale << "Angle : "<< angle);

/*  double top_left, top_right, bottom_left, bottom_right;
    x1 = (2147483647/33000)*(x_axis_val/2);
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

    /*
        vel.left_front_vel = vel.left_front_vel/2 + 750 ;
        vel.right_front_vel = vel.right_front_vel/2 + 750;
        vel.left_middle_vel = vel.left_middle_vel/2 + 750;
        vel.right_middle_vel = vel.right_middle_vel/2 + 750;
        vel.left_back_vel = vel.left_back_vel/2 + 750;
        vel.right_back_vel = vel.right_back_vel/2 + 750;
    */
    vel_pub.publish(vel);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
