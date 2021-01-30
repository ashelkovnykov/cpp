#ifndef TYPES_FUNDAMENTAL_H
#define TYPES_FUNDAMENTAL_H

/**
 * The fundamental types of C++ are the most primitive objects upon which a program may be built. These include numbers, letters, and the concepts
 * of 'true' and 'false'.
 */
struct FundamentalTypes {
  
  //
  // LINUX, UNIX, & MAC OS (IEEE standard LP64)
  //
  
  void *p1; // 'void' is an incomplete type; cannot have an object of type 'void', but can have a 'void' pointer or 'void' return type
  
  bool b1; // Holds one of two primitive values: 'true' or 'false', equivalent to 1 and 0 respectively
  
  char c1; // Equivalent to either signed char or unsigned char, depending on the compiler
  signed char c2; // Represents ASCII characters or integers in the range [-128 - 127]
  unsigned char c3; // Represents ASCII characters, raw memory contents, or integers in the range [0 - 255]
  wchar_t wc1; // Represents "wide characters", usually in 32 bits. Leftover from when ISO and Unicode were competing.
  char8_t uc1; // Represents UTF-8 characters. Same size, signedness, and alignment as unsigned char, but it's a distinct type.
  char16_t uc2; // Represents UTF-16 characters
  char32_t uc3; // Represents UTF-32 characters
  
  short s1; // 16-bit, represents integers in range [-32,768 - 32,767]
  short int s2;
  signed short s3;
  signed short int s4;
  unsigned short s5; // 16-bit, represents integers in range [0 - 65,535]
  unsigned short int s6;
  int i1; // 32-bit, represents integers in range [-2,147,483,648 - 2,147,483,647]
  signed i2;
  signed int i3;
  unsigned i4; // 32-bit, represents integers in range [0 - 4,294,967,295]
  unsigned int i5;
  long l1; // 64-bit, represents integers in range [-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807]
  long int l2;
  signed long l3;
  signed long int l4;
  unsigned long l5; // 64-bit, represents integers in range [0 - 18,446,744,073,709,551,615]
  unsigned long int l6;
  
  float f1; // Represents floating point numbers using 32 bits. Approx. min = 1.4 * 10^-45. Approx. max = 3.4 * 10^38.
  double d1; // Represents floating point numbers using 64 bits. Approx. min = 4.94 * 10^-324. Approx. max = 1.79 * 10^308.
  long double ld1; // On x86 architecture, represents floating point numbers using 80 bits. On x86-64, compiler may choose to use 128 bits instead.
  
  //
  // WINDOWS (IEEE standard LLP64)
  //
  
  // Fundamental types are identical to LP64 standard, unless noted below:
  
  long wl1; // Equivalent to 'int' above
  long int wl2;
  signed long wl3;
  signed long int wl4;
  unsigned long wl5; // Equivalent to 'unsigned int' above
  unsigned long int wl6;
  long long wll1; // Equivalent to 'long' above
};

#endif //TYPES_FUNDAMENTAL_H
