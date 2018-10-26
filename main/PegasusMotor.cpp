#include "PegasusMotor.h"

PegasusMotor::PegasusMotor() {

}

PegasusMotor::PegasusMotor(int pin) {
   esc.attach(pin);
}

void PegasusMotor::setSpeed(int speed) {
   if (speed >= 0) {
      int value = map(speed + preference.increaseValue, 0, 100, preference.minAngleESC, preference.maxAngleESC);
      if (value >= preference.increaseValue + 5) {
         esc.write(value);
      } else {
         esc.write(preference.increaseValue + 5);
      }
   }
}
