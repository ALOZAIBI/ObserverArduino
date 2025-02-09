#include "PotentiometerPublisher.h"
#include <Arduino.h>

void PotentiometerPublisher::handleInput() {
    int val = analogRead(pin);
    if(val != value){
        setValue(val);
    }
}