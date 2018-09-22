#include "Arduino.h"
#include "SR04.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define TONE_PIN 10



SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
int missCount;

void setup() {
    Serial.begin(9600);
    missCount = 0;
    delay(100);
}

void loop() {
    long echoDelay = sr04.echoDelay();
    Serial.print(echoDelay);

    if(echoDelay > 1600 || echoDelay < 200) {
        if(missCount >= 5) {
            noTone(TONE_PIN);
        }
        else
            missCount = 0;
        Serial.println();
    }
    else {

//        double percent = echoDelay / 6000.0;
//        auto frequency = (unsigned int) (4978 - (4947 * percent + 31));

        double frequency = (
                        (0.00922 * echoDelay * echoDelay) +
                        (-19.787 * echoDelay) +
                        8088.6);

        Serial.print("\t");
        Serial.println(frequency);

        if(frequency < 31)
            frequency = 31;
        else if(frequency > 4500)
            frequency = 4500;

        tone(TONE_PIN, static_cast<unsigned int>(frequency));
    }

    delay(1000);
}

// echos 100 - 7000
// frequencies = 31 - 4978

// 6000 => 31
// 100 => 4978  3319