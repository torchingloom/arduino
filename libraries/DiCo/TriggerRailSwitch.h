#ifndef TriggerRailSwitch_h
#define TriggerRailSwitch_h

#include "Trigger.h"
#include "RailSwitch.h"

class TriggerRailSwitch:
public Trigger
{
  RailSwitch* rail_switch;
  int switch_state;
public:
  TriggerRailSwitch(int, RailSwitch*, int);
  virtual void setup();
  virtual void tick();
  virtual void onStateChange(int);
};

#endif