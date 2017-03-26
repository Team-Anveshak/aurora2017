#include<ros.h>
#include <rover_msgs/GPS.h>
#include<Arduino.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

ros::NodeHandle nh;
rover_msgs::GPS values;

ros::Publisher GPS ("test1",&values);

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 4800;

TinyGPSPlus gps;


SoftwareSerial ss(RXPin, TXPin);


void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);


  nh.initNode();
  nh.advertise(GPS);
  
}

void loop()
{
  
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
     {
      values.inst_lat= gps.location.lat();
      values.inst_lng = gps.location.lng();
     }

     GPS.publish(&values);
     nh.spinOnce();
}


