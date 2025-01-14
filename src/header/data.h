#include <stdbool.h>
#include "object.h"

char* Get_buffer();

void buffer_allocate();
void buffer_deallocate();

void data_init();
void data_deinit();

void buffer_word_allocate();
void buffer_word_deallocate();


void buffer_array_deallocate(unsigned short *index);

