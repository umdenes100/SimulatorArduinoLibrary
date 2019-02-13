#ifndef Enes100Simulation_h
#define Enes100Simulation_h

#include "TankSimulation.h"
#include "SimulatorClient.h"

#define abs(x) ((x)>0?(x):-(x))

#define BASE        0
#define BONUS       1

#define BLACK_BOX   0
#define CHEMICAL    1
#define DEBRIS      2
#define FIRE        3
#define WATER       4

#define FRESH       0
#define POLLUTED    1
#define SALT        2

#define COPPER      0
#define STEEL       1

SimulatorClient Enes100Simulation;
TankSim TankSimulation;

#endif /* Enes100Simulation_h */