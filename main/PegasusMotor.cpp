#include "PegasusMotor.h"

PegasusMotor::PegasusMotor() {

}

PegasusMotor::PegasusMotor(int pin) {
   esc.attach(pin);
}

void PegasusMotor::setSpeed(int speed) {
   int value = map(speed + preference.increaseValue, 0, 100, preference.minAngleESC, preference.maxAngleESC);
   esc.write(value);
}
