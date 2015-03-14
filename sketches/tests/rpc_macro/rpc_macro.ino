#include "Light.h"
#include "CommandBrocker.h"


Light l(13);
CommandT <Light*> l_on ("light_on", &l);
CommandT <Light*> l_off = CommandT <Light*> ("light_off", &l);
CommandBrocker brocker(2);

RPC_BEGIN;
    RPC_COMMAND("light_on", Light, on);
    RPC_COMMAND("light_off", Light, off);
RPC_END;

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



