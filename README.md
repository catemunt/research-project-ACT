# 289312 Independent Research Project
## The Project
I want to use this Creative Tech Project to further the development of my Major Project.  My idea is to use physical computing to represent data in the project coming from the physical interactions from the audience and from the data held in the Unreal project. My Major Project, "The Train Of Many Stations" is an immersive art and technology installation where the audience enters a train carriage and are transported to different worlds, all from inside the train. It will use a combination of a custom-built interactive set and real-time rendering via Unreal Engine. We also aim to include interactive elements to further immerse and engage the audience. These interactions include having ambient lighting in the train that responds to the colour data from the world that is being travelled through and also having set lighting cycles that are triggered in different worlds, that create different ambiences. Upon the completion of this project, I hope to have a working prototype of the lighting procedures and ambient lighting that is triggered by a moving scene in Unreal. 

## The Tech
### Software
#### Unreal Engine
"Unreal Engine is the world’s most open and advanced real-time 3D creation tool. Continuously evolving to serve not only its original purpose as a state-of-the-art game engine, today it gives creators across industries the freedom and control to deliver cutting-edge content, interactive experiences, and immersive virtual worlds." 

#### Ue4Duino Plugin
"Use this plugin to communicate with Arduino or other COM port devices on Windows."

#### Arduino Libraries
The Arduino environment can be extended through the use of libraries. (e.g neopixel library etc.)

### Hardware
#### Programmable Circuit Boards
Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs and turn them into outputs. Arduino senses the environment by receiving inputs from many sensors and affects its surroundings by controlling lights, motors, and other actuators.

#### Addressable Lights:
I plan to use addressable lighting (probably strips) to represent the world colours in the installation. I have been looking into using Adafruit Neopixels. 

## Development
* The next step from the first prototype was to get the second LED strip to work and respond to the code.
* Once I got them both working, it was time to get them working and responding to the code at the same time. 
* This worked (as shown below) but I then ran into a new unexpected problem, where the lights would react to the code if the other light was in the process of changing or being in a delay phase. 

![dev gif](https://https://github.com/catemunt/research-project-ACT/blob/main/img/developmentGIF.gif "TEST")

* This issue is with the delay function, where the serial is seen as busy when carrying out the delay. 
* I did some research and found that this is a common problem with Arduino, and can be solved with the time function millis().
* I rewrote my code using the milis() function as a timekeeper, allowing for both strips to be carrying out different functions at the same time.


## References
#### Unreal to Arduino interaction examples:
* https://www.youtube.com/watch?v=hhVILt6duXE
* https://www.youtube.com/watch?v=Q2P_0vAYFTs
* https://www.youtube.com/watch?v=rzh9wh_SfDs
* https://www.youtube.com/watch?v=ogpD2RVNMLs&ab_channel=AdamMartin
* https://www.youtube.com/watch?v=XvfG56fa_Lk&ab_channel=ShaunFoster
* https://www.youtube.com/watch?v=pInYuj7VPQY&ab_channel=posoco2000

#### Unreal to Arduino Documentation:
* https://github.com/RVillani/UE4Duino
* https://forums.unrealengine.com/t/ue4duino-arduino-to-ue4-plugin-release/28963
* https://www.reddit.com/r/unrealengine/comments/3ceujs/how_to_use_arduino_in_ue4/v

#### Arduino/microcontroller Documentation:
* https://create.arduino.cc/projecthub/glowascii/neopixel-leds-arduino-basics-126d1a
* https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
