#include "Arduino.h"
#include "PegasusServer.h"
#include "PegasusProcessor.h"
#include "FlightController.h"

//https://www.arduinoecia.com.br/2015/07/como-ligar-motor-brushless-arduino.html
PegasusServer server;
PegasusProcessor processor;
PegasusFlightController flightController;

String buffer = "";

void setup() {
   Serial.begin(9600);
   Serial.println("Sistema iniciado");
   
   server = PegasusServer();
   server.init();
   
   // while server is not conected wait
   while (!server.isConnected) {}

   processor = PegasusProcessor();
   flightController = PegasusFlightController();
}

void loop() {
   
   buffer = server.listen();
   
   processor.process(buffer);

   // chamar a função especifica do FC para cada action
   if (processor.action == 'S') {
      // verificar se está ligado ou desligado
   } else if (processor.action == 'T') {
      flightController.takeOff();
   } else if (processor.action == 'L') {
      flightController.landing();
   }


}
