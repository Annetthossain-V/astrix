#include "header/sys.hxx"
#include <iostream>
#include "header/data.hxx"

extern bool* cli;

namespace sys {
    void MsgError(std::string title, std::string msg) {
        std::cout << title << ": " << msg << std::endl;
        

        if (*cli == true) { return; }

        data_deinit();
        CritExit();
        return;
    }
}