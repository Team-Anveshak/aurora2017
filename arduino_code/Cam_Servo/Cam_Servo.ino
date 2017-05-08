#include<ros.h>
#include<Arduino.h>
#include<Servo.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Pose2D.h>

#define servo_pin 6

Servo servo;

int angle=1,inc,flag=1,flg=0,theta;

ros::NodeHandle nh;

geometry_msgs::Pose2D pos;
ros::Publisher pos_pub("/ball_pos",&pos);

void gps_flgCallback(const std_msgs::Float32 msg){
	flg=msg.data;
}

void cam_flgCallback(const std_msgs::Float32 msg){
  if(msg.data==1)    flag=0;
}

void distCallback(const std_msgs::Float32 msg){
	if(flag==0){
		pos.x=msg.data;
    pos.theta=(angle-inc)-90;
    pos_pub.publish(&pos);
	}
}

ros::Subscriber<std_msgs::Float32> gflag_sub("/gps_loc_flg", &gps_flgCallback);
ros::Subscriber<std_msgs::Float32> cflag_sub("/rover1/FLAG_Camera", &cam_flgCallback);
ros::Subscriber<std_msgs::Float32> dist_sub("/rover1/ball_distance", &distCallback);

void setup() {
  nh.initNode();
  nh.subscribe(gflag_sub);
  nh.subscribe(cflag_sub);
	nh.subscribe(dist_sub);
  nh.advertise(pos_pub);
  servo.attach(servo_pin);
}

void loop() {
  if(flag==1 && flg==1){
  	angle=(angle%180);
		servo.write(angle);
		if(angle==1)	inc=+1;
		if(angle==179)	inc=-1;
		angle+=inc;
  }
  if(flag==0 && flg==1){
    //pos_pub.publish(&pos);
  }
  nh.spinOnce();
  delay(100);
}
