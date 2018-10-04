#ifndef PEGASUS_MOTOR_H
#define PEGASUS_MOTOR_H
#include <Arduino.h>
#include <AmebaServo.h>

class PegasusMotor {

public:
   PegasusMotor();
   PegasusMotor(int pin);
   void setSpeed(int speed);
private:
   AmebaServo esc;
};

#endif