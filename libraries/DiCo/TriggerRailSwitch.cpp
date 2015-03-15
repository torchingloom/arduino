#include "TriggerRailSwitch.h"
#include "Arduino.h"

TriggerRailSwitch::TriggerRailSwitch(int _pin, RailSwitch* s, int _state): Trigger(_pin), rail_switch(s), switch_state(_state)
{
}

void TriggerRailSwitch::setup()
{
  Trigger::setup();
  Serial.println(stateGet());
}

void TriggerRailSwitch::tick()
{
  Trigger::tick();
}

void TriggerRailSwitch::onStateChange(int _state)
{
  if (PASSIVE == modeGet()) return;
  if (LOW == _state && switch_state != rail_switch->stateGet())
  {
    rail_switch->swtch(switch_state);
    modeSet(PASSIVE);
  }
}