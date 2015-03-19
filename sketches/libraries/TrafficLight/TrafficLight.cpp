#include "TrafficLight.h"
#include "Arduino.h"

namespace moddev {

TrafficLight::TrafficLight(byte_t r, byte_t y, byte_t g, int d, byte_t _analog_pin): 
  red(r, true), yellow(y, true), green(g, true),
  work_delay(d), 
  analog_pin(_analog_pin)
{
}

void TrafficLight::setup()
{
  red.setup();
  yellow.setup();
  green.setup();
}

void TrafficLight::delayChange(int _delay)
{
  work_delay = (_delay + 70) * 20;
}

unsigned long TrafficLight::delayGet()
{
  return work_delay;
}

void TrafficLight::swtch()
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
      green.blinkStart(600);
      stateSet(GREEN_BLINK);
      wait(4610);
      break;
    case GREEN_BLINK:
      green.blinkStop();
      yellow.on();
      stateSet(YELLOW);
      wait(1000);
      break;
  }
}

void TrafficLight::tick()
{ 
  if (GREEN_BLINK == stateGet()) green.tick();
  swtch();  
}

void TrafficLight::onStateChange(byte_t _state)
{
  delayChange(analogRead(analog_pin));
}

}