#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/WheelVelPower.h>

ros::NodeHandle nh;

void locomotionCallback(const rover_msgs::WheelVelPower& locomotionVelocity){
    digitalWrite(13,HIGH - digitalRead(13));
}

ros::Subscriber<rover_msgs::WheelVelPower> sub("rover1/wheel_vel", &locomotionCallback);

void setup(){
  pinMode(13,OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}

