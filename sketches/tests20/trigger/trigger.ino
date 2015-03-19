#include "Device.h"
#include "Trigger.h"

#define DEBUG 1

using namespace moddev;

Trigger t(2, Trigger::T_LOW, 300);

void setup()
{
  Serial.begin(9600);
  delay(20);
  t.setup();
}

void loop()
{
  t.tick();
}
