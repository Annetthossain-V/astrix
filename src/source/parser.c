
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "../header/data.h"
#include "../header/object.h"
#include "../header/id.h"
#include "../header/lexer.h"

OperandMetadataBasic_t ParserBasic() {
    OperandMetadataBasic_t metadata;
    char** BufferWord = Get_buffer_word();

    int result;
    bool match;

    result = strcmp(BufferWord[0], "debug");
    if (result == 0) {
        metadata.SingleOperand = true;
        metadata.DoubleOperand = false;
        metadata.TripleOperand = false;
        metadata.RequireRegister = false;
        metadata.DoubleRegister = false;
        metadata.FirstRegister = null;
        metadata.SecondRegister = null;
        metadata.RegisterValue = false;
        metadata.RegisterMix = null_null;
        metadata.id = ID_DEBUG;
        metadata.group = GROUP_DEBUG;

        match = true;
    }
    result = strcmp(BufferWord[0], "dprintreg");
    if (result == 0) {
        Register_t second = StrToReg(BufferWord[1]);
        metadata.SingleOperand = false;
        metadata.DoubleOperand = true;
        metadata.TripleOperand = false;
        metadata.RequireRegister = true;
        metadata.DoubleRegister = false;
        metadata.FirstRegister = second;
        metadata.SecondRegister = null;
        metadata.RegisterValue = false;
        metadata.RegisterMix = null_null;
        metadata.id = ID_DPRINTREG;
        metadata.group = GROUP_DEBUG;

        match = true;
    }

    if (match == false) {
        metadata.SingleOperand = NULL;
        metadata.DoubleOperand = NULL;
        metadata.TripleOperand = NULL;
        metadata.RequireRegister = NULL;
        metadata.DoubleRegister = NULL;
        metadata.FirstRegister = null;
        metadata.SecondRegister = null;
        metadata.RegisterValue = NULL;
        metadata.RegisterMix = r0_r0;
        metadata.id = ID_NONE;
        metadata.group = GROUP_NONE;
    }

    return metadata;
}