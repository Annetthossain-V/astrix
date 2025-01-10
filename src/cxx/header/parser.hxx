#include "../../header/object.h"
#include <string>


namespace parser {
    class ParserBasic {
    public:
        void pMain(OperandMetadataBasic_t *metadata, bool* match, char** BufferWord);
        Register_t StrToReg(std::string str);
    private:
        std::string First;

    };
}