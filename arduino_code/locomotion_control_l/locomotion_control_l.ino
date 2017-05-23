/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/SC_task.h>

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 24

Adafruit_BMP085 bmp;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celsius =0, Fahrenheit = 0;
const int HumidSensor= 2;



#define dir1 47
#define pwm1 7
#define dir2 49
#define pwm2 6
#define dir3 29
#define pwm3 5
#define dir4 27
#define pwm4 4
#define dir5 25
#define pwm5 3
#define dir6 23
#define pwm6 2
#define drill_pin 48


int tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

ros::NodeHandle nh;
rover_msgs::SC_task sensor_msg;
ros::Publisher sensor_pub("SC_Task_Sensors", &sensor_msg);


void loco(int vel,int dir_pin,int pwm_pin)
{
if(vel<=0)
  {
   digitalWrite(dir_pin,LOW);
   analogWrite(pwm_pin,abs(vel));
  }
else
  { 
    digitalWrite(dir_pin,HIGH);
    analogWrite(pwm_pin,abs(vel));
  }
   
  
}




void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){

  

  lt = map(RoverVelocity.left_front_vel,-70,70,-175,175);
  rt = map(RoverVelocity.right_front_vel,-70,70,-175,175);
  lm = map(RoverVelocity.left_middle_vel,-70,70,-175,175);
  rm = map(RoverVelocity.right_middle_vel,-70,70,-175,175);
  lb = map(RoverVelocity.left_back_vel,-70,70,-175,175);
  rb = map(RoverVelocity.right_back_vel,-70,70,-175,175);

   


  loco(lt,dir1,pwm1);
  loco(rt,dir2,pwm2);
  loco(lm,dir3,pwm3);
  loco(rm,dir4,pwm4);
  loco(lb,dir5,pwm5);
  loco(rb,dir6,pwm6);
  
  if (RoverVelocity.drill==1)
  {
    digitalWrite(drill_pin,HIGH);
  }
  else
  {
    digitalWrite(drill_pin,LOW);
  }
  
 }
 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 
 void setup(){
   nh.initNode();
 
   nh.subscribe(locomotion_sub);
   nh.advertise(sensor_pub);
 
  bmp.begin();
  sensors.begin();
  
   pinMode(dir1,OUTPUT);
   pinMode(dir2,OUTPUT);
   pinMode(dir3,OUTPUT);
   pinMode(dir4,OUTPUT);
   pinMode(dir5,OUTPUT);
   pinMode(dir6,OUTPUT); 
  
   pinMode(pwm1,OUTPUT);
   pinMode(pwm2,OUTPUT);
   pinMode(pwm3,OUTPUT);
   pinMode(pwm4,OUTPUT);
   pinMode(pwm5,OUTPUT);
   pinMode(pwm6,OUTPUT);

  
   
 }
 
 void loop(){
   
     
 sensor_msg.Atm_temp=bmp.readTemperature();

 sensor_msg.Atm_press=bmp.readPressure();

 sensor_msg.Soil_humi=analogRead(HumidSensor);
 
 sensor_msg.Altitude=bmp.readAltitude();
 
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);
 
 sensor_msg.Soil_temp=Celsius;
 
 sensor_pub.publish( &sensor_msg );
   nh.spinOnce();
   delay(1);
}

