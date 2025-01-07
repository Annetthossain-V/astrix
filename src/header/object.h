#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum Operand {
    test,
} Operand_t;

typedef enum Register {
    R0,
    R1,
    S0,
    S1,
    STACK,
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
    r0_s1,
    r0_s0,
    r1_s1,
    r1_s0,
    s0_r1,
    s0_r0,
    s1_r1,
    s1_r0,
    null_null

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
    int16_t id;
    int8_t group;
} OperandMetadataBasic_t;


typedef struct Config{
    char filename[24];
    bool FoundFileName;
} config_t;