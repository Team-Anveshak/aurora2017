/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>




#define dir1 25
#define pwm1 3
#define dir2 23
#define pwm2 2
#define dir3 29
#define pwm3 5
#define dir4 27
#define pwm4 4
#define dir5 3
#define pwm5 7
#define dir6 31
#define pwm6 6



int tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

ros::NodeHandle nh;


rover_msgs::WheelVelocity RoverVel;
ros::Publisher vel_pub("rover1/wheel", &RoverVel);

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

  

  lt = map(RoverVelocity.left_front_vel,-70,70,175,175);
  rt = map(RoverVelocity.right_front_vel,-70,70,175,175);
  lm = map(RoverVelocity.left_middle_vel,-70,70,175,175);
  rm = map(RoverVelocity.right_middle_vel,-70,70,175,175);
  lb = map(RoverVelocity.left_back_vel,-70,70,175,175);
  rb = map(RoverVelocity.right_back_vel,-70,70,175,175);
  
  tl = (int)lt;///k1*mink;
  tr = (int)rt;///k1*mink;
   
  ml = (int)lm;///k2*mink;
  mr = (int)rm;///k2*mink;
   
  bl = (int)lb;///k3*mink;
  br = (int)rb;///k3*mink;

  loco(tl,dir1,pwm1);
  loco(tr,dir2,pwm2);
  loco(ml,dir3,pwm3);
  loco(mr,dir4,pwm4);
  loco(bl,dir5,pwm5);
  loco(br,dir6,pwm6);
  
  RoverVel.left_front_vel=tl;
  RoverVel.right_front_vel=tr;
  RoverVel.left_middle_vel=ml;
  RoverVel.right_middle_vel=mr;
  RoverVel.left_back_vel=bl;
  RoverVel.right_back_vel=br;
  
  vel_pub.publish(&RoverVel);
 

 }
 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 
 void setup(){
   nh.initNode();
 
   nh.subscribe(locomotion_sub);
   nh.advertise(vel_pub);
 
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
   delay(1);
}
