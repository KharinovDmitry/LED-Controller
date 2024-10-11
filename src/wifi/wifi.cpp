#include <Arduino.h>
#include <ESP8266WiFi.h>

int tries = 20;

int connectToWifi(char* ssid, char* password) {
    WiFi.begin(ssid, password);

    while (--tries && WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    if (WiFi.status() != WL_CONNECTED)
    {
        return -1;
    }

    Serial.print("local ip: ");
    Serial.println(WiFi.localIP());

    Serial.print("mac address: ");
    Serial.println(WiFi.macAddress());

    return 1;
}