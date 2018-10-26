#include <Arduino.h>
#include "Buzzer.h"

void Buzzer::beep(int numberOfTimes, int delayms) {

  pinMode(pin, OUTPUT);

   for (int i = 0; i <= numberOfTimes; i++) {
      digitalWrite(pin, HIGH);
      delay(delayms);
      digitalWrite(pin, LOW);
      delay(delayms); 
   }
}
