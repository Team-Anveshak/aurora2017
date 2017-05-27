#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# Copyright (c) 2016, Tal Regev.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of the Willow Garage nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.


#check if it checks for the status of the gps flag from time to time. The code needs to be modified. Also, In case the the ball wasn't detected, we should proceed to the next gps coordinate provided. This has to be taken care of too.. 
import sys
import time
import math
import rospy
import numpy as np
import cv2
from std_msgs.msg import Float32
import std_msgs.msg
from cv_bridge import CvBridge

flg=0;

class Source:

    def __init__(self):
        self.dist_pub = rospy.Publisher('rover1/ball_distance', std_msgs.msg.Float32, queue_size = 10)
        self.flag_pub = rospy.Publisher('rover1/FLAG_Camera', std_msgs.msg.Float32, queue_size = 10)

    def subsciber_flag(self):
	rospy.Subscriber("/gps_loc_flg", Float32, self.callback)

    def callback(self,msg):
	flg=msg.data

    def spin(self):
        time.sleep(1.0)
        started = time.time()

#************************************************************************************************************        
        imag = cv2.imread('/home/niyas/cfi/rover-control/src/ball_nav/ball.jpg',1)

        imags=imag

        im=imag


        img = cv2.cvtColor(imag, cv2.COLOR_BGR2GRAY)

        hsv = cv2.cvtColor(imag,cv2.COLOR_BGR2HSV)      #converting to hsv space

# define threshold range of yellow color in HSV
# ************************************************************************************************************
        lower_yellow = np.array([26, 162, 66])
        upper_yellow = np.array([52, 255, 255])

        # Threshold the HSV image to get only yellow colors
        mask1 = cv2.inRange(hsv, lower_yellow, upper_yellow)
        mask = cv2.dilate(mask1, None, iterations=2)
        mask = cv2.erode(mask, None, iterations=2)

        # Bitwise-AND mask and original image
        res = cv2.bitwise_and(imag,imag, mask= mask)

        #Find contours
        ims, cnts, hierarchys = cv2.findContours(mask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

        #find maximum contour
        c = max(cnts, key=cv2.contourArea)
        epsilon = 0.1*cv2.arcLength(c,True)
        approx = cv2.approxPolyDP(c,epsilon,True)
        hull = cv2.convexHull(c)
        cv2.drawContours(im, [hull], 0, (150,150,0), 2)
        cv2.drawContours(imags, c, -1, (0,0,255), 3)
        x,y,w,h = cv2.boundingRect(c)
        cv2.rectangle(im,(x,y),(x+w,y+h),(200,0,0),2)

        ((x, y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)

        x1,y1,w,h = cv2.boundingRect(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

        cv2.circle(imag, (int(x), int(y)), int(radius),(0, 255, 255), 2)
        cv2.circle(imag, center, 3, (0, 0, 255), -1)

        cv2.rectangle(imag,(x1,y1),(x1+w,y1+h),(0,255,0),2)

        # cv2.imshow("encl_circle", imag)
            
# initialize the known distance from the camera to the object
# *****************************************************************************************************
        KNOWN_DISTANCE = 50.0
         
# initialize the known object width
# *****************************************************************************************************
        KNOWN_WIDTH = 6.5
          
        perWidth=2*radius
        focalLength = (perWidth * KNOWN_DISTANCE) / KNOWN_WIDTH

#******************************************************************************************************
        cap = cv2.VideoCapture(0)
        # print "\nDistance to traverse : \n\n"
        #cv2.namedWindow('encl_circle',cv2.WINDOW_NORMAL)

        count_y=0
        count_n=0
        center=[0,0]

        distance=0
        r=distance
        flag=0
        done=0
        temp=0

        cvb = CvBridge()
	
        while done==0:

            ret, frame = cap.read()
            # cv2.imshow('frame',frame)
            imag=frame
            imags=imag

            im=imag

            img = cv2.cvtColor(imag, cv2.COLOR_BGR2GRAY)

            hsv = cv2.cvtColor(imag,cv2.COLOR_BGR2HSV)      #converting to hsv space

# define range of yellow color in HSV
# *********************************************************************** 
            lower_yellow = np.array([26, 162, 66])
            upper_yellow = np.array([52, 255, 255])

            # Threshold the HSV image to get only yellow colors
            mask1 = cv2.inRange(hsv, lower_yellow, upper_yellow)
            mask = cv2.dilate(mask1, None, iterations=2)
            mask = cv2.erode(mask, None, iterations=2)

            # Bitwise-AND mask and original image
            res = cv2.bitwise_and(imag,imag, mask= mask)

            #Find contours
            ims, cnts, hierarchys = cv2.findContours(mask.copy(), cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

            if len(cnts) > 0:# and k==1:
                #find maximum contour
                c = max(cnts, key=cv2.contourArea)
                epsilon = 0.1*cv2.arcLength(c,True)
                approx = cv2.approxPolyDP(c,epsilon,True)
                hull = cv2.convexHull(c)
                #cv2.drawContours(im, [hull], 0, (150,150,0), 2)
                #cv2.drawContours(imags, c, -1, (0,0,255), 3)
                x,y,w,h = cv2.boundingRect(c)
                #cv2.rectangle(im,(x,y),(x+w,y+h),(200,0,0),2)

                ((x, y), radius) = cv2.minEnclosingCircle(c)
                    
                if radius>5:
                    M = cv2.moments(c)
                    try:
                        x1,y15w,h = cv2.boundingRect(c)
                        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

                        #cv2.circle(imag, (int(x), int(y)), int(radius),(0, 255, 255), 2)
                        #cv2.circle(imag, center, 3, (0, 0, 255), -1)

                        #cv2.rectangle(imag,(x1,y1),(x1+w,y1+h),(0,255,0),2)

                        #cv2.imshow("encl_circle", imag)

                        marker=cv2.minAreaRect(c)
                        perWidth=2*radius#marker[1][0]
                        distance = (KNOWN_WIDTH * focalLength) / perWidth
                    
                        count_y+=1
                        temp+=distance
                    except :
                        count_n+=1
                        #cv2.imshow("encl_circle",frame)
                        continue
                # if ((center[0] in range(169,474)) and (center[1] in range(62,380)) and count_y>30 and count_n<10 and done==0) :
                if ((center[0] in range(169,474)) and count_y>6 and count_n<3) : #only horizontally bounded
                    r=temp*1.0/count_y
                    done=1
                    flag=1
#Computing r as an average over count_y readings
            self.dist_pub.publish(r)
            self.flag_pub.publish(flag)
            time.sleep(0.03)


def main(args):
    s = Source()
    rospy.init_node('Source')
    try:
        while(True):
            s.subsciber_flag()
            if(flg==1):
                s.spin()
                rospy.spin()
                outcome = 'test completed'
    except KeyboardInterrupt:
        print "shutting down"
        outcome = 'keyboard interrupt'
    rospy.core.signal_shutdown(outcome)

if __name__ == '__main__':
    main(sys.argv)
