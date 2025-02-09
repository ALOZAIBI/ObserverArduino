const int redLEDBtnPin = 7;
const int redLEDPin = 11;
//2 3 
const int greenLEDBtnPin = 6;
const int greenLEDPin = 10;

const int blueLEDBtnPin = 8;
const int blueLEDPin = 9;

const int publisherBtn = 2;
// const int bluePin = 9;
// const int greenPin = 10;
int val = 0;

#include "ButtonPublisher.h"

#include "LEDSubscriber.h"

Publisher* btnPublisher;

bool redLEDBtnClicked = false;
Subscriber* redLED;

bool greenLEDBtnClicked = false;
Subscriber* greenLED;

bool blueLEDBtnClicked = false;
Subscriber* blueLED;


void interrupt(){
  Serial.println("INTERRUPT");
  btnPublisher->interrupt();
}

void redListening(){
  redLEDBtnClicked = !redLEDBtnClicked;
  Serial.print("RED Status");
  Serial.println(redLEDBtnClicked);
  if(redLEDBtnClicked)
    redLED->getSubscribed();
  else
    redLED->getUnsubscribed();
}

void greenListening(){
  greenLEDBtnClicked = !greenLEDBtnClicked;
  Serial.print("GREEN Status");
  Serial.println(greenLEDBtnClicked);
  if(greenLEDBtnClicked)
    greenLED->getSubscribed();
  else
    greenLED->getUnsubscribed();
}

void blueListening(){
  blueLEDBtnClicked = !blueLEDBtnClicked;
  Serial.print("BLUE Status");
  Serial.println(blueLEDBtnClicked);
  if(blueLEDBtnClicked)
    blueLED->getSubscribed();
  else
    blueLED->getUnsubscribed();
}


void setup() {
  Serial.begin(9600);
  pinMode(redLEDBtnPin, INPUT);
  pinMode(greenLEDBtnPin, INPUT);
  pinMode(blueLEDBtnPin, INPUT);
  pinMode(publisherBtn, INPUT);



  btnPublisher = new ButtonPublisher(publisherBtn);

  redLED = new LEDSubscriber(*btnPublisher, redLEDPin);
  greenLED = new LEDSubscriber(*btnPublisher, greenLEDPin);
  blueLED = new LEDSubscriber(*btnPublisher, blueLEDPin);
  
  Serial.println("Yopo");


  attachInterrupt(digitalPinToInterrupt(publisherBtn), interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(redLEDBtnPin), redListening, CHANGE);
  attachInterrupt(digitalPinToInterrupt(greenLEDBtnPin), greenListening, CHANGE);
  attachInterrupt(digitalPinToInterrupt(blueLEDBtnPin), blueListening, CHANGE);
}

void loop() {

}
