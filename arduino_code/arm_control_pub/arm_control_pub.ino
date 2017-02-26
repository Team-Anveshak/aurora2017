#include <ros.h>
#include <rover_msgs/ArmAngle.h>

#define potPin1 A3
#define potPin2 A4

ros::NodeHandle nh;

int mimic_1,mimic_2;
float ref_1, ref_2;

rover_msgs::ArmAngle ArmMotion;
ros::Publisher arm_pub("rover1/arm_angles", &ArmMotion);

void UpdatePotValues(){
  mimic_1 = analogRead(potPin1);
  mimic_2 = analogRead(potPin2);
}

void AnalogToAngles(){
  ref_1 = ((mimic_1-32)/3.8);
  ref_2 = ((587-mimic_2)/3.74);    
}

void setup() {
  pinMode(potPin1, INPUT); 
  pinMode(potPin2, INPUT);
  nh.initNode(); 
  nh.advertise(arm_pub);
}

void loop() {
  UpdatePotValues();
  
  AnalogToAngles();
  delay(50);

  ArmMotion.angle_1 = ref_1;
  ArmMotion.angle_2 = ref_2; 

//  nh.loginfo(nh.get_caller_id()+"value 1 %f",ref_1);
 // nh.loginfo(nh.get_caller_id()+"value 2 %f",ref_2);
  arm_pub.publish(&ArmMotion);  
  nh.spinOnce();
  delay(10);
}
