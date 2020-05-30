#include <IRremote.h>
#include "IRReceiver.h"

IRReceiver::IRReceiver(DigitalOutputController* digitalOutputController):
  digitalOutputController(digitalOutputController),
  receiver(IRrecv(RECV_PIN)),
  results(decode_results()),
  lastResult(0) {
  // no-op  
}

void IRReceiver::onSetup() {
  receiver.enableIRIn();
}

void IRReceiver::onLoop() {
  if (receiver.decode(&results)) {
      if (results.value == 0xFFFFFFFF) {
        Serial.print("R");
        Serial.println(getCommand(&lastResult));
      } else {
        if (results.value != 0xFF) {
          String command = getCommand(&results.value);
          if (!command.equals("INVALID")) {
            lastResult = results.value;
            Serial.print("R");
            Serial.println(command);
          }
        }
      }
      
      receiver.resume();
    }
  }

String IRReceiver::getCommand(unsigned long* code) {
  switch (*code) {
    case KEY_1:
    case KEY_1_ALT:
      return KEY_1_COM;
      break;
    case KEY_2:
    case KEY_2_ALT:
      return "2";
      break;
    case KEY_3:
    case KEY_3_ALT:
      return "3";
      break;
    case KEY_4:
    case KEY_4_ALT:
      return "4";
      break;
    case KEY_5:
    case KEY_5_ALT:
      return "5";
      break;
    case KEY_6:
    case KEY_6_ALT:
      return "6";
      break;
    case KEY_7:
    case KEY_7_ALT:
      return "7";
      break;
    case KEY_8:
    case KEY_8_ALT:
      return "8";
      break;
    case KEY_9:
    case KEY_9_ALT:
      return "9";
      break;
    case KEY_STAR:
    case KEY_STAR_ALT:
      digitalOutputController->toggleTurbine();
      return "*";
      break;
    case KEY_0:
    case KEY_0_ALT:
      return "0";
      break;
    case KEY_HASH:
    case KEY_HASH_ALT:
      digitalOutputController->toggleSaltLamp();
      return "#";
      break;
    case KEY_UP:
    case KEY_UP_ALT:
      return "^";
      break;
    case KEY_RIGHT:
    case KEY_RIGHT_ALT:
      return ">";
      break;
    case KEY_DOWN:
    case KEY_DOWN_ALT:
      return "v";
      break;
    case KEY_LEFT:
    case KEY_LEFT_ALT:
      return "<";
      break;
    case KEY_OK:
    case KEY_OK_ALT:
      return "OK";
      break;
    default:
      return "INVALID";
  }
}
