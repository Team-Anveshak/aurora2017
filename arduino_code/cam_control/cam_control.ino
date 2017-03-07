#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
#include <Servo.h>



Servo mainCameraYaw;
Servo mainCameraPitch;

//initialising the yaw and pitch to 90 and creating a nodehandle object
int yaw_initial = 90;
int pitch_initial=90;
ros::NodeHandle nh;

//Callback funtion for the working of the camera
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
       if(pitch_initial >145)
          pitch_initial = 145;
      else 
         pitch_initial = pitch_initial +2;
      
    mainCameraYaw.write(yaw_initial);
    mainCameraPitch.write(pitch_initial);
}

//creating a subscriber for the topic river1/camera_dir
ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);


//initialising the node and subscribing to the message cammotion_sub
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
