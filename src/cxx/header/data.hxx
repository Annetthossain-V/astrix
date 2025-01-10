// basic convertion from C style data.h to more C++ style data.hpp
// connects C++ to the data.h header file


#include <stdbool.h>
#include "../../header/object.h"

extern "C" char* Get_buffer();

extern "C" void buffer_allocate();
extern "C" void buffer_deallocate();

extern "C" void data_init();
extern "C" void data_deinit();

extern "C" void buffer_word_allocate();
extern "C" void buffer_word_deallocate();

extern "C" char** Get_buffer_word();

extern "C" void buffer_array_deallocate(unsigned short *index);

extern "C" double* get_r1();

extern "C" double* get_r0();

extern "C" char* get_s1();

extern "C" char* get_s0();

extern "C" void registerDealloc();

extern "C" void registrAllocate();

extern "C" char* GetFuncName();

extern "C" void functionNameDealloc();

extern "C" void functionNameAlloc();

extern "C" bool* GetJmp();

extern "C" void BasicDealloc();

extern "C" void BasicAlloc();

extern "C" void stackAlloc();

extern "C" void stackDealloc();

extern "C" sstack** getstack();

extern "C" config_t* GetArgs();

extern "C" bool* GetCli();

extern "C" unsigned short* GetSp();

extern "C" bool* getAdmin();

extern "C" sstack* GetstRegister(StorageRegister_t Register);
