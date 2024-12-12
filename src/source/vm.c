#include <stdbool.h>
#include <stdio.h>


#include "../header/object.h"
#include "../header/vm.h"
#include "../header/sys.h"

int vmMain(OperandMetadataBasic_t* metadata) {
    
    vmId(metadata);


    return 0;
}

bool vmId(OperandMetadataBasic_t* metadata) {
    switch (metadata->id) {
        case 0xFF:
            printf("DEBUG POINT\n");
            return true;

        default:
            Msg_Box_Error("Id did not match", "Invalid MetaData id");
            return false;
    }
}