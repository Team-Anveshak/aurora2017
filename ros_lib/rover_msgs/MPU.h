#ifndef _ROS_rover_msgs_MPU_h
#define _ROS_rover_msgs_MPU_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Vector3.h"

namespace rover_msgs
{

  class MPU : public ros::Msg
  {
    public:
      geometry_msgs::Quaternion orientation;
      float orientation_covariance[9];
      geometry_msgs::Vector3 angular_velocity;
      float angular_velocity_covariance[9];
      geometry_msgs::Vector3 linear_acceleration;
      float linear_acceleration_covariance[9];

    MPU():
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->orientation.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->orientation_covariance[i]);
      }
      offset += this->angular_velocity.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_velocity_covariance[i]);
      }
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_acceleration_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->orientation.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->orientation_covariance[i]));
      }
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_velocity_covariance[i]));
      }
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 9; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_acceleration_covariance[i]));
      }
     return offset;
    }

    const char * getType(){ return "rover_msgs/MPU"; };
    const char * getMD5(){ return "2a1c12e6ecad236f76fdb98f7ce21822"; };

  };

}
#endif