#ifndef AR_h
#define AR_h

#include "Device.h"

// огонь
class AR :
public Device
{
private:
  int pin;
  int interval;
  int val;
public:
  AR();
  AR(int pin);
  virtual void setup();
  virtual void tick();
  int data();
};

#endif