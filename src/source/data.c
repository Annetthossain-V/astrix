#include <bits/types/stack_t.h>
#include <stdlib.h>
#include "../header/data.h"
#include "../header/sys.h"
#include <string.h>
#include <stdbool.h>
#include "../header/object.h"


static char* buffer;
static char** buffer_word;

// switch args to local variable
static config_t* args;

static bool *cli;

// Registers
// add more in the future
static double* r0;
static double* r1;

static char* s0;
static char* s1;


static sstack** stack;
static unsigned short* sp;


static char* functionName;
static bool* jmp;




void stackAlloc() {
    stack = malloc(800);
    for (int i = 0; i <= 49; i++) {
        stack[i] = malloc(((1024 + 8) + 248));
    }
    return;
}

void stackDealloc() {
    for (int i = 0; i <= 49; i++) {
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

    return;
}

void BasicDealloc() {
    free(jmp);
    free(cli);
    free(sp);
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

    return;
}

void data_deinit() {
    buffer_deallocate();
    buffer_word_deallocate();
    registerDealloc();
    functionNameDealloc();
    BasicAlloc();
    stackDealloc(); // bug here

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