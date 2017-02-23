/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelPower.h>

int dir1=2;
int pwm1=3;
int dir2=4;
int pwm2=5;
int dir3=7;
int pwm3=6;
int dir4=8;
int pwm4=9;
int dir5=12;
int pwm5=10;
int dir6=13;
int pwm6=11;

//int tl,tr,ml,mr,bl,br;

//float k1,k2,k3, mink;

float tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
//float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

ros::NodeHandle nh;

rover_msgs::WheelVelPower RoverVelocity;

//ros::Publisher vel_pub("rover1/wheel", &RoverVelocity);

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


void roverMotionCallback(const rover_msgs::WheelVelPower& RoverVelocity){
  tl = map(RoverVelocity.left_front_vel,0,50,0,255);
  tr = map(RoverVelocity.right_front_vel,0,50,0,255);
  ml = map(RoverVelocity.left_middle_vel,0,50,0,255);
  mr = map(RoverVelocity.right_middle_vel,0,50,0,255);
  bl = map(RoverVelocity.left_back_vel,0,50,0,255);
  br = map(RoverVelocity.right_back_vel,0,50,0,255);
  
 
   
  loco(tl,dir1,pwm1);
  loco(tr,dir2,pwm2);
  loco(ml,dir3,pwm3);
  loco(mr,dir4,pwm4);
  loco(bl,dir5,pwm5);
  loco(br,dir6,pwm6);
 }
 
 ros::Subscriber<rover_msgs::WheelVelPower> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 
 void setup(){
   nh.initNode();
   nh.subscribe(locomotion_sub);
 
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
   nh.spinOnce();
   delay(10);
}
