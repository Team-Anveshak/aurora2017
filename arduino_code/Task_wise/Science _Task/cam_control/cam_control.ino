#include <ros.h>
#include <rover_msgs/CameraMotion.h>
#include <Servo.h>
#include <avr/wdt.h>



Servo mainCameraYaw;


//initialising the yaw and pitch to 90 and creating a nodehandle object
int yaw_initial = 90;
int reset_flag;

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
  
    mainCameraYaw.write(yaw_initial);
   
}

//creating a subscriber for the topic river1/camera_dir
ros::Subscriber<rover_msgs::CameraMotion> cammotion_sub("rover1/camera_dir", &cameraMotionCallback);


//initialising the node and subscribing to the message cammotion_sub
void setup(){
  nh.initNode();
  nh.subscribe(cammotion_sub);
  mainCameraYaw.write(yaw_initial);
  mainCameraYaw.attach(A0);

  wdt_disable();
  wdt_enable(WDTO_8S);
  
}

void loop(){

  if(reset_flag==1)  wdt_reset();
  reset_flag=0;

  nh.spinOnce();
  delay(1);
}
