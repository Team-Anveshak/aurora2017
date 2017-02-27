/* rosserial Subscriber For Locomotion Control */
#include <ros.h>
<<<<<<< HEAD
#include <rover_msgs/WheelVelPower.h>
=======
>>>>>>> 4accc70fcee837d69764f60f9ca2f4c55a6f5e36
#include <rover_msgs/WheelVelocity.h>

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

float tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;

ros::NodeHandle nh;

<<<<<<< HEAD
rover_msgs::WheelVelPower RoverVelocity;
rover_msgs::WheelVelocity RoverPub;

=======
rover_msgs::WheelVelocity RoverVel;
ros::Publisher vel_pub("rover1/wheel", &RoverVel);
>>>>>>> 4accc70fcee837d69764f60f9ca2f4c55a6f5e36

/*
void loco(int vel,int dir_pin,int pwm_pin)
{
    if(vel<=0){
        digitalWrite(dir_pin,LOW);
        analogWrite(pwm_pin,abs(vel));
    }
    else{ 
        digitalWrite(dir_pin,HIGH);
        analogWrite(pwm_pin,abs(vel));
    }
}
*/

<<<<<<< HEAD
void Callback(rover_msgs::WheelVelPower& RoverVelocity){
    /*
    tl = map(RoverVelocity.left_front_vel,0,50,0,255);
    tr = map(RoverVelocity.right_front_vel,0,50,0,255);
    ml = map(RoverVelocity.left_middle_vel,0,50,0,255);
    mr = map(RoverVelocity.right_middle_vel,0,50,0,255);
    bl = map(RoverVelocity.left_back_vel,0,50,0,255);
    br = map(RoverVelocity.right_back_vel,0,50,0,255);
    */
    
    tl = RoverVelocity.left_front_vel;
    tr = RoverVelocity.right_front_vel;
    ml = RoverVelocity.left_middle_vel;
    mr = RoverVelocity.right_middle_vel;
    bl = RoverVelocity.left_back_vel;
    br = RoverVelocity.right_back_vel;
    digitalWrite(13, HIGH - digitalRead(13));
    /*
    loco(tl,dir1,pwm1);
    loco(tr,dir2,pwm2);
    loco(ml,dir3,pwm3);
    loco(mr,dir4,pwm4);
    loco(bl,dir5,pwm5);
    loco(br,dir6,pwm6);
    */
 }
 
 ros::Subscriber<rover_msgs::WheelVelPower> locomotion_sub("rover1/wheel_vel",Callback);
 ros::Publisher vel_pub("rover1/wheel", &RoverPub); 
 
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
=======

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  tl = map(RoverVelocity.left_front_vel,-50,50,-255,255);
  tr = map(RoverVelocity.right_front_vel,-50,50,-255,255);
  ml = map(RoverVelocity.left_middle_vel,-50,50,-255,255);
  mr = map(RoverVelocity.right_middle_vel,-50,50,-255,255);
  bl = map(RoverVelocity.left_back_vel,-50,50,-255,255);
  br = map(RoverVelocity.right_back_vel,-50,50,-255,255);

   
  RoverVel.left_front_vel = map((int)RoverVelocity.left_front_vel,-50,50,-255,255);
  RoverVel.right_front_vel = map((int)RoverVelocity.right_front_vel,-50,50,-255,255);
  RoverVel.left_middle_vel = map((int)RoverVelocity.left_middle_vel,-50,50,-255,255);
  RoverVel.right_middle_vel = map((int)RoverVelocity.right_middle_vel,-50,50,-255,255);
  RoverVel.left_back_vel = map((int)RoverVelocity.left_back_vel,-50,50,-255,255);
  RoverVel.right_back_vel = map((int)RoverVelocity.right_back_vel,-50,50,-255,255);
  vel_pub.publish(&RoverVel);
   
  loco(tl,dir1,pwm1);
  loco(tr,dir2,pwm2);
  loco(ml,dir3,pwm3);
  loco(mr,dir4,pwm4);
  loco(bl,dir5,pwm5);
  loco(br,dir6,pwm6);
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
>>>>>>> 4accc70fcee837d69764f60f9ca2f4c55a6f5e36
  
    pinMode(pwm1,OUTPUT);
    pinMode(pwm2,OUTPUT);
    pinMode(pwm3,OUTPUT);
    pinMode(pwm4,OUTPUT);
    pinMode(pwm5,OUTPUT);
    pinMode(pwm6,OUTPUT);
 }
 
 void loop(){
    //nh.spinOnce();

    RoverPub.left_front_vel=tl;
    RoverPub.right_front_vel=tr;
    RoverPub.left_middle_vel=ml;
    RoverPub.right_middle_vel=mr;
    RoverPub.left_back_vel=bl;
    RoverPub.right_back_vel=br;
  
    vel_pub.publish(&RoverPub);
    nh.spinOnce();
    delay(10);
}
