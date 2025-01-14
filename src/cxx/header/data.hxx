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


extern "C" void buffer_array_deallocate(unsigned short *index);

