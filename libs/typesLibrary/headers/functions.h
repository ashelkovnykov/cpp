#ifndef TYPES_FUNCTIONS_H
#define TYPES_FUNCTIONS_H

/**
 * A function is a subroutine of sequenced expressions that performs a specific task. These expressions are packaged as a named unit so that they may
 * be reused.
 *
 * A function is composed of three parts: type, signature, and body. The type is the type of the object returned by the function (or 'void' if it does
 * not return any object). The signature is the name of the function, the list of input parameters, and an optional set of constraints. The body is
 * the sequence of commands which are performed by the function.
 *
 * Functions cannot return array objects or other functions.
 */
struct FunctionTypes {
  
  void f1(); // function with no input parameters that returns nothing
  int f2(); // function with no input parameters that returns an int
  int * f3(); // function with no input parameters that returns a pointer to int
  
  // A function which takes an int input parameter as input and returns nothing; the input parameter will need to be named during the declaration of
  // the function body.
  void f4(int);
  // A function which takes an int input parameter "i" as input and returns nothing.
  void f5(int i);
  // A function which takes two named int input parameters as input and returns nothing.
  void f6(int i1, int i2);
  // A function which takes two named int input parameters as input, the second of which has a default value. When the function is called, a second
  // argument can be omitted; the default value will be used.
  void f7(int i1, int i2 = 42);
  // Arrays and functions cannot be passed as input to a function: they are implicitly converted to pointers. In addition, input parameters cannot
  // have qualifiers. The below function is equivalent to:
  // void f8(int *a, int (*f)(), int i);
  void f8(int a[3], int f(), const int i);
  // A function which takes an arbitrary number of arguments (at least one) of type int and returns nothing.
  void f9(int i ...);
  
  auto f10() { return 42; } // the 'auto' keyword can be used to have the compiler determine return type using the template argument deduction rules
  const auto& f11(int& i) { return i; } // modifiers will be applied to the type determined by 'auto': return type is 'const int&'
  // The 'auto' keyword can be used with 'decltype' as an alternative method to have the compiler determine the type. The return type will be
  // whatever the result of wrapping 'decltype' around the return statement body would be.
  decltype(auto) f12() { return 42; }
  // If there all multiple return statements in the function body, all of their types must match.
  auto f13(bool b) {
    if (b) {
      return 10;
    } else {
      return 100;
    }
  }
  // NOTE:
  // Virtual functions cannot use type deduction.
  // If a function used type deduction, it can only be re-declared with type deduction.
  
};

#endif // TYPES_FUNCTIONS_H
