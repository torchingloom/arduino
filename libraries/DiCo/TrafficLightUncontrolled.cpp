#include "TrafficLightUncontrolled.h"

TrafficLightUncontrolled::TrafficLightUncontrolled(int y, int d): yellow(y), TrafficLight(d)
{
}

TrafficLightUncontrolled::TrafficLightUncontrolled()
{
  TrafficLightUncontrolled(14, 1000);
}

void TrafficLightUncontrolled::setup()
{
  TrafficLight::setup();
  yellow.blink(delayGet());
}

void TrafficLightUncontrolled::swtch()
{
  yellow.tick();
}