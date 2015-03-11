#ifndef Device_h
#define Device_h

class Device
{
private:
  unsigned long time;
  int state;
public:
  Device();
  virtual void setup();
  void static debug(const char* mess);
  virtual void tick();
  void wait(unsigned long mls);
  bool waiting();
  int stateGet();
  int stateSet(int s);
  virtual void onStateChange(int new_state, int old_state);
};

#endif