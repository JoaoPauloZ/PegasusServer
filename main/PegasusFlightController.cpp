#include <Arduino.h>
#include "PegasusFlightController.h"

PegasusFlightController::PegasusFlightController() {
   motor0 = PegasusMotor(11);
}

void PegasusFlightController::update() {

   if (action == 'S') {
      toggleEngines();
   } else if (action == 'T') {
      takeOff();
   } else if (action == 'L') {
      landing();
   }

   motor0.setSpeed(throttle);

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

