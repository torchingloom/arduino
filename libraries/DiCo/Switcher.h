#ifndef Switcher_h
#define Switcher_h
#include "ServoM.h"
#include "ArrayT.h"
#include "Trigger.h"

class Switcher:
public ServoM
{
private:
  int angle;
  int u, d;
  int interval;
  //ArrayT<Trigger*> triggers;
  Trigger* triggers[2];
  int cnt;

public:
  enum {UP, DOWN};
  Switcher(int, int, int, int, int);
  void setup();
  void up();
  void down();
  void tick();
  void triggerAdd(Trigger* t);
};

#endif;