#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN D3 // Пин, к которому подключен DIN
#define NUM_PIXELS 256 // Количество пикселей в матрице

Adafruit_NeoPixel strip(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void initLED() {
    strip.begin();
    strip.show(); 
}

void setLED(short x, short y, short r, short g, short b) {
    Serial.println("SET LED");
    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    Serial.print("color #");

    Serial.print(r, HEX); 
    Serial.print(g, HEX); 
    Serial.print(b, HEX); 
    Serial.println();

    strip.setPixelColor(x * 16 + y, r, g, b);
    strip.show(); 
}