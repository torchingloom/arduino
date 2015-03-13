#define DEBUG

#include "Sketch.h"
#include "TrafficLightControlled.h"

Sketch s;
TrafficLightControlled t1;


void setup()
{
  Serial.begin(9600);
  
  //ar = AR();
  //s.deviceAdd(&ar);
  // обычный светофор, с 6 сек. интервалом
  t1 = TrafficLightControlled(13, 12, 11, 6000);
  //t1.delayChange(50);
  s.deviceAdd(&t1);
  // ночной светофор на 15 ноге, мигает желтым каждые 2 сек.
  //t2 = TrafficLightUncontrolled(10, 2000);
  //s.deviceAdd(&t2);
  // фонарик на 10 ноге будет мигать с интералом .5 сек.
  s.setup();
}

void loop()
{
  // поихалы
  s.tick();  
}


