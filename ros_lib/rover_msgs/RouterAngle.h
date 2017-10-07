#ifndef _ROS_rover_msgs_RouterAngle_h
#define _ROS_rover_msgs_RouterAngle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class RouterAngle : public ros::Msg
  {
    public:
      float angle;

    RouterAngle():
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
     return offset;
    }

    const char * getType(){ return "rover_msgs/RouterAngle"; };
    const char * getMD5(){ return "4edb55038e2b888976a0c0c56935341c"; };

  };

}
#endif