#ifndef TYPES_UNIONS_H
#define TYPES_UNIONS_H

/**
 * A union is a special class which can hold only one of its data members at a time. All non-static data members share the same storage location.
 * However, the union may add padding bytes so that it's easier to store such objects in memory, depending on the alignment of the union members.
 * Therefore, the size of a union object is the size of the largest data member, rounded up to the nearest multiple of the largest data member
 * alignment.
 *
 * A union cannot derive from another class or be derived from by another class.
 *
 * If a union contains a non-static data member which has non-trivial special member functions (constructors, destructors, move assignments, etc.),
 * those functions are deleted by the union. To use this data member, it is necessary to call these functions explicitly.
 */

// Example union; largest data member size is 9, largest alignment is 8, round 9 up to nearest multiple of 8 to get size 16
union Union_1 {
  
  char c;     // size 1, alignment 1
  short s;    // size 2, alignment 2
  int i;      // size 4, alignment 4
  long l;     // size 8, alignment 8
  char a[9];  // size 9, alignment 1
              // 7 bytes empty padding
};

#endif // TYPES_UNIONS_H
