#include "Sketch.h"

Sketch::Sketch():device_count(SKETCH_MAX_DEVICES){}

int Sketch::deviceAdd(Device* d)
{
  if (device_count < SKETCH_MAX_DEVICES)
  {
    dev[device_count++] = d;
  }
}

void Sketch::setup()
{
  for (int i=0; i < device_count; i++) dev[i]->setup();
}

void Sketch::tick()
{
  for (int i=0; i < device_count; i++) dev[i]->tick();
}