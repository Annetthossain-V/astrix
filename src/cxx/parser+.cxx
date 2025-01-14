#include "../header/object.h"
#include "header/parser.hxx"
#include <string>
#include "../header/id.h"
#include "header/sys.hxx"

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
        else if (First == "movl") {
            if (BufferWord[1] == NULL || BufferWord[2] == NULL)  { sys::MsgError("parser+.cxx","Invalid Number Of Arguments"); return; }
            Register_t First = StrToReg(BufferWord[1]);
            Register_t Second = StrToReg(BufferWord[2]);
            metadata->id = ID_MOVL;
            metadata->group = GROUP_MOV;
            metadata->FirstRegister = First;
            metadata->SecondRegister = Second;
            *match = true;
        }
        else if (First == "movs") {
            if (BufferWord[1] == NULL || BufferWord[2] == NULL)  { sys::MsgError("parser+.cxx","Invalid Number Of Arguments"); return; }
            Register_t First = StrToReg(BufferWord[1]);
            Register_t Second = StrToReg(BufferWord[2]);
            metadata->id = ID_MOVS;
            metadata->group = GROUP_MOV;
            metadata->FirstRegister = First;
            metadata->SecondRegister = Second;
            *match = true;
        }
    }

    Register_t ParserBasic::StrToReg(std::string str) {
        Register_t RetVal;

        if (str == "r0") { RetVal = R0; }
        else if (str == "r1") { RetVal = R1; }
        else if (str == "s1") { RetVal = S1; }
        else if (str == "s0") { RetVal = S0; }
        else if (str == "st0") { RetVal = SST1; }
        else if (str == "st1") { RetVal = SST1; }
        else if (str == "st2") { RetVal = SST2; }
        else if (str == "st3") { RetVal = SST3; }
        else if (str == "st4") { RetVal = SST4; }
        else if (str == "st5") { RetVal = SST5; }
        else if (str == "st6") { RetVal = SST6; }
        else if (str == "stf0") { RetVal = SSTF1; }
        else if (str == "stf1") { RetVal = SSTF1; }
        else if (str == "stf2") { RetVal = SSTF2; }
        else if (str == "stf3") { RetVal = SSTF3; }
        else { RetVal = null; }

        return RetVal;
    }
}