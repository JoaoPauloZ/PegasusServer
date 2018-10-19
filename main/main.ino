#include "Arduino.h"
#include "Buzzer.h"
#include "PegasusServer.h"

//https://www.arduinoecia.com.br/2015/07/como-ligar-motor-brushless-arduino.html
PegasusServer server;

void setup() {
   Serial.begin(9600);
   Serial.println("Sistema iniciado");

   Buzzer::buzz(2, 50);

   server = PegasusServer();
   server.init();
 
   // while server is not conected wait
   while (!server.isConnected) {}
   
   Buzzer::buzz(3, 50);
}

void loop() {

   server.listen();

}
