#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif
#include <Servo.h> 
#include <ros.h>
#include <rover_msgs/RouterAngle.h>

ros::NodeHandle  nh;

Servo servo;

void servo_cb( const rover_msgs::RouterAngle& msg){
  servo.write(msg.angle); //set servo angle, should be from 0-180    
}

ros::Subscriber<rover_msgs::RouterAngle> sub("/rover1/routerAngle", servo_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
  servo.attach(9); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}
