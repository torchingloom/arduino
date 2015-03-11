#include "TrafficLight.h"
#include "Arduino.h"

TrafficLight::TrafficLight(int d): 
	work_delay(d), 
	analog_pin(0), 
	Device()
{
	roller = AR();
}

TrafficLight::TrafficLight()
{
  TrafficLight(1000);
}

void TrafficLight::setup()
{
	roller.setup();
}

void TrafficLight::tick()
{
	roller.tick();
	delayChange(roller.data());
}

unsigned long TrafficLight::delayGet()
{
  return work_delay;
}

void TrafficLight::delayChange(int _delay)
{
	work_delay = (_delay + 70) * 20;
}

int TrafficLight::readAnalogData()
{
}

