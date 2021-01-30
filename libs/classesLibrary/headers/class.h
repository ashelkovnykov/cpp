#ifndef CPP_CLASS_H
#define CPP_CLASS_H

/**
 * This file demonstrates the many concepts of C++ classes.
 */

/**
 * This class demonstrates class members, member access, default initialization, local classes, nested classes. bit fields, injected class names, and
 * the 'this' pointer. Keyword 'class' means that default member access and inheritance are private.
 */
class ClassA {
  
  //
  // Private members
  //
  
  //
  // Private data members
  //
  
  // Non-static data member without default initialization
  int x;
  
  //
  // Private member functions
  //
  
  int f(int i, int j) {
    
    // Local class, exists only within scope of 'f'. Keyword 'struct' means that default member access and inheritance are public.
    struct Adder {
      
      //
      // Public members
      //
      
      //
      // Public data members
      //
      
      // Non-static data members with default initialization
      int a = 0;
      int b = 0;
      
      // Non-default, converting constructor. If this constructor is used, the default initializers for 'a' and 'b' are ignored.
      Adder(int i, int j): a(i), b(j) {}
      
      //
      // Public member functions
      //
      
      int sum() {
        return (a + b);
      }
      
    };
    
    return Adder(i, j).sum();
  }
  
  //
  // Protected members
  //
protected:
  
  //
  // Protected data members
  //
  
  // Static data member with default initialization
  static const int y = 2;
  
  // Nested class: exists only in the scope of ClassA and can access anything that a protected member of ClassA could
  class ClassB {
    int z = y;
  };
  
  //
  // Protected member functions
  //
  
  // Class name is injected into its own body as a valid type
  ClassA* me() {
    // The 'this' pointer refers to the particular instance of the class which is running the code, allowing it to refer to itself
    return this;
  }
  
  //
  // Public members
  //
public:
  
  //
  // Public data members
  //
  
  // 'a' and 'b' are bit fields
  // 'a' uses 3 bits, thus has range [0 .. 7]
  unsigned char a : 3;
  // Signal to use a new byte for the next bit field, thus 5 empty bits
  int : 0;
  // 'b' uses 4 bits, thus has range [-8 .. 7]
  char b : 4;
  // 4 empty bits after 'b'
  // Total space used by these bit fields is 2 bytes, though they could fit in 1 byte
  
  //
  // Public member functions
  //
  
  // Reference-qualified member function: this will be called by lvalues
  int whatIsInMe() &{
    return x;
  }
  // Reference-qualified member function: this will be called by rvalues
  int whatIsInMe() &&{
    return x;
  }
  
};

/**
 * These classes demonstrate inheritance (direct and virtual) and virtual functions.
 *
 * Note that this 'ClassB' and the one above don't conflict, since the 'ClassB' above is a nested class and therefore only valid within the scope of
 * 'ClassA'.
 */
class ClassB {

  int x = 1;
  
protected:
  
  int y = 2;
  
public:
  
  int z = 3;
  
};

// Every object of ClassC contains a ClassB sub-object. ClassB is inherited with public inheritance.
struct ClassC : ClassB {
  
  int sum(int i) {
    int r = i;
    
    // Note that x is not accessible, since it is private in ClassB
    r += z;
    r += y;
//    r += x;

    return r;
  }
  
};

// Every object of ClassD contains ClassC and ClassB sub-objects. ClassC is inherited with private inheritance.
struct ClassD : private ClassC {
  
  // This sum hides the sum of ClassC
  virtual int sum(int i) {
    // Note that sum from ClassC can still be directly accessed internally
    return ClassC::sum(i);
  }
  
};

// Every object of ClassD contains ClassD, ClassC, and ClassB sub-objects. ClassD is inherited with protected inheritance.
struct ClassE : protected ClassD {
  
  // The override keyword specifies that this sum is overriding a virtual function from a base class and not hiding it with a new definition
  // The final keyword specifies that no class derived from ClassE can override sum
  int sum(int i) override final {
    int r = i;
    
    // Note that y and z are inaccessible since they were inherited as private members of ClassD
//    r += z;

    return r;
  }
  
};

class ClassF : public ClassB {};
// Every object of ClassG contains ClassF, ClassC, and two ClassB sub-objects.
class ClassG : ClassC, ClassF {
  
  ClassG() {
    // The two expressions below modify different objects
    ClassF::z += 1;
    ClassC::z += 1;
  }
  
};

class ClassH : public virtual ClassB {};
class ClassI : public virtual ClassB {};
// Every object of ClassJ contains ClassI, ClassH, and ClassB sub-objects. Unlike ClassG, ClassJ has only one ClassB because it is virtually
// inherited in both ClassH and ClassI.
class ClassJ : ClassH, ClassI {
  
  ClassJ() {
    // The two expressions below modify the same object
    ClassH::z += 1;
    ClassI::z += 1;
  }
  
};

/**
 * These classes abstract classes, empty-base optimization, and friends.
 */
// ClassK is abstract: it has a pure virtual function. No ClassK object can be created, it cannot be used as a parameter, return, or cast type, and no
// pointers or references to ClassK may exist. It's also an empty base class, since it contains no data members.
struct ClassK {
  virtual void f() = 0;
};

// ClassL does not contain a ClassK sub-object: empty-base optimization removes ClassK from ClassL to save space.
class ClassL : private ClassK {
  
  // ClassL overrides ClassK::f and makes it concrete. Thus, ClassL is not an abstract class.
  void f() override {}
  
  // Since ClassL inherits ClassK with private inheritance, f() is a private function of ClassL and cannot be used anywhere else. However, ClassM is
  // labeled a friend of ClassL, and thus may access all private members in ClassL objects.
  friend class ClassM;
  
};

struct ClassM {
  
  void f(ClassL l) {
    // Demonstration of ClassM permission to access f() in ClassL objects as a friend
    l.f();
  }
  
};

/**
 * These classes demonstrate constructors, destructors, and assignment operators.
 */
struct ClassN {

  int x;
  int* y;
  
  // Default, converting constructor
  ClassN(): x(0) {
    y = new int;
    *y = 0;
  }
  
  // Non-default, converting constructor
  ClassN(int i, int j): x(i) {
    y = new int;
    *y = j;
  }
  
  // Explicit, delegating constructor
  explicit ClassN(int i): ClassN(i, i) {}
  
  // Copy constructor
  ClassN(ClassN& n): x(n.x) {
    y = new int;
    *y = *(n.y);
  }
  
  // Move constructor (note that it steals the resources of the argument)
  ClassN(ClassN&& n): x(n.x) {
    y = new int;
    y = n.y;
    n.y = 0;
  }
  
  // Copy constructor
  ClassN& operator=(ClassN& n) {
    x = n.x;
    *y = *(n.y);
    
    return *this;
  }
  
  // Move constructor
  ClassN& operator=(ClassN&& n) {
    x = n.x;
    y = n.y;
    n.y = 0;
    
    return *this;
  }
  
protected:
  
  // Destructor
  virtual ~ClassN() {
    delete y;
  }

};

#endif // CPP_CLASS_H
