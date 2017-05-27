#include<ros.h>
#include <rover_msgs/GPS.h>
#include<Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
//Incuding all the necessary headers and messages
ros::NodeHandle nh; //initiating the node handler
rover_msgs::GPS values; // creating a GPS message and naming it values

ros::Publisher GPS ("test1",&values); // initialising the publisher for the GPS


static const int RXPin = 4, TXPin = 3; // initiating the static constants for pins of arduino
static const uint32_t GPSBaud = 4800;  // initiating the baud rate of the gps communication link

TinyGPSPlus gps; // creating a tinygps object


SoftwareSerial ss(RXPin, TXPin);


void setup()
{
  // initialising the communication with the arduino at 115200 baud rate
  Serial.begin(115200);
  ss.begin(GPSBaud);


  nh.initNode();
  // advertising the nodehandler to the GPS
  nh.advertise(GPS);

}

void loop()
{

  // Getting the latitude and longitude of the position of the rover
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
    {
      values.inst_lat= gps.location.lat();
      values.inst_lng = gps.location.lng();
    }
//publishing the values to the message
  GPS.publish(&values);
  nh.spinOnce();
}



