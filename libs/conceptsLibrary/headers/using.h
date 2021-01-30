#ifndef CONCEPTS_USING_H
#define CONCEPTS_USING_H

namespace A {
  
  void f() {}
  
}

namespace B {
  
  using ::A::f; // using declaration; '::A::f' now visible as '::B::f' in the example below
  
  namespace E {
    enum { X, Y, Z };
  }
  using E::X, E::Z; // using declaration; 'E::X' and 'E::Z' now visible in namespace 'B'
  
  // Below line is invalid, since an object 'X' already exists in this scope because of the above using declaration
//  int X;
  
}

namespace C {
  
  // Using directive; treats all members of namespace 'B' as if they were declared in the nearest namespace scope which encloses both namespace 'B'
  // and namespace 'C', i.e. the global namespace.
  using namespace B;
  
  void g() {
    // This 'f' is '::A::f', which is visible from namespace 'B' because it was brought into scope there by the using declaration on line 12 and
    // brought into scope here by the using directive on line 26.
    f();
  }
  
  // Since the using directive on line 26 makes the members of namespace 'B' visible as if they were in the global namespace scope (see above), this
  // 'f' overwrites '::A::f' in the scope of namespace 'C'.
  void f() {}

  void example() {
    
    int i = X + Z; // enumerators 'X' and 'Z' are visible here
    
    f(); // this 'f' is the '::C::f'
  }

}

struct Base {
  
  Base(int xx): x(xx) {}
  
  virtual void a() {}
  void b() {}
  void c() {}
  
protected:
  
  int x;
  
};

struct Derived : Base {
  
  using Base::Base, Base::a, Base::b, Base::c, Base::x; // using declaration

  void a() {} // this 'a' overwrites 'Base::a'
  void b(int i) {} // this 'b' overloads 'Base::b'; both are visible
  void c() {} // this 'c' hides 'Base::c'
  
};

int classExample(int i) {
  
  Derived d(i); // 'Base' is initialized by calling constructor 'Base(i)'
  
  return d.x; // member 'x' is protected in 'Base' but public in 'Derived'
};

#endif // CONCEPTS_USING_H
