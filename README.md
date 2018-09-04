# SimulatorArduinoLibrary

### Purpose ###
The Simulator library serves as a bridge between the arduino and the simulator program. It is designed to mimic the API of the enes and dfr tank libraries to create as simple a transition as possible from the simulator to a physical system. The API is described below. more information about the code can be found on the github repo linked above.

### Function Definitions ###
`void turnOffMotors()`

This function simply stops the OSV. It can and should be used when the OSV arrives at the destination.

`void setRightMotorPWM(), void setLeftMotorPWM()`

These functions set the PWM of the right and left motors. They can be used to manuver the OSV as needed.

`bool retrieveDestination()`

This function retrieves the destination for the current run from the simulator, stores the destination in the destination variable, and returns true or false depending on the success of the call. This function should be encapsulated in a while loop to ensure that the OSV has retrieved the destination before begining the run.

`bool updateLocation()`

This function communicates with the simulator to retrieve the current OSV location and updates the location variable in the object. It returns true or false depending on the success of the call.

`float readDistanceSensor(int sensorIndex)`

This function reads the distance sensor on the simulator OSV and returns the distance as a float. The sensor index is a number from 0-11 as defined in the simulator 'Edit OSV' form.

`void print(msg), void println(msg)`

These functions are provided to mimic the enes library but are not nessesary for the simulator. When switching to a physical system, if regular print statements are used, you should switch them to enes.print statements.