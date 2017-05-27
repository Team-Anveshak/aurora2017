#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <rover_msgs/WheelVelocity.h>
#include <cstdlib>
#include <cmath>

#define PI 3.14159

// To control the Locomotion of the Rover
//     @LocomotionControl constructor for the class	
//     @joyCallback callback function for joy subscriber
//     @nh initialise the NodeHandler object
//     @vel_pub publisher variable
//     @joy_sub subscriber variable
float x_axis_val;
float y_axis_val;
float sp_inc;
float sp_dec;
float count= 0;
float c2;
int flag,flag2 ;
int Drill;
int Sensor;
int Reset;
int cnt;

/*class LocomotionControl{
    public:
        LocomotionControl();
    private:
        void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
        ros::NodeHandle nh;
        ros::Publisher vel_pub;
        ros::Subscriber joy_sub;
};

// @vel_pub is assigned to advertise the /rover1/wheel_vel message
// @joy_sub is assigned to subscribe the /joy message
LocomotionControl::LocomotionControl(){
    vel_pub = nh.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
    joy_sub = nh.subscribe<sensor_msgs::Joy>("/joy1",10,&LocomotionControl::joyCallback,this);
}*/

//      @x_axis_value- x axis position of joystick controller
//      @y_axis_value- y axis position of joystick controller
//      @scale- magnitude of a vector, lies between (0, 5)
//      @angle- horizontal plane angle made by controller
void joyCallback1(const sensor_msgs::Joy::ConstPtr& joy1)
{
    
    
     x_axis_val = joy1->axes[0];
     y_axis_val = joy1->axes[1];
     sp_inc = joy1->axes[5];
     sp_dec = joy1->axes[2];
   
    
}

// @init initialises the ros
// creates a LocomotionControl object

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");

    //LocomotionControl locomotion_control;
    ros::NodeHandle nh;
    ros::Publisher vel_pub = nh.advertise<rover_msgs::WheelVelocity>("/rover1/wheel_vel",10);
    ros::Subscriber joy_sub1 = nh.subscribe<sensor_msgs::Joy>("/joy1",10,joyCallback1);
    ros::Rate loop_rate(10);	

while(ros::ok())
	{

	ros::spinOnce();
    rover_msgs::WheelVelocity vel;


     if(sp_inc <0.0 && count<2 && flag==1)
	{
	  count++;
	  flag = 0;
	}

    if (sp_inc >0.0)  flag=1;
    if(sp_dec <0.0 && count>0 && flag2 ==1)
	{
	  count--;
	  flag2= 0;
	}
     if (sp_dec >0.0) flag2=1;
	  

    c2 = (0.8 + (count/10.0)) ;

    if ((y_axis_val>0.25) && (fabs(y_axis_val)>fabs(x_axis_val)))
	{
		
	    vel.left = c2 * y_axis_val*70;
        vel.right = c2 * y_axis_val*70;
        
	}

	
	else if ((y_axis_val< (-0.25)) && (fabs(y_axis_val)>fabs(x_axis_val)))
	{
		
	    vel.left = (c2 * y_axis_val)*70;
        vel.right = (c2 * y_axis_val)*70;

	}
	
	
	else if ((x_axis_val>0.25) && (fabs(x_axis_val)>fabs(y_axis_val)))
	{
		
	    vel.left = -c2 * x_axis_val*70;
        vel.right = c2 * x_axis_val*70;
        
	}

	else if ((x_axis_val < (-0.25)) && (fabs(x_axis_val)>fabs(y_axis_val)))
	{
	    vel.left = -c2 * x_axis_val*70;
        vel.right = c2 * x_axis_val*70;
        
	}

	else 
	{
	    vel.left = 0;
        vel.right =  0;
	}
	
	if(cnt==5)
           {
            
            vel.reset_flag = 1;
           	cnt=0;
           }
            cnt++;
    vel_pub.publish(vel);
	loop_rate.sleep();
}
    ros::spin();
    return 0;
}
