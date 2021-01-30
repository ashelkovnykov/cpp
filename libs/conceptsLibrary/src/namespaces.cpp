#include "namespaces.h"

// Functions defined outside of the namespace
void outerNamespace::f() {}
void outerNamespace::innerNamespace1::f() {}
void outerNamespace::innerNamespace1::g() {}
void outerNamespace::innerNamespace3::h() {}
// This 'g' function refers to the same one as introduced in the anonymous namespace inside of 'innerNamespace3'
namespace outerNamespace {
  void g() {}
}

void example1() {
  // Can use 'h' of 'innerNamespace3' as if were a member of 'outerNamespace', since 'innerNamespace3' is an inline namespace
  outerNamespace::h();
  // This is 'g' of the unnamed namespace in 'innerNamespace3'; it's implicitly available in 'innerNamespace3' and thus inlined into 'outerNamespace'
  outerNamespace::g();
  // This is 'g' of 'innerNamespace1'
  alias::g();
}

void example2() {
  // Using directive to import 'outerNamespace' members automatically imports 'innerNamespace3' members
  using namespace outerNamespace;
  f();
  h();
  innerNamespace1::f();
}
