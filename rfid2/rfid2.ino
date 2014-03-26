

#define  CLK  2
#define  OUT  3
#define  MOD  4
#define  SHD  8

boolean val = false;
unsigned char count,bitno,i;
char sequ[10];
char* cadena;

/*
 Init() function
*/
void setup()
{
  // global variables
  count = bitno = 0;
  cadena = sequ;
  for (i=0;i<10;i++) sequ=0;
  
  // i/o setting
  pinMode(CLK,INPUT);
  pinMode(OUT,INPUT);
  pinMode(MOD,OUTPUT);
  pinMode(SHD,OUTPUT);

  // em4095
  digitalWrite(MOD,HIGH);
  digitalWrite(SHD,HIGH);
  delay(100);
  digitalWrite(SHD,LOW);
  digitalWrite(MOD,LOW);

  
  // UART
  Serial.begin(9600);
  Serial.println("em4095 RFid reader for ARDUINO");

  // interrupts
  attachInterrupt(0,rf_clock,RISING);
}

void loop()
{
  // process header
  if (!(sequ[0] & 0xff) || !(sequ[1] & 0x01))
  {
    detachInterrupt(0);
    count = bitno = 0;
    cadena = sequ;
    for (i=0;i<10;i++) sequ = 0;
    led.on();
    Serial.print("Bad header: ");
    Serial.print(sequ[0],HEX);
    Serial.print(",");
    Serial.print(sequ[1],HEX);
    Serial.println();
    delay(100);
    led.off();
    attachInterrupt(0,rf_clock,RISING);
  }

  // process frame
  if (count >= 64)
  {
    detachInterrupt(0);
    cadena = sequ;
    count = bitno = 0;

    for (i=0;i<8;i++) 
    {
      Serial.print(sequ,DEC);
      Serial.print(",");
    }
    Serial.println();    
    
    led.blink(500,2);
    
    for (i=0;i<10;i++) sequ = 0;
  

    delay(1000);
    attachInterrupt(0,rf_clock,RISING);
  }
}

/*
 interrupt routine
  loads the bits array
*/
void rf_clock()
{
  val = !digitalRead(OUT);
  bitWrite(*cadena,bitno,val);
  count++;
  bitno++;
  if (bitno == 8)
  {
    cadena ++;
    bitno = 0;
  }
}
