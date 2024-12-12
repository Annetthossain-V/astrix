#pragma once

#include <stdbool.h>

typedef enum Operand {
    test,
} Operand_t;

typedef enum Register {
    r0,
    r1,
    s0,
    s1,
    null,
} Register_t;

typedef enum RegisterMix {
    r0_r1,
    r1_r0,
    r0_val,
    r1_val,
    r1_r1,
    r0_r0,
    s0_s1,
    s1_s0,
    s0_val,
    s1_val,
    s1_s1,
    s0_s0,

    // mix registers
    // may not be used everywhere
    r0_s1,
    r0_s0,
    r1_s1,
    r1_s0,
    s0_r1,
    s0_r0,
    s1_r1,
    s1_r0,

    null_r,
    null_s

} RegisterMix_t;

typedef struct OperandMetadataBasic {
    bool SingleOperand;
    bool DoubleOperand;
    bool TripleOperand;

    bool RequireRegister;
    bool DoubleRegister;

    Register_t FirstRegister;
    Register_t SecondRegister;
    
    bool RegisterValue;
    RegisterMix_t RegisterMix;
    short id;
} OperandMetadataBasic_t;


