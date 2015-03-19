#include <Light.h>
#include <Device.h>
#include <TrafficLight.h>

using namespace moddev;

TrafficLight l(13, 12, 11, 5000, 4);

void setup()
{
  l.setup();
}

void loop()
{
  l.tick();
}

