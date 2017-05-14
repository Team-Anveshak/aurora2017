#include<ros.h>
#include<sensor_msgs/Joy.h>
#include<Servo.h>
#include<rover_msgs/ArmAngle.h>

#define Actuator 3
#define Chain 4

#define Base_fdir 11
#define Base_bdir 12

Servo Chn,Act;

ros::NodeHandle nh;

rover_msgs::ArmAngle msg;
ros::Publisher arm_pub("Arm_vel", &msg);

void CallBack(const sensor_msgs::Joy& joy)
{
  if(joy.buttons[3]==1){
    Act.writeMicroseconds(1900);
    msg.angle_1=1900;
  }
  else if(joy.buttons[0]==1){
    Act.writeMicroseconds(1100);   
    msg.angle_1=1100;
  }
  else{
    Act.writeMicroseconds(1500);
    msg.angle_1=1500;
  }
  if(joy.buttons[1]==1){
    Chn.writeMicroseconds(1700);
    msg.angle_2=1700;
  }
  else if(joy.buttons[2]==1){
    Chn.writeMicroseconds(1300);    
    msg.angle_2=1300;
  }
  else{
    Chn.writeMicroseconds(1500);
    msg.angle_2=1500;
  }
  /*if(joy.buttons[5]==1){
    digitalWrite(Base_fdir,HIGH);
    digitalWrite(Base_bdir,LOW);    
  }
  if(joy.axes[4]<=-0.9 && joy.buttons[5]==0){
    digitalWrite(Base_bdir,HIGH);
    digitalWrite(Base_fdir,LOW);    
  }
 */
  arm_pub.publish(&msg);
}

ros::Subscriber<sensor_msgs::Joy> sub("joy", &CallBack);

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  Act.attach(Actuator,1000,2000);             
  Chn.attach(Chain,1000,2000);

  Act.writeMicroseconds(1500);
  Chn.writeMicroseconds(1500);
  
  pinMode(Base_fdir,OUTPUT);
  pinMode(Base_bdir,OUTPUT);

  nh.advertise(arm_pub);

}

void loop() {
  nh.spinOnce();
  delay(1);
}
