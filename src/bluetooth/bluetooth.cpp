#include <SoftwareSerial.h>

#define TXD D7
#define RXD D8

SoftwareSerial btSerial(RXD, TXD);

void initBluetooth() {
    btSerial.begin(38400);
}

void bluetoothHandle() {
     if (btSerial.available() > 0) {    // проверим, отправляет ли модуль bluetooth какие-то данные в esp8266
        char data = btSerial.read();  // считать данные из HC-05
        Serial.print("bluetooth input: ");
        Serial.println(data);

        btSerial.write(btSerial.read());
    }
}