#ifndef PEGASUS_FLIGHT_CONTROLLER_H
#define PEGASUS_FLIGHT_CONTROLLER_H
#include "PegasusMotor.h"
#include "PegasusMotorPreferences.h"

class PegasusFlightController {

public:
   int throttle = 0;
   int pitch = 0;
   int roll = 0;
   int yaw = 0;
   char action = '0';

   PegasusFlightController();

   void update(int throttle, int pitch, int roll, int yaw);
   void setPreferencesForMotor(int motor, PegasusMotorPreferences preference);
   void toggleEngines();

private:
   bool enginesOn = false;

   PegasusMotor motor0; // Front left
   PegasusMotor motor1; // Front right
   PegasusMotor motor2; // Back right
   PegasusMotor motor3; // Back left

   void startEngines();
   void stopEngines();
   void printValues();

};

#endif