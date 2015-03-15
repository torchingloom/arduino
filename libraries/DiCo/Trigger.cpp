#include "Trigger.h"
#include "Arduino.h"

Trigger::Trigger(int _pin): pin(_pin)
{
}

void Trigger::setup()
{
  pinMode(pin, INPUT);
  stateSet(T_HIGH);
  modeSet(ACTIVE);
}

void Trigger::reset()
{
  stateSet(T_HIGH);
  modeSet(ACTIVE);
}

int Trigger::read()
{
  return digitalRead(pin);
}

void Trigger::tick()
{
  if (PASSIVE == modeGet()) return;
  stateSet(read());
}


void Trigger::onStateChange(int _state)
{
  if (PASSIVE == modeGet()) return;
  if (LOW == _state)
  {
    Serial.println(_state);
    modeSet(PASSIVE);
  }
}




