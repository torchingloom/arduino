#ifndef RailSwitch_h
#define RailSwitch_h

#include "ServoM.h"
#include "Trigger.h"
#include "Switcher.h"

class RailSwitch:
public ServoM
{
private:
  int angle;
  int l, r;
  Switcher* switcher;
  int switcher_state;

public:
  enum {INITIAL, LEFT, RIGHT};
  RailSwitch(int, int, int, int);
  void setup();
  void left();
  void right();
  void swtch(int);
  void switcherAttach(Switcher*, int);
  void onStateChange(int);
};

#endif;