# ESP8266OTA
An ESP8266 Library for easy Over-The-Air code uploading.

## Usage
```cpp
#include <ESP8266OTA.h>

void setup() {
  ESP8266OTA.init();
}

void loop() {
  ESP8266OTA.handle();
}
```

***note:** make sure not to use `delay()`, as this might cause the ESP8266 to miss upload requests! use timers instead, as shown below:*
```cpp
  // to be added
```
