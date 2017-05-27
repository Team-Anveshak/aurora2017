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

ros::NodeHandle_<ArduinoHardware, 5, 5, 125, 125> nh;

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

ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(cammotion_sub);
  
  mainCameraYaw.write(yaw_initial);
  mainCameraPitch.write(pitch_initial);
  mainCameraYaw.attach(A0);
  mainCameraPitch.attach(A1);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
