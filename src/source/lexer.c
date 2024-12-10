// the lexer takes raw string and
// returns objects that the computer understands

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/data.h"

unsigned short StringHyperV(char* buffer) {
    char* token;
    char* delim = " ";
    int count = 0;
    
    char** buffer_word = Get_buffer_word();

    token = strtok(buffer, delim);

    while (token != NULL) {
        buffer_word[count] = malloc(1024);
        buffer_word[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }

    return count;
}