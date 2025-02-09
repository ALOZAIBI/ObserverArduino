#ifndef BUTTON_PUB_H
#define BUTTON_PUB_H
#include "Publisher.h"

class ButtonPublisher : public Publisher {
public:
    ButtonPublisher(int pin);
    void handleInput() override;
};

#endif