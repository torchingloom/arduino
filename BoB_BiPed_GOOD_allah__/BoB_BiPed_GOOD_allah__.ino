// http://www.bajdi.com
// Bob the biped
// Basic walking gait code

#include <Servo.h>
// 6 servos
Servo leftFootServo;
Servo leftHipServo;
Servo rightFootServo;
Servo rightHipServo;
// Servo leftArmServo;
// Servo rightArmServo;

const int offset = 25;//how many degrees we want to move the servos
const int offsetarm = 42;
/* CENTRE POSITION view on face and top!!!
right edge UP
leftFoot  VALUE down (-)
rightFoot  VALUE down (-)
clockwise HIP
leftHip VALUE up (+)
rightHip  VALUE up (+)
*/
// Servo positions
// Left foot servo
const int leftFootC = 128;  // centered
const int leftFootD = leftFootC-offset-5; // foot down
const int leftFootU = leftFootC+offset-3; // foot up

// Left hip servo
const int leftHipC = 132; // centered
const int leftHipL = leftHipC-offset; // hip left
const int leftHipR = leftHipC+offset; // hip right

// Right foot servo
const int rightFootC = 135;
const int rightFootD = rightFootC+offset+5;
const int rightFootU = rightFootC-offset;

// Right hip servo
const int rightHipC = 128;
const int rightHipL = rightHipC+offset-7;
const int rightHipR = rightHipC-offset;

// Left arm ervo
//const int leftArmC = 124;
//const int leftArmF = leftArmC+offsetarm;
//const int leftArmB = leftArmC-offsetarm;

//Right arm servo
//const int rightArmC = 136;
//const int rightArmF = rightArmC+offsetarm;
//const int rightArmB = rightArmC-offsetarm;

// Servo positions we want the servo to move to (in small steps)
float leftFootPos;
float leftHipPos;
float rightFootPos;
float rightHipPos;
//float leftArmPos;
//float rightArmPos;

// Servo postions written to the servos
float leftFootPosInt = leftFootC;
float leftHipPosInt = leftHipC;
float rightFootPosInt = rightFootC;
float rightHipPosInt = rightHipC;
//float leftArmPosInt = leftArmC;
//float rightArmPosInt = rightArmC;

// Calculated values for moving servos in small steps (position we want to move to - current servo position / steps)
float leftFootStep;
float leftHipStep;
float rightFootStep;
float rightHipStep;
// float leftArmStep;
// float rightArmStep;

const int steps = 10  ;  // divide every servo move in 20 steps
byte speed = 40;  // time between steps
unsigned long SuperTurboTimer;
byte SuperTurboStep = 1;
unsigned long SuperTurboMillis;
unsigned long timer;
byte direction;
byte legInStep = 1;

//const int Trig = 7;
//const int Echo = 8;
//float time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//float distance_sm=time_us/58; // Пересчитываем в сантиметры

void setup()
{
//  pinMode(Trig, OUTPUT);
//  pinMode(Echo, INPUT);
  leftFootServo.write(leftFootC);
  leftFootServo.attach(11);
  leftHipServo.write(leftHipC);
  leftHipServo.attach(10);
  rightFootServo.write(rightFootC);
  rightFootServo.attach(9);
  rightHipServo.write(rightHipC);
  rightHipServo.attach(6);
//  leftArmServo.write(leftArmC);
//  leftArmServo.attach(5);
//  rightArmServo.write(rightArmC);
//  rightArmServo.attach(6);
  delay(1000);
}

void loop()
{
  // direction = 0; //stopped
  // direction = 1; // forward
  // direction = 2; // backward
  // direction = 3; // left
  // direction = 4; // right
  direction = 1;
  walk();
}

