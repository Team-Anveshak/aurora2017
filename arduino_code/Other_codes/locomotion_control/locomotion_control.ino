#include <ros.h>
#include <rover_msgs/WheelVelocity.h>


#define fr_1A 10
#define fr_1B 11
#define br_2A 12
#define br_2B 13

#define dir_ml 6
#define pwm_ml 7  

#define dir_mr 8 
#define pwm_mr 9

#define fl_1A 3
#define fl_1B 2
#define bl_2A 5
#define bl_2B 4


ros::NodeHandle nh;

//creating the message object Rovervel of the message WheelVelocity
rover_msgs::WheelVelocity RoverVel;
ros::Publisher vel_pub("rover1/wheel", &RoverVel);
 
void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  digitalWrite(13,HIGH- digitalRead(13));

  if((int)RoverVelocity.left_front_vel>=0){
      digitalWrite(fl_1A,LOW);
      analogWrite(fl_1B,map((int)RoverVelocity.left_front_vel,0,5,0,255));
    }    
  else{
      analogWrite(fl_1A,map(-(int)RoverVelocity.left_front_vel,0,5,0,255));
      digitalWrite(fl_1B,LOW);
    }
      
  if((int)RoverVelocity.right_front_vel>=0){
      digitalWrite(fr_1A,LOW);
      analogWrite(fr_1B,map((int)RoverVelocity.right_front_vel,0,5,0,255));
    }    
  else{
      analogWrite(fr_1A,map(-(int)RoverVelocity.right_front_vel,0,5,0,255));
      digitalWrite(fr_1B,LOW);
    }



  if((int)RoverVelocity.left_middle_vel>=0){
      analogWrite(pwm_ml,map((int)RoverVelocity.left_middle_vel,0,5,0,255));
      digitalWrite(dir_ml,HIGH);
    }    
  else{
      analogWrite(pwm_ml,map(-(int)RoverVelocity.left_middle_vel,0,5,0,255));
      digitalWrite(dir_ml,LOW);
    }
  if((int)RoverVelocity.right_middle_vel>=0){
      analogWrite(pwm_mr,map((int)RoverVelocity.right_middle_vel,0,5,0,255));
      digitalWrite(dir_mr,LOW);
    }    
  else{
      analogWrite(pwm_mr,map(-(int)RoverVelocity.right_middle_vel,0,5,0,255));
      digitalWrite(dir_mr,HIGH);
    }



  if((int)RoverVelocity.left_back_vel>=0){
      digitalWrite(bl_2A,LOW);
      analogWrite(bl_2B,map((int)RoverVelocity.left_back_vel,0,5,0,255));
    }    
  else{
      analogWrite(bl_2A,map(-(int)RoverVelocity.left_back_vel,0,5,0,255));
      digitalWrite(bl_2B,LOW);
    }
      
  if((int)RoverVelocity.right_back_vel>=0){
      digitalWrite(br_2A,LOW);
      analogWrite(br_2B,map((int)RoverVelocity.right_back_vel,0,5,0,255));
    }    
  else{
      analogWrite(br_2A,map(-(int)RoverVelocity.right_back_vel,0,5,0,255));
      digitalWrite(br_2B,LOW);
    }  

 
  RoverVel.left_front_vel = map((int)RoverVelocity.left_front_vel,0,5,0,255);
  RoverVel.right_front_vel = map((int)RoverVelocity.right_front_vel,0,5,0,255);
  RoverVel.left_middle_vel = map((int)RoverVelocity.left_middle_vel,0,5,0,255);
  RoverVel.right_middle_vel = map((int)RoverVelocity.right_middle_vel,0,5,0,255);
  RoverVel.left_back_vel = map((int)RoverVelocity.left_back_vel,0,5,0,255);
  RoverVel.right_back_vel = map((int)RoverVelocity.right_back_vel,0,5,0,255);
  vel_pub.publish(&RoverVel);
  
}

//creating a subscriber for the WheelVelocity and of the topic rover1/wheel_vel
ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(locomotion_sub);
  nh.advertise(vel_pub);
  pinMode(fl_1A,OUTPUT);
  pinMode(fl_1B,OUTPUT);
  pinMode(fr_1A,OUTPUT);
  pinMode(fr_1B,OUTPUT);
  pinMode(bl_2A,OUTPUT);
  pinMode(bl_2B,OUTPUT);
  pinMode(bl_2A,OUTPUT);
  pinMode(bl_2B,OUTPUT);
  pinMode(pwm_ml,OUTPUT);
  pinMode(dir_ml,OUTPUT);
  pinMode(pwm_mr,OUTPUT);
  pinMode(dir_mr,OUTPUT);  
  pinMode(13,OUTPUT);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
