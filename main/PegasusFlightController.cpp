#include <Arduino.h>
#include "PegasusFlightController.h"

PegasusFlightController::PegasusFlightController() {
   motor0 = PegasusMotor(11);
}

void PegasusFlightController::update(int throttle, int pitch, int roll, int yaw) {

   Serial.print("T: ");
   Serial.print(throttle);
   Serial.print(" P: ");
   Serial.print(pitch);
   Serial.print(" R: ");
   Serial.print(roll);
   Serial.print(" Y: ");
   Serial.println(yaw);

   //motor0.setSpeed(throttle);

}

void PegasusFlightController::toggleEngines() {
   if (enginesOn) {
      stopEngines();
   } else {
      startEngines();
   }
}

void PegasusFlightController::startEngines() {

}

void PegasusFlightController::stopEngines() {

}

void PegasusFlightController::takeOff() {

}

void PegasusFlightController::landing() {

}

