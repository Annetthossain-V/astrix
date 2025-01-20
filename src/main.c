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
#include "asm/header/simple.h"
#include "asm/header/crit.h"


const char* version = "Version: 0.0.2 Alpha, Compiled on 15/1/2025";


extern void Data_Initialize();
void FileReader(const char* filename, char* func);
void CmdReader();

config_t* _config(short argc, char** argv) {
    short index = 1;
    config_t *args = malloc(sizeof(config_t) + 8);
    args->FoundFileName = false;

    if (argc < 2) {
        strcpy(args->filename, "NULL");
        args->FoundFileName = false;
        return args;
    }

    while (index != argc) {
        char *current = argv[index];
        short tmp = 0;
        short currentLen = strlen_ASM(current);

        if (args->FoundFileName == false) {
            while (current[tmp] != '\0' || NULL) {
                if (current[tmp] == '.' && current[(tmp+1)] == 's') {

                    short len = strlen_ASM(argv[index]);
                    if (len > 24) { printf("File Name Too Long\n"); CritExit(); }
                    strcpy(args->filename, argv[index]);
                    args->FoundFileName = true;
                
                }
                if (current[tmp] == '.' && current[(tmp+1)] != 's') {
                    printf("Invalid File Format, Use .s instead\n");
                    CritExit();
                }

                tmp++;
            }
        }
        if (current[0] == '-' && current[1] == 'v') {
            printf("%s\n", version);
            Exit_Astrix();
        }
        

        index++;
    }

    return args;
}


int main(int argc, char** argv) {
    config_t *args = _config(argc, argv);
    data_init();
    Data_Initialize();
    extern unsigned short* sp;
    *sp = 0;
    extern bool *cli;

    extern char* functionName;
    strcpy(functionName, "main:");

    extern bool* jmp;
    *jmp = true;

    if (args->FoundFileName == true) { args->cli = false; *cli = false;; }
    else if (args->FoundFileName == false) { args->cli = true; *cli = true; }

    if (args->cli == false) {
        const char* filename = args->filename;
        while (true) {
            if (*jmp == true) {
                *jmp = false;
                FileReader(filename, functionName);
            } else if (*jmp == false) {
                break;
            }
        }
        
    } else if (args->cli == true) {
        CmdReader();
    }

    free(args);
    data_deinit();
    Exit_Astrix();
}

void FileReader(const char* filename, char* func) {
    extern char* buffer;
    bool fndFnc = false;
    extern bool* jmp;

    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) { Msg_Box_Error("File Does not Exist", "Invalid File"); }

    while (fgets(buffer, 1024, file) != NULL) {
        char* newline = strchr(buffer, '\n');
        if (newline) { *newline = '\0'; }

        unsigned short count = StringHyperV(buffer);
        extern char** buffer_word;

        int matchName = strcmp(buffer_word[0], func);
        if (fndFnc == false) {
            if (matchName == 0) {
                fndFnc = true;
                continue;
            } else if (matchName != 0) {
                continue;
            }
        } else if (fndFnc == true) {
            char* fnc = ":";
            if (strstr(buffer_word[0], fnc) != NULL) {
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
    extern char* buffer;
    extern char** buffer_word;
    while (true) {
        printf("Astrix $> ");
        fgets(buffer, 1024, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "") == 0) { continue; }
        if (strcmp(buffer, "exit()") == 0) {
            data_deinit();
            Exit_Astrix();
        }
        if (strcmp(buffer, "clear()") == 0) {
           system("clear");
           continue;
        }
        unsigned short count = StringHyperV(buffer);
        OperandMetadataBasic_t *metadata = (OperandMetadataBasic_t*) malloc(52);
        *metadata = ParserBasic();
        vmMain(metadata);

        buffer_array_deallocate(&count);
        free(metadata);
    } 
}
