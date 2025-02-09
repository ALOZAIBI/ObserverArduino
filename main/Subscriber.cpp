#include "Subscriber.h"

#include "Publisher.h"
#include <Arduino.h>

Subscriber::Subscriber(Publisher& p, int pin) : publisher(p), pin(pin) {
    pinMode(pin, OUTPUT);
}

void Subscriber::getSubscribed() {
    // Serial.println("I SHOULD BE SUBSCRIBED");
    publisher.subscribe(this);
}

void Subscriber::getUnsubscribed() {
    // Serial.println("I SHOULD BE UNSUBSCRIBED");
    publisher.unsubscribe(this);
}