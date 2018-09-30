#include "PegasusServer.h"

PegasusServer::PegasusServer() {

  	String fv = WiFi.firmwareVersion();
  	if (fv != "1.1.0") {
   		printf("Please upgrade the firmware\n");
  	}

}

void PegasusServer::init() {
	// attempt to connect to Wifi network:
	while (status != WL_CONNECTED) {
		printf("Attempting to connect to Network named: %s\n", "T.A.R.D.I.S.");
		// Connect to WPA/WPA2 network.
		char ssid[] = "T.A.R.D.I.S.";
		char pass[] = "p47p51zero0";
		status = WiFi.begin("T.A.R.D.I.S.", "p47p51zero0");
		// wait 10 seconds for connection:
		delay(10000);
	}

	isConnected = true;
	// connected, so print out the status
	printWifiStatus();
	// if you get a connection, report back via serial:
	serverUDP.begin(localPort);
}

void PegasusServer::listen() {
  // if there's data available, read a packet
  if (serverUDP.parsePacket()) {
    // read the packet into packetBufffer
    int len = serverUDP.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    printf("%s", packetBuffer);
  }
}

void PegasusServer::printWifiStatus() {
	printf("\n####### CONECTED #######\n");
	// print the SSID of the network:
	printf("SSID: %s\n", WiFi.SSID());  
	// print WiFi IP address:
	IPAddress ipno = WiFi.localIP();
	char ipno2[26];
	sprintf(ipno2, "%d.%d.%d.%d", ipno[0], ipno[1], ipno[2], ipno[3]);
	printf("IP Address: %s\n", ipno2);
}
