#ifndef _ROS_rover_msgs_SC_task_h
#define _ROS_rover_msgs_SC_task_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class SC_task : public ros::Msg
  {
    public:
      float Atm_temp;
      float Atm_press;
      float Soil_humi;
      float Altitude;
      float Soil_temp;

    SC_task():
      Atm_temp(0),
      Atm_press(0),
      Soil_humi(0),
      Altitude(0),
      Soil_temp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->Atm_temp);
      offset += serializeAvrFloat64(outbuffer + offset, this->Atm_press);
      offset += serializeAvrFloat64(outbuffer + offset, this->Soil_humi);
      offset += serializeAvrFloat64(outbuffer + offset, this->Altitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->Soil_temp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Atm_temp));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Atm_press));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Soil_humi));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Altitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->Soil_temp));
     return offset;
    }

    const char * getType(){ return "rover_msgs/SC_task"; };
    const char * getMD5(){ return "b900671081180e4f2234b5fd31a35404"; };

  };

}
#endif