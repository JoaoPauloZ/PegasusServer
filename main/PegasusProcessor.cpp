#include <Arduino.h>
#include "PegasusProcessor.h"

PegasusProcessor::PegasusProcessor() {
   flightController = PegasusFlightController();
}

//"\(action);\(throttle);\(pitch);\(roll);\(yaw);"
void PegasusProcessor::process(String buffer) {

   if (buffer.length() > 0) {
      action = buffer[0];
   }

   // Update preferences
   if (action == 'U') {
      fillMotorPreferences(buffer);
   }

   // Flight Commands
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
   flightController.update(throttle, pitch, roll, yaw);
   //printf("T=%d P=%d R=%d Y=%d\n", throttle, pitch, roll, yaw);
}

void PegasusProcessor::fillMotorPreferences(String buffer) {
   int count = 0;
   char c = ' ';

   String buffer_temp = "";
   PegasusMotorPreferences pref_0;
   PegasusMotorPreferences pref_1;
   PegasusMotorPreferences pref_2;
   PegasusMotorPreferences pref_3;

   Serial.println(buffer);

   for (int i = 1; i < buffer.length(); i++) {
      c = buffer.charAt(i);
      // if finished a number
      if (c == '&') {
         Serial.println(buffer_temp);
         if (count == 0) {
            pref_0 = strToPref(buffer_temp);
            buffer_temp = "";
            count++;
         } else if (count == 1) {
            pref_1 = strToPref(buffer_temp);
            buffer_temp = "";
            count++;
         } else if (count == 2) {
            pref_2 = strToPref(buffer_temp);
            buffer_temp = "";
            count++;
         } else if (count == 3) {
            pref_3 = strToPref(buffer_temp);
            buffer_temp = "";
            count = 0;
         }
      // add str to buffer_temp
      } else {
         buffer_temp += c;
      }
   }

   flightController.setPreferencesForMotor(0, pref_0);
   flightController.setPreferencesForMotor(1, pref_1);
   flightController.setPreferencesForMotor(2, pref_2);
   flightController.setPreferencesForMotor(3, pref_3);

}

PegasusMotorPreferences PegasusProcessor::strToPref(String buffer) {
   int count = 0;
   char c = ' ';

   PegasusMotorPreferences pref;
   String buffer_temp = "";

   for (int i = 0; i < buffer.length(); i++) {
      c = buffer.charAt(i);
      // if finished a number
      if (c == ';') {
         if (count == 0) {
             pref.increaseValue = buffer_temp.toInt();
             buffer_temp = "";
             count++;
          } else if (count == 1) {
             pref.minAngleESC = buffer_temp.toInt();
             buffer_temp = "";
             count++;
          } else if (count == 2) {
             pref.maxAngleESC = buffer_temp.toInt();
             buffer_temp = "";
             count++;
          }
      // add str to buffer_temp
      } else {
         buffer_temp += c;
      }
   }

   return pref;
}
