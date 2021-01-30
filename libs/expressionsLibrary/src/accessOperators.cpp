#include <cassert>

#include "accessOperators.h"

void accessOperatorsExample() {
  
  int i = 1;
  int r[2] = {0, 0};
  AccessStruct a = {i};
  AccessStruct *p;
  
  p = &a;
  
  assert(p->i == i);
  
  assert((*p).i == a.i);
  
  assert(r[0] == r[1]);

}
