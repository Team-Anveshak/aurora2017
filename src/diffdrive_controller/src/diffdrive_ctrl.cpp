#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <rover_msgs/WheelVelocity.h>
#define L 100
class CmdVelToDiffDriveMotors{
    public:
        CmdVelToDiffDriveMotors();
    private:
        void twistCallback(const geometry_msgs::Twist::ConstPtr& cmd_vel);
        ros::NodeHandle nh;
        ros::Publisher vel_pub;
        ros::Subscriber cmd_vel_sub;
};

CmdVelToDiffDriveMotors::CmdVelToDiffDriveMotors(){
    vel_pub = nh.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
    cmd_vel_sub = nh.subscribe<geometry_msgs::Twist>("/cmd_vel",10,&CmdVelToDiffDriveMotors::twistCallback,this);
}

void CmdVelToDiffDriveMotors::twistCallback(const geometry_msgs::Twist::ConstPtr& cmd_vel){
    rover_msgs::WheelVelocity vel;
    float target_v = cmd_vel->linear.x;
    float target_w = cmd_vel->angular.z;
    vel.left_front_vel = (2*target_v + target_w*L) / (2);
    vel.left_middle_vel = (2*target_v + target_w*L) / (2);
    vel.left_back_vel = (2*target_v + target_w*L) / (2);
    vel.right_front_vel = (2*target_v - target_w*L) / (2);
    vel.right_middle_vel = (2*target_v - target_w*L) / (2);
    vel.right_back_vel = (2*target_v - target_w*L) / (2);

vel_pub.publish(vel);    
}


int main(int argc, char** argv) {
    ros::init(argc,argv,"diffdrive_ctrl");
    CmdVelToDiffDriveMotors diffdrive_ctrl;
    ros::spin();
    return 0;
}
