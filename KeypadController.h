#include <Keypad.h>

#ifndef IRSENDER_IMPORT
  #define IRSENDER_IMPORT
  #include "IRSender.h"
#endif

#ifndef DOC_GUARD
  #define DOC_GUARD
  #include "DigitalOutputController.h"
#endif

class KeypadController {
  private:
    Keypad pad;
    DigitalOutputController* digitalOutputController;
    IRSender* irSender;
  public:
    KeypadController(
      DigitalOutputController* digitalOutputController,
      IRSender* irSender);
    void onLoop();
};
