#include <Arduino.h>

void setup() {
    pinMode(0, INPUT_PULLUP);
}

void loop() {
    if(!digitalRead(0)){
        Keyboard.set_key1(39);
    } else {
        Keyboard.set_key1(0);
    }
    Keyboard.send_now();
    delay(100);
}