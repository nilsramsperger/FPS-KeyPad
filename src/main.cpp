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

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void processPinkyButtons();
void processRingButtons();
void processMiddleButtons();
void processIndexButtons();
void processThumbButton();
void processModifierButton();
boolean isPressed(uint8_t button);

boolean modifierIsPressed = false;

struct PinkyFinger {
    uint8_t buttons[2] = { BUTTON_9, BUTTON_11 };
    uint16_t keys[2] = { MODIFIERKEY_LEFT_SHIFT, MODIFIERKEY_LEFT_CTRL };
    uint16_t keysModified[2] = { 0, 0 };
} pinkyFinger;

struct RingFinger {
    uint8_t buttons[2] = { BUTTON_1, BUTTON_5 };
    uint16_t keys[2] = { KEY_Q, KEY_A};
    uint16_t keysModified[2] = { 0, 0 };
} ringFinger;

struct MiddleFinger {
    uint8_t buttons[2] = { BUTTON_2, BUTTON_6 };
    uint16_t keys[2] = { KEY_W, KEY_S};
    uint16_t keysModified[2] = { 0, 0 };
} middleFinger;

struct IndexFinger {
    uint8_t buttons[5] = { BUTTON_3, BUTTON_4, BUTTON_7, BUTTON_8, BUTTON_10 };
    uint16_t keys[5] = { KEY_E, KEY_R, KEY_D, KEY_F, KEY_C };
    uint16_t keysModified[5] = { 0, 0, 0 ,0 ,0 };
} indexFinger;

struct Thumb {
    uint8_t buttons[1] = { BUTTON_12 };
    uint16_t keys[1] = { KEY_SPACE };
    uint16_t keysModified[1] = { 0 };
} thumb;

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
    processModifierButton();

    processPinkyButtons();
    processRingButtons();
    processMiddleButtons();
    processIndexButtons();
    processThumbButton();

    Keyboard.send_now();
    delay(1);
}

void processModifierButton() {
    modifierIsPressed = isPressed(BUTTON_13);
}

void processPinkyButtons() {
    for(int i = 0; i < 2; i++){
        if(isPressed(pinkyFinger.buttons[i])){
            Keyboard.set_modifier(modifierIsPressed ? pinkyFinger.keysModified[i] : pinkyFinger.keys[i]);
            return;
        }
    }
    Keyboard.set_modifier(0);
}

void processRingButtons() {
    for(int i = 0; i < 2; i++){
        if(isPressed(ringFinger.buttons[i])){
            Keyboard.set_key1(modifierIsPressed ? ringFinger.keysModified[i] : ringFinger.keys[i]);
            return;
        }
    }
    Keyboard.set_key1(0);
}

void processMiddleButtons() {
    for(int i = 0; i < 2; i++){
        if(isPressed(middleFinger.buttons[i])){
            Keyboard.set_key2(modifierIsPressed ? middleFinger.keysModified[i] : middleFinger.keys[i]);
            return;
        }
    }
    Keyboard.set_key2(0);
}

void processIndexButtons() {
    for(int i = 0; i < 5; i++){
        if(isPressed(indexFinger.buttons[i])){
            Keyboard.set_key3(modifierIsPressed ? indexFinger.keysModified[i] : indexFinger.keys[i]);
            return;
        }
    }
    Keyboard.set_key3(0);
}

void processThumbButton() {
    if(isPressed(thumb.buttons[0])) {
        Keyboard.set_key4(modifierIsPressed ? thumb.keysModified[0] : thumb.keys[0]);
    } 
    else {
        Keyboard.set_key4(0);
    }
}

boolean isPressed(uint8_t button) {
    return !digitalRead(button);
}