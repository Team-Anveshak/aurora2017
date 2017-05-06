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

class LocomotionControl{
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
    joy_sub = nh.subscribe<sensor_msgs::Joy>("/joy",10,&LocomotionControl::joyCallback,this);
}

//      @x_axis_value- x axis position of joystick controller
//      @y_axis_value- y axis position of joystick controller
//      @scale- magnitude of a vector, lies between (0, 5)
//      @angle- horizontal plane angle made by controller
void LocomotionControl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy){
    rover_msgs::WheelVelocity vel;
    
    float x_axis_val = joy->axes[0];
    float y_axis_val = joy->axes[1];
    float sp_inc = joy->axes[5];
    float sp_dec = joy->axes[2];
    static float count= 0;
    static float c2;
    static int flag,flag2 ;

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

    //double angle = atan2(y_axis_val,x_axis_val);

    //float scale = sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val);
    //ROS_INFO_STREAM("scale : " << scale);
    float e= 4;
    float b = 45;
    float a = 110;
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
   /* float dem = (1+ b/r)*(1+ b/r) + (a/2/r)*(a/2/r);

    float v1 = v;
    float v2 = v*( (1+b/r)*(1+b/r)/dem);
    float v3 = v* ((1+b/r)*(1+(a/2/r*a/2/r))/dem);
    float v4 = v*((1+b/r)/dem);*/


   /* if(fabs(x_axis_val)<0.2){
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
    }*/
	if ((y_axis_val>0.25) && (fabs(y_axis_val)>fabs(x_axis_val)))
	{
		
	vel.left_front_vel = c2 * y_axis_val*70;
        vel.right_front_vel = c2 * y_axis_val*70;
        vel.left_middle_vel = c2 * y_axis_val*70;
        vel.right_middle_vel = c2 * y_axis_val*70;
        vel.left_back_vel = c2 * y_axis_val*70;
	vel.right_back_vel = c2 * y_axis_val*70;
	}

	
	else if ((y_axis_val< (-0.25)) && (fabs(y_axis_val)>fabs(x_axis_val)))
	{
		
	vel.left_front_vel = (c2 * y_axis_val)*70;
        vel.right_front_vel = (c2 * y_axis_val)*70;
        vel.left_middle_vel = (c2 * y_axis_val)*70;
        vel.right_middle_vel = (c2 * y_axis_val)*70;
        vel.left_back_vel = (c2 * y_axis_val)*70;
	vel.right_back_vel = (c2 * y_axis_val)*70;
	}
	
	
	else if ((x_axis_val>0.25) && (fabs(x_axis_val)>fabs(y_axis_val)))
	{
		
	vel.left_front_vel = -c2 * x_axis_val*70;
        vel.right_front_vel = c2 * x_axis_val*70;
        vel.left_middle_vel = -c2 * x_axis_val*70;
        vel.right_middle_vel = c2 * x_axis_val*70;
        vel.left_back_vel = -c2 * x_axis_val*70;
        vel.right_back_vel = c2 * x_axis_val*70;
	}

	else if ((x_axis_val < (-0.25)) && (fabs(x_axis_val)>fabs(y_axis_val)))
	{
	vel.left_front_vel = -c2 * x_axis_val*70;
        vel.right_front_vel = c2 * x_axis_val*70;
        vel.left_middle_vel = -c2 * x_axis_val*70;
        vel.right_middle_vel = c2 * x_axis_val*70;
        vel.left_back_vel = -c2 * x_axis_val*70;
        vel.right_back_vel = c2 * x_axis_val*70;
	}

	else 
	{
	vel.left_front_vel = 0;
        vel.right_front_vel =  0;
        vel.left_middle_vel = 0;
        vel.right_middle_vel = 0;
        vel.left_back_vel =  0;
        vel.right_back_vel =  0;
	}
	

  

vel_pub.publish(vel);    
}

// @init initialises the ros
// creates a LocomotionControl object

int main(int argc, char** argv) {
    ros::init(argc,argv,"locomotion_control");
    LocomotionControl locomotion_control;
    ros::spin();
    return 0;
}
