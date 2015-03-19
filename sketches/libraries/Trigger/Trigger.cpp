#include <Arduino.h>
#include "Trigger.h"

namespace moddev {

Trigger::Trigger(byte_t _pin, byte_t _switch_state, unsigned int _time_delay):
  pin(_pin),
  switch_state(_switch_state),
  time_delay(_time_delay)
{
}

void Trigger::setup()
{
  pinMode(pin, INPUT);
  reset();
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
  if (waiting()) return;
  if (PASSIVE == modeGet()) reset();
  stateSet(read());
}

void Trigger::onStateChange(byte_t _state)
{
  if (switch_state == _state)
  {
    modeSet(PASSIVE);
    wait(time_delay);
  }
}
}


