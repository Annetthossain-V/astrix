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

extern "C" Register_t StrToReg(char *str) {
    parser::ParserBasic PBOBJ;

    std::string val = str;
    Register_t retVal = PBOBJ.StrToReg(val);
    return retVal;
}

namespace parser {
    void ParserBasic::pMain(OperandMetadataBasic_t* metadata, bool* match, char** BufferWord) {
        First = BufferWord[0];
        if (First == "dprintstk") {
            metadata->id = ID_DPRINTSTK;
            metadata->group = GROUP_DEBUG;
            *match = true;
        }
        
    }

    Register_t ParserBasic::StrToReg(std::string str) {
        Register_t RetVal;

        if (str == "r0") { RetVal = R0; }
        else if (str == "r1") { RetVal = R1; }
        else if (str == "s1") { RetVal = S1; }
        else if (str == "s0") { RetVal = S0; }
        else if (str == "st1") { RetVal = SST1; }
        else if (str == "st2") { RetVal = SST2; }
        else if (str == "st3") { RetVal = SST3; }
        else if (str == "st4") { RetVal = SST4; }
        else if (str == "st5") { RetVal = SST5; }
        else if (str == "st6") { RetVal = SST6; }
        else if (str == "stf1") { RetVal = SSTF1; }
        else if (str == "stf2") { RetVal = SSTF2; }
        else if (str == "stf3") { RetVal = SSTF3; }
        else { RetVal = null; }

        return RetVal;
    }
}