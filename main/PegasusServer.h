#ifndef PEGASUS_SERVER_H
#define PEGASUS_SERVER_H

//#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

class PegasusServer {

public:
   bool isConnected;

   PegasusServer();
   void listen();

private:
//   char ssid[] = {'T','.','A','.','R','.','D','.','I','.','S','.'};
//   char pass[] = {'p','4','7','p','5','1','z','e','r','o','0'};
  
   WiFiUDP serverUDP;
   int status = WL_IDLE_STATUS;
   unsigned int localPort = 80;
   char packetBuffer[255];

   void printWifiStatus();
};

#endif
