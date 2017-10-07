#ifndef _ROS_rover_msgs_Power_h
#define _ROS_rover_msgs_Power_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rover_msgs
{

  class Power : public ros::Msg
  {
    public:
      float power_1;
      float power_2;
      float power_3;
      float power_4;
      float power_5;
      float power_6;
      float power_7;
      float bat1[7];
      float bat2[7];
      float bat3[7];
      float bat4[7];
      float bat5[7];
      float bat6[7];
      float bat7[7];

    Power():
      power_1(0),
      power_2(0),
      power_3(0),
      power_4(0),
      power_5(0),
      power_6(0),
      power_7(0),
      bat1(),
      bat2(),
      bat3(),
      bat4(),
      bat5(),
      bat6(),
      bat7()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->power_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_2);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_3);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_4);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_5);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_6);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_7);
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat1[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat2[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat3[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat4[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat5[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat6[i]);
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->bat7[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_4));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_5));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_6));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_7));
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat1[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat2[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat3[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat4[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat5[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat6[i]));
      }
      for( uint8_t i = 0; i < 7; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bat7[i]));
      }
     return offset;
    }

    const char * getType(){ return "rover_msgs/Power"; };
    const char * getMD5(){ return "50044eea4a2b4dfd6071c2aa9e0bcb01"; };

  };

}
#endif