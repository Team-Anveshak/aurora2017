#ifndef _ROS_rover_msgs_WheelVelocity_h
#define _ROS_rover_msgs_WheelVelocity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class WheelVelocity : public ros::Msg
  {
    public:
      float left;
      float right;
      int16_t reset_flag;

    WheelVelocity():
      left(0),
      right(0),
      reset_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->left);
      offset += serializeAvrFloat64(outbuffer + offset, this->right);
      union {
        int16_t real;
        uint16_t base;
      } u_reset_flag;
      u_reset_flag.real = this->reset_flag;
      *(outbuffer + offset + 0) = (u_reset_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reset_flag.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->reset_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right));
      union {
        int16_t real;
        uint16_t base;
      } u_reset_flag;
      u_reset_flag.base = 0;
      u_reset_flag.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reset_flag.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->reset_flag = u_reset_flag.real;
      offset += sizeof(this->reset_flag);
     return offset;
    }

    const char * getType(){ return "rover_msgs/WheelVelocity"; };
    const char * getMD5(){ return "22c56d70a0f2060151657bd9cd98512f"; };

  };

}
#endif