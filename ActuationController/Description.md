# Writeup about control and actuation for the car

## Arduino controlling a stepper motor for steering hack

Stepper motors are used everywhere in actuations because they help with accurate controlling. We will be implementing the same controlled by an arduino to translate rotational motion to drive the steering wheel.

This will help accurately control the degree at which the entire steering wheel is rotated.

It's important to know that this is not a long term solution but a way to create somewhat of a working hack that can be used with a basic car.

## The same arduino controlling the accelerator pedal

Similarly a stepper motor is used for accurate actuation of the accelerator pedal.

## The same arduino is used to control the brake pedal.

Same concept used for the brake pedal.

## Comm with the USB serial port 

This is a jugaad. To minimize the number of ports and the controlling motors, the value being passed to the arduino actually are the entire steering values.

The first two values being passed to the arduino contain the degree to which the steering angle is shifted. The next two values contain the accelerator value, and the last two contain the values at which the brake pedal is to be pushed.

Now the rate at which the communication occurs is very important. This feature hasn't still been implemented. Basically the communication should happen as many times as a second as possible to best control the car.
