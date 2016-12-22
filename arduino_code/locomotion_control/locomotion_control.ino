/* 
 * rosserial Subscriber For Locomotion Control
 */

#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
#include <std_msgs/String.h>


ros::NodeHandle nh;

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


void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  str_msg.data = "hello";
  chatter.publish( &str_msg );
  /*analogWrite(A0, RoverVelocity[0]);
  analogWrite(A1, RoverVelocity[1]);
  analogWrite(A2, RoverVelocity[2]);
  analogWrite(A3, RoverVelocity[3]);
  analogWrite(A4, RoverVelocity[4]);
  analogWrite(A5, RoverVelocity[5]); 
 */ 
}



ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(locomotion_sub);

// pin arrangements for wheel motors in the above order...
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

}

void loop(){
  nh.spinOnce();
  delay(1);
}
