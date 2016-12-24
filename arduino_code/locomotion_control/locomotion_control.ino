/* 
 * rosserial Subscriber For Locomotion Control
 */

#include <ros.h>
#include <Servo.h> 
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
#include <std_msgs/String.h>
#define dcmotor_tl 3  //tl-DR1
#define dcmotor_tr 5  //tr-DR1
#define dcmotor_bl 9 //bl-DR2
#define dcmotor_br 10 //br-DR3
#define dcmotor_br2 6
#define dcmotor_bl2 11

ros::NodeHandle nh;

Servo driveServo1;
Servo steerServo1;
Servo driveServo2;
Servo driveServo3;
Servo steerServo2;
Servo steerServo3;

//rover_msgs::CameraMotion camFeedback[4];
//rover_msgs::WheelVelocity wheelFeedback[6];

/*
*RoverVelocity is an array of the velocity values in order:
* 0 left_front_vel
* 1 right_front_vel
* 2 left_middle_vel
* 3 right_middle_vel
* 4 left_back_vel
* 5 right_back_vel
*/

int tl = 0,tr = 0,bl = 0,br = 0;

void Locomotion(int tl,int tr,int bl,int br)
{
//SetSpeed(servoAddr1,theta); // theta between -2147483648 and 2147483648 
//SetSpeed(servoAddr2,theta);
driveServo1.writeMicroseconds(tl);
steerServo1.writeMicroseconds(tr);
driveServo2.writeMicroseconds(bl);
//steerServo2.writeMicroseconds(1500);
driveServo3.writeMicroseconds(br);
//steerServo2.writeMicroseconds(1500);
  
}

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  str_msg.data = "hello";
  chatter.publish( &str_msg );
  tl = (int)RoverVelocity.left_front_vel;
  tr = (int)RoverVelocity.right_front_vel;
  bl = (int)RoverVelocity.left_vel;
  br = (int)RoverVelocity.right_vel;

  tl=(tl+100)*10;
  tr=(tr+100)*10;
  bl=(bl+100)*10;
  br=(br+100)*10;
  
  tl=tl/2+750;
  tr=tr/2+750;
  bl=bl/2+750;
  br=br/2+750;
  
  Locomotion(tl,tr,bl,br);
}

ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(locomotion_sub);

driveServo1.attach(dcmotor_tl,1000,2000);            
steerServo1.attach(dcmotor_tr,1000,2000);             
driveServo2.attach(dcmotor_bl,1000,2000);
steerServo2.attach(dcmotor_bl2,1000,2000);
driveServo3.attach(dcmotor_br,1000,2000);
steerServo3.attach(dcmotor_br2,1000,2000);
driveServo1.writeMicroseconds(1500);
steerServo1.writeMicroseconds(1500);
driveServo2.writeMicroseconds(1500);
steerServo2.writeMicroseconds(1500);
driveServo3.writeMicroseconds(1500);
steerServo3.writeMicroseconds(1500);

}

void loop(){
  nh.spinOnce();
  delay(1);
}