#include <stdbool.h>
#include "object.h"

char* Get_buffer();

void buffer_allocate();
void buffer_deallocate();

void data_init();
void data_deinit();

void buffer_word_allocate();
void buffer_word_deallocate();

char** Get_buffer_word();

void buffer_array_deallocate(unsigned short *index);

double* get_r1();

double* get_r0();

char* get_s1();

char* get_s0();

void registerDealloc();

void registrAllocate();

char* GetFuncName();

void functionNameDealloc();

void functionNameAlloc();

bool* GetJmp();

void BasicDealloc();

void BasicAlloc();

void stackAlloc();

void stackDealloc();

sstack** getstack();

config_t* GetArgs();

bool* GetCli();

unsigned short* GetSp();

bool* getAdmin();