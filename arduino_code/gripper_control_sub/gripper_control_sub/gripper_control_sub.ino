#include <ros.h>
#include <rover_msgs/GripperMotion.h>

ros::NodeHandle nh;

void GripperMotionCallback(const rover_msgs::GripperMotion& GripperControl){
  if(GripperControl.button_1){
    digitalWrite(7,HIGH); //  gripping motor
  }
  else{
    digitalWrite(7,LOW); //  gripping motor
  }
  if(GripperControl.button_2){
    digitalWrite(8,HIGH); // gripping motor
  }
  else{
    digitalWrite(8,LOW); //  gripping motor
  }
  if(GripperControl.button_3){
    digitalWrite(5,HIGH); // pan tilt motor
  }
  else{
    digitalWrite(5,LOW); //  gripping motor
  }
  if(GripperControl.button_4){
    digitalWrite(6,HIGH); // pan tilt motor
  }
  else{
    digitalWrite(6,LOW); //  gripping motor
  }
  if(GripperControl.button_5){
    digitalWrite(2,HIGH); // roll motor
  }
  else{
    digitalWrite(2,LOW); //  gripping motor
  }
  if(GripperControl.button_6){
    digitalWrite(4,HIGH); // roll motor
  }
  else{
    digitalWrite(4,LOW); //  gripping motor
  }
}

ros::Subscriber<rover_msgs::GripperMotion> gripper_sub("rover1/gripper_turn", &GripperMotionCallback);

void setup(){
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(gripper_sub);
}

void loop(){  
  nh.spinOnce();
  delay(100);
} 
