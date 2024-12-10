#include <stdlib.h>
#include "../header/data.h"
#include "../header/sys.h"
#include <string.h>

static char* buffer;
static char** buffer_word;

char* Get_buffer() {
    return buffer;
}

char** Get_buffer_word() {
    return buffer_word;
}

void buffer_allocate() {
    buffer = (char*) malloc(1024);

    if (buffer == NULL) {
        Msg_Box_Error("Buffer Allocation Failed", "Alloc Failed");
    }

    strcpy(buffer, "NULL");

    return;
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
    *index = 0;
    return;
}

void data_init() {
    buffer_allocate();
    buffer_word_allocate();

    return;
}

void data_deinit() {
    buffer_deallocate();
    buffer_word_deallocate();

    return;
}
