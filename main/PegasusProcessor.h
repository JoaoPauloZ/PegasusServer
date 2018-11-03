#ifndef PEGASUS_PROCESSOR_H
#define PEGASUS_PROCESSOR_H

#include "PegasusMotorPreferences.h"
#include "PegasusFlightController.h"

class PegasusProcessor {

public:
   int throttle;
   int pitch;
   int roll;
   int yaw;

   // C —> Commands
   // S —> Start/Stop
   // T —> Take off
   // L —> Landing
   // U -> Update preferences
   char action;

   PegasusProcessor();
   void process(String buffer);

private:
   PegasusFlightController flightController; 
   void fillCommands(String buffer);
   void fillMotorPreferences(String buffer);
   PegasusMotorPreferences strToPref(String buffer);
};

#endif