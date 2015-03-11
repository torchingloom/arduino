#ifndef TrafficLight_h
#define TrafficLight_h

#include "Device.h"
#include "Light.h"
#include "AR.h"

class TrafficLight : 
public Device
{
private:
  int work_delay;
	int analog_pin;
	AR roller;
	
public:
  TrafficLight();
  TrafficLight(int delay);
  virtual void setup();
  unsigned long delayGet();
  void delayChange(int _delay);
  int readAnalogData();
  virtual void tick();
};

#endif