#include "RailSwitch.h"
#include "Arduino.h"

RailSwitch::RailSwitch(int pin, int _angle, int _left, int _right):
ServoM(pin), angle(_angle), r(_right), l(_left)
{
  switcher = NULL;
}

void RailSwitch::setup()
{
  ServoM::setup();
  rotate(angle);
  if (INITIAL)
  {
    stateSet(INITIAL);
  }
  else
  {
    stateSet(angle);
  }
  delay(100);
}

void RailSwitch::left()
{
  rotate(l);
  stateSet(LEFT);
}

void RailSwitch::right()
{
  rotate(r);
  stateSet(RIGHT);
}

void RailSwitch::swtch(int _state)
{
  switch(_state)
  {
    case LEFT: left(); break;
    case RIGHT: right(); break;
  }
}

void RailSwitch::switcherAttach(Switcher* s, int _state)
{
  switcher = s;
  switcher_state = _state;
}

void RailSwitch::onStateChange(int _state)
{
   if (_state == switcher_state)
   {
     switcher->up();
   }
}