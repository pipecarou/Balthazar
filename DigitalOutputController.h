#include "SimpleDigitalOutput.h"

#define SALT_LAMP_PIN 4
#define TURBINE_PIN 44

class DigitalOutputController {
  private:
    SimpleDigitalOutput saltLamp;
    SimpleDigitalOutput turbine;
  public:
    DigitalOutputController();
    void onSetup();
    void toggleSaltLamp();
    void toggleTurbine();
};
