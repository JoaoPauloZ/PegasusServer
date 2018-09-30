#include "Arduino.h"
#include "PegasusServer.h"

PegasusServer server;

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema iniciado");
  // while server is not conected wait
  server = PegasusServer();
  server.init();
  while (!server.isConnected) {}
}

void loop() {
	server.listen();
}
