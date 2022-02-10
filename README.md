# ESP8266OTA
An ESP8266 Library for easy Over-The-Air code uploading. **Under development, not yet ready to use!**

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
- ***note:** this begins the serial, with a default baud speed of `115200`. [how to change the baud speed](https://github.com/MaiTheLord/ESP8266OTA/edit/master/README.md#changing-the-serial-baud-speed)*

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
---

### Setting a password
To set a password for the access point, just pass it as the second parameter of `init()`, like this:
```cpp
ESP8266OTA::init("SSID", "PASS");
```
---

### Changing the serial baud speed
To change the serial baud speed, pass the desired speed as the second parameter of `init()`, or as the third parameter, if using a password:
```cpp
ESP8266OTA::init("SSID", 115200);
```
```cpp
ESP8266OTA::init("SSID", "PASS", 115200);
```
