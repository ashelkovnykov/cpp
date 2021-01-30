#include <iostream>

#include "literals.h"

void printLiterals() {
  
  // Boolean literals
  std::cout << true << std::endl;
  std::cout << false << std::endl;
  
  // Character literals
  std::cout << 'a' << std::endl; // regular character
  std::cout << reinterpret_cast<const char*>(u8'a')<< std::endl; // UTF- 8 character
  std::cout << reinterpret_cast<const char*>(u'貓') << std::endl; // UTF-16 character
  std::cout << reinterpret_cast<const char*>(U'🍌') << std::endl; // UTF-32 character
  std::cout << reinterpret_cast<const char*>(L'β') << std::endl; // wide character
  
  // Integer literals
  std::cout << 42 << std::endl; // decimal integer
  std::cout << 052 << std::endl; // octal integer
  std::cout << 0x2a << std::endl; // hexadecimal integer
  std::cout << 0b101010 << std::endl; // binary integer
  
  std::cout << 1 << std::endl; // signed integer
  std::cout << 1U << std::endl; // unsigned integer
  std::cout << 1L << std::endl; // signed long integer
  std::cout << 1UL << std::endl; // unsigned long integer
  std::cout << -1UL << std::endl; // same as above; there are no negative integer literals, only positive ones sent as input to unary '-'
  
  // Floating-point literals
  std::cout << 40.0 << std::endl; // floating-point number
  std::cout << 4e1 << std::endl; // same as above, expressed differently
  std::cout << 0xa.8p2 << std::endl; // same as above, expressed as hex floating point: a=10; 8=0.5 (since 16 * 0.5 = 8); 2^2=4; 10.5 * 4 = 42
  
  // String literals
  std::cout << "Hello, world!" << std::endl;
  
  // User-defined literals
  std::cout << 12_km << std::endl;
  
}
