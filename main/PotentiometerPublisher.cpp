#include "PotentiometerPublisher.h"
#include <Arduino.h>

void PotentiometerPublisher::notify() {
    for (Subscriber* s : subscribers) {
        s->update(value);
    }
    Serial.println("Notified subscribers");
}