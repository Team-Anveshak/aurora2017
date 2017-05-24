#include<ros.h>
#include<rover_msgs/digger.h>
#include <avr/wdt.h>


#define Step_UD1_dir 39
#define Step_UD1_step 37
#define Step_UD2_dir 43
#define Step_UD2_step 41
#define Step_LR_dir 47
#define Step_LR_step 45
#define Step_probe_dir 51
#define Step_probe_step 49
#define n 3000
#define enable_ver_1 53
#define enable_ver_2 53
#define enable_hor 53
#define enable_probe 53
#define ena_1 46
#define ena_2 44
#define fdir1 50
#define fdir2 42
#define bdir1 48
#define bdir2 40



int delay1=4000,delay2=2000,delay3=2000;
int motorPin = 3; //check pin number
int x = 0, i = 1;
int reset_flag;




void CallBack(const rover_msgs::digger& D)
{
  
    
       
  if((D.Step_UD_step)==1 )
  {
    
    if((D.Step_UD_dir)==1)
    {
      digitalWrite(Step_UD1_dir, HIGH);
      digitalWrite(Step_UD2_dir, HIGH);
    }
    if((D.Step_UD_dir)==-1)
    {
      digitalWrite(Step_UD1_dir, LOW);
      digitalWrite(Step_UD2_dir, LOW);  
    }
    
    digitalWrite(enable_ver_1, LOW);
   
    
   for(int i=0;i<50;i++)
    {
      digitalWrite(Step_UD1_step, HIGH);
      digitalWrite(Step_UD2_step, HIGH);
      delayMicroseconds(delay1);
      digitalWrite(Step_UD1_step, LOW);
      digitalWrite(Step_UD2_step, LOW);
      delayMicroseconds(delay1);

    }
   
   }
      
  if((D.LR_step)==1)
   {
    if((D.LR_dir)==1)
    {
      digitalWrite(Step_LR_dir, HIGH);
    }
    if((D.LR_dir)==-1)
    {
      digitalWrite(Step_LR_dir, LOW);
    }
  
    
    digitalWrite(enable_hor, LOW);
    for(int i=0;i<50;i++)
    {
      digitalWrite(Step_LR_step,HIGH);
      delayMicroseconds(delay3);
      digitalWrite(Step_LR_step,LOW);
      delayMicroseconds(delay3);
     
    }
    
    }
    
    if((D.probe_step)==1)
   {
    if((D.probe_dir)==1)
    {
      digitalWrite(Step_probe_dir, HIGH);
    }
    if((D.probe_dir)==-1)
    {
      digitalWrite(Step_probe_dir, LOW);
    }
  
    
    
    for(int i=0;i<50;i++)
    {
      digitalWrite(Step_probe_step,HIGH);
      delayMicroseconds(delay3);
      digitalWrite(Step_probe_step,LOW);
      delayMicroseconds(delay3);
     
    }
    
    }
    
     if(D.reset_flag==1) reset_flag=1;
   
}

ros::NodeHandle nh;

ros::Subscriber<rover_msgs::digger> sub("dig", &CallBack);


void setup() {
  nh.initNode();
  nh.subscribe(sub);
  
  wdt_disable();
  wdt_enable(WDTO_8S);

  pinMode(motorPin, OUTPUT); //dc motor
  
  pinMode(Step_UD1_dir, OUTPUT);
  pinMode(Step_UD1_step, OUTPUT);
  pinMode(Step_UD2_dir, OUTPUT);
  pinMode(Step_UD2_step, OUTPUT);
  pinMode(Step_LR_dir, OUTPUT);
  pinMode(Step_LR_step, OUTPUT);
  pinMode(Step_probe_dir, OUTPUT);
  pinMode(Step_probe_step, OUTPUT);
  pinMode(enable_ver_1,OUTPUT);
  pinMode(enable_ver_2,OUTPUT);
  pinMode(enable_hor,OUTPUT);
  pinMode(enable_probe,OUTPUT);
  pinMode(ena_1,OUTPUT);
  pinMode(ena_2,OUTPUT);
  pinMode(fdir1,OUTPUT);
  pinMode(fdir2,OUTPUT);
  pinMode(bdir1,OUTPUT);
  pinMode(bdir2,OUTPUT);
  
  delay(10);
 
}


void loop() 
{
  if(reset_flag==1)  wdt_reset();
   reset_flag=0;
  nh.spinOnce();
  delay(1);
}

