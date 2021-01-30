#ifndef CONCEPTS_EXCEPTIONS_H
#define CONCEPTS_EXCEPTIONS_H

namespace exceptionsExample {
  enum Colour { red, blue, green, yellow };
}

struct AlwaysFailsToBuild;

void exceptionCatcher();

#endif // CONCEPTS_EXCEPTIONS_H
