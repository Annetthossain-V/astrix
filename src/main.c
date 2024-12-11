#include <complex.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "header/sys.h"
#include "header/data.h"
#include "header/lexer.h"

void FileReader(const char* filename, char* func);
void CmdReader();

int main(int argc, char** argv) {
    data_init();

    bool Cmdline;
    
    char* funcName = GetFuncName();
    strcpy(funcName, "main:");

    bool* jmp = GetJmp();
    *jmp = true;


    if (argc <= 1) {
        Cmdline = true;
    } else {
        Cmdline = false;
    }

    if (Cmdline == false) {
        const char* filename = argv[1];
        while (true) {
            if (*jmp == true) {
                *jmp = false;
                FileReader(filename, funcName);
            } else if (*jmp == false) {
                break;
            }
        }
        
    } else if (Cmdline == true) {
        CmdReader();
    }


    data_deinit();
    Exit_Astrix(EXIT_SUCCESS);
}

void FileReader(const char* filename, char* func) {
    char* buffer = Get_buffer();
    bool fndFnc = false;
    bool* jmp = GetJmp();

    FILE *file;
    file = fopen(filename, "r");


    while (fgets(buffer, 1024, file) != NULL) {
        char* newline = strchr(buffer, '\n');
        if (newline) { *newline = '\0'; }

        unsigned short count = StringHyperV(buffer);
        char **buff_word = Get_buffer_word();

        int matchName = strcmp(buff_word[0], func);
        if (fndFnc == false) {
            if (matchName == 0) {
                fndFnc = true;
                continue;
            } else if (matchName != 0) {
                continue;
            }
        } else if (fndFnc == true) {
            char* fnc = ":";
            if (strstr(buff_word[0], fnc) != NULL) {
                break;
            }
        }
        if (*jmp == true) {
            break;
        }


        printf("Buff Word: %s\n", buff_word[0]);
        buffer_array_deallocate(&count);

    }

    fclose(file);
    return;
}

void CmdReader() {
    char* buffer = Get_buffer();
    char** buffer_word = Get_buffer_word();
    while (true) {
        printf("Astrix $> ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "exit()") == 0) {
            Exit_Astrix(EXIT_SUCCESS);
        }
        unsigned short count = StringHyperV(buffer);
        printf("First Word: %s \n", buffer_word[0]);
        buffer_array_deallocate(&count);
    } 
}