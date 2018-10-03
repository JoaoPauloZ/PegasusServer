#ifndef PEGASUS_FLIGHT_CONTROLLER_H
#define PEGASUS_FLIGHT_CONTROLLER_H

class PegasusFlightController {

public:
   float throttle;
   float pitch;
   float roll;
   float yaw;

   PegasusFlightController();

   void startEngines();
   void stopEngines();
   void takeOff();
   void landing();

private:
   // função para normalizar o valor do throttle percent to absolute
};

#endif