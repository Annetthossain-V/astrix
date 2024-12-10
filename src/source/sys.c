#include <stdio.h>
#include <stdlib.h>
#include "../header/sys.h"


void Exit_Astrix(const short code) {
  exit(code);
}

void Msg_Box_Error(char* msg, char* title) {
  printf("%s: %s", title, msg);
  Exit_Astrix(EXIT_FAILURE);
}