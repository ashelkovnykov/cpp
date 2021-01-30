#include <cassert>

#include "incrementOperators.h"

void incrementOperatorsExample() {

  int a = 1;
  
  // Prefix Increment
  assert((++a) == 2);
  assert(a == 2);
  
  // Prefix Decrement
  assert((--a) == 1);
  assert(a == 1);
  
  // Postfix Increment
  assert((a++) == 1);
  assert(a == 2);
  
  // Postfix Decrement
  assert((a--) == 2);
  assert(a == 1);

}
