#include <ros.h>
#include <rover_msgs/ArmAngle.h>
#include <Servo.h>

#define act_1 10 
#define act_2 9

#define potPin1 A1
#define potPin2 A2

ros::NodeHandle nh;

//int ext_speed_1 = 1800; //must be greater than 1500   
//int rtd_speed_1 = 1200; //must be lesser than 1500 

int speed_big = 1500;
int speed_small = 1500;

int pot_1, pot_2;
float angle_1, angle_2;

int mimic_1,mimic_2;
float ref_1, ref_2;

float dif = 0;
float k = 25;

Servo steerServo;
Servo driveServo;

void ArmMotionCallback(const rover_msgs::ArmAngle& ArmMotion){
  //nh.loginfo("ArmMotion.. %f %f", ArmMotion.angle_1, ArmMotion.angle_2);

  UpdatePotValues();
  AnalogToAngles(ArmMotion.angle_1,ArmMotion.angle_2);
  ImplementProportional();
}

ros::Subscriber<rover_msgs::ArmAngle> arm_sub("rover1/arm_angles", &ArmMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(arm_sub);
  
  pinMode(potPin1, INPUT); 
  pinMode(potPin2, INPUT); 
  
  steerServo.attach(act_1,1000,2000);             
  driveServo.attach(act_2,1000,2000);

  steerServo.writeMicroseconds(1500);
  driveServo.writeMicroseconds(1500);

 // Serial.begin(9600);

}

void UpdatePotValues(){
  pot_1 = analogRead(A1);
  pot_2 = analogRead(A2);
}

void AnalogToAngles(float angle1 , float angle2){
  
  angle_1 = ((pot_1-987)/3.41)*0.6+60;
  angle_2 = (597-pot_2)/3.41+90;
  ref_1 = angle1;
  ref_2 = angle2;  
  
}

void ImplementProportional(){
  if (angle_1 < ref_1-4 )  speed_small = 2000;
  else if(angle_1 < ref_1+4)  speed_small = 1500;
  else speed_small = 1000;

  driveServo.writeMicroseconds(speed_small);
  //Serial.print(speed_small);
  //Serial.print("\t");
  
  dif = ref_2-angle_2;
  speed_big = 1500+k*dif;  

  if(speed_big < 1000)  speed_big = 1000;
  else if(speed_big < 1300) speed_big = speed_big;
  else if(speed_big < 1500-2*k) speed_big = 1300;
  else if(speed_big < 1500+2*k) speed_big = 1500;
  else if(speed_big < 1700) speed_big = 1700;
  else if(speed_big < 2000) speed_big = speed_big;
  else speed_big = 2000;

  steerServo.writeMicroseconds(speed_big);
  //Serial.println(speed_big);
}

void loop(){  
  nh.spinOnce();
  delay(500);
}
