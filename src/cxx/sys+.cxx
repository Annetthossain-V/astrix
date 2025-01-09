#include "header/sys.hxx"
#include <iostream>


namespace sys {
    void MsgError(std::string title, std::string msg) {
        std::cout << title << ": " << msg << std::endl;
        data_deinit();
        CritExit();
        return;
    }
}