#define DEBUG

//#include "Sketch.h"
#include "TrafficLightControlledWithStop.h"
#include "RailSwitch.h"
#include "TriggerRailSwitch.h"
#include "Switcher.h"

// светофор
RailSwitch rs1(5, 88, 88, 66);
TrafficLightControlledWithStop t1(13, 12, 11, 100, &rs1);
// стрелка
RailSwitch rs(8, 59, 59, 95);
// триггер, который переводит стрелку влево
// срабатывает один раз
TriggerRailSwitch tr1(2, &rs, RailSwitch::LEFT);
// триггер, который переводит стрелку вправо
TriggerRailSwitch tr2(4, &rs, RailSwitch::RIGHT);
// стоп магнит
// управляется стрелкой (см setup())
// и взводит триггеры через оппределенное время
Switcher sw(6, 84, 62, 84, 10000);
  
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
  rs1.setup();
  tr1.setup();
  tr2.setup();
  sw.setup();
  //rs.rotate(55);
  delay(2000);
  //delay(3000);
    
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

