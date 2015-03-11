#include "AR.h"
#include "Arduino.h"

AR::AR(int p): pin(p), interval(5000), val(0)
{
  Device();
}

AR::AR()
{
  AR(0);
}

void AR::setup()
{
	interval = 1000;
	Serial.print("ssss: ");
	Serial.println(interval);
	Serial.println("");
	Serial.println("");
}

void AR::tick()
{
	if (waiting()) return;
	val = analogRead(pin);
	Serial.println(val);
	Serial.print("1: ");
	Serial.println(interval);
	Serial.println("");
	wait(interval);
}

int AR::data()
{
	return val;
}