#include <ros.h>
#include <rover_msgs/WheelVelPower.h>

float x51;
float x52;
float x53;
//float x54;

float bat1[7];
float bat2[7];
float bat3[7];
//float bat4[7];
//float bat5[7];
//float bat6[7];

int k= 1023/255;

ros::NodeHandle nh;

rover_msgs::WheelVelPower PowerCheck;
ros::Publisher power_pub("rover1/power_check", &PowerCheck);

void binInput(int count)
{
 int r0 = bitRead(count,0);    
 int r1 = bitRead(count,1);    
 int r2 = bitRead(count,2);       
 int r3 = bitRead(count,3);

 digitalWrite(2, r0);
 digitalWrite(3, r1);
 digitalWrite(4, r2);
 digitalWrite(5, r3);
 
}

void UpdatePowerValues(){
  //24V battery1 connected to A0 ------------------------------------
  binInput(0);
  int x01=analogRead(0);
  binInput(1);
  int x11=analogRead(0);
  binInput(2);
  int x21=analogRead(0);
  binInput(3);
  int x31=analogRead(0);  
  binInput(4);
  int x41=analogRead(0);  
  binInput(5);
  x51=analogRead(0); 
  
  int b1c1=x51*k;
  int b1c2=abs(x41-x51)*k;
  int b1c3=abs(x31-x41)*k;
  int b1c4=abs(x21-x31)*k;
  int b1c5=abs(x11-x21)*k;
  int b1c6=abs(x01-x11)*k;


   //24V battery2 connected to A0 ---------------------------------------
  binInput(10);
  int x02=analogRead(0);
  binInput(11);
  int x12=analogRead(0);
  binInput(12);
  int x22=analogRead(0);
  binInput(13);
  int x32=analogRead(0);  
  binInput(14);
  int x42=analogRead(0);  
  binInput(15);
  x52=analogRead(0); 
  
  bat2[0]=x52*k;
  bat2[1]=abs(x42-x52)*k;
  bat2[2]=abs(x32-x42)*k;
  bat2[3]=abs(x22-x32)*k;
  bat2[4]=abs(x12-x22)*k;
  bat2[5]=abs(x02-x12)*k;

   //24V battery3 connected to A1 --------------------------------------
  binInput(0);
  int x03=analogRead(1);
  binInput(1);
  int x13=analogRead(1);
  binInput(2);
  int x23=analogRead(1);
  binInput(3);
  int x33=analogRead(1);  
  binInput(4);
  int x43=analogRead(1);  
  binInput(5);
  x53=analogRead(1); 
  
  bat3[0]=x03*k;
  bat3[1]=abs(x13-x03)*k;
  bat3[2]=abs(x23-x13)*k;
  bat3[3]=abs(x33-x23)*k;
  bat3[4]=abs(x43-x33)*k;
  bat3[5]=abs(x53-x43)*k;

     //24V battery4 connected to A1---------------------------------------
  /*binInput(15);
  int x04=analogRead(1);
  binInput(14);
  int x14=analogRead(1);
  binInput(13);
  int x24=analogRead(1);
  binInput(12);
  int x34=analogRead(1);  
  binInput(11);
  int x44=analogRead(1);  
  binInput(10);
  x54=analogRead(1); 
  
  bat4[0]=x54*k;
  bat4[1]=abs(x44-x54)*k;
  bat4[2]=abs(x34-x44)*k;
  bat4[3]=abs(x24-x34)*k;
  bat4[4]=abs(x14-x24)*k;
  bat4[5]=abs(x04-x14)*k;
  */

}

void setup() {
  nh.initNode(); 
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);   
  pinMode(4, OUTPUT);   
  pinMode(5, OUTPUT);
  nh.advertise(power_pub);
}

void loop() {
   
  UpdatePowerValues();
  PowerCheck.power_1=x51;
  PowerCheck.power_2=x52;
  PowerCheck.power_3=x53;

  for(int i=0; i<7; i++){
   PowerCheck.bat1[i]=bat1[i];  
   PowerCheck.bat2[i]=bat2[i];  
   //PowerCheck.bat3[i]=bat3[i];  
  }
  
  

  //nh.loginfo(nh.get_caller_id()+"value 1 %f",ref_1);
  power_pub.publish(&PowerCheck);  
  nh.spinOnce();
  delay(10);
}
