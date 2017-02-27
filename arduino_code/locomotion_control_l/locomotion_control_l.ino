/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelPower.h>

int dir1=22;
int pwm1=8;
int dir2=23;
int pwm2=9;
int dir3=22;
int pwm3=8;
int dir4=23;
int pwm4=9;
int dir5=22;
int pwm5=8;
int dir6=23;
int pwm6=9;

//int tl,tr,ml,mr,bl,br;

float k1,k2,k3, mink;

int tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

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

float minK(float k1,float k2, float k3){  
  if(k1>=k2){
    if(k2>=k3){
      return k3;
      }
    else{
      return k2;}  
    }
    
  else{
    if(k1>=k3){
      return k3;
    }
    else{
      return k1;}  
    }  
  
}

void roverMotionCallback(const rover_msgs::WheelVelPower& RoverVelocity){
  
  k1 = RoverVelocity.power_1;
  k2 = RoverVelocity.power_2;
  k3 = RoverVelocity.power_3;

  mink=minK(k1,k2,k3);

  lt = map(RoverVelocity.left_front_vel,0,50,0,255);
  rt = map(RoverVelocity.right_front_vel,0,50,0,255);
  lm = map(RoverVelocity.left_middle_vel,0,50,0,255);
  rm = map(RoverVelocity.right_middle_vel,0,50,0,255);
  lb = map(RoverVelocity.left_back_vel,0,50,0,255);
  rb = map(RoverVelocity.right_back_vel,0,50,0,255);
  
  tl = (int)lt/k1*mink;
  tr = (int)rt/k1*mink;
   
  ml = (int)lm/k2*mink;
  mr = (int)rm/k2*mink;
   
  bl = (int)lb/k3*mink;
  br = (int)rb/k3*mink;
 
   
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
