
#include "../header/object.h"
#include "header/data.hxx"
#include "header/sys.hxx"
#include <cstdio>
#include <cstdlib>
#include "header/instruction.hxx"


extern sstack* st1;
extern sstack* st2;
extern sstack* st3;
extern sstack* st4;
extern sstack* st5;
extern sstack* st6;
extern sstack* stf1;
extern sstack* stf2;
extern sstack* stf3;

namespace inst {
class risc {
public:
  bool movs(OperandMetadataBasic_t* metadata);

  bool movl(OperandMetadataBasic_t* metadata);
};

class cisc {
public:
  bool dprintreg(OperandMetadataBasic_t* metadata, double* r0, double* r1, char* s0, char* s1) {


    switch (metadata->FirstRegister) {
      case R0:
        printf("Value: %lf, Address: %p\n", *r0, r0);
        return true;

      case R1:
        printf("Value: %lf, Address: %p\n", *r1, r1);
        return true;

      case S0:
        printf("Value: %s, Address %p\n", s0, s0);
        return true;

      case S1:
        printf("Value: %s, Address: %p\n", s1, s1);
        return true;

      case SST1:
        printf("Char: %s, Double: %lf, Address: %p\n", st1->s, st1->r, st1);
        return true;

      case SST2:
        printf("Char: %s, Double: %lf, Address: %p\n", st2->s, st2->r, st2);
        return true;

      case SST3:
        printf("Char: %s, Double: %lf, Address: %p\n", st3->s, st3->r, st3);
        return true;

      case SST4:
        printf("Char: %s, Double: %lf, Address: %p\n", st4->s, st4->r, st4);
        return true;
      
      case SST5:
        printf("Char: %s, Double: %lf, Address: %p\n", st5->s, st5->r, st5);
        return true;

      case SST6:
        printf("Char: %s, Double: %lf, Address: %p\n", st6->s, st6->r, st6);
        return true;

      case SSTF1:
        printf("Char: %s, Double: %lf, Address: %p\n", stf1->s, stf1->r, stf1);
        return true;

      case SSTF2:
        printf("Char: %s, Double: %lf, Address: %p\n", stf2->s, stf2->r, stf2);
        return true;

      case SSTF3:
        printf("Char: %s, Double: %lf, Address: %p\n", stf3->s, stf3->r, stf3);
        return true;

      default:
        sys::MsgError("Invalid Register", "Instruction.cxx, dprintreg");
    }
    return true;
  }

  bool dprintstk(sstack** stack, char** buffword, unsigned short* sp) {
    if (buffword[1] == NULL) {  sys::MsgError("instruction.cxx, dprintstk", "Invalid Arguments"); }
    short index = atoi(buffword[1]);
    if (stack[index] == NULL) { sys::MsgError("Invalid Address", "STACK Address NULL"); }
    sstack* local = stack[index];
    if (local == NULL) { sys::MsgError("Invalid Address", "STACK Address NULL"); } 
    
    printf("String: %s, Double: %lf, Address: %p\n", local->s, local->r, local);
    printf("STACK PTR: %d\n", *sp);
    return true;
  }
};


}



// C APIs 
extern "C" void dprintregAPI(OperandMetadataBasic_t* metadata) {
    extern double* r0;
    extern double* r1;
    extern char* s0;
    extern char* s1;
    
    inst::cisc CISC;

    CISC.dprintreg(metadata, r0, r1, s0, s1);

    return;
}

extern "C" void dprintstk() {
  extern char** buffer_word;
  extern sstack** stack;
  extern unsigned short* sp;
  inst::cisc CISC;
  CISC.dprintstk(stack, buffer_word, sp);

  return;
}
