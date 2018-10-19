#ifndef PEGASUS_BUZZER_H
#define PEGASUS_BUZZER_H

class Buzzer {

public:
   static const int pin = 8;

   static void buzz(int numberOfTimes, int timer);
};

#endif
