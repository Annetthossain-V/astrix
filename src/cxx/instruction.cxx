
#include "../header/object.h"
#include "header/data.hxx"
#include "header/sys.hxx"
#include <cstdio>
#include <cstdlib>
#include "header/instruction.hxx"




namespace inst {
class risc {
public:
  bool movs(OperandMetadataBasic_t* metadata);

  bool movl(OperandMetadataBasic_t* metadata);
};

class cisc {
public:
  bool dprintreg(OperandMetadataBasic_t* metadata, double* r0, double* r1, char* s0, char* s1) {
    sstack* sst1 = GetstRegister(ST1);
    sstack* sst2 = GetstRegister(ST2);
    sstack* sst3 = GetstRegister(ST3);
    sstack* sst4 = GetstRegister(ST4);
    sstack* sst5 = GetstRegister(ST5);
    sstack* sst6 = GetstRegister(ST6);
    sstack* sstf1 = GetstRegister(STF1);
    sstack* sstf2 = GetstRegister(STF2);
    sstack* sstf3 = GetstRegister(STF3);

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
        printf("Char: %s, Double: %lf, Address: %p\n", sst1->s, sst1->r, sst1);
        return true;

      case SST2:
        printf("Char: %s, Double: %lf, Address: %p\n", sst2->s, sst2->r, sst2);
        return true;

      case SST3:
        printf("Char: %s, Double: %lf, Address: %p\n", sst3->s, sst3->r, sst3);
        return true;

      case SST4:
        printf("Char: %s, Double: %lf, Address: %p\n", sst4->s, sst4->r, sst4);
        return true;
      
      case SST5:
        printf("Char: %s, Double: %lf, Address: %p\n", sst5->s, sst5->r, sst5);
        return true;

      case SST6:
        printf("Char: %s, Double: %lf, Address: %p\n", sst6->s, sst6->r, sst6);
        return true;

      case SSTF1:
        printf("Char: %s, Double: %lf, Address: %p\n", sstf1->s, sstf1->r, sstf1);
        return true;

      case SSTF2:
        printf("Char: %s, Double: %lf, Address: %p\n", sstf2->s, sstf2->r, sstf2);
        return true;

      case SSTF3:
        printf("Char: %s, Double: %lf, Address: %p\n", sstf3->s, sstf3->r, sstf3);
        return true;

      default:
        sys::MsgError("Invalid Register", "Instruction.cxx, dprintreg");
    }
    return true;
  }

  bool dprintstk(sstack** stack, char** buffword, unsigned short* sp) {
    if (buffword[1] == NULL) {  sys::MsgError("instruction.cxx, dprintstk", "Invalid Arguments"); }
    short index = atoi(buffword[1]);
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
    double* r0 = get_r0();
    double* r1 = get_r1();
    char* s0 = get_s0();
    char* s1 = get_s1();
    
    inst::cisc CISC;

    CISC.dprintreg(metadata, r0, r1, s0, s1);

    return;
}

extern "C" void dprintstk() {
  char** Buffword = Get_buffer_word();
  sstack** stk = getstack();
  unsigned short* sp = GetSp();
  inst::cisc CISC;
  CISC.dprintstk(stk, Buffword, sp);

  return;
}
