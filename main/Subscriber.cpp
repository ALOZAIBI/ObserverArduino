#include "Subscriber.h"

#include "Publisher.h"
#include <Arduino.h>

Subscriber::Subscriber(Publisher& p, int oPin,int iPin) : publisher(p), outputPin(oPin), inputPin(iPin){
    pinMode(oPin, OUTPUT);
    pinMode(iPin, INPUT);
}

void Subscriber::subscribe() {
    // Serial.println("I SHOULD BE SUBSCRIBED");
    publisher.addSubscriber(this);
}

void Subscriber::unSubscribe() {
    // Serial.println("I SHOULD BE UNSUBSCRIBED");
    publisher.removeSubscriber(this);
}