#include "TrafficLightControlled.h"

TrafficLightControlled::TrafficLightControlled(int r, int y, int g, int d): 
red(r), yellow(y), green(g), TrafficLight(d)
{
  stateSet(OFF);
}

TrafficLightControlled::TrafficLightControlled()
{
  TrafficLightControlled(11, 12, 13, 2000);
}

void TrafficLightControlled::setup()
{ red.setup();
  yellow.setup();
  green.setup();
  TrafficLight::setup();
}

void TrafficLightControlled::swtch()
{
  if (waiting()) return;


  switch (stateGet())
  {
    case OFF:
    case YELLOW:
      yellow.off();
      red.on();
      stateSet(RED);
      wait(delayGet());
      break;
    case RED:
      red.off();
      green.on();
      stateSet(GREEN);
      wait(delayGet());
      break;
    case GREEN:
      green.off();
      green.blink(600);
      stateSet(GREEN_BLINK);
      wait(4610);
      break;
    case GREEN_BLINK:
      green.off();
      yellow.on();
      stateSet(YELLOW);
      wait(1000);
      break;
  }
}

void TrafficLightControlled::tick()
{ 
  if (GREEN_BLINK == stateGet()) green.tick();
  swtch();
  TrafficLight::tick();
}