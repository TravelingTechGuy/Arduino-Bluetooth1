Arduino Bluetooth example
=========================

This is my first Arduino bluetooth project, using the Bluetooth HC-05 module.

Operation
---------
Once the Arduino is paired with a client, it accepts the following commands:

+ '1' - turn on red LED
+ '2' - turn on green LED
+ '0' - turn off both LEDs

Video: [A short YouTube video](https://www.youtube.com/watch?v=YswK21ztCtc) showing the board in action.

Components
----------
1. Arduino Uno R3 (or similar)
2. 2 LEDs, one red, one green (or choose your own colors)
3. HC-05 bluetooth module (~$10 on Amazon, less on eBay)
4. Mini breadboard
5. A couple of jumper cables

Connections
-----------
1. LEDs: GND and digital pin10 (red), pin11 (green)
2. HC-05: GND->GND, VCC->3.3V, RX->TX (pin0), TX->RX (pin1)

Client
------
For a bluetooth client, you could use one of the following:

1. The Serial Monitor in the Arduino IDE - make sure you dial it to the right baud rate.
2. On Mac or Linux, use Screen: `screen <deviceid> <baud rate>`
 - the device id would look like /dev/tty.HC-05 - try `ls /dev/tty.*` to find your device.
3. On Android, look for "Arduino Bluetooth Terminal" in the [Play store](https://play.google.com/store/apps/details?id=arduino.bluetooth.terminal&hl=en).
4. On Windows machines, [TeraTerm](http://ttssh2.sourceforge.jp/index.html.en), or [PuTTY](http://www.chiark.greenend.org.uk/~sgtatham/putty/download.html).

Comments
--------
1. The board's pairing code is **'1234'**, not the usual '0000' - requires another manual step on a Mac.
2. While you can set the baud rate to 115200, I did not really need it for this project (since I send one character).
3. For some reason, the Arduino Bluetooth Terminal on Android did not send any data when the baud rate was set to 115200.
