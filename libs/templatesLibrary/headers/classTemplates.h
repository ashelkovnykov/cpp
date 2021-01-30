#ifndef TEMPLATES_CLASSTEMPLATES_H
#define TEMPLATES_CLASSTEMPLATES_H

// Class template taking a type and an object of matching type, both of which have defaults
template <typename T = int, T i = 100>
struct T_A {
  
  T myDefault = i;
  
  T_A() {}
  T_A(T j): myDefault(j) {}
  
};

// Class template taking a template template parameter
template <template<typename U, U> typename T>
struct T_B {
  T<short, 5> myDefault;
};


// Non-template class which demonstrates member function templates
struct T_C {
  
  unsigned int x;
  
  // Non-template and template member functions may have the same name
  T_C(): x(0) {}
  
  // When a non-template and template function conflict, the non-template function takes precedence unless an explicit list of template
  // arguments is provided
  T_C(int i): x(-1) {}
  
  // Common uses for member function templates are constructors and conversion operators
  template <typename T>
  T_C(T t) {
    x = (int)t;
  }
  
};

// Explicit instantiation of class template A specialization used by a2 below
template struct T_A<short, 100>;

// Partial specialization of class template A where T must be pointer type and the default value is replaced by 0
template <typename T, T i>
struct T_A<T*, i> {
  T myDefault = 0;
};

// Class template deduction guide that tells the compiler to treat any attempted instantiations of A with type long as instantiations of A with type
// unsigned int
T_A(long) -> T_A<unsigned int>;

void classTemplateDemonstration();

#endif // TEMPLATES_CLASSTEMPLATES_H
