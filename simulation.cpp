#include "simulation.h"


Coordinate::Coordinate() {
    init(0, 0, 0);
}

Coordinate::Coordinate(double x, double y) {
    init(x, y, 0);
}

Coordinate::Coordinate(double x, double y, double theta) {
    init(x, y, theta);
}

void Coordinate::init(double x, double y, double theta) {
    this->x = x; 
    this->y = y;
    this->theta = theta;
}

DFRTankSimulation::DFRTankSimulation() {
  DFRTankSimulation("TeamNoName");
}

DFRTankSimulation::DFRTankSimulation(String name) {
  _left_motor_pwm = 0;
  _right_motor_pwm = 0;
  this->teamName = String(name);
  Serial.print(name);
};

void DFRTankSimulation::init(){ 
  //think about moving this line to the constructor and removing the method
  Serial.begin(9600);
};

void DFRTankSimulation::setLeftMotorPWM(int pwm) {
  
  Serial.print("#l");
  Serial.print(pwm);
  Serial.println("*");
  Serial.flush();

  _left_motor_pwm = pwm;
};

void DFRTankSimulation::setRightMotorPWM(int pwm) {
  
  Serial.print("#r");
  Serial.print(pwm);
  Serial.println("*#");
  Serial.flush();

  _right_motor_pwm = pwm;
};

void DFRTankSimulation::turnOffMotors() {
  
  Serial.print("#r");
  Serial.print(0);
  Serial.println("*");

  Serial.print("#l");
  Serial.print(0);
  Serial.println("*");

  Serial.flush();

  _right_motor_pwm = 0;
  _left_motor_pwm = 0;
};

bool DFRTankSimulation::retrieveDestination() {
  Serial.println("#destination*");
  Serial.flush();

  unsigned long start = millis();
    int state = 0;
    
    while((millis() - start) < 600) {
        if (Serial.available()) {
            switch(state) {
                case 0:
                    destination.x = Serial.parseFloat();
                    state++;
                    break;
                case 1:
                    destination.y = Serial.parseFloat();
                    state++;
                    break;
                case 2:
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
        }
    }
    
    return false;

}

bool DFRTankSimulation::updateLocation() {
  //add Serial.flush(); here?
  Serial.println("#destination*");
  Serial.flush();

  unsigned long start = millis();
    int state = 0;
    
    while((millis() - start) < 600) {
        if(Serial.available()) {
            switch(state) {
                case 0:
                    location.x = Serial.parseFloat();
                    state++;
                    break;
                case 1:
                    location.y = Serial.parseFloat();
                    state++;
                    break;
                case 2:
                    location.theta = Serial.parseFloat();
                    return true;
                    break;
                default:
                    return false;
                    break;
            }
        }
    }
    return false;
}

float DFRTankSimulation::readUltrasonicSensor(int sensorIndex) {
  Serial.print("#distance");
  Serial.print(sensorIndex);
  Serial.print("*");
  Serial.flush();

  unsigned long start = millis();
    
    while((millis() - start) < 600) {
        if(Serial.available()) {
            return Serial.parseFloat();
        }
    }
    return 0;
}


void DFRTankSimulation::print(const char *msg) {
    Serial.print(msg);
    Serial.flush();
}

void DFRTankSimulation::print(int msg) {
    Serial.print(msg);
    Serial.flush();
}

void DFRTankSimulation::print(double msg) {
    Serial.print(msg);
    Serial.flush();
}

// MARK: println
void DFRTankSimulation::println(const char *msg) {
    Serial.println(msg);
    Serial.flush();
}

void DFRTankSimulation::println(int msg) {
    Serial.println(msg);
    Serial.flush();
}

void DFRTankSimulation::println(double msg) {
    Serial.println(msg);
    Serial.flush();
}
