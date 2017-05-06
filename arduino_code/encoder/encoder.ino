#include<ros.h>
#include <rover_msgs/Enc.h>
#include<Arduino.h>


ros::NodeHandle nh;
rover_msgs::Enc rpm;
ros::Publisher Enc("Enc_pub",&rpm);

int encoder_pin = 2;             
unsigned int Rpm;     
volatile byte pulses;  
unsigned long timeold; 

unsigned int pulsesperturn = 20;

 void counter()
 {
      pulses++;    
 }

void setup()
 {
   Serial.begin(9600);
    nh.initNode();
    nh.advertise(Enc);
    
   pinMode(encoder_pin, INPUT);
   attachInterrupt(0, counter, FALLING);
   pulses = 0;
   Rpm = 0;
   timeold = 0;

 }

 void loop()
 {
   if (millis() - timeold >= 1000){  
 
   detachInterrupt(0);
   
   Rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses;
   timeold = millis();
   pulses = 0;
   
   rpm.rpm = Rpm;
   attachInterrupt(0, counter, FALLING);
   }

        Enc.publish(&rpm);
        nh.spinOnce();
   
  }
