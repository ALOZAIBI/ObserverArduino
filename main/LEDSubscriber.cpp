#include "LEDSubscriber.h"
#include <Arduino.h>

LEDSubscriber::LEDSubscriber(Publisher& p,int oPin, int iPin) : Subscriber(p,oPin,iPin) {
    value = LOW;
}

void LEDSubscriber::update(int value) {
    Serial.println("Updating LED");
    analogWrite(outputPin, value);
}

void LEDSubscriber::handleInput() {
    int val = digitalRead(inputPin);
    if(val != value){
        value = val;
        if(value == HIGH)
            subscribe();
        else
            unSubscribe();

        Serial.println("I'm handling input");
    }
}