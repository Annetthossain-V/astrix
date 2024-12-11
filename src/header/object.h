
#include <stdbool.h>

struct OperandMetadataBasic {
    char* OperandFirst;
    char* OperandSecond;
    char* OperandThird;
    bool Single;
    bool Double;
    bool Triple;
    bool SecondRegister;
    bool ThirdRegister;
};
typedef OperandMetadataBasic OperandMetadataBasic_t;


enum Operand {
    test,
};
typedef Operand Operand_t;


enum RegisterMix {

};
typedef RegisterMix RegisterMix_t;