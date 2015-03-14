#ifndef ServoM_H
#define ServoM_h

#include <Device.h>
#include "ServoCopy.h"

class ServoM:
public Device
{
private:
  int pin;
  Servo servo;
public:
  ServoM();
  ServoM(int);
  void rotate(int);
  void sweep(int delay);
  void setup();
};

#endif;