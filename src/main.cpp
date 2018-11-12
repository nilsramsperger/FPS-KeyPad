#include <Arduino.h>

#define BUTTON_1 0
#define BUTTON_2 1
#define BUTTON_3 2
#define BUTTON_4 3
#define BUTTON_5 4
#define BUTTON_6 5
#define BUTTON_7 6
#define BUTTON_8 7
#define BUTTON_9 8
#define BUTTON_10 9
#define BUTTON_11 10
#define BUTTON_12 11
#define BUTTON_13 12

void processPinkyButtons();
void processRingButtons();
void processMiddleButtons();
void processIndexButtons();
void processThumbButtons();
boolean isPressed(uint8_t button);

void setup() {
    pinMode(BUTTON_1, INPUT_PULLUP);
    pinMode(BUTTON_2, INPUT_PULLUP);
    pinMode(BUTTON_3, INPUT_PULLUP);
    pinMode(BUTTON_4, INPUT_PULLUP);
    pinMode(BUTTON_5, INPUT_PULLUP);
    pinMode(BUTTON_6, INPUT_PULLUP);
    pinMode(BUTTON_7, INPUT_PULLUP);
    pinMode(BUTTON_8, INPUT_PULLUP);
    pinMode(BUTTON_9, INPUT_PULLUP);
    pinMode(BUTTON_10, INPUT_PULLUP);
    pinMode(BUTTON_11, INPUT_PULLUP);
    pinMode(BUTTON_12, INPUT_PULLUP);
    pinMode(BUTTON_13, INPUT_PULLUP);
}

void loop() {
    processPinkyButtons();
    processRingButtons();
    processMiddleButtons();
    processIndexButtons();
    processThumbButtons();
    Keyboard.send_now();
    delay(1);
}

void processPinkyButtons() {
    if(isPressed(BUTTON_9)) {
        Keyboard.set_modifier(MODIFIERKEY_LEFT_SHIFT);
    } else if(isPressed(BUTTON_11)) {
        Keyboard.set_modifier(MODIFIERKEY_LEFT_CTRL);
    } else {
        Keyboard.set_modifier(0);
    }
}

void processRingButtons() {
    if(isPressed(BUTTON_1)) {
        Keyboard.set_key2(KEY_Q);
    } else if(isPressed(BUTTON_5)) {
        Keyboard.set_key2(KEY_A);
    } else {
        Keyboard.set_key2(0);
    }
}

void processMiddleButtons() {
    if(isPressed(BUTTON_2)) {
        Keyboard.set_key3(KEY_W);
    } else if(isPressed(BUTTON_6)) {
        Keyboard.set_key3(KEY_S);
    } else {
        Keyboard.set_key3(0);
    }
}

void processIndexButtons() {
    if(isPressed(BUTTON_3)) {
        Keyboard.set_key4(KEY_E);
    } else if(isPressed(BUTTON_4)) {
        Keyboard.set_key4(KEY_R);
    } else if(isPressed(BUTTON_7)) {
        Keyboard.set_key4(KEY_D);
    } else if(isPressed(BUTTON_8)) {
        Keyboard.set_key4(KEY_F);
    } else if(isPressed(BUTTON_10)) {
        Keyboard.set_key4(KEY_C);
    } else {
        Keyboard.set_key4(0);
    }
}

void processThumbButtons() {
    if(isPressed(BUTTON_12)) {
        Keyboard.set_key5(KEY_SPACE);
    } else if(isPressed(BUTTON_13)) {
        Keyboard.set_key5(KEY_B);
    } else {
        Keyboard.set_key5(0);
    }
}

boolean isPressed(uint8_t button) {
    return !digitalRead(button);
}