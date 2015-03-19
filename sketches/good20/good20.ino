#include "Light.h"
#include "Device.h"
#include "Trigger.h"
#include "TrafficLight.h"
#include <Servo.h>
#include "ServoSwitcher.h"

using namespace moddev;

// Зона 1 - светофор, управляющий магнитом
//
// светофор на 13, 12, 11 пинах, задержка 100 мс., с A0 -го пина читать задержку
TrafficLight tl(13, 12, 11, 100, A0);
// стоп магнит, которым будет управлять светофор
// на 5 пине, 88(POS1) и 66(POS2) углы на которые будет страбатывать серво, ServoSwitcher::POS1 - начальное положение (88 град.)
ServoSwitcher tl_servo(5, 88, 66, ServoSwitcher::POS1);

// Зона 2 - ЖД стрелка
//
// триггер (геркон) перед стрелкой на 2 пине, будет переводить стрелку в состояние POS2. 300 мс. на дребезг контактов
Trigger before_railsw_tr(2, Trigger::T_LOW, 300);
// ЖД стрелка на 8 пине с углами поворота серво 88 и 66 град. в начальном положении POS1 (59 град.)
ServoSwitcher railsw(8, 59, 95, ServoSwitcher::POS1);
// триггер (геркон) после стрелки на 4 пине, будет переводить стрелку в состояние POS1. 300 мс. на дребезг контактов
Trigger after_railsw_tr(4, Trigger::T_LOW, 300);
// стоп магнит, который будет срабатывать при переводе стрелки
ServoSwitcher rail_stop_sw(6, 84, 62, ServoSwitcher::POS1);

void setup()
{
  Serial.begin(9600);
  
  // связываем светофор с серво
  tl.control(&tl_servo, TrafficLight::YELLOW, ServoSwitcher::POS2);
  tl.control(&tl_servo, TrafficLight::GREEN, ServoSwitcher::POS1);
  tl_servo.setup();
  tl.setup();
  
  // привязываем триггер к стрелке - переключение стрелки в POS2
  before_railsw_tr.control(&railsw, Trigger::T_LOW, ServoSwitcher::POS2);
  // привязываем стрелку с стоп магниту
  railsw.control(&rail_stop_sw, ServoSwitcher::POS2, ServoSwitcher::POS2);
  // привязываем второй триггер к стрелке  - переключение стрелки в POS1
  after_railsw_tr.control(&railsw, Trigger::T_LOW, ServoSwitcher::POS1);
  // если стрелка в POS1 опускаем стоп магнит
  railsw.control(&rail_stop_sw, ServoSwitcher::POS1, ServoSwitcher::POS1);
  before_railsw_tr.setup();
  railsw.setup();
  after_railsw_tr.setup();
  rail_stop_sw.setup();
  
  delay(2000);
  
}

void loop()
{
  tl.tick();
  before_railsw_tr.tick();
  after_railsw_tr.tick();
}

