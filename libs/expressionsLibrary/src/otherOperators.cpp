#include <cassert>

#include "otherOperators.h"

void otherOperatorsExample() {

  bool t = true;
  bool f = false;
  int a = 1;
  int b = 2;
  int c;
  
  assert((t ? a : b) == a);
  assert((f ? a : b) == b);
  
  assert((a++, a) == 2);
  
  assert(sizeof(t) == 1);
  
  assert(alignof(char) == 1);

  assert(!noexcept(otherOperatorsExample));
}
