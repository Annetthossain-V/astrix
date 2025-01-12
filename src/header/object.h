#pragma once

#include <stdbool.h>
#include <stdint.h>


typedef enum Register {
    R0,
    R1,
    S0,
    S1,
    STACK,
    null,
    SST1,
    SST2,
    SST3,
    SST4,
    SST5,
    SST6,
    
    SSTF1,
    SSTF2,
    SSTF3,
} Register_t;



typedef struct OperandMetadataBasic {
    Register_t FirstRegister;
    Register_t SecondRegister;

    char* content;
    char* content2;
    char* content3;

    int16_t id;
    int8_t group;
} OperandMetadataBasic_t;


typedef struct Config{
    char filename[24];
    bool FoundFileName;
    bool cli;
} config_t;

typedef union stack {
    char s[1024];
    double r;
} sstack;

typedef struct cmp {
    bool e; // equal to
    bool ne; // not equal to
    bool g; // greater then
    bool ge; // greater or equal
    bool l; // less then
    bool le; // less or equal
} cmp_t;

typedef enum StorageRegister {
    ST1,
    ST2,
    ST3,
    ST4,
    ST5,
    ST6,
    
    STF1,
    STF2,
    STF3,
} StorageRegister_t;