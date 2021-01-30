#ifndef CONCEPTS_DECLARATIONS_H
#define CONCEPTS_DECLARATIONS_H

/**
 * Declarations which are NOT definitions.
 */
namespace declarations {
  
  int f(int); // function declaration without definition
  
  extern int i; // object with external linkage declaration without definition
  
  enum E : int; // enumeration declaration without definition
  
  struct C; // class declaration without definition
  
  struct ExampleClass {
    
    static int i; // static class member object declaration without definition
    
  };
  
  typedef C MyC; // type declaration without definition
  
}

/**
 * Structured bindings bind names to sub-objects/elements of arrays. Like a reference, a binding is an alias for an existing object.
 */
namespace bindings {
  
  struct Pair {
    int a {1}, b {2};
  };

  int array[2] = {1, 2};
  auto [x, y] = array;    // creates a copy of 'a[2]' (e.g. 'c[2]'), then 'x' refers to 'c[0]' and 'y' refers to 'c[1]'
  auto& [xr, yr] = array; // 'xr' refers to 'a[0]' and 'y' refers to 'a[1]'
  
  auto [c, d] = Pair();   // creates an anonymous Pair object, then 'c' and 'd' refer to members 'a' and 'b' respectively of this object

}

#endif // CONCEPTS_DECLARATIONS_H
