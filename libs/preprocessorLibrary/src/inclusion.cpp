#include <iostream>               // include the standard library I/O code (injects all code from the file into this source file)

#if __has_include("inclusion.h")  // conditional evaluation of a constant expression; __has_include returns 1 if the filename can be found, else 0
#include "inclusion.h"
#endif                            // Required directive to signal end of if directive

#define DEFINED

void inclusionSuccess() {

#ifdef DEFINED  // true if the given identifier is defined as a preprocessing macro
  std::cout << "succ\n";
#else           // always true
  std::cout << "fail\n";
#endif

#ifndef DEFINED           // true if the given identifier is not defined as a preprocessing macro
  std::cout << "ure\n";
#elif (1 > 2)             // true if the expression evaluates to a non-zero value
  std::cout << "ure\n";
#elif defined(UNDEFINED)  // true if the given identifier is not defined as a preprocessing macro; 'ifdef' equivalent for 'elif'
  std::cout << "ure\n";
#elif !defined(UNDEFINED)
  std::cout << "ess\n";
#endif

}

#undef DEFINED
