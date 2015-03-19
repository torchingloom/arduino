#ifndef moddev_Light_h
#define moddev_Light_h

#include "../Device/Device.h"

namespace moddev {

class Light:
public Device
{
private:
  byte_t pin;

  enum {
  	// states
  		ON, OFF,
  	// modes
   	NORMAL, BLINKING
  };

  int interval;
  bool inversed;

public:
  Light(byte_t, bool = false);
  virtual void setup();
  void on();
  void off();
  void blinkStart(int interval);
  void blinkStop(int state = OFF);
  virtual void tick();
};
};

#endif