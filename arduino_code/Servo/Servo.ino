#include<ros.h>
#include<Arduino.h>
#include<Servo.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int8.h>


Servo servo;
#define servo_pin 6

int angle=0;
int theta;
int flag=1;
ros::NodeHandle nh;

std_msgs::Int8 th;
ros::Publisher theta_pub("cam/theta",&th);

void Callback(const std_msgs::Float32 msg){
  if(msg.data==1){
    flag=0;
    th.data=angle;
    theta_pub.publish(&th);
  }
  
}


ros::Subscriber<std_msgs::Float32> flag_sub("/rover1/FLAG_Camera", &Callback);

void setup() {
  nh.initNode();
  nh.subscribe(flag_sub);
  nh.advertise(theta_pub);
  servo.attach(servo_pin);
}

void loop() {
  if(flag==1){
  	angle=(angle%180);
	  servo.write(angle);
	  angle++;
  }
  nh.spinOnce();
  delay(100);
}