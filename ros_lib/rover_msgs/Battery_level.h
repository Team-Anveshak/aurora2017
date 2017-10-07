#ifndef _ROS_rover_msgs_Battery_level_h
#define _ROS_rover_msgs_Battery_level_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class Battery_level : public ros::Msg
  {
    public:
      float batt1;
      float batt2;
      float batt3;
      int32_t batt;

    Battery_level():
      batt1(0),
      batt2(0),
      batt3(0),
      batt(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->batt1);
      offset += serializeAvrFloat64(outbuffer + offset, this->batt2);
      offset += serializeAvrFloat64(outbuffer + offset, this->batt3);
      union {
        int32_t real;
        uint32_t base;
      } u_batt;
      u_batt.real = this->batt;
      *(outbuffer + offset + 0) = (u_batt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batt);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->batt1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->batt2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->batt3));
      union {
        int32_t real;
        uint32_t base;
      } u_batt;
      u_batt.base = 0;
      u_batt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batt = u_batt.real;
      offset += sizeof(this->batt);
     return offset;
    }

    const char * getType(){ return "rover_msgs/Battery_level"; };
    const char * getMD5(){ return "193ae58d2bb8491f232609244038c21e"; };

  };

}
#endif