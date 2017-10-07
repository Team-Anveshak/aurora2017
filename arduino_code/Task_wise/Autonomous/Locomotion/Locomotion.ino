/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/Arm.h>
#include <avr/wdt.h>

#define dir1 33
#define pwm1 9
#define dir2 31
#define pwm2 8
#define dir3 29
#define pwm3 7
#define dir4 27
#define pwm4 6
#define dir5 25
#define pwm5 5
#define dir6 23
#define pwm6 4





float left=0,right=0; 
int reset_flag;

ros::NodeHandle nh;


/*rover_msgs::WheelVelocity RoverVel;
ros::Publisher vel_pub("rover1/wheel", &RoverVel);*/

void loco(int vel,int dir_pin,int pwm_pin)
{
if(vel<=0)
  {
   digitalWrite(dir_pin,LOW);
   analogWrite(pwm_pin,abs(vel));
  }
else
  { 
    digitalWrite(dir_pin,HIGH);
    analogWrite(pwm_pin,abs(vel));
  }
   
  
}




void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){

  

  
  left = map(RoverVelocity.left,-70,70,-150,150);
  right = map(RoverVelocity.right,-70,70,-150,150);
  

  
   if(RoverVelocity.reset_flag==1) reset_flag=1;
   
 

  loco(left,dir1,pwm1);
  loco(-right,dir2,pwm2);//Wheels were running in the oppposite direction
  loco(left,dir3,pwm3);
  loco(-right,dir4,pwm4);//Wheels were running in the oppposite direction
  loco(left,dir5,pwm5);
  loco(right,dir6,pwm6);


  
  /*RoverVel.left=left;
  RoverVel.right=right;
  
  vel_pub.publish(&RoverVel);*/
   
  
 }
 
 

 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 
 
 void setup(){
   nh.initNode();
 
   nh.subscribe(locomotion_sub);
   //nh.advertise(vel_pub);
   
   wdt_disable();
   wdt_enable(WDTO_8S);
  
 
   pinMode(dir1,OUTPUT);
   pinMode(dir2,OUTPUT);
   pinMode(dir3,OUTPUT);
   pinMode(dir4,OUTPUT);
   pinMode(dir5,OUTPUT);
   pinMode(dir6,OUTPUT); 
  
   pinMode(pwm1,OUTPUT);
   pinMode(pwm2,OUTPUT);
   pinMode(pwm3,OUTPUT);
   pinMode(pwm4,OUTPUT);
   pinMode(pwm5,OUTPUT);
   pinMode(pwm6,OUTPUT);

  
   
 }
 
 void loop(){
   
    
   if(reset_flag==1)  wdt_reset();
   reset_flag=0;
 
   nh.spinOnce();
   delay(1);
}
