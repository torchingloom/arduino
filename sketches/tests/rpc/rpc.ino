#include "Light.h"
#include "CommandBrocker.h"

Light l(13);
CommandT <Light*> l_on ("light_on", &l);
CommandT <Light*> l_off = CommandT <Light*> ("light_off", &l);
CommandBrocker brocker(2);

class MyProxy:
public ClientProxy
{
public:
  MyProxy():ClientProxy(){}
  ~MyProxy(){};
  Command::Param dispatch(Command* c)
  {
    String action(c->nameGet());
    if ( action == "light_on" ) ((Light*)(c->dev()))->on();
    if ( action == "light_off" ) ((Light*)(c->dev()))->off();
    //if ( action == "bar" ) ret = c->dev()->bar((int)(c->paramGet(0)));

   return result;
  }
} 
proxy;

void serialEvent()
{
  brocker.serialEvent();
}

void setup()
{
  Serial.begin(9600);
  l.setup();  

  brocker.commandAdd(&l_on);
  brocker.commandAdd(&l_off);

  brocker.proxyAttach(&proxy);
  brocker.transportAttach(&Serial);

}


void loop()
{
}



