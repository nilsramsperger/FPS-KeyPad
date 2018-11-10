#include <Arduino.h>
#include <usb_keyboard.h>

void setup() {
    pinMode(0, INPUT_PULLUP);
}

void loop() {
    if(!digitalRead(0)){
        Keyboard.set_key0(KEY_0);
    } else {
        Keyboard.set_key0(0);
    }
    Keyboard.send_now();
    delay(100);
}