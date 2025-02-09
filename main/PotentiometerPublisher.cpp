#include "PotentiometerPublisher.h"
#include <Arduino.h>

PotentiometerPublisher::PotentiometerPublisher(int pin): Publisher(pin){
}
void PotentiometerPublisher::handleInput() {
    int val = map(analogRead(pin),0,1023,0,255);
    //Added a threshold to the potentiometer to avoid flickering
    if(abs(val - value) >3){
        setValue(val);
        Serial.println("Potentiometer value: ");
        Serial.println(val);
    }
}