#include "Enes100Simulation.h"

Enes100Simulation::Enes100Simulation() {

}

bool Enes100Simulation::retrieveDestination() {
    Serial.print("#destination*");
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

bool Enes100Simulation::updateLocation() {
  Serial.print("#location*");
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

float Enes100Simulation::readDistanceSensor(int sensorIndex) {
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


void Enes100Simulation::print(const char *msg) {
    Serial.print(msg);
    Serial.flush();
}

void Enes100Simulation::print(int msg) {
    Serial.print(msg);
    Serial.flush();
}

void Enes100Simulation::print(double msg) {
    Serial.print(msg);
    Serial.flush();
}

// MARK: println
void Enes100Simulation::println(const char *msg) {
    Serial.println(msg);
    Serial.flush();
}

void Enes100Simulation::println(int msg) {
    Serial.println(msg);
    Serial.flush();
}

void Enes100Simulation::println(double msg) {
    Serial.println(msg);
    Serial.flush();
}
