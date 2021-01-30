#include <iostream>
#include <vector>

#include "statements.h"

void selectionExample() {

  int i = 1;
  
  // Regular if statement
  if (i != 0) {
    std::cout << "s";
    
  } else {
    std::cout << "f";
  }
  
  // Uses an initializer prior to the first conditional; the initialized object has block scope and is destroyed at the end of the if statement
  if (int i = 2 * i; i == 1) {
    std::cout << "a";
    
  } else if (i == 2) {
    std::cout << "u";
    
  } else {
    std::cout << "a";
  }
  
  // Constexpr if statement: the else statement below will be removed during compile time
  if constexpr (true) {
    std::cout << "c";
    i = 4;
    
  } else {
    std::cout << "i";
  }
  
  // Switch statement, including example of case fall-through
  switch (i) {
    case 0:
      std::cout << "l";
      
    case 1:
      std::cout << "u";
      
    case 2:
      std::cout << "r";
      
    case 3:
      std::cout << "e";
      break;
      
    case 4:
      std::cout << "c";
      
    case 5:
      std::cout << "e";
      
    case 6:
      std::cout << "s";
      
    case 7:
      std::cout << "s";
  }
  
  std::cout << std::endl;
}

void iterationExample() {
  
  char cstr[] = "Hello";
  for (int n = 0; char c = cstr[n]; ++n) {
    std::cout << c;
  }
  
  std::cout << ", ";
  
  std::vector<char> v = {'W', 'o', 'r', 'l', 'd'};
  for (const char& c : v) {
    std::cout << c;
  }
  
  unsigned short i = 0;
  while (i != 33) {
    i += 1;
  }
  std::cout << static_cast<char>(i);
  
  do {
    i -= 1;
  } while (i > 10);
  std::cout << static_cast<char>(i);
}

void jumpExample() {

  int i = 0;
  
  label:
  switch (i) {
    case 0:
      i = 1;
      break;
  
    default:
      i *= 2;
  }
  
  while (i++ < 5) {
    continue;
    i = 0;
  }
  
  if (i < 10) {
    goto label;
  } else {
    return;
  }
  
}
