#include "IRReceiver.h"
#include "KeypadController.h"

#ifndef IRSENDER_IMPORT
  #define IRSENDER_IMPORT
  #include "IRSender.h"
#endif

IRReceiver* receiver;
KeypadController* keypadController;

IRSender* irSender;

void setup() {
  Serial.begin(115200);
  DigitalOutputController* digitalOutputController = new DigitalOutputController();
  digitalOutputController->onSetup();
  irSender = new IRSender();
  
  receiver = new IRReceiver(digitalOutputController, irSender);
  receiver->onSetup();

  keypadController = new KeypadController(digitalOutputController, irSender);
}

void loop() {
  receiver->onLoop();
  keypadController->onLoop();
}
