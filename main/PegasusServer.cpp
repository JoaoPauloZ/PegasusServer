#include "PegasusServer.h"

PegasusServer::PegasusServer() {

  	String fv = WiFi.firmwareVersion();
  	if (fv != "1.1.0") {
      Serial.println("Please upgrade the firmware");
  	}

}

void PegasusServer::init() {
   // attempt to connect to Wifi network:
   while (status != WL_CONNECTED) {
      char ssid[] = "T.A.R.D.I.S.";
      char pass[] = "p47p51zero0";
      Serial.print("Attempting to connect to Network named: ");
      Serial.println(ssid);
      // Connect to WPA/WPA2 network.
      status = WiFi.begin(ssid, pass);
      // wait 10 seconds for connection:
      delay(10000);
   }

   isConnected = true;
   // connected, so print out the status
   printWifiStatus();
   // if you get a connection, report back via serial:
   serverUDP.begin(localPort);
}

String PegasusServer::listen() {
   // if there's data available, read a packet
   int packetSize = serverUDP.parsePacket();
   if (packetSize) {
      // read the packet into packetBufffer
      int len = serverUDP.read(packetBuffer, 255);
      if (len > 0) {
         packetBuffer[len] = 0;
      }
      Serial.println(packetBuffer);
      //String buffer_str(packetBuffer);
      return "buffer_str";
   }
}

void PegasusServer::printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
