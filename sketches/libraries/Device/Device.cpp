#include <Arduino.h>
#include "Device.h"

namespace moddev {

Device::Device():time(0), device_count(0)
{
}

void Device::setup()
{
}

void Device::tick()
{
}

byte_t Device::stateGet()
{
  return state;
}

byte_t Device::stateSet(byte_t _state)
{
  prev_state = state;
  state = _state;
  onStateChange(state);
  if (device_count > 0)
  {
    for (int i=0; i < device_count; i++)
    {
      if (_state == controlled[i].on_state)
      {
        controlled[i].device->stateSet(controlled[i].set_state);
      }
    }
  }
  return prev_state;
}

byte_t Device::modeGet()
{
  return mode;
}

byte_t Device::modeSet(byte_t _mode)
{
  prev_mode = mode;
  mode = _mode;
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

void Device::onStateChange(byte_t _state)
{
}


void Device::control(Device* d, byte_t _on_state, byte_t _set_state)
{
  if (device_count < 2)
  {
    controlled[device_count].device = d;
    controlled[device_count].on_state = _on_state;
    controlled[device_count].set_state = _set_state;
  }
  device_count++;
}

};



