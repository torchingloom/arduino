#ifndef Trigger_h
#define Trigger_h

#include "Device.h"

class Trigger:
public Device
{
private:
  int pin;
 
public:
  enum {T_HIGH, T_LOW};
  enum {ACTIVE, PASSIVE};
  Trigger(int);
  virtual void setup();
  virtual void tick();
  int read();
  void reset();
  virtual void onStateChange(int);
};

#endif
