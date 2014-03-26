
int in1 = A1;
int ledPin = 13;
int randint;
int inwow = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(in1, INPUT);
  
  digitalWrite(ledPin, LOW);

  attachInterrupt(0, blink1, CHANGE);
  attachInterrupt(1, blink2, CHANGE);
}

void loop() {
  inwow = analogRead(in1);
  if (inwow) {
    Serial.println(inwow);
  }
/*
  randint = random(0, 100);
  if (randint >= 50) {
    Serial.println("Go left!");
  }
  else {
    Serial.println("Go right!");
  }
*/
}  


void blink1() {
  digitalWrite(ledPin, HIGH);
}

void blink2() {
  digitalWrite(ledPin, LOW);
}
