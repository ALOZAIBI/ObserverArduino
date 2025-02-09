#include "Subscriber.h"

class LEDSubscriber : public Subscriber {



public:
    LEDSubscriber(Publisher& p,int pin);
    void update(int value) override;
};