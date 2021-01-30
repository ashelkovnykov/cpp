#include <cassert>

#include "arithmeticOperators.h"

void arithmeticOperatorsExample() {
  
  unsigned char i = 85;
  unsigned char j = 170;
  int a = 1;
  int b = -1;
  int c = 3;
  int d;
  
  d = +a;
  assert(d == a);
  
  d = -b;
  assert(d == 1);
  
  d = a + b;
  assert(d == 0);
  
  d = a - b;
  assert(d == 2);
  
  d = c * a;
  assert(d == c);
  
  d = c / b;
  assert(d == -3);
  
  d = c % 2;
  assert(d == 1);
  
  d = ~85;
  assert(d == j);
  
  d = i & j;
  assert(d == 0);
  
  d = i | j;
  assert(d == 255);
  
  d = i ^ (unsigned char)(255);
  assert(d == j);
  
  d = c << a;
  assert(d == 6);
  
  d = c >> a;
  assert(d == 1);

}
