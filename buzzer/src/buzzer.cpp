#include "Arduino.h"
#include "pitches.h"

uint8_t buzzer = 12;//the pin of the active buzzer

void playActive();

void playTone(unsigned long pause, int duration);

void playPassive();

void note(unsigned int thisNote, unsigned long duration);

void setup() {
    Serial.begin(9600);
    pinMode(buzzer, OUTPUT);
}



void loop() {
    playPassive();

    //    playActive();
}


unsigned long whole = 600;
unsigned long threeQuarters = 450;
unsigned long half = 300;
unsigned long quarter = 150;
unsigned long eigth = 75;

void playPassive() {
    note(NOTE_E5, threeQuarters);
    note(NOTE_D5, quarter);
    note(NOTE_C5, half);
    note(NOTE_D5, half);
    note(NOTE_E5, half);
    note(NOTE_E5, half);
    note(NOTE_E5, whole);
    note(NOTE_D5, half);
    note(NOTE_D5, half);
    note(NOTE_D5, whole);
    note(NOTE_E5, half);
    note(NOTE_G5, half);
    note(NOTE_G5, whole);

    note(NOTE_E5, threeQuarters);
    note(NOTE_D5, quarter);
    note(NOTE_C5, half);
    note(NOTE_D5, half);
    note(NOTE_E5, half);
    note(NOTE_E5, half);
    note(NOTE_E5, half);
    note(NOTE_E5, half);
    note(NOTE_D5, half);
    note(NOTE_D5, half);
    note(NOTE_E5, half);
    note(NOTE_D5, half);
    note(NOTE_C5, half);
    note(NOTE_G5, eigth);
    note(NOTE_F5, eigth);
    note(NOTE_E5, eigth);
    note(NOTE_D5, eigth);
    note(NOTE_C5, whole);

    delay(whole);
}

void note(unsigned int thisNote, unsigned long duration) {
    tone(8, thisNote, duration);
    delay(duration + 10);
}

void playActive() {
    playTone(1, 1000);
    playTone(2, 1000);
    playTone(3, 1000);
    playTone(4, 1000);
    playTone(5, 1000);
    playTone(6, 1000);
    playTone(7, 1000);
    playTone(8, 1000);
    playTone(9, 1000);
    playTone(10, 1000);
    playTone(20, 1000);
    playTone(30, 1000);
    playTone(40, 1000);
    playTone(50, 1000);
    playTone(60, 1000);
    playTone(70, 1000);
    playTone(80, 1000);
    playTone(90, 1000);
    playTone(100, 1000);
}

void playTone(unsigned long pause, int duration) {
    Serial.print("pause: ");
    Serial.println(pause);

    for (int i = 0; i < duration; i += (pause * 2)) {
        digitalWrite(buzzer, HIGH);
        delay(pause);
        digitalWrite(buzzer, LOW);
        delay(pause);
    }
}