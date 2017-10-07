#ifndef _ROS_rover_msgs_CameraMotion_h
#define _ROS_rover_msgs_CameraMotion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class CameraMotion : public ros::Msg
  {
    public:
      int32_t X_button;
      int32_t B_button;
      int32_t Y_button;
      int32_t A_button;
      int32_t reset_flag;

    CameraMotion():
      X_button(0),
      B_button(0),
      Y_button(0),
      A_button(0),
      reset_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_X_button;
      u_X_button.real = this->X_button;
      *(outbuffer + offset + 0) = (u_X_button.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_X_button.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_X_button.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_X_button.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->X_button);
      union {
        int32_t real;
        uint32_t base;
      } u_B_button;
      u_B_button.real = this->B_button;
      *(outbuffer + offset + 0) = (u_B_button.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B_button.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B_button.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B_button.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->B_button);
      union {
        int32_t real;
        uint32_t base;
      } u_Y_button;
      u_Y_button.real = this->Y_button;
      *(outbuffer + offset + 0) = (u_Y_button.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Y_button.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Y_button.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Y_button.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Y_button);
      union {
        int32_t real;
        uint32_t base;
      } u_A_button;
      u_A_button.real = this->A_button;
      *(outbuffer + offset + 0) = (u_A_button.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A_button.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A_button.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A_button.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->A_button);
      union {
        int32_t real;
        uint32_t base;
      } u_reset_flag;
      u_reset_flag.real = this->reset_flag;
      *(outbuffer + offset + 0) = (u_reset_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reset_flag.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reset_flag.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reset_flag.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reset_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_X_button;
      u_X_button.base = 0;
      u_X_button.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_X_button.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_X_button.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_X_button.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->X_button = u_X_button.real;
      offset += sizeof(this->X_button);
      union {
        int32_t real;
        uint32_t base;
      } u_B_button;
      u_B_button.base = 0;
      u_B_button.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B_button.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B_button.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B_button.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->B_button = u_B_button.real;
      offset += sizeof(this->B_button);
      union {
        int32_t real;
        uint32_t base;
      } u_Y_button;
      u_Y_button.base = 0;
      u_Y_button.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Y_button.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Y_button.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Y_button.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Y_button = u_Y_button.real;
      offset += sizeof(this->Y_button);
      union {
        int32_t real;
        uint32_t base;
      } u_A_button;
      u_A_button.base = 0;
      u_A_button.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A_button.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A_button.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A_button.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->A_button = u_A_button.real;
      offset += sizeof(this->A_button);
      union {
        int32_t real;
        uint32_t base;
      } u_reset_flag;
      u_reset_flag.base = 0;
      u_reset_flag.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_reset_flag.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_reset_flag.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_reset_flag.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->reset_flag = u_reset_flag.real;
      offset += sizeof(this->reset_flag);
     return offset;
    }

    const char * getType(){ return "rover_msgs/CameraMotion"; };
    const char * getMD5(){ return "e9f74620875109c0323fbfee10cf0d8f"; };

  };

}
#endif