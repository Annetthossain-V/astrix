
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "../header/data.h"
#include "../header/object.h"
#include "../header/id.h"
#include "../header/lexer.h"
#include "../cxx/header/export.h"

OperandMetadataBasic_t ParserBasic() {
    OperandMetadataBasic_t metadata;
    char** BufferWord = Get_buffer_word();

    int result;
    bool match;

    result = strcmp(BufferWord[0], "debug");
    if (result == 0) {
        metadata.FirstRegister = null;
        metadata.SecondRegister = null;
        metadata.id = ID_DEBUG;
        metadata.group = GROUP_DEBUG;

        match = true;
    }
    result = strcmp(BufferWord[0], "dprintreg");
    if (result == 0) {
        Register_t first = StrToReg(BufferWord[1]);
        metadata.FirstRegister = first;
        metadata.SecondRegister = null;
        metadata.id = ID_DPRINTREG;
        metadata.group = GROUP_DEBUG;

        match = true;
    }

    ParserP(&metadata, &match, BufferWord);

    if (match == false) {
        metadata.FirstRegister = null;
        metadata.SecondRegister = null;
        metadata.id = ID_NONE;
        metadata.group = GROUP_NONE;
    }

    return metadata;
}