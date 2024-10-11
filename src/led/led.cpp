#include <Arduino.h>

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
}