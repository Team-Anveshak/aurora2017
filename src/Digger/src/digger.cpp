#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <rover_msgs/digger.h>

float ver_up,ver_do,hor_r,hor_l,probe_up,probe_do,Drill;
int value,value1,value2,sensor_key,count;

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{ 

 ver_up=joy->buttons[3];
 ver_do=joy->buttons[0];
 hor_r=joy->buttons[1];
 hor_l=joy->buttons[2];
 probe_up=joy->buttons[6];
 probe_do=joy->buttons[7];
 Drill=joy->buttons[8]; 
 sensor_key=joy->buttons[4];

}


int main(int argc,char **argv)
{
	ros::init(argc,argv,"dig");
	ros::NodeHandle n;

	ros::Subscriber dig_sub = n.subscribe("/joy2",100,joyCallback);
	ros::Publisher dig_pub = n.advertise<rover_msgs::digger>("/dig",10);
	ros::Rate loop_rate(10);	
	


   while(ros::ok())
   {
	ros::spinOnce();
	rover_msgs::digger Digger;	

	if(ver_up==1.0||ver_do==1.0)
	{
		if(ver_up==1.0)
		{
		Digger.Step_UD_dir=1;
	
		}
		else if(ver_do==1.0)
		{
		Digger.Step_UD_dir=-1;
		}
		else Digger.Step_UD_dir;
	
		if(value==1) value=0;
		else value=1;
		Digger.Step_UD_step = value;
	}

	if(hor_l==1.0||hor_r==1.0)
	{
		if(hor_r==1.0)
		{
		Digger.LR_dir=1;
	
		}
		else if(hor_l==1.0)
		{
		Digger.LR_dir=-1;
		}
		else Digger.LR_dir=0;
	
		if(value1==1) value1=0;
		else value1=1;
		Digger.LR_step = value1;
	}
	

	if(probe_up==1.0||probe_do==1.0)
	{
		if(probe_up==1.0)
		{
		Digger.probe_dir=1;
	
		}
		else if(probe_do==1.0)
		{
		Digger.probe_dir=-1;
		}
		else Digger.probe_dir=0;
	
		if(value2==1) value2=0;
		else value2=1;
		Digger.probe_step = value2;
	}
        

           Digger.drill=Drill;
           if(count==5)
           {
            
            Digger.reset_flag = 1;
           	count=0;
           }
            count++;
           	Digger.sensor_flag = sensor_key;


	dig_pub.publish(Digger);
    loop_rate.sleep();

   }

}



