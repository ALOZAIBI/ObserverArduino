#ifndef PUB_H
#define PUB_H
#include "Subscriber.h"

#define MAX_SUBSCRIBERS 10

class Publisher {
protected:
    //input pin
    int pin;

    Subscriber* subscribers[MAX_SUBSCRIBERS];
    //The value
    int value;
    //We need this since we are using a static array
    int subscriberCount;
    //Calls the update method of all subscribers
    void notify();
    void setValue(int value);
public:
    Publisher(int pin);
    //We update the value if there is a change (The handling of the value is up to the publisher)
    virtual void handleInput() = 0;
    //Adds subscriber and calls update
    void addSubscriber(Subscriber* s);
    //Removes subscriber
    void removeSubscriber(Subscriber* s);
};

#endif