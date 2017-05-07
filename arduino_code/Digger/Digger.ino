#include<ros.h>
#include<sensor_msgs/Joy.h>


#define Step_UD1_dir 37
#define Step_UD1_step 39
#define Step_UD2_dir 43
#define Step_UD2_step 41
#define Step_LR_dir 47
#define Step_LR_step 45
#define Step_probe_dir 51
#define Step_probe_step 49
#define n 3000
#define enable 53


ros::NodeHandle nh;

int delay1=4000,delay2=500,delay3=500;
int motorPin = 3; //check pin number
int x = 0, i = 1;

void UP_DOWN(int a )
{

    if(a==1)
    {
      digitalWrite(Step_UD1_dir, HIGH);
      digitalWrite(Step_UD2_dir, HIGH);
    }
    if(a==-1)
    {
      digitalWrite(Step_UD1_dir, LOW);
      digitalWrite(Step_UD2_dir, LOW);  
    }
    
    digitalWrite(enable, LOW);
    while(fabs(a)==1)
    {
      digitalWrite(Step_UD1_step, HIGH);
      digitalWrite(Step_UD2_step, HIGH);
      delayMicroseconds(delay1);
      digitalWrite(Step_UD1_step, LOW);
      digitalWrite(Step_UD2_step, LOW);
      delayMicroseconds(delay1);

    }
    digitalWrite(enable, HIGH);
    return;
}
void LEFT_RIGHT(int a)
{ 
  
   
    
    if(a=1)
    {
      digitalWrite(Step_LR_dir, HIGH);
    }
    if(a==-1)
    {
      digitalWrite(Step_LR_dir, LOW);
    }
  
    
    digitalWrite(enable, LOW);
    while(fabs(a)==1)
    {
      digitalWrite(Step_LR_step, HIGH);
      delayMicroseconds(delay2);
      digitalWrite(Step_LR_step, LOW);
      delayMicroseconds(delay2);
     
    }
    digitalWrite(enable, HIGH);
   
    return;
}
void PROBE(int a,int b)
{
    
   
    if(a=1)
    {
      digitalWrite(Step_probe_dir, HIGH);
    }
     if(b=1)
    {
      digitalWrite(Step_probe_dir, LOW);  
    }

    digitalWrite(enable, LOW);
    while(a==1||b==1)
    {
      digitalWrite(Step_probe_step, HIGH);
      delayMicroseconds(delay3);
      digitalWrite(Step_probe_step, LOW);
      delayMicroseconds(delay3);
     
    }
    digitalWrite(enable, HIGH);
   
}


void CallBack(const sensor_msgs::Joy& joy)
{
  if(fabs(joy.axes[7])==1 && fabs(joy.axes[6])==0)
    UP_DOWN(joy.axes[7]);
    
  if(fabs(joy.axes[6])==1&& fabs(joy.axes[7])==0)
    LEFT_RIGHT(joy.axes[6]);
    
  if(joy.buttons[6]==1||joy.buttons[7]==1)
   PROBE(joy.buttons[6],joy.buttons[7]);
}

ros::Subscriber<sensor_msgs::Joy> sub("joy", &CallBack);

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  pinMode(motorPin, OUTPUT); //dc motor
  
  pinMode(Step_UD1_dir, OUTPUT);
  pinMode(Step_UD1_step, OUTPUT);
  pinMode(Step_UD2_dir, OUTPUT);
  pinMode(Step_UD2_step, OUTPUT);
  pinMode(Step_LR_dir, OUTPUT);
  pinMode(Step_LR_step, OUTPUT);
  pinMode(Step_probe_dir, OUTPUT);
  pinMode(Step_probe_step, OUTPUT);
  pinMode(enable, OUTPUT);
  delay(10);
  digitalWrite(enable, HIGH);
}

void loop() 
{
  nh.spinOnce();
  delay(1);
}

