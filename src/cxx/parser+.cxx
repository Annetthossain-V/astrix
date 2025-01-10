#include "../header/object.h"
#include "header/parser.hxx"
#include <string>
#include "../header/id.h"

// C api
extern "C" void ParserP(OperandMetadataBasic_t* metadata, bool* match, char** BufferWord) {
    parser::ParserBasic pbasic;
    pbasic.pMain(metadata, match, BufferWord);
    return;
}

namespace parser {
    void ParserBasic::pMain(OperandMetadataBasic_t* metadata, bool* match, char** BufferWord) {
        First = BufferWord[0];
        


    }
}