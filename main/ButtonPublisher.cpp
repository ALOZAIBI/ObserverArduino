#include "ButtonPublisher.h"
#include <Arduino.h>

//Constructor

ButtonPublisher::ButtonPublisher(int pin) : Publisher(pin) {
    pinMode(pin, INPUT);
}


void ButtonPublisher::notify() {
    for(int i = 0;i<subscriberCount;i++){
        subscribers[i]->update(value);
    }
    Serial.println("Notified subscribers");
}