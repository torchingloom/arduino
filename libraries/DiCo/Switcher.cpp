#include "Switcher.h"
#include "Arduino.h"
#include "Trigger.h"

Switcher::Switcher(int pin, int _angle, int _up, int _down, int _time):
ServoM(pin), angle(_angle), u(_up), d(_down), interval(_time)
{
  // triggers = ArrayT<Trigger*>(1);
  cnt = 0;
}

void Switcher::setup()
{
  ServoM::setup();
  down();
  delay(100);
}

void Switcher::up()
{
  rotate(u);
  stateSet(UP);
  wait(interval);
}

void Switcher::down()
{
  rotate(d);
  stateSet(DOWN);
}

void Switcher::tick()
{
  if(waiting() || DOWN == stateGet()) return;
  down();
  for (int i=0; i < cnt; i++)
  {
    triggers[i]->reset();
  }
}

int Switcher::triggerAdd(Trigger* t)
{
   //triggers.add(t);
   triggers[cnt] = t;
   cnt++;
   return cnt;
}