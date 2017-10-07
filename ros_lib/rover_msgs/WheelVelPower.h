#ifndef _ROS_rover_msgs_WheelVelPower_h
#define _ROS_rover_msgs_WheelVelPower_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class WheelVelPower : public ros::Msg
  {
    public:
      float left_front_vel;
      float right_front_vel;
      float left_middle_vel;
      float right_middle_vel;
      float left_back_vel;
      float right_back_vel;
      float power_1;
      float power_2;
      float power_3;

    WheelVelPower():
      left_front_vel(0),
      right_front_vel(0),
      left_middle_vel(0),
      right_middle_vel(0),
      left_back_vel(0),
      right_back_vel(0),
      power_1(0),
      power_2(0),
      power_3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->left_front_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_front_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_middle_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_middle_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_back_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_back_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_2);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_front_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_front_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_middle_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_middle_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_back_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_back_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_3));
     return offset;
    }

    const char * getType(){ return "rover_msgs/WheelVelPower"; };
    const char * getMD5(){ return "f13c06ab7a6186260b614a9e977d02cb"; };

  };

}
#endif