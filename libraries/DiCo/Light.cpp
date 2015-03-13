#include "Light.h"
#include "Arduino.h"

Light::Light(int p): pin(p), blinking(false)
{
  Device();
  stateSet(OFF);
}

Light::Light()
{
  Light(13);
}

void Light::setup()
{
  pinMode(pin, OUTPUT);
  off();
}

void Light::on()
{
  digitalWrite(pin, LOW);
Serial.println("light on");
  stateSet(ON);
}

void Light::off()
{
  digitalWrite(pin, HIGH);
Serial.println("light off");
  stateSet(OFF);
}

void Light::blink(int _interval)
{
  blinking = true;
  interval = _interval;
}

void Light::tick()
{
  if (!blinking) return;
  if (waiting()) return;

  if (OFF == stateGet()) on();
  else off();

  wait(interval);
}