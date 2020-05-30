#include "DigitalOutputController.h"

DigitalOutputController::DigitalOutputController():
  saltLamp(SimpleDigitalOutput(SALT_LAMP_PIN)),
  turbine(SimpleDigitalOutput(TURBINE_PIN)) {
  // no-op
}

void DigitalOutputController::toggleSaltLamp() {
  saltLamp.toggle();
}

void DigitalOutputController::toggleTurbine() {
  turbine.toggle();
}

void DigitalOutputController::onSetup() {
  saltLamp.onSetup();
  turbine.onSetup();
}
