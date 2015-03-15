#include "Light.h"
#include "ServoM.h"
#include "Sketch.h"
#include "RequestBrocker.h"

RequestBrocker brocker;
Light l(13);
ServoM s(4);
RequestT <Light*> l_on("on", &l);
RequestT <Light*> l_off("off", &l);
//RequestT <Light*> l_blink("blink", &l, 1);
//RquestT <ServoM*> s_rotate("rotate", &s, 1);

Sketch k;

DISPATCH_BEGIN
    DISPATCH_COMMAND("on", Light, on);
    DISPATCH_COMMAND("off", Light, off);
//    DISPATCH_COMMAND_INT("blink", Light, blinkStart);
//    DISPATCH_COMMAND_INT("rotate", ServoM, rotate);
DISPATCH_END;

void serialEvent()
{
  brocker.serialEvent();
}

void setup()
{
  Serial.begin(9600);
  
  brocker.dispatcherAttach(&dispatcher);
  brocker.RequestAdd(&l_on);
  brocker.RequestAdd(&l_off);
  
  l.setup();
  //s.setup();
  
  //k.deviceAdd(&s);
  //k.deviceAdd(&l);

  //k.setup();
 
}


void loop()
{
  //k.tick();
}



