#ifndef PEGASUS_FLIGHT_CONTROLLER_H
#define PEGASUS_FLIGHT_CONTROLLER_H
#include "PegasusMotor.h"

class PegasusFlightController {

public:
   int throttle = 0;
   int pitch = 0;
   int roll = 0;
   int yaw = 0;
   char action = '0';

   PegasusFlightController();

   void update();
   void toggleEngines();
   void takeOff();
   void landing();

private:
   bool enginesOn = false;

   PegasusMotor motor0; // Font left
   PegasusMotor motor1; // Front right
   PegasusMotor motor2; // Back right
   PegasusMotor motor3; // Back left

   void startEngines();
   void stopEngines();

   // função para normalizar o valor do throttle percent to absolute

};

#endif