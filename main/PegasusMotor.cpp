#include "PegasusMotor.h"

PegasusMotor::PegasusMotor() {
   
}

PegasusMotor::PegasusMotor(int pin) {
   esc.attach(pin);
}

void PegasusMotor::setSpeed(int speed) {
   int value = map(speed, 0, 100, 60, 179);
   esc.write(value);
   Serial.print("Motor speed: ");
   Serial.println(value);
}