#include "LEDSubscriber.h"
#include <Arduino.h>

LEDSubscriber::LEDSubscriber(Publisher& p,int pin) : Subscriber(p,pin) {

}

void LEDSubscriber::update(int value) {
    Serial.println("Updating LED");
    digitalWrite(pin, value);
}