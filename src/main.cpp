#include <Arduino.h>
#include <WiFiUdp.h>
#include <wifi/wifi.h>
#include <builtin/builtin.h>
#include <server/server.h>

char* ssid = "TP-Link_362C";
char* password = "16192546";

WiFiUDP udp;
String deviceName = "ESP32";

const int udpServerPort = 8888; 


void setup() {
  Serial.begin(9600);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  int err = connectToWifi(ssid, password);
  if (err == -1) {
    Serial.println("wifi connect error");
    return;
  }

  Serial.println("wifi connected");

  udp.begin(udpServerPort);
  Serial.println("udp server started");

  ledPing();
}

void loop() {
  handleUDP(udp);
}