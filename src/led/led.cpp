#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN D3 
#define NUM_PIXELS 256 
#define WIDTH 16 

Adafruit_NeoPixel strip(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setLED(short x, short y, short r, short g, short b);

void initLED() {
    strip.begin();
    setLED(0, 15, 0, 0, 0);
    strip.show(); 
    strip.setBrightness(50);
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

    if (x % 2 == 0) {
        strip.setPixelColor(x * WIDTH + (WIDTH - 1 - y), r, g, b);
    } else {
        strip.setPixelColor(x * WIDTH + y, r, g, b);
    }
    
    strip.show(); 
}