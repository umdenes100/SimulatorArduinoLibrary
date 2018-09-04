#include <simulation.h>
#define abs(x) ((x)>0?(x):-(x))
#define MaxPWM 255
DFRTankSimulation tank;

void setup() {

  tank.init();

  tank.println("Starting Navigation");

  while (!tank.retrieveDestination());

  while (!tank.updateLocation());

}

void loop() {

  while (abs(tank.location.theta) > 0.05) {

    tank.setLeftMotorPWM(MaxPWM);
    tank.setRightMotorPWM(- MaxPWM);

    while (!tank.updateLocation());
    
  }

  tank.setLeftMotorPWM(MaxPWM);
  tank.setRightMotorPWM(MaxPWM);

  while (tank.readDistanceSensor(1) > 0.2) ;

  tank.turnOffMotors();
  tank.println("Found Obstacle");

  while(1);

}
