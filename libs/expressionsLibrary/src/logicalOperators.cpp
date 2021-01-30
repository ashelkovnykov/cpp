#include <cassert>

#include "logicalOperators.h"

void logicalOperatorsExample() {
  
  bool t = true;
  bool f = false;
  
  assert(t);
  assert(!f);
  
  assert(t && t);
  assert(!(t && f));
  assert(!(f && f));
  
  assert(t || t);
  assert(t || f);
  assert(!(f || f));
  
}
