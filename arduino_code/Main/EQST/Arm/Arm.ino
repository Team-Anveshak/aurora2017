#include<ros.h>
#include<rover_msgs/Arm.h>
#include<Servo.h>
#include<rover_msgs/ArmAngle.h>
#include <avr/wdt.h>

#define Actuator 3
#define Chain 4
#define base 5
#define wris 6

int reset_flag;

Servo Chn,Act,bas,wri;

ros::NodeHandle nh;

rover_msgs::ArmAngle msg;
ros::Publisher arm_pub("Arm_vel", &msg);

void CallBack(const rover_msgs::Arm& arm)
{
  if(arm.acc_forw==1){
    
    Act.writeMicroseconds(1100);   
    msg.angle_1=1100;
  }
  else if(arm.acc_back==1)
  {
    Act.writeMicroseconds(1900);
    msg.angle_1=1900;
  }
  else{
    Act.writeMicroseconds(1500);
    msg.angle_1=1500;
  }
  
  
  if(arm.chain_forw==1){
    Chn.writeMicroseconds(1750);
    msg.angle_2=1700;
  }
  else if(arm.chain_back==1){
    Chn.writeMicroseconds(1250);    
    msg.angle_2=1300;
  }
  else{
    Chn.writeMicroseconds(1500);
    msg.angle_2=1500;
  }
  
  
  if(arm.base_right==1){
    bas.writeMicroseconds(1800);
    msg.angle_2=1700;
  }
  else if(arm.base_left==1){
    bas.writeMicroseconds(1200);    
    msg.angle_2=1300;
  }
  else{
    bas.writeMicroseconds(1500);
    msg.angle_2=1500;
  }
  
  
  if(arm.wrist==1){
    wri.writeMicroseconds(1700);
    msg.angle_2=1700;
  }
  else if(arm.wrist==-1){
    wri.writeMicroseconds(1300);    
    msg.angle_2=1300;
  }
  else{
    wri.writeMicroseconds(1500);
    msg.angle_2=1500;
  }
  if(arm.reset_flag==1) reset_flag=1;
  
  arm_pub.publish(&msg);
}

ros::Subscriber<rover_msgs::Arm> sub("arm", &CallBack);

void setup() {
  nh.initNode();
  nh.subscribe(sub);
  
  wdt_disable();
  wdt_enable(WDTO_8S);

  Act.attach(Actuator,1000,2000);             
  Chn.attach(Chain,1000,2000);
  bas.attach(base,1000,2000); 
  wri.attach(wris,1000,2000); 

  Act.writeMicroseconds(1500);
  Chn.writeMicroseconds(1500);
  bas.writeMicroseconds(1500);
  wri.writeMicroseconds(1500);
  
  nh.advertise(arm_pub);

}

void loop() {
  
  if(reset_flag==1)  wdt_reset();
  reset_flag=0;
 
  nh.spinOnce();
  delay(1);
}
