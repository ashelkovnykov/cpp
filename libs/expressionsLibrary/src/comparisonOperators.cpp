#include <cassert>
#include <compare>

#include "comparisonOperators.h"

void comparisonOperatorsExample() {

  int a = 1;
  int b = 2;
  
  assert(a == a);
  
  assert(a != b);
  
  assert(a < b);
  
  assert(b > a);
  
  assert(a <= a);
  
  assert(a >= a);
  
  assert((a <=> b) < 0);
  assert((b <=> a) > 0);
  assert((a <=> a) == 0);
  
}
