#ifndef POT_PUB_H
#define POT_PUB_H
#include "Publisher.h"

class PotentiometerPublisher : public Publisher {

public:
    PotentiometerPublisher(int pin);
    void handleInput() override;
};
#endif