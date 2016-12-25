#include <ros.h>
#include <Servo.h> 
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>

#define dcmotor_fl 3 
#define dcmotor_fr 5  
#define dcmotor_ml 6 
#define dcmotor_mr 9
#define dcmotor_br 10
#define dcmotor_bl 11

Servo mainCameraYaw;
Servo mainCameraPitch;

int yaw_initial = 90;
int pitch_initial = 0;

ros::NodeHandle_<ArduinoHardware, 5, 5, 125, 125> nh1;
ros::NodeHandle_<ArduinoHardware, 5, 5, 125, 125> nh2;

Servo frontLeft;
Servo frontRight;

Servo middleLeft;
Servo middleRight;

Servo backLeft;
Servo backRight;


void cameraMotionCallback(const rover_msgs::CameraMotion& CameraVelocity){
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
       if(pitch_initial >140)
          pitch_initial = 140;
      else 
         pitch_initial = pitch_initial +2;
      
    mainCameraYaw.write(yaw_initial);
    mainCameraPitch.write(pitch_initial);
}


/*
*RoverVelocity is an array of the velocity values in order:
* 0 left_front_vel
* 1 right_front_vel
* 2 left_middle_vel
* 3 right_middle_vel
* 4 left_back_vel
* 5 right_back_vel
*/

int fl = 0,fr = 0, ml = 0, mr = 0, bl = 0, br = 0;

void Locomotion()
{
  frontLeft.writeMicroseconds(fl);
  frontRight.writeMicroseconds(fr);
  
  middleLeft.writeMicroseconds(ml);
  middleRight.writeMicroseconds(mr);
  
  backLeft.writeMicroseconds(bl);
  backRight.writeMicroseconds(br);
}

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
  fl = (int)RoverVelocity.left_front_vel;
  fr = (int)RoverVelocity.right_front_vel;
  
  ml = (int)RoverVelocity.left_middle_vel;
  mr = (int)RoverVelocity.right_middle_vel;
  
  bl = (int)RoverVelocity.left_back_vel;
  br = (int)RoverVelocity.right_back_vel;

  if(abs(fl)<25){
     fl=25;fr=25;ml=25;mr=25;bl=25;br=25;
  }
  
  Locomotion();
}

ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);


void setup(){
  nh1.initNode();
  nh2.initNode();
  nh1.subscribe(locomotion_sub);
  nh2.subscribe(cammotion_sub);
  
  mainCameraYaw.write(yaw_initial);
  mainCameraPitch.write(pitch_initial);
  mainCameraYaw.attach(A0);
  mainCameraPitch.attach(A1);

  frontLeft.attach(dcmotor_fl,1000,2000);            
  frontRight.attach(dcmotor_fr,1000,2000);             
  middleLeft.attach(dcmotor_ml,1000,2000);
  middleRight.attach(dcmotor_mr,1000,2000);
  backLeft.attach(dcmotor_bl,1000,2000);
  backRight.attach(dcmotor_br,1000,2000);

  frontLeft.writeMicroseconds(1500);
  frontRight.writeMicroseconds(1500);
  middleLeft.writeMicroseconds(1500);
  middleRight.writeMicroseconds(1500);
  backLeft.writeMicroseconds(1500);
  backRight.writeMicroseconds(1500);

}

void loop(){
  nh1.spinOnce();
  nh2.spinOnce();
  delay(1);
}
