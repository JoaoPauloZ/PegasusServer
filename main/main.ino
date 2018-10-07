#include "Arduino.h"
#include "PegasusServer.h"

//https://www.arduinoecia.com.br/2015/07/como-ligar-motor-brushless-arduino.html
PegasusServer server;

void setup() {
   Serial.begin(9600);
   Serial.println("Sistema iniciado");
 
   server = PegasusServer();
   server.init();
 
   // while server is not conected wait
   while (!server.isConnected) {}
}

void loop() {

   server.listen();

}
