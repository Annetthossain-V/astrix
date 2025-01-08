#include <stdio.h>
#include <stdlib.h>
#include "../header/sys.h"
#include "../header/data.h"
#include "../asm/header/crit.h"

void Exit_Astrix() {
  exit(EXIT_SUCCESS);
}

void Msg_Box_Error(char* msg, char* title) {
  printf("%s: %s\n", title, msg);
  bool *cli = GetCli();
  if (*cli == true) { return; }

  data_deinit();
  CritExit();
}

void* dlopenAstrix() {
  return NULL;
}