#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 7
#define TxD 6

#define DEBUG_ENABLED  1
#define MAX_BITS 100                 // max number of bits 
#define WEIGAND_WAIT_TIME  3000      // time to wait for another weigand pulse.  

unsigned char databits[MAX_BITS];    // stores all of the data bits
unsigned char bitCount;              // number of bits currently captured
unsigned char flagDone;              // goes low when data is currently being captured
unsigned int weigand_counter;        // countdown until we assume there are no more bits

unsigned long facilityCode = 0;        // decoded facility code
unsigned long cardCode = 0;            // decoded card code
unsigned int waitng = 0;

long cards[3] = {37323, 19188, 60892};
String catds_title[3] = {"Card ONE", "Card TWO", "CARD THREE"};

SoftwareSerial BT(RxD,TxD);

void setup() { 
  Serial.begin(9600);
  bt_setup();  

  pinMode(13, OUTPUT);  // LED
  pinMode(2, INPUT);     // DATA0 (INT0)
  pinMode(3, INPUT);     // DATA1 (INT1)

  attachInterrupt(0, ISR_INT0, FALLING);  
  attachInterrupt(1, ISR_INT1, FALLING);

  weigand_counter = WEIGAND_WAIT_TIME;    
}

void loop() {
  if (!flagDone) {
    if (--weigand_counter == 0)
      flagDone = 1;	
  }

  if (bitCount > 0 && flagDone) {
    unsigned char i;
    
    if (Serial) {
      Serial.print("Read ");
      Serial.print(bitCount);
      Serial.print(" bits. ");
    }
    
    if (bitCount == 26) {
      for (i=1; i<9; i++) {
        facilityCode <<=1;
        facilityCode |= databits[i];
      }
      for (i=9; i<25; i++) {
        cardCode <<= 1;
        cardCode |= databits[i];
      }
      
      /* juju start */
      digitalWrite(13, LOW); 
      delay(100);            
      digitalWrite(13, HIGH);
      delay(100);           
      digitalWrite(13, LOW);
      delay(100);            
      digitalWrite(13, HIGH);
      delay(100);
      /* juju end */
      
      printBits();
    }
    else {
      if (Serial) {
        Serial.println("Unable to decode."); 
      }
    } 

    bitCount = 0;
    facilityCode = 0;
    cardCode = 0;
    for (i=0; i<MAX_BITS; i++) {
      databits[i] = 0;
    }
  }
}

void printBits() {
  int index = -1;
  for (int i = 0; i < sizeof(cards) - 1; i++) {
    if (cards[i] == cardCode) {
      index = i;
      break;
    }
  }  
  
  if (Serial) {
    Serial.print("FC = ");
    Serial.print(facilityCode);
    Serial.print(", CC = ");
    Serial.print(cardCode);
    Serial.print(", Find - ");
    if (index < 0) {
      Serial.println("not find");
    }
    else {
      Serial.println(catds_title[index]);
    }
  }

  if (BT.available()) {
    BT.print("FC = ");
    BT.print(facilityCode);
    BT.print(", CC = ");
    BT.print(cardCode);
    BT.print(", Find - ");
    if (index < 0) {
      BT.println("not find");
    }
    else {
      BT.println(catds_title[index]);
    }
  }
} 

void bt_setup() {
  BT.begin(9600);
  BT.print("\r\n+STWMOD=0\r\n");
  BT.print("\r\n+STNA=helper\r\n");
  BT.print("\r\n+STOAUT=1\r\n");
  BT.print("\r\n+STAUTO=0\r\n");
  delay(2000);
  BT.print("\r\n+INQ=1\r\n");
}

void ISR_INT0() {
  bitCount++;
  flagDone = 0;
  weigand_counter = WEIGAND_WAIT_TIME;
}

void ISR_INT1() {
  databits[bitCount] = 1;
  bitCount++;
  flagDone = 0;
  weigand_counter = WEIGAND_WAIT_TIME;  
}

