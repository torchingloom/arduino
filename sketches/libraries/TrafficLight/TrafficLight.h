#ifndef moddev_TrafficLight_h
#define moddev_TrafficLight_h

#include "../Device/Device.h"
#include "../Light/Light.h"
#include "../ServoSwitcher/ServoSwitcher.h"

namespace moddev {

class TrafficLight : 
public Device
{
private:
  int work_delay;
  byte_t analog_pin;
  Light red, yellow, green;
public:
  enum {OFF, RED, GREEN, GREEN_BLINK, YELLOW};
  TrafficLight(byte_t red, byte_t yellow, byte_t green, int delay, byte_t analog_pin = 0);
  virtual void setup();
  void delayChange(int _delay);
  unsigned long delayGet();
  void onStateChange(byte_t);
  virtual void swtch();
  virtual void tick();
};
};

#endif