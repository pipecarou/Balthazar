#include "SimpleDigitalOutput.h"
#include "Arduino.h"

SimpleDigitalOutput::SimpleDigitalOutput(int pin): 
  pin(pin), 
  state(false) {
    // no-op
  }

void SimpleDigitalOutput::onSetup() {
  pinMode(pin, OUTPUT);
}

void SimpleDigitalOutput::toggle() {
  if (state) {
    digitalWrite(pin, LOW);
  } else {
    digitalWrite(pin, HIGH);
  }

  state = !state;
}
