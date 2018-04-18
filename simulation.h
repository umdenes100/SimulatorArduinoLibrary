#ifndef DFRTank_SIMULATION_H_
#define DFRTank_SIMULATION_H_   //should this be kept the same as DFR_Tank to avoid interference?

#include <Arduino.h>



class Coordinate {
public:
    Coordinate();
    Coordinate(double x, double y);
    Coordinate(double x, double y, double theta);
    double x;
    double y;
    double theta;
private:
    void init(double x, double y, double theta);
};



class DFRTankSimulation {
  private:
    int _right_motor_pwm, _left_motor_pwm;
    float ultrasonic_reading;
    String teamName;

  public:

    DFRTankSimulation();
    DFRTankSimulation(String name);
    void init();        //should this be kept for consistency between simulation and dfr_tank libraries?
    void turnOffMotors();
  
    void setRightMotorPWM(int pwm);
    void setLeftMotorPWM(int pwm);

    int getLeftMotorPWM(){
      return _left_motor_pwm;
    };
    int getRightMotorPWM(){
      return _right_motor_pwm;
    };

    bool retrieveDestination();
    bool updateLocation();

    Coordinate destination;
    Coordinate location;

    float readUltrasonicSensor(int sensorIndex);


    void print(const char *msg);

    void print(int msg);

    void print(double msg);

    // MARK: println
    void println(const char *msg);

    void println(int msg);

    void println(double msg);

};

#endif
