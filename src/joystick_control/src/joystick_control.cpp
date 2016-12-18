#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

using namespace ros;

class JoystickControl{
    public:
        JoystickControl();

    private:
        void joystickCallback(const sensor_msgs::Joy::ConstPtr& joy);
        NodeHandle nh;
        Publisher wheel_velocity_publisher;
        Subscriber joy_subscriber;
};
