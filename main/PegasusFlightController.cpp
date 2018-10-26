#include <Arduino.h>
#include "PegasusFlightController.h"

PegasusFlightController::PegasusFlightController() {
   motor0 = PegasusMotor(11);
   motor1 = PegasusMotor(10);
   motor2 = PegasusMotor(9);
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

   int speedMin = 5;
   int speed0 = throttle;
   int speed1 = throttle;
   int speed2 = throttle;
   int speed3 = throttle;
   
   if (throttle >= 1 && throttle <= 100) {
      // [Pitch]
      // - Move forward: motor 2 and 3 speed up, motor 0 and 1 speed down (pitch > 0)
      if (pitch > 0) {
         speed2 += pitch;
         speed3 += pitch;
         speed0 -= max(pitch, speedMin);
         speed1 -= max(pitch, speedMin);
      }

      // - Move backward: motor 2 and 3 speed down, motor 0 and 1 speed up (pitch < 0)
      if (pitch < 0) {
         speed2 -= max(pitch, speedMin);
         speed3 -= max(pitch, speedMin);
         speed0 += pitch;
         speed1 += pitch;
      }

      // [Roll]
      // - Turn right: motor 0 and 3 speed up, motor 1 and 2 speed down (roll > 0)
      if (roll > 0) {
         speed0 += roll;
         speed3 += roll;
         speed1 -= max(roll, speedMin);
         speed2 -= max(roll, speedMin);
      }
      // - Turn left: motor 0 and 3 speed down, motor 1 and 2 speed up (roll < 0)
      if (roll < 0) {
         speed0 -= max(roll, speedMin);
         speed3 -= max(roll, speedMin);
         speed1 += roll;
         speed2 += roll;
      }

      // [Yaw]
      // - Rotate clockwise: motor 0 and 2 speed up, motor 1 and 3 speed down (yaw > 0)
      if (yaw > 0) {
         speed0 += yaw;
         speed2 += yaw;
         speed1 -= max(yaw, speedMin);
         speed3 -= max(yaw, speedMin);
      }

      // - Rotate counterclockwise: motor 0 and 2 speed down, motor 1 and 3 speed up (yaw < 0)
      if (yaw < 0) {
         speed0 -= max(yaw, speedMin);
         speed2 -= max(yaw, speedMin);
         speed1 += yaw;
         speed3 += yaw;
      }
   }

   motor0.setSpeed(speed0);
   motor1.setSpeed(speed1);
   motor2.setSpeed(speed2);
   motor3.setSpeed(speed3);

}

void PegasusFlightController::toggleEngines() {
   if (enginesOn) {
      stopEngines();
   } else {
      startEngines();
   }
}

void PegasusFlightController::startEngines() {
   // motor0.setSpeed(5);
   // motor1.setSpeed(5);
   // motor2.setSpeed(5);
   // motor3.setSpeed(5);
   // delay(500);
   // motor0.setSpeed(0);
   // motor1.setSpeed(0);
   // motor2.setSpeed(0);
   // motor3.setSpeed(0);
}

void PegasusFlightController::stopEngines() {
   motor0.setSpeed(0);
   motor1.setSpeed(0);
   motor2.setSpeed(0);
   motor3.setSpeed(0);
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
