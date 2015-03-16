#ifndef TrafficLightControlledWithStop_h
#define TrafficLightControlledWithStop_h

#include "RailSwitch.h"
#include "TrafficLightControlled.h"

class TrafficLightControlledWithStop : 
public TrafficLightControlled
{
  RailSwitch* rail_switch;

public:
  TrafficLightControlledWithStop(int, int, int, int, RailSwitch*);
  virtual void setup();
  virtual void onStateChange(int);
};

#endif