#ifndef TEMPLATES_PARAMETERPACK_H
#define TEMPLATES_PARAMETERPACK_H

/**
 * The class and function templates below demonstrate the different possible uses for parameter pack expansion.
 */

// Template parameter list
template<class ... Types>
struct Tuple {
  
  // sizeof operator (count number of arguments in the parameter pack)
  static const int num_types = sizeof...(Types);
  
  // Template arguments list
  Tuple<Types...>* t = 0;
  
};

// Function parameter list
template<class ... Types>
void f(bool b, Types ... args) {
  
  if (b) {
    // Lambda captures
    [&, args...](){
      // Function arguments list
      f(false, args...);
    }();
  }
  
}

template <int ... numbers>
struct Demo {

  // Fold expressions
  int sum = (numbers + ... + 0);
  int truth = (... && numbers);

};

#endif // TEMPLATES_PARAMETERPACK_H
