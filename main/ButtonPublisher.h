#ifndef BUTTON_PUB_H
#define BUTTON_PUB_H
#include "Publisher.h"

class ButtonPublisher : public Publisher {
private:
    void notify() override;
public:
    ButtonPublisher(int pin);
};

#endif