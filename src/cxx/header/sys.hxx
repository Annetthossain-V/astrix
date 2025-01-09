#pragma once

#include <string>

extern "C" void Exit_Astrix();
extern "C" void Msg_Box_Error(char* msg, char* title);

extern "C" void* dlopenAstrix();

// C++ special

extern "C" void CritExit();
extern "C" void data_deinit();

// C++ custom

namespace sys {
    void MsgError(std::string title, std::string msg);
}