/* 
 * rosserial Subscriber For Locomotion Control
 */

#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>

ros::NodeHandle nh;
/*
*RoverVelocity is an array of the velocity valuesin order:
* 0 left_front_vel
* 1 right_front_vel
* 2 left_middle_vel
* 3 right_middle_vel
* 4 left_back_vel
* 5 right_back_vel
*/
void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  analogWrite(A0, RoverVelocity[0]);
  analogWrite(A1, RoverVelocity[1]);
  analogWrite(A2, RoverVelocity[2]);
  analogWrite(A3, RoverVelocity[3]);
  analogWrite(A4, RoverVelocity[4]);
  analogWrite(A5, RoverVelocity[5]);  
}

void cameraMotionCallback(const rover_msgs::WheelVelocity& CameraVelocity){
  
}

ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
ros::Subscriber<rover_msgs::WheelVelocity> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop(){
  nh.spinOnce();
  delay(1);
}