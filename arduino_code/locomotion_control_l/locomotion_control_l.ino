/* rosserial Subscriber For Locomotion Control*/
#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
//#include <Servo.h>

//Servo mainCameraYaw;
//Servo mainCameraPitch;

#define dir1 23
#define pwm1 7
#define dir2 25
#define pwm2 8
#define dir3 27
#define pwm3 9
#define dir4 29
#define pwm4 10
#define dir5 31
#define pwm5 12
#define dir6 33
#define pwm6 13

//#define pwm_bat1 35
//#define pwm_bat2 37
//#define pwm_bat3 39
//#define pwm_bat4 41
//#define pwm_bat5 43
//#define pwm_bat6 45

//int yaw_initial = 90;
//int pitch_initial= 90;

//float k1,k2,k3, mink;

int tl = 0,tr = 0,ml = 0, mr = 0, bl = 0, br = 0;
float lt = 0,rt = 0,lm = 0,rm = 0,lb = 0,rb = 0; 

ros::NodeHandle nh;

//rover_msgs::WheelVelPower RoverVelocity;

rover_msgs::WheelVelocity RoverVel;
ros::Publisher vel_pub("rover1/wheel", &RoverVel);

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

/*float minK(float k1,float k2, float k3){  
  if(k1>=k2){
    if(k2>=k3){
      return k3;
      }
    else{
      return k2;}  
    }
    
  else{
    if(k1>=k3){
      return k3;
    }
    else{
      return k1;}  
    }  
  
}

void UpdatePowerValues(){
  k1 = 255;//analogRead(pwm_bat1);
  k2 = 255;//analogRead(pwm_bat2);
  k3 = 255;//analogRead(pwm_bat3);
}*/

/*void cameraMotionCallback(const rover_msgs::CameraMotion& CameraVelocity){
  //nh.loginfo("CameraVelocity.A_button");
  
  if(CameraVelocity.X_button)
      if(yaw_initial > 180)
            yaw_initial = 180;
      else 
            yaw_initial = yaw_initial + 2;
            
  if(CameraVelocity.B_button)
      if(yaw_initial < 0)
                  yaw_initial = 0;
      else 
            yaw_initial = yaw_initial - 2;
            
  if(CameraVelocity.Y_button)
      if(pitch_initial < 10)
          pitch_initial = 0;
      else 
          pitch_initial = pitch_initial -2;
      
  if(CameraVelocity.A_button)
       if(pitch_initial >145)
          pitch_initial = 145;
      else 
         pitch_initial = pitch_initial +2;
      
    mainCameraYaw.write(yaw_initial);
    mainCameraPitch.write(pitch_initial);
}*/

//ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){

  //UpdatePowerValues();
  //mink=minK(k1,k2,k3);

  lt = map(RoverVelocity.left_front_vel,-50,50,-150,150);
  rt = map(RoverVelocity.right_front_vel,-50,50,-150,150);
  lm = map(RoverVelocity.left_middle_vel,-50,50,-150,150);
  rm = map(RoverVelocity.right_middle_vel,-50,50,-150,150);
  lb = map(RoverVelocity.left_back_vel,-50,50,-150,150);
  rb = map(RoverVelocity.right_back_vel,-50,50,-150,150);
  
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
  
  RoverVel.left_front_vel=tl;
  RoverVel.right_front_vel=tr;
  RoverVel.left_middle_vel=ml;
  RoverVel.right_middle_vel=mr;
  RoverVel.left_back_vel=bl;
  RoverVel.right_back_vel=br;
  //RoverVel.power_1=0;//k1*24/255;
  //RoverVel.power_2=0;//k2*24/255;
  //RoverVel.power_3=0;//k3*24/255;

  vel_pub.publish(&RoverVel);
 

 }
 
 ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
 
 void setup(){
   nh.initNode();
   //nh.subscribe(cammotion_sub);
   nh.subscribe(locomotion_sub);
   nh.advertise(vel_pub);
 
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

   //pinMode(pwm_bat1,INPUT);
   //pinMode(pwm_bat2,INPUT);
   //pinMode(pwm_bat3,INPUT);
   //pinMode(pwm_bat4,INPUT);
   //pinMode(pwm_bat5,INPUT);
   //pinMode(pwm_bat6,INPUT);

   /*mainCameraYaw.write(yaw_initial);
   mainCameraPitch.write(pitch_initial);
   mainCameraYaw.attach(A0);
   mainCameraPitch.attach(A1);
  */
 }
 
 void loop(){
   nh.spinOnce();
   delay(1);
}
