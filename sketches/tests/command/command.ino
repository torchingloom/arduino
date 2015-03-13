#include <Command.h>
#include <Light.h>

Light l;
Command* c;

Command::Param p;


void setup()
{
  Serial.begin(9600);
  
  p = Command::Param((int)13);
  Serial.println((int)p);
  
  c = new CommandT<Light*>("on", &l, 1  );
  c->paramAdd((int)75);
  Serial.println(c->nameGet());
  Serial.println((int)c->paramGet(0));
  delete c;
}
    
void loop()
{
}
