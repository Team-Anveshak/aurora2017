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


float bat[10][7]={};
float x[15]={};
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
  
  lt = map(RoverVelocity.left_front_vel,-70*k1,70*k1,175*k1,175*k1);
  rt = map(RoverVelocity.right_front_vel,-70*k1,70*k1,175*k1,175*k1);
  lm = map(RoverVelocity.left_middle_vel,-70*k2,70*k2,175*k2,175*k2);
  rm = map(RoverVelocity.right_middle_vel,-70*k2,70*k2,175*k2,175*k2);
  lb = map(RoverVelocity.left_back_vel,-70*k3,70*k3,175*k3,175*k3);
  rb = map(RoverVelocity.right_back_vel,-70*k3,70*k3,175*k3,175*k3);
  
  tl = (int)lt;///k1*mink;
  tr = (int)rt;///k1*mink;
   
  ml = (int)lm;///k2*mink;
  mr = (int)rm;///k2*mink;
   
  bl = (int)lb;///k3*mink;
  br = (int)rb;///k3*mink;

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
/***************MUX3--A4**************/
  for(int i=0;i<6;i++)
  {
    binInput(i);
    x[i]=analogRead(4);
  }
  for(int i=10;i<16;i++)
  {
    binInput(i);
    x[i]=analogRead(4);
  }
  for(int i=6;i<9;i++)
  {
    binInput(i);
    x[i]=analogRead(4);
  }

  for(int i=0;i<4;i++)
    bat[7][i]=(x[i]-x[i+1])*k;
  bat[7][5]=(x[5])*k; 
  bat[7][6]=x[0]*k;            //Final VolTage
  
  for(int i=0;i<5;i++)
    bat[8][i]=(x[15-i]-x[15-(i+1)])*k;
  bat[8][5]=(x[10])*k;
  bat[8][6]=x[15]*k;           //Final VolTage

  bat[9][0]=(x[8])*k;
  bat[9][1]=(x[7]-x[8])*k;
  bat[9][2]=(x[6]-x[7])*k;
  bat[9][3]=x[7]*k;             //Final VolTage
  

/****************MUX2--A3****************/
  for(int i=0;i<6;i++)
  {
    binInput(i);
    x[i]=analogRead(3);
  }
  for(int i=10;i<16;i++)
  {
    binInput(i);
    x[i]=analogRead(3);
  }
  for(int i=6;i<9;i++)
  {
    binInput(i);
    x[i]=analogRead(3);
  }

  for(int i=0;i<5;i++)
    bat[4][i]=(x[i]-x[i+1])*k;
  bat[4][5]=(x[5])*k; 
  bat[4][6]=x[0]*k;                     //Final VolTage
  
  for(int i=0;i<5;i++)
    bat[5][i]=(x[15-i]-x[15-(i+1)])*k;
  bat[5][5]=(x[10])*k;
  bat[5][6]=x[15]*k;           //Final VolTage

  bat[6][0]=(x[8])*k;
  bat[6][1]=(x[7]-x[8])*k;
  bat[6][2]=(x[6]-x[7])*k;
  bat[6][3]=x[7]*k;             //Final VolTage

  

  /***************MUX1--A2****************/
  for(int i=0;i<6;i++)
  {
    binInput(i);
    x[i]=analogRead(2);
  }
  for(int i=10;i<16;i++)
  {
    binInput(i);
    x[i]=analogRead(2);
  }
  for(int i=6;i<9;i++)
  {
    binInput(i);
    x[i]=analogRead(2);
  }  

  for(int i=0;i<5;i++)
    bat[1][i]=(x[i]-x[i+1])*k;
  bat[1][5]=(x[5])*k; 
  bat[1][6]=x[0]*k;               //Final VolTage
  
  for(int i=0;i<5;i++)
    bat[2][i]=(x[15-i]-x[15-(i+1)])*k;
  bat[2][5]=(x[10])*k;
  bat[2][6]=x[15]*k;           //Final VolTage

  bat[3][2]=(x[8])*k;
  bat[3][1]=(x[8]-x[7])*k;
  bat[3][0]=(x[7]-x[6])*k;
  bat[3][3]=x[6]*k;             //Final VolTage

  /**********************Publishing battery levels***************************/

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
  
 /* Serial.print(x[6]);
  Serial.print("\t");
  Serial.print(x[7]);
  Serial.print("\t");
  Serial.print(x[8]);
  Serial.print("\n");
  */
    /*
  Serial.println(bat[3][0]);
  Serial.println(bat[3][1]);
  Serial.println(bat[3][2]);
  Serial.println(bat[3][3]);
  */
 /* int i,j;
  for (j=1; j<10; j=j+1)
  {  
    for (i = 0; i < 7; i = i + 1) 
    {
      Serial.print(bat[j][i]);
      Serial.print("\t");
    }
  
      Serial.print("\n");
  }
  */
  //Serial.println(map(bat[1][0],0,1024,0,24));
}
