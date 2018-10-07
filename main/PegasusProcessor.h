#ifndef PEGASUS_PROCESSOR_H
#define PEGASUS_PROCESSOR_H

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
   char action;

   PegasusProcessor();
   void process(String buffer);

private:
   PegasusFlightController flightController; 
   void fillCommands(String buffer);
};

#endif