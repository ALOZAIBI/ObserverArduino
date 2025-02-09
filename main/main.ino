//Uses polling for input

const int redLEDBtnPin = 7;
const int redLEDPin = 11;
//2 3 
const int greenLEDBtnPin = 8;
const int greenLEDPin = 10;

const int blueLEDBtnPin = 6;
const int blueLEDPin = 9;

const int publisherBtn = 2;
// const int bluePin = 9;
// const int greenPin = 10;
int val = 0;

#include "ButtonPublisher.h"

#include "LEDSubscriber.h"

Publisher* btnPublisher;

Subscriber* redLED;

Subscriber* greenLED;

Subscriber* blueLED;



void setup() {
  Serial.begin(9600);


  btnPublisher = new ButtonPublisher(publisherBtn);

  redLED = new LEDSubscriber(*btnPublisher, redLEDPin,redLEDBtnPin);
  greenLED = new LEDSubscriber(*btnPublisher, greenLEDPin,greenLEDBtnPin);
  blueLED = new LEDSubscriber(*btnPublisher, blueLEDPin,blueLEDBtnPin);
  
  Serial.println("Yopo");
}

void loop() {
  btnPublisher->handleInput();

  redLED->handleInput();
  greenLED->handleInput();
  blueLED->handleInput();

  // Serial.println("Digitally reading this ting");
  // Serial.print(digitalRead(redLEDBtnPin));
}
