#ifndef TrafficLightControlled_h
#define TrafficLightControlled_h

#include "TrafficLight.h"

class TrafficLightControlled : 
public TrafficLight
{
protected:
  // states
  enum {OFF, RED, GREEN, GREEN_BLINK, YELLOW};
  Light red, yellow, green;

public:
  TrafficLightControlled(int r, int y, int g, int d);
  TrafficLightControlled();
  virtual void swtch();
  virtual void setup();
  virtual void tick();
};

#endif