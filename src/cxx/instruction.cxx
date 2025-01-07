
#include "../header/object.h"

extern "C" double* get_r0();
extern "C" double* get_r1();
extern "C" char* get_s0();
extern "C" char* get_s1();


class risc {

};

class cisc {
public:
  bool dprintreg(OperandMetadataBasic_t metadata, double* r0, double* r1, char* s0, char* s1) {
    return true;
  }
};

void dprintregAPI(OperandMetadataBasic_t metadata) {
    double* r0 = get_r0();
    double* r1 = get_r1();
    char* s0 = get_s0();
    char* s1 = get_s1();


    return;
}
