#include "Subscriber.h"

class LEDSubscriber : public Subscriber {



public:
    LEDSubscriber(Publisher& p,int oPin, int iPin);
    void update(int value) override;
    void handleInput() override;
};