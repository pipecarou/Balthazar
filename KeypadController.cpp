#include <Keypad.h>
#include "KeypadController.h"

static const byte ROWS = 4;
    static const byte COLS = 4;
    static byte rowPins[ROWS] = {52, 50, 48, 46}; //connect to the row pinouts of the keypad
    static byte colPins[COLS] = {44, 42, 40, 38}; //connect to the column pinouts of the keypad
    static char keys[ROWS][COLS] = {
      {'1','2','3','A'},
      {'4','5','6','B'},
      {'7','8','9','C'},
      {'*','0','#','D'}
    };

KeypadController::KeypadController(DigitalOutputController* digitalOutputController, IRSender* irSender):
  digitalOutputController(digitalOutputController),
  irSender(irSender),
  pad(Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS )) {
}

void KeypadController::onLoop() {
  char key = pad.getKey();

  if (key) {
    switch(key) {
      case 'A':
        digitalOutputController->toggleSaltLamp();
        break;
      case 'B':
        irSender->sendEdifierCode(EDIFIER_PWR);
        break;
      case 'C':
        irSender->sendLGCode(LG_PWR);
        break;
      case 'D':
        irSender->sendLGCode(LG_QMENU);
        delay(1000);
        irSender->sendLGCode(LG_LEFT);
        delay(3000);
        irSender->sendLGCode(LG_OK);
        delay(1000);
        for (int i = 0; i < 3; i++) {
          irSender->sendLGCode(LG_DOWN);
          delay(1000);
        }
        irSender->sendLGCode(LG_EXIT);
        break;
      case '#':
        irSender->sendEdifierCode(EDIFIER_VOL_UP);
        break;
      case '*':
        irSender->sendEdifierCode(EDIFIER_VOL_DOWN);
        break;
    }
  }
}
