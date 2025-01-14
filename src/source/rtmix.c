#include "../header/object.h"
#include "../cxx/header/RgMix.h"
#include "src/cxx/header/RgMix.h"
#include "src/header/object.h"
#include "src/header/sys.h"

RegisterMix_t RegsiterMixInfo(Register_t First, Register_t Second) {
  switch (First) {
    case R0:
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
          default:
            Msg_Box_Error("Invalid Combination", "rtmix.c");
            return nil_nil;


      }
  }

}