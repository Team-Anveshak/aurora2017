#!/usr/bin/env python
import rospy
import math
from sensor_msgs.msg import Joy
from rover_msgs.msg import GripperMotion

PI = 3.14159
motion_value = [False, False, False, False, False, False]


# To Control the Fripper of the Rover
#  @joyCallback callback function for joy subscriber
#     @x_axis_value- x axis position of joystick controller
#     @y_axis_value- y axis position of joystick controller
#     @scale- magnitude of a vector, lies between (0, 5)
#     @angle- horizontal plane angle made by controller
#  @__init__ initialising the rospy node (GripperControl)
class GripperControl:
    def __init__(self):
        rospy.init_node('GripperControl', anonymous = True)
        self.topic = rospy.get_param('~gripper_control', 'rover1/gripper_motion')

 
    def joyCallback(self, data):
        ##motion_value = [False, False, False, False, False, False]
        motion_value[0] = data.buttons[6]
        motion_value[1] = data.buttons[7]

        x_axis_val = data.axes[6]
        y_axis_val = data.axes[7]
        scale = 5 *math.sqrt(x_axis_val * x_axis_val + y_axis_val * y_axis_val)
        angle = math.atan2(y_axis_val,-x_axis_val) * 180 / PI
        if scale > 0.5:

            if angle < -150 or angle > 150 :
                motion_value[2]= True
	    else :
		motion_value[2]= False
            if angle > -30  and angle < 30:
                motion_value[3]= True
	    else :
		motion_value[3]= False
            if angle > 60  and angle < 120:
                motion_value[4]= True
	    else :
		motion_value[4]= False
            if angle > -120 and angle < -60:
                motion_value[5]= True
            else :
		motion_value[5]= False
	else:
	    motion_value[2] = False
	    motion_value[3] = False
	    motion_value[4] = False
	    motion_value[5] = False	
        rospy.loginfo("GripIn %d\t" % motion_value[0] +"GripOut %d\t" % motion_value[1] + "RollLeft %d\t" % motion_value[2] + "RollRight %d\t" % motion_value[3] + "PitchUp %d\t" % motion_value[4] + "PitchDown %d\t" % motion_value[5])

   
# @gripper_pub is assigned as a publisher for the rover/gripper_turn message
# @joy_sub is assigned as a subscriber for the joy message with the help of the joycallback function
    def start(self):
        gripper_pub = rospy.Publisher('rover1/gripper_turn', GripperMotion, queue_size = 10)
        joy_sub = rospy.Subscriber('joy', Joy, self.joyCallback)
        rate = rospy.Rate(10)

        while not rospy.is_shutdown():
            gripper_pub.publish( motion_value[0], motion_value[1], motion_value[2], motion_value[3], motion_value[4], motion_value[5])
            rate.sleep()

if __name__ == '__main__':
    try:
        gripperControl = GripperControl()
        gripperControl.start()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
