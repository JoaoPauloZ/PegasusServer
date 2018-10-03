#include "Arduino.h"
#include "PegasusServer.h"

//https://www.arduinoecia.com.br/2015/07/como-ligar-motor-brushless-arduino.html
PegasusServer server;
String buffer = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Sistema iniciado");
  // while server is not conected wait
  server = PegasusServer();
  server.init();
  while (!server.isConnected) {}
}

void loop() {
   buffer = server.listen();
}
