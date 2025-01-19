
typedef union {
  char s[1024];
  double r;
} sstack;

extern sstack** ststack;
extern short* stsp;

void push();

void pop()