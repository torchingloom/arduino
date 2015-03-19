#ifndef moddev_ServoSwitcher_h
#define moddev_ServoSwitcher_h

#include "../Device/Device.h"
#include <Servo.h>

namespace moddev {

class ServoSwitcher:
public Device
{
private:
  Servo servo;
  byte_t pin;
  int pos1_angle;
  int pos2_angle;
  byte_t init_state;
protected:
  void swtch(byte_t _state);
public:
  enum {POS1, POS2};
  ServoSwitcher(byte_t pin, int pos1_angle, int pos2_angle, byte_t init_state = POS1);
  void setup();
  void onStateChange(byte_t);
};

}; // ns
#endif