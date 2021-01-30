#ifndef CONCEPTS_NAMESPACES_H
#define CONCEPTS_NAMESPACES_H

namespace outerNamespace { // Named namespace
  
  void f();
  
  namespace innerNamespace1 { // Named namespace
    
    void f(); // No conflict with 'f' defined in 'outerNamespace'
    
  }
  
  namespace innerNamespace2 { // Named namespace
    
    // Cannot define 'f' of 'innerNamespace1' here, since 'innerNamespace2' does not enclose 'innerNamespace1'
    //void innerNamespace1::f() {}
    
  }
  
  namespace innerNamespace1 { // Not a new namespace, continuation of 'innerNamespace1' from above
    
    void g();
    
  }
  
  inline namespace innerNamespace3 { // Named inline namespace
    
    void h(); // Function 'h' will be available in `outerNamespace` as if it were a member of that namespace
    
    namespace { // Unnamed namespace
      
      void g(); // Function 'g' will be available in `innerNamespace3` as if it were a member of that namespace, and therefore 'outerNamespace' too
      
    }
    
  }
  
}

// Namespaces can be given aliases by which to address them, to avoid overly long scope resolution sequences
namespace alias = outerNamespace::innerNamespace1;

#endif // CONCEPTS_NAMESPACES_H
