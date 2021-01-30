#include <iostream>

#include "replacement.h"

// Define an identifier (empty object macro)
#define IDENTIFIER
// Define an object macro; preprocessor will replace all future instances of 'OBJECT' with '"\n"'
#define OBJECT "\n"
// Define a function style macro, which can take arguments to insert into the replacement text.
// Note the '#' directive, which means that the argument to 'input' should be wrapped in quotes to form a string literal.
// Note the '##' directive, which performs argument injection on the following identifier ('name') and then concatenates the result with the previous
// identifier.
#define FUNCTION(name, input) void f##name() { std::cout << #input; }

FUNCTION(1, s)
FUNCTION(2, u)
FUNCTION(3, c)

#undef FUNCTION

// Define a function style macro which takes a variable number of arguments
#define FUNCTION(num, ...) void f4() { char array[num] = { __VA_ARGS__ }; for(int i = 0; i < num; ++i) { std::cout << array[i]; } }

FUNCTION(3, 'e', 's', 's')

void replacementSuccess() {
  
  char s = 'X';
  
  f1();
  f2();
  f3();
  f3();
  f4();
  
  std::cout << OBJECT;
  
}

// Delete the existing definitions for each of the below macros
#undef IDENTIFIER
#undef OBJECT
#undef FUNCTION

void predefinedMacros() {
  
  // Predefined macros guaranteed to exist in every C++ compilier
  std::cout << "C++ version: " << __cplusplus << std::endl;
  std::cout << "Hosted or Freestanding program: " << (__STDC_HOSTED__ ? "HOSTED" : "FREESTANDING") << std::endl;
  std::cout << "Filename of diagnostic function: " << __FILE__ << std::endl;
  std::cout << "This code executed on line: " << __LINE__ << std::endl;
  std::cout << "Date of translation: " << __DATE__ << std::endl;
  std::cout << "Time of translation: " << __TIME__ << std::endl;
  std::cout << "Default alignment: " << __STDCPP_DEFAULT_NEW_ALIGNMENT__ << std::endl;
  
  // Compilers may also have their own additional predefined macros available
  
}
