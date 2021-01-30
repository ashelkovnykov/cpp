#include <cassert>

#include "assignmentOperators.h"

void assignmentOperatorsExample() {

  int a = 1;
  int b = 2;
  int c = 7;
  
  // Assignment
  a = b;
  assert(a == 2);
  
  // Addition Compound Assignment
  a += b;
  assert(a == 4);
  
  // Subtraction Compound Assignment
  a -= b;
  assert(a == 2);
  
  // Multiplication Compound Assignment
  a *= b;
  assert(a == 4);
  
  // Division Compound Assignment
  a /= b;
  assert(a == 2);
  
  // Modulo Compound Assignment
  a %= c;
  assert(a == 2);
  
  // Bitwise AND Compound Assignment
  a &= c;
  assert(a == 2);
  
  // Bitwise XOR Compound Assignment
  a ^= c;
  assert(a == 5);
  
  // Bitwise OR Compound Assignment
  a |= c;
  assert(a == 7);
  
  // Bitshift Left Compound Assignment
  a <<= b;
  assert(a == 28);
  
  // Bitshift Right Compound Assignment
  a >>= c;
  assert(a == 0);
  
}
