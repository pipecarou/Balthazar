#ifndef IRSENDER_IMPORT
  #define IRSENDER_IMPORT
  #include "IRSender.h"
#endif

IRSender::IRSender():
  irsend(IRsend()) {
  // no-op  
}

void IRSender::sendEdifierCode(unsigned long code) {
  irsend.sendNEC(code, 32);
}

void IRSender::sendLGCode(unsigned long code) {
  irsend.sendNEC(code, 32);
}
