#include "Light.h"
#include "RequestBrocker.h"
#include "Sketch.h"

RequestBrocker brocker;
Light l(13);
RequestT <Light*> l_on("on", &l);
RequestT <Light*> l_off("off", &l);
RequestT <Light*> l_blink("blink", &l, 1);
Sketch sk;


class MyDispatcher:
public Dispatcher
{
public:
  MyDispatcher():Dispatcher(){}
  ~MyDispatcher(){};
  Request::Param dispatch(Request* c)
  {
    String action(c->nameGet());
    if ( action == "on" ) ((Light*)(c->dev()))->on();
    if ( action == "off" ) ((Light*)(c->dev()))->off();
    //if ( action == "blink" ) ((Light*)(c->dev()))->blinkStart((int)(*c->paramGet(0)));
    if ( action == "blink" ) ((Light*)(c->dev()))->blinkStart((int)(*c->paramGet(0)));

   return result;
  }
} 
dispatcher;

void serialEvent()
{
  brocker.serialEvent();
}

void setup()
{
  Serial.begin(9600);
  //l.setup();
  
  brocker.RequestAdd(&l_on);
  brocker.RequestAdd(&l_off);
  brocker.RequestAdd(&l_blink);
  brocker.dispatcherAttach(&dispatcher);

  //sk.deviceAdd(&l);
  //sk.setup();
  l.setup();  
  
}


void loop()
{
   l.tick();
}



