#include <Arduino.h>
#include "PegasusFlightController.h"

PegasusFlightController::PegasusFlightController() {
   motor0 = PegasusMotor(9);
   motor1 = PegasusMotor(10);
   motor2 = PegasusMotor(11);
   motor3 = PegasusMotor(12);
}

void PegasusFlightController::setPreferencesForMotor(int motor, PegasusMotorPreferences preference) {

   switch (motor) {
      case 0:
         motor0.preference = preference;
         break;
      case 1:
         motor1.preference = preference;
         break;
      case 2:
         motor2.preference = preference;
         break;
      case 3:
         motor3.preference = preference;
         break;
      default:
         break;
   }
}

void PegasusFlightController::update(int throttle, int pitch, int roll, int yaw) {

   motor0.setSpeed(throttle);
   motor1.setSpeed(throttle);
   motor2.setSpeed(throttle);
   motor3.setSpeed(throttle);

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

void PegasusFlightController::printValues() {
   Serial.print("T: ");
   Serial.println(throttle);
   Serial.print(" P: ");
   Serial.print(pitch);
   Serial.print(" R: ");
   Serial.print(roll);
   Serial.print(" Y: ");
   Serial.println(yaw);
}
