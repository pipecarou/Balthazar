#ifndef IR_IMPORT
  #define IR_IMPORT
  #include <IRremote.h>
#endif

#define EDIFIER_PWR       0x8E7629D
#define EDIFIER_VOL_UP    0x8E7609F
#define EDIFIER_VOL_DOWN  0x8E7926D

#define LG_PWR            0x20DF10EF
#define LG_INPUT          0x20DF10EF
#define LG_UP             0x20DF02FD
#define LG_RIGHT          0x20DF609F
#define LG_DOWN           0x20DF827D
#define LG_LEFT           0x20DFE01F
#define LG_OK             0x20DF22DD
#define LG_QMENU          0x20DFA25D
#define LG_EXIT           0x20DFDA25

class IRSender {
  private:
    IRsend irsend;
  public:
    IRSender();
    void sendEdifierCode(unsigned long code);
    void sendLGCode(unsigned long code);
};
