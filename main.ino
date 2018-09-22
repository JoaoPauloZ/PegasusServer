#include <Arduino.h>

#include <SPI.h>
#include <WiFi.h>
#include <WiFiUdp.h>

char ssid[] = "T.A.R.D.I.S.";
char pass[] = "p47p51zero0";

int status = WL_IDLE_STATUS;
WiFiUDP serverUDP;
unsigned int localPort = 80;
char packetBuffer[255];

void setup() {
  Serial.begin(9600);

  String fv = WiFi.firmwareVersion();
  if (fv != "1.1.0") {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
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

void loop() {
  // if there's data available, read a packet
  if (serverUDP.parsePacket()) {
    // read the packet into packetBufffer
    int len = serverUDP.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    Serial.write(packetBuffer);
  }
}

void printWifiStatus() {
  // print the SSID of the network:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print WiFi IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}