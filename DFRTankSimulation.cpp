#include "DFRTankSimulation.h"

DFRTankSimulation::DFRTankSimulation() {

}

void DFRTankSimulation::init(){ 
  Serial.begin(9600);
}

void DFRTankSimulation::setLeftMotorPWM(int pwm) {
    if (pwm > 255) {
        pwm = 255;
    } else if (pwm < -255) {
        pwm = -255;
    }

    Serial.print("#l");
    Serial.print(pwm);
    Serial.print("*");
    Serial.flush();

}

void DFRTankSimulation::setRightMotorPWM(int pwm) {
    if (pwm > 255) {
        pwm = 255;
    } else if (pwm < -255) {
      pwm = -255;
    }

    Serial.print("#r");
    Serial.print(pwm);
    Serial.print("*");
    Serial.flush();
  
}

void DFRTankSimulation::turnOffMotors() {

    Serial.print("#r");
    Serial.print(0);
    Serial.print("*");

    Serial.print("#l");
    Serial.print(0);
    Serial.print("*");

    Serial.flush();
}