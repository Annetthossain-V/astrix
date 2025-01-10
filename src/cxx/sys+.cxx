#include "header/sys.hxx"
#include <iostream>
#include "header/data.hxx"


namespace sys {
    void MsgError(std::string title, std::string msg) {
        std::cout << title << ": " << msg << std::endl;
        
        bool* cli = GetCli();
        if (*cli == true) { return; }

        data_deinit();
        CritExit();
        return;
    }
}