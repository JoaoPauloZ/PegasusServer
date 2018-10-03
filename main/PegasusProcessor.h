#ifndef PEGASUS_PROCESSOR_H
#define PEGASUS_PROCESSOR_H

class PegasusProcessor {

public:
   float throttle;
   float pitch;
   float roll;
   float yaw;

   PegasusProcessor();
   void process(String);

private:
   char packetBuffer[255];
   void printWifiStatus();
};

#endif