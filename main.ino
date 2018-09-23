#include <Arduino.h>
#include "PegasusServer.h"

void setup() {
  serverInit();
  // while server is not conected wait
  while (!serverConnected()) {}
}

void loop() {
  serverRead();
}