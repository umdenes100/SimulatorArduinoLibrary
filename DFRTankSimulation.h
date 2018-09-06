#ifndef DFRTankSimulation_h
#define DFRTankSimulation_h

#include <Arduino.h>

class DFRTankSimulation {

public:

    DFRTankSimulation();
    void init();

    void turnOffMotors();
    void setRightMotorPWM(int pwm);
    void setLeftMotorPWM(int pwm);

};

#endif