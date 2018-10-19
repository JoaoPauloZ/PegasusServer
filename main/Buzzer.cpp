#include <Arduino.h>
#include "Buzzer.h"

void Buzzer::buzz(int numberOfTimes, int timer) {
   int frequence = 2500;

   for (int i = 0; i <= numberOfTimes; i++) {
      tone(pin,frequence);   
      delay(timer);

      noTone(pin);
      delay(timer);  
   }
}