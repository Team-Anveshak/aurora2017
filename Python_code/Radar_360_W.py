

#Arduino code : auto_radar_nav

#The below code receives laser data (radial values - 0 to any theta) and plots the same onto a polar plot. 
#Each line read from the serial port comprises of radial distance values between 0 to any degree.
#There is a time delay between plots because of the time taken to complete the sensor rotation to the required angle.

import numpy as np
import matplotlib.pyplot as plt
import pyart
from pylab import *
import re

import serial
import time 
from drawnow import *
ser = serial.Serial('/dev/ttyACM1', 9600)
time.sleep(2)

plt.ion()
def fun() :
    plt.polar(data,'ro')
    plt.show()

while True:
    while (ser.inWaiting()==0): #Wait here until there is data
        pass #do nothing
    data=ser.readline()
    data=re.sub('[^0-9 ]+', '', data)
    data=data.split()
    data=[int(a) for a in data]
    data = np.array(data)
    # print data
    # print type(data)
    # print np.amin(data[np.where(data!=0)])
    data=np.array(data)
    data=data[np.where(data<400)]

    drawnow(fun)
    plt.pause(.000001)#sthash.JUzdSP5G.dpuf