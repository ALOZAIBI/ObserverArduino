#include "ButtonPublisher.h"
#include <Arduino.h>

//Constructor

ButtonPublisher::ButtonPublisher(int pin) : Publisher(pin) {
    pinMode(pin, INPUT);
}


void ButtonPublisher::handleInput() {
    int val = digitalRead(pin);
    if(val != value){
        setValue(val);
    }
}