#include <stdlib.h>
#include <string.h>
#include "../header/sys.h"

char* GetSubStr(const char* str) {
    int start = -1;
    int end = -1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\'') {
            if (start == -1) {
                start = i + 1;
            } else {
                end = i;
                break;
            }
        }
        i++;
    }

    if (start == -1 || end == -1) {
        return NULL;
    }

    int len = end - start;
    char* substring = (char*) malloc(120);
    if (substring == NULL) {
        Msg_Box_Error("substring Alloc Failed", "Alloc Failed"); // turn this to CritExit
    }

    strncpy(substring, &str[start], len);
    substring[len] = '\0';

    // don't forget to free this
    return substring;
}