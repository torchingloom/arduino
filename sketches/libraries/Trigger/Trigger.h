#ifndef moddev_Trigger_h
#define moddev_Trigger_h

#include "../Device/Device.h"

namespace moddev {

class Trigger:
public Device
{
private:
  byte_t pin;
  unsigned int time_delay;
  byte_t switch_state;
 
public:
  enum {
    // states
    T_LOW, T_HIGH,
    // modes
    ACTIVE, PASSIVE
  };
  Trigger(byte_t, byte_t = T_LOW, unsigned int = 250);
  virtual void setup();
  virtual void tick();
  int read();
  void reset();
  virtual void onStateChange(byte_t);
};
};

#endif
