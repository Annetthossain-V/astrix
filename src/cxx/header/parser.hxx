#include "../../header/object.h"
#include <string>


namespace parser {
    class ParserBasic {
    public:
        void pMain(OperandMetadataBasic_t *metadata, bool* match, char** BufferWord);
    private:
        std::string First;

    };
}