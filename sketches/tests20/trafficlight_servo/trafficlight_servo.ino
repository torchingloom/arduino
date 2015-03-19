#include "Light.h"
#include "Device.h"
//#include "Trigger.h"
#include "TrafficLight.h"
#include <Servo.h>
#include "ServoSwitcher.h"

using namespace moddev;

TrafficLight tl(13, 12, 11, 100, 4);
ServoSwitcher tl_servo(5, 88, 66, ServoSwitcher::ON);

void setup()
{
  Serial.begin(9600);
  tl.controlled(&tl_servo);
  tl_servo.setup();
  tl.setup();
}

void loop()
{
  tl.tick();
}

