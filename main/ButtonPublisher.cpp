#include "ButtonPublisher.h"
#include <Arduino.h>

//Constructor

ButtonPublisher::ButtonPublisher(int pin) : Publisher(pin) {

}


void ButtonPublisher::handleInput() {
    //Currently we hard code the *255 however later on we might want to change this by adding the range as a parameter
    int modifier = 30;
    int val = digitalRead(pin) * modifier;
    if(val != value){
        setValue(val*modifier);
    }
}