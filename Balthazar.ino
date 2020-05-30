#include "IRReceiver.h"
#include "KeypadController.h"

IRReceiver* receiver;
//KeypadController keypadController;

DigitalOutputController* digitalOutputController;

void setup() {
  Serial.begin(115200);
  digitalOutputController = new DigitalOutputController();
  digitalOutputController->onSetup();
  receiver = new IRReceiver(digitalOutputController);
  receiver->onSetup();
}

void loop() {
  receiver->onLoop();
  //keypadController.onLoop();
  delay(100);
}
