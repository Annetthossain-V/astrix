
#include <cstdio>
#include <thread>

#include "../header/object.h"
#include "header/sys.hxx"
#include "header/sys.hxx"
#include "../header/id.h"
#include "header/instruction.hxx"
#include "header/vm.hxx"

extern "C" int vmMain(OperandMetadataBasic_t* metadata) {


    std::thread vmIdThread(vmId, metadata);
    

    vmIdThread.join();
    return 0;
}

extern "C" bool vmId(OperandMetadataBasic_t* metadata) {
    switch (metadata->group) {
        case GROUP_DEBUG:
            switch (metadata->id) {
                case ID_DEBUG:
                    printf("DEBUG POINT\n");
                    return true;

                case ID_NONE:
                    sys::MsgError("ID Mismatch", "Invalid Instruction");

                case ID_DPRINTREG:
                    dprintregAPI(metadata);
                    return true;
                case ID_DPRINTSTK:
                    dprintstk();
                    return true;

                default:
                    sys::MsgError("Invalid MetaData id", "Id did not match");
                    return false;
            }
        case GROUP_NONE:
            sys::MsgError("Group Mismatch", "invalid Group");
            return false;
        

        default:
            sys::MsgError("Invalid MetaData Group", "Group did not match");
            return false;

    }
    
}

