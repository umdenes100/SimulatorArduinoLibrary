#ifndef TankSimulation_h
#define TankSimulation_h

#include <Arduino.h>

class TankSimulation {

public:

    TankSimulation();
    void begin();

    void turnOffMotors();
    void setRightMotorPWM(int pwm);
    void setLeftMotorPWM(int pwm);

};

#endif