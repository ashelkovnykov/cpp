#ifndef TYPES_ARRAYS_H
#define TYPES_ARRAYS_H

/**
 * An array is a contiguous block of allocated memory for storing a known number of objects which all have the same type. Arrays can be constructed
 * for the following objects:
 * - Fundamental objects (except 'void')
 * - Classes
 * - Pointers
 * - Enumerations
 * - Arrays (of bounded size)
 *
 * The objects in an array of size N are indexed 0, 1, ..., (N - 1).
 *
 * Arrays cannot have qualifiers; the qualifiers are instead applied to the type of the array.
 */
struct ArrayTypes {

  int a1[3]; // array of 3 int objects
  int a2[3] = {1, 2, 3}; // array of 3 int objects with initialization
  int a3[2][2]; // multi-dimensional array of 4 int objects (like a 2 x 2 matrix)
  int a4[2][2] = {{1, 2}, {3, 4}}; // multi-dimensional array of 4 int objects with initialization
  
  int *p1 = a1; // arrays are implicitly converted to pointers to the first element in the array
  int *p2 = (a1 + 1); // arrays have special addition/subtraction logic: the result is a pointer to the second element in the array
  int (*p3)[2] = a3; // arrays are implicitly converted only once: a3 is not converted to a pointer-to-pointer-to-int
  
};

#endif // TYPES_ARRAYS_H
