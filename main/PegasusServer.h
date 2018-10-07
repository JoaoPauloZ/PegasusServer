#ifndef PEGASUS_SERVER_H
#define PEGASUS_SERVER_H

#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "PegasusProcessor.h"

class PegasusServer {

public:
   bool isConnected;

   PegasusServer();
   void init();
   void listen();

private:
   WiFiUDP serverUDP;
   PegasusProcessor processor;

   int status = WL_IDLE_STATUS;
   unsigned int localPort = 80;
   char packetBuffer[255];

   void printWifiStatus();
};

#endif
