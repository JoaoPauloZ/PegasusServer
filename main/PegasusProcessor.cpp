#include <Arduino.h>
#include "PegasusProcessor.h"

PegasusProcessor::PegasusProcessor() {

}

//"\(command);\(throttle);\(pitch);\(roll);\(yaw);"
void PegasusProcessor::process(String buffer) {

   if (buffer.length() > 0) {
      action = buffer[0];
   }

   if (action == 'C') {
      fillCommands(buffer);
   }

}

void PegasusProcessor::fillCommands(String buffer) {
   int count = 0;
   char c = ' ';
   String number_str = "";

   for (int i = 1; i < buffer.length(); i++) {
      c = buffer.charAt(i);
      // if finished a number
      if (c == ';') {
         if (count == 0) {
             throttle = number_str.toInt();
             number_str = "";
             count++;
          } else if (count == 1) {
             pitch = number_str.toInt();
             number_str = "";
             count++;
          } else if (count == 2) {
             roll = number_str.toInt();
             number_str = "";
             count++;
          } else if (count == 3) {
             yaw = number_str.toInt();
             number_str = "";
             count = 0;
          }
      // add str to number
      } else {
         number_str += c;
      }
   }
   //printf("T=%d P=%d R=%d Y=%d\n", throttle, pitch, roll, yaw);
}
