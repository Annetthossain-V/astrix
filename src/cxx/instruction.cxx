
#include "../header/object.h"
#include "header/data.hxx"
#include "header/sys.hxx"
#include <cstdio>

namespace inst {
class risc {

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

      default:
        sys::MsgError("Invalid Register", "Instruction.cxx, dprintreg");
    }
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
