/*
    ESP8266OTA.h - ESP8266 OTA Library
    Created by Mai Porat on %DATE.
    Released into the public domain.
*/

#ifndef ESP8266OTA_h
#define ESP8266OTA_h

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class ESP8266OTAClass {
    public:
        void init(const char *ssid, const char *pass = "", const int serialBaud = 115200);
        void handle();

        static ESP8266OTAClass instance;

    private:
        ESP8266OTAClass();
};

ESP8266OTAClass ESP8266OTA = ESP8266OTAClass::instance;

#endif