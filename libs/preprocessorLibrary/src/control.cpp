#include <iostream>

#include "control.h"

void controlSuccess() {

#ifdef BROKEN
#line 666 "broken.cpp"              // If this execution path triggered, then the compiler would report an error on line 666 of file "broken.cpp"
#error "Forced preprocessing error" // with this error message
#else
  std::cout << "success\n";
#endif

}

#undef DEFINED
