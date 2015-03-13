#include <ServoM.h>
#include "Arduino.h"

ServoM::ServoM(int _pin):pin(_pin)
{
}

ServoM::ServoM()
{
  ServoM(4);
}

void ServoM::rotate(int deg)
{
  servo.write(deg);
}

void ServoM::setup()
{
  servo.attach(pin);
}
