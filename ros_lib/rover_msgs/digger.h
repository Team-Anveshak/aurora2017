#ifndef _ROS_rover_msgs_digger_h
#define _ROS_rover_msgs_digger_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class digger : public ros::Msg
  {
    public:
      int16_t Step_UD_dir;
      int16_t Step_UD_step;
      int16_t LR_dir;
      int16_t LR_step;
      int16_t probe_dir;
      int16_t probe_step;
      int16_t sensor_flag;
      int16_t drill;
      int16_t reset_flag;

    digger():
      Step_UD_dir(0),
      Step_UD_step(0),
      LR_dir(0),
      LR_step(0),
      probe_dir(0),
      probe_step(0),
      sensor_flag(0),
      drill(0),
      reset_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_Step_UD_dir;
      u_Step_UD_dir.real = this->Step_UD_dir;
      *(outbuffer + offset + 0) = (u_Step_UD_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Step_UD_dir.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Step_UD_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_Step_UD_step;
      u_Step_UD_step.real = this->Step_UD_step;
      *(outbuffer + offset + 0) = (u_Step_UD_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Step_UD_step.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Step_UD_step);
      union {
        int16_t real;
        uint16_t base;
      } u_LR_dir;
      u_LR_dir.real = this->LR_dir;
      *(outbuffer + offset + 0) = (u_LR_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LR_dir.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->LR_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_LR_step;
      u_LR_step.real = this->LR_step;
      *(outbuffer + offset + 0) = (u_LR_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LR_step.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->LR_step);
      union {
        int16_t real;
        uint16_t base;
      } u_probe_dir;
      u_probe_dir.real = this->probe_dir;
      *(outbuffer + offset + 0) = (u_probe_dir.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probe_dir.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->probe_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_probe_step;
      u_probe_step.real = this->probe_step;
      *(outbuffer + offset + 0) = (u_probe_step.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_probe_step.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->probe_step);
      union {
        int16_t real;
        uint16_t base;
      } u_sensor_flag;
      u_sensor_flag.real = this->sensor_flag;
      *(outbuffer + offset + 0) = (u_sensor_flag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sensor_flag.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->sensor_flag);
      union {
        int16_t real;
        uint16_t base;
      } u_drill;
      u_drill.real = this->drill;
      *(outbuffer + offset + 0) = (u_drill.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_drill.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->drill);
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
      } u_Step_UD_dir;
      u_Step_UD_dir.base = 0;
      u_Step_UD_dir.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Step_UD_dir.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Step_UD_dir = u_Step_UD_dir.real;
      offset += sizeof(this->Step_UD_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_Step_UD_step;
      u_Step_UD_step.base = 0;
      u_Step_UD_step.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Step_UD_step.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Step_UD_step = u_Step_UD_step.real;
      offset += sizeof(this->Step_UD_step);
      union {
        int16_t real;
        uint16_t base;
      } u_LR_dir;
      u_LR_dir.base = 0;
      u_LR_dir.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LR_dir.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->LR_dir = u_LR_dir.real;
      offset += sizeof(this->LR_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_LR_step;
      u_LR_step.base = 0;
      u_LR_step.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LR_step.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->LR_step = u_LR_step.real;
      offset += sizeof(this->LR_step);
      union {
        int16_t real;
        uint16_t base;
      } u_probe_dir;
      u_probe_dir.base = 0;
      u_probe_dir.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probe_dir.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->probe_dir = u_probe_dir.real;
      offset += sizeof(this->probe_dir);
      union {
        int16_t real;
        uint16_t base;
      } u_probe_step;
      u_probe_step.base = 0;
      u_probe_step.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_probe_step.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->probe_step = u_probe_step.real;
      offset += sizeof(this->probe_step);
      union {
        int16_t real;
        uint16_t base;
      } u_sensor_flag;
      u_sensor_flag.base = 0;
      u_sensor_flag.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sensor_flag.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sensor_flag = u_sensor_flag.real;
      offset += sizeof(this->sensor_flag);
      union {
        int16_t real;
        uint16_t base;
      } u_drill;
      u_drill.base = 0;
      u_drill.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_drill.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->drill = u_drill.real;
      offset += sizeof(this->drill);
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

    const char * getType(){ return "rover_msgs/digger"; };
    const char * getMD5(){ return "a7cf0473c0894e95cbc4f5151b34a89d"; };

  };

}
#endif