#include <Arduino.h>
#include "Light.h"

namespace moddev {

Light::Light(byte_t p, bool inv): pin(p), inversed(inv)
{
}

void Light::setup()
{
  pinMode(pin, OUTPUT);
  modeSet(NORMAL);
  off();
}

void Light::on()
{
  digitalWrite(pin, inversed ? LOW : HIGH);
  stateSet(ON);
}

void Light::off()
{
  digitalWrite(pin, inversed ? HIGH : LOW);
  stateSet(OFF);
}

void Light::blinkStart(int _interval)
{
  modeSet(BLINKING);
  interval = _interval;
}

void Light::blinkStop(int state)
{
  modeSet(NORMAL);
  state == OFF ? off() : on();
}

void Light::tick()
{
  if (NORMAL == modeGet()) return;
  if (waiting()) return;

  if (OFF == stateGet()) on();
  else off();

  wait(interval);
}

};