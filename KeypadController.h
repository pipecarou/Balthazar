#include <Keypad.h>

//#include "DigitalOutputController.h"

class KeypadController {
  private:
    Keypad pad;
    //DigitalOutputController digitalOutputController;
  public:
    KeypadController(/*DigitalOutputController* digitalOutputController*/);
    void onLoop();
};
