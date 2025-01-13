#include <bits/types/stack_t.h>
#include <stdlib.h>
#include "../header/data.h"
#include "../header/sys.h"
#include <string.h>
#include <stdbool.h>
#include "../header/object.h"

extern void CritExit();


static char* buffer;
static char** buffer_word;

// switch args to local variable
static config_t* args;

static bool *cli;
static bool *admin;

static bool *sstring;

// Registers
// add more in the future
static double* r0;
static double* r1;

static char* s0;
static char* s1;

// storage registers
static sstack* st1;
static sstack* st2;
static sstack* st3;
static sstack* st4;
static sstack* st5;
static sstack* st6;

static sstack* stf1;
static sstack* stf2;
static sstack* stf3;


static sstack** stack;
static unsigned short* sp;


static char* functionName;
static bool* jmp;





void stRegAlloc() {
    st1 = malloc(((1024+8) + 12));
    st2 = malloc(((1024+8) + 12));
    st3 = malloc(((1024+8) + 12));
    st4 = malloc(((1024+8) + 12));
    st5 = malloc(((1024+8) + 12));
    st6 = malloc(((1024+8) + 12));
    stf1 = malloc(((1024+8) + 12));
    stf2 = malloc(((1024+8) + 12));
    stf3 = malloc(((1024+8) + 12));
    return;
}

void stRegDealloc() {
    free(st1);
    free(st2);
    free(st3);
    free(st4);
    free(st5);
    free(st6);
    free(stf1);
    free(stf2);
    free(stf3);
}
#include <stdio.h>
void stackAlloc() {
    unsigned short size;
    const char* VarName = "STACK_SIZE";
    const char* Var = getenv(VarName);
    if (Var == NULL) { size = 100; }
    else { size = atoi(Var); }

    stack = malloc((size * 32));
    for (int i = 0; i != size; i++) {
        stack[i] = malloc(((1024 + 8) + 248));
        if (stack[i] == NULL) { printf("OUT OF MEMORY\n"); CritExit(); }
    }
    return;
}

void stackDealloc() {
    unsigned short size;
    const char* VarName = "STACK_SIZE";
    const char* Var = getenv(VarName);
    if (Var == NULL) { size = 100; }
    else { size = atoi(Var); }

    for (int i = 1; i != size; i++) {

        free(stack[i]);
        
    }
    free(stack);
}

void registrAllocate() {
    // integers
    r0 = (double*) malloc(6);
    r1 = (double*) malloc(6);

    // strings
    s0 = (char*) malloc(1024);
    s1 = (char*) malloc(1024);

    if (r0 == NULL) { Msg_Box_Error("R0 Alloc Failed", "Alloc Failed"); }
    if (r1 == NULL) { Msg_Box_Error("R1 Alloc Failed", "Alloc Failed"); }
    if (s0 == NULL) { Msg_Box_Error("S0 Alloc Failed", "Alloc Failed"); }
    if (s1 == NULL) { Msg_Box_Error("S1 Alloc Failed", "Alloc Failed"); }
    return;
}

void registerDealloc() {
    free(r0);
    free(r1);
    free(s0);
    free(s1);
    return;
}

void buffer_allocate() {
    buffer = (char*) malloc(1024);

    if (buffer == NULL) {
        Msg_Box_Error("Buffer Allocation Failed", "Alloc Failed");
    }

    strcpy(buffer, "NULL");

    return;
}

void functionNameAlloc() {
    functionName = (char*) malloc(18);
    if (functionName == NULL) { Msg_Box_Error("Funcname Alloc Failed", "Alloc Failed"); }
    return;
}

void functionNameDealloc() {
    free(functionName);
    return;
}

void BasicAlloc() {
    jmp = (bool*) malloc(1);
    cli = malloc(1);
    sp = malloc((2 + 2));
    admin = malloc(1);
    sstring = malloc(1);

    return;
}

void BasicDealloc() {
    free(jmp);
    free(cli);
    free(sp);
    free(admin);
}

void buffer_deallocate() {
    free(buffer);
    return;
}

void buffer_word_allocate() {
    buffer_word = (char**) malloc(10024);

    if (buffer_word == NULL) {
        Msg_Box_Error("Buffer Allocation Failed", "Alloc Failed");
    }



    return;
}

void buffer_word_deallocate() {
    free(buffer_word);
    return;
}

void buffer_array_deallocate(unsigned short* index) {
    for (short i = 0; i != *index; i++) {
        free(buffer_word[i]);
    }
    return;
}

void data_init() {
    buffer_allocate();
    buffer_word_allocate();
    registrAllocate();
    functionNameAlloc();
    BasicAlloc();
    stackAlloc();
    stRegAlloc();

    return;
}

void data_deinit() {
    buffer_deallocate();
    buffer_word_deallocate();
    registerDealloc();
    functionNameDealloc();
    BasicAlloc();
    stackDealloc(); // bug here
    stRegDealloc();

    return;
}

char* get_s1() {
    return s1;
}

char* get_s0() {
    return s0;
}

double* get_r1() {
    return r1;
}

double* get_r0() {
    return r0;
}

char* Get_buffer() {
    return buffer;
}

char** Get_buffer_word() {
    return buffer_word;
}

char* GetFuncName() {
    return functionName;
}

bool* GetJmp() {
    return jmp;
}

sstack** getstack() {
    return stack;
}

config_t* GetArgs() {
    return args;
}

bool* GetCli() {
    return cli;
}

unsigned short* GetSp() {
    return sp;
}

bool* getAdmin() {
    return admin;
}

sstack* GetstRegister(StorageRegister_t Register) {
    switch (Register) {
        case ST1:
            return st1;
        case ST2:
            return st2;
        case ST3:
            return st3;
        case ST4:
            return st4;
        case ST5:
            return st5;
        case ST6:
            return st6;
        case STF1:
            return stf1;
        case STF2:
            return stf2;
        case STF3:
            return stf3;
        default:
            return NULL;
    }
}

bool* getsstring() {
    return sstring;
}