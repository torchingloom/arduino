#include <Arduino.h>
#include "ServoSwitcher.h"

namespace moddev {

ServoSwitcher::ServoSwitcher(byte_t _pin, int _pos1_angle, int _pos2_angle, byte_t _init_state):
pin(_pin), pos1_angle(_pos1_angle), pos2_angle(_pos2_angle), init_state(_init_state)
{
}

void ServoSwitcher::setup()
{
  servo.attach(pin);
  init_state == POS1 ? stateSet(POS1) : stateSet(POS2);
}

void ServoSwitcher::onStateChange(byte_t _state)
{
  if (POS1 == _state) servo.write(pos1_angle);
  else servo.write(pos2_angle);
}
};



