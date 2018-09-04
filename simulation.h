#ifndef DFRTank_SIMULATION_H_
#define DFRTank_SIMULATION_H_

#include <Arduino.h>
#include "Coordinate.h"


class DFRTankSimulation {
  private:
    int _right_motor_pwm, _left_motor_pwm;
    float ultrasonic_reading;

  public:

    Coordinate destination;
    Coordinate location;

    DFRTankSimulation();
    void init();

    void turnOffMotors();
    void setRightMotorPWM(int pwm);
    void setLeftMotorPWM(int pwm);

    bool retrieveDestination();
    bool updateLocation();
    float readDistanceSensor(int sensorIndex);


    void print(const char *msg);
    void print(int msg);
    void print(double msg);

    void println(const char *msg);
    void println(int msg);
    void println(double msg);

};

#endif
