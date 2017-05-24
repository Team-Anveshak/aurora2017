#!/bin/bash
sudo add-apt-repository ppa:mc3man/trusty-media
sudo apt-get update 
sudo apt-get dist-upgrade 
sudo apt-get install ffmpeg
sudo apt-get install build-essential autoconf libjpeg-dev libavformat-dev libavcodec-dev libswscale-dev subversion git
tar -xvzf ~/Downloads/motion-3.2.12.tar.gz 
cd motion-3.2.12
echo '#include </usr/include/linux/videodev.h>' | cat - track.h > temp && mvtemp track.h
echo '#include <linux/videodev2.h>' | cat - track.c > temp && mvtemp track.c
sudo ln -s /usr/include/libv4l1-videodev.h /usr/include/linux/videodev.h
./configure
sudo make
sudo make install
sudo mkdir /var/run/motion
sudo chmod a+rwxt /var/run/motion
cd ../../..
cd /usr/local/etc
rm -rf motion-dist.conf
cd
cd motion-3.2.12/
sudo cp -a motion-dist.conf thread1.conf thread2.conf thread3.conf thread4.conf /usr/local/etc/
sudo mv /usr/local/etc/motion-dist.conf /usr/local/etc/motion.conf



