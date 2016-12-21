/* 
 * rosserial Subscriber For Locomotion Control
 */

#include <ros.h>
#include <rover_msgs/WheelVelocity.h>
#include <rover_msgs/CameraMotion.h>
#include <Servo.h>

Servo mainCameraYaw;
Servo mainCameraPitch;

cam_pitch = 0;
cam_yaw = 0;

ros::NodeHandle nh;
//rover_msgs::CameraMotion camFeedback[4];
//rover_msgs::WheelVelocity wheelFeedback[6];

/*
*RoverVelocity is an array of the velocity values in order:
* 0 left_front_vel
* 1 right_front_vel
* 2 left_middle_vel
* 3 right_middle_vel
* 4 left_back_vel
* 5 right_back_vel
*/

void roverMotionCallback(const rover_msgs::WheelVelocity& RoverVelocity){
/*
  analogWrite(A0, RoverVelocity[0]);
  analogWrite(A1, RoverVelocity[1]);
  analogWrite(A2, RoverVelocity[2]);
  analogWrite(A3, RoverVelocity[3]);
  analogWrite(A4, RoverVelocity[4]);
  analogWrite(A5, RoverVelocity[5]);
*/  
}

void cameraMotionCallback(const rover_msgs::WheelVelocity& CameraVelocity){
  if(CameraVelocity[0])
	cam_yaw = cam_yaw + 2;
  if(CameraVelocity[1])
        cam_yaw = cam_yaw - 2;
  if(CameraVelocity[3])
        cam_pitch = cam_pitch - 2;
  if(CameraVelocity[4])
        cam_pitch = cam_pitch + 2;
  
  mainCameraYaw.write(cam_yaw);
  mainCameraPitch.write(cam_pitch);

}

ros::Subscriber<rover_msgs::WheelVelocity> locomotion_sub("rover1/wheel_vel", &roverMotionCallback);
ros::Subscriber<rover_msgs::WheelVelocity> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);

void setup(){
  nh.initNode();
  nh.subscribe(sub);

// pin arrangements for wheel motors in the above order...
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OTUPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  mainCameraYaw.attach(A0);
  mainCameraPitch.attach(A1)
}

void loop(){
  nh.spinOnce();
  delay(1);
}
