#include "Device.h"
#include "Arduino.h"

Device::Device():time(0){}

void Device::setup()
{
}

void Device::tick()
{
}

int Device::stateGet()
{
  return state;
}

int Device::stateSet(int _state)
{
  int old_state = state;
  state = _state;
  onStateChange(state, old_state);
  return old_state;
}

void Device::wait(unsigned long mls)
{
  time = mls + millis();
}

bool Device::waiting()
{
  return time > millis();
}

void Device::onStateChange(int new_state, int old_state)
{
}


