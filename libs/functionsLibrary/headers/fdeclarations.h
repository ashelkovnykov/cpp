#ifndef FUNCTIONS_DECLARATIONS_H
#define FUNCTIONS_DECLARATIONS_H

// Function declaration with unnamed parameters
int f(int, long, double);

// Function declaration with formal parameters
int f(int i, long l, double d);

// Function declaration with formal parameters and default arguments
int f(int i = 1, long l = 10000000000, double d = 3.14);

/**
 * In a function parameter list:
 * - arrays are converted to pointers
 * - functions are converted to pointers
 * - top-level qualifiers are dropped
 *
 * Due to the above rules, all of the functions below declare exactly the same function.
 */
void g(char c[3], int());
void g(char [], int());
void g(char* const, int());
void g(char* c, int());
void g(char* c, int (*g)());

// Deleted function: any attempts to call it will throw a compilation error
void h() = delete;

/**
 * This function has variadic arguments: it can be called with one or more arguments. Within the function body, the following macros (made available
 * by <cstdarg>) allow access to the arguments:
 * - va_start: Enables access to variadic function arguments
 * - va_arg: Accesses the next variadic function argument
 * - va_copy: Makes a copy of the current variadic function argument
 * - va_end: Ends traversal of variadic function arguments
 * - va_list: Type which holds variadic function information necessary for the above macros to work
 *
 * While functions with variadic arguments are a core part of the language, the same functionality can be achieved using variadic templates or the
 * std::initializer_list, both of which are heavily preferred due to the inconvenient nature of variadic functions for more purposes.
 */
void j(const char * ...) = delete;

#endif // FUNCTIONS_DECLARATIONS_H
