#ifndef PEGASUS_PROCESSOR_H
#define PEGASUS_PROCESSOR_H

class PegasusProcessor {

public:
   float throttle;
   float pitch;
   float roll;
   float yaw;

   // C —> Commands
   // S —> Start/Stop
   // T —> Take off
   // L —> Landing
   char action;

   PegasusProcessor();
   void process(String);

private:
   void fillCommands(String buffer);
};

#endif