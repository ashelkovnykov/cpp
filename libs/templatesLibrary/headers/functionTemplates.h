#ifndef TEMPLATES_FUNCTIONTEMPLATES_H
#define TEMPLATES_FUNCTIONTEMPLATES_H

#include <iostream>

// Function template taking a single type template parameter
template<typename T>
void echo(T s)
{
  std::cout << s << std::endl;
}

// Abbreviated function template: this template is identical to the one above
void echo2(auto a) {
  std:: cout << a << std::endl;
}

#endif // TEMPLATES_FUNCTIONTEMPLATES_H
