#ifndef moddev_Device_h
#define moddev_Device_h

#ifdef DEBUG
#define debug(name,arg) Serial.print(#name": "); Serial.prinln(arg);
#else
#define debug(name,arg)
#endif

#define MAX_CONTROLLED_DEVICE (2);

namespace moddev {

typedef unsigned char byte_t;

class Device
{
private:
  unsigned long time;

  byte_t prev_state, state;
  byte_t prev_mode, mode;

  // controlled device by this device
  struct devctrl {
    Device* device;
    byte_t on_state;  // when main device go to on_state
    byte_t set_state; // controlled device set to set_state
  };
  devctrl controlled[2];

  byte_t device_count;

public:
  Device();
  virtual void setup();
  virtual void tick();

  void wait(unsigned long);
  bool waiting();

  byte_t stateGet();
  byte_t stateSet(byte_t);
  byte_t modeGet();
  byte_t modeSet(byte_t);

  virtual void onStateChange(byte_t);

  void control(Device* d, byte_t _on_state, byte_t _set_state);
};
}; // ns
#endif