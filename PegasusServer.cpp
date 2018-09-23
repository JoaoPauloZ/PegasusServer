#include <Arduino.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "PegasusServer.h"

#include "PegasusProcessor.h"

char ssid[] = "T.A.R.D.I.S.";
char pass[] = "p47p51zero0";

int status = WL_IDLE_STATUS;
WiFiUDP serverUDP;
unsigned int localPort = 80;
char packetBuffer[255];

void printWifiStatus();

void serverInit() {

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    printf("Please upgrade the firmware\n");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    printf("Attempting to connect to Network named: %s\n", ssid);
    // Connect to WPA/WPA2 network.
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }

  // connected, so print out the status
  printWifiStatus();
  // if you get a connection, report back via serial:
  serverUDP.begin(localPort);
}

bool serverConnected() {
  return status == WL_CONNECTED;
}

void serverRead() {
  // if there's data available, read a packet
  if (serverUDP.parsePacket()) {
    // read the packet into packetBufffer
    int len = serverUDP.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }

    processorProcess(packetBuffer);
    //printf("%s", packetBuffer);
    
  }
}

void printWifiStatus() {
  printf("\n####### CONECTED #######\n");
  // print the SSID of the network:
  printf("SSID: %s\n", WiFi.SSID());  
  // print WiFi IP address:

  IPAddress ipno = WiFi.localIP();
  char ipno2[26];
  sprintf(ipno2, "%d.%d.%d.%d", ipno[0], ipno[1], ipno[2], ipno[3]);
  printf("IP Address: %s\n", ipno2);
}
