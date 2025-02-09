#ifndef SUB_H
#define SUB_H

class Publisher;
class Subscriber {
private:
    Publisher& publisher;
    
protected:
    //This is the output pin
    int outputPin;

    //This is the input pin
    int inputPin;

    //Used for input (subscribing and unsubscribing)
    int value;

    //This is the input pin ( The button while clicked will subscribe to the publisher)
public:
    //Adds this as the base publisher. When we subscribe and unsubscribe it will always be to the same publisher
    Subscriber(Publisher& p,int oPin, int iPin);
    //How it gets updated is up to the subscriber
    //This is called by the publisher
    virtual void update(int value) = 0;
    void subscribe();
    void unSubscribe();
    virtual void handleInput() = 0;
};
#endif