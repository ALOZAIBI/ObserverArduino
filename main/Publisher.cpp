#include "Publisher.h"
#include <Arduino.h>

Publisher::Publisher(int pin) {
    this->pin = pin;
    value = 0;
    subscriberCount = 0;
}

void Publisher::setValue(int value) {
    this->value = value;
    notify();
}

void Publisher::subscribe(Subscriber* s) {
    Serial.println("Subscribed");
    if(subscriberCount < MAX_SUBSCRIBERS){
        subscribers[subscriberCount++] = s;
        s->update(value);
    }
    else
        Serial.println("Exceeded Max Subscribers");

    
}

void Publisher::unsubscribe(Subscriber* s) {
    Serial.print("Subscriber countaa: ");
    Serial.print(subscriberCount);
    Serial.println("Unsubscribed");
    for(int i = 0;i<subscriberCount;i++){
        //Shift all after s to the left
        if(subscribers[i] == s){
            for(int j = i;j<subscriberCount-1;j++){
                subscribers[j]=subscribers[j+1];
            }
            subscribers[--subscriberCount] = nullptr;
            return;
        }
    }
}

void Publisher::interrupt() {
    setValue(digitalRead(pin));
}



