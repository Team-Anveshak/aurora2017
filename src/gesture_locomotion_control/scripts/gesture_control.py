#!/usr/bin/env python
import rospy
import sys
#sys.path.append('../lib/')
from rover_msgs.msg import WheelVelocity
from rover_msgs.msg import Arm
from myo import Myo
from vibration_type import VibrationType
from device_listener import DeviceListener
from pose_type import PoseType

gesture=0
mode=0

class PrintPoseListener(DeviceListener):
	def __init__(self):
		self.gesture_pub=rospy.Publisher('rover1/wheel_vel', WheelVelocity,queue_size=10)
		self.gesture_arm_pub=rospy.Publisher("arm",Arm,queue_size=10)


	def on_pose(self, pose):
		vel =WheelVelocity()
		arm=Arm()

		pose_type = PoseType(pose)
		global gesture
		gesture = pose_type.value
<<<<<<< HEAD
		rospy.loginfo(pose_type.value)

		if(gesture==0):
=======
		if(pose_type.value==5 and mode=0):
			mode=1
		elif(pose_type.value==5 and mode=1):
			mode=0

		if(mode==0):
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
		if(mode==1):
>>>>>>> 45a4c7cab44100cbc265d4d7acb486f577094443
			vel.left=0
			vel.right=0
			if(gesture==2):
				arm.acc_forw=1
				arm.acc_back=0

			if(gesture==3):
				arm.acc_back=1
				arm.acc_forw=0
			if(gesture==1):
				arm.grip=1
			if(gesture==4):
				arm.grip==-1
			else:
				arm.acc_forw=0
				arm.acc_back=0
				arm.grip=0






		self.gesture_pub.publish(vel)
		self.gesture_arm_pub.publish(arm)

		




		


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