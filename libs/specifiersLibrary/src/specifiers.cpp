#include <iostream>

#include "specifiers.h"

namespace specifiers {
  
  // Multiple definitions of specialSum are allowed, though it's preferred to replace function calls to it with the raw instructions for the function
  // body.
  inline int specialSum(int& a, int& b) {
    return a + b + 36;
  }
  
  // A version of factorial which uses recursion instead of iteration. Any calls to this function must provide a constant expression as an argument
  // and CAN be evaluated at compile time and replaced in the source code with the resultant value.
  constexpr int factorialA(int n) {
    return (n <= 1) ? 1 : (n * factorialA(n - 1));
  }
  
  // A version of factorial which uses recursion instead of iteration. Any calls to this function must provide a constant expression as an argument
  // and MUST be evaluated at compile time and replaced in the source code with the resultant value.
  consteval int factorialB(int n) {
    return (n <= 1) ? 1 : (n * factorialB(n - 1));
  }
  
  // Not a literal class and no constexpr constructor, therefore cannot be either constant initialized or constant destroyed (therefore compile-time
  // replaced).
  //constinit StructA x1 = StructA("Test");
  //constexpr StructA x2 = StructA("Test");
  
  // Not a literal class, but has a constexpr constructor. Therefore, it cannot be cannot be constant destroyed (therefore compile-time replaced), but
  // it can be constant initialized.
  constinit StructB x3 = StructB("Test");
  //constexpr StructB x4 = StructB("Test");
  
  // Literal class, therefore can be both constant initialized and constant destroyed (therefore compile-time replaced).
  constinit StructC x5 = StructC("Test");
  constexpr StructC x6 = StructC("Test");
  
  // Type automatically deduced from initializer.
  auto i = 42;
  // Type automatically deduced from return statement.
  auto f(int x) {
    return x + 1;
  }
  // Type automatically deduced from argument to template.
  template<auto x>
  void print(decltype(x) out) { // Type deduced from object
    std::cout << out << std::endl;
  }
  
}
