# SimulatorArduinoLibrary

## Purpose ##
The Simulator library serves as a bridge between the arduino and the simulator program. It is designed to mimic the API of the enes and dfr tank libraries to create as simple a transition as possible from the simulator to a physical system. The API is described below. more information about the code can be found on the github repo linked above.

## Definitions ##

### Coordinate Object ###
The Simulation and ENES100 libraries also includes a Coordinate class that holds an x, y, and theta. Students may use Coordinates in their code as desired. The destination and location members of Enes100 are Coordinate objects. The x, y, and theta are accessed in the same way as in destination and location, i.e. coordinate.x, coordinate.y, and coordinate.theta. For convenience, we have included 3 constructors for the Coordinate object.

```
Coordinate coordinate1(); // Represents the point (0, 0, 0)
Coordinate coordinate2(1.2, 0.7); // Represents the point (1.2, 0.7, 0)
Coordinate coordinate3(1.2, 0.7, 1.1); // Represents the point (1.2, 0.7, 1.1)
```

For the Black Box mission, the base objective must be transmitted using a Coordinate object.

```
Coordinate blackBox(3.2, 1.6);
baseObjective(blackBox);
```

### TankSimulation Object ###

The functions associated with the TankSimulation object control the movement of the OSV. 


`void turnOffMotors()`

This function simply stops the OSV by setting both motor PWM's to zero.

`void setRightMotorPWM()`

This function sets the PWM of the tank's right motor. It accepts one argument (an integer), which should be in the range [-255, 255]

`void setLeftMotorPWM()`

This function sets the PWM of the tank's left motor. It accepts one argument (an integer), which should be in the range [-255, 255]


### Enes100Simulation Object ###

The functions associated with the Enes100Simulation object provide information about the OSV's location, destination, and distance sensor readings. They also allow print messages to be sent to the console for debugging purposes. 


`bool begin()`

This function retrieves the destination for the current run from the simulator, stores the destination in the destination variable, and returns true or false depending on the success of the call. This function should be encapsulated in a while loop to ensure that the OSV has retrieved the destination before begining the run.


`bool updateLocation()`

This function communicates with the simulator to retrieve the current OSV location and updates the location variable in the object. It returns true or false depending on the success of the call.


`float readDistanceSensor(int sensorIndex)`

This function reads the distance sensor on the simulator OSV and returns the distance as a float. The sensor index is a number from 0-11 as defined in the simulator 'Edit OSV' form.


`void print(msg), void println(msg)`

These functions are print messages to the console. These functions may be helping in debugging your code. 