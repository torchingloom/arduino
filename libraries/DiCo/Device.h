#ifndef Device_h
#define Device_h

class Device
{
private:
  unsigned long time;
  int prev_state;
  int state;
  int prev_mode;
  int mode;
public:
  Device();
  virtual void setup();
  void static debug(const char*);
  virtual void tick();
  void wait(unsigned long);
  bool waiting();
  int stateGet();
  int stateSet(int);
  int modeGet();
  int modeSet(int);
  virtual void onStateChange(int);
  virtual void onModeChange(int);
};

#endif