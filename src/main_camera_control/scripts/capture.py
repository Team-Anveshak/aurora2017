#!/usr/bin/env python
import os
import sys
import time
import math

def motioncam():
 	rospy.init_node('motioncam', anonymous=True)
	
 	if not rospy.is_shutdown():
 		os.system("sudo motion")		

 	if rospy.is_shutdown():
 		print "exiting motion...."
 		exit()

if __name__ == '__main__':
	try:
		motioncam()
	except rospy.ROSInterruptException:
		pass
