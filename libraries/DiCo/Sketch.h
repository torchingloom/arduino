#ifndef Sketch_h
#define Sketch_h

#include "Device.h"

#define SKETCH_MAX_DEVICES 10

class Sketch
{
  private:
  Device* dev[SKETCH_MAX_DEVICES];
  int device_count;
  public:
  Sketch();
  int deviceAdd(Device* d);
  void setup();
  void tick();
};

#endif
