#include "Arduino.h"
#include "Servo.h"

Servo myservo;

void setup()
{
    Serial.begin(9600);
    myservo.attach(9);
    randomSeed(analogRead(0));
}

void loop() {

    long p = random(160);
    Serial.print("p: ");
    Serial.println(p);
    myservo.write(p);
    delay(1000);

//    Serial.println("0 - 180");
//    for (int pos = 0; pos <= 160; pos += 1) {
//        myservo.write(pos);
//        delay(15);
//    }
//    Serial.print("180 - 0");
//    for (int pos = 160; pos >= 0; pos -= 1) {
//        myservo.write(pos);
//        delay(15);
//    }
}
