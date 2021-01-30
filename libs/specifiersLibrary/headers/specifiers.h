#ifndef SPECIFIERS_SPECIFIERS_H
#define SPECIFIERS_SPECIFIERS_H

// Default alignment of this class would be 8, since it only has a double data member and the alignment of double is 8
struct alignas(16) Aligned {
  double d;
};

// Not a literal class.
class StructA {
  const char* p;
  unsigned size;
public:
  template<std::size_t N>
  StructA(const char(&a)[N]): p(a), size(N - 1) {}
  ~StructA() { size = 0; }
};

// Not a literal class, but it has a constexpr constructor.
class StructB {
  const char* p;
  unsigned size;
public:
  template<std::size_t N>
  constexpr StructB(const char(&a)[N]): p(a), size(N - 1) {}
  ~StructB() { size = 0; }
};

// Literal class.
class StructC {
  const char* p;
  unsigned size;
public:
  template<std::size_t N>
  constexpr StructC(const char(&a)[N]): p(a), size(N - 1) {}
  constexpr ~StructC() { size = 0; }
};

#endif // SPECIFIERS_SPECIFIERS_H
