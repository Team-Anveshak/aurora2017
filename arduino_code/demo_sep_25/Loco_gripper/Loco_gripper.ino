/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/Arm.h>


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

#define dir_grip1 40
#define dir_grip2 38
#define dir_rot1  36
#define dir_rot2  34
#define ena_grip  12
#define ena_rot   11



float left=0,right=0; 
int reset_flag;

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

  

  
  left = map(RoverVelocity.left,-70,70,-175,175);
  right = map(RoverVelocity.right,-70,70,-175,175);
  

   
 

  loco(left,dir1,pwm1);
  loco(-right,dir2,pwm2);
  loco(left,dir3,pwm3);
  loco(-right,dir4,pwm4);
  loco(left,dir5,pwm5);
  loco(right,dir6,pwm6);


  
  RoverVel.left=left;
  RoverVel.right=right;
  
  
  vel_pub.publish(&RoverVel);
   
  
 }
 
 void gripperCallback(const rover_msgs::Arm& gripper)
 {
   if(gripper.grip ==1)
   {
     digitalWrite(dir_grip1,HIGH);
     digitalWrite(dir_grip2,LOW);
     analogWrite( ena_grip,200);
   }
   else if(gripper.grip ==-1)
   {
     digitalWrite(dir_grip1,LOW);
     digitalWrite(dir_grip2,HIGH);
     analogWrite( ena_grip,200);
   }
   else
   {
     analogWrite( ena_grip,0);
   }
   
   if(gripper.rotate_clk ==1)
   {
     digitalWrite(dir_rot1,HIGH);
     digitalWrite(dir_rot2,LOW);
     analogWrite( ena_rot,255);
   }
   else if(gripper.rotate_aclk ==1)
   {
     digitalWrite(dir_rot1,LOW);
     digitalWrite(dir_rot2,HIGH);
     analogWrite( ena_rot,255);
   }
   else
   {
     analogWrite( ena_rot,0);
   }
 }

 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 ros::Subscriber<rover_msgs::Arm> gripper_sub("arm", &gripperCallback);
 
 void setup(){
   nh.initNode();
 
   nh.subscribe(locomotion_sub);
   nh.subscribe(gripper_sub);
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
   
   pinMode(dir_grip1,OUTPUT);
   pinMode(dir_grip2,OUTPUT);
   pinMode(dir_rot1,OUTPUT);
   pinMode(dir_rot2,OUTPUT);
   pinMode(ena_grip,OUTPUT);
   pinMode(ena_rot,OUTPUT);
   
   

  
   
 }
 
 void loop(){
 
   nh.spinOnce();
   delay(1);
}
