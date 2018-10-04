#include "Arduino.h"
#include "PegasusServer.h"
#include "PegasusProcessor.h"
#include "PegasusFlightController.h"

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

   flightController.throttle = processor.throttle;
   flightController.pitch = processor.pitch;
   flightController.roll = processor.roll;
   flightController.yaw = processor.yaw;
   flightController.action = processor.action;

   flightController.update();

}
