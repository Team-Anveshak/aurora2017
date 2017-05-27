
#include <ros.h>
#include <math.h>
#include <sensor_msgs/NavSatFix.h>
#include <rover_msgs/RouterAngle.h>
#include <stdlib.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte rxAddr[6] = "00001";

#define PI 3.1415926535897932384626433832795

double lat_initR = 12.99178849*PI/180,logg_initR = 80.2310192*PI/180, dist_init;
double lat_initB = 12.99978849*PI/180,logg_initB = 80.2910192*PI/180;
double lat,logg;
double dist,dist_diff;
unsigned long theta=0,control=876;
int c=0;

ros::NodeHandle nh;


rover_msgs::RouterAngle angle;

ros::Publisher angle_pub("angletopic", &angle);


sensor_msgs::NavSatFix gps;

int pos=0;

void gpsRouterCallback(const sensor_msgs::NavSatFix& gps){
  lat = (gps.latitude)*PI/180;
  logg = (gps.longitude)*PI/180;
  dist = (sqrt((lat_initR-lat)*(lat_initR-lat)*100 + (logg_initR-logg)*(logg_initR-logg)*100))/10.0;
  dist_diff = (sqrt((lat_initB-lat)*(lat_initB-lat)*100 + (logg_initB-logg)*(logg_initB-logg)*100))/10.0;
  theta = int(acos((dist*dist + dist_init*dist_init - dist_diff*dist_diff)/(2*dist*dist_init)));

  
  angle_pub.publish(&angle);
}


ros::Subscriber<sensor_msgs::NavSatFix> gps_sub("coordstopic", &gpsRouterCallback);

void setup() {
  
  nh.initNode();
  nh.subscribe(gps_sub);
  nh.advertise(angle_pub);
  
  radio.begin();
  Serial.begin(9600);
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
  

}
 void loop(){
   nh.spinOnce();

   
  Serial.println("Sending to reciever");
  // Send a message to nrf24_server

  if(c==0){
  if(Serial.available()){
  control = Serial.read();

  if(control==48)
   {c=10;}
  
  radio.write(&control, sizeof(control));
  
  delay(10);


  if (control == 50) {
      // Make sure not to exceed the mechanical limitation.
      if (pos < 180) {
        pos += 1;
      }
    } else if (control==49)
    {
      // Make sure not to exceed the mechanical limitation.
      if (pos > 0) {
        pos -= 1;
      }
    }
  }
  Serial.print("Current angle position of servo : ");
  Serial.println(pos);
 } 

  
  if(c==10)
  {delay(20000);
   c=11;}
  
  
  if(c==11){
  radio.write(&theta,sizeof(unsigned long));
  delay(15);
  
  radio.write(&theta,sizeof(unsigned long));
  delay(15);
  
  
  radio.write(&theta,sizeof(unsigned long));
  delay(15);
  
  delay(1000);
  
  }

  
   
   
}
