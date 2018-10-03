#include <Arduino.h>
#include "PegasusProcessor.h"

PegasusProcessor::PegasusProcessor() {

}

//"\(command);\(throttle);\(pitch);\(roll);\(yaw);"
void PegasusProcessor::process(String buffer) {

   int count = 0;
   char c = ' ';
   String number_str = "";

   for (int i = 0; i < buffer.length(); i++) {
      c = buffer.charAt(i);
      // if finished a number
      if (c == ';') {
         if (count == 0) {
         throttle = number_str.toFloat();
         number_str = "";
         count++;
      } else if (count == 1) {
         pitch = number_str.toFloat();
         number_str = "";
         count++;
      } else if (count == 2) {
         roll = number_str.toFloat();
         number_str = "";
         count++;
      } else if (count == 3) {
         yaw = number_str.toFloat();
         number_str = "";
         count = 0;
      }
      // add str to number
      } else {
         number_str += c;
      }
   }
   //printf("T=%f P=%f R=%f Y=%f\n", throttle, pitch, roll, yaw);
}
