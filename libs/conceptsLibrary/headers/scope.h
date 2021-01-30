#ifndef CONCEPTS_SCOPE_H
#define CONCEPTS_SCOPE_H

#include <stdexcept>
#include <iostream>

// This class is defined in the global namespace; its scope will end at the end of its translation unit
struct ScopeClass {
  
  int doubleOrNothing(bool dub) { // Function parameter scope; scope of 'dub' ends at the end of the function body
    
    goto here;
    
    here: // Function scope; this label is in scope everywhere within the function body, even before it is declared
    int a = x; // Block scope; scope of 'a' ends at the end of the function body
    
    if (dub) {
      int x = (a * 2); // This 'x' has block scope; example of scope nesting, as this x takes priority over the class member x defined below
      return x;        // Scope of this 'x' ends at the end of the if statement
      
    } else {
      return 0;
    }
  }
  
  int x; // This 'x' has class scope; note that it's used in the function above before its definition here
  
};

namespace scope_example {
  
  // This class is defined in the custom "scope_example" namespace, thus it has namespace scope; no conflicts with the similarly named class above
  struct ScopeClass {
    
    int doubleIt(int i) {
      
      int r; // Block scope
      
      try {
        r = i * 2;
        
      } catch(const std::runtime_error& re) { // Block scope; scope of 're' ends at the end of this catch block
        std::cout << re.what(); // re is in scope
        r = -1; // 'r' from outer block is still in scope
        
      } catch(std::exception& e) { // Block scope; scope of 'e' ends at the end of this catch block
        // 're' from the above block is not in scope here
        std::cout << e.what();
        r = -1; // 'r' from outer block is still in scope
      }
      
      return r;
    }
  };

}

template <
    template <
        typename T > // Scope of 'T' for the inner template begins and ends on this line
    class T > // Scope of 'T' begins for outer template
class TemplateClass {

}; // Scope of 'T' for outer template ends

int sizeOfClass1() {
  // Unambiguous; only the 'ScopeClass' from the global namespace is in scope
  return sizeof(ScopeClass);
}

int sizeOfClass2() {
  using namespace scope_example;
  // Ambiguous; both 'ScopeClass' classes are in scope, so we need to distinguish between them
  return sizeof(scope_example::ScopeClass);
}

#endif // CONCEPTS_SCOPE_H
