# GPIO-Dual-Motor-PWM.cpp

## What is it?
A function that sends appropriately timed pulses to two independant motors over gpio, and some simple driver code to run the function

## Why are you making this?
I wanted to make a robot tht balances on two wheels, it's been done before, but I wanted to do it myself. This is the first step of that process.

## What can it do?
At the moment, it's only capable of sending timed pulses between -100 and 100 independantly to two motors at once. The function also supports changing how fast the micropulses are, and how many pulses are sent. The function is designed to be called multiple times from whithin a control loop, and then immediately returns control back to main.

## Are you going to update this?
Probably not, it's basically done. If a better method of accomplishing this is found, I'll write a whole new program and upload that too.

## Can I use this for my own project?
Yes! I don't care how or where this code is used. It's been done hundreds of times anyway, so it's stupid to treat it like some proprietary secret.

## If I want to use this, how do I get it to work?
With the current implementation, this will only work on a raspberry pi. You will also need to install the wiringPi library in order to compile this. Compile it with "g++ name.cpp -o name -lwiringPi". You will also need to use an Hbridge DC motor driver, and wire pins 0,1 and 3,4 to each motor input. The GPIO pins do not provide enough power to drive a motor of any size.
