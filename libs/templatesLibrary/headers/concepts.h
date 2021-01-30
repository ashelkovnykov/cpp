#ifndef TEMPLATES_CONCEPTS_H
#define TEMPLATES_CONCEPTS_H

// Basic concept with one parameter
template<typename T> concept C1 = true;
// Basic concept with two parameters
template<typename T, typename U> concept C2 = true;
// Basic concept with arbitrary number of parameters
template<typename... Ts> concept C3 = true;
// Concept which performs a constrain check
template<typename T> concept C4 = requires(T t) {
  sizeof(T) != sizeof(int);
};

// Constraint expression is C1<T>
template<C1 T> struct s1;
// Constraint expression is (C1<T> && ...)
template<C1... T> struct s2;
// Constraint expression is C2<T, int>
template<C2<int> T> struct s3;
// Constraint expression is (C2<T, int> && ...)
template<C2<int>... T> struct s4;
// Constraint expression is (C3<T> && ...)
template<C3... T> struct s5;
// TODO: Get example of Constraint expression C3<T, ...>
//template<> struct s6;

// Same as template<C1 T> void f2(T)
void f2(C1 auto);
// Same as template<C3... Ts> void f3(Ts...)
void f3(C3 auto...);

#endif // TEMPLATES_CONCEPTS_H
