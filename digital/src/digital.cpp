#include "Arduino.h"

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10 // fading time between colors

// define variables
int redValue;
int greenValue;
int blueValue;

void cycleColors();

void fade(short rMod, short gMod, short bMod);

void setColor(u8 r, u8 g, u8 b);

void setup() {
    Serial.begin(9600);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

}

void loop() {
    Serial.println("Beginning");
    setColor(0, 0, 0);
    cycleColors();
}

void setColor(u8 r, u8 g, u8 b) {
    Serial.print("setColor: ");
    Serial.print(r);
    Serial.print(", ");
    Serial.print(g);
    Serial.print(", ");
    Serial.println(b);
    analogWrite(RED, r);
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}

void cycleColors() {
    Serial.println("red to green");
    fade(-1, 1, 0);
    Serial.println("green to blue");
    fade(0, -1, 1);
    Serial.println("blue to red");
    fade(1, 0, -1);
}

void fade(short rMod, short gMod, short bMod) {
    short r = rMod == -1 ? 255 : 0;
    short g = gMod == -1 ? 255 : 0;
    short b = bMod == -1 ? 255 : 0;
    for (int i = 0; i < 255; i++) {
        r += rMod;
        g += gMod;
        b += bMod;
        setColor(r, g, b);
    }
    delay(delayTime);
}

