//Uses polling for input

const int redLEDBtnPin = 7;
const int redLEDPin = 11;
//2 3 
const int greenLEDBtnPin = 8;
const int greenLEDPin = 10;

const int blueLEDBtnPin = 6;
const int blueLEDPin = 9;

const int potentiometerPin = A7;

// const int bluePin = 9;
// const int greenPin = 10;
int val = 0;


#include "ButtonPublisher.h"
#include "PotentiometerPublisher.h"

#include "LEDSubscriber.h"

Publisher* potentiometerPublisher;

Subscriber* redLED;

Subscriber* greenLED;

Subscriber* blueLED;



void setup() {
  Serial.begin(9600);

  potentiometerPublisher = new PotentiometerPublisher(potentiometerPin);

  redLED = new LEDSubscriber(*potentiometerPublisher, redLEDPin,redLEDBtnPin);
  greenLED = new LEDSubscriber(*potentiometerPublisher, greenLEDPin,greenLEDBtnPin);
  blueLED = new LEDSubscriber(*potentiometerPublisher, blueLEDPin,blueLEDBtnPin);
  
  Serial.println("Yopo");
}

void loop() {
  potentiometerPublisher->handleInput();

  redLED->handleInput();
  greenLED->handleInput();
  blueLED->handleInput();

  // Serial.println("Digitally reading this ting");
  // Serial.print(digitalRead(redLEDBtnPin));
}
