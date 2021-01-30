#ifndef TEMPLATES_VARIABLETEMPLATES_H
#define TEMPLATES_VARIABLETEMPLATES_H

// Variable template taking a single type template parameter
template <typename T>
constexpr T pi = T(3.141592645);

// Member variable templates can only produce static members
struct Time {
  
  template <typename T>
  static const T min = 0;
  
  template <typename T>
  static const T max = 23;
  
};

#endif // TEMPLATES_VARIABLETEMPLATES_H
