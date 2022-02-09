# ESP8266OTA
An ESP8266 Library for easy Over-The-Air code uploading.

## Usage
To use the library, you need to call `ESP8266OTA::init()` in the `setup()`, and `ESP8266OTA::handle()` in the `loop()`, like this:
```cpp
#include <ESP8266OTA.h>

void setup() {
  ESP8266OTA::init("SSID");
}

void loop() {
  ESP8266OTA::handle();
}
```
- ***note:** this begins the serial, with a default baud speed of `115200`. you can change the baud speed, as demonstrated below.*

- ***note:** make sure not to use `delay()`, as this might cause the ESP8266 to miss upload requests! use timers instead.*
*for example:*
```cpp
#include <ESP8266OTA.h>

unsigned long timer1; // timestamp of start

void setup() {
  ESP8266OTA::init("SSID");

  timer1 = millis(); // set timer1 to the current time
}

void loop() {
  ESP8266OTA::handle();

  if (millis() - timer1 > 1000) {
    // 1 second have passed
    // do stuff
  
    timer1 = millis(); // reset timer, so it will run again after one more second.
  }
}
```
