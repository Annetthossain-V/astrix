#include <complex.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "header/sys.h"
#include "header/data.h"
#include "header/lexer.h"

void FileReader(const char* filename);
void CmdReader();

int main(int argc, char** argv) {
    data_init();

    bool Cmdline;

    if (argc <= 1) {
        Cmdline = true;
    } else {
        Cmdline = false;
    }

    if (Cmdline == false) {
        const char* filename = argv[1];
        FileReader(filename);
    } else if (Cmdline == true) {
        CmdReader();
    }


    data_deinit();
    Exit_Astrix(EXIT_SUCCESS);
}

void FileReader(const char* filename) {
    char* buffer = Get_buffer();
    
    FILE *file;
    file = fopen(filename, "r");

    while (fgets(buffer, 1024, file) != NULL) {
        unsigned short count = StringHyperV(buffer);
        char **buff_word = Get_buffer_word();
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