#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/Battery_level.h>

float k=0.0273; // ??

#define dir1 25
#define pwm1 3
#define dir2 23
#define pwm2 2
#define dir3 29
#define pwm3 5
#define dir4 27
#define pwm4 4
#define dir5 3
#define pwm5 7
#define dir6 31
#define pwm6 6


float bat[7][7]={};
int i;
int lowest_vol=0;

float minimum_bat_level;

int tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

ros::NodeHandle nh;

rover_msgs::WheelVelocity RoverVel;
rover_msgs::Battery_level level;

ros::Publisher Battery_level("Battery_level", &level);

/******************LOCOMOTION************************/

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

/***Function to calculate the minimum of 3 numbers***/

float minimum(float b1,float b2,float b3)
{
  int temp=min(b1,b2);
  temp=min(temp,b3);
  return(temp);
}

/*****Subscriber callback function for wheel velocities***/

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity)
{
  int factor=minimum(bat[0][6],bat[3][6],bat[6][6]);

//scaling factors for the batteries
  int k1=factor/bat[0][6];  //front
  int k2=factor/bat[3][6];  //middle
  int k3=factor/bat[6][6];  //back
  
  lt = map(RoverVelocity.left_front_vel,-70,70,-175,175);
  rt = map(RoverVelocity.right_front_vel,-70,70,-175,175);
  lm = map(RoverVelocity.left_middle_vel,-70,70,-175,175);
  rm = map(RoverVelocity.right_middle_vel,-70,70,-175,175);
  lb = map(RoverVelocity.left_back_vel,-70,70,-175,175);
  rb = map(RoverVelocity.right_back_vel,-70,70,-175,175);
  
  tl = (int)lt*k1;
  tr = (int)rt*k1;
   
  ml = (int)lm*k2;
  mr = (int)rm*k2;
   
  bl = (int)lb*k3;
  br = (int)rb*k3;

  loco(tl,dir1,pwm1);
  loco(tr,dir2,pwm2);
  loco(ml,dir3,pwm3);
  loco(mr,dir4,pwm4);
  loco(bl,dir5,pwm5);
  loco(br,dir6,pwm6);

}
 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);

/******************BIN INPUT FOR MULTIPLEXER*****************/

void binInput(int count)
{
 int r0 = bitRead(count,0);    
 int r1 = bitRead(count,1);    
 int r2 = bitRead(count,2);       
 int r3 = bitRead(count,3);

 digitalWrite(22, r0);
 digitalWrite(24 ,r1);
 digitalWrite(26, r2);
 digitalWrite(28, r3);
 
}

/***************BMS FUNCTION CALL*************/
void BMS()

{ 
  float x[15]={};
    ///////////////////////////////MUX2--A3
  binInput(0);
  x[0]=analogRead(3);
  binInput(1);
  x[1]=analogRead(3);
  binInput(2);
  x[2]=analogRead(3);
  binInput(3);
  x[3]=analogRead(3);
  binInput(4);
  x[4]=analogRead(3);
  binInput(5);
  x[5]=analogRead(3);
  binInput(10);
  x[10]=analogRead(3);
  binInput(11);
  x[11]=analogRead(3);
  binInput(12);
  x[12]=analogRead(3);
  binInput(13);
  x[13]=analogRead(3);
  binInput(14);
  x[14]=analogRead(3);
  binInput(15);
  x[15]=analogRead(3);
  binInput(6);
  x[6]=analogRead(3);
  binInput(7);
  x[7]=analogRead(3);
  binInput(8);
  x[8]=analogRead(3);
  
  bat[4][0]=(x[0]-x[1])*k;
  bat[4][1]=(x[1]-x[2])*k;
  bat[4][2]=(x[2]-x[3])*k; 
  bat[4][3]=(x[3]-x[4])*k;
  bat[4][4]=(x[4]-x[5])*k;
  bat[4][5]=(x[5])*k; 
  bat[4][6]=x[0]*k;                     //Final VolTage
  
  bat[5][0]=(x[15]-x[14])*k;
  bat[5][1]=(x[14]-x[13])*k;
  bat[5][2]=(x[13]-x[12])*k;
  bat[5][3]=(x[12]-x[11])*k;
  bat[5][4]=(x[11]-x[10])*k;
  bat[5][5]=(x[10])*k;
  bat[5][6]=x[15]*k;           //Final VolTage

  bat[6][0]=(x[8])*k;
  bat[6][1]=(x[7]-x[8])*k;
  bat[6][2]=(x[6]-x[7])*k;
  bat[6][3]=x[7]*k;             //Final VolTage

  

     ///////////////////////////////MUX1--A2
  binInput(0);
  x[0]=analogRead(2);
  binInput(1);
  x[1]=analogRead(2);
  binInput(2);
  x[2]=analogRead(2);
  binInput(3);
  x[3]=analogRead(2);
  binInput(4);
  x[4]=analogRead(2);
  binInput(5);
  x[5]=analogRead(2);
  binInput(10);
  x[10]=analogRead(2);
  binInput(11);
  x[11]=analogRead(2);
  binInput(12);
  x[12]=analogRead(2);
  binInput(13);
  x[13]=analogRead(2);
  binInput(14);
  x[14]=analogRead(2);
  binInput(15);
  x[15]=analogRead(2);
  binInput(6);
  x[6]=analogRead(2);
  binInput(7);
  x[7]=analogRead(2);
  binInput(8);
  x[8]=analogRead(2);
  
  bat[1][0]=(x[0]-x[1])*k;
  bat[1][1]=(x[1]-x[2])*k;
  bat[1][2]=(x[2]-x[3])*k; 
  bat[1][3]=(x[3]-x[4])*k;
  bat[1][4]=(x[4]-x[5])*k;
  bat[1][5]=(x[5])*k; 
  bat[1][6]=x[0]*k;                     //Final VolTage

  bat[2][0]=(x[15]-x[14])*k;
  bat[2][1]=(x[14]-x[13])*k;
  bat[2][2]=(x[13]-x[12])*k;
  bat[2][3]=(x[12]-x[11])*k;
  bat[2][4]=(x[11]-x[10])*k;
  bat[2][5]=(x[10])*k;
  bat[2][6]=x[15]*k;           //Final VolTage


  bat[3][2]=(x[8])*k;
  bat[3][1]=(x[8]-x[7])*k;
  bat[3][0]=(x[7]-x[6])*k;
  bat[3][3]=x[6]*k;            //Final VolTage

  level.batt1=bat[0][6];
  level.batt2=bat[3][6];
  level.batt3=bat[6][6];
  level.batt=0;
  for(int i=0;i<7;i+=3)
    if(bat[i][6]<minimum_bat_level)
      level.batt=i;  //0,3,and 6 refers to front,middle and back wheel battery
  Battery_level.publish(&level);
 
  
}

/*******************************SETUP**********************************/
void setup()
{

   nh.initNode();
 
   nh.subscribe(locomotion_sub);
   nh.advertise(Battery_level);
   
   //Serial.begin(9600);
   
/**************Multiplexer digital inputs************/
   
   pinMode(22,OUTPUT);
   pinMode(24,OUTPUT);
   pinMode(26,OUTPUT);
   pinMode(28,OUTPUT);

/*****Locomotion Pins******/

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

/*********************Looping***************************/
void loop() 
{
  BMS();
  nh.spinOnce();
  delay(1); 
}
