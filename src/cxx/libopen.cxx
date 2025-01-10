

// A astrix library is expected to have these arguments
// libmain(double* r0, double* r1, char* s0, char* s1, sstack* stack, short* sp, sstack* stf1, sstack* stf2)
// sstack union layout is 
/*
    typedef union sstack {
        char s[1024];
        double r;
    } sstack;
*/


typedef union sstack {
    char s[1024];
    double r;
} sstack;

