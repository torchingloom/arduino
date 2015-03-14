#include <ServoM.h>

ServoM s(4);


void setup()
{
  s.setup();  
}

int pos = 0;

void loop()
{
  for(pos = 0; pos <= 180; pos += 1)
  {
    s.rotate(pos);
    delay(15);
  } 
  for(pos = 180; pos>=0; pos-=1)
  {                                
    s.rotate(pos);
    delay(15);
  } 
}

