#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 7
#define TxD 6

#define DEBUG_ENABLED  1

SoftwareSerial BT(RxD,TxD);

unsigned int waitng = 0;

void setup()
{ 
  Serial.begin(9600);
  bt_setup();
}

void loop() 
{
  waitng++;
  BT.print("Test ");
  BT.println(waitng);
  delay(1000);
}

void bt_setup() {
  BT.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  BT.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  BT.print("\r\n+STNA=SeeedBTSlave\r\n"); //set the bluetooth name as "SeeedBTSlave"
  BT.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  BT.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here

//  BT.print("\r\n+STECHO=1\r\n");

  delay(2000); // This delay is required.

  BT.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable 
  
  //delay(2000); // This delay is required.
  
  //BT.flush();
 
  Serial.print("\n\rWe test BT "); 
  
  while (!BT.available()) {
    delay(1000);
    waitng++;
    if (waitng > 9) {
      waitng = 0;
      break;
    }
    Serial.print("."); 
  }  
  
  
  if (BT.available()) {
    Serial.println("connecting");
    BT.println("Hello, world?");
  }
  else {
    Serial.println("fuck up!");
  }
  
  waitng = 0;
}
