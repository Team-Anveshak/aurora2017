#ifndef _ROS_rover_msgs_GPS_h
#define _ROS_rover_msgs_GPS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class GPS : public ros::Msg
  {
    public:
      float inst_lat;
      float inst_lng;

    GPS():
      inst_lat(0),
      inst_lng(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_inst_lat;
      u_inst_lat.real = this->inst_lat;
      *(outbuffer + offset + 0) = (u_inst_lat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inst_lat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inst_lat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inst_lat.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inst_lat);
      union {
        float real;
        uint32_t base;
      } u_inst_lng;
      u_inst_lng.real = this->inst_lng;
      *(outbuffer + offset + 0) = (u_inst_lng.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_inst_lng.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_inst_lng.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_inst_lng.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inst_lng);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_inst_lat;
      u_inst_lat.base = 0;
      u_inst_lat.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inst_lat.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inst_lat.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inst_lat.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inst_lat = u_inst_lat.real;
      offset += sizeof(this->inst_lat);
      union {
        float real;
        uint32_t base;
      } u_inst_lng;
      u_inst_lng.base = 0;
      u_inst_lng.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_inst_lng.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_inst_lng.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_inst_lng.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->inst_lng = u_inst_lng.real;
      offset += sizeof(this->inst_lng);
     return offset;
    }

    const char * getType(){ return "rover_msgs/GPS"; };
    const char * getMD5(){ return "bdc78d65862232f16b2d232d64a4f3eb"; };

  };

}
#endif