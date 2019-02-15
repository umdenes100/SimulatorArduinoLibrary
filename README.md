# SimulatorArduinoLibrary

This document describes how to use the Simulator Arduino library. Complete documentation on how to install and use the Simulator, is available [here](https://github.com/umdenes100/VisionSystemSimulatorInstallers/blob/master/README.md). To see an example sketch using the library, go to **File > Examples > SimulatorArduinoLibrary > navigation_example**

## Table of Contents
- [Download and Installation](#download-and-installation)
- [Purpose](#purpose)
- [Definitions](#definitions)
- [TankSimulation Object](#tanksimulation-object)
- [Enes100Simulation Object](#enes100simulation-object)

## Download and Installation

To use this library, download the contents from [this Github repository](https://github.com/umdenes100/SimulatorArduinoLibrary) by going to the green **Clone or Download** menu and clicking **Download ZIP**. (There is no need to unzip the file.) Open the Arduino IDE and install the library by going to **Sketch > Include Library > Add .ZIP Library** and selecting the downloaded file. You must have Arduino IDE version 1.5.0 or above. The most current version of Arduino IDE can be downloaded from the [Arduino website](https://www.arduino.cc/en/Main/Software).

## Purpose
The Simulator library serves as a bridge between the arduino and the simulator program. It is designed to mimic the API of the enes and dfr tank libraries to create as simple a transition as possible from the simulator to a physical system. The API is described below.

## Definitions

### TankSimulation Object

The functions associated with the TankSimulation object control the movement of the OSV. 

`bool begin()`

This function initializes the tank object.


`void turnOffMotors()`

This function simply stops the OSV by setting both motor PWM's to zero.


`void setRightMotorPWM()`

This function sets the PWM of the tank's right motor. It accepts one argument (an integer), which should be in the range [-255, 255]


`void setLeftMotorPWM()`

This function sets the PWM of the tank's left motor. It accepts one argument (an integer), which should be in the range [-255, 255]


### Enes100Simulation Object

The functions associated with the Enes100Simulation object provide information about the OSV's location, destination, and distance sensor readings. They also allow print messages to be sent to the console for debugging purposes. 


`bool begin()`

This function retrieves the destination for the current run from the simulator, stores the destination in the destination variable, and returns true or false depending on the success of the call. This function should be encapsulated in a while loop to ensure that the OSV has retrieved the destination before begining the run.


`bool updateLocation()`

This function communicates with the simulator to retrieve the current OSV location and updates the location variable in the object. It returns true or false depending on the success of the call.


`float readDistanceSensor(int sensorIndex)`

This function reads the distance sensor on the simulator OSV and returns the distance as a float. The sensor index is a number from 0-11 as defined in the simulator 'Edit OSV' form.


`void print(msg), void println(msg)`

These functions are print messages to the console. These functions may be helping in debugging your code. 