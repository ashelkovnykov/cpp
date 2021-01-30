#ifndef TYPES_POINTERS_H
#define TYPES_POINTERS_H

/**
 * A pointer is an object which represents an address in memory. The type of the pointer is the type of the object
 * which is stored at that memory address.
 *
 * Pointer objects of every type have a special "null" value, which represents an empty pointer (i.e. a pointer which does not point to any entity).
 * A pointer object can be assigned this value (or can compare against the value) using the null pointer literal 'nullptr', the null pointer constant
 * 'NULL', or using an implicit conversion to/from the integer '0'.
 *
 * Qualifiers that appear after the '*' modify the pointer itself.
 */
struct PointerTypes {
  
  void *p0; // pointer to nothing
  int *p1; // pointer to int
  int **p2; // pointer to pointer to int
  const int *p3; // pointer to constant int
  int * const p4; // constant pointer to int
  const int * const p5; // constant pointer to constant int
  const int * const *p6; // pointer to constant pointer to constant int
  
  int (*p7)(); // pointer to function taking no inputs and returning an int
  int (*p8)(int, double); // pointer to a function taking an int and a double as input and returning an int
  int * const *(*p9)(float); // pointer to a function taking a float as input and returning a pointer to a constant pointer to an int
  
  int * PointerTypes::* p10; // pointer to a pointer-to-int member of class PointerTypes
  int (*(PointerTypes::* p11))(); // pointer to a pointer-to-function-taking-no-input-and-returning-int member of class PointerTypes
  
};

#endif //TYPES_POINTERS_H

