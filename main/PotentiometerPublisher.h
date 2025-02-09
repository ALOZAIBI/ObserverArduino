#ifndef POT_PUB_H
#define POT_PUB_H
#include "Publisher.h"

class PotentiometerPublisher : public Publisher {

public:
    void handleInput() override;
};
#endif