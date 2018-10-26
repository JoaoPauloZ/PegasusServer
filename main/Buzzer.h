#ifndef PEGASUS_BUZZER_H
#define PEGASUS_BUZZER_H

class Buzzer {

public:
   static const int pin = 12;

   static void beep(int numberOfTimes, int delayms);
};

#endif
