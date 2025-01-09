// the lexer takes raw string and
// returns objects that the computer understands

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../header/data.h"
#include "../header/sys.h"
#include "../header/object.h"

unsigned short StringHyperV(char* buffer) {
    char* token;
    char* delim = " ";
    int count = 0;
    
    char** buffer_word = Get_buffer_word();

    token = strtok(buffer, delim);

    while (token != NULL) {
        buffer_word[count] = malloc(1024);
        if (buffer_word[count] == NULL) { Msg_Box_Error("Buffer World Alloc Failed", "Alloc Failed"); }
        buffer_word[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }

    return count;
}


Register_t StrToReg(char *str) {
    Register_t RetVal;
    char cmp;
    bool match = false;
    cmp = strcmp(str, "r0");
    if (cmp == 0) {
        match = true;
        RetVal = R0;
        return RetVal;
    }
    cmp = strcmp(str, "r1");
    if (cmp == 0) {
        match = true;
        RetVal = R1;
        return RetVal;
    }
    cmp = strcmp(str, "s0");
    if (cmp == 0) {
        match = true;
        RetVal = S0;
        return RetVal;
    }
    cmp = strcmp(str, "s1");
    if (cmp == 0) {
        match = true;
        RetVal = S1;
        return RetVal;
    }


    if (match == false) {
        Msg_Box_Error("lexer.c: StrToReg", "Invalid Register");
        
    }

    RetVal = null;
    return RetVal;

}