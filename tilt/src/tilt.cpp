#include "Arduino.h"

#define LED 13
#define TILT 2

void setup()
{
    Serial.begin(9600);
    pinMode(LED,OUTPUT);
    pinMode(TILT,INPUT_PULLUP);
}

void loop()
{
    int tiltValue = digitalRead(TILT);
    Serial.print("tiltValue: ");
    Serial.println(tiltValue);
    if(HIGH == tiltValue)
        digitalWrite(LED,LOW);
    else
        digitalWrite(LED,HIGH);
}