// #include "PegasusProcessor.h"

// static float throttle = 0.0;
// static float pitch = 0.0;
// static float roll = 0.0;
// static float yaw = 0.0;

// void processorProcess(char buffer[]) {

//   String buffer_str(buffer);

//   //"C;T=\(throttle);P=\(pitch);R=\(roll);Y=\(yaw);"

//   // Aqui só deve ter o swicth pela primeira letra e chamar a flight controller
// }

// void updateFlightCommands(String bufferCommands) {

//   int count = 0;
//   char c = ' ';
//   String number_str = "";

//   // [0] = C
//   for (int i = 1; i < bufferCommands.length(); i++) {
//     c = bufferCommands.charAt(i);
//     // if finished a number
//     if (c == ';') {
//       if (count == 0) {
//         throttle = number_str.toFloat();
//         number_str = "";
//         count++;
//       } else if (count == 1) {
//         pitch = number_str.toFloat();
//         number_str = "";
//         count++;
//       } else if (count == 2) {
//         roll = number_str.toFloat();
//         number_str = "";
//         count++;
//       } else if (count == 3) {
//         yaw = number_str.toFloat();
//         number_str = "";
//         count = 0;
//       }
//     // add str to number
//     } else {
//       number_str += c;
//     }
//   }
// }