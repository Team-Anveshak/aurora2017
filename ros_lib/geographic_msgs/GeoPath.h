#ifndef _ROS_geographic_msgs_GeoPath_h
#define _ROS_geographic_msgs_GeoPath_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geographic_msgs/GeoPoseStamped.h"

namespace geographic_msgs
{

  class GeoPath : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t poses_length;
      geographic_msgs::GeoPoseStamped st_poses;
      geographic_msgs::GeoPoseStamped * poses;

    GeoPath():
      header(),
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t poses_lengthT = *(inbuffer + offset++);
      if(poses_lengthT > poses_length)
        this->poses = (geographic_msgs::GeoPoseStamped*)realloc(this->poses, poses_lengthT * sizeof(geographic_msgs::GeoPoseStamped));
      offset += 3;
      poses_length = poses_lengthT;
      for( uint8_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geographic_msgs::GeoPoseStamped));
      }
     return offset;
    }

    const char * getType(){ return "geographic_msgs/GeoPath"; };
    const char * getMD5(){ return "1476008e63041203a89257cfad97308f"; };

  };

}
#endif