#ifndef TrafficLightUncontrolled_h
#define TrafficLightUncontrolled_h

#include "TrafficLight.h"

class TrafficLightUncontrolled: 
public TrafficLight
{
protected:
  Light yellow; 
public:
  TrafficLightUncontrolled();
  TrafficLightUncontrolled(int y, int d);
  virtual void swtch();
  virtual void setup();
};

#endif