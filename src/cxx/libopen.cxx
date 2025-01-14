

// A astrix library is expected to have these arguments
// libmain(double* r0, double* r1, char* s0, char* s1, sstack* stack, unsigned short* sp, sstack* stf1, sstack* stf2, sstack* stf3)
// sstack union layout is 
/*
    typedef union sstack {
        char s[1024];
        double r;
    } sstack;
*/

#include "header/data.hxx"
#include <string>
#include "../header/object.h"

void libmain() {
    // double* r0 = get_r0();
    // double* r1 = get_r1();
    // char* s0 = get_s0();
    // char* s1 = get_s1();
    // sstack** stack = getstack();
    // unsigned short* sp = GetSp();
    // sstack* stf1 = GetstRegister(STF1);
    // sstack* stf2 = GetstRegister(STF2);
    // sstack* stf3 = GetstRegister(STF3);

    // std::string dllname = s0;
    // std::string funcname = s1;


}
