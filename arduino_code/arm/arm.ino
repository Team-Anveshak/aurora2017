#include<ros.h>
#include<sensor_msgs/Joy.h>

#define Actuator_fdir 30
#define Actuator_bdir 31
#define Chain_fdir 32
#define Chain_bdir 33
#define Base_fdir 34
#define Base_bdir 35

ros::NodeHandle nh;

void CallBack(const sensor_msgs::Joy& joy)
{
  if(joy.axes[5]>=0.9){
    digitalWrite(Actuator_fdir,HIGH);
    digitalWrite(Actuator_bdir,LOW);
  }
  else if(joy.axes[5]<=-0.9){
    digitalWrite(Actuator_bdir,HIGH);
    digitalWrite(Actuator_fdir,LOW);    
  }
  if(joy.axes[4]<=-0.9){
    digitalWrite(Base_fdir,HIGH);
    digitalWrite(Base_bdir,LOW);    
  }
  else if(joy.axes[4]>=0.9){
    digitalWrite(Base_bdir,HIGH);
    digitalWrite(Base_fdir,LOW);    
  }
  if(joy.buttons[6]==1){
    digitalWrite(Chain_fdir,HIGH);
    digitalWrite(Chain_bdir,LOW);    
  }
  if(joy.axes[6]<=-0.9 && joy.buttons[6]==0){
    digitalWrite(Chain_bdir,HIGH);
    digitalWrite(Chain_fdir,LOW);    
  }
}

ros::Subscriber<sensor_msgs::Joy> sub("joy", &CallBack);

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  pinMode(Actuator_fdir,OUTPUT);
  pinMode(Actuator_bdir,OUTPUT);
  pinMode(Chain_fdir,OUTPUT);
  pinMode(Chain_bdir,OUTPUT);
  pinMode(Base_fdir,OUTPUT);
  pinMode(Base_bdir,OUTPUT);

}

void loop() {
  nh.spinOnce();
  delay(1);
}
