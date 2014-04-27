#include <SoftwareSerial.h>
#define RED 10
#define GREEN 11
#define BAUD 9600
#define RX 0
#define TX 1

SoftwareSerial bluetooth(RX, TX); // RX, TX
char bluetoothData;
char *instructions = "Available commands:\n1 - Red On\n2 - Green On\n0 - Both Off";

void setup() {
  bluetooth.begin(BAUD);
  bluetooth.println("Ready!");
  bluetooth.println(instructions);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  if (bluetooth.available())
  {
    bluetoothData = bluetooth.read();
    switch (bluetoothData) {
      case '0':
        bluetooth.println("Both Off");
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        break;
      case '1':
        bluetooth.println("Red On");
        digitalWrite(RED, HIGH);
        break;
      case '2':
        bluetooth.println("Green On");
        digitalWrite(GREEN, HIGH);
        break;
      default:
        if (bluetoothData > ' ') { //ignore unprintable characters, below a space
          bluetooth.println(instructions);
        }
        break;
    }
  }
  delay(100);
}
