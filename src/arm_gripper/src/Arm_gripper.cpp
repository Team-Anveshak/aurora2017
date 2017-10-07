#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <rover_msgs/Arm.h>

int  acc_forw,acc_back,chain_forw,chain_back,base_right,base_left,grip,rotate_clk,rotate_aclk,wrist;
int count;

void joyCallback1(const sensor_msgs::Joy::ConstPtr& joy)
{ 
	 acc_forw=joy->buttons[3];
     acc_back=joy->buttons[0];
     chain_forw=joy->buttons[1];
     chain_back=joy->buttons[2];
     base_left=joy->buttons[6];
     base_right=joy->buttons[7]; 
     //wrist=joy->axes[7];
	 grip=joy->axes[5];
	 rotate_clk=joy->buttons[4];
     rotate_aclk=joy->buttons[5];
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"Arm");
	ros::NodeHandle n;

	ros::Subscriber grip_sub = n.subscribe("/joy",100,joyCallback1);

	ros::Publisher arm_pub = n.advertise<rover_msgs::Arm>("/arm",10);
	ros::Rate loop_rate(10);	
	


   while(ros::ok())
   {
	ros::spinOnce();
	rover_msgs::Arm arm;

	arm.acc_forw=acc_forw;
	arm.acc_back=acc_back;
	arm.chain_forw=chain_forw;
	arm.chain_back=chain_back;
	arm.base_right=base_right;
	arm.base_left=base_left;
	arm.rotate_clk=rotate_clk;
	arm.rotate_aclk=rotate_aclk;
	arm.grip=grip;
	arm.wrist=wrist;
	if(count==5)
           {
            
            arm.reset_flag = 1;
           	count=0;
           }
            count++;

	arm_pub.publish(arm);
    loop_rate.sleep();
   }

}



