#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif 
#include <ros.h>
#include <rover_msgs/RouterAngle.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte rxAddr[6] = "00001";

unsigned long x;

ros::NodeHandle  nh;

rover_msgs::RouterAngle anglemsg;
rover_msgs::RouterAngle msg;


ros::Publisher angle_pub("angle_topic",&anglemsg);



void angle_cb( const rover_msgs::RouterAngle& msg){
  x=msg.angle; //set servo angle, should be from 0-180    
}



ros::Subscriber<rover_msgs::RouterAngle> sub("/rover1/routerAngle", angle_cb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(angle_pub);
  Serial.begin(9600);
  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  radio.stopListening();
  
}

void loop(){
  nh.spinOnce();
  //Sending via nrf24l01 module
  radio.write(&x,sizeof(unsigned long));
  Serial.print("Current angle position of servo : ");
  Serial.println(x);
  Serial.print("\n");
  delay(1);
}
