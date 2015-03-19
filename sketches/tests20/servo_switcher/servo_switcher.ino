#include <Servo.h>
#include "Device.h"
#include "ServoSwitcher.h"

using namespace moddev;

ServoSwitcher switcher(8, 59, 95);

void setup()
{
  Serial.begin(9600);
  switcher.setup();
}

void loop()
{
  switcher.stateSet(ServoSwitcher::ON);
  delay(1000);
  switcher.stateSet(ServoSwitcher::OFF);
  delay(1000);
}

