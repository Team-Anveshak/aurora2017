/* 
 * rosserial Subscriber For Locomotion Control
 */

#include <ros.h>
#include <Servo.h> 
#include <rover_msgs/WheelVelocity.h>
#define dcmotor_fl 3 
#define dcmotor_fr 5  
#define dcmotor_ml 6 
#define dcmotor_mr 9
#define dcmotor_br 10
#define dcmotor_bl 11

ros::NodeHandle_<ArduinoHardware, 5, 5, 125, 125> nh;

Servo frontLeft;
Servo frontRight;

Servo middleLeft;
Servo middleRight;

Servo backLeft;
Servo backRight;

/*
*RoverVelocity is an array of the velocity values in order:
* 0 left_front_vel
* 1 right_front_vel
* 2 left_middle_vel
* 3 right_middle_vel
* 4 left_back_vel
* 5 right_back_vel
*/

int fl = 0,fr = 0, ml = 0, mr = 0, bl = 0, br = 0;

void Locomotion()
{
  frontLeft.writeMicroseconds(fl);
  frontRight.writeMicroseconds(fr);
  
  middleLeft.writeMicroseconds(ml);
  middleRight.writeMicroseconds(mr);
  
  backLeft.writeMicroseconds(bl);
  backRight.writeMicroseconds(br);
}

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  fl = (int)RoverVelocity.left_front_vel;
  fr = (int)RoverVelocity.right_front_vel;
  
  ml = (int)RoverVelocity.left_middle_vel;
  mr = (int)RoverVelocity.right_middle_vel;
  
  bl = (int)RoverVelocity.left_back_vel;
  br = (int)RoverVelocity.right_back_vel;

  if(abs(fl)<25){
     fl=25;fr=25;ml=25;mr=25;bl=25;br=25;
  }
  
  Locomotion();
}

ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(locomotion_sub);

  frontLeft.attach(dcmotor_fl,1000,2000);            
  frontRight.attach(dcmotor_fr,1000,2000);             
  middleLeft.attach(dcmotor_ml,1000,2000);
  middleRight.attach(dcmotor_mr,1000,2000);
  backLeft.attach(dcmotor_bl,1000,2000);
  backRight.attach(dcmotor_br,1000,2000);

  frontLeft.writeMicroseconds(1500);
  frontRight.writeMicroseconds(1500);
  middleLeft.writeMicroseconds(1500);
  middleRight.writeMicroseconds(1500);
  backLeft.writeMicroseconds(1500);
  backRight.writeMicroseconds(1500);

}

void loop(){
  nh.spinOnce();
  delay(1);
}
