#include "Publisher.h"
#include <Arduino.h>

Publisher::Publisher(int pin) {
    pinMode(pin, INPUT);
    this->pin = pin;
    value = 0;
    subscriberCount = 0;
}

void Publisher::notify() {
    for(int i = 0;i<subscriberCount;i++){
        subscribers[i]->update(value);
    }
    Serial.println("Notified subscribers");
}

void Publisher::setValue(int value) {
    this->value = value;
    notify();
}

void Publisher::addSubscriber(Subscriber* s) {
    Serial.println("Subscribed");
    if(subscriberCount < MAX_SUBSCRIBERS){
        subscribers[subscriberCount++] = s;
        s->update(value);
    }
    else
        Serial.println("Exceeded Max Subscribers");

}

void Publisher::removeSubscriber(Subscriber* s) {
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





