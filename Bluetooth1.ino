#include <SoftwareSerial.h>
#define RED 10
#define GREEN 11
#define BAUD 9600

SoftwareSerial bluetooth(0, 1); // RX, TX
int BluetoothData;

void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(BAUD);
  Serial.begin(BAUD);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (bluetooth.available())
   {
     BluetoothData=bluetooth.read();
     
     switch(BluetoothData) {
       case '0':
         Serial.println("Both Off");
         digitalWrite(RED, LOW);
         digitalWrite(GREEN, LOW);
         break;
       case '1':
         Serial.println("Red On");
         digitalWrite(RED, HIGH);
         break;
       case '2':
         Serial.println("Green On");
         digitalWrite(GREEN, HIGH);
         break;
       default:
         break;
     }
   }
   delay(100);
}
