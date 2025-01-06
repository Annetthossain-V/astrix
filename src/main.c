#include <complex.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "header/object.h"
#include "header/sys.h"
#include "header/data.h"
#include "header/lexer.h"
#include "header/parser.h"
#include "header/vm.h"


void FileReader(const char* filename, char* func);
void CmdReader();

config_t* _config(short argc, char** argv) {
    short index = 1;
    config_t *args = malloc(sizeof(config_t) * 4);
    args->FoundFileName = false;

    if (argc < 2) {
        strcpy(args->filename, "NULL");
        args->FoundFileName = false;
        return args;
    }

    while (index != argc) {
        char *current = argv[index];
        short tmp = 0;
        while (current[tmp] != '\0' || NULL) {
            if (current[tmp] == '.' && current[(tmp+1)] == 's') {
                if (args->FoundFileName == true) {
                    Msg_Box_Error("Double input file", "Argument Error");
                }

                strcpy(args->filename, argv[index]);
                args->FoundFileName = true;
                
            }

            tmp++;
        }

        index++;
    }

    return args;
}

int main(int argc, char** argv) {
    config_t *args = GetArgs();
    args = _config(argc, argv);
    
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
        const char* filename = args->filename;
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

    free(args);
    data_deinit();
    Exit_Astrix();
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


        OperandMetadataBasic_t *metadata = (OperandMetadataBasic_t*) malloc(52);
        *metadata = ParserBasic();
        vmMain(metadata);

        buffer_array_deallocate(&count);
        free(metadata);

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
            data_deinit();
            Exit_Astrix();
        }
        unsigned short count = StringHyperV(buffer);
        OperandMetadataBasic_t *metadata = (OperandMetadataBasic_t*) malloc(52);
        *metadata = ParserBasic();
        vmMain(metadata);

        buffer_array_deallocate(&count);
        free(metadata);
    } 
}
