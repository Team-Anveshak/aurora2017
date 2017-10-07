#ifndef _ROS_rover_msgs_ArmAngle_h
#define _ROS_rover_msgs_ArmAngle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class ArmAngle : public ros::Msg
  {
    public:
      float angle_1;
      float angle_2;
      float angle_3;

    ArmAngle():
      angle_1(0),
      angle_2(0),
      angle_3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle_1;
      u_angle_1.real = this->angle_1;
      *(outbuffer + offset + 0) = (u_angle_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_1);
      union {
        float real;
        uint32_t base;
      } u_angle_2;
      u_angle_2.real = this->angle_2;
      *(outbuffer + offset + 0) = (u_angle_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_2);
      union {
        float real;
        uint32_t base;
      } u_angle_3;
      u_angle_3.real = this->angle_3;
      *(outbuffer + offset + 0) = (u_angle_3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle_1;
      u_angle_1.base = 0;
      u_angle_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_1 = u_angle_1.real;
      offset += sizeof(this->angle_1);
      union {
        float real;
        uint32_t base;
      } u_angle_2;
      u_angle_2.base = 0;
      u_angle_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_2 = u_angle_2.real;
      offset += sizeof(this->angle_2);
      union {
        float real;
        uint32_t base;
      } u_angle_3;
      u_angle_3.base = 0;
      u_angle_3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_3 = u_angle_3.real;
      offset += sizeof(this->angle_3);
     return offset;
    }

    const char * getType(){ return "rover_msgs/ArmAngle"; };
    const char * getMD5(){ return "7023de6969abdb6bc7e604ee027fa612"; };

  };

}
#endif