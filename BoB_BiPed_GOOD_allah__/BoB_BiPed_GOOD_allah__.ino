// http://www.bajdi.com
// Bob the biped
// Basic walking gait code

#include <Servo.h>

int incoming = 0;


// 6 servos
Servo leftFootServo;
Servo leftHipServo;
Servo rightFootServo;
Servo rightHipServo;

const int offset = 25;//how many degrees we want to move the servos
const int offsetarm = 42;

/* 
CENTRE POSITION view on face and top!!!
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


// Servo positions we want the servo to move to (in small steps)
float leftFootPos;
float leftHipPos;
float rightFootPos;
float rightHipPos;

// Servo postions written to the servos
float leftFootPosInt = leftFootC;
float leftHipPosInt = leftHipC;
float rightFootPosInt = rightFootC;
float rightHipPosInt = rightHipC;

// Calculated values for moving servos in small steps (position we want to move to - current servo position / steps)
float leftFootStep;
float leftHipStep;
float rightFootStep;
float rightHipStep;

const int steps = 10  ;  // divide every servo move in 20 steps
byte speed = 40;  // time between steps
unsigned long SuperTurboTimer;
byte SuperTurboStep = 1;
unsigned long SuperTurboMillis;
unsigned long timer;
byte direction;
byte legInStep = 1;

void setup()
{
  Serial.begin(9600);
  leftFootServo.write(leftFootC);
  leftFootServo.attach(11);
  leftHipServo.write(leftHipC);
  leftHipServo.attach(10);
  rightFootServo.write(rightFootC);
  rightFootServo.attach(9);
  rightHipServo.write(rightHipC);
  rightHipServo.attach(6);
  delay(1000);
}

void loop()
{
  // direction = 0; //stopped
  // direction = 1; // forward
  // direction = 2; // backward
  // direction = 3; // left
  // direction = 4; // right
//  direction = 1;

  incoming = Serial.read();
  if (incoming > 0)
  {
    switch (incoming)
    {
      case 49:
        direction = 1;
        break;
      case 50:
        direction = 2;
        break;
      case 51:
        direction = 3;
        break;
      case 52:
        direction = 4;
        break;
      default:
        direction = 0;
        break;
    }  
  }
  Serial.println(direction);  
//  walk();
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
    }

    leftFootPosInt = leftFootPosInt + leftFootStep;
    leftHipPosInt = leftHipPosInt + leftHipStep;
    rightFootPosInt = rightFootPosInt + rightFootStep;
    rightHipPosInt = rightHipPosInt + rightHipStep;
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
  }

  if (direction == 1)     // forward walking gait
  {
    
    if (SuperTurboStep == 1)
    {
      
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
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
    }


    if (SuperTurboStep == 4)
    {
      
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
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
    }
  }
  
  if (direction == 2)     // backward walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
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
    }

    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
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
    }
  }

  if (direction == 3)     // left walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
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
    }

    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
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
    }
  }

  if (direction == 4)     // right walking gait
  {
    if (SuperTurboStep == 1)
    {
      leftFootPos = leftFootU;
      rightFootPos = rightFootD;
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
    }
    if (SuperTurboStep == 4)
    {
      leftFootPos = leftFootD;
      rightFootPos = rightFootU;
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
    }

  }
  leftFootServo.write(leftFootPosInt);
  leftHipServo.write(leftHipPosInt);
  rightFootServo.write(rightFootPosInt);
  rightHipServo.write(rightHipPosInt);
}
