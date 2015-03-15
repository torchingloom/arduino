#define DEBUG

//#include "Sketch.h"
#include "TrafficLightControlled.h"
#include "RailSwitch.h"
#include "TriggerRailSwitch.h"
#include "Switcher.h"

// светофор
TrafficLightControlled t1(13, 12, 11, 6000);
// стрелка
RailSwitch rs(10, 90, 180, 0);
// триггер, который переводит стрелку влево
// срабатывает один раз
TriggerRailSwitch tr1(2, &rs, RailSwitch::LEFT);
// триггер, который переводит стрелку вправо
TriggerRailSwitch tr2(3, &rs, RailSwitch::RIGHT);
// стоп магнит
// управляется стрелкой (см setup())
// и взводит триггеры через оппределенное время
Switcher sw(9, 90, 180, 0, 5000);


void setup()
{
  Serial.begin(9600);
    
  // стрелка будет оправлять стоп магнитом при срабатывание вправо
  rs.switcherAttach(&sw, RailSwitch::RIGHT);
  
  // стоп мангит будет "взводить" эти триггеры
  sw.triggerAdd(&tr1);
  sw.triggerAdd(&tr2);
  
  t1.setup();
  rs.setup();
  tr1.setup();
  tr2.setup();
  sw.setup();
  //rs.rotate(55);
  delay(2000);
  //rs.swtch(RailSwitch::LEFT);
  //delay(3000);
  // ch(RailSwitch::RIGHT);
    
  Serial.println("ready");
  //s.deviceAdd(&t1);
  //s.setup();
}

void loop()
{
 
  t1.tick();
  tr2.tick();
  tr1.tick();
  sw.tick();
}


