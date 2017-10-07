#ifndef _ROS_rover_msgs_Arm_h
#define _ROS_rover_msgs_Arm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class Arm : public ros::Msg
  {
    public:
      int16_t acc_forw;
      int16_t acc_back;
      int16_t chain_forw;
      int16_t chain_back;
      int16_t base_right;
      int16_t base_left;
      int16_t grip;
      int16_t rotate_clk;
      int16_t rotate_aclk;
      int16_t wrist;
      int16_t reset_flag;

    Arm():
      acc_forw(0),
      acc_back(0),
      chain_forw(0),
      chain_back(0),
      base_right(0),
      base_left(0),
      grip(0),
      rotate_clk(0),
      rotate_aclk(0),
      wrist(0),
      reset_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_acc_forw;
      u_acc_forw.real = this->acc_forw;
      *(outbuffer + offset + 0) = (u_acc_forw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_forw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_forw);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_back;
      u_acc_back.real = this->acc_back;
      *(outbuffer + offset + 0) = (u_acc_back.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_acc_back.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->acc_back);
      union {
        int16_t real;
        uint16_t base;
      } u_chain_forw;
      u_chain_forw.real = this->chain_forw;
      *(outbuffer + offset + 0) = (u_chain_forw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_chain_forw.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->chain_forw);
      union {
        int16_t real;
        uint16_t base;
      } u_chain_back;
      u_chain_back.real = this->chain_back;
      *(outbuffer + offset + 0) = (u_chain_back.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_chain_back.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->chain_back);
      union {
        int16_t real;
        uint16_t base;
      } u_base_right;
      u_base_right.real = this->base_right;
      *(outbuffer + offset + 0) = (u_base_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base_right.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->base_right);
      union {
        int16_t real;
        uint16_t base;
      } u_base_left;
      u_base_left.real = this->base_left;
      *(outbuffer + offset + 0) = (u_base_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_base_left.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->base_left);
      union {
        int16_t real;
        uint16_t base;
      } u_grip;
      u_grip.real = this->grip;
      *(outbuffer + offset + 0) = (u_grip.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_grip.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->grip);
      union {
        int16_t real;
        uint16_t base;
      } u_rotate_clk;
      u_rotate_clk.real = this->rotate_clk;
      *(outbuffer + offset + 0) = (u_rotate_clk.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotate_clk.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rotate_clk);
      union {
        int16_t real;
        uint16_t base;
      } u_rotate_aclk;
      u_rotate_aclk.real = this->rotate_aclk;
      *(outbuffer + offset + 0) = (u_rotate_aclk.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotate_aclk.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->rotate_aclk);
      union {
        int16_t real;
        uint16_t base;
      } u_wrist;
      u_wrist.real = this->wrist;
      *(outbuffer + offset + 0) = (u_wrist.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wrist.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wrist);
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
      union {
        int16_t real;
        uint16_t base;
      } u_acc_forw;
      u_acc_forw.base = 0;
      u_acc_forw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_forw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_forw = u_acc_forw.real;
      offset += sizeof(this->acc_forw);
      union {
        int16_t real;
        uint16_t base;
      } u_acc_back;
      u_acc_back.base = 0;
      u_acc_back.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_acc_back.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc_back = u_acc_back.real;
      offset += sizeof(this->acc_back);
      union {
        int16_t real;
        uint16_t base;
      } u_chain_forw;
      u_chain_forw.base = 0;
      u_chain_forw.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_chain_forw.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->chain_forw = u_chain_forw.real;
      offset += sizeof(this->chain_forw);
      union {
        int16_t real;
        uint16_t base;
      } u_chain_back;
      u_chain_back.base = 0;
      u_chain_back.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_chain_back.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->chain_back = u_chain_back.real;
      offset += sizeof(this->chain_back);
      union {
        int16_t real;
        uint16_t base;
      } u_base_right;
      u_base_right.base = 0;
      u_base_right.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base_right.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->base_right = u_base_right.real;
      offset += sizeof(this->base_right);
      union {
        int16_t real;
        uint16_t base;
      } u_base_left;
      u_base_left.base = 0;
      u_base_left.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_base_left.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->base_left = u_base_left.real;
      offset += sizeof(this->base_left);
      union {
        int16_t real;
        uint16_t base;
      } u_grip;
      u_grip.base = 0;
      u_grip.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_grip.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->grip = u_grip.real;
      offset += sizeof(this->grip);
      union {
        int16_t real;
        uint16_t base;
      } u_rotate_clk;
      u_rotate_clk.base = 0;
      u_rotate_clk.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotate_clk.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rotate_clk = u_rotate_clk.real;
      offset += sizeof(this->rotate_clk);
      union {
        int16_t real;
        uint16_t base;
      } u_rotate_aclk;
      u_rotate_aclk.base = 0;
      u_rotate_aclk.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotate_aclk.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->rotate_aclk = u_rotate_aclk.real;
      offset += sizeof(this->rotate_aclk);
      union {
        int16_t real;
        uint16_t base;
      } u_wrist;
      u_wrist.base = 0;
      u_wrist.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wrist.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->wrist = u_wrist.real;
      offset += sizeof(this->wrist);
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

    const char * getType(){ return "rover_msgs/Arm"; };
    const char * getMD5(){ return "c65e328e94b4ec51b6508d481408f5c9"; };

  };

}
#endif