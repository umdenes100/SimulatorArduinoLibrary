#include "TankSimulation.h"

TankSimulation::TankSimulation() {

}

void TankSimulation::begin(){ 
  Serial.begin(9600);
}

void TankSimulation::setLeftMotorPWM(int pwm) {
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

void TankSimulation::setRightMotorPWM(int pwm) {
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

void TankSimulation::turnOffMotors() {

    Serial.print("#r");
    Serial.print(0);
    Serial.print("*");

    Serial.print("#l");
    Serial.print(0);
    Serial.print("*");

    Serial.flush();
}