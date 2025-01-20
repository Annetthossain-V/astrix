#include "../header/object.h"
#include "../cxx/header/RgMix.h"
#include "../cxx/header/RgMix.h"
#include "../header/object.h"
#include "../header/sys.h"

RegisterMix_t RegsiterMixInfo(Register_t First, Register_t Second) {

    if (First == R0) {
      switch (Second) {
        case R1:
          return R0_R1;
        case SSTF1:
          return R0_STF1;
        case SSTF2:
          return R0_STF2;
         case SSTF3:
          return R0_STF3;
         case SST1:
           return R0_ST1;
         case SST2:
           return R0_ST2;
          case SST3:
            return R0_ST3;
          case SST4:
            return R0_ST4;
          case SST5:
            return R0_ST5;
          case SST6:
            return R0_ST6;
          case null:
            return R0_VAL;
          default:
            return R0_VAL;
      }
    }

    else if (First == R1) {
      switch (Second) {
        case R0:
          return R1_R0;
        case SSTF1:
          return R1_STF1;
        case SSTF2:
          return R1_STF2;
        case SSTF3:
          return R1_STF3;
        case SST1:
          return R1_ST1;
        case SST2:
          return R1_ST2;
        case SST4:
          return R1_ST4;
        case SST5:
          return R1_ST5;
        case SST6:
          return R1_ST6;
        case null:
          return R1_VAL;
        default:
          return R1_VAL;
      }
    }

    





   return nil_nil;
}
