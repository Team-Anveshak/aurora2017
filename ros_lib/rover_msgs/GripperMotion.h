#ifndef _ROS_rover_msgs_GripperMotion_h
#define _ROS_rover_msgs_GripperMotion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class GripperMotion : public ros::Msg
  {
    public:
      bool button_1;
      bool button_2;
      bool button_3;
      bool button_4;
      bool button_5;
      bool button_6;

    GripperMotion():
      button_1(0),
      button_2(0),
      button_3(0),
      button_4(0),
      button_5(0),
      button_6(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_button_1;
      u_button_1.real = this->button_1;
      *(outbuffer + offset + 0) = (u_button_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_1);
      union {
        bool real;
        uint8_t base;
      } u_button_2;
      u_button_2.real = this->button_2;
      *(outbuffer + offset + 0) = (u_button_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_2);
      union {
        bool real;
        uint8_t base;
      } u_button_3;
      u_button_3.real = this->button_3;
      *(outbuffer + offset + 0) = (u_button_3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_3);
      union {
        bool real;
        uint8_t base;
      } u_button_4;
      u_button_4.real = this->button_4;
      *(outbuffer + offset + 0) = (u_button_4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_4);
      union {
        bool real;
        uint8_t base;
      } u_button_5;
      u_button_5.real = this->button_5;
      *(outbuffer + offset + 0) = (u_button_5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_5);
      union {
        bool real;
        uint8_t base;
      } u_button_6;
      u_button_6.real = this->button_6;
      *(outbuffer + offset + 0) = (u_button_6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->button_6);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_button_1;
      u_button_1.base = 0;
      u_button_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_1 = u_button_1.real;
      offset += sizeof(this->button_1);
      union {
        bool real;
        uint8_t base;
      } u_button_2;
      u_button_2.base = 0;
      u_button_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_2 = u_button_2.real;
      offset += sizeof(this->button_2);
      union {
        bool real;
        uint8_t base;
      } u_button_3;
      u_button_3.base = 0;
      u_button_3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_3 = u_button_3.real;
      offset += sizeof(this->button_3);
      union {
        bool real;
        uint8_t base;
      } u_button_4;
      u_button_4.base = 0;
      u_button_4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_4 = u_button_4.real;
      offset += sizeof(this->button_4);
      union {
        bool real;
        uint8_t base;
      } u_button_5;
      u_button_5.base = 0;
      u_button_5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_5 = u_button_5.real;
      offset += sizeof(this->button_5);
      union {
        bool real;
        uint8_t base;
      } u_button_6;
      u_button_6.base = 0;
      u_button_6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->button_6 = u_button_6.real;
      offset += sizeof(this->button_6);
     return offset;
    }

    const char * getType(){ return "rover_msgs/GripperMotion"; };
    const char * getMD5(){ return "8edaeaec64be0c5d3ae535eef1f2c3ef"; };

  };

}
#endif