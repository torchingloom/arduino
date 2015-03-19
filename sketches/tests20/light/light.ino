#include "Device.h"
#include "Light.h"

#define DEBUG 1;

using namespace moddev;

Light l(13);


void setup()
{
  Serial.begin(9600);
 
  l.setup();
  l.off();
  l.blinkStart(1000);
}

void loop()
{
    l.tick();
}
