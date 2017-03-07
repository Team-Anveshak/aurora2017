//ARM CONTROL PUBLISHER NODE



//including the ros library and including the ArmAngle message library
#include <ros.h>
#include <rover_msgs/ArmAngle.h>

//Definining the pins for the potentiometer
#define potPin1 A3
#define potPin2 A4

//Creating the ros NodeHandle object
ros::NodeHandle nh;

//Defining the variables for storing and for computation
int mimic_1,mimic_2;
float ref_1, ref_2;

//Creating an ArmAngle message object and Defining the arm_pub publisher of the topic rover1/arm_angles and it adresses ArmMotion object 
rover_msgs::ArmAngle ArmMotion;
ros::Publisher arm_pub("rover1/arm_angles", &ArmMotion);

//Function gets the analog values from the potentiometer connected to the arduino(connected to the mimic arm) and assigns its values to the varibles mimic_1 and mimic_2
void UpdatePotValues(){
  mimic_1 = analogRead(potPin1);
  mimic_2 = analogRead(potPin2);
}

//Function to conver the analog values of the potentiometer to the angles
void AnalogToAngles(){
  ref_1 = ((mimic_1-32)/3.8);
  ref_2 = ((587-mimic_2)/3.74);    
}

//Function sets up the pinmodes and initialises the ros and it advertises to the arm_pub publisher
void setup() {
  pinMode(potPin1, INPUT); 
  pinMode(potPin2, INPUT);
  nh.initNode(); 
  nh.advertise(arm_pub);
}


//Function initialises all the other functions and publishes to the ArmMotion message object
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
