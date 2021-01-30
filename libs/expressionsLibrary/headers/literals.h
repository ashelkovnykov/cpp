#ifndef EXPRESSIONS_LITERALS_H
#define EXPRESSIONS_LITERALS_H

namespace {
  double operator "" _km(unsigned long long ll) { return (double)ll; }
}

void printLiterals();

#endif // EXPRESSIONS_LITERALS_H
