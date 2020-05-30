#include <IRremote.h>
#include "DigitalOutputController.h"

#define RECV_PIN 5
#define KEY_1         0xFFA25D
#define KEY_1_ALT     0xE318261B
#define KEY_1_COM     "1"
#define KEY_2         0xFF629D
#define KEY_2_ALT     0x511DBB
#define KEY_3         0xEE886D7F
#define KEY_3_ALT     0xFFE21D
#define KEY_4         0x52A3D41F
#define KEY_4_ALT     0xFF22DD
#define KEY_5         0xD7E84B1B
#define KEY_5_ALT     0xFF02FD
#define KEY_6         0x20FE4DBB
#define KEY_6_ALT     0xFFC23D
#define KEY_7         0xF076C13B
#define KEY_7_ALT     0xFFE01F
#define KEY_8         0xA3C8EDDB
#define KEY_8_ALT     0xFFA857
#define KEY_9         0xE5CFBD7F
#define KEY_9_ALT     0xFF906F
#define KEY_STAR      0xC101E57B
#define KEY_STAR_ALT  0xFF6897
#define KEY_0         0x97483BFB
#define KEY_0_ALT     0xFF9867
#define KEY_HASH      0xF0C41643
#define KEY_HASH_ALT  0xFFB04F
#define KEY_UP        0x3D9AE3F7
#define KEY_UP_ALT    0xFF18E7
#define KEY_RIGHT     0x449E79F
#define KEY_RIGHT_ALT 0xFF5AA5
#define KEY_DOWN      0x1BC0157B
#define KEY_DOWN_ALT  0xFF4AB5
#define KEY_LEFT      0x8C22657B
#define KEY_LEFT_ALT  0xFF10EF
#define KEY_OK        0x488F3CBB
#define KEY_OK_ALT    0xFF38C7

class IRReceiver {
  private:
    IRrecv receiver;
    DigitalOutputController* digitalOutputController;
    decode_results results;
    unsigned long lastResult;
    String getCommand(unsigned long* code);
  public:
    IRReceiver(DigitalOutputController* digitalOutputController);
    void onSetup();
    void onLoop();
};
