
#include <stdbool.h>
#include <string.h>

#include "../header/data.h"
#include "../header/object.h"


OperandMetadataBasic_t ParserBasic() {
    OperandMetadataBasic_t metadata;
    char** BufferWord = Get_buffer_word();

    int result;

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
        metadata.RegisterMix = r0_r0;
        metadata.id = 0xFF;
    }

    else {
        // todo
    }

    return metadata;
}