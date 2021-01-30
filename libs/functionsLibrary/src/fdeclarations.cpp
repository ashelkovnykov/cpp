#include "fdeclarations.h"

// This overwrites the final declaration of 'f' from the header - meaning that the default arguments are still registered
int f(int i, long l, double d) {
  return (i + (l * d));
}

void g(char* c, int (*g)()) {}
