#include "Arduino.h"

uint8_t ledPin = 5;
uint8_t buttonA = 9;
uint8_t buttonB = 8;

bool isPressed(uint8_t pin);

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(buttonA, INPUT_PULLUP);
    pinMode(buttonB, INPUT_PULLUP);
}

void loop() {
    bool aPressed = isPressed(buttonA);
    bool bPressed = isPressed(buttonB);
    Serial.print("aPressed: ");
    Serial.println(aPressed);
    Serial.print("bPressed: ");
    Serial.println(bPressed);
    if (aPressed)
        digitalWrite(ledPin, HIGH);
    if (bPressed)
        digitalWrite(ledPin, LOW);
}

bool isPressed(uint8_t pin) { return digitalRead(pin) == LOW; }