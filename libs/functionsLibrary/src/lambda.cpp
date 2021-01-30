#include <iostream>

#include "lambda.h"

template<typename Func>
//void lambdaHelper(int (*f)(int i)) {
void lambdaHelper(Func f) {
  
  const int input = 42;
  
  std::cout << f(input) << std::endl;
}

void lambdaExample() {
  
  int x = 36;
  
  // Basic lambda function, without closures
  lambdaHelper([](int i) { return i * 2; });
  // Template lambda function, without closures
  lambdaHelper([]<class T>(T i) { return i + 1; });
  // Basic closure: x captured by value
  lambdaHelper([=](int i) { return i + x; });
  // Basic closure: x captured by reference
  lambdaHelper([&](int i) { return i + x; });
  // Closure which captures objects by value by default, except for x, which should be captured by reference
  lambdaHelper([=, &x](int i) { return i + x; });
  // Closure which captures and renames local objects
  lambdaHelper([&a = x, x = x - 1](int i) { return a - x; });
  
}
