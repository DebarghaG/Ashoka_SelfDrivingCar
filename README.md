# Ashokan_SelfDrivingCar

Over the next month , I will attempt to write the code to run a self-driving car around campus, completely autonomously.

## StreamClient_Video
These libraries need to be run on individual Raspberry Pi communication protocol :
When the Stream_Client is run, it opens a network socket and sends the stream in the form of a set of jpeg images.

## CoreDrivingEngine
This is where all the streams come in, and the all the major image recognition algorithms occur.

## ActuationController
The core driving engine is supposed to send the actuation controller a 6 digit value, the first two digits of which are the steer angle, the next two are the accelerator speed, and the last two are the braking control. The arduino controls actuation motos according to the same values. 
