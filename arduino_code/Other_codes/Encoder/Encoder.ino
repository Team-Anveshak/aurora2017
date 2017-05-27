#include<ros.h>
#include<rover_msgs/Enc.h>
#include<Arduino.h>

ros::NodeHandle nh;
rover_msgs::Enc rpm;
ros::Publisher Enc("Enc_pub",&rpm);

int encoder_1_pin = 2;
int encoder_2_pin = 3 ;           
unsigned int Rpm_enc_1,Rpm_enc_2;    
volatile byte pulses1,pulses2; 
unsigned long timeold;
unsigned long timer;
unsigned int pulsesperturn = 20;

void counter1()
{
  pulses1 = pulses1 + 1;
}

void counter2()
{
  pulses2 = pulses2 +1;
}

void setup()
{
  Serial.begin(9600);
  nh.initNode();
  nh.advertise(Enc);
  pinMode(encoder_1_pin, INPUT);
  pinMode(encoder_2_pin,INPUT);
  attachInterrupt(digitalPinToInterrupt(2), counter1, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), counter2, FALLING);
  pulses1 = 0;
  pulses2 = 0;
  Rpm_enc_1 = 0;
  Rpm_enc_2 = 0;
  timeold = 0;  
}

void loop()
{
  if (millis() - timeold >= 1000){
    detachInterrupt(digitalPinToInterrupt(2));
    detachInterrupt(digitalPinToInterrupt(3));
    timer=millis()-timeold;
    
    Rpm_enc_1 = ((60 * 1000 / pulsesperturn )/ timer)* pulses1;
    Rpm_enc_2= ((60*1000/pulsesperturn)/timer)*pulses2;
    timeold = millis();
    pulses1 = 0;
    pulses2 = 0;
    
    rpm.rpm_enc_1 = Rpm_enc_1;
    rpm.rpm_enc_2 = Rpm_enc_2;
    attachInterrupt(digitalPinToInterrupt(2), counter1, FALLING);
    attachInterrupt(digitalPinToInterrupt(3), counter2,FALLING);
  }
  Enc.publish(&rpm);
  nh.spinOnce();
}
