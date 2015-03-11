#ifndef Light_h
#define Light_h

#include "Device.h"

// огонь
class Light :
public Device
{
private:
  int pin;
  enum {ON, OFF};
  bool blinking;
  int interval;
public:
  Light();
  Light(int pin);
  virtual void setup();
  void on(); // гори
  void off(); // потухни
  void blink(int interval); // мигай с интервалом interval
  virtual void tick();
};

#endif