#include <stdbool.h>
#include <stdio.h>


#include "../header/object.h"
#include "../header/vm.h"
#include "../header/sys.h"
#include "../header/id.h"

int vmMain(OperandMetadataBasic_t* metadata) {
    
    vmId(metadata);


    return 0;
}

bool vmId(OperandMetadataBasic_t* metadata) {
    switch (metadata->group) {
        case GROUP_DEBUG:
            switch (metadata->id) {
                case ID_DEBUG:
                    printf("DEBUG POINT\n");
                    return true;

                case ID_NONE:
                    Msg_Box_Error("Invalid Instruction", "ID Mismatch");
                default:
                    Msg_Box_Error("Id did not match", "Invalid MetaData id");
                    return false;
            }
        case GROUP_NONE:
            Msg_Box_Error("invalid Group", "Group Mismatch");
            return false;
        

        default:
            Msg_Box_Error("Group did not match", "Invalid MetaData Group");
            return false;

    }
    
}