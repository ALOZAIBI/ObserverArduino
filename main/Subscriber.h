#ifndef SUB_H
#define SUB_H

class Publisher;
class Subscriber {
private:
    Publisher& publisher;
    
protected:
    //This is the output pin
    int pin;

    //This is the input pin ( The button while clicked will subscribe to the publisher)
public:
    //Adds this as the base publisher. When we subscribe and unsubscribe it will always be to the same publisher
    Subscriber(Publisher& p,int pin);
    //How it gets updated is up to the subscriber
    virtual void update(int value) = 0;
    void getSubscribed();
    void getUnsubscribed();
};
#endif