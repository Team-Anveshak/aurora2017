#!/usr/bin/env python
import rospy
import sys
sys.path.append('../lib/')
from rover_msgs.msg import WheelVelocity
from myo import Myo
from vibration_type import VibrationType
from device_listener import DeviceListener
from pose_type import PoseType

gesture=0

class PrintPoseListener(DeviceListener):
	def __init__(self):
		self.gesture_pub=rospy.Publisher('rover1/wheel_vel', WheelVelocity,queue_size=10)


	def on_pose(self, pose):
		vel =WheelVelocity()

		pose_type = PoseType(pose)
		global gesture
		gesture = pose_type.value

		if(gesture==0):
			vel.left=0
			vel.right=0

		elif(gesture==2):
			vel.left=-30
			vel.right=30
		elif(gesture==3):
			vel.left=30
			vel.right=-30
		elif(gesture==4):
			vel.left=30
			vel.right=30
		elif(gesture==1):
			vel.right=-30
			vel.left=-30
		else:
			vel.right=0
			vel.left=0

		self.gesture_pub.publish(vel)

		




		


def main():
    rospy.loginfo('Start Myo for Linux')

    gesture_pub=rospy.Publisher('rover1/wheel_vel', WheelVelocity,queue_size=10)

    listener = PrintPoseListener()
    myo = Myo()

    try:
        myo.connect()
        myo.add_listener(listener)
        while True:
            myo.run()

    except KeyboardInterrupt:
        pass
    except ValueError as ex:
        print(ex)
    finally:
        myo.safely_disconnect()
        print('Finished.')

if __name__ == '__main__':
	rospy.init_node("gesture_control")
    main()