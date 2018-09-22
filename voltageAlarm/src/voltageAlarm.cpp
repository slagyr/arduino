#include "Arduino.h"

int vIn;

void setup()
{
    Serial.begin(9600);
    //pinMode(23, INPUT);
}

void loop()
{
    vIn = analogRead(0);
    Serial.println(vIn);
    delay(500);
}
