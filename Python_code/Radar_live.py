

#Arduino code : radar_work live

#The below code receives live laser data (theta and radial values) and plots the same onto a polar plot. 
#Each line read from the serial port comprises of a theta and the corresponding radial distance value.
#r values for same theta values are overwritten.

import numpy as np
import matplotlib.pyplot as plt
import pyart
from pylab import *
import re

import serial
import time 
from drawnow import *

ser = serial.Serial('/dev/ttyACM1', 9600)   #specify port and baudrate
time.sleep(2)


plt.ion()

def fun() :
    plt.polar(theta,r,'ro')
    plt.show()  #display the radar data

theta=np.arange(70,111)/180*np.pi
r=np.zeros(41)

temp=200
while True :
    while (ser.inWaiting()==0): #Wait here until there is data
        pass #do nothing
    #each line comprises of theta and corresponding radial distance
    data=ser.readline() #read in data from serial port from arduino
    data=re.sub('[^0-9 ]+', ' ', data)
    data=data.split()
    data=[int(a) for a in data] #extract the integers
    # print data
    data=np.array(data)
    # print len(data)

    try :
        if data[1]>200 :    #any reading exceeding 200cm
            data[1]=200
        theta[data[0]-70]=data[0]*np.pi/180
        r[data[0]-70]=(0.8*data[1]+0.2*temp)    #weighted average of r with the previous r value
        temp=data[1]    #storing the current r value to be used for weighted average in the next iter
        drawnow(fun)
        plt.pause(.0000001)#sthash.JUzdSP5G.dpuf
    except ValueError and IndexError:
        print "oops"