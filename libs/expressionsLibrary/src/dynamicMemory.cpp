#include "dynamicMemory.h"

/**
 * The 'new' expression creates and initializes objects with dynamic storage duration (i.e. objects whose storage duration is not limited by the
 * scope in which they were declared). It first attempts to allocate storage, and then attempts to construct and initialize objects. If initialization
 * fails, all allocated storage is deallocated before throwing error.
 *
 * The 'new' expression can be used to create either a single object or an array of objects. It's also possible to "place" a new object into a
 * specific memory location.
 *
 * The objects created by 'new' are initialized as follows:
 * - for a non-array object:
 *  - if no initializer is provided, it is default-initialized
 *  - if a parenthesized initializer list is provided, it is direct-initialized
 *  - if a brace-enclosed list of initializers is provided, it is list-initialized
 * - for an array of objects:
 *  - if no initializer is provided, each object is default-initialized
 *  - if an empty parentheses initializer list is provided, each object is value-initialized
 *  - if a parenthesized or brace-enclosed list of initializers is provided, the entire array is aggregate-initialized
 *
 *
 *  The 'delete' expression destroys objects with dynamic storage location that have been previously allocated by the 'new' expression. There are two
 *  different delete expressions: one for individual objects and one for array objects. Calling the individual form of 'delete' on an array with
 *  dynamic storage, calling the array form of 'delete' on an individual object with dynamic storage, or calling either on anything else results in
 *  undefined behaviour.
 *
 *  If 'delete' is called on a null pointer, no destructors are called. If an error occurs during deletion, the storage is still deallocated.
 */
void dynamicMemoryExample() {
  
  // Complex types should be wrapped in parentheses; for example, without braces the below type would be interpreted as "(new int)(*[10])()"
  auto fa = new (int(*[10])());
  
  // Can use keyword `auto` with new, but must provide an initializer list in such a case (otherwise the type cannot be determined)
  int* p = new auto(42);
  
  // The first dimension of an array can be specified at runtime, creating a dynamic array
  double (*matrix)[5] = new double[(*p)][5];

  // Delete individual objects
  delete p;
  
  // Delete arrays
  delete[] fa;
  delete[] matrix;
  
}
