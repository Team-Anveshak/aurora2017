#!/bin/bash

sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
sudo apt-get update
sudo apt-get install ros-indigo-desktop-full
sudo rosdep init
sudo rosdep update
echo "source /opt/ros/indigo/setup.bash" >> ~/.bashrc
source ~/.bashrc
sudo apt-get install python-rosinstall
sudo apt-get install ros-indigo-joy
sudo apt-get install ros-indigo-robot-localization
sudo apt-get install ros-indigo-rosserial-arduino
sudo apt-get install ros-indigo-rosserial-python
sudo apt-get install ros-indigo-teleop-twist-joy
sudo apt-get install ros-indigo-navigation

