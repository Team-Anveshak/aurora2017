#ifndef _ROS_rover_msgs_Enc_h
#define _ROS_rover_msgs_Enc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class Enc : public ros::Msg
  {
    public:
      float rpm_enc_1;
      float rpm_enc_2;

    Enc():
      rpm_enc_1(0),
      rpm_enc_2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->rpm_enc_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->rpm_enc_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rpm_enc_1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rpm_enc_2));
     return offset;
    }

    const char * getType(){ return "rover_msgs/Enc"; };
    const char * getMD5(){ return "7fc26589b8f906330b9bf64006152365"; };

  };

}
#endif