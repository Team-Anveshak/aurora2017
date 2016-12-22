#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
#include <Servo.h>

Servo mainCameraYaw;
Servo mainCameraPitch;

ros::NodeHandle nh;

void cameraMotionCallback(const rover_msgs::CameraMotion& CameraVelocity){
  nh.loginfo("CameraVelocity.A_button");
  
  if(CameraVelocity.X_button)
      mainCameraYaw.write(2);
      
  if(CameraVelocity.B_button)
       mainCameraYaw.write(-2);

  if(CameraVelocity.Y_button)
     mainCameraPitch.write(-2);

  if(CameraVelocity.A_button)
      mainCameraPitch.write(2);
      
}

ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(cammotion_sub);

  mainCameraYaw.attach(A0);
  mainCameraPitch.attach(A1);

}

void loop(){
  nh.spinOnce();
  delay(1);
}
