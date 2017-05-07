from collections import deque
import numpy as np
#import imutils
import cv2
def nothing(x):
    pass
cv2.namedWindow('HueComp')
cv2.namedWindow('SatComp')
cv2.namedWindow('ValComp')

cv2.createTrackbar('hmin', 'HueComp',12,179,nothing)
cv2.createTrackbar('hmax', 'HueComp',37,179,nothing)

cv2.createTrackbar('smin', 'SatComp',96,255,nothing)
cv2.createTrackbar('smax', 'SatComp',255,255,nothing)

cv2.createTrackbar('vmin', 'ValComp',186,255,nothing)
cv2.createTrackbar('vmax', 'ValComp',255,255,nothing)

hmn = cv2.getTrackbarPos('hmin','HueComp')
hmx = cv2.getTrackbarPos('hmax','HueComp')


smn = cv2.getTrackbarPos('smin','SatComp')
smx = cv2.getTrackbarPos('smax','SatComp')


vmn = cv2.getTrackbarPos('vmin','ValComp')
vmx = cv2.getTrackbarPos('vmax','ValComp')

yellowLower = (60 ,100, 100)
yellowUpper = (80, 255, 255)
pts = deque(maxlen=100)

cap = cv2.VideoCapture(0)

# keep looping
while True:
	# grab the current frame
	_,frame = cap.read()
	#frame = imutils.resize(frame, width=600)
	# blurred = cv2.GaussianBlur(frame, (11, 11), 0)
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	hue,sat,val = cv2.split(hsv)
	
	hmn = cv2.getTrackbarPos('hmin','HueComp')
	hmx = cv2.getTrackbarPos('hmax','HueComp')


	smn = cv2.getTrackbarPos('smin','SatComp')
	smx = cv2.getTrackbarPos('smax','SatComp')


	vmn = cv2.getTrackbarPos('vmin','ValComp')
	vmx = cv2.getTrackbarPos('vmax','ValComp')
	
	hthresh = cv2.inRange(np.array(hue),np.array(hmn),np.array(hmx))
	sthresh = cv2.inRange(np.array(sat),np.array(smn),np.array(smx))
	vthresh = cv2.inRange(np.array(val),np.array(vmn),np.array(vmx))
	mask = cv2.bitwise_and(hthresh,cv2.bitwise_and(sthresh,vthresh))
     
    # hdisplay=cv2.bitwise_and(frame,frame,mask=hthresh)
    # sdisplay=cv2.bitwise_and(frame,frame,mask=sthresh)
    # vdisplay=cv2.bitwise_and(frame,frame,mask=vthresh)

	cv2.imshow("HueComp", hthresh)
	cv2.imshow("SatComp", sthresh)
	cv2.imshow("ValComp", vthresh)


    
	# construct a mask for the color "green", then perform
	# a series of dilations and erosions to remove any small
	# blobs left in the mask
	#mask = cv2.inRange(hsv, yellowLower, yellowUpper)
	mask = cv2.erode(mask, None, iterations=2)
	mask = cv2.dilate(mask, None, iterations=2)

	# find contours in the mask and initialize the current
	# (x, y) center of the ball
	cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
		cv2.CHAIN_APPROX_SIMPLE)[-2]
	center = None

	# only proceed if at least one contour was found
	if len(cnts) > 0:
		# find the largest contour in the mask, then use
		# it to compute the minimum enclosing circle and
		# centroid
		c = max(cnts, key=cv2.contourArea)
		((x, y), radius) = cv2.minEnclosingCircle(c)
		M = cv2.moments(c)
		center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

		# only proceed if the radius meets a minimum size
		if radius > 10:
			# draw the circle and centroid on the frame,
			# then update the list of tracked points
			cv2.circle(frame, (int(x), int(y)), int(radius),
				(0, 255, 255), 2)
			cv2.circle(frame, center, 5, (0, 0, 255), -1)

	# update the points queue
	pts.appendleft(center)

	# loop over the set of tracked points
	#for i in xrange(1, len(pts)):
		# if either of the tracked points are None, ignore
		# them
		#if pts[i - 1] is None or pts[i] is None:
			#continue

		# otherwise, compute the thickness of the line and
		# draw the connecting lines
		#thickness = int(np.sqrt(100 / float(i + 1)) * 1.5)
		#cv2.line(frame, pts[i - 1], pts[i], (0, 0, 255), thickness)

	# show the frame to our screen
	cv2.imshow("Frame", frame)
	key = cv2.waitKey(1) & 0xFF

	# if the 'q' key is pressed, stop the loop
	if key == ord("q"):
		break

# cleanup the camera and close any open windows
camera.release()
cv2.destroyAllWindows()