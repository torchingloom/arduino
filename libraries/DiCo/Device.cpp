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
  prev_state = state;
  state = _state;
  onStateChange(state);
  return prev_state;
}

int Device::modeGet()
{
  return mode;
}

int Device::modeSet(int _mode)
{
  prev_mode = mode;
  mode = _mode;
  onModeChange(mode);
  return prev_mode;
}

void Device::wait(unsigned long mls)
{
  time = mls + millis();
}

bool Device::waiting()
{
  return time > millis();
}

void Device::onStateChange(int _state)
{
}

void Device::onModeChange(int _mode)
{
}