// This function makes Bob walk <img class="wp-smiley" alt=":)" src="http://www.bajdi.com/wp-includes/images/smilies/icon_smile.gif"> 
void walk()
{
  SuperTurboMillis = millis();

  if (SuperTurboMillis >= timer) 
  {
    timer = timer+speed;

    legInStep = legInStep + 1;
    if (legInStep == steps + 1)
    {
      legInStep = 1;
    }
    if (legInStep == 1)
    {
      leftFootStep = (leftFootPos - leftFootPosInt) / steps;
      leftHipStep = (leftHipPos - leftHipPosInt) / steps;
      rightFootStep = (rightFootPos - rightFootPosInt) / steps;
      rightHipStep = (rightHipPos - rightHipPosInt) / steps;
//      leftArmStep = (leftArmPos - leftArmPosInt) / steps;
//      rightArmStep = (rightArmPos - rightArmPosInt) / steps;
    }

    leftFootPosInt = leftFootPosInt + leftFootStep;
    leftHipPosInt = leftHipPosInt + leftHipStep;
    rightFootPosInt = rightFootPosInt + rightFootStep;
    rightHipPosInt = rightHipPosInt + rightHipStep;
//    leftArmPosInt = leftArmPosInt + leftArmStep;
//    rightArmPosInt = leftArmPosInt + leftArmStep;
  }

  if (SuperTurboMillis >= SuperTurboTimer){
    SuperTurboTimer = SuperTurboTimer+(steps*speed);
    SuperTurboStep = SuperTurboStep +1;
    if (SuperTurboStep == 7){
      SuperTurboStep = 1;
    }
  }

  if (direction == 0)  // stop, both feet on the ground
  {
    leftFootPos = leftFootC;
    leftHipPos = leftHipC;
    rightFootPos = rightFootC;
    rightHipPos = rightHipC;
//    leftArmPos = leftArmC;
//    rightArmPos = rightArmC;
  }

  if (direction == 1)     // forward walking gait
  {
    
    if (SuperTurboStep == 1)
    {
      
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
//      leftArmPos = leftArmF;
//      rightArmPos = rightArmB;
      
}


    if (SuperTurboStep == 2)
    {
      leftHipPos = leftHipL;
      rightHipPos = rightHipR;
    }
    
    
    if (SuperTurboStep == 3)
    {
      
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
      
    }


    if (SuperTurboStep == 4)
    {
      
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
//      leftArmPos = leftArmB;
//      rightArmPos = rightArmF;
      
      
    }


    if (SuperTurboStep == 5)
    {
      leftHipPos = leftHipR;
      rightHipPos = rightHipL;
    }


    if (SuperTurboStep == 6)
    {
      
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
  //    leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
      
      
  }
  }
  if (direction == 2)     // backward walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
 //     leftArmPos = leftArmF;
//      rightArmPos = rightArmB;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

    if (SuperTurboStep == 2)
    {
      leftHipPos = leftHipR;
      rightHipPos = rightHipL;
    }

    if (SuperTurboStep == 3)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
//      leftArmPos = leftArmB;
//      rightArmPos = rightArmF;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

    if (SuperTurboStep == 5)
    {
      leftHipPos = leftHipL;
      rightHipPos = rightHipR;
    }

    if (SuperTurboStep == 6)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры


    }
  }

  if (direction == 3)     // left walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
//      leftArmPos = leftArmF;
//      rightArmPos = rightArmB;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }
    if (SuperTurboStep == 2)
    {
      leftHipPos = leftHipL+15;
      rightHipPos = rightHipL;
    }
    if (SuperTurboStep == 3)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }
    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
//      leftArmPos = leftArmB;
//      rightArmPos = rightArmF;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

    if (SuperTurboStep == 5)
    {
      leftHipPos = leftHipR-15;
      rightHipPos = rightHipR+15;
    }
    if (SuperTurboStep == 6)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }
  }

  if (direction == 4)     // right walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
//      leftArmPos = leftArmF;
//      rightArmPos = rightArmB;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }
    if (SuperTurboStep == 2)
    {
      leftHipPos = leftHipR-5;
      rightHipPos = rightHipR+10;//левая перестала наступать на правую, правая поворачивает направо не так сильно//
    }
    if (SuperTurboStep == 3)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }
    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
//      leftArmPos = leftArmB;
//      rightArmPos = rightArmF;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

    if (SuperTurboStep == 5)
    {
      leftHipPos = leftHipL+10;
      rightHipPos = rightHipL-10;//то же  что и при повороте направо//
    }
    if (SuperTurboStep == 6)
    {
      leftFootPos = leftFootC;
      rightFootPos = rightFootC;
//      leftArmPos = leftArmC;
//      rightArmPos = rightArmC;
//      digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
//delayMicroseconds(10); // Удерживаем 10 микросекунд
//digitalWrite(Trig, LOW); // Затем убираем
//time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
//distance_sm=time_us/58; // Пересчитываем в сантиметры

    }

  }
  leftFootServo.write(leftFootPosInt);
  leftHipServo.write(leftHipPosInt);
  rightFootServo.write(rightFootPosInt);
  rightHipServo.write(rightHipPosInt);
//  leftArmServo.write(leftArmPosInt);
//  rightArmServo.write(rightArmPosInt);
}


