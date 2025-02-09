#ifndef PUB_H
#define PUB_H
#include "Subscriber.h"

#define MAX_SUBSCRIBERS 10

class Publisher {
protected:
    int pin;

    Subscriber* subscribers[MAX_SUBSCRIBERS];
    //The raw value of the publisher(before any processing)
    int value;
    //We need this since we are using a static array
    int subscriberCount;
    //Calls the update method of all subscribers
    //The notify is abstract since different publishers will process the value differently (button is simple, potentiometer is more complex) 
    virtual void notify()=0;
    void setValue(int value);
public:
    Publisher(int pin);
    void interrupt();
    //Adds a subscriber to the list of subscribers and also calls the update method of the subscriber
    void subscribe(Subscriber* s);
    void unsubscribe(Subscriber* s);
};

#endif