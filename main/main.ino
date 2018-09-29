#include "Arduino.h"
#include "PegasusServer.h"

PegasusServer server;

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema iniciado");
  // while server is not conected wait
  //server = PegasusServer();
  //while (!server.isConnected) {}
  Serial.println("++ conected ++");
}

void loop() {
	//server.listen();
}
