#include "PegasusMotor.h"

PegasusMotor::PegasusMotor() {

}

PegasusMotor::PegasusMotor(int pin) {
   esc.attach(pin);
}

void PegasusMotor::setSpeed(int speed) {
   if (speed >= 0) {
      if (speed > 25) {
         speed += preference.increaseValue;
      }
      int value = map(speed, 0, 100, preference.minAngleESC, preference.maxAngleESC);
      esc.write(value);
   }
}
