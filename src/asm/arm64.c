
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

short strlen__ASM(char* str) {
  short index = 0;
  while (str[index] != '\0' || NULL) {
    index++;
  }
  return index;
  
}

void CritExit() {
  puts("critical error");
  exit(1);
}

void* kmalloc(short kbyte) {
  int num = kbyte * 1024;
  return malloc(num);
}

void ksleep(int ammount)
{
  usleep((ammount * 1261));
  return;
}

void data_default() {
  
}